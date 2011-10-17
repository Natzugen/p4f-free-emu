#include "..\Header\stdafx.h"
#include "..\Header\Mercenary.h"
#include "..\Header\protocol.h"
#include "..\Header\GameMain.h"
#include "..\Header\LogProc.h"

#include "..\Header\CastleSiege.h"
#include "..\Header\CastleSiegeSync.h"
// GS-N 0.99.60T 0x0051A200
/*	GS-N	1.00.18	JPN	0x0054BB70	-	Completed
		BOOL CMercenary::CreateMercenary(int iIndex, int iMercenaryTypeIndex, BYTE cTX, BYTE cTY) Weird Compilation
	*/

CMercenary g_CsNPC_Mercenary;

CMercenary::CMercenary()
{
	this->m_iMercenaryCount = 0;
}




CMercenary::~CMercenary()
{
	return;
}



BOOL CMercenary::CreateMercenary(int iIndex, int iMercenaryTypeIndex, BYTE cTX, BYTE cTY)
{
	LPOBJ lpObj = &gObj[iIndex];
	int iMonsterIndex = -1;
	BYTE cX = cTX;
	BYTE cY = cTY;

	BYTE btMapAttr = MapC[lpObj->MapNumber].GetAttr(cX, cY);

	if ( lpObj->MapNumber != MAP_INDEX_CASTLESIEGE )
	{
		::MsgOutput(iIndex, "This is not a map of the Offensive Alliance.");

		return FALSE;
	}

 

	if ( g_CastleSiegeSync.GetCastleState() != CASTLESIEGE_STATE_STARTSIEGE )
	{
		::MsgOutput(iIndex, "Soldiers can be summoned only after the Siege begins.");

		return FALSE;
	}


	if ( iMercenaryTypeIndex == 286 || iMercenaryTypeIndex == 287 )
	{
		if ( lpObj->m_btCsJoinSide != 1 )
		{
			::MsgOutput(iIndex, "Only the Defensive Alliance can be summoned.");

			return FALSE;
		}
	}

	if ( lpObj->GuildStatus != 0x80 && lpObj->GuildStatus != 0x40 )
	{
		::MsgOutput(iIndex, "Only the Guild Master and Assistant Guild Master can summon Soldiers.");

		return FALSE;
	}

	if ( this->m_iMercenaryCount > MAX_MERCENARY_COUNT )
	{
		::MsgOutput(iIndex, "The maximum number of Soldiers has been exceeded.");

		return FALSE;
	}

	iMonsterIndex = gObjAddMonster(lpObj->MapNumber);

	if ( iMonsterIndex >= 0 )
	{
		MONSTER_ATTRIBUTE * MAttr = gMAttr.GetAttr(iMercenaryTypeIndex);

		if ( MAttr == NULL )
		{
			gObjDel(iMonsterIndex);
			return FALSE;
		}

		gObjSetMonster(iMonsterIndex, iMercenaryTypeIndex);

		gObj[iMonsterIndex].Live = TRUE;
		gObj[iMonsterIndex].Life = MAttr->m_Hp;
		gObj[iMonsterIndex].MaxLife = MAttr->m_Hp;
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = cX;
		gObj[iMonsterIndex].Y = cY;
		gObj[iMonsterIndex].MTX = cX;
		gObj[iMonsterIndex].MTY = cY;
		gObj[iMonsterIndex].TX = cX;
		gObj[iMonsterIndex].TY = cY;
		gObj[iMonsterIndex].m_OldX = cX;
		gObj[iMonsterIndex].m_OldY = cY;
		gObj[iMonsterIndex].StartX = cX;
		gObj[iMonsterIndex].StartY = cY;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 0;
		gObj[iMonsterIndex].Level = MAttr->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 1000;
		gObj[iMonsterIndex].Dir = 1;
		gObj[iMonsterIndex].RegenTime = GetTickCount();
		gObj[iMonsterIndex].m_Attribute = 0;
		gObj[iMonsterIndex].DieRegen = 0;
		gObj[iMonsterIndex].m_btCsNpcType = OBJ_MONSTER;
		gObj[iMonsterIndex].m_btCsJoinSide = 1;
		
		MsgOutput(iIndex, "Soldier summon succeeded!");

		this->m_iMercenaryCount++;

		if ( lpObj->lpGuild )
		{
			LogAdd("[CastleSiege] Mercenary is summoned [%d] - [%d][%d] [%s][%s][%d] - (Guild : %s)",
				iMonsterIndex, iMercenaryTypeIndex, this->m_iMercenaryCount, 
				lpObj->AccountID, lpObj->Name, lpObj->GuildStatus, lpObj->lpGuild->Name);
		}
		else
		{
			LogAdd("[CastleSiege] Mercenary is summoned [%d] - [%d][%d] [%s][%s][%d]",
				iMonsterIndex, iMercenaryTypeIndex, this->m_iMercenaryCount, 
				lpObj->AccountID, lpObj->Name, lpObj->GuildStatus);
		}
	}
	else
	{
		MsgOutput(iIndex, "Soldier summon failed!");
		return FALSE;
	}

	return TRUE;
}


