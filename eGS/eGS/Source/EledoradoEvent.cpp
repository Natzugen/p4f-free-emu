#include "..\Header\stdafx.h"
#include "..\Header\EledoradoEvent.h"
#include "..\Header\Gamemain.h"
#include "..\Header\LogProc.h"
#include "..\Header\user.h"

CEledoradoEvent gEledoradoEvent;



CEledoradoEvent::CEledoradoEvent()
{
	this->GoldGoblenEventStartTime = 0;
	this->TitanEventStartTime = 0;
	this->GoldDerconEventStartTime = 0;
	this->DevilLizardKingEventStartTime = 0;
	this->KanturEventStartTime = 0;
	this->m_BossGoldDerconMapNumber[0] = -1;
	this->m_BossGoldDerconMapNumber[1] = -1;
	this->m_BossGoldDerconMapNumber[2] = -1;
}




CEledoradoEvent::~CEledoradoEvent()
{
	return;
}





void CEledoradoEvent::Init()
{
	return;
}




void CEledoradoEvent::SetEventState(int State)
{
	this->EventState = State;
}



void CEledoradoEvent::Run()
{
	if ( this->m_bMenualStart != FALSE )
	{
		return;
	}

	if ( this->EventState == 0 )
	{
		return;
	}

	if ( this->GoldGoblenEventStartTime == 0 )
	{
		tm today={0};
		time_t ltime;

		time(&ltime);
		localtime_s(&today,&ltime);

		if ( today.tm_min >= 30 && today.tm_min  <= 35 )
		{
			int Time = GetTickCount();

			this->GoldGoblenEventStartTime = Time;
			this->RegenGoldGoblen();

			this->TitanEventStartTime = Time;
			this->RegenTitan();

			this->GoldDerconEventStartTime = Time;
			this->RegenGoldDercon();

			this->DevilLizardKingEventStartTime = Time;
			this->RegenDevilLizardKing();

			this->KanturEventStartTime = Time;
			this->RegenKantur();
		}
	}
	else
	{
		DWORD Time = GetTickCount();

		if ( ( Time - this->GoldGoblenEventStartTime ) > gEledoradoGoldGoblenRegenTime * 60000 )
		{
			this->GoldGoblenEventStartTime = Time;
			this->RegenGoldGoblen();
		}

		if ( ( Time - this->TitanEventStartTime ) > gEledoradoTitanRegenTime * 60000 )
		{
			this->TitanEventStartTime = Time;
			this->RegenTitan();
		}

		if ( ( Time - this->GoldDerconEventStartTime ) > gEledoradoGoldDerconRegenTime * 60000 )
		{
			this->GoldDerconEventStartTime = Time;
			this->RegenGoldDercon();
		}

		if ( ( Time - this->DevilLizardKingEventStartTime ) > gEledoradoDevilLizardKingRegenTime * 60000 )
		{
			this->DevilLizardKingEventStartTime = Time;
			this->RegenDevilLizardKing();
		}

		if ( ( Time - this->KanturEventStartTime ) > gEledoradoDevilTantarosRegenTime * 60000 )
		{
			this->KanturEventStartTime = Time;
			this->RegenKantur();
		}
	}
}







void CEledoradoEvent::RegenGoldGoblen()
{
	#if (MP==1)
	#pragma omp parallel for
	#endif
	for (int n=0;n<OBJ_MAXMONSTER;n++)
	{
		if ( gObj[n].Class == 78 )
		{
			gObj[n].Live = TRUE;
			int rnd = Random(0,GGoblinMap.size()-1);
			int MapNumber = GGoblinMap[rnd];
			gObj[n].MapNumber = MapNumber;

			while ( gMSetBase.GetBoxPosition(MapNumber, GGoblinXmin[rnd], GGoblinYmin[rnd], GGoblinXmax[rnd], GGoblinYmax[rnd], gObj[n].X, gObj[n].Y) == 0 )
			{

			}

			gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;

			LogAdd("Make GoldGoblen : %d, %d,%d",
				MapNumber, gObj[n].X, gObj[n].Y);

			AllSendServerMsg((char*)GGoblinTown[rnd].c_str());
		}
	}
}



void CEledoradoEvent::RegenTitan()
{
	#if (MP==1)
	#pragma omp parallel for
	#endif
	for (int n=0;n<OBJ_MAXMONSTER;n++)
	{
		if ( gObj[n].Class == 53 )	// Golden Titan
		{
			gObj[n].Live = TRUE;
			int rnd = Random(0,GTitanMap.size()-1);
			int MapNumber = GTitanMap[rnd];
			gObj[n].MapNumber = MapNumber;

			while ( gMSetBase.GetBoxPosition(MapNumber, GTitanXmin[rnd], GTitanYmin[rnd], GTitanXmax[rnd], GTitanYmax[rnd], gObj[n].X, gObj[n].Y) == 0 )
			{

			}

			this->m_BossTitanMapNumber = gObj[n].MapNumber;
			this->m_BossTitanMapX = gObj[n].X;
			this->m_BossTitanMapY = gObj[n].Y;

			gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;

			LogAdd("Make GoldTaitan : %d, %d,%d",
				MapNumber, gObj[n].X, gObj[n].Y);

			AllSendServerMsg((char*)GTitanTown[rnd].c_str());
		}
		else if ( gObj[n].Class == 54 ) // Golden Soldier
		{
			gObj[n].Live = TRUE;
			int MapNumber = this->m_BossTitanMapNumber;
			gObj[n].MapNumber = MapNumber;

			gMSetBase.GetBoxPosition(MapNumber, this->m_BossTitanMapX-4, this->m_BossTitanMapY-4,
				this->m_BossTitanMapX+4, this->m_BossTitanMapY+4, gObj[n].X, gObj[n].Y);

						gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;
		}
	}
}


void CEledoradoEvent::RegenGoldDercon()
{
	int MapNumber=-1;
	int Map[3]={0,3,2};
	int count = 0;

	this->CheckGoldDercon(MapNumber);	// clearing golden invision map

	#if (MP==1)
	#pragma omp parallel for private(MapNumber) reduction(+: count)
	#endif
	for (int n=0;n<OBJ_MAXMONSTER;n++)
	{
		if ( gObj[n].Class == 79 )	// Gold Dercon
		{
			gObj[n].Live = TRUE;
			int rnd = Random(0,GDragonMap.size()-1);
			MapNumber = GDragonMap[rnd];

			gObj[n].MapNumber = MapNumber;

			while ( gMSetBase.GetBoxPosition(MapNumber, GDragonXmin[rnd], GDragonYmin[rnd], GDragonXmax[rnd], GDragonYmax[rnd], gObj[n].X, gObj[n].Y) == 0 )
			{

			}

			gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;

			LogAdd("Make GoldDercon : %d, %d,%d", MapNumber, gObj[n].X, gObj[n].Y);

			AllSendServerMsg((char*)GDragonTown[rnd].c_str());


			this->m_BossGoldDerconMapNumber[count] = MapNumber;
			gObj[n].m_BossGoldDerconMapNumber = MapNumber;	
			count++;

		}
	}

	this->CheckGoldDercon(MapNumber);
}



void CEledoradoEvent::RegenDevilLizardKing()
{

//	int Map[2]={0,3};
	#if (MP==1)
	#pragma omp parallel for
	#endif
	for (int n=0;n<OBJ_MAXMONSTER;n++)
	{
		if ( gObj[n].Class == 80 )	// Devil Lizard King
		{
			gObj[n].Live = TRUE;
			int rnd = Random(0,GLizardMap.size()-1);
			int MapNumber = GLizardMap[rnd];
			gObj[n].MapNumber = MapNumber;

			while ( gMSetBase.GetBoxPosition(MapNumber, GLizardXmin[rnd], GLizardYmin[rnd], GLizardXmax[rnd], GLizardYmax[rnd], gObj[n].X, gObj[n].Y) == 0 )
			{

			}

			this->m_BossDevilLizardKingMapNumber = gObj[n].MapNumber;
			this->m_BossDevilLizardKingMapX = gObj[n].X;
			this->m_BossDevilLizardKingMapY = gObj[n].Y;

			gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;

			LogAdd("Make GoldLizarKing : %d, %d,%d",
				MapNumber, gObj[n].X, gObj[n].Y);

			AllSendServerMsg((char*)GLizardTown[rnd].c_str());
		}
		else if ( gObj[n].Class == 81 ) // Golden Velparie
		{
			gObj[n].Live = TRUE;
			int MapNumber = this->m_BossDevilLizardKingMapNumber;
			gObj[n].MapNumber = MapNumber;

			gMSetBase.GetBoxPosition(MapNumber, this->m_BossDevilLizardKingMapX-4, this->m_BossDevilLizardKingMapY-4,
				this->m_BossDevilLizardKingMapX+4, this->m_BossDevilLizardKingMapY+4, gObj[n].X, gObj[n].Y);

			gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;
		}
	}
}