BOOL CMercenary::DeleteMercenary(int iIndex)
{
	if ( iIndex < 0 || iIndex > OBJMAX-1 )
	{
		return FALSE;
	}

	this->m_iMercenaryCount--;

	LogAdd("[CastleSiege] Mercenary is broken [%d] - [%d]", iIndex, this->m_iMercenaryCount);

	if ( this->m_iMercenaryCount < 0 )
	{
		this->m_iMercenaryCount = 0;
	}

	return TRUE;
}




BOOL CMercenary::SearchEnemy(LPOBJ lpObj)
{
	int iTargetNumber = -1;
	int iAttackRange = 0;

	lpObj->TargetNumber = -1;

	if ( lpObj->Class == 286 )
		iAttackRange = 5;
	else if ( lpObj->Class == 287 )
		iAttackRange = 3;

	for (int i=0;i<MAX_VIEWPORT;i++)
	{
		iTargetNumber = lpObj->VpPlayer2[i].number;
		if ( iTargetNumber >= 0 )
		{
			if ( gObj[iTargetNumber].Type == OBJ_USER )
			{
				if ( gObj[iTargetNumber].Live )
				{
					if ( gObj[iTargetNumber].Teleport == 0 )
					{
						 
						if ( gObj[iTargetNumber].m_btCsJoinSide == lpObj->m_btCsJoinSide )
							continue;
						

						int x = lpObj->X - gObj[iTargetNumber].X;
						int y = lpObj->Y - gObj[iTargetNumber].Y;
						int iDis = (int)sqrt( double(x*x + y*y ));
						lpObj->VpPlayer2[i].dis = iDis;

						if ( lpObj->Dir == 1 )
						{
							if ( abs(x) <= 2 )
							{
								int cY = lpObj->Y - iAttackRange;
								if ( cY <= gObj[iTargetNumber].Y && lpObj->Y >= gObj[iTargetNumber].Y )
								{
									lpObj->TargetNumber = iTargetNumber;
									return TRUE;
								}
							}
						}

						if ( lpObj->Dir == 3 )
						{
							if ( abs(y) <= 2 )
							{
								int cX = lpObj->X - iAttackRange;
								if ( cX <= gObj[iTargetNumber].X && lpObj->X >= gObj[iTargetNumber].X )
								{
									lpObj->TargetNumber = iTargetNumber;
									return TRUE;
								}
							}
						}
					}
				}
			}
		}
	}
	return FALSE;
}




void CMercenary::MercenaryAct(int iIndex)
{
	if ( ::gObjIsConnected(iIndex) == FALSE )
	{
		return;
	}

	LPOBJ lpObj = &gObj[iIndex];


	if ( lpObj->VPCount2 < 1 )
	{
		return;
	}

	if ( this->SearchEnemy(lpObj) != 0 && lpObj->TargetNumber >= 0)
	{
		lpObj->m_ActState.Attack = 1;
		lpObj->NextActionTime = lpObj->m_AttackSpeed;
	}
	else
	{
		lpObj->NextActionTime = lpObj->m_MoveSpeed;
	}
}