void CEledoradoEvent::RegenKantur()
{

	//	int Map[2]={0,3};
	#if (MP==1)
	#pragma omp parallel for
	#endif
	for (int n=0;n<OBJ_MAXMONSTER;n++)
	{
		if ( gObj[n].Class == 82 )	// Gold Tantalos
		{
			gObj[n].Live = TRUE;
			int rnd = Random(0,GTantalosMap.size()-1);
			int MapNumber = GTantalosMap[rnd];
			gObj[n].MapNumber = MapNumber;

			while ( gMSetBase.GetBoxPosition(MapNumber, GTantalosXmin[rnd], GTantalosYmin[rnd], GTantalosXmax[rnd], GTantalosYmax[rnd], gObj[n].X, gObj[n].Y) == 0 )
			{

			}

			this->m_BossKanturMapNumber = gObj[n].MapNumber;
			this->m_BossKanturMapX = gObj[n].X;
			this->m_BossKanturMapY = gObj[n].Y;

			gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_PoisonBeattackCount = 0;
			gObj[n].m_ColdBeattackCount = 0;
			gObj[n].m_ViewState = 0;
			gObj[n].Teleport = 0;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;

			LogAdd("Make GoldTantarus : %d, %d,%d",
				MapNumber, gObj[n].X, gObj[n].Y);

			AllSendServerMsg((char*)GTantalosTown[rnd].c_str());
		}
		else if ( gObj[n].Class == 83 ) // Gold Iron Wheel
		{
			gObj[n].Live = TRUE;
			int MapNumber = this->m_BossKanturMapNumber;
			gObj[n].MapNumber = MapNumber;

			gMSetBase.GetBoxPosition(MapNumber, this->m_BossKanturMapX-10, this->m_BossKanturMapY-10,
				this->m_BossKanturMapX+10, this->m_BossKanturMapY+10, gObj[n].X, gObj[n].Y);

			gObj[n].Life = gObj[n].MaxLife;
			gObj[n].TX = gObj[n].X;
			gObj[n].TY = gObj[n].Y;
			gObj[n].MTX = gObj[n].X;
			gObj[n].MTY = gObj[n].Y;
			gObj[n].StartX = (BYTE)gObj[n].X;
			gObj[n].StartY = (BYTE)gObj[n].Y;
			gObj[n].m_State = 1;
			gObj[n].PathCount = 0;
		}
	}
}



void CEledoradoEvent::CheckGoldDercon(int MapNumber)
{
	if ( this->EventState == 0 )
		return;

	BOOL EventOn = FALSE;
	int EventClearMapNumber = -1;

	for ( int i=0;i<3;i++)
	{
		if ( this->m_BossGoldDerconMapNumber[i] != -1 )
		{
			if ( this->m_BossGoldDerconMapNumber[i] == MapNumber )
			{
				EventOn = TRUE;
			}
			else
			{
				EventClearMapNumber = this->m_BossGoldDerconMapNumber[i];
			}
		}
	}

	if ( EventClearMapNumber != -1 )
	{
		GCMapEventStateSend(EventClearMapNumber, 0, 3);
	}

	if ( EventOn != FALSE )
	{
		GCMapEventStateSend(MapNumber, 1, 3);
	}
	else
	{
		GCMapEventStateSend(MapNumber, 0, 3);
	}
}



void CEledoradoEvent::Start_Menual()
{
	this->SetMenualStart(TRUE);

	LogAdd("[Event Management] [Start] EledoradoEvent Event!");

	DWORD TickCount = GetTickCount();

	this->GoldGoblenEventStartTime = TickCount;
	this->RegenGoldGoblen();

	this->TitanEventStartTime = TickCount;
	this->RegenTitan();

	this->GoldDerconEventStartTime = TickCount;
	this->RegenGoldDercon();

	this->DevilLizardKingEventStartTime = TickCount;
	this->RegenDevilLizardKing();

	this->KanturEventStartTime = TickCount;
	this->RegenKantur();

}
void CEledoradoEvent::End_Menual()
{
	this->SetMenualStart(FALSE);
}
