// ------------------------------
// Decompiled by Deathway
// Date : 2007-05-09
// ------------------------------
// GS-N 0.99.60T 0x004B1200
/*	GS-N	1.00.18	JPN	0x004CF4C0	-	Completed
	void MoveMonsterProc()	-	Wierd Compilation - Status OK
	void gObjSpriteDamage(LPOBJ lpObj, int damage)	-	Wierd Compilation - Status OK
	void gObjTradeCancel(int aIndex)	-	Wierd Compilation - Status OK
	BOOL gObjJoominCheck(int aIndex, char* szInJN)	-	strcmpi comflict symbols
	void gObjGiveItemSearch(LPOBJ lpObj, int maxlevel)	-	Complete just for size
	void gObjGiveItemWarehouseSearch(LPOBJ lpObj, int maxlevel)	-	Completes just for size
	void InitFrustrum()	-	Wrong Symbol NAmes of the zzmath functions
	void SkillFrustrum()	-	Wrong Symbol NAmes of the zzmath functions
	int  gObjCurMoveMake(BYTE * const path , LPOBJ lpObj)	// Func not used - Need to be completed
*/
//	GS-CS	1.00.18	JPN	0x004CF4C0	-	Completed
#include "..\Header\stdafx.h"
#include "..\Header\GameServer.h"
#include "..\Header\logproc.h"
#include "..\Header\GameMain.h"
#include "..\Header\MapServerManager.h"
#include "..\Header\gObjMonster.h"
#include "..\Header\ObjCalCharacter.h"
#include "..\Header\ObjUseSkill.h"
#include "..\Header\DarkSpirit.h"
#include "..\Header\DSProtocol.h"
#include "..\Header\DevilSquare.h"
#include "..\Header\protocol.h"
#include "..\Header\AcceptIp.h"
#include "..\Header\BattleGround.h"
#include "..\Header\MonsterAttr.h"
#include "..\Header\ChaosBox.h"
#include "..\Header\PacketChecksum.h"
#include "..\Header\QuestInfo.h"
#include "..\Header\EledoradoEvent.h"
#include "..\Header\TNotice.h"
#include "..\Header\GMMng.h"
#include "..\Header\zzzmathlib.h"
#include "..\Header\Gate.h"
#include "..\Header\ObjAttack.h"
#include "..\Header\SProtocol.h"
#include "..\Header\MultiAttackHAckCheck.h"
#include "..\Header\BattleSoccer.h"
#include "..\Header\BattleSoccerManager.h"
#include "..\Header\TUnion.h"
#include "..\Header\TMonsterAIElement.h"
#include "..\Header\winutil.h"
#include "..\Header\Weapon.h"
#include "..\Header\CrywolfSync.h"
#include "..\Header\Kanturu.h"
//#include "..\Header\CashShop.h"
#include "..\Header\Mercenary.h"
#include "..\Header\KalimaGate.h"
#include "..\Header\KanturuBattleUserMng.h"
#include "..\Header\Guardian.h"
#include "..\Header\SProtocol.h"
#include "..\Header\GameServerAuth.h"
#include "..\Header\MoveCommand.h"
#include "..\Header\ItemAddOption.h"
#include "..\Header\StatMng.h"
#include "..\Header\SetItemOption.h"
#include "..\Header\SkillAdditionInfo.h"
//#include "..\Header\CashItemPeriodSystem.h"
#include "..\Header\TMonsterSkillManager.h"
#include "..\Header\user.h"
#include "..\Header\IpCache.h"
#include "..\Header\CastleSiege.h"
#include "..\Header\LifeStone.h"
#include "..\Header\GuardianStatue.h"
#include "..\Header\CannonTower.h"
#include "..\Header\CastleCrown.h"
#include "..\Header\CastleCrownSwitch.h"

#include "..\Header\Crywolf.h"
#include "..\Header\CrywolfAltar.h"
#include "..\Header\protocol.h"
#include "..\SQL.h"


#include "..\sfmt.h"

// directions

//Y
//|-------
//||6|5|4|
//||7|9|3|
//||8|1|2|
//|------- X





int ChangeCount; 
int lOfsChange;
int GuildUserCount;
int GuildUserOfs;
int GuildInfoCount;
int GuildInfoOfs;
int skillSuccess;
int gCurConnectUser;
int gDisconnect;
int gObjTotalUser;
int gItemLoopMax;
int gItemLoop;
int gItemLoop2;
int gObjCSFlag;

#include "..\Header\ChaosCastle.h"
#include "..\Header\ReadScript.h"


CViewportGuild ViewGuildMng;	// line : 130



OBJECTSTRUCT gObj[OBJMAX];	// line : 180
int gObjCount;
int gObjMonCount;
int gObjCallMonCount;




MessageStateMachine gSMMsg[OBJMAX][MAX_MONSTER_SEND_MSG];	
ExMessageStateMachine gSMAttackProcMsg[OBJMAX][MAX_MONSTER_SEND_ATTACK_MSG];



HANDLE hThread_gObjMove;

CItem * pTempInventory = NULL;
BYTE * pTempInventoryMap = NULL;


struct PWMSG_COUNT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x4|*/ struct PWMSG_HEAD h;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char count;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x5>

struct PBMSG_COUNT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char count;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x4>

struct PMSG_ITEMVIEWPORTCREATE {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char px;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char py;
  /*<thisrel this+0x4>*/ /*|0x7|*/ unsigned char ItemInfo[7]; //12 for Season4

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0xb>

struct PMSG_VIEWPORTCREATE {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char X;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char Y;
  /*<thisrel this+0x4>*/ /*|0x12|*/ unsigned char CharSet[18];
  /*<thisrel this+0x18>*/ /*|0x4|*/ unsigned long ViewSkillState;
  /*<thisrel this+0x1c>*/ /*|0xa|*/ char Id[10];
  /*<thisrel this+0x26>*/ /*|0x1|*/ unsigned char TX;
  /*<thisrel this+0x27>*/ /*|0x1|*/ unsigned char TY;
  /*<thisrel this+0x28>*/ /*|0x1|*/ unsigned char DirAndPkLevel;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x2c>

struct PMSG_VIEWPORTCREATE_CHANGE {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char X;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char Y;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char SkinH;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char SkinL;
  /*<thisrel this+0x8>*/ /*|0x4|*/ int ViewSkillState;
  /*<thisrel this+0xc>*/ /*|0xa|*/ char Id[10];
  /*<thisrel this+0x16>*/ /*|0x1|*/ unsigned char TX;
  /*<thisrel this+0x17>*/ /*|0x1|*/ unsigned char TY;
  /*<thisrel this+0x18>*/ /*|0x1|*/ unsigned char DirAndPkLevel;
  /*<thisrel this+0x19>*/ /*|0x12|*/ unsigned char CharSet[18]; //para o illusion temple

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x1c>

struct PMSG_VIEWPORTDESTROY {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x2>

struct PMSG_MONSTER_VIEWPORTCREATE {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char Type_HI;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char Type_LO;
  /*<thisrel this+0x4>*/ /*|0x4|*/ unsigned long ViewState;
  /*<thisrel this+0x8>*/ /*|0x1|*/ unsigned char X;
  /*<thisrel this+0x9>*/ /*|0x1|*/ unsigned char Y;
  /*<thisrel this+0xa>*/ /*|0x1|*/ unsigned char TX;
  /*<thisrel this+0xb>*/ /*|0x1|*/ unsigned char TY;
  /*<thisrel this+0xc>*/ /*|0x1|*/ unsigned char Path;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x10>

struct PMSG_CALLMONSTER_VIEWPORTCREATE {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char Type_HI;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char Type_LO;
  /*<thisrel this+0x4>*/ /*|0x4|*/ int ViewState;
  /*<thisrel this+0x8>*/ /*|0x1|*/ unsigned char X;
  /*<thisrel this+0x9>*/ /*|0x1|*/ unsigned char Y;
  /*<thisrel this+0xa>*/ /*|0x1|*/ unsigned char TX;
  /*<thisrel this+0xb>*/ /*|0x1|*/ unsigned char TY;
  /*<thisrel this+0xc>*/ /*|0x1|*/ unsigned char Path;
  /*<thisrel this+0xd>*/ /*|0xa|*/ unsigned char Id[10];

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x18>

struct PMSG_GUILDVIEWPORT_USER {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char GNumberH;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char GNumberL;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x4>

struct PMSG_GUILDVIEWPORT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x2>*/ /*|0x8|*/ char GuildName[8];
  /*<thisrel this+0xa>*/ /*|0x20|*/ unsigned char Mark[32];

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x2a>


struct GOBJ_BOT_INIT 
{
	int aIndex;
	int X;
	int Y;
	int MapNum;
	int Class;
	char Name[11];
	char AccountID[11];
	int Strength;
	int Dexterity;
	int Vitality;
	int Energy;
	int Leadership;
	int Level;
	int PK_Level;
	int PK_Count;
	int Experience;
};


BYTE GuildInfoBuf[10000];
BYTE GuildUserBuf[10000];
BYTE SendGBufChange[5000];

PMSG_VIEWPORTCREATE pViewportCreate;
PMSG_VIEWPORTCREATE_CHANGE pViewportCreateChange;
PMSG_VIEWPORTDESTROY pViewportDestroy;
PMSG_MONSTER_VIEWPORTCREATE pMonsterViewportCreate;
PMSG_CALLMONSTER_VIEWPORTCREATE pCallMonsterViewportCreate;

#pragma pack(1)

PWMSG_COUNT pItemCount;
PMSG_ITEMVIEWPORTCREATE pItemViewportCreate;
PMSG_VIEWPORTDESTROY pItemViewportDestroy;

#pragma pack()



short RoadPathTable[MAX_ROAD_PATH_TABLE] = { -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1, -1, 0 };	// THIS VARIABLE HAS SOME STRANGE THINGS ONT ITS UBICATION
int  gServerMaxUser=500;	// THIS VARIABLE HAS SOME STRANGE THINGS ONT ITS UBICATION
BOOL g_EnergyCheckOn=1; // THIS VARIABLE HAS SOME STRANGE THINGS ONT ITS UBICATION



struct PMSG_EX_SKILL_COUNT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;	// C1:BA
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char Type;
  /*<thisrel this+0x6>*/ /*|0x1|*/ unsigned char Count;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};



void gObjSkillUseProcTime500(LPOBJ lpObj)
{
	if ( lpObj->SkillHellFire2State != 0 )
	{
		unsigned long dwCurrentTick = GetTickCount();
		lpObj->SkillHellFire2Count = BYTE((dwCurrentTick - lpObj->SkillHellFire2Time) / 500);

		if ( lpObj->SkillHellFire2Count > 12 )
		{
			lpObj->SkillHellFire2Count = 12;
		}

		if(dwCurrentTick >= (lpObj->SkillHellFire2Time + 6000))
		{
			CMagicInf * lpMagic = gObjGetMagicSearch(lpObj,0x28);

			if(lpMagic != 0)
			{
				gObjUseSkill.RunningSkill(lpObj->m_Index,0,lpMagic,0);
			}
		}
		else
		{
			int mana = MagicDamageC.SkillGetMana(40);
			mana = mana * 20 / 100;
			BOOL bSuccess = TRUE;

			if ( mana > lpObj->Mana )
			{
				bSuccess = FALSE;
				int count = 0;

				while ( true )
				{
					count++;

					if ( gObjIsConnected(lpObj) == FALSE )
					{
						LogAdd("��[CHECK_LOG_INFINITY] gObjIsConnected() error %s %d", __FILE__, __LINE__);
						break;
					}

					if ( count > 100 )
					{
						LogAdd("��[CHECK_LOG_INFINITY] ( _count > 100 ) error %s %d", __FILE__, __LINE__);
						break;
					}

					int pos = gObjGetManaItemPos(lpObj->m_Index);

					if ( pos == -1 )
					{
						break;
					}

					PMSG_USEITEM pMsg;
					pMsg.inventoryPos = pos;
					pMsg.invenrotyTarget = 0;
					CGUseItemRecv(&pMsg, lpObj->m_Index);

					if ( mana <= lpObj->Mana )
					{
						bSuccess = TRUE;
						break;
					}
				}
			}
			
			if ( bSuccess == FALSE )
			{
				CMagicInf * lpMagic = gObjGetMagicSearch(lpObj, 40);
				
				if (lpMagic != NULL )
				{
					gObjUseSkill.RunningSkill(lpObj->m_Index, 0, lpMagic, 0);
				}
			}
			else
			{
				lpObj->Mana -= mana;

				if ( lpObj->Mana < 0.0f )
				{
					lpObj->Mana = 0.0f;
				}

				GCManaSend(lpObj->m_Index, (short)lpObj->Mana, -1, 0, lpObj->BP);
				PMSG_EX_SKILL_COUNT pMsg;
				PHeadSetB( (LPBYTE)&pMsg, 0xBA, sizeof(pMsg));
				pMsg.Type = 0x28;
				pMsg.Count = lpObj->SkillHellFire2Count;
				pMsg.NumberH = SET_NUMBERH(lpObj->m_Index);
				pMsg.NumberL = SET_NUMBERL(lpObj->m_Index);

				DataSend(lpObj->m_Index, (UCHAR *)&pMsg, pMsg.h.size);
				MsgSendV2(lpObj, (UCHAR *)&pMsg, pMsg.h.size);
			}
		}
	}
}


//------------------------------------------------------------


void MonsterAndMsgProc()
{
	LPOBJ lpObj;
	int n;
	int aIndex;

	for ( n=0;n<OBJMAX;n++)
	{
		lpObj = &gObj[n];

		if ( lpObj->Connected == PLAYER_PLAYING  )
		{
			if ( lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC) 
			{
				if(lpObj->m_iCurrentAI != 0)
				{
					continue;
				}
				gObjMonsterProcess(lpObj);
			}
			else
			{
				gObjSkillUseProcTime500(lpObj);
				gObjMsgProc(lpObj);
				CreateFrustrum(lpObj->X, lpObj->Y, n);
			}

			if ( lpObj->Type == OBJ_USER )
			{
				gDarkSpirit[n].Run();
			}
		}
		else if ( lpObj->Connected >= PLAYER_LOGGED )
		{
			if ( lpObj->Type == OBJ_USER )
			{
				gObjMsgProc(lpObj);

				if ( lpObj->Connected == PLAYER_PLAYING )
				{
					CreateFrustrum(lpObj->X, lpObj->Y, n);
				}
			}
		}
	}

	for ( n=0;n<OBJMAXUSER;n++)
	{
		lpObj = &gObj[n+OBJ_STARTUSERINDEX];

		if ( lpObj->Connected == PLAYER_PLAYING  )
		{
			aIndex = lpObj->m_Index;

			for ( int i=0;i<MAX_MONSTER_SEND_ATTACK_MSG;i++)
			{
				if ( gSMAttackProcMsg[n][i].MsgCode >= 0 )
				{
					if ( GetTickCount() > gSMAttackProcMsg[n][i].MsgTime )
					{
						gObjStateAttackProc(lpObj, gSMAttackProcMsg[n][i].MsgCode, gSMAttackProcMsg[n][i].SendUser,
							gSMAttackProcMsg[n][i].SubCode, gSMAttackProcMsg[n][i].SubCode2);
						gSMAttackProcMsg[n][i].MsgCode = -1;
					}
				}
			}
		}
	}
	TMonsterSkillManager::MonsterSkillProc();
}







/*void MoveMonsterProc2()
{
// NEED REWRITINGS
	int MoveTime;
	int DelayTime;
	LPOBJ lpObj;

	for ( int n=0;n<OBJMAX;n++)
	{
		lpObj = &gObj[n];

		if ( lpObj->Connected == PLAYER_PLAYING )
		{

			if (lpObj->m_iCurrentAI != 0  lpObj->Type == OBJ_MONSTER && (  ((lpObj->m_Attribute <51)?FALSE:(lpObj->m_Attribute>56)?FALSE:TRUE )) != FALSE )
			{
				CreateFrustrum(lpObj->X, lpObj->Y, n);
				continue;
			}

			if ( lpObj->m_State == 2 )
			{
				if ( lpObj->PathCount != 0 && lpObj->m_SkillHarden == 0 )
				{
					if ( lpObj->DelayLevel != 0 )
					{
						DelayTime = 300;
					}
					else
					{
						DelayTime = 0;
					}

					if ( lpObj->Type == OBJ_MONSTER && lpObj->m_RecallMon >= 100 )
					{
						lpObj->m_MoveSpeed = 200;
					}
					else
					{
						lpObj->m_MoveSpeed = 400;
					}

					if ( (lpObj->PathDir[lpObj->PathCur] %2) == 0 )
					{
						MoveTime = (lpObj->m_MoveSpeed + DelayTime) * 1.3;
					}
					else
					{
						MoveTime = lpObj->m_MoveSpeed + DelayTime;
					}

					if ( (GetTickCount() - lpObj->PathTime) > MoveTime )
					{
						if ( lpObj->PathCur < 14 )
						{
							lpObj->X = lpObj->PathX[lpObj->PathCur];
							lpObj->Y = lpObj->PathY[lpObj->PathCur];
							lpObj->Dir = lpObj->PathDir[lpObj->PathCur];
							lpObj->PathTime = GetTickCount();
							lpObj->PathCur++;

							if ( lpObj->PathCur >= lpObj->PathCount )
							{
								lpObj->PathCur = 0;
								lpObj->PathCount = 0;

								if ( lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC )
								{
									lpObj->PathStartEnd = 0;
								}
							}
						}
					}
				}

				CreateFrustrum(lpObj->X, lpObj->Y, n);
				
				
			}
		}
	}


}*/

void MoveMonsterProc()
{
	DWORD MoveTime;
	int DelayTime;
	LPOBJ lpObj;

	for(int n = 0; n < OBJMAX;n++)
	{
		lpObj = &gObj[n];

		if(lpObj->m_iCurrentAI != 0)
		{
			if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
			{
				continue;
			}
		}

                
         
        if(lpObj->Connected == PLAYER_PLAYING)
        {
                /*if(lpObj->Type == OBJ_MONSTER)
                {
                        if(ATTRIBUTE_RANGE(lpObj->m_Attribute) == FALSE)
                        {
                                if(lpObj->Class != 277)
                                {
                                        if(lpObj->Class != 283)
                                        {
                                                if(lpObj->Class != 288)
                                                {
                                                        if(lpObj->Class != 278)
                                                        {
                                                                if(lpObj->Class != 216)
                                                                {
                                                                        if(lpObj->Class != 217)
                                                                        {
                                                                                if(lpObj->Class != 218)
                                                                                {
                                                                                        if(lpObj->Class != 219)
                                                                                        {
                                                                                                if(lpObj->Class != 205) //Good
                                                                                                {
                                                                                                        continue;
                                                                                                }
                                                                                        }
                                                                                }
                                                                        }       
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }*/
                //Here Comes
                if(lpObj->Class == 209)
                {
                        if(lpObj->Class != 204)
                        {
                                CreateFrustrum(lpObj->X,lpObj->Y,n);
                                continue;
                        }
                }
                if(lpObj->m_State == 2)
                {
                        if(lpObj->PathCount != 0 && lpObj->m_SkillHarden == 0 && lpObj->m_iSkillStunTime == 0)
                        {
                                if(lpObj->DelayLevel != 0)
                                {
                                        DelayTime = 300;
                                }
                                else
                                {
                                        DelayTime = 0;
                                }
        
                                if(lpObj->Type == OBJ_MONSTER && lpObj->m_RecallMon >= 100)
                                {
                                        lpObj->m_MoveSpeed = 200;
                                }
                                else
                                {
                                        lpObj->m_MoveSpeed = 400;
                                }
        
                                if(lpObj->PathDir[lpObj->PathCur]%2 == 0)
                                {
                                        MoveTime = DWORD( (lpObj->m_MoveSpeed + DelayTime)*1.3);
                                }
                                else
                                {
                                        MoveTime = lpObj->m_MoveSpeed + DelayTime;
                                }
        
                                if( (GetTickCount() - lpObj->PathTime) > MoveTime && lpObj->PathCur < 14)
                                {
                                        int nextX = lpObj->PathX[lpObj->PathCur];
                                        int nextY = lpObj->PathY[lpObj->PathCur];
                                        BYTE mapnumber = lpObj->MapNumber;
                                        BYTE attr = MapC[mapnumber].GetAttr(nextX,nextY);
        
                                        if( lpObj->Type == OBJ_USER &&
                                                ( (attr & 4) == 4 || (attr & 8) == 8) )
                                        {
                                                LogAdd("[ CHECK POSITION ] MoveMosterProc [%s][%s] Map[%d]-(%d,%d) User(%d,%d) Can not Move Position Attr[%d]",
                                                        lpObj->AccountID,lpObj->Name,lpObj->MapNumber,nextX,nextY,lpObj->X,lpObj->Y,attr);
                                                for(n = 0; n < 15;n++)
                                                {
                                                        lpObj->PathX[n] = 0;
                                                        lpObj->PathY[n] = 0;
                                                        lpObj->PathOri[n] = 0;
                                                }
        
                                                lpObj->PathCount = 0;
                                                lpObj->PathCur = 0;
                                                lpObj->PathTime = GetTickCount();

                                                if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
                                                {
                                                        lpObj->PathStartEnd = 0;
                                                }
        
                                                if(lpObj->Type == OBJ_USER)
                                                {
                                                        gObjSetPosition(lpObj->m_Index,lpObj->X,lpObj->Y);
                                                }
                                        }
                                        else
                                        {
                                                lpObj->X = lpObj->PathX[lpObj->PathCur];
                                                lpObj->Y = lpObj->PathY[lpObj->PathCur];
                                                lpObj->Dir = lpObj->PathDir[lpObj->PathCur];

                                                lpObj->PathTime = GetTickCount();
                                                lpObj->PathCur++;

                                                if(lpObj->PathCur >= lpObj->PathCount)
                                                {
                                                        lpObj->PathCur = 0;
                                                        lpObj->PathCount = 0;

                                                        if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
                                                        {
                                                                lpObj->PathStartEnd = 0;
                                                        }
                                                }
                                        }
                                }
                        }
                        CreateFrustrum(lpObj->X,lpObj->Y,n);
                }
        }
        

		if(lpObj->Connected == PLAYER_PLAYING)
		{
			if(lpObj->Type == OBJ_MONSTER)
			{
				if(	 ATTRIBUTE_RANGE(lpObj->m_Attribute) != FALSE
 
				  || lpObj->Class == 277 || lpObj->Class == 283 ||
					 lpObj->Class == 288 || lpObj->Class == 278 ||
					 lpObj->Class == 216 || lpObj->Class == 217 || 
					 lpObj->Class == 218 || lpObj->Class == 219 ||
					 CHECK_LIMIT2(lpObj->Class, 205, 210) ||
					 CHECK_CLASS(lpObj->Class, 204)

						)
				{
					CreateFrustrum(lpObj->X,lpObj->Y,n);
					return;
				}
			}
			
			if(lpObj->m_State == 2)
			{
				if(lpObj->PathCount != 0 && lpObj->m_SkillHarden == 0 && lpObj->m_iSkillStunTime == 0)
				{
					if(lpObj->DelayLevel != 0)
					{
						DelayTime = 300;
					}
					else
					{
						DelayTime = 0;
					}
	
					if(lpObj->Type == OBJ_MONSTER && lpObj->m_RecallMon >= 100)
					{
						lpObj->m_MoveSpeed = 200;
					}
					else
					{
						lpObj->m_MoveSpeed = 400;
					}
	
					if(lpObj->PathDir[lpObj->PathCur]%2 == 0)
					{
						MoveTime = DWORD((lpObj->m_MoveSpeed + DelayTime)*(double)1.3);
					}
					else
					{
						MoveTime = lpObj->m_MoveSpeed + DelayTime;
					}
	
					if( (GetTickCount() - lpObj->PathTime) > MoveTime && lpObj->PathCur < 14)
					{
						int nextX = lpObj->PathX[lpObj->PathCur];
						int nextY = lpObj->PathY[lpObj->PathCur];
						BYTE mapnumber = lpObj->MapNumber;
						BYTE attr = MapC[mapnumber].GetAttr(nextX,nextY);
	
						if( lpObj->Type == OBJ_USER &&
							( (attr & 4) == 4 || (attr & 8) == 8) )
						{
							LogAdd("[ CHECK POSITION ] MoveMosterProc [%s][%s] Map[%d]-(%d,%d) User(%d,%d) Can not Move Position Attr[%d]",
								lpObj->AccountID,lpObj->Name,lpObj->MapNumber,nextX,nextY,lpObj->X,lpObj->Y,attr);
							for(n = 0; n < 15;n++)
							{
								lpObj->PathX[n] = 0;
								lpObj->PathY[n] = 0;
								lpObj->PathOri[n] = 0;
							}
	
							lpObj->PathCount = 0;
							lpObj->PathCur = 0;
							lpObj->PathTime = GetTickCount();

							if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
							{
								lpObj->PathStartEnd = 0;
							}
	
							if(lpObj->Type == OBJ_USER)
							{
								gObjSetPosition(lpObj->m_Index,lpObj->X,lpObj->Y);
							}
						}
						else
						{
							lpObj->X = lpObj->PathX[lpObj->PathCur];
							lpObj->Y = lpObj->PathY[lpObj->PathCur];
							lpObj->Dir = lpObj->PathDir[lpObj->PathCur];

							lpObj->PathTime = GetTickCount();
							lpObj->PathCur++;

							if(lpObj->PathCur >= lpObj->PathCount)
							{
								lpObj->PathCur = 0;
								lpObj->PathCount = 0;

								if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
								{
									lpObj->PathStartEnd = 0;
								}
							}
						}
					}
				}
				CreateFrustrum(lpObj->X,lpObj->Y,n);
			}
		}
	}

	// STRANGE COMPILATION ... 
}


void gObjRefillProcess(int aIndex, LPOBJ lpObj)
{
	return;	// HEre is a MACRO
}


void Bot()
{
	//::Sleep(240000);
	int aIndex=OBJ_STARTUSERINDEX;

	GOBJ_BOT_INIT bot;
	strcpy_s(bot.AccountID, sizeof(bot.AccountID), "bot1");
	strcpy_s(bot.Name, sizeof(bot.Name),"TurboBot");
	bot.aIndex=aIndex;
	bot.Class=0x10; //DK
	bot.Dexterity=1000;
	bot.Energy=1000;
	bot.Experience=0;
	bot.Leadership=0;
	bot.Level=200;
	bot.MapNum=0;
	bot.PK_Count=0;
	bot.PK_Level=0;
	bot.Strength=1000;
	bot.Vitality=1000;
	bot.X=192;
	bot.Y=126;
	
	gObjBotInit(bot);

	while (1)
	{
		gObjBotMove(bot.aIndex,gObj[bot.aIndex].X+=2,gObj[bot.aIndex].Y+=2);
		Sleep(2000);
		gObjBotMove(bot.aIndex,gObj[bot.aIndex].X-=2,gObj[bot.aIndex].Y-=2);
		Sleep(2000);
		gObjBotChat("%",bot.aIndex);
		Sleep(2000);
	}



}





bool gObjBotInit(GOBJ_BOT_INIT bot)
{
	//---
	gObj[bot.aIndex].m_Index=bot.aIndex; //aIndex
	//---
	gObj[bot.aIndex].MapNumber=bot.MapNum;
	gObj[bot.aIndex].X=bot.X;
	gObj[bot.aIndex].Y=bot.Y;
	gObj[bot.aIndex].TX = gObj[bot.aIndex].X;
	gObj[bot.aIndex].TY = gObj[bot.aIndex].Y;	
	gObj[bot.aIndex].PathCount = 0;
	gObj[bot.aIndex].Teleport = 0;
	//---
	gObj[bot.aIndex].Level=bot.Level;
	gObj[bot.aIndex].Experience=bot.Experience;
	//---
	gObj[bot.aIndex].Class=bot.Class;
	//---
	gObj[bot.aIndex].Strength=bot.Strength;
	gObj[bot.aIndex].Dexterity=bot.Dexterity;
	gObj[bot.aIndex].Vitality=bot.Vitality;
	gObj[bot.aIndex].Energy=bot.Energy;
	gObj[bot.aIndex].Leadership=bot.Leadership;
	//---
	gObj[bot.aIndex].Type = OBJ_USER;
	gObj[bot.aIndex].PathTime = GetTickCount();
	gObj[bot.aIndex].m_RecallMon = -1;//��� ������� ��� �����
	//---
	gObj[bot.aIndex].bot=true;
	gObj[bot.aIndex].m_Change=0; //��� ����������� ���������
	gObj[bot.aIndex].Dir=1; // ��� �����������
	//---
	gObj[bot.aIndex].Connected = PLAYER_LOGGED;//����� ������� gObjSetCharacter ���� ����� ����� ���������
	//---
	gObj[bot.aIndex].m_PK_Level=bot.PK_Level;
	gObj[bot.aIndex].m_PK_Count=bot.PK_Count;
	//---
	gObj[bot.aIndex].RegenMapNumber = gObj[bot.aIndex].MapNumber;
	gObj[bot.aIndex].RegenMapX = (BYTE)gObj[bot.aIndex].X;//���������� ��������� ��������� ����� ������
	gObj[bot.aIndex].RegenMapY = (BYTE)gObj[bot.aIndex].Y;
	gObj[bot.aIndex].RegenOk=0;
	gObj[bot.aIndex].ChatLimitTime=0;//����� �� ��������� � ���. ������ ������� ������ ��� � ���� �� 1 ������
	//---

	strcpy_s(gObj[bot.aIndex].Name, sizeof(gObj[bot.aIndex].Name), bot.Name);
	strcpy_s(gObj[bot.aIndex].AccountID, sizeof(gObj[bot.aIndex].AccountID), bot.AccountID);

	//---
	SDHP_DBCHAR_INFORESULT lpmsg;
	//---
	lpmsg.AccountCtlCode=0;
	lpmsg.CtlCode=0;
	lpmsg.MapX=(BYTE)gObj[bot.aIndex].X;
	lpmsg.MapY=(BYTE)gObj[bot.aIndex].Y;
	lpmsg.MapNumber=gObj[bot.aIndex].MapNumber;
	lpmsg.Str=gObj[bot.aIndex].Strength;
	lpmsg.Dex=gObj[bot.aIndex].Dexterity;
	lpmsg.Vit=gObj[bot.aIndex].Vitality;
	lpmsg.Energy=gObj[bot.aIndex].Energy;
	lpmsg.Leadership=gObj[bot.aIndex].Leadership;
	lpmsg.Level=gObj[bot.aIndex].Level;
	lpmsg.Class=(BYTE)gObj[bot.aIndex].Class;
	lpmsg.PkLevel=gObj[bot.aIndex].m_PK_Level;
	lpmsg.PkCount=gObj[bot.aIndex].m_PK_Count;
	strcpy_s(lpmsg.Name, sizeof(lpmsg.Name), bot.Name);
	strcpy_s(lpmsg.AccountID, sizeof(lpmsg.AccountID), bot.AccountID);

	
	if (!gObjSetCharacter(&lpmsg,bot.aIndex))
		return false;

	gObjCalcMaxLifePower(bot.aIndex);
	gObjCalCharacter(bot.aIndex);

	CreateFrustrum(gObj[bot.aIndex].X,gObj[bot.aIndex].Y,bot.aIndex);

	gObjClearViewport(&gObj[bot.aIndex]);

	gObjViewportListProtocolCreate(&gObj[bot.aIndex]);

	return true;
}

void gObjBotChat(char* msg,int aIndex)
{
	PMSG_CHATDATA Chat;
	strcpy_s(Chat.chatmsg, sizeof(Chat.chatmsg), msg);
	Chat.h.size=14+strlen(msg);//14 ������ ������ ��������... ������ ������ ������ ���������� � 15... 
	Chat.h.c=193;//��� ���� �� ������ ����� 193
	Chat.h.headcode=0;//���������� ���� ����� 0
	gObj[aIndex].ChatLimitTime=0;
	PChatProc(&Chat,aIndex);
}

void gObjBotMove(int aIndex,int X,int Y)
{
	PMSG_MOVE Move;
	Move.X=X;
	Move.Y=Y;
	Move.Path[0]=gObj[aIndex].Dir << 4;
	gObj[aIndex].RegenOk=0;
	PMoveProc(&Move,aIndex);
}

void gObjInit()
{
	gObjCount=OBJ_STARTUSERINDEX;
	gObjMonCount=0;
	gObjCallMonCount= OBJ_MAXMONSTER;

	if (pTempInventory != NULL)
		delete[] pTempInventory;

	if (pTempInventoryMap != NULL)
		delete[] pTempInventoryMap;

	pTempInventory = new CItem[INVENTORY_SIZE];
	pTempInventoryMap = new BYTE [INVENTORY_MAP_SIZE];

	int ChatTime = GetTickCount();

	for ( int n = 0; n< OBJMAX ; n++)
	{
		memset(&gObj[n], 0, sizeof(OBJECTSTRUCT));
		gObj[n].Type = (BYTE)OBJ_EMPTY;
		gObj[n].m_socket = INVALID_SOCKET;
		gObj[n].PathTime = GetTickCount();
		gObj[n].m_RecallMon = -1;
		gObj[n].m_lpMagicBack = new CMagicInf[MAGIC_SIZE];
		gObj[n].Magic = new CMagicInf[MAGIC_SIZE];
		
		if ( n >= OBJ_STARTUSERINDEX )
		{
			gObj[n].Inventory1 = new CItem[INVENTORY_SIZE];
			gObj[n].Inventory2 = new CItem[INVENTORY_SIZE];
			gObj[n].InventoryMap1 = new BYTE[INVENTORY_MAP_SIZE];
			gObj[n].InventoryMap2 = new BYTE[INVENTORY_MAP_SIZE];
		}
		else
		{
			gObj[n].Inventory1 = pTempInventory;
			gObj[n].Inventory2 = pTempInventory;
			gObj[n].InventoryMap1 = pTempInventoryMap;
			gObj[n].InventoryMap2 = pTempInventoryMap;
		}

		if ( n >= OBJ_STARTUSERINDEX )
		{
			gObj[n].Trade = new CItem[TRADE_BOX_SIZE];
			gObj[n].TradeMap = new BYTE[TRADE_BOX_MAP_SIZE];
			gObj[n].pWarehouse = new CItem[WAREHOUSE_SIZE];
			gObj[n].pWarehouseMap = new BYTE[WAREHOUSE_SIZE];
		}
		
		gObj[n].WarehouseCount = 0;
		gObj[n].pChaosBox = NULL;
		
		if ( n >= OBJ_STARTUSERINDEX )
		{
			gObj[n].PerSocketContext = new _PER_SOCKET_CONTEXT;
		}

		gObj[n].ChatTickCount = ChatTime;

		InitializeCriticalSection(&gObj[n].m_critPShopTrade);
	}


	InitFrustrum();
	HANDLE bThread4;
	//bThread4 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Bot,NULL,0,0);

}






void gObjEnd()
{
	gObjAllDisconnect();
	gObjAllLogOut();

	for ( int n=0; n< OBJMAX; n++)
	{
		if ( gObj[n].m_lpMagicBack != NULL )
		{
			delete [] gObj[n].m_lpMagicBack;
		}

		if ( gObj[n].Magic != NULL )
		{
			delete [] gObj[n].Magic;
		}


		if ( n >= OBJ_STARTUSERINDEX )
		{
			if ( gObj[n].Inventory1 != NULL )
			{
				delete[] gObj[n].Inventory1;
			}

			if ( gObj[n].Inventory2 != NULL )
			{
				delete[] gObj[n].Inventory2;
			}

			if ( gObj[n].InventoryMap1 != NULL )
			{
				delete[] gObj[n].InventoryMap1;
			}

			if ( gObj[n].InventoryMap2 != NULL )
			{
				delete[] gObj[n].InventoryMap2;
			}

			if ( gObj[n].PerSocketContext != NULL )
			{
				delete gObj[n].PerSocketContext;
			}

			if ( gObj[n].Trade != NULL )
			{
				delete[] gObj[n].Trade;
			}

			if ( gObj[n].TradeMap != NULL )
			{
				delete[] gObj[n].TradeMap;
			}

			if ( gObj[n].pWarehouse != NULL )
			{
				delete[] gObj[n].pWarehouse;
			}

			if ( gObj[n].pWarehouseMap != NULL )
			{
				delete[] gObj[n].pWarehouseMap;
			}
		}

		DeleteCriticalSection( &gObj[n].m_critPShopTrade );
	}
	delete[] pTempInventory;
	delete[] pTempInventoryMap;
}






void gObjClearViewportOfMine(LPOBJ lpObj)
{
	for (int i=0;i<MAX_VIEWPORT;i++)
	{
		lpObj->VpPlayer[i].state =0;
		lpObj->VpPlayer[i].number =-1;
	}

	lpObj->VPCount=0;
}







void gObjClearViewport(LPOBJ lpObj)
{
	for ( int i=0;i<MAX_VIEWPORT;i++)
	{
		lpObj->VpPlayer[i].state=0;
		lpObj->VpPlayer[i].number =-1;
		lpObj->VpPlayer2[i].state=0;
		lpObj->VpPlayer2[i].number=-1;
	}

	lpObj->VPCount = 0;
	lpObj->VPCount2 = 0;
}







void gObjCloseSet(int aIndex, int Flag)
{
	if ( aIndex < 0 || aIndex > OBJMAX-1 )
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if ( lpObj->CloseCount > 0 )
	{
		return;
	}

	if ( lpObj->Connected == PLAYER_PLAYING )
	{
		
		if ( BC_MAP_RANGE(lpObj->MapNumber) )
		{
			g_BloodCastle.SearchUserDropQuestItem(aIndex);
		}

		if ( (GetTickCount() - lpObj->MySelfDefenseTime )< 30000)
		{
			GCServerMsgStringSend("Defense setting", lpObj->m_Index, 1);
			return;
		}

		if ( (lpObj->m_IfState.use != 0 ) && ( ( lpObj->m_IfState.type == 1 ) || (lpObj->m_IfState.type == 6) || (lpObj->m_IfState.type == 13) || (lpObj->m_IfState.type == 7)  ) ) 
		{
			gObjSaveChaosBoxItemList(lpObj);
			switch ( lpObj->m_IfState.type )
			{
				case 1:
					GCServerMsgStringSend("Close the trading window and exit", lpObj->m_Index, 1);
					break;

				case 6:
					GCServerMsgStringSend("Close the vault and exit", lpObj->m_Index, 1);
					break;

				case 7:
					GCServerMsgStringSend("Close the Chaos Machine window before you EXIT the game.", lpObj->m_Index, 1);
					break;

				case 13:
					GCServerMsgStringSend("Disconnect only after closing the Training window.", lpObj->m_Index, 1);
					break;
			}

			return;
		}
	}

	
	lpObj->CloseCount = 6;
	lpObj->CloseType = Flag;
	lpObj->bEnableDelCharacter = 1;
	
}







void gObjCharTradeClear(LPOBJ lpObj)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return;
	}

	memset(lpObj->TradeMap, 0xFF , TRADE_BOX_SIZE);

	for ( int i=0 ; i< TRADE_BOX_SIZE ; i++)
	{
		lpObj->Trade[i].Clear();
	}

	lpObj->TradeMoney = 0;
	lpObj->TradeOk = false;
}






void gObjCharZeroSet(int aIndex)
{
	int i;
	LPOBJ lpObj = &gObj[aIndex];
	int n;

	memset( lpObj->Name, 0, MAX_ACCOUNT_LEN);
	memset( lpObj->GuildName, 0, sizeof (lpObj->GuildName ));
	lpObj->m_Option = 3;
	lpObj->m_iScriptMaxLife = 0;
	lpObj->Level = 0;

	memset( lpObj->BackName,0,sizeof(lpObj->BackName));

	lpObj->Life = 0;
	lpObj->MaxLife = 0;
	lpObj->AddLife = 0;
	lpObj->AddMana = 0;
	lpObj->Live = FALSE;
	lpObj->Dir = 0;
	lpObj->X = 0;
	lpObj->Y = 0;
	lpObj->TX = 0;
	lpObj->TY = 0;
	lpObj->MTX = 0;
	lpObj->MTY = 0;
	lpObj->MapNumber = MAP_INDEX_LORENCIA;
	lpObj->RegenTime = 0;
	lpObj->m_State = 0;
	lpObj->RegenOk = 0;
	lpObj->lpAttackObj = 0;
	lpObj->PartyTargetUser = -1;
	lpObj->m_MoveGateNumber = -1;
	lpObj->CloseCount = -1;
	lpObj->CloseType = -1;
	lpObj->m_IfState.state = -1;
	lpObj->m_IfState.type = -1;
	lpObj->m_IfState.use = 0;
	lpObj->m_InterfaceTime = 0;
	lpObj->m_ActionNumber = 0;
	lpObj->m_State = 0;
	lpObj->m_StateSub = 0;
	lpObj->m_ViewState = 0;
	lpObj->m_Rest = 0;

	lpObj->iMaxShield = 0;
	lpObj->iShield = 0;
	lpObj->iAddShield = 0;
	lpObj->iFillShield = 0;
	lpObj->iFillShieldMax = 0;
	lpObj->iFillShieldCount = 0;
	lpObj->dwShieldAutoRefillTimer = 0;
	lpObj->m_wItemEffectType = 0;
	lpObj->m_iItemEffectValidTime = 0;
	lpObj->m_wCashPoint = 0;
	lpObj->m_iPeriodItemEffectIndex = -1;
	lpObj->m_wExprienceRate = 100;
	lpObj->m_wItemDropRate = 100;

	lpObj->m_ViewSkillState = 0;
	lpObj->m_PoisonBeattackCount = 0;
	lpObj->m_ColdBeattackCount = 0;
	lpObj->m_Attribute = 0;
	lpObj->m_ImmuneToMagicCount = 0;
	lpObj->m_ImmuneToHarmCount = 0;
	lpObj->m_iMonsterBattleDelay = 0;
	lpObj->m_cKalimaGateExist = FALSE;
	lpObj->m_iKalimaGateIndex = -1;
	lpObj->m_cKalimaGateEnterCount = 0;
	lpObj->TradeOk = false;
	lpObj->sHDCount = 0;
	lpObj->PathCount = 0;
	lpObj->PathCur = 0;
	lpObj->PathStartEnd = 0;
	lpObj->VPCount = 0;
	lpObj->VPCount2 = 0;
	lpObj->m_ShopTime = 0;
	lpObj->m_ManaFillCount = 0;
	lpObj->FillLife = 0;
	lpObj->iObjectSecTimer = 0;
	lpObj->m_FriendServerOnline = FALSE;
	lpObj->SetOpAddMaxAttackDamage = 0;
	lpObj->SetOpAddMinAttackDamage = 0;
	lpObj->SetOpAddDamage = 0;
	lpObj->SetOpIncAGValue = 0;
	lpObj->SetOpAddCriticalDamageSuccessRate = 0;
	lpObj->SetOpAddCriticalDamage = 0;
	lpObj->SetOpAddExDamageSuccessRate = 0;
	lpObj->SetOpAddExDamage = 0;
	lpObj->SetOpAddSkillAttack = 0;
	lpObj->AddStrength = 0;
	lpObj->AddDexterity = 0;
	lpObj->AddVitality = 0;
	lpObj->AddEnergy = 0;
	lpObj->SetOpAddAttackDamage = 0;
	lpObj->SetOpAddDefence = 0;
	lpObj->SetOpAddMagicPower = 0;
	lpObj->SetOpAddDefenceRate = 0;
	lpObj->SetOpIgnoreDefense = 0;
	lpObj->SetOpDoubleDamage = 0;
	lpObj->SetOpTwoHandSwordImproveDamage = 0;
	lpObj->SetOpImproveSuccessAttackRate = 0;
	lpObj->SetOpReflectionDamage = 0;
	lpObj->SetOpImproveSheldDefence = 0;
	lpObj->SetOpDecreaseAG = 0;
	lpObj->SetOpImproveItemDropRate = 0;
	memset( lpObj->m_AddResistance, 0, sizeof(lpObj->m_AddResistance));
	lpObj->IsFullSetItem = false;
	lpObj->DamageMinus = 0;
	lpObj->DamageReflect = 0;
	lpObj->MonsterDieGetMoney = 0;
	lpObj->MonsterDieGetLife = 0;
	lpObj->MonsterDieGetMana = 0;
	lpObj->m_CriticalDamage = 0;
	lpObj->m_ExcelentDamage = 0;
	lpObj->UseMagicNumber = 0;
	lpObj->UseMagicTime = 0;
	lpObj->UseMagicCount = 0;
	lpObj->OSAttackSerial = -1;
	lpObj->SASCount = 0;
	lpObj->SkillAttackTime = GetTickCount();
	lpObj->m_AttackSpeed = 0;
	lpObj->m_MagicSpeed = 0;
	lpObj->m_TotalAttackTime = GetTickCount();
	lpObj->m_TotalAttackCount = 0;
	lpObj->CheckSumTime = GetTickCount() + 10000;
	lpObj->CheckSumTableNum = -1;
	lpObj->m_SumLastAttackTime = 0;
	lpObj->m_DetectCount = 0;
	lpObj->m_DetectSpeedHackTime = 0;
	lpObj->m_SpeedHackPenalty = 0;
	lpObj->m_DetectedHackKickCount = 0;
	lpObj->IsInBattleGround = false;
	lpObj->m_dwPKTimer = GetTickCount();
	lpObj->CheckTickCount = 0;
	lpObj->m_AttackSpeedHackDetectedCount = 0;

	for ( n =0;n<MAX_VIEWPORT ;n++)
	{
		lpObj->VpPlayer[n].state = 0;
		lpObj->VpPlayer2[n].state = 0;
		lpObj->VpPlayer[n].number = -1;
		lpObj->VpPlayer2[n].number = -1;
	}

	lpObj->GuildNumber = 0;
	lpObj->lpGuild = NULL;
	lpObj->PartyNumber = -1;
	lpObj->PartyTargetUser = -1;
	lpObj->m_Drink = 0;
	lpObj->Authority = 0;
	lpObj->AuthorityCode = 0;
	lpObj->Penalty = 0;
	lpObj->m_RecallMon = -1;
	lpObj->m_Change = -1;
	lpObj->GuildStatus = -1;
	lpObj->LastAttackerID = -1;
	lpObj->m_cChaosCastleIndex= -1;
	lpObj->m_cChaosCastleSubIndex = -1;
	lpObj->m_iChaosCastleBlowTime = 0;
	lpObj->m_cKillUserCount = 0;
	lpObj->m_cKillMonsterCount = 0;
	lpObj->m_InWebzen = false;
	memset( lpObj->CharSet, 0, sizeof(lpObj->CharSet));

	for ( i =0; i<MAX_SELF_DEFENSE;i++)
	{
		lpObj->SelfDefense[i] = -1;
		lpObj->SelfDefenseTime[i] = 0;
	}

	lpObj->MySelfDefenseTime = 0;
	lpObj->m_MagicDefense = 0;
	lpObj->m_SkillDefense = 0;
	lpObj->m_SkillDefenseTime = 0;
	lpObj->m_SkillAttack = 0;
	lpObj->m_SkillAttackTime = 0;
	lpObj->m_SkillAttack2 = 0;
	lpObj->m_SkillAttackTime2 = 0;
	lpObj->LoadWareHouseInfo = false;
	lpObj->m_SkillAddLife = 0;
	lpObj->m_SkillAddLifeTime = 0;
	lpObj->m_SkillHarden = 0;
	lpObj->m_SkillHardenTime = 0;
	lpObj->m_SkillMagumReduceDefense = 0;
	lpObj->m_SkillMagumReduceDefenseTime = 0;
	lpObj->m_SkyBossMonSheildLinkIndex = -1;
	lpObj->m_SkyBossMonSheild = 0;
	lpObj->m_SkyBossMonSheildTime = 0;
	lpObj->m_bAttackerKilled = false;
	lpObj->m_MoveOtherServer = 0;
	lpObj->m_BossGoldDerconMapNumber = -1;
	lpObj->TargetNumber =	0;
	lpObj->TargetShopNumber = 0;
	lpObj->WarehouseMoney = 0;
	lpObj->WarehouseSave = 0;
	lpObj->WarehouseLock = -1;
	lpObj->WarehouseCount = 0;
	lpObj->WarehousePW = 0;
	lpObj->WarehouseUnfailLock = 0;
	lpObj->m_bDevilSquareAuth = false;
	lpObj->m_TimeCount = 0;
	lpObj->EventChipCount = 0;
	lpObj->MutoNumber = 0;
	lpObj->HaveWeaponInHand = false;
	lpObj->m_ReqWarehouseOpen = 0;
	lpObj->iStoneCount = 0;
	lpObj->m_iDuelUserReserved = -1;
	lpObj->m_iDuelUserRequested = -1;
	lpObj->m_iDuelUser = -1;
	lpObj->m_btDuelScore = 0;
	lpObj->m_iDuelTickCount = 0;
	lpObj->m_MaxLifePower = 0;
	lpObj->m_WizardSkillDefense = 0;
	lpObj->m_WizardSkillDefenseTime = 0;
	lpObj->m_PacketChecksumTime = 0;
	lpObj->AddBP = 0;
	lpObj->m_CheckLifeTime = 0;
	memset(lpObj->m_Quest, (BYTE)-1, sizeof(lpObj->m_Quest));
	lpObj->m_SendQuestInfo = 0;
	gPacketCheckSum.ClearCheckSum(lpObj->m_Index);
	lpObj->PlusStatQuestClear = false;
	lpObj->ComboSkillquestClear = false;
	lpObj->m_LastTeleportTime = 0;
	lpObj->m_ClientHackLogCount = 0;
	lpObj->UseEventServer = FALSE;

	if ( lpObj->Type == OBJ_USER )
	{
		memset(lpObj->pWarehouseMap, (BYTE)-1, WAREHOUSE_SIZE);
		memset(lpObj->TradeMap, (BYTE)-1, TRADE_BOX_SIZE);
	}

	for ( i=0;i<MAX_MAGIC ; i++)
	{
		lpObj->Magic[i].Clear();
	}

	lpObj->MagicCount = 0;

	for ( i=0;i<MAX_MONSTER_SEND_MSG;i++)
	{
		gSMMsg[aIndex][i].MsgCode = -1;
	}

	lpObj->m_bIsInMonsterHerd = false;
	lpObj->m_bIsMonsterAttackFirst = true;
	lpObj->m_lpMonsterHerd = NULL;

	if ( (aIndex-OBJ_STARTUSERINDEX) >= 0 )
	{
		for ( i=0;i<MAX_MONSTER_SEND_ATTACK_MSG;i++)
		{
			gSMAttackProcMsg[aIndex-OBJ_STARTUSERINDEX][i].MsgCode = -1;
		}
	}

	lpObj->SkillHellFire2State = 0;
	lpObj->SkillHellFire2Count = 0;
	lpObj->m_PoisonType = 0;
	lpObj->m_IceType = 0;
	lpObj->Leadership = 0;
	lpObj->AddLeadership = 0;
	lpObj->ChatLimitTime = 0;
	lpObj->ChatLimitTimeSec = 0;
	lpObj->SkillRecallParty_Time = 0;
	lpObj->SkillAddCriticalDamageTime = 0;
	lpObj->SkillAddCriticalDamage = 0;
	lpObj->SkillLongSpearChange = false;
	lpObj->SkillDelay.Init();

	lpObj->bEnableDelCharacter = 1;

	if ( lpObj->Type == OBJ_USER )
	{
		for (i=0;i<WAREHOUSE_SIZE;i++)
		{
			lpObj->pWarehouse[i].Clear();
		}
	}

	::gMultiAttackHackCheck[aIndex].Init();
	lpObj->pTransaction = 0;
	::gObjMonsterHitDamageInit(lpObj);
	::gObjSetInventory1Pointer(&gObj[aIndex]);

	if ( lpObj->Type == OBJ_USER )
	{
		memset(lpObj->pInventoryMap, (BYTE)-1, INVENTORY_MAP_SIZE);
	}

	lpObj->m_bPShopOpen = false;
	lpObj->m_bPShopTransaction = false;
	lpObj->m_bPShopItemChange = false;
	lpObj->m_bPShopRedrawAbs = false;
	memset(lpObj->m_szPShopText, 0, sizeof(lpObj->m_szPShopText));
	lpObj->m_bPShopWantDeal = false;
	lpObj->m_iPShopDealerIndex = -1;
	memset(lpObj->m_szPShopDealerName, 0, sizeof(lpObj->m_szPShopDealerName));
	memset(lpObj->m_iVpPShopPlayer, 0, sizeof(lpObj->m_iVpPShopPlayer));
	lpObj->m_wVpPShopPlayerCount =0;
	lpObj->iGuildUnionTimeStamp = 0;
	::gObjCharTradeClear(lpObj);

	if ( lpObj->Type == OBJ_USER )
	{
		for ( i=0;i<WAREHOUSE_SIZE;i++)
		{
			lpObj->pWarehouse[i].Clear();
		}

		for ( i=0;i<INVENTORY_SIZE;i++)
		{
			lpObj->Inventory1[i].Clear();
		}

		for ( i=0;i<INVENTORY_SIZE;i++)
		{
			lpObj->Inventory2[i].Clear();
		}

		for ( i=0;i<TRADE_BOX_SIZE;i++)
		{
			lpObj->Trade[i].Clear();
		}
	}

	lpObj->bIsChaosMixCompleted = false;
	lpObj->m_bMapSvrMoveQuit = false;

 

	lpObj->m_iCsNpcExistVal = 0;
	lpObj->m_btCsNpcType = 0;
	lpObj->m_btCsGateOpen = 0;
	lpObj->m_iCsGateLeverLinkIndex = -1;
	lpObj->m_btCsNpcDfLevel = 0;
	lpObj->m_btCsNpcRgLevel = 0;
	lpObj->m_btCsJoinSide = 0;
	lpObj->m_bCsGuildInvolved = 0;



	lpObj->m_bIsCastleNPCUpgradeCompleted = false;
	lpObj->m_btWeaponState = 0;
	lpObj->m_btKillCount = 0;
	lpObj->m_iSkillStunTime = 0;
	lpObj->m_iSkillBrandOfSkillTime = 0;
	lpObj->m_iSkillInvisibleTime = 0;
	lpObj->m_iSkillManaSwellTime = 0;
	lpObj->m_iSkillManaSwell = 0;
	lpObj->m_iPotionBlessTime = 0;
	lpObj->m_iPotionSoulTime = 0;
	lpObj->m_iAccumulatedDamage = 0;

 

	lpObj->m_iCreatedActivationTime = 0;
	lpObj->m_btLifeStoneCount = 0;


	lpObj->m_iAccumulatedCrownAccessTime = 0;

	lpObj->m_iSkillNPCHelpTime = 0;
	lpObj->m_iSkillNPCDefense = 0;
	lpObj->m_iSkillNPCAttack = 0;
	lpObj->m_iMuseElfInfinityArrowSkillTime = 0;

	lpObj->m_MonsterSkillElementInfo.Reset();
	lpObj->m_iCrywolfMVPScore = 0;
	lpObj->m_iSkillDistanceErrorCount = 0;
	lpObj->m_dwSkillDistanceErrorTick = 0;
	g_kJewelOfHarmonySystem.InitEffectValue(&lpObj->m_JewelOfHarmonyEffect);
	g_kItemSystemFor380.InitEffectValue(&lpObj->m_ItemOptionExFor380);
 
	lpObj->m_bKanturuEntranceByNPC = 0;

	::gObjClearViewport(&gObj[aIndex]);
}






int gObjGetSocket(SOCKET socket)
{
	for (int n=OBJ_STARTUSERINDEX;n<OBJMAX;n++)
	{
		if (gObj[n].Connected != PLAYER_EMPTY)
		{
			if (gObj[n].m_socket == socket)
			{
				return n;
			}
		}
	}
	return -1;
}






void gObjSetTradeOption( int aIndex, int option)
{
	if ( gObjIsConnected(aIndex) == TRUE )
	{
		if ( option == 0 )
		{
			gObj[aIndex].m_Option = 0;
			GCServerMsgStringSend("You are now rejecting all requests from other players.", aIndex, 1);
		}
		else
		{
			gObj[aIndex].m_Option |= 1;
			GCServerMsgStringSend("You are now accepting all requests from other players.", aIndex, 1);
		}
	}
}





void gObjSetDuelOption(int aIndex, int option)
{
	if ( gObjIsConnected(aIndex) == TRUE )
	{
		if ( option == 0 )
		{
			gObj[aIndex].m_Option = 0;
		}
		else
		{
			gObj[aIndex].m_Option |= 2;
		}
	}
}






bool IsDuelEnable(int aIndex)
{
	if ( OBJMAX_RANGE(aIndex ) == FALSE)
	{
		return false;
	}

	if ( gObjIsConnected(aIndex) == TRUE )
	{
		if ( (gObj[aIndex].m_Option&2) == 2 )
		{
			return true;
		}
	}

	return false;
}







bool IsOnDuel(int aIndex1, int aIndex2 )
{
	if ( OBJMAX_RANGE(aIndex1) == FALSE || OBJMAX_RANGE(aIndex2) == FALSE )
	{
		return false;
	}

	if ( gObj[aIndex1].Type != OBJ_USER || gObj[aIndex2].Type != OBJ_USER )
	{
		return false;
	}

	if ( gObj[aIndex1].m_iDuelUser == aIndex2 && gObj[aIndex2].m_iDuelUser == aIndex1 )
	{
		return true;
	}

	return false;
}






int GetMapMoveLevel(LPOBJ lpObj, int mapnumber, int max_over)
{
	int overLevel = 0;

	if ( mapnumber > MAX_NUMBER_MAP-1 )
	{
		mapnumber = 0;
		LogAdd("error-L3 : map number not %s %d", __FILE__, __LINE__);
		return 0;
	}

	if ( max_over != 0 )
	{
		overLevel = max_over;
	}
	else
	{
		max_over = MapMinUserLevel[mapnumber];
		overLevel = MapMinUserLevel[mapnumber];
	}
	
	if ( lpObj->Class == 4 || lpObj->Class == 3 )
	{
		if ( overLevel > 0 && max_over > 0 )
		{
			overLevel = (max_over/3)*2;
		}
	}

	return overLevel;
}






// ! REWRITE HERE !

/*
void DbItemSetInByte(LPOBJ lpObj, struct SDHP_DBCHAR_INFORESULT* lpMsg, int ItemDbByte, bool* bAllItemExist)
{
	int n;
	int itype;
	int _type;
	CItem item;
	BYTE OptionData;
	WORD hiWord;
	WORD loWord;
	bool bIsItemExist = true;

	for ( n=0;n<INVENTORY_SIZE;n++)
	{
		bIsItemExist = TRUE;
		itype = lpMsg->dbInventory[n * ItemDbByte+DBI_TYPE];

		if ( lpMsg->dbInventory[n * ItemDbByte+DBI_TYPE] == (BYTE)-1 && (lpMsg->dbInventory[n * ItemDbByte+DBI_NOPTION_DATA]&0x80) == 0x80 )
		{
			continue;
		}

		if ( ItemDbByte == 10 )
		{
			if ( (lpMsg->dbInventory[n * ItemDbByte+DBI_NOPTION_DATA] & 0x80) == 0x80 )
			{
				itype += 0x100;
			}

			_type = itype;
		}
		else
		{
			_type = (itype / MAX_TYPE_ITEMS * MAX_SUBTYPE_ITEMS) % MAX_TYPE_ITEMS;
		}

		lpObj->pInventory[n].Clear();

		if ( lpMsg->dbInventory[n * ItemDbByte+DBI_TYPE] == (BYTE)-1 && (lpMsg->dbInventory[n * ItemDbByte+DBI_NOPTION_DATA]&0x80) == 0x80 )
		{
			itype = -1;
		}

		if ( IsItem(_type)== FALSE )
		{
			bIsItemExist = false;

			if (  bAllItemExist != NULL )
			{
				 *bAllItemExist = FALSE;
			}
		}

		if ( _type == ITEMGET(14,17) || _type == ITEMGET(14,18) )	// Decvil Eye and Key
		{
			if ( lpMsg->dbInventory[n * ItemDbByte+DBI_DUR] == 0 )
			{
				itype = -1;
			}
		}

		if ( _type == ITEMGET(14,19) ) // Devil Invitation
		{
			if ( lpMsg->dbInventory[n * ItemDbByte+DBI_DUR] == -1 )
			{
				itype = -1;
			}
		}

		if ( itype != -1 )
		{
			item.m_Level = lpMsg->dbInventory[n * ItemDbByte+DBI_OPTION_DATA] >> 3 & MAX_ITEM_LEVEL;	// Limit Max LEvel to 15

			if ( lpMsg->DbVersion < 2 )
			{
				lpMsg->dbInventory[n * ItemDbByte+DBI_SOPTION_DATA] = -1;
				lpMsg->dbInventory[n * ItemDbByte+DBI_OPTION380_DATA] = -1;
			}

			if ( _type == ITEMGET(14,11) ) // Box Of Luck
			{
				if ( item.m_Level > 13 )
				{
					item.m_Level = 0;
				}
			}

			OptionData = lpMsg->dbInventory[n * ItemDbByte+DBI_OPTION_DATA];
			item.m_Option1 = OptionData >> 7;
			item.m_Option2 = (OptionData >> 2) & 1;
			item.m_Option3 = OptionData & 3;

			if ( ItemDbByte == 10 )
			{
				if ( _type == ITEMGET(13,3) ) // Dino
				{
					item.m_Option3 |= (lpMsg->dbInventory[n * ItemDbByte+DBI_NOPTION_DATA] & 0x40) >> 4;
				}
				else if ( (lpMsg->dbInventory[n * ItemDbByte+DBI_NOPTION_DATA] & 0x40) == 0x40 )
				{
					item.m_Option3 = 4;	// Set +16 Option
				}
			}

			item.m_Durability = lpMsg->dbInventory[n * ItemDbByte+DBI_DUR];

			if ( ItemDbByte == 7 )
			{
				item.Convert(itype, item.m_Option1, item.m_Option2, item.m_Option3, 0,0, 0, 0);
			}
			else
			{
				item.Convert(itype, item.m_Option1, item.m_Option2, item.m_Option3,
					lpMsg->dbInventory[n * ItemDbByte+DBI_NOPTION_DATA] & 0x3F, 
					lpMsg->dbInventory[n * ItemDbByte+DBI_SOPTION_DATA],0 , 1);
			}

			if ( _type == ITEMGET(14,7) ) // Siege Potion
			{

			}
			else if ( _type >= ITEMGET(14,0) && _type <= ITEMGET(14,8) ) // Potions
			{
				if ( item.m_Durability <= 0.0f )
				{
					item.m_Durability = 1.0f;
				}

				if ( item.m_Durability > 3.0f ) // Potion BUG
				{
					item.m_Durability = 3.0f;
				}
			}
			else if ( _type != ITEMGET(14,0) && _type != ITEMGET(14,8) && _type != ITEMGET(14,0) && item.m_Level == 3  )
			{
				if ( item.m_Durability < item.m_BaseDurability && bIsItemExist == true )
				{
					item.m_Durability = item.m_BaseDurability;
				}
			}

			lpObj->pInventory[n].m_Option1 = item.m_Option1;
			lpObj->pInventory[n].m_Option2 = item.m_Option2;
			lpObj->pInventory[n].m_Option3 = item.m_Option3;
			hiWord = MAKE_NUMBERW(lpMsg->dbInventory[n * ItemDbByte+DBI_SERIAL1], lpMsg->dbInventory[n * ItemDbByte+DBI_SERIAL2]);
			loWord = MAKE_NUMBERW(lpMsg->dbInventory[n * ItemDbByte+DBI_SERIAL3], lpMsg->dbInventory[n * ItemDbByte+DBI_SERIAL4]);

			item.m_Number = MAKELONG(hiWord, loWord);

			gObjInventoryInsertItemPos(lpObj->m_Index, item, n, FALSE);

			if ( bIsItemExist == false )
			{
				lpObj->pInventory[n].m_bItemExist = false;

				LogAdd("error-L2 : Unknown Item found [%s][%s] (Type:%d, LEV:%d, DUR:%d, OP1:%d, OP2:%d, OP3:%d, NEWOP:%d, SET:%d)",
					lpObj->AccountID, lpObj->Name, lpObj->pInventory[n].m_Number, 
					lpObj->pInventory[n].m_Level, lpObj->pInventory[n].m_Durability, 
					lpObj->pInventory[n].m_Option1, lpObj->pInventory[n].m_Option2,
					lpObj->pInventory[n].m_Option3, lpObj->pInventory[n].m_NewOption,
					lpObj->pInventory[n].m_SetOption);
			}
		}
	
	}
	
	gObjRequestPetItemInfo(lpObj->m_Index, 0);
}
*/

void DbItemSetInByte(LPOBJ lpObj, struct SDHP_DBCHAR_INFORESULT* lpMsg, int ItemDbByte, bool* bAllItemExist)
{
	int n;
	int itype;
	int _type;
	CItem item;
	BYTE OptionData;
	WORD hiWord;
	WORD loWord;
	bool bIsItemExist = true;

	for(n = 0; n < INVENTORY_SIZE;n++)
	{
		bIsItemExist = true;
		lpObj->pInventory[n].Clear();
		itype = lpMsg->dbInventory[n*ItemDbByte];

		if(ItemDbByte >= 16)
		{
			if(lpMsg->dbInventory[n*ItemDbByte] == 0xFF
				&& (lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA] & 0x80) == 0x80
				&& (lpMsg->dbInventory[n*ItemDbByte+DBI_OPTION380_DATA] & 0xF0) == 0xF0)
			{
				continue;
			}
		}
		else if(ItemDbByte > 7)
		{
			if(lpMsg->dbInventory[n*ItemDbByte] == 0xFF
				&& (lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA] & 0x80) == 0x80)
			{
				continue;
			}
		}
		else
		{
			if(lpMsg->dbInventory[n*ItemDbByte+DBI_TYPE] == 0xFF)
			{
				continue;
			}
		}

		if(ItemDbByte == 16)
		{
			itype |= (lpMsg->dbInventory[n*ItemDbByte+DBI_OPTION380_DATA] & 0xF0) * 32;
			itype |= (lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA] & 0x80) * 2;
			_type = itype;
		}
		else if(ItemDbByte == 10)
		{
			if((lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA] & 0x80) == 0x80)
			{
				itype += 256;
			}

			_type = ((itype / 32) * 512) + itype % 32;
		}
		else
		{
			_type = ((itype / 16) * 512) + itype % 16;
		}

		if(ItemDbByte >= 16)
		{
			if(lpMsg->dbInventory[n*ItemDbByte] == 0xFF
				&& (lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA] & 0x80) == 0x80
				&& (lpMsg->dbInventory[n*ItemDbByte+DBI_OPTION380_DATA] & 0xF0) == 0xF0)
			{
				itype = -1;
			}
		}
		else if(ItemDbByte >= 10)
		{
			if(lpMsg->dbInventory[n*ItemDbByte] == 0xFF
				&& (lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA] & 0x80) == 0x80)
			{
				itype = -1;
			}
		}
		else
		{
			if(lpMsg->dbInventory[n*ItemDbByte+DBI_TYPE] == 0xFF)
			{
				itype = -1;
			}
		}

		if(IsItem(_type) == false)
		{
			bIsItemExist = 0;

			if(bAllItemExist != 0)
			{
				*bAllItemExist = 0;
			}
		}

		if(_type == ITEMGET(14,17) || _type == ITEMGET(14,18))
		{
			if(lpMsg->dbInventory[n*ItemDbByte+DBI_DUR]==0)
			{
				itype = -1;
			}
		}

        if(_type == ITEMGET(13,49) || _type == ITEMGET(13,50))
        {
                if(lpMsg->dbInventory[n*ItemDbByte+DBI_DUR]==0)
                {
                        itype = -1;
                }
        }

		if(_type == ITEMGET(14,19))
		{
			if(lpMsg->dbInventory[n*ItemDbByte+DBI_DUR]==(BYTE)-1)
			{
				itype = -1;
			}
		}

		if(itype != -1)
		{
			item.m_Level = DBI_GET_LEVEL(lpMsg->dbInventory[n*ItemDbByte+DBI_OPTION_DATA]);

			if(lpMsg->DbVersion < 2)
			{
				lpMsg->dbInventory[n*ItemDbByte+DBI_SOPTION_DATA] = -1;
				lpMsg->dbInventory[n*ItemDbByte+DBI_OPTION380_DATA] = -1;
			}

			if(_type != ITEMGET(14,11))
			{
				if(item.m_Level > 13)
				{
					item.m_Level = 0;
				}
			}

			OptionData = lpMsg->dbInventory[n*ItemDbByte+DBI_OPTION_DATA];
			item.m_Option1 = DBI_GET_SKILL(OptionData);
			item.m_Option2 = DBI_GET_LUCK(OptionData);
			item.m_Option3 = DBI_GET_OPTION(OptionData);

			if(ItemDbByte >= 10)
			{
				//if(_type == ITEMGET(13,3))
				//{
					item.m_Option3 |= DBI_GET_OPTION16(lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA]) >> 4;
				/*}
				else
				{
					if((lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA] & 0x40)== 0x40)
					{
						item.m_Option3 = 7;
					}
				}*/
			}

			item.m_Durability = lpMsg->dbInventory[n*ItemDbByte+DBI_DUR];

			if(ItemDbByte >= 16)
			{
				item.m_JewelOfHarmonyOption = lpMsg->dbInventory[n*ItemDbByte+DBI_JOH_DATA];
			}

			if(ItemDbByte >= 16)
			{
				item.m_ItemOptionEx = DBI_GET_380OPTION(lpMsg->dbInventory[n*ItemDbByte+DBI_OPTION380_DATA]);

				if(item.m_ItemOptionEx)
				{
					item.m_Type = itype;

					if(g_kItemSystemFor380.Is380Item(&item)==false)
					{
						item.m_ItemOptionEx = 0;
						LogAdd("[380Item][%s][%s] Invalid 380 Item Option in Inventory pos[%d]",
							lpObj->AccountID,lpObj->Name,n);
					}
				}
			}

			if(ItemDbByte == 7)
			{
				item.Convert(itype,item.m_Option1,item.m_Option2,item.m_Option3,0,0,0,0);
			}
			else if(ItemDbByte <= 10)
			{
				item.Convert(itype,item.m_Option1,item.m_Option2,item.m_Option3,DBI_GET_NOPTION(lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA]),lpMsg->dbInventory[n*ItemDbByte+DBI_SOPTION_DATA],item.m_ItemOptionEx,1);
			}
			else
			{
				item.Convert(itype,item.m_Option1,item.m_Option2,item.m_Option3,DBI_GET_NOPTION(lpMsg->dbInventory[n*ItemDbByte+DBI_NOPTION_DATA]),lpMsg->dbInventory[n*ItemDbByte+DBI_SOPTION_DATA],item.m_ItemOptionEx,3);
			}

			if(_type == ITEMGET(14,7))
			{

			}
			else
			{
				if(_type >= ITEMGET(14,0) && _type <= ITEMGET(14,8)//Potions
					|| _type >= ITEMGET(14,38) && _type <= ITEMGET(14,40) )
				{
					if(item.m_Durability == 0.0f)
					{
						item.m_Durability = 1.0f;
					}

					if(item.m_Durability > MaxPotionDurability)
					{
						item.m_Durability = MaxPotionDurability;
					}
				}
				else if(_type >= ITEMGET(14,46) && _type <= ITEMGET(14,50))
				{
					if(item.m_Durability == 0.0f)
					{
						item.m_Durability = 1.0f;
					}

					if(item.m_Durability > 3.0f)
					{
						item.m_Durability = 3.0f;
					}
				}
				else if(_type >= ITEMGET(14,35) && _type <= ITEMGET(14,37))
				{
					if(item.m_Durability == 0.0f)
					{
						item.m_Durability = 1.0f;
					}

					if(item.m_Durability > MaxPotionDurability)
					{
						item.m_Durability = MaxPotionDurability;
					}
				}
                else if(_type == ITEMGET(13,51))
                {
                        if(item.m_Durability == 0.0f)
                        {
                                item.m_Durability = 1.0f;
                        }

                        if(item.m_Durability > 1.0f)
                        {
                                item.m_Durability = 1.0f;
                        }
                }
				else if(_type != ITEMGET(13,10)
					&& _type != ITEMGET(14,29)
					&& _type != ITEMGET(14,21))
				{
					if(item.m_Level == 3)
					{
						if(item.m_Durability > item.m_BaseDurability && bIsItemExist == 1)
						{
							item.m_Durability = item.m_BaseDurability;
						}
					}
				}
			}

			lpObj->pInventory[n].m_Option1 = item.m_Option1;
			lpObj->pInventory[n].m_Option2 = item.m_Option2;
			lpObj->pInventory[n].m_Option3 = item.m_Option3;
			lpObj->pInventory[n].m_JewelOfHarmonyOption = item.m_JewelOfHarmonyOption;
			lpObj->pInventory[n].m_ItemOptionEx = item.m_ItemOptionEx;

			hiWord = ((lpMsg->dbInventory[n*ItemDbByte+DBI_SERIAL2])&0xFF)&0xFF | (((lpMsg->dbInventory[n*ItemDbByte+DBI_SERIAL1])&0xFF)&0xFF) * 256;
			loWord = ((lpMsg->dbInventory[n*ItemDbByte+DBI_SERIAL4])&0xFF)&0xFF | (((lpMsg->dbInventory[n*ItemDbByte+DBI_SERIAL3])&0xFF)&0xFF) * 256;

			item.m_Number = ((loWord &0xFFFF)&0xFFFF) | ((hiWord & 0xFFFF)&0xFFFF) << 16;

			gObjInventoryInsertItemPos(lpObj->m_Index,item,n,0);

			if(bIsItemExist == false)
			{
				lpObj->pInventory[n].m_bItemExist = 0;

				LogAdd("error-L2 : Unknown Item found [%s][%s] (Type:%d, LEV:%d, DUR:%d OP1:%d, OP2:%d, OP3:%d, NEWOP:%d, SET:%d)",
					lpObj->AccountID,lpObj->Name,lpObj->pInventory[n].m_Type,lpObj->pInventory[n].m_Level,
					lpObj->pInventory[n].m_Durability,lpObj->pInventory[n].m_Option1,
					lpObj->pInventory[n].m_Option2,lpObj->pInventory[n].m_Option3,
					lpObj->pInventory[n].m_NewOption,lpObj->pInventory[n].m_SetOption);
			}
		}
	}
	gObjRequestPetItemInfo(lpObj->m_Index, 0);
}


TMonsterSkillElementInfo::TMonsterSkillElementInfo()	// line.h 10
{
	// Reset Data
	this->Reset();
}

void gObjSetBP(int aIndex)
{
	int Strength = gObj[aIndex].Strength + gObj[aIndex].AddStrength;
	int Dexterity = gObj[aIndex].Dexterity + gObj[aIndex].AddDexterity;
	int Vitality = gObj[aIndex].Vitality + gObj[aIndex].AddVitality;
	int Energy = gObj[aIndex].Energy + gObj[aIndex].AddEnergy;
	int Leadership = gObj[aIndex].Leadership + gObj[aIndex].AddLeadership;

	switch ( gObj[aIndex].Class )
	{
		case 0:
			gObj[aIndex].MaxBP = int((Strength * 0.2) + (Dexterity * 0.4) + (Vitality * 0.3) + (Energy * 0.2));
			break;

		case 1:
			gObj[aIndex].MaxBP = int((Strength * 0.15) + (Dexterity * 0.2) + (Vitality * 0.3) + (Energy * 1.0));
			break;

		case 2:
			gObj[aIndex].MaxBP = int((Strength * 0.3) + (Dexterity * 0.2) + (Vitality * 0.3) + (Energy * 0.2));
			break;

		case 3:
			gObj[aIndex].MaxBP = int((Strength * 0.2) + (Dexterity * 0.25) + (Vitality * 0.3) + (Energy * 0.15));
			break;

		case 4:
			gObj[aIndex].MaxBP = int((Strength * 0.3) + (Dexterity * 0.2) + (Vitality * 0.1) + (Energy * 0.15) + (Leadership * 0.3));
			break;
	}
}




int gObjSetCharacter(SDHP_DBCHAR_INFORESULT *lpMsg, int aIndex)
{
	int itype;
	int n;
	char szCharName[MAX_ACCOUNT_LEN+1];

	// Check in position
	if ( OBJMAX_RANGE(aIndex) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return FALSE;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if ( lpObj->Connected < PLAYER_LOGGED )
	{
		return FALSE;
	}

	if ( gObj[aIndex].Connected == PLAYER_PLAYING )
	{
		LogAdd( "error-L1:(%s/%s)Received reconnect message while playing game. Forced to disconnect" , gObj[aIndex].AccountID, gObj[aIndex].Name);
		return FALSE;
	}
	// DB CLASS          DW                      DK                      Elf                     MG						   SM					  BK						ME						DL						GM					  BM					  HE					  DM						LE
	if ( lpMsg->Class == 0x00 || lpMsg->Class == 0x10 || lpMsg->Class == 0x20 || lpMsg->Class == 0x30  || lpMsg->Class == 0x01 || lpMsg->Class == 0x11 || lpMsg->Class == 0x21 || lpMsg->Class == 0x40 || lpMsg->Class == 0x02 || lpMsg->Class == 0x12 || lpMsg->Class == 0x22 || lpMsg->Class == 0x32 || lpMsg->Class == 0x42 )
	{

	}
	else
	{
		return FALSE;
	}

	gObjCharZeroSet(aIndex);

	if ( ChaosBoxInit(lpObj) == FALSE )
	{
		LogAdd("error-L1 : ChaosBox Init error %s %d", __FILE__, __LINE__);
	}

	lpObj->m_PosNum = 0;
	lpObj->Level = lpMsg->Level;
	lpObj->LevelUpPoint = lpMsg->LevelUpPoint;
	lpObj->DbClass = lpMsg->Class;
	lpObj->Class = lpMsg->Class >> 4;
	lpObj->ChangeUP = lpMsg->Class & 0x07;	// Set Second Type of Character

	szCharName[MAX_ACCOUNT_LEN] = 0;
	memcpy(szCharName, lpMsg->Name , MAX_ACCOUNT_LEN);
	strcpy_s(lpObj->Name, sizeof(lpObj->Name), szCharName);

	if ( lpObj->Level < 1 )
	{
		LogAdd( "error : %s Level Zero", lpMsg->Name);
		return FALSE;
	}

	lpObj->X = lpMsg->MapX;
	lpObj->Y = lpMsg->MapY;
	lpObj->MapNumber = lpMsg->MapNumber;
	lpObj->StartX = (BYTE)lpObj->X;
	lpObj->StartY = (BYTE)lpObj->Y;
	
	if ( MAX_MAP_RANGE(lpObj->MapNumber) == FALSE )
	{
		LogAdd("error : Map Number max over. %s %d", __FILE__, __LINE__);
		lpObj->MapNumber = MAP_INDEX_LORENCIA;
		MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber, lpObj->X, lpObj->Y);
	}

	if ( lpObj->Level < 6 || DS_MAP_RANGE(lpObj->MapNumber) != FALSE )
	{
		switch(lpMsg->Class)
		{
		case 0x00:
			{
				lpMsg->MapNumber = NewbieDKStartMap;
			}
			break;

		case 0x10:
			{
				lpMsg->MapNumber = NewbieDWStartMap;
			}
			break;

		case 0x20:
			{
				lpMsg->MapNumber = NewbieElfStartMap;
			}
			break;

		case 0x30:
			{
				lpMsg->MapNumber = NewbieMGStartMap;
			}
			break;

		case 0x40:
			{
				lpMsg->MapNumber = NewbieDLStartMap;
			}
			break;

		default:
			break;
		}
		MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber, lpObj->X, lpObj->Y);
	}

	if ( BC_MAP_RANGE(lpObj->MapNumber) != FALSE )
	{
		lpObj->MapNumber = MAP_INDEX_DEVIAS;
		MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber, lpObj->X, lpObj->Y);
	}

    if ( lpObj->MapNumber == MAP_INDEX_REFUGEE )
    {
		lpObj->MapNumber = MAP_INDEX_BARRACKS;
		MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber, lpObj->X, lpObj->Y);
    }

	lpObj->m_cBloodCastleIndex = -1;
	lpObj->m_cBloodCastleSubIndex = -1;
	lpObj->m_iBloodCastleEXP = 0;
	lpObj->m_bBloodCastleComplete = 0;

	if ( CC_MAP_RANGE(lpObj->MapNumber) != FALSE )
	{
		lpObj->MapNumber = MAP_INDEX_DEVIAS;
		MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber, lpObj->X, lpObj->Y);
	}

	
	lpObj->m_cChaosCastleIndex = -1;
	lpObj->m_cChaosCastleSubIndex = -1;
	lpObj->m_iChaosCastleBlowTime = 0;
	lpObj->m_cKillUserCount = 0;
	lpObj->m_cKillMonsterCount = 0;

 
	if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE &&
		 g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
	{
		short sX;
		short sY;
		short sLVL;
		unsigned char btMAPNUM = lpObj->MapNumber;
		unsigned char btDIR;

		int iMapNumber = gGateC.GetGate(100,(short &)sX,(short &)sY,(BYTE &)btMAPNUM,(BYTE &)btDIR,(short &)sLVL);

		if(iMapNumber >= 0)
		{
			lpObj->MapNumber = btMAPNUM;
			lpObj->X = sX;
			lpObj->Y = sY;

			lpObj->m_sDestMapNumber = btMAPNUM;
			lpObj->m_btDestX = (BYTE)sX;
			lpObj->m_btDestY = (BYTE)sY;
		}
	}

	if ( lpObj->MapNumber == MAP_INDEX_CASTLEHUNTZONE )
	{
		short sX;
		short sY;
		short sLVL;
		unsigned char btMAPNUM = lpObj->MapNumber;
		unsigned char btDIR;

		int iMapNumber = gGateC.GetGate(106,(short &)sX,(short &)sY,(BYTE &)btMAPNUM,(BYTE &)btDIR,(short &)sLVL);

		if(iMapNumber >= 0)
		{
			lpObj->MapNumber = btMAPNUM;
			lpObj->X = sX;
			lpObj->Y = sY;

			lpObj->m_sDestMapNumber = btMAPNUM;
			lpObj->m_btDestX = (BYTE)sX;
			lpObj->m_btDestY = (BYTE)sY;
		}
	}



	if ( lpObj->MapNumber == MAP_INDEX_KANTURU_BOSS )
	{
		short sX;
		short sY;
		short sLVL;
		unsigned char btMAPNUM = lpObj->MapNumber;
		unsigned char btDIR;

		int iMapNumber = gGateC.GetGate(137,(short &)sX,(short &)sY,(BYTE &)btMAPNUM,(BYTE &)btDIR,(short &)sLVL);

		if(iMapNumber >= 0)
		{
			lpObj->MapNumber = btMAPNUM;
			lpObj->X = sX;
			lpObj->Y = sY;
		}
	}


	if ( lpObj->m_bMapSvrMoveReq == true )
	{
		short sSVR_CODE = ::g_MapServerManager.CheckMoveMapSvr(lpObj->m_Index, lpObj->m_sDestMapNumber, lpObj->m_sPrevMapSvrCode);

		if ( sSVR_CODE == gGameServerCode )
		{
			lpObj->MapNumber = (BYTE)lpObj->m_sDestMapNumber;
			lpObj->X = lpObj->m_btDestX;
			lpObj->Y = lpObj->m_btDestY;
			lpObj->StartX = (BYTE)lpObj->X;
			lpObj->StartY = (BYTE)lpObj->Y;
		}
		else	
		{
			LogAdd( "[MapServerMng] Dest Map Server doesn't have Map [%s][%s] : %d",
				lpObj->AccountID, lpObj->Name, lpObj->m_sDestMapNumber);
			gObjDel(lpObj->m_Index);

			return FALSE;
		}
	}

	BYTE attr = MapC[lpObj->MapNumber].GetAttr(lpObj->X, lpObj->Y);
	int result;
	short x;
	short y;
	BYTE mapNumber;
	BYTE dir;
	short level;
	int gt;
	int userlevel;

	if ( (attr&4) == 4 || (attr&8) == 8 )
	{
		LogAdd("error : Invalid place to be located causes modifying location");
		MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber, lpObj->X, lpObj->Y);
	}

	userlevel = gObj[aIndex].Level;
	x = lpObj->X;
	y = lpObj->Y;
	dir = lpObj->Dir;
	level = lpObj->Level;
	mapNumber = lpObj->MapNumber;
	gt = 0;

	if(g_iBlockKanturuMapEnter == 1)
	{
		if(gObj[aIndex].MapNumber >= MAP_INDEX_KANTURU1 && gObj[aIndex].MapNumber <= MAP_INDEX_KANTURU_BOSS)
		{
			LogAdd("[ KANTURU ][ Forced Move From Kanturu to Lorencia ] (%s)(%s) (BeforeMap:%d(%d/%d))",
				gObj[aIndex].AccountID,gObj[aIndex].Name,gObj[aIndex].MapNumber,gObj[aIndex].X,gObj[aIndex].Y);
			gObj[aIndex].MapNumber = MAP_INDEX_LORENCIA;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
	}

	if(g_iBlockCastleSiegeMapEnter == 1)
	{
		if(gObj[aIndex].MapNumber == MAP_INDEX_CASTLESIEGE
			|| gObj[aIndex].MapNumber == MAP_INDEX_CASTLEHUNTZONE
			|| gObj[aIndex].MapNumber == MAP_INDEX_CRYWOLF_FIRSTZONE
			|| gObj[aIndex].MapNumber == MAP_INDEX_CRYWOLF_SECONDZONE)
		{
			LogAdd("[ KANTURU ][ Forced Move From CastleSiegeMap to Lorencia ] (%s)(%s) (BeforeMap:%d(%d/%d))",
				gObj[aIndex].AccountID,gObj[aIndex].Name,gObj[aIndex].MapNumber,gObj[aIndex].X,gObj[aIndex].Y);
			gObj[aIndex].MapNumber = MAP_INDEX_LORENCIA;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
	}

	if ( lpObj->MapNumber == MAP_INDEX_DEVIAS )
	{
		gt = 22;
	}
	else if ( lpObj->MapNumber == MAP_INDEX_NORIA )
	{
		gt = 27;
	}
	else if ( lpObj->MapNumber == MAP_INDEX_LOSTTOWER )
	{
		gt = 42;
	}

	if ( gt > 0 )
	{
		result = gGateC.GetGate(gt, x, y, mapNumber, dir, level);

		if ( result >= 0 )
		{
			if ( lpObj->Class == 4 || lpObj->Class == 3 )
			{
				if ( level > 0 )
				{
					level = level / 3 * 2;
				}
			}

			if ( level != 0 && lpObj->Level < level)
			{
				switch(lpMsg->Class)
				{
				case 0x00:
					{
						lpMsg->MapNumber = NewbieDKStartMap;
					}
					break;

				case 0x10:
					{
						lpMsg->MapNumber = NewbieDWStartMap;
					}
					break;

				case 0x20:
					{
						lpMsg->MapNumber = NewbieElfStartMap;
					}
					break;

				case 0x30:
					{
						lpMsg->MapNumber = NewbieMGStartMap;
					}
					break;

				case 0x40:
					{
						lpMsg->MapNumber = NewbieDLStartMap;
					}
					break;

				default:
					break;
				}

				MapC[lpObj->MapNumber].GetLevelPos(lpObj->Level, lpObj->X, lpObj->Y);
			}
		}
		else
		{
			LogAdd("error : %d (%s %d)", result, __FILE__, __LINE__);
		}
	}

	lpMsg->MapX = (BYTE)lpObj->X;
	lpMsg->MapY = (BYTE)lpObj->Y;
	lpObj->TX = lpMsg->MapX;
	lpObj->TY = lpMsg->MapY;
	lpObj->m_OldX = lpObj->X;
	lpObj->m_OldY = lpObj->Y;
	lpObj->Experience = lpMsg->Exp;
	lpObj->Strength = lpMsg->Str ;
	lpObj->Dexterity = lpMsg->Dex ;
	lpObj->Vitality = lpMsg->Vit ;
	lpObj->Energy = lpMsg->Energy ;
	lpObj->Life = lpMsg->Life;
	lpObj->Life /= 10.0;
	lpObj->MaxLife = lpMsg->MaxLife;
	lpObj->MaxLife /= 10.0;
	lpObj->Mana = lpMsg->Mana;
	lpObj->Mana /= 10.0;
	lpObj->MaxMana = lpMsg->MaxMana;
	lpObj->MaxMana /= 10.0;
	lpObj->Money = lpMsg->Money;
	lpObj->Leadership = lpMsg->Leadership;
	lpObj->ChatLimitTime = lpMsg->ChatLitmitTime;
	lpObj->iFruitPoint = lpMsg->iFruitPoint;

	if ( lpObj->Mana < 1.0 )
	{
		lpObj->Mana = 1.0;
	}

	if ( lpObj->Life < 1.0 )
	{
		lpObj->Life = 1.0;
		FixWarpIfUserDie(aIndex);
	}


	lpObj->MaxLife = DCInfo.DefClass[lpObj->Class].Life + (lpObj->Level - 1) * DCInfo.DefClass[lpObj->Class].LevelLife  + ((lpObj->Vitality - DCInfo.DefClass[lpObj->Class].Vitality ) * DCInfo.DefClass[lpObj->Class].VitalityToLife);
	lpObj->MaxMana = DCInfo.DefClass[lpObj->Class].Mana + (lpObj->Level - 1) * DCInfo.DefClass[lpObj->Class].LevelMana  + ((lpObj->Energy - DCInfo.DefClass[lpObj->Class].Energy ) * DCInfo.DefClass[lpObj->Class].EnergyToMana);

	lpObj->VitalityToLife = DCInfo.DefClass[lpObj->Class].VitalityToLife;
	lpObj->EnergyToMana = DCInfo.DefClass[lpObj->Class].EnergyToMana;

	::gObjSetBP(aIndex);
	lpObj->BP = lpObj->MaxBP / 2;
	::gObjCalcMaxLifePower(aIndex);
	lpObj->m_PK_Count = lpMsg->PkCount;
	lpObj->m_PK_Level = lpMsg->PkLevel;
	lpObj->m_PK_Time  = lpMsg->PkTime;

	if ( ::gApplyHeroSystem != FALSE )
	{
		if ( lpObj->m_PK_Level <= 3 )
		{
			lpObj->m_PK_Level = 2;
		}
	}

	if ( lpObj->m_PK_Level == 3 )
	{
		lpObj->m_PK_Count = 0;
		lpObj->m_PK_Time = 0;
	}

	lpObj->MaxRegenTime = 4000;	// Resurrection of the player if die
	lpObj->m_MoveSpeed = 1000;

	memcpy(lpObj->m_Quest, lpMsg->dbQuest, sizeof(lpObj->m_Quest));

	if ( lpObj->m_Quest[0] == 0 )
	{
		memset(lpObj->m_Quest, (BYTE)-1, sizeof(lpObj->m_Quest));
	}

	if ( ::g_QuestInfo.GetQuestState(lpObj, 2) == 2 )	// Ring of Honor
	{
		if ( lpObj->Level < QUEST_MINLEVEL_PLUSSTAT )	// Repair Bug of Marlon Before
		{
			::g_QuestInfo.ReSetQuestState(lpObj, 2);
			LogAdd("[%s][%s] Find Invalid QuestInfo (%d)",
				lpObj->AccountID, lpObj->Name, 2);
		}
		else
		{
			lpObj->PlusStatQuestClear = true;
		}
	}

	if ( ::g_QuestInfo.GetQuestState(lpObj, 3) == 2 )	// Dark Stone
	{
		if ( lpObj->Level < QUEST_MINLEVEL_PLUSSTAT )	// Repair Bug of Marlon After
		{
			::g_QuestInfo.ReSetQuestState(lpObj, 3);
			LogAdd("[%s][%s] Find Invalid QuestInfo (%d)",
				lpObj->AccountID, lpObj->Name, 3);
		}
		else
		{
			lpObj->ComboSkillquestClear = true;
		}
	}

	::gObjSetInventory1Pointer(lpObj);
	lpObj->GuildNumber = 0;
	lpObj->lpGuild = NULL;

	if ( lpObj->Class == 0 || lpObj->Class == 2 || lpObj->Class == 1 || lpObj->Class == 4 || lpObj->Class == 3 )
	{
		BOOL bEnergyBall = TRUE;
		BOOL bForceSkill = TRUE;
		BOOL IsGetInitinityArrowSkill = FALSE;// DarkLord

		gObjMagicAddEnergyCheckOnOff(0);

		for ( n=0;n<MAX_MAGIC;n++)
		{
			itype = lpMsg->dbMagicList[n*3];

			if ( itype != (BYTE)-1 )
			{
				if ( itype == 17 )
				{
					bEnergyBall = FALSE;
				}

				if ( itype == 60 )
				{
					bForceSkill = FALSE;
				}

				if ( itype == 77 )
				{
					IsGetInitinityArrowSkill = 1;
					gObjMagicAdd(lpObj,itype,lpMsg->dbMagicList[n*3+DBM_LEVEL]&0xF);
				}

				// Main Engine of Add Skills
				if ( itype != 18 && itype != 19 && itype != 20 && itype != 21 && itype != 22 && itype != 23 && itype != 24 && itype != 25 && itype != 49 && itype != 56 && itype != 62 && itype != 76 && itype != 54 )
				{
					gObjMagicAdd(lpObj, itype, lpMsg->dbMagicList[n*3+DBM_LEVEL] & 0x0F);
				}
			}
		}

		if ( lpObj->Class == 0 )	// Wizard
		{
			if ( bEnergyBall == TRUE )
			{
				gObjMagicAdd(lpObj, 17, 0);
				bEnergyBall = FALSE;
			}
		}

		if ( lpObj->Class == 4 )	// Dark Lord
		{
			if ( bForceSkill == TRUE )
			{
				gObjMagicAdd(lpObj, 60, 0);
				bForceSkill = FALSE;
			}
		}

		if ( IsGetInitinityArrowSkill == 0 && lpObj->Class == 2)
		{
			if(lpObj->Level >= g_SkillAdditionInfo.GetInfinityArrowUseLevel())
			{
				if(lpObj->ChangeUP >= 1)
				{
					int iAddSkillPosition = gObjMagicAdd(lpObj,77,0);

					if(iAddSkillPosition > 0)
					{
						LogAdd("[%s][%s] Add Infinity Arrow Skill (Character Level : %d)(ChangeUp: %d)",
							lpObj->AccountID,lpObj->Name,lpObj->Level,lpObj->ChangeUP);
					}
				}
			}
		}

		if ( lpObj->Class == 0 )
		{
			gObjMagicAdd(lpObj, 45, 0);
		}
		else if ( lpObj->Class == 1 )
		{
			gObjMagicAdd(lpObj, 44, 0);
		}
		else if ( lpObj->Class == 2 )
		{
			gObjMagicAdd(lpObj, 46, 0);
		}
		else if ( lpObj->Class == 3 )	// Magic Gladiator
		{
			gObjMagicAdd(lpObj, 57, 0);
			gObjMagicAdd(lpObj, 73, 0);
		}
		else if ( lpObj->Class == 4 )	// Dark Lord
		{
			gObjMagicAdd(lpObj, 74, 0);	// Fire Blast
			gObjMagicAdd(lpObj, 75, 0);	// Sacrifice - BUG Apply Fix in Skill.vtm coz is not created
		}

		gObjMagicAdd(lpObj,67,0);
		gObjMagicAdd(lpObj,68,0);
		gObjMagicAdd(lpObj,69,0);
		gObjMagicAdd(lpObj,70,0);
		gObjMagicAdd(lpObj,71,0);
		gObjMagicAdd(lpObj,72,0);


		::gObjMagicAddEnergyCheckOnOff(TRUE);
	}

	bool bAllItemExist = true;

	if ( lpMsg->DbVersion == 0 ) 
	{
		::DbItemSetInByte(lpObj, lpMsg, 7, &bAllItemExist);

		for ( int i=MAIN_INVENTORY_SIZE;i<INVENTORY_SIZE;i++)
		{
			lpObj->Inventory1[i].Clear();
		}

		memset(lpObj->InventoryMap1+64, (BYTE)-1, PSHOP_MAP_SIZE);	
	}
	else if(lpMsg->DbVersion < 3)
	{
		::DbItemSetInByte(lpObj, lpMsg, 10, &bAllItemExist);
	}
	else
	{
		if (!gObj[aIndex].bot)
			::DbItemSetInByte(lpObj, lpMsg, 16, &bAllItemExist);
	}

	if ( lpObj->Level <=5 )
	{
		for ( int i=MAIN_INVENTORY_SIZE;i<INVENTORY_SIZE;i++)
		{
			BYTE NewOption[MAX_EXOPTION_SIZE];

			if ( lpObj->Inventory1[i].IsItem() == TRUE )
			{
				for ( int j=0;j<MAX_EXOPTION_SIZE;j++)
				{
					NewOption[j] = 0;
				}

				if ( ( lpObj->Inventory1[i].m_NewOption & 0x20 ) != 0 )
				{
					NewOption[0] = TRUE;
				}

				if ( ( lpObj->Inventory1[i].m_NewOption & 0x10 ) != 0 )
				{
					NewOption[1] = TRUE;
				}

				if ( ( lpObj->Inventory1[i].m_NewOption & 0x08 ) != 0 )
				{
					NewOption[2] = TRUE;
				}

				if ( ( lpObj->Inventory1[i].m_NewOption & 0x04 ) != 0 )
				{
					NewOption[3] = TRUE;
				}

				if ( ( lpObj->Inventory1[i].m_NewOption & 0x02 ) != 0 )
				{
					NewOption[4] = TRUE;
				}

				if ( ( lpObj->Inventory1[i].m_NewOption & 0x01 ) != 0 )
				{
					NewOption[5] = TRUE;
				}

				LogAdd("[PShop] PShop Item Delete LV <= 5 [%s][%s] [LV:%d] : serial:%d [%s][%d][%d][%d][%d] Ex:[%d,%d,%d,%d,%d,%d,%d] Set:[%d]",
					lpObj->AccountID, lpObj->Name, lpObj->Level, lpObj->Inventory1[i].m_Number, 
					ItemAttribute[lpObj->Inventory1[i].m_Type].Name, lpObj->Inventory1[i].m_Level,
					lpObj->Inventory1[i].m_Option1, lpObj->Inventory1[i].m_Option2,
					lpObj->Inventory1[i].m_Option3, NewOption[0], NewOption[1], NewOption[2], NewOption[3],
					NewOption[4], NewOption[5], NewOption[6], lpObj->Inventory1[i].m_SetOption);
			}

			lpObj->Inventory1[i].Clear();
		}

		memset(lpObj->InventoryMap1+64, (BYTE)-1, PSHOP_MAP_SIZE);
	}

	lpObj->Live = TRUE;
	lpObj->Type = OBJ_USER;
	lpObj->TargetNumber = -1;
	lpObj->Connected = PLAYER_PLAYING;
	::gObjMakePreviewCharSet(aIndex);
	CreateFrustrum(lpObj->X, lpObj->Y, aIndex);
	MapC[lpObj->MapNumber].SetStandAttr(lpObj->X, lpObj->Y);
	lpObj->m_OldX = lpObj->X;
	lpObj->m_OldY = lpObj->Y;
	lpMsg->NextExp = lpObj->NextExp;

	lpObj->m_State = 1;//������ � ����� ������ ��� ��������� � ������ ��� ��� ��� ������ ��������� ��� ����...

	if ( (lpMsg->CtlCode & 8) == 8 )
	{
		lpObj->Authority = 2;
		LogAdd( "[%s][%s] Administrator setting", lpObj->AccountID, lpObj->Name);
		cManager.ManagerAdd(lpObj->Name, lpObj->m_Index);
	}
	else
	{
		lpObj->Authority = 1;
	}

	if ( (lpMsg->CtlCode & 0x20 ) == 0x20 )
	{
		lpObj->Authority = 0x20;
		LogAdd( "(%s)(%s) Set Event GM", lpObj->AccountID, lpObj->Name);
	}

	lpObj->Penalty = 0;

	if ( lpObj->m_cAccountItemBlock != 0 )
	{
		lpObj->Penalty |= 8;
	}

	if ( (lpMsg->CtlCode & 2) == 2 )
	{
		lpObj->Penalty |= 4;
		LogAdd("Penalty : Item Don't touch  %s %s", lpObj->AccountID, lpObj->Name);
	}

	gObjAuthorityCodeSet(lpObj);
	LogAdd("(%d)[%s][%s] Character select", lpObj->m_Index, lpObj->AccountID, lpObj->Name);

	BYTE weather = MapC[lpObj->MapNumber].GetWeather();

	if ( (weather >> 4) > 0 )
	{
		CGWeatherSend(aIndex, weather);
	}

	if ( DragonEvent->GetState() > 0 )
	{
		if ( DragonEvent->GetMapNumber() == lpObj->MapNumber )
		{
			::GCMapEventStateSend(lpObj->MapNumber, 1, 1);
		}
	}

 
	if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE )
	{
		GCAnsCsNotifyStart(lpObj->m_Index, CHECK_CLASS(g_CastleSiege.GetCastleState(), CASTLESIEGE_STATE_STARTSIEGE));

		if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
			g_CastleSiege.NotifyCsSelfLeftTime(lpObj->m_Index);
	}


	::gEledoradoEvent.CheckGoldDercon(lpObj->MapNumber);
	if (!lpObj->bot)
		::GCCheckMainExeKeySend(aIndex);


	if ( bAllItemExist == false )
	{
		PMSG_NOTICE pNotice;
		TNotice::MakeNoticeMsgEx((TNotice *)&pNotice, 1, "���� ������ �߰� !!!");	// Deathway need Translation
		DataSend(lpObj->m_Index, (UCHAR *)&pNotice, pNotice.h.size);
	}

	if ( lpObj->Level <= g_iCharacterRecuperationMaxLevel )
	{
		lpObj->m_iAutoRecuperationTime = GetTickCount();
	}
	else
	{
		lpObj->m_iAutoRecuperationTime = 0;
	}

	lpObj->dwShieldAutoRefillTimer = GetTickCount();

	LogAdd("[ShieldSystem][CalcSDPoint] [%s][%s] user SD Gage : %d",
		lpObj->AccountID,lpObj->Name,lpObj->iMaxShield+lpObj->iAddShield);

	/*g_CashShop.AddUser(lpObj);
	g_CashShop.CGCashPoint(lpObj);
	g_CashItemPeriodSystem.GDReqPeriodItemList(lpObj);*/

	return TRUE;
}




BOOL gObjCanItemTouch(LPOBJ lpObj, int type )
{
	if ( (lpObj->Penalty &4) == 4 )
	{
		return false;
	}

	if ( (lpObj->Penalty &8) == 8 )
	{
		if ( type == 6 || type == 8 )
		{
			return true;
		}
		return false;
	}
	return true;
}








void gObjMagicTextSave(LPOBJ lpObj)
{
	int total=0;

	for ( int n=0;n<MAGIC_SIZE;n++)
	{
		if ( lpObj->Magic[n].IsMagic() == TRUE )
		{
			LogAdd("[%s][%s] Skill Save Complete. %d %d", lpObj->AccountID, lpObj->Name, n, lpObj->Magic[n].m_Skill);
			total++;
		}
	}
}








void ItemIsBufExOption(BYTE * buf, CItem * lpItem)
{
	for ( int i=0;i<MAX_EXOPTION_SIZE;i++ )
	{
		buf[i] = 0;
	}

	if ( lpItem->IsExtLifeAdd() != FALSE )
	{
		buf[0] = TRUE;
	}

	if ( lpItem->IsExtManaAdd() != FALSE )
	{
		buf[1] = TRUE;
	}

	if ( lpItem->IsExtDamageMinus() != FALSE )
	{
		buf[2] = TRUE;
	}

	if ( lpItem->IsExtDamageReflect() != FALSE )
	{
		buf[3] = TRUE;
	}

	if ( lpItem->IsExtDefenseSuccessfull() != FALSE )
	{
		buf[4] = TRUE;
	}

	if ( lpItem->IsExtMonsterMoney() != FALSE )
	{
		buf[5] = TRUE;
	}

}







void gObjStatTextSave(LPOBJ lpObj)
{
	LogAdd("[%s][%s] CharInfoSave : Class=%d Level=%d LVPoint=%d Exp=%u Str=%d Dex=%d Vit=%d Energy=%d Leadership:%d Map=%d Pk=%d",
		lpObj->AccountID, lpObj->Name, lpObj->DbClass,lpObj->Level, lpObj->LevelUpPoint, lpObj->Experience, 
		lpObj->Strength, lpObj->Dexterity, lpObj->Vitality, lpObj->Energy, lpObj->Leadership, lpObj->MapNumber,
		lpObj->m_PK_Level);
}







void gObjItemTextSave(LPOBJ lpObj)
{
	BYTE NewOption[MAX_EXOPTION_SIZE];
	int n;

	for ( n=0;n<INVENTORY_SIZE;n++)
	{
		if ( lpObj->pInventory[n].IsItem() == TRUE )
		{
			if ( lpObj->pInventory[n].m_serial != 0 )
			{
				ItemIsBufExOption(NewOption, &lpObj->pInventory[n]);// #error max params overflow
				LogAdd("***0504*** [%s][%s] SI(%d,%s,%d,%d,%d,%d)serial:(%d) dur:(%d) Ex:(%d,%d,%d,%d,%d,%d,%d) Set : (%d)", lpObj->AccountID, lpObj->Name, 
					n, lpObj->pInventory[n].GetName(),
					lpObj->pInventory[n].m_Level, lpObj->pInventory[n].m_Option1,
					lpObj->pInventory[n].m_Option2, lpObj->pInventory[n].m_Option3,
					lpObj->pInventory[n].m_Number, (BYTE)lpObj->pInventory[n].m_Durability,
					NewOption[0], NewOption[1], NewOption[2], NewOption[3], NewOption[4], NewOption[5], NewOption[6],
					lpObj->pInventory[n].m_SetOption/*,lpObj->pInventory[n].m_ItemOptionEx >> 7,g_kJewelOfHarmonySystem.GetItemStrengthenOption(&lpObj->pInventory[n]),g_kJewelOfHarmonySystem.GetItemOptionLevel(&lpObj->pInventory[n])*/);
			}
		}
	}

	LogAdd("***0505*** [%s][%s] Item Save Complete. Money ( %d )", lpObj->AccountID, lpObj->Name, lpObj->Money);
}








void gObjWarehouseTextSave(LPOBJ lpObj)
{
	BYTE NewOption[MAX_EXOPTION_SIZE];
	int n;

	for ( n=0;n<WAREHOUSE_SIZE;n++)
	{
		if ( lpObj->pWarehouse[n].IsItem() == TRUE )
		{
			if ( lpObj->pWarehouse[n].m_serial != 0 )
			{
				ItemIsBufExOption(NewOption, &lpObj->pWarehouse[n]);// #error
				LogAdd("***0506*** [%s][%s] SW (%d,%s,%d,%d,%d,%d)serial:(%d) dur:(%d) Ex:(%d,%d,%d,%d,%d,%d,%d) Set : (%d)", lpObj->AccountID, lpObj->Name, 
					n, lpObj->pWarehouse[n].GetName(),
					lpObj->pWarehouse[n].m_Level, lpObj->pWarehouse[n].m_Option1,
					lpObj->pWarehouse[n].m_Option2, lpObj->pWarehouse[n].m_Option3,
					lpObj->pWarehouse[n].m_Number, (BYTE)lpObj->pWarehouse[n].m_Durability,
					NewOption[0], NewOption[1], NewOption[2], NewOption[3], NewOption[4], NewOption[5], NewOption[6],
					lpObj->pWarehouse[n].m_SetOption/*, lpObj->pWarehouse[n].m_ItemOptionEx>>7,
					g_kJewelOfHarmonySystem.GetItemStrengthenOption(&lpObj->pWarehouse[n]),
					g_kJewelOfHarmonySystem.GetItemOptionLevel(&lpObj->pWarehouse[n])*/);
			}
		}
	}

	LogAdd("***0507*** [%s][%s] Store Save Complete. wMoney(%d)", lpObj->AccountID, lpObj->Name, lpObj->WarehouseMoney);
}








void gObjAuthorityCodeSet(LPOBJ lpObj)
{
	if ( (lpObj->Authority&1) == 1 )
	{
		return;
	}

	if ( (lpObj->Authority&2)== 2 )
	{
		lpObj->AuthorityCode = -1;
		return;
	}

	if ( (lpObj->Authority&4) == 4 )
	{
		return;
	}

	if ( (lpObj->Authority&8) == 8 )
	{
		lpObj->AuthorityCode |= 1;
		lpObj->AuthorityCode |= 2;
		lpObj->AuthorityCode |= 4;
		lpObj->AuthorityCode |= 8;
		lpObj->AuthorityCode |= 16;
		lpObj->AuthorityCode |= 32;

		return;
	}

	if ( (lpObj->Authority&16) == 16 )
	{
		return;
	}

	if ( (lpObj->Authority&32) == 32 )
	{
		lpObj->AuthorityCode |= 1;
		lpObj->AuthorityCode |= 2;
		lpObj->AuthorityCode |= 4;
		lpObj->AuthorityCode |= 8;
		lpObj->AuthorityCode |= 16;
		lpObj->AuthorityCode |= 32;

		return;
	}

}








BOOL gObjSetPosMonster(int aIndex, int PosTableNum)
{
	if ( (  (aIndex<0)? FALSE: (aIndex > OBJMAX-1)? FALSE: TRUE ) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return FALSE;
	}

	
	if ( (  (PosTableNum<0)? FALSE: (PosTableNum > OBJ_MAXMONSTER-1)? FALSE: TRUE ) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return FALSE;
	}

	LPOBJ lpObj = &gObj[aIndex];
	lpObj->m_PosNum = PosTableNum;
	lpObj->X = gMSetBase.m_Mp[PosTableNum].m_X;
	lpObj->Y = gMSetBase.m_Mp[PosTableNum].m_Y;
	lpObj->MapNumber = gMSetBase.m_Mp[PosTableNum].m_MapNumber;
	lpObj->TX = lpObj->X;
	lpObj->TY = lpObj->Y;
	lpObj->m_OldX = lpObj->X;
	lpObj->m_OldY = lpObj->Y;
	lpObj->Dir = gMSetBase.m_Mp[PosTableNum].m_Dir;
	lpObj->StartX = (BYTE)lpObj->X;
	lpObj->StartY = (BYTE)lpObj->Y;

	if ( lpObj->Class == 44 ||  lpObj->Class == 53 ||  lpObj->Class == 54 ||  lpObj->Class == 55 ||  lpObj->Class == 56)
	{

	}
	else if (  lpObj->Class >= 78 &&  lpObj->Class <= 83)
	{

	}
	else if ( gMSetBase.GetPosition(PosTableNum, lpObj->MapNumber, lpObj->X, lpObj->Y) == FALSE )
	{
		LogAdd("error : Monster location setting error %s %d", __FILE__, __LINE__);
		LogAdd("error-L2 : %d class : %d", PosTableNum, lpObj->Class);
		return FALSE;
	}

	lpObj->TX = lpObj->X;
	lpObj->TY = lpObj->Y;
	lpObj->m_OldX = lpObj->X;
	lpObj->m_OldY = lpObj->Y;
	lpObj->Dir = gMSetBase.m_Mp[PosTableNum].m_Dir;
	lpObj->StartX = (BYTE)lpObj->X;
	lpObj->StartY = (BYTE)lpObj->Y;

	return true;
}









BOOL gObjSetMonster(int aIndex, int MonsterClass)
{
	int Level;
	LPOBJ lpObj;

	if ( OBJMAX_RANGE(aIndex) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return false;
	}

	lpObj = &gObj[aIndex];
	lpObj->ConnectCheckTime = GetTickCount();
	lpObj->ShopNumber = -1;
	lpObj->TargetNumber = -1;
	lpObj->m_RecallMon = -1;

	switch ( MonsterClass )	// Switch COMPLETE REVIEWED (JPN-GSn-1.00.18)
	{
		case 200:
			gBSGround[0]->m_BallIndex = aIndex;
			break;

		case 251:
			lpObj->ShopNumber = 0;//#shop
			break;

		case 255:
			lpObj->ShopNumber = 1;
			break;

		case 254:
			lpObj->ShopNumber = 2;
			break;

		case 250:
			lpObj->ShopNumber = 3;
			break;

		case 248:
		//case 253:
			lpObj->ShopNumber = 4;
			break;

		case 239:
		case 253:
			lpObj->ShopNumber = 5;
			break;

		case 244:
			lpObj->ShopNumber = 6;
			break;

		case 245:
			lpObj->ShopNumber = 7;
			break;

		case 246:
			lpObj->ShopNumber = 8;
			break;

		case 243:
			lpObj->ShopNumber = 9;
			break;

		case 242:
			lpObj->ShopNumber = 10;
			break;

		case 231:
			lpObj->ShopNumber = 12;
			break;

		case 230:
			lpObj->ShopNumber = 11;
			break;

		case 240:
			lpObj->ShopNumber = 100;
			break;

		case 238:
			lpObj->ShopNumber = 101;
			break;

		case 236:
			lpObj->ShopNumber = 102;
			break;
		case 259:
			lpObj->ShopNumber = 5;
			break;
		case 368:
		case 369:
		case 370:
			lpObj->ShopNumber = 101;
			break;
        case 376:
            lpObj->ShopNumber = 5;
            break;
        case 377:
            lpObj->ShopNumber = 5;
            break;
        case 379:
            lpObj->ShopNumber = 13;
            break;
	}

	lpObj->Connected = PLAYER_PLAYING;
	lpObj->Live = FALSE;
	lpObj->m_State = 0;

	if ( MonsterClass == 44 || MonsterClass == 54 || MonsterClass == 53 || lpObj->Class == 55 || lpObj->Class == 56 || MonsterClass == 76 || MonsterClass == 78 || MonsterClass == 79 || MonsterClass == 80 || MonsterClass == 81 ||	MonsterClass == 82 || MonsterClass == 83 )
	{

	}
	else
	{
		lpObj->Live = TRUE;
		lpObj->m_State = 1;
	}

	if ( MonsterClass >= 204 && MonsterClass <= 259 || MonsterClass == 367 || MonsterClass >= 368 && MonsterClass <= 379 || MonsterClass >= 380 && MonsterClass <= 385 || MonsterClass >= 406 && MonsterClass <= 408 || MonsterClass == 414)
	{
		lpObj->Type = OBJ_NPC;
	}
	else
	{
		lpObj->Type = OBJ_MONSTER;
	}

	if ( MonsterClass == 77 )
	{
		int iSL = gObjAddMonster(MAP_INDEX_ICARUS);

		if ( iSL >= 0 )
		{
			if ( gObjSetMonster(iSL, 76) == FALSE )
			{
				MsgBox("õ�������� ���� ����");
				return false;
			}

			lpObj->m_SkyBossMonSheildLinkIndex = iSL;
			LogAdd("SkyLand Boss Monster Setting!!");
		}
		else
		{
			MsgBox("õ�������� ���� ����");
			return false;
		}
	}

	if ( MonsterClass == 76 )
	{
		LogAdd("SkyLand Boss Shield Setting!!");
	}

	lpObj->Class = MonsterClass;
	Level = lpObj->Level;
	LPMONSTER_ATTRIBUTE lpm = gMAttr.GetAttr( lpObj->Class);

	if ( lpm == NULL )
	{
		MsgBox("Warning! : Can't find monster attribute. %d (%s %d)", lpObj->Class, __FILE__, __LINE__);
		return false;
	}

	strncpy_s(gObj[aIndex].Name, lpm->m_Name , 10 );

	if (lpm->m_Level == 0)
	{
		LogAdd("Monster level can't be 0. %d (%s %d)", lpObj->Class, __FILE__, __LINE__);
	}

	lpObj->Level = lpm->m_Level;
	lpObj->m_AttackSpeed = lpm->m_AttackSpeed;
	lpObj->m_AttackDamageMin = lpm->m_DamageMin;
	lpObj->m_AttackDamageMax = lpm->m_DamageMax;
	lpObj->m_Defense = lpm->m_Defense;
	lpObj->m_MagicDefense = lpm->m_MagicDefense;
	lpObj->m_AttackRating = lpm->m_AttackRating;
	lpObj->m_SuccessfulBlocking = lpm->m_Successfulblocking;
	lpObj->Life = lpm->m_Hp;
	lpObj->MaxLife = lpm->m_Hp;
	lpObj->Mana = lpm->m_Mp;
	lpObj->MaxMana = lpm->m_Mp;
	lpObj->m_MoveRange = lpm->m_MoveRange;
	lpObj->m_AttackSpeed = lpm->m_AttackSpeed;
	lpObj->m_MoveSpeed = lpm->m_MoveSpeed;
	lpObj->MaxRegenTime = lpm->m_RegenTime * 1000;
	lpObj->m_AttackRange = lpm->m_AttackRange;
	lpObj->m_ViewRange = lpm->m_ViewRange;
	lpObj->m_Attribute = lpm->m_Attribute;
	lpObj->m_AttackType = lpm->m_AttackType;
	lpObj->m_ItemRate = lpm->m_ItemRate;
	lpObj->m_MoneyRate = lpm->m_MoneyRate;
	lpObj->Dexterity = 0;

	lpObj->m_iScriptMaxLife = lpm->m_iScriptHP;
	lpObj->m_iBasicAI = lpm->m_iAINumber;
	lpObj->m_iCurrentAI = lpm->m_iAINumber;
	lpObj->m_iCurrentAIState = 0;
	lpObj->m_iLastAIRunTime = 0;
	lpObj->m_iGroupNumber = 0;
	lpObj->m_iSubGroupNumber = 0;
	lpObj->m_iGroupMemberGuid = -1;
	lpObj->m_iRegenType = 0;

	lpObj->m_Agro.ResetAll();

	lpObj->m_iLastAutomataRuntime = 0;
	lpObj->m_iLastAutomataDelay = 0;

	lpObj->pInventoryCount[0] = 0;
	memcpy(lpObj->m_Resistance, lpm->m_Resistance, MAX_RESISTENCE_TYPE );
	gObjSetInventory1Pointer(lpObj);

	if ( lpObj->m_AttackType != 0 )
	{
		if ( lpObj->m_AttackType >= 100 )
		{
			gObjMonsterMagicAdd(lpObj, lpObj->m_AttackType - 100, 1);
		}
		else
		{
			gObjMonsterMagicAdd(lpObj, (BYTE)lpObj->m_AttackType, 1);
		}

		if ( lpObj->Class == 144 || lpObj->Class == 174 || lpObj->Class == 182 || lpObj->Class == 190 || lpObj->Class == 260 || lpObj->Class == 268 )
		{
			gObjMonsterMagicAdd(lpObj, 17, 1);
		}

		if ( lpObj->Class == 145 
			|| lpObj->Class == 175 
			|| lpObj->Class == 183 
			|| lpObj->Class == 191 
			|| lpObj->Class == 261 
			|| lpObj->Class == 269 
			|| lpObj->Class == 146 
			|| lpObj->Class == 176 
			|| lpObj->Class == 184 
			|| lpObj->Class == 192 
			|| lpObj->Class == 262 
			|| lpObj->Class == 270 
			|| lpObj->Class == 147 
			|| lpObj->Class == 177 
			|| lpObj->Class == 185 
			|| lpObj->Class == 193 
			|| lpObj->Class == 263 
			|| lpObj->Class == 271 
			|| lpObj->Class == 148
			|| lpObj->Class == 178
			|| lpObj->Class == 186
			|| lpObj->Class == 194
			|| lpObj->Class == 264
			|| lpObj->Class == 272
			|| lpObj->Class == 160
			|| lpObj->Class == 180
			|| lpObj->Class == 188
			|| lpObj->Class == 196
			|| lpObj->Class == 266
			|| lpObj->Class == 274 )
		{
			gObjMonsterMagicAdd(lpObj, 17, 1);
		}

		if ( lpObj->Class == 161 || lpObj->Class == 181 || lpObj->Class == 189 || lpObj->Class == 197 || lpObj->Class == 267 || lpObj->Class == 275 )
		{
			gObjMonsterMagicAdd(lpObj, 200, 1);
			gObjMonsterMagicAdd(lpObj, 17, 1);
			gObjMonsterMagicAdd(lpObj, 1, 1);
			gObjMonsterMagicAdd(lpObj, 201, 1);
			gObjMonsterMagicAdd(lpObj, 202, 1);
			gObjMonsterMagicAdd(lpObj, 55, 1);
		}

		if (  lpObj->Class == 149 || lpObj->Class == 179 || lpObj->Class == 187 || lpObj->Class == 195 || lpObj->Class == 265 || lpObj->Class == 273 )
		{
			gObjMonsterMagicAdd(lpObj, 17, 1);
			gObjMonsterMagicAdd(lpObj, 1, 1);
		}

		if ( lpObj->Class == 66 || lpObj->Class == 73 || lpObj->Class == 77 || lpObj->Class == 89 || lpObj->Class == 95 || lpObj->Class == 112 || lpObj->Class == 118 || lpObj->Class == 124 || lpObj->Class == 130 || lpObj->Class == 143 || lpObj->Class == 163 || lpObj->Class == 165 || lpObj->Class == 167 || lpObj->Class == 169 || lpObj->Class == 171 || lpObj->Class == 173 )
		{
			gObjMonsterMagicAdd(lpObj, 17, 1);
		}
		
		if( lpObj->Class == 89 || lpObj->Class == 95 || lpObj->Class == 112 || lpObj->Class == 118 || lpObj->Class == 124 || lpObj->Class == 130 || lpObj->Class == 143 )
		{
			gObjMonsterMagicAdd(lpObj, 3, 1);
		}
	}

	gObjGiveItemSearch(lpObj, lpm->m_MaxItemLevel);
	gObjGiveItemWarehouseSearch(lpObj, lpm->m_MaxItemLevel);
	CreateFrustrum(lpObj->X, lpObj->Y, aIndex);
	MapC[lpObj->MapNumber].SetStandAttr(lpObj->X, lpObj->Y);
	lpObj->m_OldX = lpObj->X;
	lpObj->m_OldY = lpObj->Y;
	lpObj->LastAttackerID = -1;
	return true;
}











void gObjDestroy(unsigned int aSocket,int client)
{
	if ( client < 0 || client > OBJMAX-1)
	{
		return;
	}

	gObj[client].Connected = PLAYER_EMPTY;
}







short gObjAddSearch(SOCKET aSocket, char* ip)
{
	int count;
	int totalcount = 0;

	if ( gDisconnect == 1 )
	{
		return -1;
	}

	if ( gObjTotalUser > gServerMaxUser )
	{
		if (acceptIP.IsIp(ip) == 0 )
		{
			GCJoinSocketResult(4, aSocket);
			return -1;
		}
	}

	count = gObjCount;
	
	while ( true )
	{
		if ( gObj[count].Connected == PLAYER_EMPTY )
		{
			return count;
		}

		count++;

		if ( count >= OBJMAX )
		{
			count = OBJ_STARTUSERINDEX;
		}
		totalcount++;
		if ( totalcount >= OBJMAXUSER )
		{
			break;
		}
	}
	return -1;
}







short gObjAdd(SOCKET aSocket, char* ip, int aIndex)
{
	if ( gObj[aIndex].Connected != PLAYER_EMPTY )
	{
		return -1;
	}

	gObjCharZeroSet(aIndex);
	gNSerialCheck[aIndex].init();
	gObj[aIndex].LoginMsgSnd = FALSE;
	gObj[aIndex].LoginMsgCount = 0;
	memset(gObj[aIndex].AccountID, 0, sizeof(gObj[0].AccountID)-1);
	gObj[aIndex].m_Index = aIndex;
	gObj[aIndex].m_socket = aSocket;
	gObj[aIndex].ConnectCheckTime = GetTickCount();
	gObj[aIndex].AutoSaveTime = gObj[aIndex].ConnectCheckTime;
	gObj[aIndex].Connected = PLAYER_CONNECTED;
	gObj[aIndex].CheckSpeedHack = false;
	gObj[aIndex].LoginMsgCount = 0;
	gObj[aIndex].Magumsa = 0;
	gObj[aIndex].Type = OBJ_USER;
	gObj[aIndex].SaveTimeForStatics = GetTickCount() + 3600000;

	strcpy_s(gObj[aIndex].Ip_addr, sizeof(gObj[aIndex].Ip_addr), ip);
	LogAdd("connect : [%d][%s]", aIndex, ip);
	gObjCount++;
	
	if ( gObjCount >= OBJMAX )
	{
		gObjCount = OBJ_STARTUSERINDEX;
	}

	return aIndex;
}







short gObjMonsterRecall(int iMapNumber)
{
	int number = gObjAddMonster(iMapNumber);

	if ( number < 0 )
	{
		return -1;
	}
	return -1;
}







short gObjAddMonster(int iMapNumber)
{
	if (g_MapServerManager.CheckMapCanMove(iMapNumber) == FALSE )
	{
		return -1;
	}

	int count;
	int totalcount=0;

	count = gObjMonCount;

	while ( true )
	{
		if ( gObj[count].Connected == PLAYER_EMPTY )
		{
			gObjCharZeroSet(count);
			gObj[count].m_Index = count;
			gObj[count].Connected = PLAYER_CONNECTED;
			gObjMonCount++;

			if ( gObjMonCount >= OBJ_MAXMONSTER )
			{
				gObjMonCount = 0;
			}
			
		return count;

		}

		count ++;
		
		if ( count >= OBJ_MAXMONSTER )
		{
			count = 0;
		}

		totalcount++;

		if ( totalcount >= OBJ_MAXMONSTER )
		{
			LogAdd( "error : Can't add any more. %s %d", __FILE__, __LINE__ );
			return -1;
		}
	}
	return -1;
}







int gObjAddCallMon()//����� ������� � ��� ����� �������� �������(� ������� ��� ������� PLAYER_CONNECTED)
{
	int count;
	int totalcount = 0;

	count = gObjCallMonCount;

	while ( true )
	{
		if ( gObj[count].Connected == PLAYER_EMPTY )
		{
			gObjCharZeroSet(count);
			gObj[count].m_Index = count;
			gObj[count].Connected = PLAYER_CONNECTED;
			gObjCallMonCount++;

			if ( gObjCallMonCount >= OBJ_STARTUSERINDEX )
			{
				gObjCallMonCount = OBJ_MAXMONSTER;

			}
			return count;
		}

		count++;

		if ( count >= OBJ_STARTUSERINDEX )
		{
			count = OBJ_MAXMONSTER;
		}

		totalcount++;

		if ( totalcount >= OBJ_CALLMONCOUNT )
		{
			LogAdd("error : Can't add any more. %s %d", __FILE__, __LINE__);
			return -1;
		}
	}

	return -1;

}







void gObjUserKill(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if ( lpObj->CloseCount < 1 )
	{
		lpObj->CloseCount = 6;
		lpObj->CloseType = 0;
	}
}






void gObjAllLogOut()
{
	static BOOL bAllLogOut = FALSE;

	if ( bAllLogOut == 0 )
	{
		bAllLogOut = 1;
		gObjAllDisconnect();
		Sleep(1000);
		LogAdd( "Whole connection closed");
	}
}






void gObjAllDisconnect()
{
	gDisconnect = TRUE;

	for ( int n=OBJ_STARTUSERINDEX; n< OBJMAX; n++)
	{
		if ( gObj[n].Connected > PLAYER_EMPTY )
		{
			if ( gObj[n].Type == OBJ_USER )
			{
				CloseClient(n);
			}
		}
	}
}






void gObjTradeSave(LPOBJ lpObj, int index)
{
	if ( lpObj->m_IfState.use != 0 && lpObj->m_IfState.type == 1 )
	{
		int tObjNum = lpObj->TargetNumber;

		if ( tObjNum > 0 )
		{
			char szTemp[256];

			CGTradeResult(tObjNum, 0);
			wsprintf(szTemp, "%s has logged out. Trading will be cancelled.", lpObj->Name);
			GCServerMsgStringSend((char*)szTemp, tObjNum, 1);
			gObjTradeCancel(tObjNum);
			LogAdd("Opposite canceled trade : [%s][%s] .", gObj[tObjNum].AccountID, gObj[tObjNum].Name);
		}

		gObjTradeCancel( index );
		LogAdd("Cancel trade : [%s][%s] .", lpObj->AccountID, lpObj->Name);
	}
}






void gObjBillRequest(LPOBJ lpObj)
{
	char szMsg[128];

	wsprintf(szMsg, "Welcome to Play4Free My Games Network!");
	LogAdd("[%s][%s] BillType : (NoCharge)", lpObj->AccountID, lpObj->Name);

	LogAdd(szMsg);
	GCServerMsgStringSend(szMsg, lpObj->m_Index, 1);
}






short gObjMemFree(int index)
{
	int i = 0;
	LPOBJ lpObj;

	if ( gDisconnect == TRUE )
	{
		return -1;
	}

	if ( index < 0 || index > OBJMAX )
	{
		LogAdd("(%s)(%d) = index over error (%d)", __FILE__, __LINE__, index);
		return false;
	}

	lpObj = &gObj[index];

	if ( lpObj->Connected < PLAYER_CONNECTED )
	{
		return false;
	}

	gObjTradeSave(lpObj, index);

	if ( lpObj->Connected >= PLAYER_LOGGED )
	{
		if ( lpObj->Type == OBJ_USER )
		{
			if ( lpObj->Connected == PLAYER_PLAYING )
			{
				if (  BC_MAP_RANGE(lpObj->MapNumber) )
				{
					g_BloodCastle.SearchUserDropQuestItem(lpObj->m_Index);
				}

				GJSetCharacterInfo(lpObj, index, 0);
			}
			
			GJPUserClose(lpObj);
		}
	}

	gObjViewportClose(lpObj);
	lpObj->Connected = PLAYER_EMPTY;
	return 1;
}








BOOL gObjGameClose(int aIndex)
{
	if ( aIndex < 0 || aIndex > OBJMAX )	// Deathway fix
	{
		LogAdd("(%s)(%d) = index over error (%d)", __FILE__, __LINE__, aIndex);

		return FALSE;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if ( lpObj->Connected != PLAYER_PLAYING )
	{
		return FALSE;
	}

	if ( lpObj->Type != OBJ_USER )
	{
		LogAdd("Invalid character type causes failure to close (%s/%s)", lpObj->AccountID, lpObj->Name);
		return FALSE;
	}

	if ( lpObj->m_RecallMon >= 0 )
	{
		gObjMonsterCallKill(lpObj->m_Index);
	}

	gObjMagicTextSave(lpObj);

	if ( (   (lpObj->m_IfState.use != 0 )
		&&  (lpObj->m_IfState.type == 7 )) 
		|| ((lpObj->m_IfState.use != 0)  
		&& (lpObj->m_IfState.type == 13)))
	{
		if ( lpObj->bIsChaosMixCompleted == true || lpObj->m_bIsCastleNPCUpgradeCompleted == true)
		{
			gObjInventoryCommit(aIndex);
		}
		else
		{
			gObjInventoryRollback(aIndex);
		}
	}

	gObjTradeSave(lpObj, aIndex);

	if ( (lpObj->m_IfState.use != 0 )
		&&  (lpObj->m_IfState.type == 10 ) 
		&& lpObj->TargetShopNumber == 229)
	{
		gQeustNpcTeleport.TalkRefDel();
	}

	if ( (lpObj->Authority&2) == 2 )
	{
		cManager.ManagerDel(lpObj->Name);
	}


	if ( OBJMAX_RANGE(lpObj->m_iDuelUserRequested) )
	{
		gObjSendDuelEnd(&gObj[lpObj->m_iDuelUserRequested]);
	}


	if ( gObjDuelCheck(lpObj) != FALSE )
	{
		gObjSendDuelEnd(&gObj[lpObj->m_iDuelUser]);
	}


	gObjResetDuel(lpObj);


	if ( lpObj->PartyNumber >= 0 )
	{
		int iPartyIndex= gParty.GetIndex(lpObj->PartyNumber, lpObj->m_Index, lpObj->DBNumber);

		if ( iPartyIndex >= 0 )
		{
			PMSG_PARTYDELUSER pMsg;

			pMsg.Number = iPartyIndex;

			CGPartyDelUser(&pMsg, lpObj->m_Index);
		}
	}


	if ( lpObj->GuildNumber > 0 )
	{
		if ( lpObj->lpGuild->WarState == 1 )
		{
			gObjGuildWarMasterClose(lpObj);
		}

		GDCharClose(0, lpObj->lpGuild->Name, lpObj->Name);
	}
	else
	{
		GDCharClose(1, NULL, lpObj->Name);
	}

	if ( lpObj->WarehouseSave == 1 )
	{
		GDSetWarehouseList(lpObj->m_Index);
	}

	if ( (lpObj->MapNumber<11)?FALSE:(lpObj->MapNumber>17)?FALSE:TRUE )
	{
		g_BloodCastle.SearchUserDropQuestItem(lpObj->m_Index);
	}

	gObjSaveChaosBoxItemList(lpObj);

	if ( gObjFixInventoryPointer(aIndex) == false )
	{
		LogAdd("[Fix Inv.Ptr] False Location - %s, %d", __FILE__, __LINE__);
	}

	/*g_CashItemPeriodSystem.GDReqPeriodItemUpdate(lpObj);
	g_CashItemPeriodSystem.ClearPeriodItemEffect(lpObj);*/

	if (IsGM(aIndex))
	{
		TotalGMOnline--;
		for (std::list<std::string>::iterator iter=GMOnline.begin();iter != GMOnline.end();iter++)
		{
			if (strcmp(iter->c_str(),lpObj->Name) ==0 )
			{
				GMOnline.erase(iter);
				GMOnline.sort();
				break;
			}
		}
	}
	else
		TotalOnline--;

	UserSaveMysteryShopFromDB(lpObj);
	SaveUserBuff(lpObj->Name,aIndex);

	ZeroMemory(&gObj[aIndex].SecurePackets,sizeof(gObj[aIndex].SecurePackets));

	GJSetCharacterInfo(lpObj, aIndex, 0);
	gObjViewportClose(lpObj);
	LogAdd("(%d)[%s][%s] Character closed", lpObj->m_Index, lpObj->AccountID, lpObj->Name);

	if(lpObj->Name)
	{
		WhisperCash.DelCash(lpObj->Name);
	}

	/*g_CashShop.DeleteUser(lpObj);*/

	/*if(lpObj->m_iPeriodItemEffectIndex != -1)
	{
		g_CashItemPeriodSystem.GDReqPeriodItemUpdate(lpObj);
		g_CashItemPeriodSystem.ClearPeriodItemEffect(lpObj);
	}*/

	memcpy(lpObj->BackName, lpObj->Name, sizeof(lpObj->Name)-1);
	lpObj->BackName[10] = 0;


	memset(lpObj->Name, 0, sizeof(lpObj->Name)-1);
	lpObj->Connected = PLAYER_LOGGED;

	return TRUE;
}








short gObjDel(int index)
{

	if ( index < 0 || index > OBJMAX )
	{
		LogAdd ("(%s)(%d) = index over error (%d)", __FILE__, __LINE__, index);
		return 0;
	}

	LPOBJ lpObj = &gObj[index];

	if ( lpObj->Connected < PLAYER_CONNECTED )
	{
		return 0;
	}

	if ( MAX_MAP_RANGE(lpObj->MapNumber) )
	{
		MapC[lpObj->MapNumber].ClearStandAttr(lpObj->m_OldX, lpObj->m_OldY);
		MapC[lpObj->MapNumber].ClearStandAttr(lpObj->X, lpObj->Y);
	}

	int UserConnectState = lpObj->Connected;

	if ( lpObj->Type == OBJ_USER )
	{
		gObjGameClose(index);

		if ( UserConnectState >= PLAYER_LOGGED )
		{
			if ( lpObj->m_bMapSvrMoveQuit == false )
			{
				GJPUserClose(lpObj);
				LogAdd("(%d)logout-send : %s [%s]", index, lpObj->AccountID, lpObj->Ip_addr);
			}
			else
			{
				LogAdd("[MapServerMng] User Quit without JoinServer logout-send [%s][%s]",
					lpObj->AccountID, lpObj->Name);
			}

			memset(lpObj->AccountID, 0, sizeof(lpObj->AccountID) -1);
			memset(lpObj->LastJoominNumber, 0, sizeof(lpObj->LastJoominNumber));
		}

		LogAdd("(%d)logout : %s [%s]", index, lpObj->AccountID, lpObj->Ip_addr);
		IpCache.DelIp(lpObj->Ip_addr);
	}

	lpObj->Connected = PLAYER_EMPTY;
	return 1;
}






short gObjSometimeClose(int index)
{
	if ( gDisconnect == 1 )
	{
		return -1;
	}

	if ( index < 0 || index > OBJMAX )	// deathway fix needed
	{
		LogAdd("(%s)(%d) = index over error (%d)", __FILE__, __LINE__, index);
		return 0;
	}

	LPOBJ lpObj = &gObj[index];
	gObjTradeSave(lpObj, index);

	if ( lpObj->Connected > PLAYER_CONNECTED )
	{
		if ( lpObj->Type == OBJ_USER )
		{
			if ( lpObj->Connected == PLAYER_PLAYING )
			{
				if ( lpObj->PartyNumber >= 0 )
				{
					PMSG_PARTYDELUSER pMsg;
					int iPartyIndex = gParty.GetIndex(lpObj->PartyNumber, lpObj->m_Index, lpObj->DBNumber);

					if ( iPartyIndex >= 0 )
					{
						pMsg.Number = iPartyIndex;
						CGPartyDelUser(&pMsg, lpObj->m_Index);
					}
				}
			}
		}
	}

	return 1;
}







BOOL gObjIsGamePlaing(LPOBJ lpObj)
{
	if ( lpObj->Connected < PLAYER_PLAYING )
	{
		return false;
	}

	return TRUE;
}





BOOL gObjIsConnectedGP(int aIndex)
{
	if (aIndex < 0 || aIndex > OBJMAX-1 )
	{
		return FALSE;
	}

	if ( gObj[aIndex].Type != OBJ_USER )
	{
		return FALSE;
	}

	if ( gObj[aIndex].Connected != PLAYER_PLAYING )
	{
		return FALSE;
	}

	if ( gObj[aIndex].CloseCount > 0 )
	{
		return FALSE;
	}

	return TRUE;
}




BOOL gObjIsConnectedGP(int aIndex, char * CharName)
{
	if (aIndex < 0 || aIndex > OBJMAX-1 )
	{
		return FALSE;
	}
	
	if ( gObj[aIndex].Type != OBJ_USER )
	{
		return FALSE;
	}

	if ( gObj[aIndex].Connected < PLAYER_PLAYING )
	{
		return FALSE;
	}

	if ( gObj[aIndex].CloseCount > 0 )
	{
		return FALSE;
	}

	if ( strcmp(gObj[aIndex].Name, CharName) != 0 )
	{
		return FALSE;
	}

	return TRUE;
}








BOOL gObjIsConnected(LPOBJ lpObj)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return FALSE;
	}

	if ( lpObj->Connected != PLAYER_PLAYING )
	{
		return FALSE;
	}

	if ( lpObj->CloseCount > 0 )
	{
		return FALSE;
	}

	return TRUE;
}







BOOL gObjIsConnected(int aIndex) 
{
	if ( aIndex < 0 || aIndex > OBJMAX-1)
	{
		return FALSE;
	}
	LPOBJ lpObj=&gObj[aIndex];

	if ( lpObj->Connected != PLAYER_PLAYING )
	{
		return FALSE;
	}
	return TRUE;
}






BOOL gObjIsConnected(LPOBJ lpObj, int dbnumber)
{
	if (lpObj->Connected != PLAYER_PLAYING)
	{
		return 0;
	}

	if (lpObj->DBNumber != dbnumber)
	{
		return 0;
	}

	return 1;
}











BOOL gObjIsAccontConnect(int aIndex, char* accountid)
{
	if (aIndex < 0 || aIndex > OBJMAX-1) 
	{
		return 0;
	}

	if (gObj[aIndex].Connected < PLAYER_CONNECTED)
	{
		return 0;
	}

	if (strlen(&gObj[aIndex].AccountID[0]) < 1 )
	{
		return 0;
	}

	if ( strcmp(accountid, &gObj[aIndex].AccountID[0]) != 0)
	{
		return 0;
	}
	return 1;
}



BOOL gObjCheckXYMapTile(LPOBJ lpObj, int iDbgName)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return false;
	}

	if ( (lpObj->Authority&2 ) == 2 )
	{
		return FALSE;
	}

	if ( CC_MAP_RANGE(lpObj->MapNumber) )
	{
		if ( g_ChaosCastle.GetCurrentState(lpObj->MapNumber-MAP_INDEX_CHAOSCASTLE1) == 2 )
		{
			return FALSE;
		}
	}

	int x = lpObj->X;
	int y = lpObj->Y;
	int mapnumber = lpObj->MapNumber;

	if ( mapnumber > MAX_NUMBER_MAP-1 )
	{
		mapnumber = MAP_INDEX_LORENCIA;
	}

	int mapminlevel = MapMinUserLevel[mapnumber];

	if ( lpObj->Class == 4 || lpObj->Class == 3 )
	{
		if ( mapminlevel > 0 )
		{
			if ( MapMinUserLevel[mapnumber] > 0 )
			{
				mapminlevel = MapMinUserLevel[mapnumber] - (MapMinUserLevel[mapnumber] / 3 * 2);
			}
		}
	}

	if (lpObj->Level < 10 && (lpObj->Class >= 0 && lpObj->Class <= 4))
	{
		int gt = -1;
		switch(lpObj->Class)
		{
			//DK:1 DW:0 ELF:2 MG:3 DL:4
		case 0:
			{
				if (lpObj->MapNumber != NewbieDWStartMap)
				{
					gt = NewbieDWStartGate;
				}
			}
			break;

		case 1:
			{
				if (lpObj->MapNumber != NewbieDWStartMap)
				{
					gt = NewbieDKStartGate;
				}
			}
			break;

		case 2:
			{
				if (lpObj->MapNumber != NewbieDWStartMap)
				{
					gt = NewbieElfStartGate;
				}
			}
			break;

		case 3:
			{
				if (lpObj->MapNumber != NewbieDWStartMap)
				{
					gt = NewbieMGStartGate;
				}
			}
			break;

		case 4:
			{
				if (lpObj->MapNumber != NewbieDWStartMap)
				{
					gt = NewbieDLStartGate;
				}
			}
			break;
		}

		if (gt != -1)
		{
			LogAdd("%s %d %d %d Invalid location causes to force to move", lpObj->Name, lpObj->MapNumber, lpObj->X, lpObj->Y);
			PMSG_TELEPORT pMsg;
			pMsg.MoveNumber = gt;
			gObjMoveGate(lpObj->m_Index, pMsg.MoveNumber);
		}

	}
	else if ( mapminlevel > lpObj->Level )
		{
			LogAdd("%s %d %d %d Invalid location causes to force to move", lpObj->Name, lpObj->MapNumber, lpObj->X, lpObj->Y);
			PMSG_TELEPORT pMsg;
			pMsg.MoveNumber = 17;
			gObjMoveGate(lpObj->m_Index, pMsg.MoveNumber);
		}
//	}

	BYTE attr = MapC[mapnumber].GetAttr(x, y);

	if ( (attr&4) == 4 || (attr&8) == 8 )
	{
		BYTE attr2 = MapC[mapnumber].GetAttr(x+2, y);
		BYTE attr3 = MapC[mapnumber].GetAttr(x, y+2);
		BYTE attr4 = MapC[mapnumber].GetAttr(x-2, y);
		BYTE attr5 = MapC[mapnumber].GetAttr(x, y-2);

		if ( attr2 > 1 && attr3 > 1 && attr4 > 1 && attr5 > 1 )
		{
			LogAdd("[HACK][ CHECK POSITION ] DbgName[%d] [%s][%s] Map[%d]-(%d,%d) Invalid location causes to force to move",iDbgName,lpObj->AccountID, lpObj->Name, lpObj->MapNumber, lpObj->X, lpObj->Y);
			/*PMSG_TELEPORT pMsg;
			pMsg.MoveNumber = 17;
			gObjMoveGate(lpObj->m_Index, pMsg.MoveNumber);*/
			CloseClient(lpObj->m_Index);

			return TRUE;
		}
	}

	return FALSE;
}







BOOL gObjSetAccountLogin(int aIndex, char * szId, int aUserNumber, int aDBNumber, char* JoominNumber)
{
	if ( !OBJMAX_RANGE(aIndex) )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return 0;
	}

	if ( gObj[aIndex].Connected != PLAYER_CONNECTED )
	{
		LogAdd("error-L2 : (%d) User(%s) is not connected. DBNumber:%d %s %d", aIndex, szId, aDBNumber, __FILE__, __LINE__);
		return 0;
	}

	if ( strcmp(gObj[aIndex].AccountID, szId) != 0 )
	{
		LogAdd("error : %s didn't request to authenticate.", szId);
		return 0;
	}

	gObj[aIndex].UserNumber = aUserNumber;
	gObj[aIndex].DBNumber = aDBNumber;
	gObj[aIndex].Connected = PLAYER_LOGGED;
	strcpy_s(gObj[aIndex].LastJoominNumber, sizeof(gObj[aIndex].LastJoominNumber), JoominNumber);
	return TRUE;

}







BOOL gObjGetUserNumber(int aIndex)
{
	int usernumber;

	if ( !OBJMAX_RANGE(aIndex))
	{
		LogAdd("error : %s %d",__FILE__, __LINE__);
		return 0;
	}

	usernumber=gObj[aIndex].UserNumber;
	return usernumber;
}








BOOL gObjGetNumber(int aIndex, int& UN, int& DBN)
{
	if ( aIndex < 0 || aIndex > OBJMAX-1)
	{
		LogAdd("error : %s %d",__FILE__, __LINE__);
		return 0;
	}
	UN=gObj[aIndex].UserNumber;
	DBN=gObj[aIndex].DBNumber;
	return 1;
}







// gObj Address 653DBF8
char* gObjGetAccountId(int aIndex)
{
	if ( aIndex < 0 || aIndex > OBJMAX-1)
	{
		LogAdd("error : %s %d",__FILE__, __LINE__);
		return 0;
	}

	if ( gObj[aIndex].Connected == 2)
	{
		return &gObj[aIndex].AccountID[0];
	}
	return 0;
}








int gObjGetIndex(char* szId)
{
	int n;

	for (n=OBJ_STARTUSERINDEX;n<OBJMAX; n++)
	{
		if ( gObj[n].Connected >= PLAYER_PLAYING)
		{
			if ( gObj[n].Name[0] == *szId )
			{
				if ( strcmp(&gObj[n].Name[0] , szId) == 0)
				{
					return n;
				}
			}
		}
	}
	return -1;
}








BOOL gObjUserIdConnectCheck(char* szId,int index)
{
	if ( index < 0 || index > OBJMAX)	// Deathway Fix Here
	{
		LogAdd("error : index error !! %s %d",__FILE__, __LINE__);
		return 0;
	}

	if ( gObj[index].Connected < PLAYER_PLAYING)
	{
		return 0;
	}

	if (gObj[index].Name[0] != *szId)
	{
		return 0;
	}

	if ( strcmp(gObj[index].Name , szId) == 0)
	{
		return 1;
	}
	return 0;
}








BYTE GetPathPacketDirPos(int px, int py)
{
	BYTE pos = 0;

	if (px <= -1 && py <= -1)
	{
		pos=0;
	}
	else if (px <= -1 && py == 0)
	{
		pos=7;
	}
	else if ( px <= -1 && py >= 1)
	{
		pos=6;
	}
	else if ( px == 0 && py <= -1)
	{
		pos= 1;
	}
	else if ( px == 0 && py >= 1)
	{
		pos = 5;
	}
	else if ( px >= 1 && py <=-1)
	{
		pos=2;
	}
	else if ( px >= 1 && py == 0)
	{
		pos = 3;
	}
	else if ( px >=1  && py >= 1)
	{
		pos = 4;
	}

	return pos;
}








int  gObjCalDistance(LPOBJ lpObj1, LPOBJ lpObj2)
{
	if ( lpObj1->X == lpObj2->X && lpObj1->Y == lpObj2->Y )
	{
		return 0;
	}

	double tx = lpObj1->X - lpObj2->X;
	double ty = lpObj1->Y - lpObj2->Y;

	return (int)sqrt( (tx*tx)+(ty*ty) );
}








BOOL gObjPositionCheck(LPOBJ lpObj)
{
	int ix = lpObj->m_OldX - lpObj->TX;
	int iy = lpObj->m_OldY - lpObj->TY;

	if ( ix <= -15 ||  ix >= 15 )
	{
		return FALSE;
	}

	if ( iy <= -15 ||  iy >= 15 )
	{
		return FALSE;
	}

	return TRUE;
}








BOOL gObjCheckTileArea(int aIndex, int x, int y, int dis)
{
	LPOBJ lpObj = & gObj[aIndex];

	if ( x < (lpObj->X - dis) || x > (lpObj->X + dis) || y < (lpObj->Y - dis) || y > (lpObj->Y + dis) )
	{
		return FALSE;
	}
	return TRUE;
}








BOOL ExtentCheck(int x, int y, int w, int h)
{
	if ( (x >=0) && (x<w) && (y >=0) && (y<h) )
	{
		return 1;
	}
	return 0;
}






void gObjSetInventory1Pointer(LPOBJ lpObj)
{
	lpObj->pInventory = lpObj->Inventory1;
	lpObj->pInventoryMap = lpObj->InventoryMap1;
	lpObj->pInventoryCount  = &lpObj->InventoryCount1;
}





void gObjSetInventory2Pointer(LPOBJ lpObj)
{
	lpObj->pInventory = lpObj->Inventory2;
	lpObj->pInventoryMap = lpObj->InventoryMap2;
	lpObj->pInventoryCount  = &lpObj->InventoryCount2;
}



	

void gObjAddMsgSend(LPOBJ lpObj, int aMsgCode, int aIndex, int  SubCode)
{
	for ( int n=0;n<MAX_MONSTER_SEND_MSG;n++)
	{
		if ( gSMMsg[lpObj->m_Index][n].MsgCode < 0 )
		{
			gSMMsg[lpObj->m_Index][n].MsgCode = aMsgCode;
			gSMMsg[lpObj->m_Index][n].MsgTime = GetTickCount();
			gSMMsg[lpObj->m_Index][n].SendUser = aIndex;
			gSMMsg[lpObj->m_Index][n].SubCode = SubCode;

			return;
		}
	}

	for (int n=0;n<MAX_MONSTER_SEND_MSG;n++)
	{
		if ( gSMMsg[lpObj->m_Index][n].MsgCode == 2 || gSMMsg[lpObj->m_Index][n].MsgCode == 6 || gSMMsg[lpObj->m_Index][n].MsgCode == 7 )
		{
			gSMMsg[lpObj->m_Index][n].MsgCode = aMsgCode;
			gSMMsg[lpObj->m_Index][n].MsgTime = GetTickCount();
			gSMMsg[lpObj->m_Index][n].SendUser = aIndex;
			gSMMsg[lpObj->m_Index][n].SubCode = SubCode;
			
			return;
		}
	}
}






void gObjAddMsgSendDelay(LPOBJ lpObj, int aMsgCode, int aIndex, int delay, int SubCode)
{
	for ( int n=0;n<MAX_MONSTER_SEND_MSG;n++)
	{
		if ( gSMMsg[lpObj->m_Index][n].MsgCode < 0 )
		{
			gSMMsg[lpObj->m_Index][n].MsgCode = aMsgCode;
			gSMMsg[lpObj->m_Index][n].MsgTime = GetTickCount() + delay;
			gSMMsg[lpObj->m_Index][n].SendUser = aIndex;
			gSMMsg[lpObj->m_Index][n].SubCode = SubCode;

			return;
		}
	}

	for (int n=0;n<MAX_MONSTER_SEND_MSG;n++)
	{
		if ( gSMMsg[lpObj->m_Index][n].MsgCode == 2 || gSMMsg[lpObj->m_Index][n].MsgCode == 6 || gSMMsg[lpObj->m_Index][n].MsgCode == 7 )
		{
			gSMMsg[lpObj->m_Index][n].MsgCode = aMsgCode;
			gSMMsg[lpObj->m_Index][n].MsgTime = GetTickCount();
			gSMMsg[lpObj->m_Index][n].SendUser= aIndex;
			gSMMsg[lpObj->m_Index][n].SubCode = SubCode;
			
			return;
		}
	}

}





void gObjAddMsgSendDelayInSpecificQPos(LPOBJ lpObj, int aMsgCode, int aIndex, int delay, int SubCode, int iQPosition)
{
	if ( iQPosition >= 0 &&  iQPosition < MAX_MONSTER_SEND_MSG )
	{
		gSMMsg[lpObj->m_Index][iQPosition].MsgCode = aMsgCode;
		gSMMsg[lpObj->m_Index][iQPosition].MsgTime = GetTickCount();
		gSMMsg[lpObj->m_Index][iQPosition].SendUser = aIndex;
		gSMMsg[lpObj->m_Index][iQPosition].SubCode = SubCode;
	}

}






void gObjAddAttackProcMsgSendDelay(LPOBJ lpObj, int aMsgCode, int aIndex, int delay, int SubCode, int SubCode2)
{
	for ( int n=0;n<MAX_MONSTER_SEND_ATTACK_MSG;n++)
	{
		int iIndex = lpObj->m_Index - OBJ_STARTUSERINDEX;

		if ( gSMAttackProcMsg[iIndex][n].MsgCode < 0 )
		{
			gSMAttackProcMsg[iIndex][n].MsgCode = aMsgCode;
			gSMAttackProcMsg[iIndex][n].MsgTime = GetTickCount() + delay;
			gSMAttackProcMsg[iIndex][n].SendUser = aIndex;
			gSMAttackProcMsg[iIndex][n].SubCode = SubCode;
			gSMAttackProcMsg[iIndex][n].SubCode2 = SubCode2;

			return;
		}
	}

}





void gObjMsgProc(LPOBJ lpObj)
{
	int aIndex = lpObj->m_Index;

	for ( int n=0;n<MAX_MONSTER_SEND_MSG;n++)
	{
		if ( gSMMsg[aIndex][n].MsgCode >= 0 )
		{
			if ( GetTickCount() > gSMMsg[aIndex][n].MsgTime )
			{
				if ( lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC )
				{
					gObjMonsterStateProc(lpObj, gSMMsg[aIndex][n].MsgCode, gSMMsg[aIndex][n].SendUser, gSMMsg[aIndex][n].SubCode);
				}
				else
				{
					gObjStateProc(lpObj, gSMMsg[aIndex][n].MsgCode, gSMMsg[aIndex][n].SendUser, gSMMsg[aIndex][n].SubCode);
				}

				gSMMsg[aIndex][n].MsgCode = -1;
			}
		}
	}
}






void gObjStateProc(LPOBJ lpObj, int aMsgCode, int aIndex, int SubCode)
{
	if ( (  (aIndex<0)?FALSE:(aIndex > OBJMAX-1)?FALSE:TRUE ) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__ );
		return;
	}

	switch ( aMsgCode )
	{
		case  2:
			gObjBackSpring(lpObj, &gObj[aIndex]);
			break;

		case  3:
			gObjMonsterDieLifePlus(lpObj, &gObj[aIndex]);
			break;

		case 1000:
			gObjBillRequest(lpObj);
			break;

		case  4:
			if ( lpObj->lpGuild != NULL && lpObj->lpGuild->lpTargetGuildNode != NULL )
			{
				gObjGuildWarEnd(lpObj->lpGuild, lpObj->lpGuild->lpTargetGuildNode);
			}
			break;

		case  5:
			if ( lpObj->lpGuild != NULL && lpObj->lpGuild->WarState != NULL && lpObj->lpGuild->WarType == 1 )
			{
				BattleSoccerGoalStart(0);
			}
			break;

		case  7:
			if ( lpObj->lpGuild != NULL && lpObj->lpGuild->WarState != NULL && lpObj->lpGuild->WarType == 1)
			{
				if ( lpObj->lpGuild->BattleGroundIndex >= 0 )
				{
					GCManagerGuildWarEnd(lpObj->lpGuild->Name);
				}
			}
			break;

		case 10:
			if ( lpObj->DamageReflect != 0 )
			{
				gObjAttack(lpObj, &gObj[aIndex], 0, 0, 0, SubCode, 0);
			}
			break;
		case 54:
			if( lpObj->Live )
			{
				CMagicInf * lpMagic = &DefMagicInf[79];
				gObjAttack(lpObj, &gObj[aIndex], lpMagic, 1, 0, SubCode, 0);
			}
			break;
	}
}







void gObjStateAttackProc(LPOBJ lpObj, int aMsgCode, int aIndex, int SubCode, int SubCode2)
{
	if ( OBJMAX_RANGE(aIndex) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__ );
		return;
	}

	switch ( aMsgCode )
	{
		case 50:
			if ( lpObj->Live != FALSE )
			{
				CMagicInf * lpMagic = gObjGetMagicSearch(lpObj, SubCode);
				gObjAttack(lpObj, &gObj[aIndex], lpMagic, 0, 1, 0, SubCode2);
			}
			break;
		case 53:
			if( lpObj->Live )
			{
				CMagicInf * lpMagic = gObjGetMagicSearch(lpObj, SubCode);
				gObjAttack(lpObj, &gObj[aIndex], lpMagic, 1, 1, 0, 0);
			}
			break;
		case 51:
			gDarkSpirit[lpObj->m_Index].Attack(lpObj, &gObj[aIndex], NULL, SubCode, SubCode2);
			break;
	}

}






BOOL gObjBackSpring(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if ( MAX_MAP_RANGE(lpObj->MapNumber) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return FALSE;
	}

	if ( lpObj->Type == OBJ_USER )
	{
		if ( lpObj->m_LastTeleportTime > 0 )
		{
			return FALSE;
		}
	}

 
	if ( lpObj->Type == OBJ_USER )
	{
		if ( (lpObj->Authority & 2) == 2 )
			return FALSE;
	}


	if ( lpObj->Class >= 131 && lpObj->Class <= 134 )
	{
		return FALSE;
	}

	int tdir;

 
	if( lpObj->Class == 277 || lpObj->Class == 283 ||
		lpObj->Class == 288 || lpObj->Class == 278 ||
		lpObj->Class == 215 || lpObj->Class == 216 || 
		lpObj->Class == 217 || lpObj->Class == 218 ||
		lpObj->Class == 219 )
	{
		return FALSE;
	}


	if ( g_CastleSiege.GetCrownUserIndex() == lpObj->m_Index )
	{
		if ( lpObj->pInventory[8].m_Type == ITEMGET(13,4) )
		{
			return FALSE;
		}
	}

	if ( g_Crywolf.GetCrywolfState() == 4 || g_Crywolf.GetCrywolfState() == 3 )
	{
		if ( lpObj->Type == OBJ_USER )
		{
			for(int i=205 ; i<=209;i++)
			{
				int iAltarIndex = g_CrywolfNPC_Altar.GetAltarUserIndex(i);
				if ( iAltarIndex != -1 )
				{
					if ( iAltarIndex == lpObj->m_Index )
					{
						return FALSE;
					}
				}
			}
		}
	}

	if ( CHECK_LIMIT2(lpObj->Class, 205, 210) || 
		 CHECK_CLASS(lpObj->Class, 204) )
	{
		return FALSE;
	}
	
	if ( lpObj->Class == 348 )
	{
		return FALSE;
	}


	if ( Random(0,2) == 0 )
	{
		if ( lpTargetObj->Dir < 4 )
		{
			tdir = lpTargetObj->Dir + 4;
		}
		else
		{
			tdir = lpTargetObj->Dir - 4;
		}

		tdir *= 2;
	}
	else
	{
		tdir = lpTargetObj->Dir * 2;
	}

	
	int x = lpObj->X;
	int y = lpObj->Y;
	x += RoadPathTable[tdir];
	y += RoadPathTable[1+tdir];
	BYTE attr = MapC[lpObj->MapNumber].GetAttr(x, y);

	if ( (attr&1)==1 || (attr&2)==2 || (attr&4)== 4 || (attr&8)== 8 
 
		 || (attr&16)== 16 

		 )
	{
		return FALSE;
	}

	PMSG_POSISTION_SET pMove;
	pMove.h.c = 0xC1;
	pMove.h.headcode = P_DAMAGE;
	pMove.h.size = sizeof(pMove);
	pMove.X = x;
	pMove.Y = y;

	lpObj->m_Rest = 0;
	MapC[lpObj->MapNumber].ClearStandAttr(lpObj->m_OldX, lpObj->m_OldY);
	MapC[lpObj->MapNumber].SetStandAttr(x, y);
	lpObj->m_OldX = x;
	lpObj->m_OldY = y;
	RecvPositionSetProc(&pMove, lpObj->m_Index);

	if ( lpObj->Type == OBJ_USER )
	{
		lpObj->PathCount = 0;
	}

	return TRUE;
}







BOOL BackSpringCheck(int & x, int & y, int & dir, BYTE map)
{
	BYTE attr;
	int tx = x;
	int ty = y;
	int tdir = dir/2;

	tx = tx + RoadPathTable[dir];
	ty = ty + RoadPathTable[1+dir];

	attr = MapC[map].GetAttr(tx, ty);

	if ( (attr&1)==1 || (attr&4)== 4 || (attr&8)== 8 
 
		 || (attr&16)== 16 

		 )
	{
		tdir += 4;

		if ( tdir > 7 )
		{
			tdir -= 8;
		}

		dir = tdir * 2;
		return FALSE;
	}

	x = tx;
	y = ty;

	return TRUE;
}

BOOL gObjBackSpring2(LPOBJ lpObj, LPOBJ lpTargetObj, int count)
{
	if ( MAX_MAP_RANGE(lpObj->MapNumber) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return FALSE;
	}

 
	if ( lpObj->Type == OBJ_USER )
	{
		if ( (lpObj->Authority & 2) == 2 )
			return FALSE;
	}

	if ( lpObj->Class == 287 || lpObj->Class == 286 )
	{
		return FALSE;
	}

 
	if ( lpObj->Class == 278 )
	{
		return FALSE;
	}


	if ( lpObj->Class >= 131 && lpObj->Class <= 134 )
	{
		return FALSE;
	}

	int tdir;
 
	if( lpObj->Class == 277 || lpObj->Class == 283 ||
		lpObj->Class == 288 || lpObj->Class == 278 ||
		lpObj->Class == 215 || lpObj->Class == 216 || 
		lpObj->Class == 217 || lpObj->Class == 218 ||
		lpObj->Class == 219 )
	{
		return FALSE;
	}


	if ( g_CastleSiege.GetCrownUserIndex() == lpObj->m_Index )
	{
		if ( lpObj->pInventory[8].m_Type == ITEMGET(13,4) )
		{
			return FALSE;
		}
	}

	if ( g_Crywolf.GetCrywolfState() == 4 || g_Crywolf.GetCrywolfState() == 3 )
	{
		if ( lpObj->Type == OBJ_USER )
		{
			for(int i=205 ; i<=209;i++)
			{
				int iAltarIndex = g_CrywolfNPC_Altar.GetAltarUserIndex(i);
				if ( iAltarIndex != -1 )
				{
					if ( iAltarIndex == lpObj->m_Index )
					{
						return FALSE;
					}
				}
			}
		}
	}

	if ( CHECK_LIMIT2(lpObj->Class, 205, 210) || 
		 CHECK_CLASS(lpObj->Class, 204) )
	{
		return FALSE;
	}
	
	if ( lpObj->Class == 348 )
	{
		return FALSE;
	}

	
	tdir = GetPathPacketDirPos(lpObj->X - lpTargetObj->X, lpObj->Y - lpTargetObj->Y) * 2;
	int x = lpObj->X;
	int y = lpObj->Y;

	for ( int n=0;n<count;n++)
	{
		if ( n >= 2 )
		{
			if ( lpObj->Class == 4 || lpObj->Class == 3 || lpObj->Class == 1 )
			{
				BackSpringCheck(x, y, tdir, lpObj->MapNumber);
			}
		}
		else
		{
			BackSpringCheck(x, y, tdir, lpObj->MapNumber);
		}
	}

	PMSG_POSISTION_SET pMove;

	pMove.h.c = 0xC1;
	pMove.h.headcode = P_DAMAGE;
	pMove.h.size = sizeof(pMove);
	pMove.X = x;
	pMove.Y = y;

	lpObj->m_Rest = 0;
	MapC[lpObj->MapNumber].ClearStandAttr(lpObj->m_OldX, lpObj->m_OldY);
	MapC[lpObj->MapNumber].SetStandAttr(x, y);
	lpObj->m_OldX = x;
	lpObj->m_OldY = y;
	RecvPositionSetProc(&pMove, lpObj->m_Index);

	return TRUE;
}








bool gObjLevelUp(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType)
{
	LogAdd("Experience : Map[%d]-(%d,%d) [%s][%s](%d) %u %d MonsterIndex : %d, EventType : %d",
		lpObj->MapNumber,lpObj->X,lpObj->Y,lpObj->AccountID,lpObj->Name,lpObj->Level,lpObj->Experience - addexp,addexp,iMonsterType,iEventType);

	if ( lpObj->Level >= MAX_CHAR_LEVEL && lpObj->Experience >= gLevelExperience[-1+lpObj->Level] )
	{
		lpObj->Experience = gLevelExperience[-1+lpObj->Level];
		GCServerMsgStringSend("You have reached a maximum level", lpObj->m_Index, 1);
		return false;
	}

	gObjSetExpPetItem(lpObj->m_Index, addexp);

	if (lpObj->Experience < lpObj->NextExp)
		return true;
	else
	{
		int NExp = 0;//�������� �����
		while (lpObj->Experience > lpObj->NextExp)//���� �-��� �������� ����� ��������� ��� ��� ���
		{
			NExp = lpObj->Experience - lpObj->NextExp;// �������� ������� ����� ���� ��� ���
			//�������� ����� ��� ��
			lpObj->Experience = lpObj->NextExp;
			lpObj->Level ++;

			if ( lpObj->Class == 4 || lpObj->Class == 3 )
			{
				lpObj->LevelUpPoint += g_LvlUpPointDLMG;
			}
			else
			{
				lpObj->LevelUpPoint += g_LvlUpPointNormal;
			}

			if ( lpObj->PlusStatQuestClear != false )
			{
				lpObj->LevelUpPoint += 1;
				LogAdd("[%s][%s] LevelUp PlusStatQuest Clear AddStat %d",
					lpObj->AccountID, lpObj->Name, lpObj->LevelUpPoint);
			}

			gObjCalCharacter(lpObj->m_Index);

			lpObj->MaxLife += DCInfo.DefClass[ lpObj->Class ].LevelLife;
			lpObj->MaxMana += DCInfo.DefClass[ lpObj->Class ].LevelMana;
			lpObj->Life = lpObj->MaxLife;
			lpObj->Mana = lpObj->MaxMana;

			lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
			lpObj->Mana = lpObj->MaxMana + lpObj->AddMana;

			gObjCalcShieldPoint(lpObj);
			lpObj->iShield = lpObj->iMaxShield + lpObj->iAddShield;
			GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,0xFF,0,lpObj->iShield);

			gObjNextExpCal(lpObj);	
			LogAdd("Level Up [%s][%s] (%d)", lpObj->AccountID, lpObj->Name, lpObj->Level);

			if(lpObj->Class == CLASS_ELF)
			{
				if(lpObj->Level >= g_SkillAdditionInfo.GetInfinityArrowUseLevel() && lpObj->ChangeUP >= 1)
				{
					int iAddSkillPosition = gObjMagicAdd(lpObj,0x4D,0);

					if(iAddSkillPosition >= 0)
					{
						GCMagicListOneSend(lpObj->m_Index,iAddSkillPosition,0x4D,0xDC,0,0);
						LogAdd("[%s][%s] Add Infinity Arrow Skill (Character Level : %d)(ChangeUp: %d)",
							lpObj->AccountID,lpObj->Name,lpObj->Level,lpObj->ChangeUP);
					}
					else
					{
						LogAdd("[%s][%s] Fail - Add Infinity Arrow Skill (Character Level : %d)(ChangeUp: %d)",
							lpObj->AccountID,lpObj->Name,lpObj->Level,lpObj->ChangeUP);
					}
				}
			}


			GJSetCharacterInfo(lpObj, lpObj->m_Index, 0);
			gObjSetBP(lpObj->m_Index);
			GCLevelUpMsgSend(lpObj->m_Index, 1);
			gObjCalcMaxLifePower(lpObj->m_Index);

			if (NExp > 0)//���� �-��� ����� ����� �� ����
				lpObj->Experience += NExp;// ������ �� �� �������� ����� � �� ��� ����� ��� ��
		}
	}
	
	return true;
}







BOOL gObjLevelUpPointAdd(BYTE type, LPOBJ lpObj)	// type : [1:Strength][2:Agility][3:Vitality][4:Energy][5:Leadership]
{
	if ( lpObj->Type > OBJ_NPC )
	{
		LogAdd( "error-L1: Level up point value error %s %s %s %d", lpObj->AccountID, lpObj->Name, __FILE__, __LINE__);
		return FALSE;
	}

	if ( lpObj->LevelUpPoint < 1 )
	{
		return FALSE;
	}

	switch ( type )
	{
		case 0:
			lpObj->Strength++;
			break;

		case 1:
			lpObj->Dexterity++;
			break;

		case 2:
			lpObj->Vitality++;

			lpObj->MaxLife += lpObj->VitalityToLife;
			gObjCalcMaxLifePower(lpObj->m_Index);
			break;

		case 3:
			lpObj->Energy++;
			lpObj->MaxMana += lpObj->EnergyToMana;
			break;

		case 4:
			lpObj->Leadership++;
			break;
	}

	lpObj->LevelUpPoint--;
	gObjCalCharacter(lpObj->m_Index);

	return TRUE;
}



BOOL gObjLevelUpPointAdd(BYTE type, LPOBJ lpObj, int count)	// type : [1:Strength][2:Agility][3:Vitality][4:Energy][5:Leadership]
{
	if ( lpObj->Type > OBJ_NPC )
	{
		LogAdd( "error-L1: Level up point value error %s %s %s %d", lpObj->AccountID, lpObj->Name, __FILE__, __LINE__);
		return FALSE;
	}

	if ( lpObj->LevelUpPoint < 1 )
	{
		return FALSE;
	}

	switch ( type )
	{
	case 0:
		lpObj->Strength+=count;
		break;

	case 1:
		lpObj->Dexterity+=count;
		break;

	case 2:
		lpObj->Vitality+=count;

		lpObj->MaxLife += lpObj->VitalityToLife;
		gObjCalcMaxLifePower(lpObj->m_Index);
		break;

	case 3:
		lpObj->Energy+=count;
		lpObj->MaxMana += lpObj->EnergyToMana;
		break;

	case 4:
		lpObj->Leadership+=count;
		break;
	}

	lpObj->LevelUpPoint-=count;
	gObjCalCharacter(lpObj->m_Index);

	return TRUE;
}





void gObjMonsterItemLoadScript(LPOBJ lpObj, char* script_file)
{
	int Token;
	int type;
	int index;
	int level;
	int op1;
	int op2;
	int op3;
	int incount;
	
	if ( fopen_s(&SMDFile,script_file, "r") != 0 )
	{
		MsgBox("file open error %s", script_file);
		return;
	}
	incount=0;

	while ( true )
	{
		Token=GetToken();
		
		if (Token == 2)
		{
			break;
		}

		if (Token == 1)
		{
			type=(int)TokenNumber;

			Token=GetToken();
			index=(int)TokenNumber;

			Token=GetToken();
			level=(int)TokenNumber;

			Token=GetToken();
			op1=(int)TokenNumber;

			Token=GetToken();
			op2=(int)TokenNumber;

			Token=GetToken();
			op3=(int)TokenNumber;

			if (  gObjMonsterInventoryInsertItem(lpObj, type, index, level, op1, op2, op3)  != 0xFF)
			{
				incount++;

				if (incount > 75)
				{
					break;
				}
			}
		}
		
	}


	fclose(SMDFile);
}


void gObjGiveItemSearch(LPOBJ lpObj, int maxlevel)
{
#if ACTIVE_ITEM_SEARCH == 0
	//goto lavelend;
#endif

//	int count;
	//while (--count)
	{

	}

#if ACTIVE_ITEM_SEARCH == 0
	//labelend:
#endif
}





BYTE gObjWarehouseInsertItem(LPOBJ lpObj, int type, int index, int level, int pos)
{
	CItem item;

	int item_type = ItemGetNumberMake(type, index);
	item.m_Level =level;
	item.Convert(item_type, 0 , 0, 0, 0, 0,0, CURRENT_DB_VERSION);
	lpObj->pWarehouse[pos] = item;
	return pos;
}







void gObjGiveItemWarehouseSearch(LPOBJ lpObj, int maxlevel)
{
#if ACTIVE_ITEM_SEARCH == 0
	//goto lavelend;
#endif

	

#if ACTIVE_ITEM_SEARCH == 0
	//labelend:
#endif
}






BOOL gObjGuildMasterCapacityTest(LPOBJ lpObj)
{
	if (lpObj->Level < gGuildCreateLevel)
	{
		return 0;
	}
	return 1;
}







void gObjNextExpCal(LPOBJ lpObj)
{
	lpObj->NextExp = gLevelExperience[lpObj->Level];
}







int  retResistance(LPOBJ lpObj, int Resistance_Type)
{
	BYTE r = lpObj->m_Resistance[Resistance_Type];

	if( r == 0xFF)
	{
		return 1;
	}

	if ( r > 0 && lpObj->m_iPotionSoulTime > 0 && (Resistance_Type == 2 || Resistance_Type == 0 ))
	{
		r += r * 50 / 100;
	}

	if ( r  == 0 )
	{
		return 0;
	}

	if (  Random(0,r) == 0 )
	{
		return 0;
	}

	return 1;
}






BOOL retCalcSkillResistance(LPOBJ lpTargetObj, BOOL isDouble)
{
	if ( isDouble != FALSE )
	{
		if ( (Random(0,99)) < 45 )
		{
			return TRUE;
		}
	}
	else
	{
		if ( (Random(0,99)) < 40 )
		{
			return TRUE;
		}
	}

	return FALSE;
}






BOOL gObjAttackQ(LPOBJ lpObj)
{
	if ( ATTRIBUTE_RANGE(lpObj->m_Attribute) )
	{
		return FALSE;
	}

	if ( lpObj->Class == 221 || lpObj->Class == 222 )
	{
		return FALSE;
	}

 
	if ( lpObj->Class == 277 || lpObj->Class == 283 )
	{
		if ( g_CastleSiege.GetCastleState() != CASTLESIEGE_STATE_STARTSIEGE )
		{
			return FALSE;
		}
	}

	if ( lpObj->Class == 221 || lpObj->Class == 222 )
	{
		return FALSE;
	}

	if ( lpObj->Class == 277 && lpObj->m_btCsGateOpen == 1 )
	{
		return FALSE;
	}


	if ( BC_MAP_RANGE(lpObj->MapNumber) )
	{
		if ( lpObj->Type >= OBJ_MONSTER )
		{
			if ( lpObj->Class == 131 && g_BloodCastle.CheckMonsterKillSuccess(lpObj->MapNumber-MAP_INDEX_BLOODCASTLE1) == false)
			{
				return FALSE;
			}

			if ( (((lpObj->Class - 132) < 0)?FALSE:((lpObj->Class-132) > 2)?FALSE:TRUE) !=FALSE && g_BloodCastle.CheckBossKillSuccess(lpObj->MapNumber-MAP_INDEX_BLOODCASTLE1) == false )
			{
				return FALSE;
			}
		}
	}

	if ( lpObj->Class != 247 && lpObj->Class != 249 && lpObj->Class  >= 100 && lpObj->Class <= 110 )
	{
		return FALSE;
	}

	if ( lpObj->m_State != 2 )
	{
		return FALSE;
	}

	if( lpObj->Live == false )
	{
		return false;
	}

	if ( lpObj->Teleport == 1 )
	{
		return FALSE;
	}

	return TRUE;
}


int Random(int imin,int imax)
{
	static CRandomSFMT SFMT(ReadTSC(),0);
	return SFMT.IRandom(imin,imax);
}

int gObjTakeClass(int Class,int ChangeUP)
{
	switch (Class)
	{
	case 0:
		switch (ChangeUP)
		{
		case 0:
			return 0;
			break;
		case 1:
			return 16;
			break;
		case 2:
			return 24;
			break;
		default:
			return -1;
			break;
		}
		break;
	case 1:
		switch (ChangeUP)
		{
		case 0:
			return 32;
			break;
		case 1:
			return 48;
			break;
		case 2:
			return 56;
			break;
		default:
			return -1;
			break;
		}
		break;
	case 2:
		switch (ChangeUP)
		{
		case 0:
			return 64;
			break;
		case 1:
			return 80;
			break;
		case 2:
			return 88;
			break;
		default:
			return -1;
			break;
		}
		break;
	case 3:
		switch (ChangeUP)
		{
		case 0:
			return 96;
			break;
		case 1:
			return 120;
			break;
		default:
			return -1;
			break;
		}
		break;
	case 4:
		switch (ChangeUP)
		{
		case 1:
			return 128;
			break;
		case 2:
			return 152;
			break;
		default:
			return -1;
			break;
		}
		break;
	default:
		return -1;
	}
}


int gObjTakeDbClass(int Class)
{
	int Preview=0;

	switch(Class)
	{
	case DB_DARK_WIZARD:
		Preview = PR_DARK_WIZARD;
		break;

	case DB_SOUL_MASTER:
		Preview = PR_SOUL_MASTER;
		break;

	case DB_GRAND_MASTER:
		Preview = PR_GRAND_MASTER;
		break;

	case DB_DARK_KNIGHT:
		Preview = PR_DARK_KNIGHT;
		break;

	case DB_BLADE_KNIGHT:
		Preview = PR_BLADE_KNIGHT;
		break;

	case DB_BLADE_MASTER:
		Preview = PR_BLADE_MASTER;
		break;

	case DB_FAIRY_ELF:
		Preview = PR_FAIRY_ELF;
		break;

	case DB_MUSE_ELF:
		Preview = PR_MUSE_ELF;
		break;

	case DB_HIGH_ELF:
		Preview = PR_HIGH_ELF;
		break;

	case DB_MAGIC_GLADIATOR:
		Preview = PR_MAGIC_GLADIATOR;
		break;

	case DB_DUEL_MASTER:
		Preview = PR_DUEL_MASTER;
		break;
		
	case DB_DARK_LORD:
		Preview = PR_DARK_LORD;
		break;

	case DB_LORD_EMPEROR:
		Preview = PR_LORD_EMPEROR;
		break;
	}
	return Preview;
}



void gObjPlayerKiller(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return;
	}

	if ( gObjGetRelationShip(lpObj, lpTargetObj) == 2 )
	{
		if ( lpObj->lpGuild!= NULL && lpTargetObj->lpGuild != NULL )
		{
			LogAdd("[U.System][Rival][Player Kill] ( Killer [%s][%s] / %s / U:%d / R:%d ) vs ( Victim [%s][%s] / %s / U:%d / R:%d )",
				lpObj->AccountID, lpObj->Name, lpObj->lpGuild->Name, lpObj->lpGuild->iGuildUnion, lpObj->lpGuild->iGuildRival,
				lpTargetObj->AccountID, lpTargetObj->Name, lpTargetObj->lpGuild->Name, lpTargetObj->lpGuild->iGuildUnion, lpTargetObj->lpGuild->iGuildRival);
		}
		else
		{
			LogAdd("[U.System][Rival][Player Kill][��ERROR : Can't find GuildInfo] (  [%s][%s] ) vs ( [%s][%s] )",
				lpObj->AccountID,lpObj->Name,lpTargetObj->AccountID,lpTargetObj->Name);
		}
		return;
	}

	if ( CC_MAP_RANGE(lpTargetObj->MapNumber)  )
	{
		if ( g_ChaosCastle.GetCurrentState(lpTargetObj->MapNumber-MAP_INDEX_CHAOSCASTLE1) == 2 )
		{
			return;
		}
	}

 
	if ( lpTargetObj->MapNumber == MAP_INDEX_CASTLESIEGE )
	{
		if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
		{
			if ( lpObj->m_btCsJoinSide )
				return;
		}
		else if ( lpObj->Y > 113 )
		{
			if ( g_CastleSiege.CheckCastleOwnerUnionMember(lpObj->m_Index) == TRUE )
			{
				return;
			}
		}
	
		if ( lpTargetObj->m_PK_Level >= 6 )
		{
			return;
		}
	}


	if((lpObj->Authority & 16) || (lpTargetObj->Authority & 16))
	{
		return;
	}

	for ( int n=0;n<MAX_SELF_DEFENSE;n++)
	{
		if ( lpTargetObj->SelfDefense[n] >= 0 )
		{
			if ( lpTargetObj->SelfDefense[n] == lpObj->m_Index )
			{
				return;
			}
		}
	}

	int iOriginPkLevel = lpObj->m_PK_Level;
	int iOriginPkCount = lpObj->m_PK_Count;

	if(g_PKLevelIncreaseOff == 1)
	{
		return;
	}

	if ( lpObj->m_PK_Level == 3 )
	{
		if(lpTargetObj->m_PK_Level == 3)
		{
			lpObj->m_PK_Count = 1;
		}
		else if(lpTargetObj->m_PK_Level < 3)
		{
			lpObj->m_PK_Count = 1;
		}
		else if(lpTargetObj->m_PK_Level == 4)
		{
			lpObj->m_PK_Count = 1;
		}
		else
		{
			if(lpTargetObj->m_PK_Level >= 6 && lpTargetObj->Level > 20)
			{
				lpObj->m_PK_Count--;

				if(lpObj->m_PK_Count < -3)
				{
					lpObj->m_PK_Count = (BYTE)-3;
					return;
				}
			}
			else
			{
				return;
			}
		}
	}
	else if( lpObj->m_PK_Level > 3)
	{
		if(lpTargetObj->m_PK_Level <= 4)
		{
			lpObj->m_PK_Count++;
			if(lpObj->m_PK_Count > 100)
			{
				lpObj->m_PK_Count = 100;
			}
		}
		else
		{
			return;
		}
	}
	else if( lpObj->m_PK_Level < 3)
	{
		if(lpTargetObj->m_PK_Level == 3)
		{
			lpObj->m_PK_Count = 1;
		}
		else if(lpTargetObj->m_PK_Level < 3)
		{
			lpObj->m_PK_Count = 1;
		}
		else if(lpTargetObj->m_PK_Level == 4)
		{
			lpObj->m_PK_Count = 1;
		}
		else
		{
			if(lpTargetObj->m_PK_Level >= 6 && lpTargetObj->Level > 20)
			{
				lpObj->m_PK_Count--;

				if(lpObj->m_PK_Count < -3)
				{
					lpObj->m_PK_Count = (BYTE)-3;
				}
			}
			else
			{
				return;
			}
		}
	}

	if(lpObj->m_PK_Count == 0)
	{
		lpObj->m_PK_Level = 3;
		lpObj->m_PK_Time = 0;
	}
	else if(lpObj->m_PK_Count == 1)
	{
		lpObj->m_PK_Level = 4;
		lpObj->m_PK_Time = 0;
	}
	else if(lpObj->m_PK_Count == 2)
	{
		lpObj->m_PK_Level = 5;
		lpObj->m_PK_Time = 0;
	}
	else if(lpObj->m_PK_Count >= 3)
	{
		lpObj->m_PK_Level = 6;
		lpObj->m_PK_Time = 0;
	}
	else if(lpObj->m_PK_Count <= -3)
	{
		lpObj->m_PK_Level = 1;
		lpObj->m_PK_Time = 0;
	}
	
	GCPkLevelSend(lpObj->m_Index, lpObj->m_PK_Level);

	if ( lpObj->m_PK_Level == 4 )
	{
		GCServerMsgStringSend("[Warning!] You will become an Outlaw if you kill anyone else again within 3 hours", lpObj->m_Index, 1);
	}

	LogAdd("[%s][%s] PK Info Set (Killed Player) Origin(PkLevel:%d, PkCount:%d) Changed(PkLevel:%d, PkCount:%d)",
		lpObj->AccountID, lpObj->Name, iOriginPkLevel, iOriginPkCount, lpObj->m_PK_Level, lpObj->m_PK_Count);
	

}






void gObjUserDie(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	int count = 76;
	int itemdrop = 1;
	int number = 0;
	int dropresult = 0;

	if(lpObj->Type != OBJ_USER)
	{
		return;
	}

	gObjSetKillCount(lpObj->m_Index,0);

	gObjUseSkill.RemoveAllCharacterInvalidMagicAndSkillState(lpObj);

	lpObj->m_iPotionBlessTime = 0;
	lpObj->m_iPotionSoulTime = 0;

	lpObj->m_ViewSkillState &= ~0x8000;
	lpObj->m_ViewSkillState &= 0xFFFEFFFF;

	if(gObjTargetGuildWarCheck(lpObj,lpTargetObj) == 1)
	{
		return;
	}

	if(DS_MAP_RANGE(lpObj->MapNumber))
	{
		if(lpTargetObj->Type == OBJ_MONSTER)
		{

			LPMONSTER_ATTRIBUTE mAttr = gMAttr.GetAttr(lpTargetObj->Class);

			if(mAttr != 0)
			{
				LogAdd("[DevilSquare] Dead In DevilSquare [%s][%s][%s]",lpObj->AccountID,lpObj->Name,mAttr->m_Name);
			}
		}

		return;
	}
	
	if(BC_MAP_RANGE(lpObj->MapNumber))
	{
		g_BloodCastle.SetUserState(lpObj->m_Index,1);
		if(g_BloodCastle.GetCurrentState(lpObj->MapNumber-MAP_INDEX_BLOODCASTLE1) == BC_STATE_PLAYING)
		{
			LogAdd("[Blood Castle] (%d) Try to drop Ultimate Weapon [%s][%s]",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1-1),lpObj->AccountID,lpObj->Name);
			g_BloodCastle.SearchUserDropQuestItem(lpObj->m_Index);
		}
		else
		{
			LogAdd("[Blood Castle] (%d) Try to delete Ultimate Weapon [%s][%s]",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1-1),lpObj->AccountID,lpObj->Name);
			g_BloodCastle.SearchUserDeleteQuestItem(lpObj->m_Index);
		}

		if(lpTargetObj->Type == OBJ_MONSTER)
		{
			LPMONSTER_ATTRIBUTE mAttr = gMAttr.GetAttr(lpTargetObj->Class);

			if(mAttr != 0)
			{
				LogAdd("[Blood Castle] (%d) Dead In Blood Castle, Killed by Monster [%s][%s][%s]",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1-1),lpObj->AccountID,lpObj->Name,mAttr->m_Name);
				g_BloodCastle.SearchUserDropQuestItem(lpObj->m_Index);
			}
		}
		else if(lpTargetObj->Type == OBJ_USER)
		{
			LogAdd("[Blood Castle] (%d) Dead In Blood Castle, Killed by Other User [%s][%s][%s]",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1-1),lpObj->AccountID,lpObj->Name,lpTargetObj->Name);
			g_BloodCastle.SearchUserDropQuestItem(lpObj->m_Index);
		}
		return;
	}
	else if(CC_MAP_RANGE(lpObj->MapNumber))
	{
		return;
	}

 
	if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE &&
		 lpObj->MapNumber == MAP_INDEX_CASTLESIEGE )
	{
		return;
	}


	if((lpObj->Authority & 0x10) || (lpTargetObj->Authority & 0x10))
	{
		return;
	}

	if(lpTargetObj->Type == OBJ_MONSTER)
	{
		LogAdd("[%s][%s] Killed [%s][%s] Pos:(%d,%d,%d)","Monster",lpTargetObj->Name,lpObj->AccountID,lpObj->Name,lpObj->MapNumber,lpObj->X,lpObj->Y);
	}
	else
	{
		LogAdd("[%s][%s] (PkLevel = %d) Killed [%s][%s] (PkLevel = %d) Pos:(%d,%d,%d)",lpTargetObj->AccountID,lpTargetObj->Name,lpTargetObj->m_PK_Level,lpObj->AccountID,lpObj->Name,lpObj->m_PK_Level,lpObj->MapNumber,lpObj->X,lpObj->Y);
		LogAdd("Killed by User State Victim:[%s][%s], Murderer:[%s][%s], Dead State (Duel:%d, GuildWar:%d, SeldDefense:%d)",lpObj->AccountID,lpObj->Name,lpTargetObj->AccountID,lpTargetObj->Name,!!IsOnDuel(lpTargetObj->m_Index,lpObj->m_Index),!!gObjTargetGuildWarCheck(lpObj,lpTargetObj),!!gObjIsSelfDefense(lpTargetObj,lpObj->m_Index));
	}

	if(gPkLimitFree == 0)
	{
		if(lpObj->m_PK_Level == 2)
		{
			itemdrop = Random(0,32);
		}
		else if(lpObj->m_PK_Level == 3)
		{
			itemdrop = Random(0,16);
		}
		else if(lpObj->m_PK_Level == 4)
		{
			itemdrop = Random(0,8);
		}
		else if(lpObj->m_PK_Level == 5)
		{
			itemdrop = Random(0,4);
		}
		else if(lpObj->m_PK_Level >= 6)
		{
			itemdrop = Random(0,2);
		}
		else
		{
			itemdrop = Random(0,64);
		}
	}
	else
	{
		if(lpObj->m_PK_Level == 2)
		{
			itemdrop = Random(0,128);
		}
		else if(lpObj->m_PK_Level == 3)
		{
			itemdrop = Random(0,64);
		}
		else if(lpObj->m_PK_Level == 4)
		{
			itemdrop = Random(0,16);
		}
		else if(lpObj->m_PK_Level == 5)
		{
			itemdrop = Random(0,4);
		}
		else if(lpObj->m_PK_Level >= 6)
		{
			itemdrop = Random(0,2);
		}
		else
		{
			itemdrop = Random(0,256);
		}
	}

	if(gPkItemDrop == 0)
	{
		if(lpTargetObj->m_PK_Level >= 4 && gPkLimitFree == 0)
		{
			itemdrop = 1;
		}
	}

	if(gLanguage == 0)
	{
		if(lpTargetObj->Type == OBJ_USER && gPkLimitFree == 0)
		{
			itemdrop = 1;
		}
	}

	if(gObjCanItemTouch(lpObj,0)==0)
	{
		itemdrop = 1;
	}

	if(lpObj->Type == OBJ_USER && lpTargetObj->Type == OBJ_USER)
	{
		if(IsOnDuel(lpObj->m_Index,lpTargetObj->m_Index))
		{
			itemdrop = 1;
		}
		//lpObj - ���� ����� , lpTargetObj
		//KillerName - ��� ������ ��� ���� ��������� lpObj; ��� ������ lpObj , ������������ lpTargetObj ��� ��� ������
		//KillingName - ���� lpTargetObj ���� ; ��� ������ lpObj, ������������ lpObj �������� lpTargetObj ����
// 		std::string TableName,TableTime;
// 
// 		TableName=SQL.GetFieldChar("MuOnline.dbo.Character","KillerName","WHERE Name = '%s'",lpObj->Name);
// 		TableTime=SQL.GetFieldChar("MuOnline.dbo.Character","KillerTime","WHERE Name = '%s'",lpObj->Name);
// 
// 		Refresh(TableName,TableTime,lpTargetObj->Name);
// 
// 		char sql[250]={0};
// 		wsprintf(sql,"UPDATE MuOnline.dbo.Character SET KillerName=('%s') WHERE Name=('%s')",TableName.c_str(),lpObj->Name);
// 		SQL.Execute(sql);
// 		wsprintf(sql,"UPDATE MuOnline.dbo.Character SET KillerTime=('%s') WHERE Name=('%s');",TableTime.c_str(),lpObj->Name);
// 		SQL.Execute(sql);
// 
// 		TableName=SQL.GetFieldChar("MuOnline.dbo.Character","KillingName","WHERE Name = '%s'",lpTargetObj->Name);
// 		TableTime=SQL.GetFieldChar("MuOnline.dbo.Character","KillingTime","WHERE Name = '%s'",lpTargetObj->Name);
// 
// 		Refresh(TableName,TableTime,lpObj->Name);
// 
// 		wsprintf(sql,"UPDATE MuOnline.dbo.Character SET KillingName=('%s') WHERE Name=('%s')",TableName.c_str(),lpTargetObj->Name);
// 		SQL.Execute(sql);
// 		wsprintf(sql,"UPDATE MuOnline.dbo.Character SET KillingTime=('%s') WHERE Name=('%s')",TableTime.c_str(),lpTargetObj->Name);
// 		SQL.Execute(sql);

	}

 
	if ( g_Crywolf.GetCrywolfState() == 4 )
	{
		if ( CHECK_CLASS(lpObj->MapNumber, MAP_INDEX_CRYWOLF_FIRSTZONE) )
		{
			itemdrop = 1;
		}
	}


	if(itemdrop == 0)
	{
		if(lpObj->m_PK_Level >= 4)
		{
			count = 24;
			for (int i=count ; i>=0; i--)
			{
				number = Random(0,11);

				if(lpObj->pInventory[number].IsItem()==1)
				{
					if(g_kJewelOfHarmonySystem.IsStrengthenByJewelOfHarmony(&lpObj->pInventory[number])==0)
					{
						PMSG_ITEMTHROW lpMsg;
						lpMsg.Ipos = number;
						lpMsg.px = (BYTE)lpObj->X;
						lpMsg.py = (BYTE)lpObj->Y;
						if(CGItemDropRequest(&lpMsg,lpObj->m_Index,1)==1)
						{
							dropresult = 1;
							break;
						}
					}
				}
			}
		}

		if(dropresult == 0)
		{
			count = INVENTORY_MAP_SIZE;

			for (int i=count ; i>=0; i--)
			{
				number = Random(0,INVENTORY_MAP_SIZE-1) + 12;

				if(lpObj->pInventory[number].IsItem()==1)
				{
					if(g_kJewelOfHarmonySystem.IsStrengthenByJewelOfHarmony(&lpObj->pInventory[number])==0)
					{
						if(lpObj->pInventory[number].m_Type >= ITEMGET(13,20) && (lpObj->pInventory[number].m_Level >= 1 && lpObj->pInventory[number].m_Level <= 2 ))
						{
							continue;
						}

						PMSG_ITEMTHROW lpMsg;
						lpMsg.Ipos = number;
						lpMsg.px = (BYTE)lpObj->X;
						lpMsg.py = (BYTE)lpObj->Y;

						if(CGItemDropRequest(&lpMsg,lpObj->m_Index,1)==1)
						{
							dropresult = 1;
							LogAdd("[%s][%s] User Die Item Drop, ItemName:%s",lpObj->AccountID,lpObj->Name,lpObj->pInventory[number].GetName());
							break;
						}
					}
				}
			}
		}
	}

	if(lpObj->Type == OBJ_USER && lpTargetObj->Type == OBJ_USER ) 
	{
		if ( IsOnDuel(lpObj->m_Index,lpTargetObj->m_Index) )
		{
			lpTargetObj->m_btDuelScore += 1;
			GCSendDuelScore(lpObj->m_Index,lpTargetObj->m_Index);
		}
		return;
	}

	DWORD minexp = gLevelExperience[-1 + lpObj->Level];
	DWORD maxexp = gLevelExperience[lpObj->Level];
	DWORD subexp = 0;
	DWORD decexp = 0;
	DWORD decexprate = 0;

	if(lpObj->Level <= 10)
	{
		decexprate = 0;
	}
	else if(lpObj->Level <= 150)
	{
		if(lpObj->m_PK_Level == 2)
		{
			decexprate = 2;
		}
		else if(lpObj->m_PK_Level == 3)
		{
			decexprate = 3;
		}
		else if(lpObj->m_PK_Level == 4)
		{
			decexprate = 5;
		}
		else if(lpObj->m_PK_Level == 5)
		{
			decexprate = 6;
		}
		else if(lpObj->m_PK_Level >= 6)
		{
			decexprate = 7;
		}
		else
		{
			decexprate = 2;
		}
	}
	else if(lpObj->Level <= 220)
	{
		if(lpObj->m_PK_Level == 2)
		{
			decexprate = 1;
		}
		else if(lpObj->m_PK_Level == 3)
		{
			decexprate = 2;
		}
		else if(lpObj->m_PK_Level == 4)
		{
			decexprate = 4;
		}
		else if(lpObj->m_PK_Level == 5)
		{
			decexprate = 5;
		}
		else if(lpObj->m_PK_Level >= 6)
		{
			decexprate = 6;
		}
		else
		{
			decexprate = 1;
		}
	}
	else
	{
		if(lpObj->m_PK_Level == 2)
		{
			decexprate = 1;
		}
		else if(lpObj->m_PK_Level == 3)
		{
			decexprate = 1;
		}
		else if(lpObj->m_PK_Level == 4)
		{
			decexprate = 3;
		}
		else if(lpObj->m_PK_Level == 5)
		{
			decexprate = 4;
		}
		else if(lpObj->m_PK_Level >= 6)
		{
			decexprate = 5;
		}
		else
		{
			decexprate = 1;
		}
	}

	decexp = (maxexp - minexp)*decexprate/100;

 
	if ( g_Crywolf.GetCrywolfState() == 4 )
	{
		if ( lpObj->MapNumber == MAP_INDEX_CRYWOLF_FIRSTZONE )
		{
			decexp = 0;
		}
	}


	subexp = lpObj->Experience - decexp;

	if(subexp < minexp)
	{
		subexp = minexp;
	}

	LogAdd("[%s][%s] Death reduces Experience %u - %d",lpObj->AccountID,lpObj->Name,subexp,decexp);

	DWORD submoney = 0;

	if(lpObj->Money > 0)
	{
		if(lpObj->Level > 10 && lpObj->Level <= 99)
		{
			submoney = (DWORD)(lpObj->Money)/100;
		}
		else if(lpObj->Level >= 100 && lpObj->Level <= 199)
		{
			submoney = (DWORD)(lpObj->Money*2)/100;
		}
		else if(lpObj->Level > 200)
		{
			submoney = (DWORD)(lpObj->Money*3)/100;
		}

		lpObj->Money = lpObj->Money - submoney;
		
		if(lpObj->Money < 0)
		{
			lpObj->Money = 0;
		}

		LogAdd("[%s][%s] Death reduces money %d - %d",lpObj->AccountID,lpObj->Name,lpObj->Money,submoney);
	}

	if(lpObj->WarehouseMoney > 0)
	{
		if(lpObj->Level > 10 && lpObj->Level <= 99)
		{
			submoney = (DWORD)(lpObj->WarehouseMoney)/100;
		}
		else if(lpObj->Level >= 100 && lpObj->Level <= 199)
		{
			submoney = (DWORD)(lpObj->WarehouseMoney*2)/100;
		}
		else if(lpObj->Level > 200)
		{
			submoney = (DWORD)(lpObj->WarehouseMoney*3)/100;
		}

		lpObj->WarehouseMoney = lpObj->WarehouseMoney - submoney;
		
		if(lpObj->WarehouseMoney < 0)
		{
			lpObj->WarehouseMoney = 0;
		}

		GDSetWarehouseMoney(lpObj->m_Index);

		LogAdd("[%s][%s] Death reduces money in Warehouse %d - %d",lpObj->AccountID,lpObj->Name,lpObj->WarehouseMoney,submoney);
	}

	lpObj->Experience = subexp;

	
}






void gObjInterfaceTimeCheck(LPOBJ lpObj)
{
	int tObjNum;
	BOOL TimeCheck = FALSE;

	if ( lpObj->m_IfState.use == 0 )
	{
		return;
	}

	if ( (GetTickCount() - lpObj->m_InterfaceTime) < 5000 )
	{
		return;
	}

	if ( lpObj->m_IfState.state == 1 )
	{
		return;
	}

	tObjNum = lpObj->TargetNumber;

	if ( tObjNum < 0 )
	{
		return;
	}

	if ( lpObj->m_IfState.type == 1 )
	{
		CGTradeResult(lpObj->m_Index, 3);
		CGTradeResult(tObjNum, 3);

		GCServerMsgStringSend("The trade has been canceled.", tObjNum, 1);
		TimeCheck = TRUE;
	}
	else
	{
		if ( lpObj->m_IfState.type == 2 )
		{
			lpObj->PartyTargetUser = -1;
			gObj[tObjNum].PartyTargetUser = -1;
			GCResultSend(tObjNum, 0x41, FALSE );
			TimeCheck = TRUE;
		}
	}

	if ( TimeCheck != FALSE )
	{
		lpObj->m_IfState.use = 0;
		lpObj->TargetNumber = -1;
		gObj[tObjNum].m_IfState.use = 0;
		gObj[tObjNum].TargetNumber = -1;
	}

}






void gObjPkDownTimeCheck(LPOBJ lpObj, int TargetLevel)
{

	if(lpObj->m_PK_Level == 3)
	{
		return;
	}

	unsigned int dwtime = ((GetTickCount() - lpObj->m_dwPKTimer) / 1000) * gPkTime;

	if(dwtime > 5)
	{
		dwtime = 2;
		lpObj->m_dwPKTimer = GetTickCount();
	}
	else
	{
		lpObj->m_dwPKTimer = dwtime * 1000;
	}

	if(TargetLevel < 2)
	{
		lpObj->m_PK_Time += dwtime;
	}
	else
	{
		lpObj->m_PK_Time += TargetLevel;
	}

	if(lpObj->m_PK_Level < 3)
	{
		if(lpObj->m_PK_Time > 3600)
		{
			lpObj->m_PK_Time = 0;
			lpObj->m_PK_Count += 1;

			if(lpObj->m_PK_Count > 100)
			{
				lpObj->m_PK_Count = 100;
			}

			lpObj->m_PK_Level += 1;

			GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);
		}
	}
	else if(lpObj->m_PK_Level > 3)
	{
		if(lpObj->m_PK_Count > 3)
		{
			if(lpObj->m_PK_Time > 3600)
			{
				lpObj->m_PK_Time = 0;
				lpObj->m_PK_Count -= 1;

				if(lpObj->m_PK_Count <= 0)
				{
					lpObj->m_PK_Count = 0;
					lpObj->m_PK_Level = 3;
				}
				else if(lpObj->m_PK_Count == 2)
				{
					lpObj->m_PK_Level = 5;
				}
				else if(lpObj->m_PK_Count == 1)
				{
					lpObj->m_PK_Level = 4;
				}

				if(lpObj->m_PK_Level <= 5)
				{
					GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);
				}

				if(lpObj->m_PK_Level == 4)
				{
					GCServerMsgStringSend("[Warning!] You will become an Outlaw if you kill anyone else again within 3 hours",lpObj->m_Index,1);
				}
			}
		}
		else if(lpObj->m_PK_Time > 10800)
		{
			lpObj->m_PK_Time = 0;
			lpObj->m_PK_Count -= 1;

			if(lpObj->m_PK_Count <= 0)
			{
				lpObj->m_PK_Count = 0;
				lpObj->m_PK_Level = 3;
			}
			else if(lpObj->m_PK_Count == 2)
			{
				lpObj->m_PK_Level = 5;
			}
			else if(lpObj->m_PK_Count == 1)
			{
				lpObj->m_PK_Level = 4;
			}

			if(lpObj->m_PK_Level <= 5)
			{
				GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);
			}

			if(lpObj->m_PK_Level == 4)
			{
				GCServerMsgStringSend("[Warning!] You will become an Outlaw if you kill anyone else again within 3 hours",lpObj->m_Index,1);
			}
		}
	}
}






BOOL gObjAngelSprite(LPOBJ lpObj)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return FALSE;
	}

	if ( lpObj->pInventory[8].IsItem() == FALSE )
	{
		return FALSE;
	}

	CItem * Angel = &lpObj->pInventory[8];

	if ( Angel->m_Type == ITEMGET(13,0) && Angel->m_Durability > 0.0f )
	{
		return TRUE;
	}

	return FALSE;
}






BOOL gObjSatanSprite(LPOBJ lpObj)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return FALSE;
	}

	if ( lpObj->pInventory[8].IsItem() == FALSE )
	{
		return FALSE;
	}

	CItem * Satan = &lpObj->pInventory[8];

	if ( Satan->m_Type == ITEMGET(13,1) && Satan->m_Durability > 0.0f )
	{
		return TRUE;
	}

	return FALSE;
}






BOOL gObjWingSprite(LPOBJ lpObj)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return FALSE;
	}

	if ( lpObj->pInventory[7].IsItem() == FALSE )
	{
		return FALSE;
	}

	CItem * Wing = &lpObj->pInventory[7];

	if ( (Wing->m_Type >= ITEMGET(12,0) && Wing->m_Type <= ITEMGET(12,6)) || (Wing->m_Type >= ITEMGET(12,36) && Wing->m_Type <= ITEMGET(12,40)) || Wing->m_Type == ITEMGET(13,30))  // Apply DEathway Fix HEre, last Must be == not <=
	{
		if ( Wing->m_Durability > 0.0f )
		{
			return TRUE;
		}
	}
	
	return FALSE;
}






BOOL gObjUniriaSprite(LPOBJ lpObj)
{
	if ( lpObj->pInventory[8].IsItem() == FALSE )
	{
		return FALSE;
	}

	CItem * Uniria = &lpObj->pInventory[8];

	if ( Uniria->m_Type == ITEMGET(13,2) && Uniria->m_Durability > 0.0f )
	{
		return TRUE;
	}

	return FALSE;
}



typedef struct tagITEM_BYTE_DB
{
	BYTE btType;
	BYTE btOption;
	BYTE btDurability;
	BYTE btExcellentOption;
	BYTE btAncientOption;

} ITEM_BYTE_DB, * LPITEM_BYTE_DB;


void gObjSpriteDamage(LPOBJ lpObj, int damage)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return;
	}

	int send_dur = 0;

	if ( lpObj->pInventory[8].IsItem() == FALSE )
	{
		return;
	}

	double fN = 10.0f;
	CItem * sprite = &lpObj->pInventory[8];
	double fdamage = damage;

	if ( sprite->m_Type == ITEMGET(13,0) ) // angel
	{
		fdamage = (damage*3)/10.0f;
		fdamage /= fN;
		sprite->m_Durability -= fdamage;
		send_dur = 1;
	}
	else if ( sprite->m_Type == ITEMGET(13,1) )
	{
		fdamage = (damage*2)/10.0f;
		fdamage /= fN;
		sprite->m_Durability -= fdamage;
		send_dur = 1;
	}
	else if ( sprite->m_Type == ITEMGET(13,2) )
	{
		fdamage = (damage)/10.0f;
		fdamage /= 10.0f;
		sprite->m_Durability -= fdamage;
		send_dur = 1;
	}
	else if ( sprite->m_Type == ITEMGET(13,3) )
	{
		fdamage = (damage)/20.0f;
		fdamage /= 10.0f;
		sprite->m_Durability -= fdamage;
		send_dur = 1;
	}		
	else if ( sprite->m_Type == ITEMGET(13,4) )
	{
		if ( sprite->m_Durability < 1.0f )
		{
			return;
		}

		fdamage = (damage*2)/10.0f;
		fdamage /= 10.0f;
		fdamage += 1.0f;
		sprite->m_DurabilitySmall += (int)fdamage;

		if ( sprite->m_DurabilitySmall > 1500 )
		{
			sprite->m_Durability -= 1.0f;
			sprite->m_DurabilitySmall = 0;
			send_dur = 1;

			if ( sprite->m_Durability < 1.0f )
			{
				sprite->m_Durability = 0;

				int iPetExperience = lpObj->pInventory[1].m_PetItem_Exp;

				if ( sprite->DecPetItemExp(10) != FALSE )
				{
					LogAdd("[%s][%s][PetItemExpDown] [%s] Level:[%d]Exp:[%d]DecExp[%d]",
						lpObj->AccountID, lpObj->Name, lpObj->pInventory[8].GetName(),
						lpObj->pInventory[8].m_PetItem_Level, lpObj->pInventory[8].m_PetItem_Exp,
						iPetExperience - lpObj->pInventory[1].m_PetItem_Exp);
					CDarkSpirit::SendLevelmsg(lpObj->m_Index, 8, 1, (BYTE)-1);
				}

				LogAdd("[%s][%s] ��ũȣ���ǻ� Item is Broken because durability is exhausted [%d]",
						lpObj->AccountID,lpObj->Name,lpObj->pInventory[8].m_Number);
			}

			GCItemDurSend(lpObj->m_Index, 8, (BYTE)sprite->m_Durability, 0);
		}
	
		return;
	}
	else if(sprite->m_Type == ITEMGET(13,37))
	{
		if ( sprite->m_Durability < 1.0f )
		{
			return;
		}

		int iMaxDurSmall = g_iFenrirDefaultMaxDurSmall;
		int iMultipleDmg = 2;

		if(lpObj->Class == CLASS_WIZARD)
		{

		}
		else if(lpObj->Class == CLASS_KNIGHT)
		{

		}
		else if(lpObj->Class == CLASS_ELF)
		{
			iMaxDurSmall = g_iFenrirElfMaxDurSmall;
			iMultipleDmg = 2;
		}

		fdamage = damage * iMultipleDmg / 10.0f;
		fdamage /= 10.0f;
		fdamage += 1.0f;

		sprite->m_DurabilitySmall += (int)fdamage;

		if(sprite->m_DurabilitySmall > iMaxDurSmall)
		{
			sprite->m_Durability -= 1.0f;
			sprite->m_DurabilitySmall = 0;

			if(sprite->m_Durability < 1.0f)
			{
				sprite->m_Durability = 0;
			}

			send_dur = 1;
		}
	}

	if ( send_dur != FALSE )
	{
		GCItemDurSend(lpObj->m_Index, 8, (BYTE)sprite->m_Durability, 0);

		if ( sprite->m_Durability < 1.0f )
		{
			int itemnum = sprite->m_Type;

			LogAdd("[%s][%s] %s+%d Item is broken because durability is exhausted", lpObj->AccountID, lpObj->Name,
				lpObj->pInventory[8].GetName(), lpObj->pInventory[8].m_Level);
			gObjInventoryDeleteItem(lpObj->m_Index, 8);
			GCInventoryItemDeleteSend(lpObj->m_Index, 8, 0);
			gObjMakePreviewCharSet(lpObj->m_Index);
			GCEquipmentChange(lpObj->m_Index, 8);

			if ( BC_MAP_RANGE(lpObj->MapNumber) || CC_MAP_RANGE(lpObj->MapNumber) )
			{
				if ( itemnum == ITEMGET(13,0) || itemnum == ITEMGET(13,1))
				{
					int pos = -1;

					for ( int i=MAX_PLAYER_EQUIPMENT;i<MAIN_INVENTORY_SIZE;i++)
					{
						if ( lpObj->pInventory[i].IsItem() == TRUE )
						{
							if ( lpObj->pInventory[i].m_Type == itemnum )
							{
								pos = i;
								break;
							}
						}
					}

					if ( pos != -1 )
					{
						BYTE ItemInfo[MAX_ITEM_INFO];
						BOOL DurSend;
						BOOL DurTargetSend;

						ItemByteConvert(ItemInfo, lpObj->pInventory[pos]);
						gObjInventoryMoveItem(lpObj->m_Index, pos, 8, DurSend, DurTargetSend, 0, 0, ItemInfo);
						GCItemMoveResultSend(lpObj->m_Index, 0, 8, ItemInfo);
						GCInventoryItemDeleteSend(lpObj->m_Index, pos, 0);
						GCServerMsgStringSend("The equipment has been changed.", lpObj->m_Index, 1);
					}
				}
			}
				
			if ( lpObj->MapNumber == MAP_INDEX_ICARUS && itemnum == ITEMGET(13,3) || lpObj->MapNumber == MAP_INDEX_ICARUS && itemnum == ITEMGET(13,37))
			{
				int pos = -1;

				for ( int i=MAX_PLAYER_EQUIPMENT;i<MAIN_INVENTORY_SIZE;i++)
				{
					if ( lpObj->pInventory[i].IsItem() == TRUE )
					{
						if ( lpObj->pInventory[i].m_Type == ITEMGET(13,3) )
						{
							pos = i;
							break;
						}
					}
				}

				if ( pos == -1 )
				{
					if ( lpObj->pInventory[7].IsItem() == FALSE )
					{
						gObjMoveGate(lpObj->m_Index, 22);
					}
				}
				else
				{
					BYTE ItemInfo[MAX_ITEM_INFO];
					BOOL DurSend;
					BOOL DurTargetSend;

					ItemByteConvert(ItemInfo, lpObj->pInventory[pos]);
					gObjInventoryMoveItem(lpObj->m_Index, pos, 8, DurSend, DurTargetSend, 0, 0, ItemInfo);
					GCItemMoveResultSend(lpObj->m_Index, 0, 8, ItemInfo);
					GCInventoryItemDeleteSend(lpObj->m_Index, pos, 0);
					GCServerMsgStringSend("The equipment has been changed.", lpObj->m_Index, 1);
				}
			}
		}

	}
}






void gObjSecondDurDown(LPOBJ lpObj)
{
	lpObj->m_TimeCount +=1;


	int ret = 0;
	int reCalCharacter = 0;

	if(lpObj->m_Change >= 0)
	{
		gObjChangeDurProc(lpObj);
	}

	BYTE attr = MapC[lpObj->MapNumber].GetAttr(lpObj->X,lpObj->Y);

	if(lpObj->m_TimeCount % 10 != 0)
	{
		return;
	}

	if(lpObj->pInventory[7].IsItem() == 1 )
	{
		ret = lpObj->pInventory[7].DurabilityDown(1,lpObj->m_Index);

		if(ret != 0)
		{
			GCItemDurSend2(lpObj->m_Index,7,(BYTE)lpObj->pInventory[7].m_Durability,0);
		}

		if(ret == 2)
		{
			reCalCharacter = 1;
		}
	}

	if((attr&1)==0)
	{
		if(lpObj->pInventory[10].IsItem() == 1)
		{
			if(lpObj->pInventory[10].m_Type == ITEMGET(13,20) && lpObj->pInventory[10].m_Level == 0)
			{
				ret = lpObj->pInventory[10].DurabilityDown(70,lpObj->m_Index);
				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,10,(BYTE)lpObj->pInventory[10].m_Durability,0);
				}

				if(ret == 2)
				{
					reCalCharacter = 1;
				}
			}
			else if(lpObj->pInventory[10].m_Type == ITEMGET(13,38))
			{
				ret = lpObj->pInventory[10].DurabilityDown(63,lpObj->m_Index);
				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,10,(BYTE)lpObj->pInventory[10].m_Durability,0);
				}
			}
			else if(lpObj->pInventory[10].m_Type != ITEMGET(13,10))
			{
				ret = lpObj->pInventory[10].DurabilityDown(1,lpObj->m_Index);
				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,10,(BYTE)lpObj->pInventory[10].m_Durability,0);
				}

				if(ret == 2)
				{
					reCalCharacter = 1;
				}
			}
		}

		if(lpObj->pInventory[11].IsItem() == 1)
		{
			if(lpObj->pInventory[11].m_Type == ITEMGET(13,20) && lpObj->pInventory[11].m_Level == 0)
			{
				ret = lpObj->pInventory[11].DurabilityDown(70,lpObj->m_Index);
				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,11,(BYTE)lpObj->pInventory[11].m_Durability,0);
				}

				if(ret == 2)
				{
					reCalCharacter = 1;
				}
			}
			else if(lpObj->pInventory[11].m_Type == ITEMGET(13,38))
			{
				ret = lpObj->pInventory[11].DurabilityDown(63,lpObj->m_Index);
				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,11,(BYTE)lpObj->pInventory[11].m_Durability,0);
				}
			}
			else if(lpObj->pInventory[11].m_Type != ITEMGET(13,10))
			{
				ret = lpObj->pInventory[11].DurabilityDown(1,lpObj->m_Index);
				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,11,(BYTE)lpObj->pInventory[11].m_Durability,0);
				}

				if(ret == 2)
				{
					reCalCharacter = 1;
				}
			}
		}

		if(lpObj->pInventory[9].IsItem() == 1)
		{
			if(lpObj->pInventory[9].m_Type != ITEMGET(13,10))
			{
				ret = lpObj->pInventory[9].DurabilityDown(1,lpObj->m_Index);

				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,9,(BYTE)lpObj->pInventory[9].m_Durability,0);
				}

				if(ret == 2)
				{
					reCalCharacter = 1;
				}
			}
		}
	}

	if(reCalCharacter != 0)
	{
		gObjCalCharacter(lpObj->m_Index);
	}
}






void gObjChangeDurProc(LPOBJ lpObj)
{

	if(lpObj->pInventory[10].IsItem() == 1 && lpObj->pInventory[10].m_Type == ITEMGET(13,10))
	{
		int m_Durability = (int)lpObj->pInventory[10].m_Durability;

		lpObj->pInventory[10].m_Durability -= (double)0.02;

		if(m_Durability > (int)lpObj->pInventory[10].m_Durability)
		{
			if(lpObj->pInventory[10].m_Durability < 1)
			{
				lpObj->pInventory[10].m_Durability = 0;
			}

			BYTE dur = (BYTE)lpObj->pInventory[10].m_Durability;

			GCItemDurSend(lpObj->m_Index,10,dur,0);

			if(dur == 0)
			{
				gObjUseSkill.SkillChangeUse(lpObj->m_Index);
				LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[10].m_Level,dur);
				lpObj->pInventory[10].Clear();
				GCInventoryItemDeleteSend(lpObj->m_Index,10,0);
			}
		}
	}
	else if(lpObj->pInventory[11].IsItem() == 1 && lpObj->pInventory[11].m_Type == ITEMGET(13,10))
	{
		int m_Durability = (int)lpObj->pInventory[11].m_Durability;

		lpObj->pInventory[11].m_Durability -= (double)0.02;

		if(m_Durability > (int)lpObj->pInventory[11].m_Durability)
		{
			if(lpObj->pInventory[11].m_Durability < 1)
			{
				lpObj->pInventory[11].m_Durability = 0;
			}

			BYTE dur = (BYTE)lpObj->pInventory[11].m_Durability;

			GCItemDurSend(lpObj->m_Index,11,dur,0);

			if(dur == 0)
			{
				gObjUseSkill.SkillChangeUse(lpObj->m_Index);
				LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[11].m_Level,dur);
				lpObj->pInventory[11].Clear();
				GCInventoryItemDeleteSend(lpObj->m_Index,11,0);
			}
		}
	}
	else if(lpObj->pInventory[10].IsItem() == 1 && lpObj->pInventory[10].m_Type == ITEMGET(13,39))
	{
		int m_Durability = (int)lpObj->pInventory[10].m_Durability;

		lpObj->pInventory[10].m_Durability -= (double)0.02;

		if(m_Durability > (int)lpObj->pInventory[10].m_Durability)
		{
			if(lpObj->pInventory[10].m_Durability < 1)
			{
				lpObj->pInventory[10].m_Durability = 0;
			}

			BYTE dur = (BYTE)lpObj->pInventory[10].m_Durability;

			GCItemDurSend(lpObj->m_Index,10,dur,0);

			if(dur == 0)
			{
				gObjUseSkill.SkillChangeUse(lpObj->m_Index);
				LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[10].m_Level,dur);
				lpObj->pInventory[10].Clear();
				GCInventoryItemDeleteSend(lpObj->m_Index,10,0);
			}
		}
	}
	else if(lpObj->pInventory[11].IsItem() == 1 && lpObj->pInventory[11].m_Type == ITEMGET(13,39))
	{
		int m_Durability = (int)lpObj->pInventory[11].m_Durability;

		lpObj->pInventory[11].m_Durability -= (double)0.02;

                if(m_Durability > (int)lpObj->pInventory[11].m_Durability)
                {
                        if(lpObj->pInventory[11].m_Durability < 1)
                        {
                                lpObj->pInventory[11].m_Durability = 0;
                        }

                        BYTE dur = (BYTE)lpObj->pInventory[11].m_Durability;

                        GCItemDurSend(lpObj->m_Index,11,dur,0);

                        if(dur == 0)
                        {
                                gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                                LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[11].m_Level,dur);
                                lpObj->pInventory[11].Clear();
                                GCInventoryItemDeleteSend(lpObj->m_Index,11,0);
                        }
                }
        }
        else if(lpObj->pInventory[10].IsItem() == 1 && lpObj->pInventory[10].m_Type == ITEMGET(13,40))
        {
                int m_Durability = (int)lpObj->pInventory[10].m_Durability;

                lpObj->pInventory[10].m_Durability -= (float)0.02;

                if(m_Durability > (int)lpObj->pInventory[10].m_Durability)
                {
                        if(lpObj->pInventory[10].m_Durability < 1)
                        {
                                lpObj->pInventory[10].m_Durability = 0;
                        }

                        BYTE dur = (BYTE)lpObj->pInventory[10].m_Durability;

                        GCItemDurSend(lpObj->m_Index,10,dur,0);

                        if(dur == 0)
                        {
                                gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                                LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[10].m_Level,dur);
                                lpObj->pInventory[10].Clear();
                                GCInventoryItemDeleteSend(lpObj->m_Index,10,0);
                        }
                }
        }
        else if(lpObj->pInventory[11].IsItem() == 1 && lpObj->pInventory[11].m_Type == ITEMGET(13,40))
        {
                int m_Durability = (int)lpObj->pInventory[11].m_Durability;

                lpObj->pInventory[11].m_Durability -= (float)0.02;

                if(m_Durability > (int)lpObj->pInventory[11].m_Durability)
                {
                        if(lpObj->pInventory[11].m_Durability < 1)
                        {
                                lpObj->pInventory[11].m_Durability = 0;
                        }

                        BYTE dur = (BYTE)lpObj->pInventory[11].m_Durability;

                        GCItemDurSend(lpObj->m_Index,11,dur,0);

                        if(dur == 0)
                        {
                                gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                                LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[11].m_Level,dur);
                                lpObj->pInventory[11].Clear();
                                GCInventoryItemDeleteSend(lpObj->m_Index,11,0);
                        }
                }
        }
        else if(lpObj->pInventory[10].IsItem() == 1 && lpObj->pInventory[10].m_Type == ITEMGET(13,41))
        {
                int m_Durability = (int)lpObj->pInventory[10].m_Durability;

                lpObj->pInventory[10].m_Durability -= (float)0.02;

                if(m_Durability > (int)lpObj->pInventory[10].m_Durability)
                {
                        if(lpObj->pInventory[10].m_Durability < 1)
                        {
                                lpObj->pInventory[10].m_Durability = 0;
                        }

                        BYTE dur = (BYTE)lpObj->pInventory[10].m_Durability;

                        GCItemDurSend(lpObj->m_Index,10,dur,0);

                        if(dur == 0)
                        {
                                gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                                LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[10].m_Level,dur);
                                lpObj->pInventory[10].Clear();
                                GCInventoryItemDeleteSend(lpObj->m_Index,10,0);
                        }
                }
        }
        else if(lpObj->pInventory[11].IsItem() == 1 && lpObj->pInventory[11].m_Type == ITEMGET(13,41))
        {
                int m_Durability = (int)lpObj->pInventory[11].m_Durability;

                lpObj->pInventory[11].m_Durability -= (float)0.02;

		if(m_Durability > (int)lpObj->pInventory[11].m_Durability)
		{
			if(lpObj->pInventory[11].m_Durability < 1)
			{
				lpObj->pInventory[11].m_Durability = 0;
			}

			BYTE dur = (BYTE)lpObj->pInventory[11].m_Durability;

			GCItemDurSend(lpObj->m_Index,11,dur,0);

			if(dur == 0)
			{
				gObjUseSkill.SkillChangeUse(lpObj->m_Index);
				LogAdd("[%s][%s] %s+%d %d Item broken because durability exhausted",lpObj->AccountID,lpObj->Name,lpObj->pInventory[10].GetName(),lpObj->pInventory[11].m_Level,dur);
				lpObj->pInventory[11].Clear();
				GCInventoryItemDeleteSend(lpObj->m_Index,11,0);
			}
		}
	}
}




#pragma warning ( disable : 4101 )

void gObjWingDurProc(LPOBJ lpObj) 
{
	BYTE send_dur=0; // HERE GOES A MACRO
	{
		int dur;
	}
}

#pragma warning ( default : 4101 )




void gObjPenaltyDurDown(LPOBJ lpObj, LPOBJ lpTargetObj)	// Functio n Not USed
{
	int ret = 0;
	int reCalCharacter = 0;

	int irand = Random(0,1);

	CItem * Weapon = &lpObj->pInventory[irand];
	int decdur = 1;

	switch(lpObj->Class)
	{
	case 0:
		decdur = lpObj->Level - (lpTargetObj->Level * 38) / 20;
		break;
	case 1:
		decdur = lpObj->Level - (lpTargetObj->Level * 37) / 20;
		break;
	case 2:
		decdur = lpObj->Level - (lpTargetObj->Level * 36) / 20;
		break;
	case 3:
	case 4:
		decdur = lpObj->Level - (lpTargetObj->Level * 37) / 20;
		break;
	default : break;
	}

	decdur /= 10;

	if(Weapon->m_Type != ITEMGET(4,7) && Weapon->m_Type != ITEMGET(4,15))
	{
		if(Weapon->m_Type < ITEMGET(6,0) && Weapon->m_Type >= ITEMGET(7,0) )
		{
			if ( Weapon->IsItem() )
			{
				ret = Weapon->DurabilityDown2(decdur,lpObj->m_Index);
			}
		}
		else
		{
			CItem * Weapon = &lpObj->pInventory[irand];

			if(Weapon->IsItem())
			{
				ret = Weapon->DurabilityDown2(decdur,lpObj->m_Index);
			}
		}
	}

	if(ret != 0)
	{
		GCItemDurSend2(lpObj->m_Index,irand,(BYTE)lpObj->pInventory[irand].m_Durability,0);
	}

	if(ret == 2)
	{
		reCalCharacter = 1;
	}

	int item_num[7] = {0,1,2,3,4,5,6};
	int item_pos = Random(0,6);

	CItem * DurItem = &lpObj->pInventory[item_num[item_pos]];

	if(DurItem->m_Type != ITEMGET(4,7) && DurItem->m_Type != ITEMGET(4,15))
	{
		if(item_pos < 2)
		{
			if(DurItem->m_Type >= ITEMGET(6,0) && DurItem->m_Type < ITEMGET(7,0))
			{
				ret = DurItem->DurabilityDown2(decdur,lpObj->m_Index);
	
				if(ret != 0)
				{
					GCItemDurSend2(lpObj->m_Index,item_num[item_pos],(BYTE)DurItem->m_Durability,0);
	
					if(ret == 2)
					{
						reCalCharacter = 1;
					}
				}
			}
		}
		else
		{
			ret = DurItem->DurabilityDown2(decdur,lpObj->m_Index);

			if(ret != 0)
			{
				GCItemDurSend2(lpObj->m_Index,item_num[item_pos],(BYTE)DurItem->m_Durability,0);

				if(ret == 2)
				{
					reCalCharacter = 1;
				}
			}
		}
	}

	CItem * Wing = &lpObj->pInventory[7];

	if(Wing->IsItem())
	{
		ret = DurItem->DurabilityDown2(decdur,lpObj->m_Index);

		if(ret != 0)
		{
			GCItemDurSend2(lpObj->m_Index,item_num[item_pos],(BYTE)DurItem->m_Durability,0);

			if(ret == 2)
			{
				reCalCharacter = 1;
			}
		}
	}

	if(reCalCharacter != 0)
	{
		gObjCalCharacter(lpObj->m_Index);
	}
}






void gObjWeaponDurDown(LPOBJ lpObj, LPOBJ lpTargetObj, int type)
{
	if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
	{
		return;
	}

	int itargetdefence = 0;
	CItem * Right = &lpObj->pInventory[0];
	CItem * Left = &lpObj->pInventory[1];
	int ret = 0;

	if(type == 0)
	{

		itargetdefence = lpTargetObj->m_Defense;
		itargetdefence += lpTargetObj->m_iSkillNPCDefense;

		if((lpObj->Class == 1 || lpObj->Class == 3 || lpObj->Class == 4)
			&& (Right->m_Type >= 0 && Right->m_Type < ITEMGET(4,0) 
				&& Left->m_Type >= 0 && Left->m_Type < ITEMGET(4,0)))
		{
			if(Random(0,1)==0)
			{
				ret = Left->NormalWeaponDurabilityDown(itargetdefence,lpObj->m_Index);
				
				if(ret != 0)
				{
					GCItemDurSend(lpObj->m_Index,1,(BYTE)Left->m_Durability,0);
					if(ret == 2)
					{
						gObjCalCharacter(lpObj->m_Index);
					}
				}
			}
			else
			{
				ret = Right->NormalWeaponDurabilityDown(itargetdefence,lpObj->m_Index);
				if(ret != 0)
				{
					GCItemDurSend(lpObj->m_Index,0,(BYTE)Right->m_Durability,0);
					if(ret==2)
					{
						gObjCalCharacter(lpObj->m_Index);
					}
				}
			}

			return;
		}
		else if(Left->m_Type >= ITEMGET(4,0) && Left->m_Type < ITEMGET(4,7) || Left->m_Type == ITEMGET(4,20) || Left->m_Type == ITEMGET(4,21))
		{
			ret = Left->BowWeaponDurabilityDown(itargetdefence,lpObj->m_Index);

			if(ret != 0)
			{
				GCItemDurSend(lpObj->m_Index,1,(BYTE)Left->m_Durability,0);
				if(ret==2)
				{
					gObjCalCharacter(lpObj->m_Index);
				}
			}
		}
		else if(Right->m_Type >= ITEMGET(4,8) && Right->m_Type < ITEMGET(4,15) || Right->m_Type >= ITEMGET(4,16) && Right->m_Type < ITEMGET(5,0))
		{
			ret = Right->BowWeaponDurabilityDown(itargetdefence,lpObj->m_Index);

			if(ret != 0)
			{
				GCItemDurSend(lpObj->m_Index,0,(BYTE)Right->m_Durability,0);
				if(ret==2)
				{
					gObjCalCharacter(lpObj->m_Index);
				}
			}
		}
		else if(Right->m_Type >= ITEMGET(0,0) && Right->m_Type < ITEMGET(4,0))
		{
			ret = Right->NormalWeaponDurabilityDown(itargetdefence,lpObj->m_Index);

			if(ret != 0)
			{
				GCItemDurSend(lpObj->m_Index,0,(BYTE)Right->m_Durability,0);
				if(ret==2)
				{
					gObjCalCharacter(lpObj->m_Index);
				}
			}
		}
		else if(Right->m_Type >= ITEMGET(5,0) && Right->m_Type < ITEMGET(6,0))
		{
			ret = Right->StaffWeaponDurabilityDown(itargetdefence,lpObj->m_Index);

			if(ret != 0)
			{
				GCItemDurSend(lpObj->m_Index,0,(BYTE)Right->m_Durability,0);
				if(ret==2)
				{
					gObjCalCharacter(lpObj->m_Index);
				}
			}
		}
	return;
	}


	if(lpTargetObj->Type == OBJ_MONSTER || lpTargetObj->Type == OBJ_NPC)
	{
		itargetdefence = lpTargetObj->m_MagicDefense;
	}
	else
	{
		itargetdefence = lpTargetObj->m_Defense;
	}

	itargetdefence += lpTargetObj->m_iSkillNPCDefense;

	if(Right->m_Type >= ITEMGET(5,0) && Right->m_Type < ITEMGET(6,0))
	{
		ret = Right->StaffWeaponDurabilityDown(itargetdefence,lpObj->m_Index);
		if(ret != 0)
		{
			GCItemDurSend(lpObj->m_Index,0,(BYTE)Right->m_Durability,0);
			if(ret==2)
			{
				gObjCalCharacter(lpObj->m_Index);
			}
		}
	}
}






void gObjArmorRandomDurDown(LPOBJ lpObj, LPOBJ lpAttackObj)
{
	int item_num[7] = {0,1,2,3,4,5,6};
	int item_pos = Random(0,6);

	if(lpObj->Type != OBJ_USER)
	{
		return;
	}

	CItem * DurItem = &lpObj->pInventory[item_num[item_pos]];
	int damagemin = lpAttackObj->m_AttackDamageMin;
	int ret;

	if(item_pos < 2)
	{
		if(DurItem->m_Type >= ITEMGET(6,0) && DurItem->m_Type < ITEMGET(7,0))
		{
			ret = DurItem->ArmorDurabilityDown(damagemin,lpObj->m_Index);

			if(ret != 0)
			{
				GCItemDurSend(lpObj->m_Index,item_num[item_pos],(BYTE)DurItem->m_Durability,0);
				if(ret == 2)
				{
					gObjCalCharacter(lpObj->m_Index);
				}
			}
			return;
		}
	}
	else
	{
		if(DurItem->m_Type != ITEMGET(4,7) && DurItem->m_Type != ITEMGET(4,15))
		{
			ret = DurItem->ArmorDurabilityDown(damagemin,lpObj->m_Index);

			if(ret != 0)
			{
				GCItemDurSend(lpObj->m_Index,item_num[item_pos],(BYTE)DurItem->m_Durability,0);
				if(ret == 2)
				{
					gObjCalCharacter(lpObj->m_Index);
				}
			}
		}
	}
}






bool gObjIsSelfDefense(LPOBJ lpObj, int aTargetIndex)
{
	if ( !OBJMAX_RANGE(aTargetIndex) )
	{
		return false;
	}

	for ( int n=0;n<MAX_SELF_DEFENSE;n++)
	{
		if ( lpObj->SelfDefense[n] >= 0 )
		{
			if ( lpObj->SelfDefense[n] == aTargetIndex )
			{
				return true;
			}
		}
	}

	return false;
}






void gObjCheckSelfDefense(LPOBJ lpObj, int aTargetIndex)
{
	if(!OBJMAX_RANGE(aTargetIndex))
	{
		return;
	}

	if(gObj[aTargetIndex].m_PK_Level > 4)
	{
		return;
	}

	for(int n = 0; n < MAX_SELF_DEFENSE;n++)
	{
		if(gObj[aTargetIndex].SelfDefense[n] >= 0)
		{
			if(gObj[aTargetIndex].SelfDefense[n]==lpObj->m_Index)
			{
				return;
			}
		}
	}

	int blank = -1;

	for(int n = 0; n < MAX_SELF_DEFENSE;n++)
	{
		if(lpObj->SelfDefense[n] >= 0)
		{
			if(lpObj->SelfDefense[n] == aTargetIndex)
			{
				lpObj->SelfDefenseTime[n] = GetTickCount()+30000;
				return;
			}
		}
		else
		{
			blank = n;
		}
	}

	if(blank < 0)
	{
		LogAdd("Self-defense count exceeds");
		return;
	}

	lpObj->MySelfDefenseTime = GetTickCount();
	lpObj->SelfDefense[blank] = aTargetIndex;
	lpObj->SelfDefenseTime[blank] = GetTickCount() + 30000;

	char szTemp[64];

	wsprintf(szTemp,"Self defense is initiated by %s's attack!",lpObj->Name);

	GCServerMsgStringSend(szTemp,lpObj->m_Index,1);
	GCServerMsgStringSend(szTemp,aTargetIndex,1);

	LogAdd("[%s][%s] Set SelfDefence [%s][%s]",lpObj->AccountID,lpObj->Name,gObj[aTargetIndex].AccountID,gObj[aTargetIndex].Name);
}






void gObjTimeCheckSelfDefense(LPOBJ lpObj)
{
	char szTemp[64];

	for ( int n=0;n<MAX_SELF_DEFENSE;n++)
	{
		if ( lpObj->SelfDefense[n] >= 0 )
		{
			if ( GetTickCount() > lpObj->SelfDefenseTime[n] )
			{
				wsprintf(szTemp, "Self defense against %s diminishes.", lpObj->Name);
				GCServerMsgStringSend(szTemp, lpObj->m_Index, 1);
				GCServerMsgStringSend(szTemp, lpObj->SelfDefense[n], 1);
				lpObj->SelfDefense[n] = -1;
				
				LogAdd("[%s][%s] ReSet SelfDefence [%s][%s]",
					lpObj->AccountID, lpObj->Name,
					gObj[lpObj->SelfDefense[n]].AccountID, gObj[lpObj->SelfDefense[n]].Name);
			}
		}
	}
}






BOOL gObjAttack(LPOBJ lpObj, LPOBJ lpTargetObj, CMagicInf * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage, BOOL bCombo)
{
	return gclassObjAttack.Attack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
}


void gObjMonsterExpDivision(LPOBJ lpMonObj, LPOBJ lpObj, int AttackDamage, int MSBFlag)
{

	gObjMonsterHitDamageUserDel(lpMonObj);
	lpMonObj->Money = 0;


	int tObjNum;
	int exp;
	LPOBJ lpTargetObj;

	for(int n = 0; n < MAX_ST_HIT_DAMAGE;n++)
	{
		if(lpMonObj->sHD[n].number >= 0)
		{
			tObjNum = lpMonObj->sHD[n].number;
			lpTargetObj = &gObj[tObjNum];

			if(lpMonObj->sHD[n].HitDamage > 0)
			{
				bool bSendExp = 1;

				exp = gObjMonsterExpSingle(lpTargetObj,lpMonObj,lpMonObj->sHD[n].HitDamage,(int)lpMonObj->MaxLife,bSendExp);

				if(exp > 0)
				{
					if(bSendExp == 1)
					{
						if(lpTargetObj->m_Index == lpObj->m_Index)
						{
							if(lpObj->m_wExprienceRate > 0)
							{
								GCKillPlayerExpSend(lpTargetObj->m_Index,lpMonObj->m_Index,exp,AttackDamage,MSBFlag);
							}
						}
						else if(lpTargetObj->m_wExprienceRate > 0)
						{
							GCKillPlayerExpSend(lpTargetObj->m_Index,lpMonObj->m_Index,exp,0,MSBFlag);
						}
					}
					lpMonObj->Money += exp;
				}
			}
		}
	}
}


DWORD gObjMonsterExpSingle(LPOBJ lpObj, LPOBJ lpTargetObj, int dmg, int tot_dmg, bool& bSendExp)
{

	if(DS_MAP_RANGE(lpObj->MapNumber))
	{
		return g_DevilSquare.gObjMonsterExpSingle(lpObj,lpTargetObj,dmg,tot_dmg);
	}

	DWORD exp;
	DWORD maxexp = 0;
	int level = (lpTargetObj->Level+25)*lpTargetObj->Level/3;

	if((lpTargetObj->Level+10) < lpObj->Level)
	{
		level = level*(lpTargetObj->Level+10)/lpObj->Level;
	}

	if(lpTargetObj->Level >= 65)
	{
		level = level + (lpTargetObj->Level-64)*(lpTargetObj->Level/4);
	}

	if(level > 0)
	{
		maxexp = level/2;
	}
	else
	{
		level = 0;
	}

	if(maxexp < 1)
	{
		exp = level;
	}
	else
	{
		exp = level + Random(0,maxexp-1);
	}

	exp = dmg * exp / tot_dmg;

	if(BC_MAP_RANGE(lpObj->MapNumber))
	{
		exp = exp * 50 / 100;
	}

	DWORD mymaxexp = gLevelExperience[lpObj->Level];

	if(exp > mymaxexp)
	{
		exp = mymaxexp;
	}

	//exp *= (DWORD)gAddExperience;
	exp *= VipSystem_MapExp[lpObj->VipType][lpObj->MapNumber];

	if ( lpObj->m_wExprienceRate > 0 )
	{
		exp =  DWORD((double)exp * ((double)lpObj->m_wExprienceRate  / 100.0));
	}

	if ( g_CrywolfSync.GetOccupationState() == 1 && g_iCrywolfApplyMvpPenalty != FALSE)
	{
		exp =  (exp * g_CrywolfSync.GetGettingExpPenaltyRate()) / 100;
	}

	if(exp > 0)
	{
		if(lpObj->Type == OBJ_USER)
		{
			if(lpObj->m_wExprienceRate > 0)
			{
				lpObj->Experience += exp;
			}

			if(gObjLevelUp(lpObj,exp,lpTargetObj->Class,0) == 0)
			{
				bSendExp = 0;
			}
		}
	}

	return exp;
}



void gObjExpParty(LPOBJ lpObj , LPOBJ lpTargetObj, int AttackDamage, int MSBFlag )
{

	if(DS_MAP_RANGE(lpObj->MapNumber))
	{
		g_DevilSquare.gObjExpParty(lpObj,lpTargetObj,AttackDamage,MSBFlag);
		return;
	}

	int n;
	DWORD exp;
	DWORD maxexp = 0;
	int totalexp;
	int level = (lpTargetObj->Level+25)*lpTargetObj->Level / 3;
	int number;
	int partynum = 0;
	int totallevel = 0;
	int partylevel;
	int partycount;
	int dis[5];
	int viewplayer = 0;
	int viewpercent = 100;
	int bApplaySetParty = 0;
	BYTE bCheckSetParty[5];
	LPOBJ lpPartyObj;

	partynum = lpObj->PartyNumber;

	int toplevel = 0;

	for(n = 0; n < MAX_USER_IN_PARTY; n++)
	{
		number = gParty.m_PartyS[partynum].Number[n];

		if(number >= 0)
		{
			lpPartyObj = &gObj[number];

			if(lpPartyObj->Level > toplevel)
			{
				toplevel = lpPartyObj->Level;
			}
		}
	}

	if(!OBJMAX_RANGE(partynum))
	{
		LogAdd("error : %s %d",__FILE__,__LINE__);
		return;
	}

	memset(bCheckSetParty,0,sizeof(bCheckSetParty));

	partycount = gParty.m_PartyS[partynum].Count;

	for(n = 0; n < MAX_USER_IN_PARTY; n++)
	{
		number = gParty.m_PartyS[partynum].Number[n];

		if(number >= 0)
		{
			lpPartyObj = &gObj[number];

			if(lpTargetObj->MapNumber == lpPartyObj->MapNumber)
			{
				dis[n] = gObjCalDistance(lpTargetObj,&gObj[number]);

				if(dis[n] < 10)
				{
					lpPartyObj = &gObj[number];

					if(toplevel >= (lpPartyObj->Level+200))
					{
						totallevel += lpPartyObj->Level+200;
					}
					else
					{
						totallevel += lpPartyObj->Level;
					}
					viewplayer += 1;
					bCheckSetParty[lpPartyObj->Class] = 1;
				}
			}
		}
	}

	if(bCheckSetParty[0] != 0 && bCheckSetParty[1] != 0 && bCheckSetParty[2]!= 0)
	{
		bApplaySetParty = 1;
	}

	if(viewplayer > 1)
	{
		if(bApplaySetParty != 0)
		{
			if(viewplayer == 3)
			{
				viewpercent = g_SetPartyExp3;//230
			}
			else if(viewplayer == 4)
			{
				viewpercent = g_SetPartyExp4;//270
			}
			else if(viewplayer >= 5)
			{
				viewpercent = g_SetPartyExp5;//300
			}
			else
			{
				viewpercent = 120;
			}
		}
		else
		{
			if(viewplayer == 2)
			{
				viewpercent = g_PartyExp2;//160
			}
			else if(viewplayer == 3)
			{
				viewpercent = g_PartyExp3;//180
			}
			else if(viewplayer == 4)
			{
				viewpercent = g_PartyExp4;//200
			}
			else if(viewplayer >= 5)
			{
				viewpercent = g_PartyExp5;//220
			}
			else
			{
				viewpercent = 150;
			}
		}

		partylevel = totallevel / viewplayer;
	}
	else
	{
		partylevel = totallevel;
	}

	if((lpTargetObj->Level+10) < partylevel)
	{
		level = level * (lpTargetObj->Level+10) / partylevel;
	}

	if(lpTargetObj->Level >= 65)
	{
		if(viewplayer == 1)
		{
			level = level + (lpTargetObj->Level-64)*(lpTargetObj->Level/4);
		}
		else
		{
			level += (int)(200.0 - (lpObj->Level * 0.2));
		}
	}

	if(level > 0)
	{
		maxexp = level / 2;
	}
	else
	{
		level = 0;
	}

	if(maxexp < 1)
	{
		totalexp = level;
	}
	else
	{
		totalexp = level + Random(0,maxexp-1);
	}

	if(lpTargetObj->Type == OBJ_MONSTER)
	{
		lpTargetObj->Money = totalexp;
	}

	for(n = 0; n < MAX_USER_IN_PARTY; n++)
	{
		number = gParty.m_PartyS[partynum].Number[n];

		if(number >= 0)
		{
			lpPartyObj = &gObj[number];

			if(lpTargetObj->MapNumber == lpPartyObj->MapNumber && dis[n] < 10)
			{
				DWORD mymaxexp = gLevelExperience[lpPartyObj->Level];

				exp = (totalexp * viewpercent * lpPartyObj->Level)/totallevel / 100;

				if(BC_MAP_RANGE(lpPartyObj->MapNumber))
				{
					exp = exp * 50 / 100;
				}

				if(exp > mymaxexp)
				{
					exp = mymaxexp;
				}

				if(lpPartyObj->Type == OBJ_USER && lpTargetObj->Type == OBJ_USER)
				{
					exp = 0;
				}

				//exp *= (DWORD)gAddExperience;
				exp *= VipSystem_MapExp[lpObj->VipType][lpObj->MapNumber];

				if(lpPartyObj->m_wExprienceRate > 0)
				{
					exp = DWORD((double)exp * ((double)lpPartyObj->m_wExprienceRate  / 100.0));
				}

				if ( g_CrywolfSync.GetOccupationState() == 1 && g_iCrywolfApplyMvpPenalty != FALSE)
				{
					exp =  (exp * g_CrywolfSync.GetGettingExpPenaltyRate()) / 100;
				}

				if(exp > 0)
				{
					if(lpPartyObj->Type == OBJ_USER)
					{
						if(lpPartyObj->m_wExprienceRate > 0)
						{
							lpPartyObj->Experience += exp;
						}

						if(gObjLevelUp(lpPartyObj,exp,lpTargetObj->Class,1) == 0)
						{
							continue;
						}
					}
				}

				if(lpPartyObj->Type == OBJ_USER && lpPartyObj->m_wExprienceRate > 0)
				{
					GCKillPlayerExpSend(lpPartyObj->m_Index,lpTargetObj->m_Index,exp,AttackDamage,MSBFlag);
				}
			}
		}
	}
}






void gObjMonsterDieLifePlus(LPOBJ lpObj, LPOBJ lpTartObj)
{
	if(lpTartObj->Level < 0 || lpTartObj->Level > 255)
	{
		return;
	}

	lpObj->Life += lpTartObj->Level;

	if(lpObj->MonsterDieGetLife != 0)
	{
		lpObj->Life = lpObj->Life + ((lpObj->MaxLife + lpObj->AddLife)/8.0f) * lpObj->MonsterDieGetLife;
	}

	if(lpObj->MonsterDieGetMana != 0)
	{
		lpObj->Mana = lpObj->Mana + ((lpObj->MaxMana + lpObj->AddMana)/8.0f) * lpObj->MonsterDieGetMana;
	}

	if(lpObj->Life > (lpObj->MaxLife + lpObj->AddLife))
	{
		lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
	}

	GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,255,0,lpObj->iShield);

	if(lpObj->MonsterDieGetMana != 0)
	{
		if(lpObj->Mana > (lpObj->MaxMana + lpObj->AddMana))
		{
			lpObj->Mana = lpObj->MaxMana + lpObj->AddMana;
		}

		GCManaSend(lpObj->m_Index,(short)lpObj->Mana,255,0,lpObj->BP);
	}
}






void gObjLifeCheck(LPOBJ lpTargetObj, LPOBJ lpObj, int AttackDamage, int DamageSendType, int MSBFlag, int MSBDamage, BYTE Skill, int iShieldDamage)
{
	if(lpObj->Connected != PLAYER_PLAYING)
	{
		return;
	}

	if(ATTRIBUTE_RANGE(lpObj->m_Attribute) || ATTRIBUTE_RANGE(lpTargetObj->m_Attribute))
	{
		return;
	}

	if (lpObj->Type == OBJ_USER && lpTargetObj->Type == OBJ_NPC)
		return;

	LPOBJ lpCallObj = lpObj;

	if(lpObj->Type == OBJ_MONSTER && lpObj->m_RecallMon >= 0)
	{
		lpCallObj = &gObj[lpObj->m_RecallMon];
	}

	if(AttackDamage != 0 && lpTargetObj->Type == OBJ_MONSTER)
	{
		if(lpTargetObj->m_RecallMon >= 0)
		{
			GCRecallMonLife(lpTargetObj->m_RecallMon,(int)lpTargetObj->MaxLife,(int)lpTargetObj->Life);
		}

		gObjMonsterSetHitDamage(lpTargetObj,lpCallObj->m_Index,AttackDamage);
	}

	if(lpTargetObj->Life <= 0 && lpTargetObj->Live != 0)
	{
		if(lpObj->Type == OBJ_MONSTER)
		{
			gObjAddMsgSend(lpObj,3,lpTargetObj->m_Index,0);
			CreateFrustrum(lpObj->X,lpObj->Y,lpObj->m_Index);
			lpTargetObj->KillerType = 1;
		}

		if(lpObj->Type == OBJ_USER)
		{
			gDarkSpirit[lpObj->m_Index].ReSetTarget(lpTargetObj->m_Index);
		}

		if(lpObj->Type == OBJ_USER && lpTargetObj->Type == OBJ_USER)
		{
			gObjSetKillCount(lpObj->m_Index,1);
		}

		if(lpTargetObj->Type == OBJ_MONSTER)
		{
 
	
			if(lpTargetObj->Class == 275 || lpTargetObj->Class == 295 || lpTargetObj->MapNumber == MAP_INDEX_CRYWOLF_FIRSTZONE)
			{
				gObjAddMsgSendDelayInSpecificQPos(lpTargetObj,1,lpObj->m_Index,800,0,0);
			}
			else
			{
				gObjAddMsgSendDelay(lpTargetObj,1,lpObj->m_Index,800,0);
			}

			g_Crywolf.CrywolfMonsterDieProc(lpTargetObj->m_Index,lpObj->m_Index);

 
			if(lpTargetObj->m_Attribute == 62)
			{

				char szMsg[256];

				switch(lpTargetObj->Class)
				{
				case 300:// Hero Mobs
				case 301:
				case 302:
				case 303:
					{
						PMSG_NOTICE pNotice;

						ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,(BYTE)lpObj->X,(BYTE)lpObj->Y,ItemGetNumberMake(14,13),0,0,0,0,0,lpObj->m_Index,0,0);

						if(gObjIsConnected(lpObj->m_Index))
						{
							wsprintf(szMsg,"%s has pushed back the attack of %s at Loren pass",lpTargetObj->Name,lpObj->Name);
							LogAdd("[CastleDeep Event] [%s][%s] Boss Monster Killed : %s",lpObj->AccountID,lpObj->Name,lpTargetObj->Name);
						}
						else
						{
							wsprintf(szMsg,"The attack of %s has been pushed back at Loren pass",lpTargetObj->Name);
							LogAdd("[CastleDeep Event] Boss Monster Killed : %s",lpTargetObj->Name);
						}

						TNotice::MakeNoticeMsg(&pNotice,0,szMsg);

						for(int i = OBJ_STARTUSERINDEX; i < OBJMAX;i++)
						{
							if(gObj[i].Connected == PLAYER_PLAYING && gObj[i].Type == OBJ_USER)
							{
								DataSend(i,(PBYTE)&pNotice,pNotice.h.size);
							}
						}
					}
					break;
				case 295: // Erohim
					{
						PMSG_NOTICE pNotice;

						if(gObjIsConnected(lpObj->m_Index))
						{
							wsprintf(szMsg,"%s has pushed back the attack of Erohim's army at Loren pass",lpObj->Name);
							LogAdd("[CastleDeep Event] [%s][%s] Boss Monster Killed : %s",lpObj->AccountID,lpObj->Name,lpTargetObj->Name);
						}
						else
						{
							strcpy(szMsg,"The attack of Erohim's army has been pushed back at Loren pass");
							LogAdd("[CastleDeep Event] Boss Monster Killed : %s",lpTargetObj->Name);
						}

						TNotice::MakeNoticeMsg(&pNotice,0,szMsg);

						for(int i = OBJ_STARTUSERINDEX; i < OBJMAX;i++)
						{
							if(gObj[i].Connected == PLAYER_PLAYING && gObj[i].Type == OBJ_USER)
							{
								DataSend(i,(PBYTE)&pNotice,pNotice.h.size);
							}
						}
					}
					break;
				}
			}

			g_Kanturu.KanturuMonsterDieProc(lpTargetObj->m_Index,lpObj->m_Index);

			if(BC_MAP_RANGE(lpTargetObj->MapNumber))
			{
				if(lpTargetObj->Class == 131)
				{
					int TopHitUser = gObjMonsterTopHitDamageUser(lpTargetObj);

					if(TopHitUser != -1)
					{
						char szMsg[256];

						wsprintf(szMsg,"%s has demolished the Castle Gates!",gObj[TopHitUser].Name);

						g_BloodCastle.SendNoticeMessage(lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1,szMsg);

						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_iExtraEXP_Kill_Door_Party = gObj[TopHitUser].PartyNumber;
						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_iExtraEXP_Kill_Door_Index = TopHitUser;

						memcpy(g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Door_CharName,gObj[TopHitUser].Name,10);
						memcpy(g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Door_AccountID,gObj[TopHitUser].AccountID,10);

						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Door_CharName[10] = 0;
						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Door_AccountID[10] = 0;

						LogAdd("[Blood Castle] (%d) Door Terminated -> %d [%s][%s]",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1-1),g_BloodCastle.m_BridgeData[lpObj->MapNumber-MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_KILL_COUNT,gObj[TopHitUser].AccountID,gObj[TopHitUser].Name);
					}
					else
					{
						g_BloodCastle.SendNoticeMessage(lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1,"The Gates of Blood Castle have been Demolished!!!");
						LogAdd("[Blood Castle] (%d) Door Terminated -> %d)",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1-1),g_BloodCastle.m_BridgeData[lpObj->MapNumber-MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_KILL_COUNT);
					}
				}


				if(BC_STATUE_RANGE(lpTargetObj->Class - 132))
				{
					int TopHitUser = gObjMonsterTopHitDamageUser(lpTargetObj);

					if(TopHitUser != -1)
					{
						char szMsg[256];

						wsprintf(szMsg,"%s has destroyed the Stone Statue!",gObj[TopHitUser].Name);

						g_BloodCastle.SendNoticeMessage(lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1,szMsg);


						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_iExtraEXP_Kill_Statue_Party = gObj[TopHitUser].PartyNumber;
						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_iExtraEXP_Kill_Statue_Index = gObj[TopHitUser].m_Index;

						memcpy(g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Status_CharName,gObj[TopHitUser].Name,10);
						memcpy(g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Status_AccountID,gObj[TopHitUser].AccountID,10);

						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Status_CharName[10] = 0;
						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_szKill_Status_AccountID[10] = 0;

						LogAdd("[Blood Castle] (%d) a stone statue Of Saint Terminated -> %d [%s][%s]",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1 - 1),g_BloodCastle.m_BridgeData[lpObj->MapNumber-MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_KILL_COUNT,gObj[TopHitUser].AccountID,gObj[TopHitUser].Name);
					}
					else
					{
						g_BloodCastle.SendNoticeMessage(lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1,"The Crystal Statue has been Destroyed!!!");
						LogAdd("[Blood Castle] (%d) a stone statue Of Saint Terminated -> %d",lpObj->MapNumber - (MAP_INDEX_BLOODCASTLE1-1),g_BloodCastle.m_BridgeData[lpObj->MapNumber-MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_KILL_COUNT);
					}
				}

				for(int n = 0; n < MAX_BLOOD_CASTLE_SUB_BRIDGE; n++)
				{
					if(g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_UserData[n].m_iIndex != -1)
					{
						if(gObj[g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_UserData[n].m_iIndex].Connected == PLAYER_PLAYING)
						{
							g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_UserData[n].m_bLiveWhenDoorBreak = 1;
						}
					}
				}
			}

			if(CC_MAP_RANGE(lpTargetObj->MapNumber))
			{
				if(Random(0,99) < 50)
				{
					g_ChaosCastle.SearchNBlowObjs(lpTargetObj->MapNumber,lpTargetObj->X,lpTargetObj->Y);
				}

				g_ChaosCastle.DelMonsterList(lpTargetObj->MapNumber - MAP_INDEX_CHAOSCASTLE1,lpTargetObj->m_Index);

				int TopHitUser = gObjMonsterTopHitDamageUser(lpTargetObj);

				if(TopHitUser != -1)
				{
					if(CC_MAP_RANGE(gObj[TopHitUser].MapNumber))
					{
						if(gObjIsConnected(TopHitUser))
						{
							gObj[TopHitUser].m_cKillMonsterCount += 1;
						}
					}
				}
			}

			gObjPkDownTimeCheck(lpObj,lpTargetObj->Level);

			if(lpObj->Type == OBJ_USER)
			{
				gObjAddMsgSendDelay(lpObj,3,lpTargetObj->m_Index,2000,0);
			}
		}
		else if(lpTargetObj->Type == OBJ_USER)
		{
			if(BC_MAP_RANGE(lpTargetObj->MapNumber))
			{
				g_BloodCastle.SetUserState(lpTargetObj->m_Index,1);
				g_BloodCastle.SearchUserDropQuestItem(lpTargetObj->m_Index);
			}

			if(CC_MAP_RANGE(lpTargetObj->MapNumber))
			{
				g_ChaosCastle.SetUserState(lpTargetObj->m_Index,1);

				if(CC_MAP_RANGE(lpObj->MapNumber))
				{
					if(gObjIsConnected(lpObj->m_Index))
					{
						lpObj->m_cKillUserCount += 1;
					}
				}

				g_ChaosCastle.SendFailMessage(lpTargetObj->MapNumber - MAP_INDEX_CHAOSCASTLE1,lpTargetObj->m_Index);

				LogAdd("[Chaos Castle] (%d) [%s][%s] User Dead In Chaos Castle : Killed by [%s][%s]",lpTargetObj->MapNumber - (MAP_INDEX_CHAOSCASTLE1 - 1),lpTargetObj->AccountID,lpTargetObj->Name,lpObj->AccountID,lpObj->Name);
			}

			lpTargetObj->KillerType = 0;

			gObjUserDie(lpTargetObj,lpCallObj);

			int iGuildWar = gObjGuildWarCheck(lpCallObj,lpTargetObj);
			int iDuel = gObjDuelCheck(lpCallObj,lpTargetObj);

			if(iGuildWar == 0 && iDuel == 0)
			{
				if(lpTargetObj->m_bAttackerKilled == 0)
				{
					gObjPlayerKiller(lpCallObj,lpTargetObj);
				}
			}

			lpTargetObj->m_bAttackerKilled = 0;

			if(lpTargetObj->m_RecallMon >= 0)
			{
				gObjMonsterCallKill(lpTargetObj->m_Index);
			}
		}

		lpTargetObj->Live = 0;
		lpTargetObj->m_State = 4;
		lpTargetObj->RegenTime = GetTickCount();
		lpTargetObj->DieRegen = 1;
		lpTargetObj->PathCount = 0;
		if(gObjTargetGuildWarCheck(lpTargetObj,lpCallObj)==1)
		{
			lpTargetObj->KillerType = 2;
		}

		if(gObjDuelCheck(lpCallObj,lpTargetObj))
		{
			lpTargetObj->KillerType = 3;
			if(lpObj->m_btDuelScore >= 10)
			{
				PMSG_ANS_END_DUEL pMsg;
				pMsg.h.c = 193;
				pMsg.h.headcode = 171;
				pMsg.h.size = 15;
				pMsg.NumberH = SET_NUMBERH(lpObj->m_Index);
				pMsg.NumberL = SET_NUMBERL(lpObj->m_Index);

				memcpy(pMsg.szName,lpObj->Name,10);

				DataSend(lpTargetObj->m_Index,(unsigned char *)&pMsg,pMsg.h.size);

				lpTargetObj->m_iDuelUser = -1;

				pMsg.NumberH = SET_NUMBERH(lpTargetObj->m_Index);
				pMsg.NumberL = SET_NUMBERL(lpTargetObj->m_Index);

				memcpy(pMsg.szName,lpTargetObj->Name,10);

				DataSend(lpObj->m_Index,(unsigned char *)&pMsg,pMsg.h.size);

				lpObj->m_iDuelUser = -1;

				gDarkSpirit[lpObj->m_Index].ReSetTarget(lpTargetObj->m_Index);
				gDarkSpirit[lpTargetObj->m_Index].ReSetTarget(lpObj->m_Index);

				char szMsg[256];

				wsprintf(szMsg,"You emerge triumphant over %s!",lpTargetObj->Name);

				GCServerMsgStringSend(szMsg,lpObj->m_Index,1);

				wsprintf(szMsg,"%s has defeated you!",lpObj->Name);

				GCServerMsgStringSend(szMsg,lpTargetObj->m_Index,1);

				PMSG_SERVERCMD ServerCmd;

				PHeadSubSetB((LPBYTE)&ServerCmd, 0xF3, 0x40, sizeof(ServerCmd));
				ServerCmd.CmdType = 0;
				ServerCmd.X = (BYTE)lpObj->X;
				ServerCmd.Y = (BYTE)lpObj->Y;

				MsgSendV2(lpObj,(unsigned char *)&ServerCmd,sizeof(ServerCmd));
				DataSend(lpObj->m_Index,(unsigned char *)&ServerCmd,sizeof(ServerCmd));

				LogAdd("[Duel] [%s][%s] Win Duel, Loser [%s][%s]",lpObj->AccountID,lpObj->Name,lpTargetObj->AccountID,lpTargetObj->Name);
			}
		}

		if(lpTargetObj->Teleport == 1)
		{
			lpTargetObj->Teleport = 0;
		}

		GCDiePlayerSend(lpTargetObj,lpTargetObj->m_Index,Skill,lpObj->m_Index);

		if(lpTargetObj->Class == 79)
		{
			gEledoradoEvent.m_BossGoldDerconMapNumber[lpTargetObj->m_BossGoldDerconMapNumber] = -1;
			gEledoradoEvent.CheckGoldDercon(lpObj->MapNumber);
		}

		if(lpTargetObj->m_RecallMon >= 0)
		{
			return;
		}

		if(lpTargetObj->Class == 340 || lpTargetObj->Class == 348 || lpTargetObj->Class == 349)
		{
			return;
		}

		if(lpTargetObj->Class == 287 || lpTargetObj->Class == 286)
		{
			return;
		}

		if(lpTargetObj->Class == 275)
		{
			return;
		}
		
		if(lpTargetObj->Class == 288)
		{
			return;
		}

		if(lpTargetObj->Class == 295)
		{
			return;
		}

 
		if(lpTargetObj->Class == 362 || lpTargetObj->Class == 363 || lpTargetObj->Class == 361)
		{
			return;
		}


		if(lpCallObj->Type == OBJ_USER)
		{
			if(lpCallObj->PartyNumber >= 0)
			{
				gObjExpParty(lpCallObj,lpTargetObj,AttackDamage,MSBFlag);
			}
			else if(lpTargetObj->Type == OBJ_MONSTER)
			{
				gObjMonsterExpDivision(lpTargetObj,lpCallObj,AttackDamage,MSBFlag);
			}

			if(lpTargetObj->Type == OBJ_MONSTER && DS_MAP_RANGE(lpTargetObj->MapNumber))
			{
				g_DevilSquare.gObjMonsterScoreDivision(lpTargetObj,lpCallObj,AttackDamage,MSBFlag);
			}
		}
		if(lpTargetObj->Type == OBJ_MONSTER)
		{
			if(lpTargetObj->m_bIsInMonsterHerd != 0 && lpTargetObj->m_lpMonsterHerd != 0)
			{
				lpTargetObj->m_lpMonsterHerd->MonsterDieAction(lpTargetObj);
			}
		}
	}
	else
	{
		if(DamageSendType == 0)
		{
			GCDamageSend(lpCallObj->m_Index,lpTargetObj->m_Index,AttackDamage,MSBFlag,MSBDamage,iShieldDamage);
		}
		else if(DamageSendType == 1)
		{
			GCDamageSend(lpTargetObj->m_Index,AttackDamage,iShieldDamage);
		}
		else if(DamageSendType == 2)
		{
			GCDamageSend(lpCallObj->m_Index,lpTargetObj->m_Index,AttackDamage,MSBFlag,5,iShieldDamage);
		}
	}
}






BOOL gObjInventoryTrans(int aIndex)
{
	if ( ((aIndex< 0)?FALSE:(aIndex > OBJMAX-1)?FALSE:TRUE) == FALSE )
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return FALSE;
	}

	if ( gObj[aIndex].pTransaction == 1 )
	{
		LogAdd("[%s][%s] error-L3 : pTransaction(%d) status error %s %d",
			gObj[aIndex].AccountID, gObj[aIndex].Name,
			gObj[aIndex].pTransaction, __FILE__, __LINE__);
		return FALSE;
	}

	for ( int n=0;n<MAX_MAGIC;n++)
	{
		gObj[aIndex].m_lpMagicBack[n] = gObj[aIndex].Magic[n]; 
	}

	for (int n=0;n<MAIN_INVENTORY_SIZE;n++)
	{
		gObj[aIndex].Inventory2[n] = gObj[aIndex].Inventory1[n];
	}

	//memcpy(gObj[aIndex].InventoryMap2, gObj[aIndex].InventoryMap1, INVENTORY_MAP_SIZE);	// #error Deathway Fix
	memcpy(gObj[aIndex].InventoryMap2, gObj[aIndex].InventoryMap1, 64);
	gObj[aIndex].InventoryCount2 = gObj[aIndex].InventoryCount1;
	gObjSetInventory2Pointer(&gObj[aIndex]);
	gObj[aIndex].pTransaction = 1;
	
	LogAdd("Trade Transaction (%s)", gObj[aIndex].Name);

	return TRUE;
}

// CMagicInf::operator= 4c4d90






int gObjInventoryCommit(int aIndex)
{

	if(!OBJMAX_RANGE(aIndex))
	{
		LogAdd("error : gObjInventoryCommit() - aIndex out of bound %s %d",__FILE__,__LINE__);
		return false;
	}

	if(gObj[aIndex].pTransaction != 1)
	{
		LogAdd("[%s][%s] error-L3 : pTransaction(%d) status2",gObj[aIndex].AccountID,gObj[aIndex].Name,gObj[aIndex].pTransaction);
		return false;
	}

	for(int n = 0; n < MAIN_INVENTORY_SIZE; n++)
	{
		gObj[aIndex].Inventory1[n] = gObj[aIndex].Inventory2[n];
	}

	memcpy(gObj[aIndex].InventoryMap1,gObj[aIndex].InventoryMap2,64);

	gObj[aIndex].InventoryCount1 = gObj[aIndex].InventoryCount2;

	gObjSetInventory1Pointer(&gObj[aIndex]);

	gObj[aIndex].pTransaction = 2;

	LogAdd("Trade Commit (%s)",gObj[aIndex].Name);

	return true;
}






int gObjInventoryRollback(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex))
	{
		LogAdd("error : %s %d",__FILE__,__LINE__);
		return false;
	}

	if(gObj[aIndex].pTransaction != 1)
	{
		LogAdd("[%s][%s] error-L3 : pTransaction(%d) status2",gObj[aIndex].AccountID,gObj[aIndex].Name,gObj[aIndex].pTransaction);
		return false;
	}

	for(int n = 0; n < MAX_MAGIC; n++)
	{
		gObj[aIndex].Magic[n] = gObj[aIndex].m_lpMagicBack[n];
	}

	for(int n = 0; n < INVENTORY_SIZE; n++)
	{
		gObj[aIndex].Inventory2[n].Clear();
	}

	gObjSetInventory1Pointer(&gObj[aIndex]);

	gObj[aIndex].pTransaction = 3;

	LogAdd("Trade Rollback (%s)",gObj[aIndex].Name);

	return true;
}






void gObjInventoryItemSet(int aIndex, int itempos, BYTE set_byte)
{
	int width;
	int height;
	if(itempos < INVETORY_WEAR_SIZE)
	{
		return;
	}
	else if(itempos > (INVENTORY_SIZE-1))
	{
		return;
	}

	if(gObj[aIndex].pInventory[itempos].GetSize((int&)width,(int &)height)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return;
	}

	gObjInventoryItemBoxSet(aIndex,itempos,width,height,set_byte);
}



void gObjInventoryItemBoxSet(int aIndex, int itempos, int xl, int yl, BYTE set_byte)
{
	int itemposx = (itempos - INVETORY_WEAR_SIZE)%8;
	int itemposy = (itempos - INVETORY_WEAR_SIZE)/8;

	int xx,yy;

	for(int y = 0; y < yl; y ++)
	{
		yy = itemposy + y;

		for(int x = 0; x < xl; x++)
		{
			xx = itemposx + x;

			if(ExtentCheck(xx,yy,8,12)==1)
			{
				*(BYTE*)(gObj[aIndex].pInventoryMap + (itemposy + y)*8+(itemposx + x)) = set_byte;
			}
			else
			{
				LogAdd("error : %s %d",__FILE__,__LINE__);
				return;
			}
		}
	}
}


bool gObjFixInventoryPointer(int aIndex)
{

	if(gObjIsConnected(aIndex)==0)
	{
		LogAdd("[Fix Inv.Ptr] [%s][%s] - disconnected",gObj[aIndex].AccountID,gObj[aIndex].Name);
		return false;
	}


	if(gObj[aIndex].pInventory == gObj[aIndex].Inventory1)
	{
		return true;
	}

	if(gObj[aIndex].pInventory == gObj[aIndex].Inventory2)
	{
		if(gObj[aIndex].pTransaction == 1)
		{
			LogAdd("[Fix Inv.Ptr] [%s][%s] - Transaction == 1, Do not change Pointer",gObj[aIndex].AccountID,gObj[aIndex].Name);
			return false;
		}
		else
		{
			LogAdd("[Fix Inv.Ptr] [%s][%s] - Inventory Pointer was 2",gObj[aIndex].AccountID,gObj[aIndex].Name);

			for(int n = 0; n < INVENTORY_SIZE; n++)
			{
				gObj[aIndex].Inventory2[n].Clear();
			}
		}
	}
	else
	{
		LogAdd("[Fix Inv.Ptr] [%s][%s] - Inventory Pointer was Wrong",gObj[aIndex].AccountID,gObj[aIndex].Name);
	}

	gObjSetInventory1Pointer(&gObj[aIndex]);

	return false;
}






void gObjInventoryItemSet_PShop(int aIndex, int itempos, BYTE set_byte)
{
	int width;
	int height;
	if(itempos < INVETORY_WEAR_SIZE)
	{
		return;
	}
	else if(itempos > (INVENTORY_SIZE-1))
	{
		return;
	}

	if(gObj[aIndex].Inventory1[itempos].GetSize((int&)width,(int &)height)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return;
	}

	gObjInventoryItemBoxSet_PShop(aIndex,itempos,width,height,set_byte);
}




void gObjInventoryItemBoxSet_PShop(int aIndex, int itempos, int xl, int yl, BYTE set_byte)
{
	int itemposx = (itempos - INVETORY_WEAR_SIZE)%8;
	int itemposy = (itempos - INVETORY_WEAR_SIZE)/8;

	int xx,yy;

	for(int y = 0; y < yl; y ++)
	{
		yy = itemposy + y;

		for(int x = 0; x < xl; x++)
		{
			xx = itemposx + x;

			if(ExtentCheck(xx,yy,8,12)==1)
			{
				*(BYTE*)(gObj[aIndex].InventoryMap1 + (itemposy + y)*8+(itemposx + x)) = set_byte;
			}
			else
			{
				LogAdd("error : %s %d",__FILE__,__LINE__);
				return;
			}
		}
	}
}






BYTE gObjInventoryDeleteItem(int aIndex ,int itempos)
{
	if(itempos < INVETORY_WEAR_SIZE)
	{
		int MagicDel = gObjMagicDel(&gObj[aIndex],gObj[aIndex].pInventory[itempos].m_Special[0],(BYTE)gObj[aIndex].pInventory[itempos].m_Level);

		if(MagicDel >= 0)
		{
			GCMagicListOneDelSend(aIndex,MagicDel,
				gObj[aIndex].pInventory[itempos].m_Special[0],
				(BYTE)gObj[aIndex].pInventory[itempos].m_Level,0,0);
		}

		gObj[aIndex].pInventory[itempos].Clear();
	}
	else
	{
		gObjInventoryItemSet(aIndex,itempos,255);
		gObj[aIndex].pInventory[itempos].Clear();
	}

	return true;
}






BYTE gObjWarehouseDeleteItem(int aIndex, int itempos)
{
	gObjWarehouseItemSet(aIndex, itempos, -1);
	gObj[aIndex].pWarehouse[itempos].Clear();

	return true;
}






BYTE gObjChaosBoxDeleteItem(int aIndex, int itempos)
{
	gObjChaosItemSet(aIndex, itempos, -1);
	gObj[aIndex].pChaosBox[itempos].Clear();

	return true;
}






BYTE gObjInventoryInsertItem(int aIndex, int item_num)
{
	int w,h,map_num,iwidth,iheight;
	BYTE blank;

	blank = 0;
	map_num = gObj[aIndex].MapNumber;

	if(MapC[map_num].m_cItem[item_num].live == 0)
	{
		return -1;
	}

	if(MapC[map_num].m_cItem[item_num].GetSize((int &)iwidth,(int &)iheight) == 0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for(w = 0; w < 8; w++)
		{
			if(*(BYTE*)(gObj[aIndex].pInventoryMap+h*8+w) == 255)
			{
				blank = gObjInventoryRectCheck(aIndex,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					gObj[aIndex].pInventory[blank] = MapC[map_num].m_cItem[item_num];
					gObjInventoryItemSet(aIndex,blank,(BYTE)gObj[aIndex].pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;

}






DWORD gGetItemNumber()	
{
	return gItemNumberCount;
}






void gPlusItemNumber() 
{
	return;	// Maybe here Apply deathway fix (gItemNumberCount++)
}






BYTE gObjInventoryInsertItem(int aIndex, CItem item)
{
	int w,h,iwidth,iheight;
	BYTE blank = 0;

	if(item.GetSize((int&)iwidth,(int&)iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for( w = 0; w < 8; w++)
		{
			if(*(BYTE*)(gObj[aIndex].pInventoryMap+h*8+w) == 255)
			{
				blank = gObjInventoryRectCheck(aIndex,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					if(gObjCheckSerial0ItemList(&item)!=0)
					{
						MsgOutput(aIndex,"Unable to use");
						return -1;
					}

					if(gObjInventorySearchSerialNumber(&gObj[aIndex],item.m_Number) == 0)
					{
						return -1;
					}

					gObj[aIndex].pInventory[blank] = item;

					gObjInventoryItemSet(aIndex,blank,(BYTE)gObj[aIndex].pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}

GOTO_EndFunc:
	return -1;
}






BYTE gObjOnlyInventoryInsertItem(int aIndex, CItem item)
{
		int w,h,iwidth,iheight;
	BYTE blank = 0;

	if(item.GetSize((int&)iwidth,(int&)iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for( w = 0; w < 8; w++)
		{
			if(*(BYTE*)(gObj[aIndex].pInventoryMap+h*8+w) == 255)
			{
				blank = gObjOnlyInventoryRectCheck(aIndex,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					if(gObjCheckSerial0ItemList(&item)!=0)
					{
						MsgOutput(aIndex,"Unable to use");
						return -1;
					}

					if(gObjInventorySearchSerialNumber(&gObj[aIndex],item.m_Number) == 0)
					{
						return -1;
					}

					gObj[aIndex].pInventory[blank] = item;

					gObjInventoryItemSet(aIndex,blank,(BYTE)gObj[aIndex].pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}

GOTO_EndFunc:
	return -1;
}






BYTE gObjInventoryInsertItem(int aIndex, CMapItem * item)
{
	int w,h,iwidth,iheight;
	BYTE blank = 0;

	CItem copyitem;


	if(item->GetSize((int &)iwidth,(int &)iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for(w = 0; w < 8; w++)
		{
			if(*(BYTE*)(gObj[aIndex].pInventoryMap+h*8+w) == 255)
			{
				blank = gObjOnlyInventoryRectCheck(aIndex,w,h,iwidth,iheight);
				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}
	
				if(blank != 255)
				{
					copyitem.m_Level = item->m_Level;
					copyitem.m_Durability = item->m_Durability;
	
					copyitem.Convert(item->m_Type,item->m_Option1,item->m_Option2,item->m_Option3,item->m_NewOption,item->m_SetOption,item->m_ItemOptionEx,CURRENT_DB_VERSION);
					copyitem.SetPetItemInfo(item->m_PetItem_Level,item->m_PetItem_Exp);
	
					copyitem.m_Number = item->m_Number;
	
					gObj[aIndex].pInventory[blank] = copyitem;
		
					gObjInventoryItemSet(aIndex,blank,(BYTE)gObj[aIndex].pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}

GOTO_EndFunc:
	return -1;
}






BOOL gObjSearchItem(LPOBJ lpObj, int item_type, int add_dur, int nLevel)
{
	for(int n = INVETORY_WEAR_SIZE; n < MAIN_INVENTORY_SIZE; n++)
	{
		if(lpObj->pInventory[n].IsItem() == 1)
		{
			if(lpObj->pInventory[n].m_Type == item_type)
			{
				if(lpObj->pInventory[n].m_Level == nLevel)
				{
					if((int)lpObj->pInventory[n].m_Durability + add_dur <= 3)
					{
						lpObj->pInventory[n].m_Durability += add_dur;
						GCItemDurSend(lpObj->m_Index,n,(BYTE)lpObj->pInventory[n].m_Durability,0);
						return true;
					}
				}
			}
		}
	}
	return false;
}






BOOL gObjSearchItemMinus(LPOBJ lpObj, int pos, int m_dur)
{
	int n = pos;
	if(n < 0 || n > (MAIN_INVENTORY_SIZE-1))
	{
		LogAdd("error-L4 : %s %d",__FILE__,__LINE__);
		return 1;
	}

	if(lpObj->pInventory[n].IsItem() == 1)
	{
		if((int)lpObj->pInventory[n].m_Durability - m_dur > 0)
		{
			lpObj->pInventory[n].m_Durability -= m_dur;
			GCItemDurSend(lpObj->m_Index,n,(BYTE)lpObj->pInventory[n].m_Durability,1);
			return 1;
		}
	}
	return 0;
}




BYTE gObjShopBuyInventoryInsertItem(int aIndex, CItem item)
{
	int w,h,iwidth,iheight;
	BYTE blank = 0;

	if(item.GetSize(iwidth,iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for( w = 0; w < 8; w++)
		{
			if(*(BYTE*)(gObj[aIndex].pInventoryMap+h*8+w) == 255)
			{
				blank = gObjOnlyInventoryRectCheck(aIndex,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					gObj[aIndex].pInventory[blank] = item;

					if(item.m_serial == 0)
					{
						gObj[aIndex].pInventory[blank].m_Number = 0;
					}
					else
					{
						gObj[aIndex].pInventory[blank].m_Number = gGetItemNumber();
						gPlusItemNumber();
					}

					gObjInventoryItemSet(aIndex,blank,(BYTE)gObj[aIndex].pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}


BYTE gObjShopBuyInventoryInsertItem(LPOBJ lpObj, int type, int index, int level, int iSerial, int iDur)
{
	int w,h,iwidth,iheight;
	BYTE blank = 0;
	CItem item;

	int item_type = ItemGetNumberMake(type,index);
	item.m_Level = level;
	item.m_Durability = iDur;

	item.Convert(item_type,0,0,0,0,0,0,CURRENT_DB_VERSION);

	if(item.GetSize((int &)iwidth,(int &)iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for(w = 0; w < 8; w++)
		{
			if(*(BYTE*)(lpObj->pInventoryMap+h*8+w) == 255)
			{
				blank = gObjOnlyInventoryRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					lpObj->pInventory[blank] = item;

					if ( !item.m_serial )
					{
						lpObj->pInventory[blank].m_Number = 0;
					}
					else
					{
						lpObj->pInventory[blank].m_Number = gGetItemNumber();
						gPlusItemNumber();
					}
					
					gObjInventoryItemSet(lpObj->m_Index,blank,(BYTE)lpObj->pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}



BYTE gObjInventoryInsertItemTemp(LPOBJ lpObj, CMapItem * Item)
{
	CItem item;
	int w,h,iwidth,iheight;
	BYTE blank = 0;

	if(Item->GetSize((int &)iwidth,(int &)iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for(w = 0; w < 8; w++)
		{
			if(*(BYTE*)(lpObj->pInventoryMap+h*8+w) == 255)
			{
				blank = gObjInventoryRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}







BYTE gObjInventoryInsertItem(LPOBJ lpObj, int type, int index, int level)
{
	CItem item;
	int w,h,iwidth,iheight;
	BYTE blank = 0;

	int item_type = ItemGetNumberMake(type,index);

	item.m_Level = level;

	item.Convert(item_type,0,0,0,0,0,0,CURRENT_DB_VERSION);

	if(item.GetSize((int &)iwidth,(int &)iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for( w = 0; w < 8; w++)
		{

			if(*(BYTE*)(lpObj->pInventoryMap+h*8+w) == 255)
			{
				blank = gObjOnlyInventoryRectCheck(lpObj->m_Index,w,h,iwidth,iheight);
	
				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}
	
				if(blank != 255)
				{
					lpObj->pInventory[blank] = item;
					lpObj->pInventory[blank].m_Number = gGetItemNumber();
					gPlusItemNumber();

					gObjInventoryItemSet(lpObj->m_Index,blank,(BYTE)lpObj->pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}






BYTE gObjInventoryInsertItem(LPOBJ lpObj, int type, int index, int level, int iSerial, int iDur)
{
	CItem item;
	int w,h,iwidth,iheight;
	BYTE blank = 0;

	int item_type = ItemGetNumberMake(type,index);
	item.m_Level = level;
	item.m_Durability = iDur;

	item.Convert(item_type,0,0,0,0,0,0,CURRENT_DB_VERSION);

	if(item.GetSize((int &)iwidth,(int &)iheight)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return -1;
	}

	for(h = 0; h < 8; h++)
	{
		for(w = 0; w < 8; w++)
		{
			if(*(BYTE*)(lpObj->pInventoryMap+h*8+w) == 255)
			{
				blank = gObjInventoryRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					lpObj->pInventory[blank] = item;
					lpObj->pInventory[blank].m_Number = iSerial;
					gPlusItemNumber();

					gObjInventoryItemSet(lpObj->m_Index,blank,(BYTE)lpObj->pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}






BYTE gObjMonsterInventoryInsertItem(LPOBJ lpObj, int type, int index, int level, int op1, int op2, int op3)
{
	CItem item;
	int w,h,iwidth,iheight;
	BYTE blank = 0;
	int item_type;
	int a = 0;

	item_type = ItemGetNumberMake(type,index);
	item.m_Level = level;

	if(type == 13 && index == 10)
	{
		item.m_Durability = Random(0,99)+100.0;
	}

	item.Convert(item_type,op1,op2,op3,0,0,0,CURRENT_DB_VERSION);

	lpObj->pInventory[blank] = item;
	iwidth = 1;
	iheight = 1;

	for(h = 0; h < 8; h++)
	{
		for(w = 0; w <8; w++)
		{
			if(*(BYTE*)(lpObj->pInventoryMap+h*8+w) == 255)
			{
				blank = gObjInventoryRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}

				if(blank != 255)
				{
					lpObj->pInventory[blank] = item;
					*lpObj->pInventoryCount += 1;

					gObjInventoryItemBoxSet(lpObj->m_Index,blank,iwidth,iwidth,(BYTE)lpObj->pInventory[blank].m_Type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}






BYTE gObjInventoryRectCheck(int aIndex, int sx, int sy, int width, int height)
{
	int x,y;
	int blank = 0;

	if(sx + width > 8)
	{
		return -1;
	}

	if(sy + height > 12)
	{
		return -2;
	}

	int xx,yy;

	for(y = 0; y < height; y ++)
	{

		yy = sy+y;

		for(x = 0; x < width; x++)
		{
			xx = sx + x;

			if(ExtentCheck(xx,yy,8,12)==1)
			{
				if(*(BYTE*)(gObj[aIndex].pInventoryMap+(sy+y)*8+(sx+x)) != 255)
				{
					blank += 1;
					return -1;
				}
			}
			else
			{
				LogAdd("error : %s %d",__FILE__,__LINE__);
				return -1;
			}
		}
	}

	if(blank == 0)
	{
		return sx+sy*8+12;
	}
	return  -1;
}






BYTE gObjOnlyInventoryRectCheck(int aIndex, int sx, int sy, int width, int height)
{
	int x,y;
	int blank = 0;

	if(sx + width > 8)
	{
		return -1;
	}

	if(sy + height > 8)
	{
		return -2;
	}

	int xx,yy;

	for(y = 0; y < height; y ++)
	{

		yy = sy+y;

		for(x = 0; x < width; x++)
		{
			xx = sx + x;

			if(ExtentCheck(xx,yy,8,8)==1)
			{
				if(*(BYTE*)(gObj[aIndex].pInventoryMap+(sy+y)*8+(sx+x)) != 255)
				{
					blank += 1;
					return -1;
				}
			}
			else
			{
				LogAdd("error : %s %d",__FILE__,__LINE__);
				return -1;
			}
		}
	}

	if(blank == 0)
	{
		return sx+sy*8+12;
	}
	return  -1;
}


BOOL CheckInventoryEmptySpace(LPOBJ lpObj, int iItemHeight, int iItemWidth)
{
	int h=0;
	int w=0;
	BYTE blank = 0;
	
	for(h=0;h<8;h++)
	{
		for(w=0;w<8;w++)
		{
			if(*(BYTE*)(lpObj->pInventoryMap+(h)*8+(w)) == 255)
			{
				blank = gObjOnlyInventoryRectCheck(lpObj->m_Index, w, h, iItemWidth, iItemHeight);

				if ( blank == 0xFE )
					return FALSE;

				if ( blank != 0xFF )
					return TRUE;
			}
		}
	}

	return FALSE;
}



BOOL gObjIsItemPut(LPOBJ lpObj, CItem * lpItem, int pos )
{
	if(lpItem->m_TwoHand == 1)
	{
		if(pos == 0 || pos == 1)
		{
			if(lpObj->pInventory[0].IsItem() == 1)
			{
				if(lpObj->pInventory[0].m_Type == ITEMGET(4,7) || lpObj->pInventory[0].m_Type == ITEMGET(4,15))
				{
					
				}
				else
				{
					return false;
				}
			}

			if(lpObj->pInventory[1].IsItem() == 1)
			{
				if(lpObj->pInventory[1].m_Type == ITEMGET(4,7) || lpObj->pInventory[1].m_Type == ITEMGET(4,15))
				{
					
				}
				else
				{
					return false;
				}
			}
		}
	}

	if(pos == 1)
	{
		if(lpObj->pInventory[0].IsItem() == 1)
		{
			if(lpItem->m_Type == ITEMGET(4,7) || lpItem->m_Type == ITEMGET(4,15))
			{
					
			}
			else
			{
				if(lpObj->pInventory[0].m_TwoHand)
				{
					return false;
				}
			}
		}
	}

	if(lpItem->m_Part != pos)
	{
		if(pos == 1 || pos == 0)
		{
			if(lpItem->m_Part == 1 || lpItem->m_Part == 0)
			{

			}
			else
			{
				return false;
			}
		}
		else if(pos == 11)
		{
			if(lpItem->m_Part == 10)
			{

			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	if((lpObj->Strength + lpObj->AddStrength) < (lpItem->m_RequireStrength - lpItem->m_HJOpStrength))
	{
		return false;
	}

	if((lpObj->Dexterity + lpObj->AddDexterity) < (lpItem->m_RequireDexterity - lpItem->m_HJOpDexterity))
	{
		return false;
	}

	if(lpObj->Level < lpItem->m_RequireLevel)
	{
		return false;
	}

	if(lpItem->m_Type >= 0 && lpItem->m_Type < ITEMGET(12,0))
	{
		if((lpObj->Vitality + lpObj->AddVitality) < lpItem->m_RequireVitality)
		{
			return false;
		}

		if((lpObj->Energy + lpObj->AddEnergy) < lpItem->m_RequireEnergy)
		{
			return false;
		}
	}

	if((lpObj->Leadership + lpObj->AddLeadership) < lpItem->m_RequireLeaderShip)
	{
		return false;
	}

	if(lpItem->m_Type >= ITEMGET(12,0) && lpItem->m_Type <= ITEMGET(12,6))
	{
		if(lpObj->Level < lpItem->m_RequireLevel)
		{
			return false;
		}
	}

    if(lpItem->m_Type >= ITEMGET(12,36) && lpItem->m_Type <= ITEMGET(12,40))
    {
            if(lpObj->Level < lpItem->m_RequireLevel)
            {
                    return false;
            }
    }

	else if(lpItem->m_Type >= ITEMGET(13,0) && lpItem->m_Type <= ITEMGET(13,15))
	{
		if(lpItem->m_Type == ITEMGET(13,10))
		{
			if(lpItem->m_Level <= 2)
			{
				if(lpObj->Level < 20)
				{
					return false;
				}
			}
			else
			{
				if(lpObj->Level < 50)
				{
					return false;
				}
			}
		}
		else if(lpItem->m_Type == ITEMGET(13,2))
		{
			if(lpObj->MapNumber == 7 || lpObj->Level < lpItem->m_RequireLevel)
			{
				return false;
			}
		}
		else if(lpItem->m_Type == ITEMGET(13,3))
		{
			if(lpObj->MapNumber == 7 || lpObj->Level < lpItem->m_RequireLevel)
			{
				return false;
			}
		}
		else
		{
			if(lpObj->Level < lpItem->m_RequireLevel)
			{
				return false;
			}
		}
	}

	if(lpItem->m_Type == ITEMGET(13,20) && lpItem->m_Level == 0)
	{
		int count = gObjGetItemCountInEquipment(lpObj->m_Index,13,20,0);

		if(count != 0)
		{
			return false;
		}
	}

	if(lpItem->m_Type == ITEMGET(13,10))
	{
		if(CC_MAP_RANGE(lpObj->MapNumber))
		{
			return false;
		}
	}

	if(lpItem->m_Type == ITEMGET(13,37))
	{
		if(CC_MAP_RANGE(lpObj->MapNumber))
		{
			return false;
		}
	}

	if(lpItem->m_Type == ITEMGET(13,38))
	{
		int count = gObjGetItemCountInEquipment(lpObj->m_Index,13,38,0);

		if(count != 0)
		{
			return false;
		}
	}

	if(lpItem->m_Type == ITEMGET(13,39))
	{
		if(CC_MAP_RANGE(lpObj->MapNumber))
		{
			return false;
		}

		int count = 0;

		for(int n = 0; n < 7; n++)
		{
			count = gObjGetItemCountInEquipment(lpObj->m_Index,13,10,n);

			if(count != 0)
			{
				return false;
			}
		}

		count = gObjGetItemCountInEquipment(lpObj->m_Index,13,39,0);

		if(count != 0)
		{
			return false;
		}

        count = gObjGetItemCountInEquipment(lpObj->m_Index,13,40,0);

        if(count != 0)
        {
                return false;
        }

        count = gObjGetItemCountInEquipment(lpObj->m_Index,13,41,0);

        if(count != 0)
        {
                return false;
        }

        count = gObjGetItemCountInEquipment(lpObj->m_Index,13,42,0);

        if(count != 0)
        {
                return false;
        }

	}

    if(lpItem->m_Type == ITEMGET(13,40))
    {
            if(CC_MAP_RANGE(lpObj->MapNumber))
            {
                    return false;
            }

            int count = 0;

            for(int n = 0; n < 7; n++)
            {
                    count = gObjGetItemCountInEquipment(lpObj->m_Index,13,10,n);

                    if(count != 0)
                    {
                            return false;
                    }
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,39,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,40,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,41,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,42,0);

            if(count != 0)
            {
                    return false;
            }
    }

    if(lpItem->m_Type == ITEMGET(13,41))
    {
            if(CC_MAP_RANGE(lpObj->MapNumber))
            {
                    return false;
            }

            int count = 0;

            for(int n = 0; n < 7; n++)
            {
                    count = gObjGetItemCountInEquipment(lpObj->m_Index,13,10,n);

                    if(count != 0)
                    {
                            return false;
                    }
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,39,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,40,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,41,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,42,0);

            if(count != 0)
            {
                    return false;
            }
    }

    if(lpItem->m_Type == ITEMGET(13,42))
    {
            if(CC_MAP_RANGE(lpObj->MapNumber))
            {
                    return false;
            }

            int count = 0;

            for(int n = 0; n < 7; n++)
            {
                    count = gObjGetItemCountInEquipment(lpObj->m_Index,13,10,n);

                    if(count != 0)
                    {
                            return false;
                    }
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,39,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,40,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,41,0);

            if(count != 0)
            {
                    return false;
            }

            count = gObjGetItemCountInEquipment(lpObj->m_Index,13,42,0);

            if(count != 0)
            {
                    return false;
            }
    }

	if(lpItem->m_Type == ITEMGET(13,10))
	{
		int count = 0;

		for(int n = 0; n < 7; n ++)
		{
			count = gObjGetItemCountInEquipment(lpObj->m_Index,13,10,n);

			if(count != 0)
			{
				return false;
			}
		}

		count = gObjGetItemCountInEquipment(lpObj->m_Index,13,39,0);
                
        if(count != 0)
        {
                return false;
        }

        count = gObjGetItemCountInEquipment(lpObj->m_Index,13,40,0);
                
        if(count != 0)
        {
                return false;
        }

        count = gObjGetItemCountInEquipment(lpObj->m_Index,13,41,0);
                
        if(count != 0)
        {
                return false;
        }

        count = gObjGetItemCountInEquipment(lpObj->m_Index,13,42,0);
                
        if(count != 0)
        {
                return false;
        }
	}
	else if(lpItem->m_Type >= ITEMGET(14,00))
	{
		return false;
	}

	return true;
}






BYTE gObjWerehouseRectCheck(int aIndex, int sx, int sy, int width, int height)
{
	int x,y;
	int blank = 0;

	if(sx + width > 8)
	{
		return -1;
	}

	if(sx + width < 0)
	{
		return -1;
	}

	if(sy + height > 15)
	{
		return -1;
	}

	if(sy + height < 0)
	{
		return -1;
	}

	int xx,yy;

	LPOBJ lpObj = &gObj[aIndex];

	for(y = 0; y < height; y ++)
	{

		yy = sy+y;

		for(x = 0; x < width; x++)
		{
			xx = sx + x;

			if(ExtentCheck(xx,yy,8,15)==1)
			{
				if(*(BYTE*)(gObj[aIndex].pWarehouseMap+(sy+y)*8+(sx+x)) != 255)
				{
					blank += 1;
					return -1;
				}
			}
			else
			{
				LogAdd("error : %s %d",__FILE__,__LINE__);
				return -1;
			}
		}
	}

	if(blank == 0)
	{
		return sx+sy*8;
	}
	return  -1;
}






BYTE gObjMapRectCheck(BYTE * lpMapBuf, int sx, int sy, int ex, int ey, int width, int height)
{
	int x,y;
	int blank = 0;

	if(sx + width > ex || sx + width < 0)
	{
		return -1;
	}

	if(sy + height > ey || sy + height < 0)
	{
		return -1;
	}

	int xx,yy;

	for(y = 0; y < height; y++)
	{
		yy = sy + y;

		for(x = 0; x < width; x++)
		{
			xx = sx + x;

			if(ExtentCheck(xx,yy,ex,ey)==1)
			{
				if(*(BYTE*)(lpMapBuf + (sy + y)*ex + (sx+x)) != 255)
				{
					blank += 1;
					return -1;
				}
			}
			else
			{
				LogAdd("error : %s %d",__FILE__,__LINE__);
				return -1;
			}
		}
	}

	if(blank == 0)
	{
		return sy*ex+sx;
	}
	return  -1;

	return -1;
}






void gObjWarehouseItemBoxSet(int aIndex, int itempos, int xl, int yl, BYTE set_byte)
{
	int itemposx = (itempos)%8;
	int itemposy = (itempos)/8;

	int xx,yy;

	for(int y = 0; y < yl; y ++)
	{
		yy = itemposy + y;

		for(int x = 0; x < xl; x++)
		{
			xx = itemposx + x;

			if(ExtentCheck(xx,yy,8,15)==1)
			{
				*(BYTE*)(gObj[aIndex].pWarehouseMap + (itemposy + y)*8+(itemposx + x)) = set_byte;
			}
			else
			{
				LogAdd("error : %d/%d  %s %d",xx,yy,__FILE__,__LINE__);
				return;
			}
		}
	}
}






void gObjWarehouseItemSet(int aIndex, int itempos, BYTE set_byte)
{
	int width;
	int height;
	if(itempos < 0)
	{
		return;
	}
	else if(itempos > (WAREHOUSE_SIZE-1))
	{
		return;
	}

	if(gObj[aIndex].pWarehouse[itempos].GetSize((int&)width,(int &)height)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return;
	}

	gObjWarehouseItemBoxSet(aIndex,itempos,width,height,set_byte);
}






void gObjChaosItemBoxSet(int aIndex, int itempos, int xl, int yl, BYTE set_byte)
{
	int itemposx = (itempos)%8;
	int itemposy = (itempos)/8;

	int xx,yy;

	for(int y = 0; y < yl; y ++)
	{
		yy = itemposy + y;

		for(int x = 0; x < xl; x++)
		{
			xx = itemposx + x;

			if(ExtentCheck(xx,yy,8,4)==1)
			{
				*(BYTE*)(gObj[aIndex].pChaosBoxMap + (itemposy + y)*8+(itemposx + x)) = set_byte;
			}
			else
			{
				LogAdd("error : %d/%d  %s %d",xx,yy,__FILE__,__LINE__);
				return;
			}
		}
	}
}






void gObjChaosItemSet(int aIndex, int itempos, BYTE set_byte)
{
	int width;
	int height;
	if(itempos < 0)
	{
		return;
	}
	else if(itempos > (CHAOS_BOX_SIZE-1))
	{
		return;
	}

	if(gObj[aIndex].pChaosBox[itempos].GetSize((int&)width,(int &)height)==0)
	{
		LogAdd("error : Item doesn't exist %s %d",__FILE__,__LINE__);
		return;
	}

	gObjChaosItemBoxSet(aIndex,itempos,width,height,set_byte);
}






BYTE gObjChaosBoxInsertItemPos(int aIndex, CItem item, int pos, int source)
{

	LPOBJ lpObj;
	BYTE TempMap[CHAOS_BOX_MAP_SIZE];

	int w,h,iwidth,iheight;

	int blank,useClass;

	if(pos < 0 || pos > (CHAOS_BOX_SIZE-1))
	{
		return -1;
	}

	useClass = 0;

	lpObj = &gObj[aIndex];

	if(lpObj->pChaosBox[pos].IsItem() == 1)
	{
		return -1;
	}

	if(item.IsItem() == 0)
	{
		return -1;
	}

	w = pos%8;
	h = pos/8;

	if(ExtentCheck(w,h,8,4) == 0)
	{
		return -1;
	}

	item.GetSize((int &)iwidth,(int &)iheight);

	if(source >= 0)
	{
		memcpy(TempMap,lpObj->pChaosBoxMap,CHAOS_BOX_MAP_SIZE);
		gObjChaosItemBoxSet(lpObj->m_Index,source,iwidth,iheight,255);
	}

	if(*(BYTE*)(lpObj->pChaosBoxMap + h * 8 + w) != 255)
	{
		if(source >= 0)
		{
			memcpy(lpObj->pChaosBoxMap,TempMap,CHAOS_BOX_MAP_SIZE);
		}
		return -1;
	}

	blank = gObjMapRectCheck(lpObj->pChaosBoxMap,w,h,8,4,iwidth,iheight);

	if(blank == 255)
	{
		if(source >= 0)
		{
			memcpy(lpObj->pChaosBoxMap,TempMap,CHAOS_BOX_MAP_SIZE);
		}
		return -1;
	}

	lpObj->pChaosBox[pos] = item;
	return pos;
}






BYTE gObjWarehouseInsertItemPos(int aIndex, CItem item, int pos, int source)
{
	LPOBJ lpObj;
	BYTE TempMap[WAREHOUSE_SIZE];

	int w,h,iwidth,iheight;

	int blank,useClass;

	if(pos < 0 || pos > (WAREHOUSE_SIZE-1))
	{
		return -1;
	}

	useClass = 0;

	lpObj = &gObj[aIndex];

	if(lpObj->pWarehouse[pos].IsItem() == 1)
	{
		return -1;
	}

	if(item.IsItem() == 0)
	{
		return -1;
	}

	w = pos%8;
	h = pos/8;

	if(ExtentCheck(w,h,8,15) == 0)
	{
		return -1;
	}

	item.GetSize((int &)iwidth,(int &)iheight);

	if(source >= 0)
	{
		memcpy(TempMap,lpObj->pWarehouseMap,WAREHOUSE_SIZE);
		gObjWarehouseItemBoxSet(lpObj->m_Index,source,iwidth,iheight,255);
	}

	if(*(BYTE*)(lpObj->pWarehouseMap + h * 8 + w) != 255)
	{
		if(source >= 0)
		{
			memcpy(lpObj->pWarehouseMap,TempMap,WAREHOUSE_SIZE);
		}
		return -1;
	}

	blank = gObjWerehouseRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

	if(blank == 255)
	{
		if(source >= 0)
		{
			memcpy(lpObj->pWarehouseMap,TempMap,WAREHOUSE_SIZE);
		}
		return -1;
	}

	lpObj->pWarehouse[pos] = item;
	return pos;
}






BYTE gObjInventoryInsertItemPos(int aIndex, CItem item, int pos, BOOL RequestCheck)
{
	if(pos < 0 || pos > INVENTORY_SIZE)
	{
		return -1;
	}

	LPOBJ lpObj;
	BYTE TempInventoryMap[INVENTORY_MAP_SIZE];

	int w,h,iwidth,iheight;

	int blank,useClass = 0;

	lpObj = &gObj[aIndex];

	if(lpObj->pInventory[pos].IsItem() == 1)
	{
		return -1;
	}

	if(item.IsItem() == 0)
	{
		return -1;
	}

	if(pos < 12)
	{
		useClass = item.IsClass((char)lpObj->Class,lpObj->ChangeUP);

		if(useClass == 0)
		{
			LogAdd("error-L2: It's not his class %s %d", __FILE__, __LINE__);
			return -1;
		}

		if(RequestCheck != 0)
		{
			if(gObjIsItemPut(lpObj,&item,pos) == 0)
			{
				return -1;
			}
		}
	}
	else
	{
		w = (pos - 12)%8;
		h = (pos - 12)/8;

		if(ExtentCheck(w,h,8,12)==0)
		{
			return -1;
		}

		memcpy(TempInventoryMap,lpObj->pInventoryMap,INVENTORY_MAP_SIZE);
		item.GetSize((int &)iwidth,(int &)iheight);

		if(*(BYTE*)(lpObj->pInventoryMap + h * 8 + w) != 255 )
		{
			memcpy(lpObj->pInventoryMap,TempInventoryMap,INVENTORY_MAP_SIZE);
			return -1;
		}

		blank = gObjInventoryRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

		if(blank >= 254)
		{
			memcpy(lpObj->pInventoryMap,TempInventoryMap,INVENTORY_MAP_SIZE);
			return false;
		}
	}

	lpObj->pInventory[pos] = item;

	if(pos > 11)
	{
		gObjInventoryItemSet(aIndex,pos,1);
	}

	if(pos < 12)
	{
		CItem * lpItem = &lpObj->pInventory[pos];

		if(lpItem->m_Option1)
		{
			int result = gObjWeaponMagicAdd(lpObj,lpItem->m_Special[0],(BYTE)lpItem->m_Level);

			if(result >= 0)
			{
				GCMagicListOneSend(lpObj->m_Index,result,lpItem->m_Special[0],(BYTE)lpItem->m_Level,0,0);
			}
		}
	}
	return pos;
}






BOOL gObjInventorySearchSerialNumber(LPOBJ lpObj, DWORD serial)
{
	int s_num;
	int count = 0;

	if(gItemSerialCheck == 0)
	{
		return true;
	}

	if(serial == 0)
	{
		return true;
	}

	for(int n = 0; n < INVENTORY_SIZE; n++)
	{
		s_num = lpObj->pInventory[n].GetNumber();

		if(s_num != 0 && s_num == serial)
		{
			count++;
		}
	}

	if(count <= 1)
	{
		return true;
	}

	for(int n = 0; n < INVENTORY_SIZE; n++)
	{
		s_num = lpObj->pInventory[n].GetNumber();

		if(s_num != 0 && s_num == serial)
		{
			LogAdd("error-L1:CopyItem Id[%s] Char[%s] Item(%s) InventoryPos(%d) serial(%d)",lpObj->AccountID,lpObj->Name,lpObj->pInventory[n].GetName(),n,s_num);
			GCServerMsgStringSend("This is an illegal duplicated item. Please Report this to a GM.",lpObj->m_Index,1);
			gObjUserKill(lpObj->m_Index);
		}
	}

	return false;
}






BOOL gObjWarehouseSearchSerialNumber(LPOBJ lpObj, DWORD sirial)
{
int s_num;
	int count = 0;

	if(gItemSerialCheck == 0)
	{
		return true;
	}

	if(sirial == 0)
	{
		return true;
	}

	for(int n = 0; n < WAREHOUSE_SIZE; n++)
	{
		s_num = lpObj->pWarehouse[n].GetNumber();

		if(s_num != 0 && s_num == sirial)
		{
			count++;
		}
	}

	if(count <= 1)
	{
		return true;
	}

	for(int n = 0; n < WAREHOUSE_SIZE; n++)
	{
		s_num = lpObj->pWarehouse[n].GetNumber();

		if(s_num != 0 && s_num == sirial)
		{
			LogAdd("error-L1:CopyItem Id[%s] Char[%s] Item(%s) warehousepos(%d) sirial(%d)",lpObj->AccountID,lpObj->Name,lpObj->pWarehouse[n].GetName(),n,s_num);
			GCServerMsgStringSend("This is an illegal duplicated item. Please Report this to a GM.",lpObj->m_Index,1);
			gObjUserKill(lpObj->m_Index);
		}
	}

	return false;
}






BYTE gObjInventoryMoveItem(int aIndex, unsigned char source, unsigned char target, int& durSsend, int& durTsend, unsigned char sFlag, unsigned char tFlag, unsigned char* siteminfo)
{
	LPOBJ lpObj;
	BYTE TempInventoryMap[64];
	int w,h;
	int iwidth,iheight;
	int blank;
	int s_num;

	CItem * sitem;
	CItem * titem;

	int bPersonalShopTrans = 0;
	int bSourceIsPShop = 0;

	durSsend = 0;
	durTsend = 0;

	lpObj = &gObj[aIndex];

	int useClass = 0;
	__try
	{
		if(sFlag == 2 || tFlag == 2)
		{
			if(lpObj->m_IfState.type != 6)
			{
				LogAdd("He is not using warehouse. [%s][%s].",lpObj->AccountID,lpObj->Name);
				return -1;
			}

			if(lpObj->m_IfState.state == 0)
			{
				LogAdd("He is not using warehouse. [%s][%s].",lpObj->AccountID,lpObj->Name);
				return -1;
			}
		}

		switch(sFlag)
		{
		case 0:
			if(source < 0 || source > (MAIN_INVENTORY_SIZE-1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			if(lpObj->pInventory[source].IsItem() == 0)
			{
				LogAdd("Item doesn't exist. [%s][%s] %s %d",lpObj->AccountID,lpObj->Name,__FILE__, __LINE__);
				return -1;
			}

			sitem = &lpObj->pInventory[source];

			if(lpObj->MapNumber == MAP_INDEX_ICARUS)
			{
				if(source == 8)
				{
					if(sitem->m_Type == ITEMGET(13,3))
					{
						if(lpObj->pInventory[7].IsItem() == 0)
						{
							return -1;
						}
					}
					else if(sitem->m_Type == ITEMGET(13,37))
					{
						if(lpObj->pInventory[7].IsItem() == 0)
						{
							return -1;
						}
					}
				}
				else if(source == 7)
				{
					if(lpObj->pInventory[8].m_Type != ITEMGET(13,3))
					{
						return -1;
					}
				}
			}

			break;
		case 2:
			if(source < 0 || source > (WAREHOUSE_SIZE-1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			if(lpObj->pWarehouse[source].IsItem() == 0)
			{
				LogAdd("Item doesn't exist. [%s][%s] %s %d",lpObj->AccountID,lpObj->Name,__FILE__, __LINE__);
				return -1;
			}

			sitem = &lpObj->pWarehouse[source];
			break;
		case 3:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			if(source < 0 || source > (CHAOS_BOX_SIZE -1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			if(lpObj->pChaosBox[source].IsItem() == 0)
			{
				LogAdd("Item doesn't exist. [%s][%s] %s %d",lpObj->AccountID,lpObj->Name,__FILE__, __LINE__);
				return -1;
			}

			sitem = &lpObj->pChaosBox[source];
			break;
		case 4:
			if(gObj[aIndex].m_bPShopOpen == 1)
			{
				return -1;
			}

			EnterCriticalSection(&gObj[aIndex].m_critPShopTrade);

			if(gObj[aIndex].m_bPShopTransaction == 1)
			{
				LogAdd("[PShop] [%s][%s] PShop Item Move Request Failed : Already Trade With Other",gObj[aIndex].AccountID,gObj[aIndex].Name);
				LeaveCriticalSection(&lpObj->m_critPShopTrade);
				return -1;
			}

			lpObj->m_bPShopTransaction = 1;
			bPersonalShopTrans = 1;
			bSourceIsPShop = 1;

			LeaveCriticalSection(&lpObj->m_critPShopTrade);

			if(source < MAIN_INVENTORY_SIZE || source > (INVENTORY_SIZE - 1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			if(lpObj->pInventory[source].IsItem() == 0)
			{
				LogAdd("Item doesn't exist. [%s][%s] %s %d",lpObj->AccountID,lpObj->Name,__FILE__, __LINE__);
				return -1;
			}

			sitem = &lpObj->pInventory[source];

			break;
		default: return -1;
		}

		BYTE level;
		BYTE op1;
		BYTE op2;
		BYTE op3;
		BYTE dur;
		int type;

		BufferItemtoConvert3(siteminfo,(int &)type,(BYTE &)level,(BYTE &)op1,(BYTE &)op2,(BYTE &)op3,(BYTE &)dur);

		op3=sitem->m_Option3;//damn WZ security... need to do this for move items + 28

		if(sitem->m_Type != type || sitem->m_Level != level || sitem->m_Option1 != op1 || sitem->m_Option2 != op2 || sitem->m_Option3 != op3)
		{
			LogAdd("Item information doesn't not match. %x %x %x %x %x/ %x %x %x %x %x",type,level,op1,op2,op3,sitem->m_Type,sitem->m_Level,sitem->m_Option1,sitem->m_Option2,sitem->m_Option3);
			return -1;
		}

		switch(tFlag)
		{
		case 0:
			if(target < 0 || target > (MAIN_INVENTORY_SIZE - 1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			titem = &lpObj->pInventory[target];
			break;
		case 2:
			if(target < 0 || target > (WAREHOUSE_SIZE - 1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			titem = &lpObj->pWarehouse[target];
			break;
		case 3:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			if(target < 0 || target > (CHAOS_BOX_SIZE -1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			titem = &lpObj->pChaosBox[target];

			if(sFlag == 0)
			{
				if(tFlag == 5)
				{
					if(sitem->m_Type == ITEMGET(12,15)	||
						sitem->m_Type == ITEMGET(14,13) ||
						sitem->m_Type == ITEMGET(14,14) ||
						sitem->m_Type == ITEMGET(14,16) ||
						sitem->m_Type == ITEMGET(14,22) ||
						sitem->m_Type == ITEMGET(13,31) ||
						sitem->m_Type == ITEMGET(14,53))
					{

					}
					else
					{
						return -1;
					}
				}
				else if(tFlag == 6)
				{
					if(g_kJewelOfHarmonySystem.IsJewelOfHarmonyOriginal(sitem->m_Type) == 0)
					{
						return -1;
					}
				}
				else if(tFlag == 7)
				{
					if(g_kJewelOfHarmonySystem.IsEnableToMakeSmeltingStoneItem(sitem) == 0)
					{
						GCServerMsgStringSend("The goods which is not smelts when fossil uses.",lpObj->m_Index,1);
						return -1;
					}
				}
				else if(tFlag == 8)
				{
					if(g_kJewelOfHarmonySystem.IsStrengthenByJewelOfHarmony(sitem) == 0)
					{
						return -1;
					}
				}
				else if(tFlag == 9)
				{
					if(sitem->m_Type != ITEMGET(14,54))
					{
						return -1;
					}
				}
				else
				{
					if(sitem->m_Level < 4 && sitem->m_Option3*4 < 4)
					{
                        if(sitem->m_Type == ITEMGET(12,15) || sitem->m_Type == ITEMGET(14,13) || sitem->m_Type == ITEMGET(14,14) || sitem->m_Type == ITEMGET(14,16) || sitem->m_Type == ITEMGET(14,22) || sitem->m_Type == ITEMGET(13,14))
                        {
                                                        
                        }
                        else if(sitem->m_Type >= ITEMGET(12,0) && sitem->m_Type <= ITEMGET(12,2))
                        {

                        }
                        else if(sitem->m_Type >= ITEMGET(12,36) && sitem->m_Type <= ITEMGET(12,40))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(14,17) || sitem->m_Type == ITEMGET(14,18))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(13,49) || sitem->m_Type == ITEMGET(13,50))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(13,2) && sitem->m_Durability == 255.0f)
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(13,16) || sitem->m_Type == ITEMGET(13,17))

                        {

                        }

                        else if(sitem->m_Type == ITEMGET(14,31))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(12,26))
                        {

                        }
                        else if(
                                sitem->m_Type == ITEMGET(12,30) ||
                                sitem->m_Type == ITEMGET(12,31) ||
                                sitem->m_Type == ITEMGET(13,32) ||
                                sitem->m_Type == ITEMGET(13,33) ||
                                sitem->m_Type == ITEMGET(13,34) ||
                                sitem->m_Type == ITEMGET(13,35) ||
                                sitem->m_Type == ITEMGET(13,36) ||
                                sitem->m_Type == ITEMGET(13,37) ||
                                sitem->m_Type == ITEMGET(13,51) ||
                                sitem->m_Type == ITEMGET(13,52) ||
                                sitem->m_Type == ITEMGET(13,53)
                                )
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(14,3) || sitem->m_Type == ITEMGET(14,38) || sitem->m_Type == ITEMGET(14,39))
                        {

                        }
                        else if(g_kJewelOfHarmonySystem.IsJewelOfHarmonyPurity(sitem->m_Type) == 1)
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(12,30))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(12,31))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(13,51))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(13,52))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(13,53))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(14,31))
                        {

                        }
                        else if(sitem->m_Type == ITEMGET(14,53))
                        {

                        }
                        else
                        {
                                return -1;
                        }
					}
				}
			}
			break;
		case 4:
			if(gDoPShopOpen == 0)
			{
				return -1;
			}

			if(gObj[aIndex].m_bPShopOpen == 1)
			{
				return -1;
			}

			if(sitem->m_Type == ITEMGET(14,11) && sitem->m_Level == 13)
			{
				return -1;
			}

			if(g_kJewelOfHarmonySystem.IsStrengthenByJewelOfHarmony(sitem) == 1)
			{
				GCServerMsgStringSend("The strengthened goods are unable to use individual store.",lpObj->m_Index,1);
				return -1;
			}

			/*if(IsCashItem(sitem->m_Type) == 1)
			{
				return -1;
			}*/

			if(sitem->m_Type == ITEMGET(13,38))
			{
				GCServerMsgStringSend("Hangs the stone to be unable to use individual store.",lpObj->m_Index,1);
				return -1;
			}

			if(sitem->m_Type == ITEMGET(13,39))
			{
				return -1;
			}

			EnterCriticalSection(&gObj[aIndex].m_critPShopTrade);

			if(gObj[aIndex].m_bPShopTransaction == 1)
			{
				if(bSourceIsPShop == 1)
				{
					lpObj->m_bPShopTransaction = 1;
					bPersonalShopTrans = 1;
				}
				else
				{
					LogAdd("[PShop] [%s][%s] PShop Item Move Request Failed : Already Trade With Other",gObj[aIndex].AccountID,gObj[aIndex].Name);
					LeaveCriticalSection(&lpObj->m_critPShopTrade);
					return -1;
				}
			}
			else
			{
				lpObj->m_bPShopTransaction = 1;
				bPersonalShopTrans = 1;
			}

			LeaveCriticalSection(&lpObj->m_critPShopTrade);

			if(target < MAIN_INVENTORY_SIZE || target > (INVENTORY_SIZE - 1))
			{
				LogAdd("error-L1 : %s %d",__FILE__,__LINE__);
				return -1;
			}

			titem = &lpObj->pInventory[target];

			break;
		default: return -1;
		}

		s_num = sitem->GetNumber();

		if(gObjCheckSerial0ItemList(sitem))
		{
			MsgOutput(lpObj->m_Index,"Unable to use");
			LogAdd("[ANTI-HACK][Serial 0 Item] [MoveItem] (%s)(%s) Item(%s) Pos(%d)",lpObj->AccountID,lpObj->Name,sitem->GetName(),source);
			return -1;
		}

		if(gObjInventorySearchSerialNumber(lpObj,s_num) == 0)
		{
			return -1;
		}

		if(gObjWarehouseSearchSerialNumber(lpObj,s_num) == 0)
		{
			return -1;
		}

		if(titem->IsItem() == 1)
		{
			int max_count = 0;

			if(sitem->m_Type == ITEMGET(13,32) && titem->m_Durability < 20.0f)
			{
				max_count = 20;
			}

			if(sitem->m_Type == ITEMGET(13,33) && titem->m_Durability < 20.0f)
			{
				max_count = 20;
			}

			if(sitem->m_Type == ITEMGET(13,34) && titem->m_Durability < 10.0f)
			{
				max_count = 10;
			}

			if(sitem->m_Type >= ITEMGET(14,35) || sitem->m_Type >= ITEMGET(14,36) || sitem->m_Type >= ITEMGET(14,37))
			{
				if(titem->m_Durability < 1.0f)
				{
					max_count = 1;
				}
			}

			if(sitem->m_Type >= ITEMGET(14,46) && sitem->m_Type <= ITEMGET(14,50))
			{
				if(titem->m_Durability < 3.0f)
				{
					max_count = 3;
				}
			}

			if(sitem->m_Type == ITEMGET(14,29))
			{
				if(sitem->m_Level == titem->m_Level)
				{
					max_count = 5;
				}
			}

			if(sitem->m_Type == ITEMGET(14,7))
			{
				if(titem->m_Durability < 250.0f)
				{
					max_count = 250;
				}
			}
			else if(sitem->m_Type >= ITEMGET(14,0) && sitem->m_Type <= ITEMGET(14,8) || sitem->m_Type >= ITEMGET(14,38) && sitem->m_Type <= ITEMGET(14,40))//POTIONS
			{
				if(titem->m_Durability < MaxPotionDurability)
				{
					max_count = MaxPotionDurability;
				}
			}
			else if(sitem->m_Type == ITEMGET(4,15) || sitem->m_Type == ITEMGET(4,7))
			{
				if(titem->m_Durability < 255.0f)
				{
					max_count = 255;
				}
			}

			if(max_count != 0)
			{
				if(sFlag != 0)
				{
					return -1;
				}

				if(titem->m_Type == sitem->m_Type && titem->m_Level == sitem->m_Level)
				{
					int t_dur = (int)titem->m_Durability;

					if(t_dur < max_count)
					{
						int dif_dur = max_count - int(titem->m_Durability);

						if(dif_dur > sitem->m_Durability)
						{
							dif_dur = (int)sitem->m_Durability;
						}

						titem->m_Durability += dif_dur;
						sitem->m_Durability -= dif_dur;

						if(titem->m_Type == ITEMGET(14,29) && max_count <= titem->m_Durability)
						{
							titem->m_Durability -= max_count;

							if(titem->m_Durability == 0)
							{
								gObjInventoryItemSet(aIndex,target,255);
								gObj[aIndex].pInventory[target].Clear();
								GCInventoryItemDeleteSend(aIndex,target,1);
								durTsend = 0;
							}
							else
							{
								durTsend = 1;
							}

							ItemSerialCreateSend(aIndex,235,(BYTE)gObj[aIndex].X,(BYTE)gObj[aIndex].Y,ItemGetNumberMake(14,28),(BYTE)sitem->m_Level,0,0,0,0,aIndex,0,0);
						}

						if(sitem->m_Durability > 0)
						{
							durSsend = 1;
							durTsend = 1;
						}
						else
						{
							switch(sFlag)
							{
							case 0:
								gObjInventoryItemSet(lpObj->m_Index,source,255);
								sitem->Clear();
								GCInventoryItemDeleteSend(lpObj->m_Index,source,0);
								durTsend = 1;
							default:	return 0;
							}
						}
					}
				}
			}
			return -1;
		}

		switch(tFlag)
		{
		case 0:
		case 4:
			if(target < INVETORY_WEAR_SIZE)
			{
				if(lpObj->MapNumber == MAP_INDEX_ICARUS)
				{
					if(target == 10)
					{
						if(lpObj->pInventory[source].m_Type == ITEMGET(13,10))
						{
							return -1;
						}
					}
					else if(target == 11)
					{
						if(lpObj->pInventory[source].m_Type == ITEMGET(13,10))
						{
							return -1;
						}
					}
                    if(target == 10)
                    {
                            if(lpObj->pInventory[source].m_Type == ITEMGET(13,40))
                            {
                                    return -1;
                            }
                    }
                    else if(target == 11)
                    {
                            if(lpObj->pInventory[source].m_Type == ITEMGET(13,40))
                            {
                                    return -1;
                            }
                    }
				}

				if(target < INVETORY_WEAR_SIZE)
				{
					if(lpObj->MapNumber == MAP_INDEX_ICARUS || lpObj->MapNumber == MAP_INDEX_KANTURU_BOSS)
					{
						if(target == 10)
						{
							if(lpObj->pInventory[source].m_Type == ITEMGET(13,39) || lpObj->pInventory[source].m_Type == ITEMGET(13,40) ||
								lpObj->pInventory[source].m_Type == ITEMGET(13,10))
							{
								return -1;
							}
						}
						else if(target == 11)
						{
							if(lpObj->pInventory[source].m_Type == ITEMGET(13,39) || lpObj->pInventory[source].m_Type == ITEMGET(13,40) ||
								lpObj->pInventory[source].m_Type == ITEMGET(13,10))
							{
								return -1;
							}
						}
					}
				}

				useClass = sitem->IsClass((char)lpObj->Class,lpObj->ChangeUP);

				if(useClass == 0)
				{
					return -1;
				}

				if(gObjIsItemPut(lpObj,sitem,target) == 0)
				{
					return -1;
				}
			}
			else 
			{
				if(target >= MAIN_INVENTORY_SIZE)
				{
					if(lpObj->pInventory[source].m_Type == ITEMGET(12,26))
					{
						if(lpObj->pInventory[source].m_Level == 1 ||
							lpObj->pInventory[source].m_Level == 2 ||
							lpObj->pInventory[source].m_Level == 3 ||
							lpObj->pInventory[source].m_Level == 4 ||
							lpObj->pInventory[source].m_Level == 5)
						{
							return -1;
						}
					}	
				}

				w = (target - INVETORY_WEAR_SIZE)%8;
				h = (target - INVETORY_WEAR_SIZE)/8;

				if(ExtentCheck(w,h,8,12) == 0)
				{
					return -1;
				}

			sitem->GetSize((int &)iwidth,(int &)iheight);
			memcpy(TempInventoryMap,lpObj->pInventoryMap,64);

				switch(sFlag)
				{
				case 0:
				case 4:
					if(source > (INVETORY_WEAR_SIZE - 1))
					{
						gObjInventoryItemBoxSet(lpObj->m_Index,source,iwidth,iheight,255);
					}
					break;
				default: break;
				}
			
			if(*(BYTE*)(gObj[aIndex].pInventoryMap + h * 8 + w) != 255)
			{
				memcpy(lpObj->pInventoryMap,TempInventoryMap,64);
				return -1;
			}

			blank = gObjInventoryRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

			if(blank >= 254)
			{
				memcpy(lpObj->pInventoryMap,TempInventoryMap,64);
				return -1;
			}
			}

			s_num = sitem->GetNumber();
			titem = sitem;

				switch(sFlag)
				{
				case 0:
				case 4:
					lpObj->pInventory[target] = lpObj->pInventory[source];
					gObjInventoryDeleteItem(aIndex,source);
					break;
				case 2:
					lpObj->pInventory[target] = lpObj->pWarehouse[source];
					gObjWarehouseDeleteItem(aIndex,source);
					break;
				case 3:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
					lpObj->pInventory[target] = lpObj->pChaosBox[source];
					gObjChaosBoxDeleteItem(aIndex,source);
					break;
				default : break;
				}

				if(target > (INVETORY_WEAR_SIZE - 1))
				{
					gObjInventoryItemSet(aIndex,target,1);
				}

				if(target < INVETORY_WEAR_SIZE)
				{
					CItem * lpItem = &lpObj->pInventory[target];
					if(lpItem->m_Option1)
					{
						int s_pos = gObjWeaponMagicAdd(&gObj[aIndex],lpItem->m_Special[0],(BYTE)lpItem->m_Level);
						if(s_pos >= 0)
						{
							GCMagicListOneSend(aIndex,s_pos,lpItem->m_Special[0],(BYTE)lpItem->m_Level,0,0);
						}
					}
				}
			break;
		case 2:
			BYTE res_1;
				switch(sFlag)
				{
				case 0:
					if(lpObj->pInventory[source].m_Type == ITEMGET(13,20))
					{
						if(lpObj->pInventory[source].m_Level == 0 ||
							lpObj->pInventory[source].m_Level == 1)
						{
							return -1;
						}
					}

					if(lpObj->pInventory[source].m_Type == ITEMGET(14,11))
					{
						if(lpObj->pInventory[source].m_Level == 13)
						{
							return -1;
						}
					}

					if(lpObj->pInventory[source].m_Type == ITEMGET(12,26))
					{
						if(lpObj->pInventory[source].m_Level == 1 ||
							lpObj->pInventory[source].m_Level == 2 ||
							lpObj->pInventory[source].m_Level == 3 ||
							lpObj->pInventory[source].m_Level == 4 ||
							lpObj->pInventory[source].m_Level == 5)
						{
							return -1;
						}
					}

					if(lpObj->pInventory[source].m_Type == ITEMGET(13,39))
					{
						return -1;
					}

					res_1 = gObjWarehouseInsertItemPos(aIndex,lpObj->pInventory[source],target,-1);
					break;
				case 2:
					res_1 = gObjWarehouseInsertItemPos(aIndex,lpObj->pWarehouse[source],target,source);
					break;
				default : break;
				}

				if(res_1 == 255)
				{
					return -1;
				}

				switch(sFlag)
				{
				case 0:
					lpObj->pWarehouse[target] = lpObj->pInventory[source];
					gObjInventoryDeleteItem(aIndex,source);
					break;
				case 2:
					lpObj->pWarehouse[target] = lpObj->pWarehouse[source];
					gObjWarehouseDeleteItem(aIndex,source);
					break;
				default : break;
				}

				gObjWarehouseItemSet(aIndex,target,1);

				if(sFlag == 0)
				{
					if(source < INVETORY_WEAR_SIZE)
					{
						if(source == 10 || source == 11)
						{
							if(lpObj->pWarehouse[target].m_Type == ITEMGET(13,10))
							{
								gObjUseSkill.SkillChangeUse(aIndex);
							}
							if(lpObj->pWarehouse[target].m_Type == ITEMGET(13,40))
							{
									gObjUseSkill.SkillChangeUse(aIndex);
							}
							if(lpObj->pWarehouse[target].m_Type == ITEMGET(13,41))
							{
									gObjUseSkill.SkillChangeUse(aIndex);
							}
							if(lpObj->pWarehouse[target].m_Type == ITEMGET(13,42))
							{
									gObjUseSkill.SkillChangeUse(aIndex);
							}
						}

						gObjMakePreviewCharSet(aIndex);
						GCEquipmentChange(aIndex,source);
					}
				}
			return 2;
		case 3:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			BYTE res_2;
				switch(sFlag)
				{
				case 0:
					res_2 = gObjChaosBoxInsertItemPos(aIndex,lpObj->pInventory[source],target,-1);
					break;
				case 3:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:

					res_2 = gObjChaosBoxInsertItemPos(aIndex,lpObj->pChaosBox[source],target,source);
					break;
				default : break;
				}

				if(res_2 == 255)
				{
					return -1;
				}

				switch(sFlag)
				{
				case 0:
					lpObj->pChaosBox[target] = lpObj->pInventory[source];
					gObjInventoryDeleteItem(aIndex,source);
					break;
				case 3:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:

					lpObj->pChaosBox[target] = lpObj->pChaosBox[source];
					gObjChaosBoxDeleteItem(aIndex,source);
					break;
				default : break;
				}

				gObjChaosItemSet(aIndex,target,1);

				if(sFlag == 0)
				{
					if(source < INVETORY_WEAR_SIZE)
					{
						if(source == 10 || source == 11)
						{
							if(lpObj->pChaosBox[target].m_Type == ITEMGET(13,10))
							{
								gObjUseSkill.SkillChangeUse(aIndex);
							}

							if(lpObj->pChaosBox[target].m_Type == ITEMGET(13,39))
							{
								gObjUseSkill.SkillChangeUse(aIndex);
							}
							
                            if(lpObj->pChaosBox[target].m_Type == ITEMGET(13,40))
                            {
                                    gObjUseSkill.SkillChangeUse(aIndex);
                            }

                            if(lpObj->pChaosBox[target].m_Type == ITEMGET(13,41))
                            {
                                    gObjUseSkill.SkillChangeUse(aIndex);
                            }

                            if(lpObj->pChaosBox[target].m_Type == ITEMGET(13,42))
                            {
                                    gObjUseSkill.SkillChangeUse(aIndex);
                            }
						}

						gObjMakePreviewCharSet(aIndex);
						GCEquipmentChange(aIndex,source);
					}
				}
			return tFlag;
		default: break;
		}

		if(sFlag == 0 && source < INVETORY_WEAR_SIZE)
		{
			if(lpObj->pInventory[source].IsItem() == 1)
			{
				if(lpObj->pInventory[source].m_Type == ITEMGET(13,10))
				{
					gObjUseSkill.SkillChangeUse(aIndex);
					LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[source].m_Level);
				}

				if(lpObj->pInventory[source].m_Type == ITEMGET(13,39))
				{
					gObjUseSkill.SkillChangeUse(aIndex);
					LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[source].m_Level);
				}

				if(lpObj->pInventory[source].m_Type == ITEMGET(13,40))
				{
						gObjUseSkill.SkillChangeUse(aIndex);
						LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[source].m_Level);
				}

				if(lpObj->pInventory[source].m_Type == ITEMGET(13,41))
				{
						gObjUseSkill.SkillChangeUse(aIndex);
						LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[source].m_Level);
				}

				if(lpObj->pInventory[source].m_Type == ITEMGET(13,42))
				{
						gObjUseSkill.SkillChangeUse(aIndex);
						LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[source].m_Level);
				}

			}
			else
			{
				if(source == 10 || source == 11)
				{
					if(lpObj->pInventory[target].m_Type == ITEMGET(13,10))
					{
						gObjUseSkill.SkillChangeUse(aIndex);
					}

					if(lpObj->pInventory[target].m_Type == ITEMGET(13,39))
					{
						gObjUseSkill.SkillChangeUse(aIndex);
					}

					if(lpObj->pInventory[target].m_Type == ITEMGET(13,40))
                    {
                            gObjUseSkill.SkillChangeUse(aIndex);
                    }

                    if(lpObj->pInventory[target].m_Type == ITEMGET(13,41))
                    {
                            gObjUseSkill.SkillChangeUse(aIndex);
                    }

                    if(lpObj->pInventory[target].m_Type == ITEMGET(13,42))
                    {
                            gObjUseSkill.SkillChangeUse(aIndex);
                    }

				}
			}

			gObjMakePreviewCharSet(aIndex);
			GCEquipmentChange(aIndex,source);
		}

		if(tFlag == 0 && target < INVETORY_WEAR_SIZE)
		{
			if(lpObj->pInventory[target].m_Type == ITEMGET(13,10))
			{
				gObjUseSkill.SkillChangeUse(aIndex);
				LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[target].m_Level);
			}

			if(lpObj->pInventory[target].m_Type == ITEMGET(13,39))
			{
				gObjUseSkill.SkillChangeUse(aIndex);
				LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[target].m_Level);
			}

            if(lpObj->pInventory[target].m_Type == ITEMGET(13,40))
            {
                    gObjUseSkill.SkillChangeUse(aIndex);
                    LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[target].m_Level);
            }

            if(lpObj->pInventory[target].m_Type == ITEMGET(13,41))
            {
                    gObjUseSkill.SkillChangeUse(aIndex);
                    LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[target].m_Level);
            }

            if(lpObj->pInventory[target].m_Type == ITEMGET(13,42))
            {
                    gObjUseSkill.SkillChangeUse(aIndex);
                    LogAdd("Using transformation ring : %s : %d",gObj[aIndex].Name,lpObj->pInventory[target].m_Level);
            }

			gObjMakePreviewCharSet(aIndex);
			GCEquipmentChange(aIndex,target);
		}
	}
	__finally
	{
		if(bPersonalShopTrans == 1)
		{
			gObj[aIndex].m_bPShopTransaction = 0;
		}
	}
	return false;
}






BYTE gObjTradeRectCheck(int aIndex, int sx, int sy, int width, int height )
{
	int x;
	int y;
	int blank = 0;
	int xx;
	int yy;

	if ( ( sx + width) > 8 )
	{
		return -1;
	}

	if ( (sy + height) > 4 )
	{
		return -1;
	}

	for ( y=0;y<height;y++)
	{
		yy = sy + y;
		
		for ( x=0;x<width;x++)
		{
			xx = sx + x;

			if ( ::ExtentCheck(xx, yy, 8, 4) == TRUE )
			{
				if ( *(BYTE*)(gObj[aIndex].TradeMap + yy * 8 + xx) != (BYTE)-1)
				{
					blank++;
					return -1;
				}
			}
			else
			{
				LogAdd("error : %s %d", __FILE__ ,__LINE__);
				return -1;
			}
		}
	}

	if ( blank == 0 )
	{
		return (sy * 8 + sx);
	}

	return -1;
}






BOOL gObjTradeItemBoxSet(int aIndex, int itempos, int xl, int yl, BYTE set_byte)
{
	int itemposx = (itempos)%8;
	int itemposy = (itempos)/8;

	int xx,yy;

	for(int y = 0; y < yl; y ++)
	{
		yy = itemposy + y;

		for(int x = 0; x < xl; x++)
		{
			xx = itemposx + x;

			if(ExtentCheck(xx,yy,8,4)==1)
			{
				*(BYTE*)(gObj[aIndex].TradeMap + yy*8+xx) = set_byte;
			}
			else
			{
				LogAdd("error : %s %d",__FILE__,__LINE__);
				return false;
			}
		}
	}
	return true;
}






BYTE gObjTradeInventoryMove(LPOBJ lpObj, BYTE source, BYTE target)
{
	int iwidth,iheight,s_num;
	BYTE itembuf[8];
	if(source > TRADE_BOX_SIZE)
	{
		LogAdd("error : %s %d",__FILE__,__LINE__);
		return -1;
	}

	if(target > MAIN_INVENTORY_SIZE)
	{
		LogAdd("error : %s %d",__FILE__,__LINE__);
		return -1;
	}

	if(lpObj->TargetNumber < 0)
	{
		return -1;
	}

	if(lpObj->Trade[source].IsItem() == 0)
	{
		return -1;
	}

	if(lpObj->m_IfState.use == 0 || lpObj->m_IfState.type != 1)
	{
		return -1;
	}

	if(gObjInventoryInsertItemPos(lpObj->m_Index,lpObj->Trade[source],target,1) == 255)
	{
		return -1;
	}

	s_num = 0;
	s_num = lpObj->Trade[source].m_Number;

	lpObj->Trade[source].GetSize((int &)iwidth,(int &)iheight);

	gObjTradeItemBoxSet(lpObj->m_Index,source,iwidth,iheight,255);
	lpObj->Trade[source].Clear();

	ItemByteConvert(itembuf,lpObj->Trade[source]);

	GCTradeOtherDel(lpObj->TargetNumber,source);

	if(gObjCheckSerial0ItemList(&lpObj->Trade[source]) != 0)
	{
		MsgOutput(lpObj->m_Index,"Unable to use");
		LogAdd("[ANTI-HACK][Serial 0 Item] [Trade] (%s)(%s) Item(%s) Pos(%d)",lpObj->AccountID,lpObj->Name,lpObj->Trade[source].GetName(),source);
		return -1;
	}

	if(gObjInventorySearchSerialNumber(lpObj,s_num) == 0)
	{
		return -1;
	}

	if(target < INVETORY_WEAR_SIZE)
	{
		if(lpObj->pInventory[target].IsItem() == 1)
		{
			if(lpObj->pInventory[target].m_Type == ITEMGET(13,10))
			{
				gObjUseSkill.SkillChangeUse(lpObj->m_Index);
				LogAdd("Using transformation ring : %s : %d",lpObj->Name,lpObj->pInventory[target].m_Level);
			}
			if(lpObj->pInventory[target].m_Type == ITEMGET(13,39))
			{
				gObjUseSkill.SkillChangeUse(lpObj->m_Index);
				LogAdd("Using transformation ring : %s : %d",lpObj->Name,lpObj->pInventory[target].m_Level);
			}

            if(lpObj->pInventory[target].m_Type == ITEMGET(13,40))
            {
                    gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                    LogAdd("Using transformation ring : %s : %d",lpObj->Name,lpObj->pInventory[target].m_Level);
            }
            if(lpObj->pInventory[target].m_Type == ITEMGET(13,41))
            {
                    gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                    LogAdd("Using transformation ring : %s : %d",lpObj->Name,lpObj->pInventory[target].m_Level);
            }
            if(lpObj->pInventory[target].m_Type == ITEMGET(13,42))
            {
                    gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                    LogAdd("Using transformation ring : %s : %d",lpObj->Name,lpObj->pInventory[target].m_Level);
            }

		}

		gObjMakePreviewCharSet(lpObj->m_Index);
		GCEquipmentChange(lpObj->m_Index,target);
	}

	return false;
}






BYTE gObjInventoryTradeMove(LPOBJ lpObj, BYTE source, BYTE target)
{
	int h,w,iwidth,iheight,s_num,blank;


	if(source > MAIN_INVENTORY_SIZE)
	{
		LogAdd("error : %s %d",__FILE__,__LINE__);
		return -1;
	}

	if(lpObj->pInventory[source].IsItem() == 0)
	{
		return -1;
	}

	if(lpObj->TargetNumber < 0)
	{
		return -1;
	}

	if(lpObj->m_IfState.use == 0 || lpObj->m_IfState.type != 1)
	{
		return -1;
	}

	if(lpObj->pInventory[source].m_Type == ITEMGET(13,20))
	{
		if(lpObj->pInventory[source].m_Level == 0 ||
			lpObj->pInventory[source].m_Level == 1)
		{
			return -1;
		}
	}

	if(lpObj->pInventory[source].m_Type == ITEMGET(13,20))
	{
		if(lpObj->pInventory[source].m_Level == 2)
		{
			return -1;
		}
	}

	if(lpObj->pInventory[source].m_Type == ITEMGET(14,11))
	{
		if(lpObj->pInventory[source].m_Level == 13)
		{
			return -1;
		}
	}

	if(lpObj->pInventory[source].m_Type == ITEMGET(12,26))
	{
		if(lpObj->pInventory[source].m_Level == 1 ||
			lpObj->pInventory[source].m_Level == 2 ||
			lpObj->pInventory[source].m_Level == 3 ||
			lpObj->pInventory[source].m_Level == 4 ||
			lpObj->pInventory[source].m_Level == 5)
		{
			return -1;
		}
	}

	if(lpObj->pInventory[source].m_Type == ITEMGET(13,38))
	{
		return -1;
	}

	if(lpObj->pInventory[source].m_Type == ITEMGET(13,39))
	{
		return -1;
	}

	/*if(IsCashItem(lpObj->pInventory[source].m_Type) == 1)
	{
		return -1;
	}*/

	lpObj->pInventory[source].GetSize((int &)iwidth,(int &)iheight);
	s_num = lpObj->pInventory[source].GetNumber();

	if(gObjCheckSerial0ItemList(&lpObj->pInventory[source]) != 0)
	{
		MsgOutput(lpObj->m_Index,"Unable to use");
		LogAdd("[ANTI-HACK][Serial 0 Item] [Trade] (%s)(%s) Item(%s) Pos(%d)",lpObj->AccountID,lpObj->Name,lpObj->pInventory[source].GetName(),source);
		return -1;
	}

	if(gObjInventorySearchSerialNumber(lpObj,s_num) == 0)
	{
		return -1;
	}

	w = target % 8;
	h = target / 8;

	if(ExtentCheck(w,h,8,4) == 0)
	{
		return -1;
	}

	if(*(BYTE*)(lpObj->TradeMap + h * 8 + w) == 255)
	{
	BYTE itembuf[8];
		blank = gObjTradeRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

		if(blank == 255)
		{
			return -1;
		}

		lpObj->Trade[blank] = lpObj->pInventory[source];
		gObjInventoryDeleteItem(lpObj->m_Index,source);
		gObjTradeItemBoxSet(lpObj->m_Index,blank,iwidth,iheight,(BYTE)lpObj->Trade[blank].m_Type);
		ItemByteConvert(itembuf,lpObj->Trade[blank]);
		GCTradeOtherAdd(lpObj->TargetNumber,blank,itembuf);

		if(source < INVETORY_WEAR_SIZE)
		{
			if(source == 10 || source == 11)
			{
				if(lpObj->Trade[blank].m_Type == ITEMGET(13,10))
				{
					gObjUseSkill.SkillChangeUse(lpObj->m_Index);
				}

                if(lpObj->Trade[blank].m_Type == ITEMGET(13,39))
                {
                        gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                }
                if(lpObj->Trade[blank].m_Type == ITEMGET(13,40))
                {
                        gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                }
                if(lpObj->Trade[blank].m_Type == ITEMGET(13,41))
                {
                        gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                }
                if(lpObj->Trade[blank].m_Type == ITEMGET(13,42))
                {
                        gObjUseSkill.SkillChangeUse(lpObj->m_Index);
                }

			}
			gObjMakePreviewCharSet(lpObj->m_Index);
			GCEquipmentChange(lpObj->m_Index,source);
		}
		return true;
	}
	return -1;
}






BYTE gObjTradeTradeMove(LPOBJ lpObj, BYTE source, BYTE target)
{
	int h,w;
	int iwidth,iheight;
	BYTE TempTradeMap[TRADE_BOX_MAP_SIZE];
	int blank;

	if(source > TRADE_BOX_SIZE)
	{
		LogAdd("error : %s %d",__FILE__,__LINE__);
		return -1;
	}
	if(source == target)
	{
		LogAdd("error : %s %d",__FILE__,__LINE__);
		return -1;
	}
	if(lpObj->Trade[source].IsItem() == 0)
	{
		return -1;
	}
	if(lpObj->Trade[target].IsItem() == 1)
	{
		return -1;
	}
	if(lpObj->TargetNumber < 0)
	{
		return -1;
	}
	if(lpObj->m_IfState.use == 0 || lpObj->m_IfState.type != 1)
	{
		return -1;
	}

	lpObj->Trade[source].GetSize((int &)iwidth,(int &)iheight);
	memcpy(TempTradeMap,lpObj->TradeMap,TRADE_BOX_MAP_SIZE);
	gObjTradeItemBoxSet(lpObj->m_Index,source,iwidth,iheight,255);

	w = target % 8;
	h = target / 8;

	if(ExtentCheck(w,h,8,4) == 0)
	{
		memcpy(lpObj->TradeMap,TempTradeMap,TRADE_BOX_MAP_SIZE);
		return -1;
	}

	if(*(BYTE*)(lpObj->TradeMap + h * 8 + w) == 255)
	{
		BYTE itembuf[8];
		blank = gObjTradeRectCheck(lpObj->m_Index,w,h,iwidth,iheight);

		if(blank == 255)
		{
			memcpy(lpObj->TradeMap,TempTradeMap,TRADE_BOX_MAP_SIZE);
			return -1;
		}

		lpObj->Trade[blank] = lpObj->Trade[source];
		lpObj->Trade[source].Clear();
		GCTradeOtherDel(lpObj->TargetNumber,source);
		gObjTradeItemBoxSet(lpObj->m_Index,blank,iwidth,iheight,(BYTE)lpObj->Trade[blank].m_Type);
		ItemByteConvert(itembuf,lpObj->Trade[blank]);
		GCTradeOtherAdd(lpObj->TargetNumber,blank,itembuf);
		return true;
	}

	memcpy(lpObj->TradeMap,TempTradeMap,TRADE_BOX_MAP_SIZE);
	return -1;
}






void gObjTradeCancel(int aIndex)
{
	if(OBJMAX_RANGE(aIndex) == 0)
	{
		LogAdd("error : index error %s %d",__FILE__,__LINE__);
		return;
	}
	if(gObj[aIndex].Type != OBJ_USER || gObj[aIndex].Connected != PLAYER_PLAYING)
	{
		LogAdd("Return, because trade canceled while game is not working [%s][%s].",gObj[aIndex].AccountID,gObj[aIndex].Name);
		return;
	}
	if(gObj[aIndex].m_IfState.use != 1)
	{
		LogAdd("Return, because trade canceled while it's not (in-trade1) [%s][%s].",gObj[aIndex].AccountID,gObj[aIndex].Name);
		return;
	}
	if(gObj[aIndex].m_IfState.type != 1)
	{
		LogAdd("Return, because trade canceled while it's not (in-trade2) [%s][%s].",gObj[aIndex].AccountID,gObj[aIndex].Name);
		return;
	}
	gObjInventoryRollback(aIndex);
	gObj[aIndex].TargetNumber = -1;
	gObj[aIndex].m_IfState.use = 0;
	gObjCharTradeClear(&gObj[aIndex]);
	GCMoneySend(aIndex,gObj[aIndex].Money);
	GCItemListSend(aIndex);
	GCEquipmentSend(aIndex);
	GCMagicListMultiSend(&gObj[aIndex],0);
	gObjUseSkill.SkillChangeUse(aIndex);

	if(gObj[aIndex].GuildNumber > 0)
	{
		GCGuildViewportNowPaint(aIndex,gObj[aIndex].GuildName,0,0);
		gObjNotifyUpdateUnionV1(&gObj[aIndex]);
		gObjNotifyUpdateUnionV2(&gObj[aIndex]);
	}
	LogAdd("Cancel trade : [%s][%s] .",gObj[aIndex].AccountID,gObj[aIndex].Name);
}






void gObjTempInventoryItemBoxSet(BYTE * TempMap, int itempos, int xl, int yl, BYTE set_byte)
{
	int itemposx = (itempos - INVETORY_WEAR_SIZE) % 8;
	int itemposy = (itempos - INVETORY_WEAR_SIZE) / 8;

	for(int y = 0 ; y < yl ; y++)
	{
		for(int x = 0; x < xl; x++)
		{
			*(BYTE*)(TempMap + (itemposy +y) * 8 + (itemposx + x)) = set_byte;
		}
	}
}






BYTE gObjTempInventoryRectCheck(BYTE * TempMap, int sx, int sy, int width, int height)
{
	int x,y,blank = 0;

	if(sx + width > 8)
	{
		return -1;
	}
	if(sy + height > 8)
	{
		return -2;
	}

	for(y = 0; y < height; y++)
	{
		for(x = 0; x < width; x++)
		{
			if(*(BYTE*)(TempMap + (sy+y)*8 + (sx+x))!= 255)
			{
				blank += 1;
				return -1;
			}
		}
	}
	if(blank == 0)
	{
		return sx+sy*8+INVETORY_WEAR_SIZE;
	}
	return -1;
}






BYTE gObjTempInventoryInsertItem(LPOBJ lpObj, CItem item, BYTE * TempMap)
{
	int w,h,iwidth,iheight;
	BYTE blank = 0;

	if(item.GetSize(iwidth,iheight) == 0)
	{
		LogAdd("Item doesn't exist. [%s][%d] %d",__FILE__,__LINE__,item.m_Type);
		return -1;
	}
	for(h = 0; h < 8; h++)
	{
		for(w = 0; w < 8; w++)
		{
			if(*(BYTE*)(TempMap + h * 8 + w) == 255)
			{
				blank = gObjTempInventoryRectCheck(TempMap,w,h,iwidth,iheight);

				if(blank == 254)
				{
					goto GOTO_EndFunc;
				}
				if(blank != 255)
				{
					gObjTempInventoryItemBoxSet(TempMap,blank,iwidth,iheight,(BYTE)item.m_Type);
					return blank;
				}
			}
		}
	}
GOTO_EndFunc:
	return -1;
}






BOOL TradeItemInventoryPutTest(int aIndex)
{
	BYTE TempInventoryMap[64];
	int number,result = 1;
	number = gObj[aIndex].TargetNumber;

	if(gObjIsConnected(number) == 0)
	{
		return false;
	}
	memcpy(TempInventoryMap,gObj[aIndex].pInventoryMap,64);

	for(int n = 0; n < TRADE_BOX_SIZE; n++)
	{
		if(gObj[number].Trade[n].IsItem() == 1)
		{
			if(gObjTempInventoryInsertItem(&gObj[aIndex],gObj[number].Trade[n],TempInventoryMap) == 255)
			{
				return false;
			}
			result = 1;
		}
	}
	if(result == 1)
	{
		return true;
	}
	return false;
}






BOOL TradeitemInventoryPut(int aIndex)
{
	int number;
	BYTE insert;
	char szItemName[50] = "Item";
	BYTE ExOption[8];

	number = gObj[aIndex].TargetNumber;

	if(gObjIsConnected(number) == 0)
	{
		return false;
	}

	for(int n = 0; n < TRADE_BOX_SIZE; n++)
	{
		if(gObj[number].Trade[n].IsItem() == 1)
		{
			insert = gObjInventoryInsertItem(aIndex,gObj[number].Trade[n]);
			if(insert != 255)
			{
				strcpy_s(szItemName, sizeof(szItemName),gObj[number].Trade[n].GetName());
				ItemIsBufExOption(ExOption,&gObj[number].Trade[n]);
				LogAdd("***0538*** [%s][%s] (%d,%d,%d) Trade Item  Opposite :[%s][%s] (%d,%d,%d) (Item:%s/Serial:%d (%d)(%d)(%d)(%d) Ex:(%d,%d,%d,%d,%d,%d,%d) Set : (%d)",
					gObj[number].AccountID,gObj[number].Name,gObj[number].MapNumber,gObj[number].X,gObj[number].Y,
					gObj[aIndex].AccountID,gObj[aIndex].Name,gObj[aIndex].MapNumber,gObj[aIndex].X,gObj[aIndex].Y,
					szItemName,gObj[number].Trade[n].m_Number,gObj[number].Trade[n].m_Level,gObj[number].Trade[n].m_Option1,gObj[number].Trade[n].m_Option2,gObj[number].Trade[n].m_Option3,
					ExOption[0],ExOption[1],ExOption[2],ExOption[3],ExOption[4],ExOption[5],ExOption[6],gObj[number].Trade[n].m_SetOption);

			}
			else
			{
				LogAdd("error : �̰� ū�ϳ�����!!"); //#error
				return false;
			}
		}
	}
	return true;
}






void gObjTradeOkButton(int aIndex)
{
	BYTE result = 1;
	int number = gObj[aIndex].TargetNumber;

	if(number < 0)
	{
		return;
	}

	if(gObjIsConnected(number) == 0)
	{
		return;
	}

	if(gObj[number].TargetNumber != aIndex)
	{
		LogAdd("error : The opposite to trade is not me. [%s][%s] Target:(%d) (%d)",gObj[aIndex].AccountID,gObj[aIndex].Name,gObj[number].TargetNumber,gObj[number].TargetNumber);
		return;
	}

	if(gObj[aIndex].TradeOk != 1 || gObj[number].TradeOk != 1)
	{
		return;
	}

	if(TradeItemInventoryPutTest(aIndex) == 1)
	{
		if(TradeItemInventoryPutTest(number) == 1)
		{
			result = 1;
		}
		else
		{
			result = 2;
		}
	}
	else
	{
		result = 2;
	}

	if(gObjCheckMaxZen(aIndex,gObj[number].TradeMoney) == 0)
	{
		result = 2;
	}

	if(gObjCheckMaxZen(number,gObj[aIndex].TradeMoney) == 0)
	{
		result = 2;
	}

	if(g_kJewelOfHarmonySystem.IsEnableToTrade(&gObj[number]) == 0 || g_kJewelOfHarmonySystem.IsEnableToTrade(&gObj[aIndex]) == 0)
	{
		result = 4;
		gObjTradeCancel(aIndex);
		gObjTradeCancel(number);
		CGTradeResult(aIndex,result);
		CGTradeResult(number,result);
		return;
	}

	if(result == 1)
	{
		TradeitemInventoryPut(aIndex);
		TradeitemInventoryPut(number);
		gObjInventoryCommit(aIndex);
		gObjInventoryCommit(number);
		gObjMakePreviewCharSet(aIndex);
		gObjMakePreviewCharSet(number);

		gObj[aIndex].Money -= gObj[aIndex].TradeMoney;
		if(gObj[aIndex].Money < 0)
		{
			gObj[aIndex].Money = 0;
		}
		gObj[number].Money -= gObj[number].TradeMoney;
		if(gObj[number].Money < 0)
		{
			gObj[number].Money = 0;
		}

		gObj[aIndex].Money += gObj[number].TradeMoney;
		gObj[number].Money += gObj[aIndex].TradeMoney;

		LogAdd("[%s][%s] , [%s][%s] Money trade (%d) (%d)",gObj[aIndex].AccountID,gObj[aIndex].Name,gObj[number].AccountID,gObj[number].Name,gObj[aIndex].TradeMoney,gObj[number].TradeMoney);
		GJSetCharacterInfo(&gObj[aIndex],aIndex,0);
		GJSetCharacterInfo(&gObj[number],number,0);
	}
	else
	{
		result = 2;
		gObjTradeCancel(aIndex);
		gObjTradeCancel(number);
		CGTradeResult(aIndex,result);
		CGTradeResult(number,result);
		return;
	}

	gObj[aIndex].TargetNumber = -1;
	gObj[aIndex].m_IfState.use = 0;
	gObj[number].TargetNumber = -1;
	gObj[number].m_IfState.use = 0;
	gObj[aIndex].TradeOk = 0;
	gObj[number].TradeOk = 0;
	gObj[aIndex].TradeMoney = 0;
	gObj[number].TradeMoney = 0;

	GCMoneySend(aIndex,gObj[aIndex].Money);
	GCMoneySend(number,gObj[number].Money);
	CGTradeResult(aIndex,result);
	CGTradeResult(number,result);

	GCItemListSend(aIndex);
	GCItemListSend(number);

	for(int n = 0; n < TRADE_BOX_SIZE; n++)
	{
		gObj[aIndex].Trade[n].Clear();
		gObj[number].Trade[n].Clear();
	}

	gObjNotifyUpdateUnionV1(&gObj[aIndex]);
	gObjNotifyUpdateUnionV2(&gObj[aIndex]);
}






BYTE LevelSmallConvert(int aIndex, int inventoryindex)
{
	int level = gObj[aIndex].pInventory[inventoryindex].m_Level;

	if(level >= 13)
	{
		return 7;
	}

	if(level == 12)
	{
		return 6;
	}

	if(level == 11)
	{
		return 5;
	}

	if(level >= 9 && level <= 10)
	{
		return 4;
	}

	if(level >= 7 && level <= 8)
	{
		return 3;
	}

	if(level >= 5 && level <= 6)
	{
		return 2;
	}

	if(level >= 3 && level <= 4)
	{
		return 1;
	}
	
	return 0;
}






BYTE LevelSmallConvert(int level)
{
	if(level >= 13)
	{
		return 6;
	}

	if(level >= 11 && level <=12)
	{
		return 5;
	}

	if(level >= 9 && level <= 10)
	{
		return 4;
	}

	if(level >= 7 && level <= 8)
	{
		return 3;
	}

	if(level >= 5 && level <= 6)
	{
		return 2;
	}

	if(level >= 3 && level <= 4)
	{
		return 1;
	}
	
	return 0;
}






void gObjAttackDamageCalc(int aIndex) 
{
	return;	// Here goes a Macro
}




void gObjMakePreviewCharSet(int aIndex)
{
	if ( !OBJMAX_RANGE(aIndex ))
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return;
	}

	BYTE index;
	LPOBJ lpObj = &gObj[aIndex];
	memset(lpObj->CharSet, 0, sizeof(lpObj->CharSet));

	lpObj->CharSet[CS_CLASS] = CS_SET_CLASS(lpObj->Class);

	if( lpObj->ChangeUP == 2 )
	{
		switch( lpObj->DbClass )
		{
		case 2:
			lpObj->CharSet[CS_CLASS] |= 24; //0x18
			break;
		case 18:
			lpObj->CharSet[CS_CLASS] |= 56; //0x38
			break;
		case 34:
			lpObj->CharSet[CS_CLASS] |= 88; //0x58
			break;
		case 50:
			lpObj->CharSet[CS_CLASS] |= 120; //0x78
			break;
		case 66:
			lpObj->CharSet[CS_CLASS] |= 152; //0x98
			break;
		}
	}

	lpObj->CharSet[CS_CLASS] |= CS_SET_CHANGEUP(lpObj->ChangeUP);

	// Set Class
	if ( lpObj->m_ActionNumber == 0x80 )
	{
		lpObj->CharSet[CS_CLASS] |= 2;
	}
	else if ( lpObj->m_ActionNumber == 0x81 )
	{
		lpObj->CharSet[CS_CLASS] |= 3;
	}
	else
	{
		lpObj->CharSet[CS_CLASS] = lpObj->CharSet[CS_CLASS];
	}

	// Set Righth HAnd Item
	if ( lpObj->pInventory[0].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[CS_WEAPON1_DATA] |= (BYTE)DBI_GET_TYPE(-1);
		lpObj->CharSet[CS_WEAPON1_TYPE] = (BYTE)DBI_GET_INDEX(-1);
	}
	else
	{
		lpObj->CharSet[CS_WEAPON1_DATA] |= DBI_GET_TYPE(lpObj->pInventory[0].m_Type);
		lpObj->CharSet[CS_WEAPON1_TYPE] = DBI_GET_INDEX(lpObj->pInventory[0].m_Type);
	}

	// Set Left Hand
	if ( lpObj->pInventory[1].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[CS_WEAPON2_DATA] |= (BYTE)DBI_GET_TYPE(-1);
		lpObj->CharSet[CS_WEAPON2_TYPE] = (BYTE)DBI_GET_INDEX(-1);
	}
	else
	{
		lpObj->CharSet[CS_WEAPON2_DATA] |= DBI_GET_TYPE(lpObj->pInventory[1].m_Type);
		lpObj->CharSet[CS_WEAPON2_TYPE] = DBI_GET_INDEX(lpObj->pInventory[1].m_Type);
	}

	// Set Helmet
	if ( lpObj->pInventory[2].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[13] |= CS_SET_HELMET1(-1);
		lpObj->CharSet[9]  |= CS_SET_HELMET2(-1);
		lpObj->CharSet[3]  |= CS_SET_HELMET3(-1);
	}
	else
	{
		lpObj->CharSet[13] |= CS_SET_HELMET1(lpObj->pInventory[2].m_Type);
		lpObj->CharSet[9]  |= CS_SET_HELMET2(lpObj->pInventory[2].m_Type);
		lpObj->CharSet[3]  |= CS_SET_HELMET3(lpObj->pInventory[2].m_Type);
	}

	// Set Armor
	if ( lpObj->pInventory[3].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[14] |= CS_SET_ARMOR1(-1);
		lpObj->CharSet[9]  |= CS_SET_ARMOR2(-1);
		lpObj->CharSet[3]  |= CS_SET_ARMOR3(-1);
	}
	else
	{
		lpObj->CharSet[14] |= CS_SET_ARMOR1(lpObj->pInventory[3].m_Type);
		lpObj->CharSet[9]  |= CS_SET_ARMOR2(lpObj->pInventory[3].m_Type);
		lpObj->CharSet[3]  |= CS_SET_ARMOR3(lpObj->pInventory[3].m_Type);
	}

	// Set Pants
	if ( lpObj->pInventory[4].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[14] |= CS_SET_PANTS1(-1);
		lpObj->CharSet[9]  |= CS_SET_PANTS2(-1);
		lpObj->CharSet[4]  |= CS_SET_PANTS3(-1);
	}
	else
	{
		lpObj->CharSet[14] |= CS_SET_PANTS1(lpObj->pInventory[4].m_Type);
		lpObj->CharSet[9]  |= CS_SET_PANTS2(lpObj->pInventory[4].m_Type);
		lpObj->CharSet[4]  |= CS_SET_PANTS3(lpObj->pInventory[4].m_Type);
	}

	// Set Gloves
	if ( lpObj->pInventory[5].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[15] |= CS_SET_GLOVES1(-1);
		lpObj->CharSet[9]  |= CS_SET_GLOVES2(-1);
		lpObj->CharSet[4]  |= CS_SET_GLOVES3(-1);
	}
	else
	{
		lpObj->CharSet[15] |= CS_SET_GLOVES1(lpObj->pInventory[5].m_Type);
		lpObj->CharSet[9]  |= CS_SET_GLOVES2(lpObj->pInventory[5].m_Type);
		lpObj->CharSet[4]  |= CS_SET_GLOVES3(lpObj->pInventory[5].m_Type);
	}

	// Set Boots
	if ( lpObj->pInventory[6].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[15] |= CS_SET_BOOTS1(-1);
		lpObj->CharSet[9]  |= CS_SET_BOOTS2(-1);
		lpObj->CharSet[5]  |= CS_SET_BOOTS3(-1);
	}
	else
	{
		lpObj->CharSet[15] |= CS_SET_BOOTS1(lpObj->pInventory[6].m_Type);
		lpObj->CharSet[9]  |= CS_SET_BOOTS2(lpObj->pInventory[6].m_Type);
		lpObj->CharSet[5]  |= CS_SET_BOOTS3(lpObj->pInventory[6].m_Type);
	}

	index = 0;

	// Set Part onf Wings
	if ( lpObj->pInventory[7].m_Type < ITEMGET(0,0) )
	{
		index |= CS_SET_WING1(-1);
	}
	else
	{
		index |= CS_SET_WING1(lpObj->pInventory[7].m_Type);
	}

	if ( lpObj->pInventory[8].m_Type != ITEMGET(13,4) )
	{
		if ( lpObj->pInventory[8].m_Type < ITEMGET(0,0) )
		{
			index |= CS_SET_HELPER(-1);
		}
		else
		{
			index |= CS_SET_HELPER(lpObj->pInventory[8].m_Type);
		}
	}
	else
	{
		index |= CS_SET_HELPER(-1);
	}

	lpObj->CharSet[5] |= index;

	int levelindex = CS_SET_SMALLLEVEL_RH(LevelSmallConvert(aIndex, 0));
	levelindex |= CS_SET_SMALLLEVEL_LH(LevelSmallConvert(aIndex, 1));
	levelindex |= CS_SET_SMALLLEVEL_HELMET(LevelSmallConvert(aIndex, 2));
	levelindex |= CS_SET_SMALLLEVEL_ARMOR(LevelSmallConvert(aIndex, 3));
	levelindex |= CS_SET_SMALLLEVEL_PANTS(LevelSmallConvert(aIndex, 4));
	levelindex |= CS_SET_SMALLLEVEL_GLOVES(LevelSmallConvert(aIndex, 5));
	levelindex |= CS_SET_SMALLLEVEL_BOOTS(LevelSmallConvert(aIndex, 6));

	lpObj->CharSet[6] = CS_SET_SMALLLEVEL1(levelindex);
	lpObj->CharSet[7] = CS_SET_SMALLLEVEL2(levelindex);
	lpObj->CharSet[8] = CS_SET_SMALLLEVEL3(levelindex);

	if ( (lpObj->pInventory[7].m_Type >= ITEMGET(12,3) && lpObj->pInventory[7].m_Type <= ITEMGET(12,6)) ||
		  lpObj->pInventory[7].m_Type == ITEMGET(13,30) )
	{
		lpObj->CharSet[5] |= CS_SET_WING1(-1);
		
		if ( lpObj->pInventory[7].m_Type == ITEMGET(13,30) )
		{
			lpObj->CharSet[9] |= 5;
		}
		else
		{
			lpObj->CharSet[9] |= (lpObj->pInventory[7].m_Type - 2) & 0x07;
		}
	}

	// Set Excellent Items
	lpObj->CharSet[10] = 0;

	if ( lpObj->pInventory[2].IsExtItem() != FALSE )
		lpObj->CharSet[10] = (char)0x80;

	if ( lpObj->pInventory[3].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x40;

	if ( lpObj->pInventory[4].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x20;

	if ( lpObj->pInventory[5].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x10;

	if ( lpObj->pInventory[6].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x8;

	if ( lpObj->pInventory[0].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x04;

	if ( lpObj->pInventory[1].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x02;

	// Set Set Items
	lpObj->CharSet[11] = 0;

	if ( lpObj->pInventory[2].IsSetItem() != FALSE )
		lpObj->CharSet[11] = (char)0x80;

	if ( lpObj->pInventory[3].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x40;

	if ( lpObj->pInventory[4].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x20;

	if ( lpObj->pInventory[5].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x10;

	if ( lpObj->pInventory[6].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x8;

	if ( lpObj->pInventory[0].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x04;

	if ( lpObj->pInventory[1].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x02;

	gObjCalCharacter(aIndex);

	if ( lpObj->IsFullSetItem != false )
		lpObj->CharSet[11] |= 0x01;

/*
13
	0	"Guardian Angel"
	1	"Imp"
	2	"Horn of Uniria"
	3	"Horn of Dinorant"
	4	"Horn of Dark Horse"
*/
	if ( (lpObj->pInventory[8].m_Type & 0x03) != 0 )
	{
		if ( lpObj->pInventory[8].m_Type > 0 )
		{
			lpObj->CharSet[10] |= 0x01;
		}
	}

	if ( lpObj->pInventory[8].m_Type == ITEMGET(13,4) )	// Dark Horse
	{
		lpObj->CharSet[12] |= 0x01;
	}
	
	//Hermex Fix for Charset 16 to prevent Wings Level 3 Visual Bug
	lpObj->CharSet[16] = 0;
	
	if( lpObj->pInventory[7].m_Type >= ITEMGET(12,36) && lpObj->pInventory[7].m_Type <= ITEMGET(12,40) ) //Third Wings
	{
		lpObj->CharSet[16] |= (lpObj->pInventory[7].m_Type - 35) * 4;
	}

	if ( lpObj->pInventory[8].m_Type == ITEMGET(13,37) )	// Fenrir
	{
		lpObj->CharSet[10] &= 0xFE;
		lpObj->CharSet[12] &= 0xFE;
		lpObj->CharSet[12] |= 0x04;
		lpObj->CharSet[17] = 0;

		if ( lpObj->pInventory[8].IsFenrirIncLastAttackDamage() != FALSE )
		{
			lpObj->CharSet[16] |= 0x01; //1
		}

		if ( lpObj->pInventory[8].IsFenrirDecLastAttackDamage() != FALSE )
		{
			lpObj->CharSet[16] |= 0x02; //2
		}

		if ( lpObj->pInventory[8].IsFenrirIllusion() != FALSE )
		{
			lpObj->CharSet[17] |= 0x01; //4
		}
	}
}

/*void gObjMakePreviewCharSet(int aIndex)
{
	if ( !OBJMAX_RANGE(aIndex ))
	{
		LogAdd("error : %s %d", __FILE__, __LINE__);
		return;
	}

	BYTE index;
	LPOBJ lpObj = &gObj[aIndex];
	memset(lpObj->CharSet, 0, sizeof(lpObj->CharSet));

	lpObj->CharSet[CS_CLASS] = CS_SET_CLASS(lpObj->Class);

	if( lpObj->ChangeUP == 2 )
	{
		switch( lpObj->DbClass )
		{
		case 2:
			lpObj->CharSet[CS_CLASS] |= 24; //0x18
			break;
		case 18:
			lpObj->CharSet[CS_CLASS] |= 56; //0x38
			break;
		case 34:
			lpObj->CharSet[CS_CLASS] |= 88; //0x58
			break;
		case 50:
			lpObj->CharSet[CS_CLASS] |= 120; //0x78
			break;
		case 66:
			lpObj->CharSet[CS_CLASS] |= 152; //0x98
			break;
		}
	}

	lpObj->CharSet[CS_CLASS] |= CS_SET_CHANGEUP(lpObj->ChangeUP);


	/*int Preview=0;


	int tmp=gObjTakeClass(lpObj->Class,lpObj->ChangeUP);
	lpObj->CharSet[CS_CLASS] = tmp;
	//lpObj->CharSet[CS_CLASS]= CS_SET_CLASS(lpObj->Class);
	//lpObj->CharSet[CS_CLASS] |= CS_SET_CHANGEUP(lpObj->ChangeUP);

	// Set Class
	if ( lpObj->m_ActionNumber == 0x80 )
	{
		lpObj->CharSet[CS_CLASS] |= 2;
	}
	else if ( lpObj->m_ActionNumber == 0x81 )
	{
		lpObj->CharSet[CS_CLASS] |= 3;
	}
	else
	{
		lpObj->CharSet[CS_CLASS] = lpObj->CharSet[CS_CLASS];
	}

	// Set Righth HAnd Item
	if ( lpObj->pInventory[0].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[CS_WEAPON1_DATA] |= (BYTE)DBI_GET_TYPE(-1);
		lpObj->CharSet[CS_WEAPON1_TYPE] = (BYTE)DBI_GET_INDEX(-1);
	}
	else
	{
		lpObj->CharSet[CS_WEAPON1_DATA] |= DBI_GET_TYPE(lpObj->pInventory[0].m_Type);
		lpObj->CharSet[CS_WEAPON1_TYPE] = DBI_GET_INDEX(lpObj->pInventory[0].m_Type);
	}

	// Set Left Hand
	if ( lpObj->pInventory[1].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[CS_WEAPON2_DATA] |= (BYTE)DBI_GET_TYPE(-1);
		lpObj->CharSet[CS_WEAPON2_TYPE] = (BYTE)DBI_GET_INDEX(-1);
	}
	else
	{
		lpObj->CharSet[CS_WEAPON2_DATA] |= DBI_GET_TYPE(lpObj->pInventory[1].m_Type);
		lpObj->CharSet[CS_WEAPON2_TYPE] = DBI_GET_INDEX(lpObj->pInventory[1].m_Type);
	}

	// Set Helmet
	if ( lpObj->pInventory[2].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[13] |= CS_SET_HELMET1(-1);
		lpObj->CharSet[9]  |= CS_SET_HELMET2(-1);
		lpObj->CharSet[3]  |= CS_SET_HELMET3(-1);
	}
	else
	{
		lpObj->CharSet[13] |= CS_SET_HELMET1(lpObj->pInventory[2].m_Type);
		lpObj->CharSet[9]  |= CS_SET_HELMET2(lpObj->pInventory[2].m_Type);
		lpObj->CharSet[3]  |= CS_SET_HELMET3(lpObj->pInventory[2].m_Type);
	}

	// Set Armor
	if ( lpObj->pInventory[3].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[14] |= CS_SET_ARMOR1(-1);
		lpObj->CharSet[9]  |= CS_SET_ARMOR2(-1);
		lpObj->CharSet[3]  |= CS_SET_ARMOR3(-1);
	}
	else
	{
		lpObj->CharSet[14] |= CS_SET_ARMOR1(lpObj->pInventory[3].m_Type);
		lpObj->CharSet[9]  |= CS_SET_ARMOR2(lpObj->pInventory[3].m_Type);
		lpObj->CharSet[3]  |= CS_SET_ARMOR3(lpObj->pInventory[3].m_Type);
	}

	// Set Pants
	if ( lpObj->pInventory[4].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[14] |= CS_SET_PANTS1(-1);
		lpObj->CharSet[9]  |= CS_SET_PANTS2(-1);
		lpObj->CharSet[4]  |= CS_SET_PANTS3(-1);
	}
	else
	{
		lpObj->CharSet[14] |= CS_SET_PANTS1(lpObj->pInventory[4].m_Type);
		lpObj->CharSet[9]  |= CS_SET_PANTS2(lpObj->pInventory[4].m_Type);
		lpObj->CharSet[4]  |= CS_SET_PANTS3(lpObj->pInventory[4].m_Type);
	}

	// Set Gloves
	if ( lpObj->pInventory[5].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[15] |= CS_SET_GLOVES1(-1);
		lpObj->CharSet[9]  |= CS_SET_GLOVES2(-1);
		lpObj->CharSet[4]  |= CS_SET_GLOVES3(-1);
	}
	else
	{
		lpObj->CharSet[15] |= CS_SET_GLOVES1(lpObj->pInventory[5].m_Type);
		lpObj->CharSet[9]  |= CS_SET_GLOVES2(lpObj->pInventory[5].m_Type);
		lpObj->CharSet[4]  |= CS_SET_GLOVES3(lpObj->pInventory[5].m_Type);
	}

	// Set Boots
	if ( lpObj->pInventory[6].m_Type < ITEMGET(0,0) )
	{
		lpObj->CharSet[15] |= CS_SET_BOOTS1(-1);
		lpObj->CharSet[9]  |= CS_SET_BOOTS2(-1);
		lpObj->CharSet[5]  |= CS_SET_BOOTS3(-1);
	}
	else
	{
		lpObj->CharSet[15] |= CS_SET_BOOTS1(lpObj->pInventory[6].m_Type);
		lpObj->CharSet[9]  |= CS_SET_BOOTS2(lpObj->pInventory[6].m_Type);
		lpObj->CharSet[5]  |= CS_SET_BOOTS3(lpObj->pInventory[6].m_Type);
	}

	index = 0;

	// Set Part onf Wings
	if ( lpObj->pInventory[7].m_Type < ITEMGET(0,0) )
	{
		index |= CS_SET_WING1(-1);
	}
	else
	{
		index |= CS_SET_WING1(lpObj->pInventory[7].m_Type);
	}

	if ( lpObj->pInventory[8].m_Type != ITEMGET(13,4) )
	{
		if ( lpObj->pInventory[8].m_Type < ITEMGET(0,0) )
		{
			index |= CS_SET_HELPER(-1);
		}
		else
		{
			index |= CS_SET_HELPER(lpObj->pInventory[8].m_Type);
		}
	}
	else
	{
		index |= CS_SET_HELPER(-1);
	}

	lpObj->CharSet[5] |= index;

	int levelindex = CS_SET_SMALLLEVEL_RH(LevelSmallConvert(aIndex, 0));
	levelindex |= CS_SET_SMALLLEVEL_LH(LevelSmallConvert(aIndex, 1));
	levelindex |= CS_SET_SMALLLEVEL_HELMET(LevelSmallConvert(aIndex, 2));
	levelindex |= CS_SET_SMALLLEVEL_ARMOR(LevelSmallConvert(aIndex, 3));
	levelindex |= CS_SET_SMALLLEVEL_PANTS(LevelSmallConvert(aIndex, 4));
	levelindex |= CS_SET_SMALLLEVEL_GLOVES(LevelSmallConvert(aIndex, 5));
	levelindex |= CS_SET_SMALLLEVEL_BOOTS(LevelSmallConvert(aIndex, 6));

	lpObj->CharSet[6] = CS_SET_SMALLLEVEL1(levelindex);
	lpObj->CharSet[7] = CS_SET_SMALLLEVEL2(levelindex);
	lpObj->CharSet[8] = CS_SET_SMALLLEVEL3(levelindex);

	if ( (lpObj->pInventory[7].m_Type >= ITEMGET(12,3) && lpObj->pInventory[7].m_Type <= ITEMGET(12,6)) ||
		  lpObj->pInventory[7].m_Type == ITEMGET(13,30)  )
	{
		lpObj->CharSet[5] |= CS_SET_WING1(-1);
		
		if ( lpObj->pInventory[7].m_Type == ITEMGET(13,30) )
		{
			lpObj->CharSet[9] |= 5;
		}
		else
		{
			lpObj->CharSet[9] |= (lpObj->pInventory[7].m_Type - 2) & 0x07;
		}
	}

	// Set Excellent Items
	lpObj->CharSet[10] = 0;

	if ( lpObj->pInventory[2].IsExtItem() != FALSE )
		lpObj->CharSet[10] = (char)0x80;

	if ( lpObj->pInventory[3].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x40;

	if ( lpObj->pInventory[4].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x20;

	if ( lpObj->pInventory[5].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x10;

	if ( lpObj->pInventory[6].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x8;

	if ( lpObj->pInventory[0].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x04;

	if ( lpObj->pInventory[1].IsExtItem() != FALSE )
		lpObj->CharSet[10] |= 0x02;

	// Set Set Items
	lpObj->CharSet[11] = 0;

	if ( lpObj->pInventory[2].IsSetItem() != FALSE )
		lpObj->CharSet[11] = (char)0x80;

	if ( lpObj->pInventory[3].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x40;

	if ( lpObj->pInventory[4].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x20;

	if ( lpObj->pInventory[5].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x10;

	if ( lpObj->pInventory[6].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x8;

	if ( lpObj->pInventory[0].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x04;

	if ( lpObj->pInventory[1].IsSetItem() != FALSE )
		lpObj->CharSet[11] |= 0x02;

	gObjCalCharacter(aIndex);

	if ( lpObj->IsFullSetItem != false )
		lpObj->CharSet[11] |= 0x01;

/*
13
	0	"Guardian Angel"
	1	"Imp"
	2	"Horn of Uniria"
	3	"Horn of Dinorant"
	4	"Horn of Dark Horse"

	if ( (lpObj->pInventory[8].m_Type & 0x03) != 0 )
	{
		if ( lpObj->pInventory[8].m_Type > 0 )
		{
			lpObj->CharSet[10] |= 0x01;
		}
	}

	if ( lpObj->pInventory[8].m_Type == ITEMGET(13,4) )	// Dark Horse
	{
		lpObj->CharSet[12] |= 0x01;
	}

	if ( lpObj->pInventory[8].m_Type == ITEMGET(13,37) )	// Fenrir
	{
		lpObj->CharSet[10] &= 0xFE;
		lpObj->CharSet[12] &= 0xFE;
		lpObj->CharSet[12] |= 0x04;
		lpObj->CharSet[16] = 0;
		lpObj->CharSet[17] = 0;

		if ( lpObj->pInventory[8].IsFenrirIncLastAttackDamage() != FALSE )
		{
			lpObj->CharSet[16] |= 0x01;
		}

		if ( lpObj->pInventory[8].IsFenrirDecLastAttackDamage() != FALSE )
		{
			lpObj->CharSet[16] |= 0x02;
		}
	}
}*/





static int FrustrumX[MAX_ARRAY_FRUSTRUM];
static int FrustrumY[MAX_ARRAY_FRUSTRUM];

void InitFrustrum()
{
	double CameraViewFar = 2400.0;
	double CameraViewNear = CameraViewFar * 0.19;
	double CameraViewTarget = CameraViewFar * 0.53;
	double WidthFar = 1190.0;
	double WidthNear =  550.0;

	double p[4][3];

	p[0][0] = -WidthFar;
	p[0][1] = CameraViewFar-CameraViewTarget;
	p[0][2] = 0;
	p[1][0] = WidthFar;
	p[1][1] = CameraViewFar-CameraViewTarget;
	p[1][2] = 0;
	p[2][0] = WidthNear;
	p[2][1] = CameraViewNear - CameraViewTarget;
	p[2][2] = 0;
	p[3][0]= -WidthNear;
	p[3][1] = CameraViewNear - CameraViewTarget;
	p[3][2] = 0;

	double Angle[3];
	Angle[0] = 0;
	Angle[1] = 0;
	Angle[2] = 45.0;

	double Matrix[3][4];
	double Frustrum[4][3];

	AngleMatrix(Angle,Matrix);

	for(int i = 0; i < MAX_ARRAY_FRUSTRUM;i++)
	{
		VectorRotate((const double *)&p[i],(const double *)&Matrix[0],(double *)&Frustrum[i]);
		FrustrumX[i] = int(Frustrum[i][0]*0.01);
		FrustrumY[i] = int(Frustrum[i][1]*0.01);
	}
}








void CreateFrustrum(int x, int y, int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	for ( int i=0;i<MAX_ARRAY_FRUSTRUM;i++)
	{
		lpObj->FrustrumX[i] = FrustrumX[i] + x;
		lpObj->FrustrumY[i] = FrustrumY[i] + y;
	}
}







bool TestFrustrum2(int x, int y, int aIndex)
{
	int j = 3;
	LPOBJ lpObj = &gObj[aIndex];

	for(int i = 0; i < MAX_ARRAY_FRUSTRUM;j = i,i++)
	{
		if((lpObj->FrustrumX[i]- x) * (lpObj->FrustrumY[j]-y) - (lpObj->FrustrumX[j]-x) * (lpObj->FrustrumY[i]-y) < 0.0f)
		{
			return false;
		}
	}
	return true;
}






BOOL gObjCheckViewport(int aIndex, int x, int y)
{
	LPOBJ lpObj = &gObj[aIndex];

	if(x < lpObj->X - 15  || x > lpObj->X + 15 || y < lpObj->Y - 15 || y > lpObj->Y + 15)
	{
		return false;
	}

	int j = 3;

	for(int i = 0; i < MAX_ARRAY_FRUSTRUM; j = i, i++)
	{
		int frustrum = (lpObj->FrustrumX[i]- x) * (lpObj->FrustrumY[j]-y) - (lpObj->FrustrumX[j]-x) * (lpObj->FrustrumY[i]-y);
		if(frustrum < 0)
		{
			return false;
		}
	}
	return true;
}






void gObjViewportClose(LPOBJ lpObj)
{
	int tObjNum,i;
	int MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	if(lpObj->Connected == PLAYER_PLAYING)
	{
		for(int n = 0; n < MVL; n++)
		{
			if(lpObj->VpPlayer2[n].state != 0)
			{
				if(lpObj->VpPlayer2[n].type != 5)
				{
					tObjNum = lpObj->VpPlayer2[n].number;

					i = 0;

					while( true )
					{
						if(gObj[tObjNum].VpPlayer[i].number == lpObj->m_Index)
						{
							if(gObj[tObjNum].VpPlayer[i].type == lpObj->Type)
							{
								gObj[tObjNum].VpPlayer[i].state = 3;
								break;
							}
						}

						if(i < MVL-1)
						{
							i++;
						}
						else
						{
							break;
						}
					}

					i = 0;

					while( true )
					{
						if(gObj[tObjNum].VpPlayer2[i].number == lpObj->m_Index)
						{
							if(gObj[tObjNum].VpPlayer2[i].type == lpObj->Type)
							{
								gObj[tObjNum].VpPlayer2[i].state = 0;
								break;
							}
						}

						if(i < MVL-1)
						{
							i++;
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}
	gObjClearViewport(lpObj);
}






void gObjViewportListCreate(short aIndex)
{
	int result;
	LPOBJ lpObj;
	int mapnum;

	if(OBJMAX_RANGE(aIndex) == 0)
	{
		return;
	}

	lpObj = &gObj[aIndex];

	if(lpObj->Connected != PLAYER_PLAYING)
	{
		return;
	}

	if(lpObj->RegenOk > 0)
	{
		return;
	}

	mapnum = lpObj->MapNumber;
	gItemLoop2 = 0;

	if(lpObj->Type == OBJ_USER)
	{
		MapClass * lpMap = &MapC[mapnum];

		for(int n = 0; n < MAX_MAPITEM; n++)
		{
			if(lpMap->m_cItem[n].live)
			{
				gItemLoop2++;

				if(lpMap->m_cItem[n].m_State == 1 || lpMap->m_cItem[n].m_State == 2)
				{
					if(gObjCheckViewport(aIndex,lpMap->m_cItem[n].px,lpMap->m_cItem[n].py) == 1)
					{
						result = ViewportAdd(aIndex,n,5);
					}
				}
			}
		}
	}

	if(aIndex == 0)
	{
		gItemLoopMax = gItemLoop2;
		gItemLoop = gItemLoop2;
	}

	LPOBJ lpTempObj;

	if(lpObj->Type == OBJ_USER 	)
	{

#if (MP==1)
#pragma omp parallel for
#endif
		for(int n = 0; n < OBJMAX; n++)
		{
			lpTempObj = &gObj[n];

			if(lpTempObj->Connected == PLAYER_PLAYING && aIndex != n)
			{
				if(lpTempObj->m_State == 1 || lpTempObj->m_State == 2)
				{
					if(mapnum == lpTempObj->MapNumber)
					{
						if(gObjCheckViewport(aIndex,lpTempObj->X,lpTempObj->Y) == 1)
						{
							result = ViewportAdd(aIndex,n,lpTempObj->Type);
							result = ViewportAdd2(n,aIndex,gObj[aIndex].Type);
						}
					}
				}
			}
		}
	}
	else if(lpObj->Type == OBJ_MONSTER 
 
		|| lpObj->Type == OBJ_NPC 
		|| lpObj->Type == OBJ_NPC

		)
	{

#if (MP==1)
#pragma omp parallel for
#endif
		for(int n = OBJ_MAXMONSTER; n < OBJMAX; n++)
		{
			lpTempObj = &gObj[n];

			if(lpTempObj->Connected == PLAYER_PLAYING && aIndex != n)
			{
				if(lpTempObj->m_State == 1 || lpTempObj->m_State == 2)
				{
					if(mapnum == lpTempObj->MapNumber)
					{
						if(gObjCheckViewport(aIndex,lpTempObj->X,lpTempObj->Y) == 1)
						{
							result = ViewportAdd(aIndex,n,gObj[n].Type);
							result = ViewportAdd2(n,aIndex,gObj[aIndex].Type);
						}
					}
				}
			}
		}
	}
}






int  ViewportAdd(int aIndex, int aAddIndex, int aType)
{
	int blank = -1;
	int count = 0;
	LPOBJ lpObj = &gObj[aIndex];
	int MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	for(int n = 0; n < MVL; n++)
	{
		if(lpObj->VpPlayer[n].state != 0)
		{
			if(lpObj->VpPlayer[n].number == aAddIndex)
			{
				if(lpObj->VpPlayer[n].type == aType)
				{
					return -1;
				}
			}
		}
		else
		{
			if(blank < 0)
			{
				blank = n;
			}
		}
	}

	if(blank < 0)
	{
		return -1;
	}


	lpObj->VpPlayer[blank].state = 1;
	lpObj->VpPlayer[blank].number = aAddIndex;
	lpObj->VpPlayer[blank].type = aType;
	lpObj->VPCount ++;

	if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
	{
		if(aType == 1)
		{
			if(lpObj->m_iCurrentAI != 0)
			{
				lpObj->m_Agro.SetAgro(aAddIndex,1000);
			}
		}
	}
	return blank;
}






int  ViewportAdd2(int aIndex, int aAddIndex, int aType)
{
	int blank = -1;
	int count = 0;
	LPOBJ lpObj = &gObj[aIndex];
	int MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	for(int n = 0; n < MVL; n++)
	{
		if(lpObj->VpPlayer2[n].state != 0)
		{
			if(lpObj->VpPlayer2[n].number == aAddIndex)
			{
				if(lpObj->VpPlayer2[n].type == aType)
				{
					return -1;
				}
			}
		}
		else
		{
			if(blank < 0)
			{
				blank = n;
			}
		}
	}

	if(blank < 0)
	{
		return -1;
	}


	lpObj->VpPlayer2[blank].state = 1;
	lpObj->VpPlayer2[blank].number = aAddIndex;
	lpObj->VpPlayer2[blank].type = aType;
	lpObj->VPCount2 ++;

	return blank;
}






void ViewportDel(short aIndex, int aDelIndex)
{
	if(gObjIsConnected(aIndex) == 0)
	{
		return;
	}

	if(gObjIsConnected(aDelIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];
	int MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	for(int n = 0; n < MVL; n++)
	{
		if(lpObj->VpPlayer[n].state == 1 || lpObj->VpPlayer[n].state == 2)
		{
			if(lpObj->VpPlayer[n].number == aDelIndex)
			{
				lpObj->VpPlayer[n].state = 0;
				lpObj->VpPlayer[n].number = -1;
				lpObj->VPCount --;
			}
		}
	}
}






void Viewport2Del(short aIndex, int aDelIndex)
{
	if(gObjIsConnected(aIndex) == 0)
	{
		return;
	}

	if(gObjIsConnected(aDelIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];
	int MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	for(int n = 0; n < MVL; n++)
	{
		if(lpObj->VpPlayer2[n].state == 1 || lpObj->VpPlayer2[n].state == 2)
		{
			if(lpObj->VpPlayer2[n].number == aDelIndex)
			{
				lpObj->VpPlayer2[n].state = 0;
				lpObj->VpPlayer2[n].number = -1;
				lpObj->VPCount2 --;
			}
		}
	}
}






void gObjViewportAllDel(short aIndex)
{
	if(gObjIsConnected(aIndex) == 0)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];
	int MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	for(int n = 0; n < MVL; n++)
	{
		if(lpObj->VpPlayer[n].state == 1 || lpObj->VpPlayer[n].state == 2)
		{
			Viewport2Del(lpObj->VpPlayer[n].number,aIndex);
		}

		if(lpObj->VpPlayer2[n].state == 1 || lpObj->VpPlayer2[n].state == 2)
		{
			ViewportDel(lpObj->VpPlayer2[n].number,aIndex);
		}
	}
}






void gObjViewportListDestroy(short aIndex)
{
	short tObjNum;
	int n;
	LPOBJ lpObj;
	int MVL;

	if(OBJMAX_RANGE(aIndex) == 0)
	{
		return;
	}

	if(gObj[aIndex].Connected < PLAYER_PLAYING)
	{
		return;
	}

	lpObj = &gObj[aIndex];
	MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	for(n = 0; n < MVL; n++)
	{
		int mapnum;
		if(lpObj->VpPlayer[n].state == 1 || lpObj->VpPlayer[n].state == 2)
		{
			tObjNum = lpObj->VpPlayer[n].number;

			switch(lpObj->VpPlayer[n].type)
			{
			case 5:
				mapnum = lpObj->MapNumber;

				if(MapC[mapnum].m_cItem[tObjNum].IsItem() == 1)
				{
					if(MapC[mapnum].m_cItem[tObjNum].m_State == 8)
					{
						lpObj->VpPlayer[n].state = 3;
					}
					else
					{
						if(gObjCheckViewport(aIndex,MapC[mapnum].m_cItem[tObjNum].px,MapC[mapnum].m_cItem[tObjNum].py) == 0)
						{
							lpObj->VpPlayer[n].state = 3;
						}
					}
				}
				else
				{
					if(MapC[mapnum].m_cItem[tObjNum].live == 0 || MapC[mapnum].m_cItem[tObjNum].Give == 0)
					{
						lpObj->VpPlayer[n].state = 3;
					}
					else
					{
						lpObj->VpPlayer[n].state = 3;
					}
				}
				break;
			default : 
				if(gObj[tObjNum].m_State == 1)
				{
					if(gObj[tObjNum].Live == 0)
					{
						lpObj->VpPlayer[n].state = 3;
					}
				}

				if(gObj[tObjNum].Connected  == PLAYER_EMPTY ||
					gObj[tObjNum].m_State == 8 ||
					gObj[tObjNum].Teleport != 0 ||
					gObj[tObjNum].m_State == 32)
				{
					lpObj->VpPlayer[n].state = 3;
				}
				else
				{
					if(gObjCheckViewport(aIndex,gObj[tObjNum].X,gObj[tObjNum].Y) == 0)
					{
						lpObj->VpPlayer[n].state = 3;

						if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
						{
							if(gObj[tObjNum].Type == OBJ_USER)
							{
								if(lpObj->m_iCurrentAI != 0)
								{
									lpObj->m_Agro.DelAgro(tObjNum);
								}
							}
						}
					}
				}
				break;
			}
		}

		if(lpObj->VpPlayer2[n].state == 1 || lpObj->VpPlayer2[n].state == 2)
		{
			tObjNum = lpObj->VpPlayer2[n].number;

			if(gObj[tObjNum].Connected < PLAYER_PLAYING)
			{
				lpObj->VpPlayer2[n].state = 0;
				lpObj->VpPlayer2[n].number = -1;
				lpObj->VPCount2 --;
			}
			else
			{
				if(gObjCheckViewport(tObjNum,lpObj->X,lpObj->Y) == 0)
				{
					lpObj->VpPlayer2[n].state = 0;
					lpObj->VpPlayer2[n].number = -1;
					lpObj->VPCount2 --;
				}
			}
		}
	}
}

struct PMSG_ANS_PSHOP_VIEWPORT_NOTIFY {
	struct PWMSG_HEAD2 h;
	unsigned char btCount;
};

struct PMSG_PSHOP_VIEWPORT_NOTIFY {
  unsigned char btNumberH;
  unsigned char btNumberL;
  char szPShopText[36];
};

void PShop_ViewportListRegenarate(short aIndex)
{
	if(gObjIsConnected(aIndex) == 0)
	{
		return ;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if(lpObj->Type != OBJ_USER)
	{
		return;
	}

	if(lpObj->RegenOk > 0)
	{
		return;
	}

	if(lpObj->CloseCount > -1)
	{
		return;
	}

	BYTE cBUFFER[6000];
	int iVpOpenCount = 0;
	int iVpAddCount = 0;

	PMSG_ANS_PSHOP_VIEWPORT_NOTIFY * lpMsg = (PMSG_ANS_PSHOP_VIEWPORT_NOTIFY *)&cBUFFER;
	PMSG_PSHOP_VIEWPORT_NOTIFY * lpMsgBody = (PMSG_PSHOP_VIEWPORT_NOTIFY *)&cBUFFER[6];

	int iPShopOpenIndex[MAX_VIEWPORT];

	if(lpObj->m_bPShopRedrawAbs != 0)
	{
		memset(lpObj->m_iVpPShopPlayer,0x00,sizeof(lpObj->m_iVpPShopPlayer));
		lpObj->m_wVpPShopPlayerCount = 0;
		lpObj->m_bPShopRedrawAbs = 0;
	}

	for(int n = 0; n < MAX_VIEWPORT; n++)
	{
		if(lpObj->VpPlayer[n].state == 2 && lpObj->VpPlayer[n].type == OBJ_USER && gObj[lpObj->VpPlayer[n].number].m_bPShopOpen == 1)
		{
			iPShopOpenIndex[iVpOpenCount] = lpObj->VpPlayer[n].number;
			iVpOpenCount++;

			if(lpObj->m_wVpPShopPlayerCount > 0 && lpObj->m_wVpPShopPlayerCount <= MAX_VIEWPORT)
			{
				int found = 0;

				for(int i = 0; i < lpObj->m_wVpPShopPlayerCount; i++)
				{
					if(lpObj->m_iVpPShopPlayer[i] == lpObj->VpPlayer[n].number)
					{
						found = 1;
						break;
					}
				}

				if(found == 0)
				{
					lpMsgBody[iVpAddCount].btNumberL = SET_NUMBERL(WORD(lpObj->VpPlayer[n].number));
					lpMsgBody[iVpAddCount].btNumberH = SET_NUMBERH(WORD(lpObj->VpPlayer[n].number));
					memcpy(lpMsgBody[iVpAddCount].szPShopText,gObj[lpObj->VpPlayer[n].number].m_szPShopText,sizeof(gObj[lpObj->VpPlayer[n].number].m_szPShopText));
					iVpAddCount++;
				}
			}
			else if(lpObj->m_wVpPShopPlayerCount == 0)
			{
				lpMsgBody[iVpAddCount].btNumberL = SET_NUMBERL(WORD(lpObj->VpPlayer[n].number));
				lpMsgBody[iVpAddCount].btNumberH = SET_NUMBERH(WORD(lpObj->VpPlayer[n].number));
				memcpy(lpMsgBody[iVpAddCount].szPShopText,gObj[lpObj->VpPlayer[n].number].m_szPShopText,sizeof(gObj[lpObj->VpPlayer[n].number].m_szPShopText));
				iVpAddCount++;
			}
			else
			{
				LogAdd("[PShop] ERROR : lpObj->m_wVpPShopPlayerCount is OUT of BOUND : %d",lpObj->m_wVpPShopPlayerCount);
			}
		}
	}

	memset(lpObj->m_iVpPShopPlayer,0x00,sizeof(lpObj->m_iVpPShopPlayer));
	lpObj->m_wVpPShopPlayerCount = 0;

	if(iVpOpenCount > 0 && iVpOpenCount <= MAX_VIEWPORT)
	{
		for(int n = 0; n < iVpOpenCount; n++)
		{
			lpObj->m_iVpPShopPlayer[n] = iPShopOpenIndex[n];
		}
		lpObj->m_wVpPShopPlayerCount = iVpOpenCount;
	}
	else if(iVpOpenCount != 0)
	{
		LogAdd("[PShop] ERROR : iVpOpenCount is OUT of BOUND: %d",iVpOpenCount);
	}

	if(iVpAddCount > 0 && iVpAddCount <= MAX_VIEWPORT)
	{
		lpMsg->btCount = iVpAddCount;
		PHeadSubSetW((unsigned char *)lpMsg,0x3F,0,sizeof(PMSG_ANS_PSHOP_VIEWPORT_NOTIFY)+sizeof(PMSG_PSHOP_VIEWPORT_NOTIFY)*iVpAddCount);
		DataSend(aIndex,(unsigned char *)lpMsg,((lpMsg->h.sizeL & 0xFF)& 0xFF | ((lpMsg->h.sizeH & 0xFF) & 0xFF) << 8) & 0xFFFF);
	}
	else if(iVpAddCount != 0)
	{
		LogAdd("[PShop] ERROR : iVpAddCount is OUT of BOUND: %d",iVpAddCount);
	}

	if(gObj[aIndex].m_bPShopWantDeal == 1)
	{
		if(gObjIsConnected(gObj[aIndex].m_iPShopDealerIndex) != 0)
		{
			if(gObj[gObj[aIndex].m_iPShopDealerIndex].Type == OBJ_USER)
			{
				if(gObj[gObj[aIndex].m_iPShopDealerIndex].m_bPShopOpen == 0)
				{
					gObj[aIndex].m_bPShopWantDeal = 0;
					gObj[aIndex].m_iPShopDealerIndex = -1;
					memset(gObj[aIndex].m_szPShopDealerName,0,sizeof(gObj[aIndex].m_szPShopDealerName));

					CGPShopAnsDealerClosedShop(aIndex,gObj[aIndex].m_iPShopDealerIndex);
				}
				else if(gObj[gObj[aIndex].m_iPShopDealerIndex].CloseCount >= 0 || gObj[aIndex].CloseCount >= 0)
				{
					gObj[aIndex].m_bPShopWantDeal = 0;
					gObj[aIndex].m_iPShopDealerIndex = -1;
					memset(gObj[aIndex].m_szPShopDealerName,0,sizeof(gObj[aIndex].m_szPShopDealerName));

					CGPShopAnsDealerClosedShop(aIndex,gObj[aIndex].m_iPShopDealerIndex);
				}
				else if(gObj[gObj[aIndex].m_iPShopDealerIndex].m_bPShopItemChange == 1)
				{
					CGPShopAnsBuyList(aIndex,gObj[aIndex].m_iPShopDealerIndex,1,1);
				}
			}
			else
			{
				gObj[aIndex].m_bPShopWantDeal = 0;
				gObj[aIndex].m_iPShopDealerIndex = -1;
				memset(gObj[aIndex].m_szPShopDealerName,0,sizeof(gObj[aIndex].m_szPShopDealerName));

				CGPShopAnsDealerClosedShop(aIndex,gObj[aIndex].m_iPShopDealerIndex);
			}
		}
		else
		{
			gObj[aIndex].m_bPShopWantDeal = 0;
			gObj[aIndex].m_iPShopDealerIndex = -1;
			memset(gObj[aIndex].m_szPShopDealerName,0,sizeof(gObj[aIndex].m_szPShopDealerName));

			CGPShopAnsDealerClosedShop(aIndex,gObj[aIndex].m_iPShopDealerIndex);
		}
	}
}

bool PShop_CheckInventoryEmpty(short aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	for(int i = MAIN_INVENTORY_SIZE; i < INVENTORY_SIZE; i++)
	{
		if(lpObj->Inventory1[i].IsItem() == 1)
		{
			return false;
		}
	}
	return true;
}






void gObjStateSetCreate(int aIndex)
{
 	LPOBJ lpObj = &gObj[aIndex];

	DWORD tmp=0;

	if(lpObj->Connected != PLAYER_PLAYING)
	{
		return;
	}

	DWORD dwNowTick = GetTickCount();
	
	if(lpObj->DieRegen == 1)
	{
		if( (dwNowTick - lpObj->RegenTime) > lpObj->MaxRegenTime + 1000)
		{
			lpObj->DieRegen = 2;
			lpObj->m_State = 8;
		}
	}

	if(lpObj->Type == OBJ_USER)
	{
		if(lpObj->m_State == 8)
		{
			gObjReady4Relife(lpObj);
		}
		else
		{
			gObjCheckTimeOutValue(lpObj,(DWORD &)dwNowTick);
		}
	}

	if(lpObj->Teleport == 1)
	{
		if(lpObj->DieRegen != 0)
		{
			lpObj->Teleport = 0;
		}
		else if(GetTickCount() - lpObj->TeleportTime > 100)
		{
			lpObj->Teleport = 2;
		}
	}
	else if(lpObj->Teleport == 2)
	{
		lpObj->Teleport = 3;

		if(lpObj->Type == OBJ_USER)
		{
			lpObj->TX = lpObj->X;
			lpObj->TY = lpObj->Y;

			CreateFrustrum(lpObj->X,lpObj->Y,aIndex);
			GCTeleportSend(&gObj[aIndex],0,lpObj->MapNumber,(BYTE)lpObj->X,(BYTE)lpObj->Y,lpObj->Dir);
			gObjViewportListProtocolCreate(lpObj);

 
			if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE && g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
			{
				g_CastleSiege.NotifySelfCsJoinSide(aIndex);
				g_CastleSiege.NotifyCsSelfLeftTime(aIndex);
			}

			lpObj->Teleport = 0;
		}
		else if(lpObj->Type == OBJ_NPC && lpObj->Class == 229)
		{
			int x = lpObj->X;
			int y = lpObj->Y;
			
			lpObj->X = x;
			lpObj->Y = y;

			lpObj->TX = lpObj->X;
			lpObj->TY = lpObj->Y;

			CreateFrustrum(lpObj->X,lpObj->Y,aIndex);

			lpObj->m_State = 1;
			lpObj->PathStartEnd = 0;
		}
		else if(lpObj->Type == OBJ_MONSTER)
		{
			lpObj->TX = lpObj->X;
			lpObj->TY = lpObj->Y;

			CreateFrustrum(lpObj->X,lpObj->Y,aIndex);

			gObjViewportListCreate(lpObj->m_Index);
			gObjViewportListProtocolCreate(lpObj);

			lpObj->Teleport = 0;
			lpObj->PathStartEnd = 0;
			lpObj->PathCur = 0;
			lpObj->PathCount = 0;
		}
		else 
		{
			int x,y;

			if(lpObj->m_RecallMon >= 0)
			{
				x = lpObj->X;
				y = lpObj->Y;
			}
			else
			{
				x = lpObj->X + Random(0,5) - 3;
				y = lpObj->Y + Random(0,5) - 3;
			}

			lpObj->X = x;
			lpObj->Y = y;

			lpObj->TX = lpObj->X;
			lpObj->TY = lpObj->Y;

			if(lpObj->m_RecallMon >= 0)
			{
				gObjViewportListProtocolCreate(lpObj);
				lpObj->PathStartEnd = 0;
			}
		}
	}

	if(lpObj->RegenOk == 2 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_State = 1;
		lpObj->RegenOk = 3;
		lpObj->X = lpObj->RegenMapX;
		lpObj->Y = lpObj->RegenMapY;
		lpObj->MapNumber = lpObj->RegenMapNumber;

		lpObj->TX = lpObj->X;
		lpObj->TY = lpObj->Y;

		CreateFrustrum(lpObj->X,lpObj->Y,aIndex);

		if(DragonEvent->GetState() > 0)
		{
			if(DragonEvent->GetMapNumber() == lpObj->MapNumber)
			{
				GCMapEventStateSend(lpObj->MapNumber,1,1);
			}
		}

 
		if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE )
		{
			GCAnsCsNotifyStart(lpObj->m_Index, CHECK_CLASS(g_CastleSiege.GetCastleState(), CASTLESIEGE_STATE_STARTSIEGE));
			
			if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
			{
				g_CastleSiege.NotifySelfCsJoinSide(lpObj->m_Index);
				g_CastleSiege.NotifyCsSelfLeftTime(lpObj->m_Index);
			}
		}


		gEledoradoEvent.CheckGoldDercon(lpObj->MapNumber);

		if(gTamaJJangEvent != 0 && gAppearTamaJJang != 0)
		{
			if(lpObj->MapNumber == 0)
			{
				GCMapEventStateSend(0,gAppearTamaJJang,2);
			}
		}
	}
}

struct PMSG_CHARREGEN {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char subcode;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char MapX;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char MapY;
  /*<thisrel this+0x6>*/ /*|0x1|*/ unsigned char MapNumber;
  /*<thisrel this+0x7>*/ /*|0x1|*/ unsigned char Dir;
  /*<thisrel this+0x8>*/ /*|0x2|*/ unsigned short Life;
  /*<thisrel this+0xa>*/ /*|0x2|*/ unsigned short Mana;
  /*<thisrel this+0xc>*/ /*|0x2|*/ unsigned short wShield;
  /*<thisrel this+0xe>*/ /*|0x2|*/ unsigned short BP;
  /*<thisrel this+0x10>*/ /*|0x4|*/ unsigned long Exp;
  /*<thisrel this+0x14>*/ /*|0x4|*/ unsigned long Money;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};

void gObjSetState()
{
	LPOBJ lpObj;

#if (MP==1)
#pragma omp parallel for private(lpObj)
#endif
	for(int n = 0; n < OBJMAX; n++)
	{
		lpObj = &gObj[n];

		if(lpObj->Connected == PLAYER_PLAYING)
		{
			if(lpObj->m_State == 1)
			{
				lpObj->m_State = 2;
				if(lpObj->RegenOk == 3)
				{
					lpObj->RegenOk = 0;
				}
			}
	
			if(lpObj->Teleport == 3)
			{
				lpObj->Teleport = 0;
			}
	
			if(lpObj->DieRegen == 2)
			{
				int mapnum = lpObj->MapNumber;
				int x = lpObj->X;
				int y = lpObj->Y;
	
				lpObj->m_bAttackerKilled = 0;
	
				if(DS_MAP_RANGE(lpObj->MapNumber))
				{
					if(lpObj->Type >= OBJ_MONSTER)
					{
						g_DevilSquare.gDevilSquareMonsterRegen(lpObj);
						continue;
					}
				}

 
				if(lpObj->m_iCurrentAI != 0 && lpObj->m_iRegenType != 0)
					continue;

				if ( lpObj->MapNumber == MAP_INDEX_CRYWOLF_FIRSTZONE )
				{
					if ( g_CrywolfSync.GetCrywolfState() == 3 && lpObj->Type >= OBJ_MONSTER )
						continue;
				}

	
				if(lpObj->MapNumber == MAP_INDEX_KANTURU_BOSS && lpObj->Type == OBJ_MONSTER)
				{
					continue;
				}
	
				if(lpObj->m_iCurrentAI != 0 && lpObj->m_iRegenType != 0)
				{
					continue;
				}

				if(lpObj->m_bIsInMonsterHerd != 0)
				{
					if(lpObj->m_lpMonsterHerd != 0)
					{
						lpObj->m_lpMonsterHerd->MonsterRegenAction(lpObj);
					}
					continue;
				}
	
				if(BC_MAP_RANGE(lpObj->MapNumber) && lpObj->Type >= OBJ_MONSTER)
				{
					if(lpObj->Class == 131)
					{
						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_bCASTLE_DOOR_LIVE = 0;
						g_BloodCastle.m_BridgeData[lpObj->m_cBloodCastleIndex].m_bBC_DOOR_TERMINATE_COMPLETE = 1;
						g_BloodCastle.m_BridgeData[lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_MAX_COUNT = g_BloodCastle.GetCurrentLiveUserCount(lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1) * 2;
	
						g_BloodCastle.m_BridgeData[lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_KILL_COUNT = 0;
	
						if(g_BloodCastle.m_BridgeData[lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_MAX_COUNT > 10)
						{
							g_BloodCastle.m_BridgeData[lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1].m_iBC_BOSS_MONSTER_MAX_COUNT = 10;
						}
	
						g_BloodCastle.SendCastleDoorBlockInfo(lpObj->m_cBloodCastleIndex,0);
						g_BloodCastle.ReleaseCastleDoor(lpObj->m_cBloodCastleIndex);
	
						if(g_BloodCastle.GetCurrentState(lpObj->m_cBloodCastleIndex) == 2)
						{
							g_BloodCastle.SetBossMonster(lpObj->m_cBloodCastleIndex);
						}
					}
	
					if(BC_STATUE_RANGE(lpObj->Class - 132) && BC_MAP_RANGE(lpObj->MapNumber))
					{
						int TopHitUser = gObjMonsterTopHitDamageUser(lpObj);
						int level = lpObj->Class - 132;
	
						int type = ItemGetNumberMake(13,19);
	
						ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber + 236,(BYTE)lpObj->X,(BYTE)lpObj->Y,type,level,0,0,0,0,TopHitUser,0,0);
	
						g_BloodCastle.m_BridgeData[lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1].m_btBC_QUEST_ITEM_NUMBER = level;
	
						LogAdd("[Blood Castle] (%d) Ultimate Weapon Dropped -> (%s)",
							lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1+1, (level !=0)?((level==1)?"Sword":"Crossbow"):"Staff");
					}

					if(lpObj->m_PosNum == -1)
					{
						gObjDel(lpObj->m_Index);
						continue;
					}

					if(lpObj->Type == OBJ_MONSTER)
					{
						if(lpObj->Class != 131 && BC_STATUE_RANGE(lpObj->Class - 132)== 0)
						{
							g_BloodCastle.ChangeMonsterState(lpObj->MapNumber - MAP_INDEX_BLOODCASTLE1,lpObj->m_Index);
						}
					}
				}

				if(lpObj->m_Attribute == 60)
				{
					gObjDel(lpObj->m_Index);
					continue;
				}

 
				if(lpObj->m_Attribute == 61)
				{
					gObjDel(lpObj->m_Index);
					continue;
				}

				if(lpObj->m_Attribute == 62)
				{
					switch ( lpObj->Class )
					{
						case 300:	case 301:	case 302:	case 303:	
							gObjDel(lpObj->m_Index);
							continue;
					}

					if ( (lpObj->m_dwLastCheckTick+600000) < GetTickCount() )
					{
						gObjDel(lpObj->m_Index);
						continue;
					}
				}


				if(lpObj->Type >= OBJ_MONSTER)
				{
					if(lpObj->Class == 287 || lpObj->Class == 286)
					{
						g_CsNPC_Mercenary.DeleteMercenary(lpObj->m_Index);
						gObjDel(lpObj->m_Index);
						continue;
					}
				}

 
				if ( lpObj->Type >= OBJ_MONSTER && lpObj->Class == 278 )
				{
					g_CsNPC_LifeStone.DeleteLifeStone(lpObj->m_Index);
					gObjDel(lpObj->m_Index);
					continue;
				}


				int State = 1;

				if(lpObj->Type >= OBJ_MONSTER)
				{
					if(lpObj->Class == 44 && DragonEvent->GetState() == 0)
					{
						State = 0;
					}

					if(lpObj->Class == 53	||
						lpObj->Class == 54	||
						lpObj->Class == 55	||
						lpObj->Class == 56)
					{
						State = 0;
						lpObj->Life = lpObj->MaxLife;
						lpObj->DieRegen = 0;
					}
	
					if(lpObj->Class >= 78 && lpObj->Class <= 83)
					{
						State = 0;
						lpObj->Life = lpObj->MaxLife;
						lpObj->DieRegen = 0;
					}
	
					if(lpObj->Class == 77)
					{
						int i_shield = lpObj->m_SkyBossMonSheildLinkIndex;
	
						if(i_shield != -1)
						{	
							gObj[i_shield].Life = gObj[i_shield].MaxLife;
						}	
					}
				}

				PMSG_CHARREGEN pMsg;

				if(State != 0)
				{
					lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
					lpObj->Mana = lpObj->MaxMana + lpObj->AddMana;
					lpObj->iShield = lpObj->iMaxShield + lpObj->iAddShield;

					lpObj->Live = 1;
					lpObj->m_PoisonBeattackCount = 0;
					lpObj->m_ColdBeattackCount = 0;
					lpObj->m_ViewState = 0;
					lpObj->Teleport = 0;

					for(int i = 0; i < MAX_SELF_DEFENSE; i++)
					{
						lpObj->SelfDefenseTime[i] = 0;
					}

					gObjTimeCheckSelfDefense(lpObj);

					lpObj->m_ViewSkillState &= 0xFFFFFFFE;
					lpObj->m_ViewSkillState &= 0xFFFFFFFD;

					gObjClearViewport(lpObj);

					if(lpObj->Type == OBJ_USER)
					{
						if(g_iUseCharacterAutoRecuperationSystem != 0 && lpObj->Level <= g_iCharacterRecuperationMaxLevel)
						{
							lpObj->m_iAutoRecuperationTime = GetTickCount();
						}
						else
						{
							lpObj->m_iAutoRecuperationTime = 0;
						}

						lpObj->dwShieldAutoRefillTimer = GetTickCount();

						if(lpObj->m_iSkillNPCHelpTime > 0)
						{
							lpObj->m_iSkillNPCHelpTime = 0;
							lpObj->m_iSkillNPCDefense = 0;
							lpObj->m_iSkillNPCAttack = 0;

							lpObj->m_ViewSkillState &= 0xFDFFFFFF;

							GCStateInfoSend(lpObj,0,0x02000000);
						}

						gDarkSpirit[lpObj->m_Index].SetMode(CDarkSpirit::ePetItem_Mode::PetItem_Mode_Normal,-1);

						if(lpObj->KillerType == 3)
						{
							MapC[lpObj->MapNumber].GetRandomLengthPos((short &)lpObj->X,(short &)lpObj->Y,18);
						}
						else if(lpObj->KillerType == 2)
						{
							int w_Type = 0;

							if(lpObj->lpGuild != 0)
							{
								if(lpObj->lpGuild->WarType == 1)
								{
									w_Type = 1;
								}
							}

							if(w_Type == 0)
							{
								MapC[lpObj->MapNumber].GetRandomLengthPos((short &)lpObj->X,(short &)lpObj->Y,18);
							}
							else if(lpObj->lpGuild->WarState)
							{
								int BattleGroundIndex = lpObj->lpGuild->BattleGroundIndex;
								gBattleGetTeamPosition(BattleGroundIndex,lpObj->lpGuild->BattleTeamCode,(short &)lpObj->X,(short &)lpObj->Y);
							}
						}
						else if(lpObj->MapNumber == MAP_INDEX_LORENCIA || lpObj->MapNumber == MAP_INDEX_DUNGEON || 
							lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE1 || lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE2 ||
							lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE3 || lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE4 ||
							lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE5)
						{
							lpObj->MapNumber = MAP_INDEX_LORENCIA;
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}
						else if(DS_MAP_RANGE(lpObj->MapNumber))
						{
							g_DevilSquare.DieProcDevilSquare(lpObj);
							lpObj->MapNumber = MAP_INDEX_NORIA;
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}
						else if(lpObj->MapNumber == MAP_INDEX_ICARUS)
						{
							lpObj->MapNumber = MAP_INDEX_DEVIAS;
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}
						else if(BC_MAP_RANGE(lpObj->MapNumber))
						{
							lpObj->MapNumber = MAP_INDEX_DEVIAS;
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}
						else if(CC_MAP_RANGE(lpObj->MapNumber))
						{
							lpObj->MapNumber = MAP_INDEX_DEVIAS;
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}
						else if(KALIMA_MAP_RANGE(lpObj->MapNumber))
						{
							lpObj->MapNumber = MAP_INDEX_DEVIAS;
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}
 
						else if(lpObj->MapNumber == MAP_INDEX_CASTLEHUNTZONE)
						{
							int mgt = 106;
							short x,y,level;
							BYTE map = lpObj->MapNumber,dir;
							int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

							if(result >= 0)
							{
								lpObj->MapNumber = map;
								lpObj->X = x;
								lpObj->Y = y;
							}
						}
						else if(lpObj->MapNumber == MAP_INDEX_CASTLESIEGE)
						{
							if ( g_CsNPC_LifeStone.SetReSpawnUserXY(lpObj->m_Index) == FALSE )
							{
								int mgt = 100;
								if ( lpObj->m_btCsJoinSide == 1 )
									mgt = 105;
								else
									mgt = 100;

								short x,y,level;
								BYTE map = lpObj->MapNumber,dir;
								int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

								if(result >= 0)
								{
									lpObj->MapNumber = map;
									lpObj->X = x;
									lpObj->Y = y;
								}
							}
						}

						else if(lpObj->MapNumber == MAP_INDEX_AIDA)
						{
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}
						else if(lpObj->MapNumber == MAP_INDEX_CRYWOLF_FIRSTZONE)
						{
 
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);

							if ( g_Crywolf.GetCrywolfState() == 4 )
							{
								int mgt = 118;
								short x,y,level;
								BYTE map = lpObj->MapNumber,dir;
								int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

								if(result >= 0)
								{
									lpObj->MapNumber = map;
									lpObj->X = x;
									lpObj->Y = y;
								}
								else
								{
									MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
								}
							}
							else
							{
								MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
							}

						}
 
						else if(lpObj->MapNumber == MAP_INDEX_KANTURU_BOSS)
						{
							int mgt = 137;
							short x,y,level;
							BYTE map = lpObj->MapNumber,dir;
							int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

							if(result >= 0)
							{
								lpObj->MapNumber = map;
								lpObj->X = x;
								lpObj->Y = y;
							}

							g_KanturuBattleUserMng.DeleteUserData(lpObj->m_Index);
						}
						else if(lpObj->MapNumber == MAP_INDEX_KANTURU1)
						{
							int mgt = 138;
							short x,y,level;
							BYTE map = lpObj->MapNumber,dir;

							int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

							if(result >= 0)
							{
								lpObj->MapNumber = map;
								lpObj->X = x;
								lpObj->Y = y;
							}
						}
						else if(lpObj->MapNumber == MAP_INDEX_KANTURU2)
						{
							int mgt = 139;
							short x,y,level;
							BYTE map = lpObj->MapNumber,dir;

							int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

							if(result >= 0)
							{
								lpObj->MapNumber = map;
								lpObj->X = x;
								lpObj->Y = y;
							}
						}

						else
						{
							MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
						}

						short m_Result = g_MapServerManager.CheckMoveMapSvr(lpObj->m_Index,lpObj->MapNumber,lpObj->m_sPrevMapSvrCode);

						if(m_Result != gGameServerCode )
						{
							if(m_Result == -1)
							{
								LogAdd("[MapServerMng] Map Server Move Fail : CheckMoveMapSvr() == -1 [%s][%s] (%d)",lpObj->AccountID,lpObj->Name,lpObj->m_Index);
								continue;
							}

							int _map = lpObj->MapNumber;
							int _x = lpObj->X;
							int _y = lpObj->Y;

							lpObj->MapNumber = mapnum;
							lpObj->X = x;
							lpObj->Y = y;

							GJReqMapSvrMove(lpObj->m_Index,m_Result,_map,_x,_y);
							LogAdd("[MapServerMng] Request to Move Map Server : (%d) - [%s][%s] (%d)",m_Result,lpObj->AccountID,lpObj->Name,lpObj->m_Index);
							continue;
						}

						lpObj->TX = lpObj->X;
						lpObj->TY = lpObj->Y;

						CreateFrustrum(lpObj->X,lpObj->Y,n);

						pMsg.h.c = 0xC3;
						pMsg.h.headcode = 0xF3;
						pMsg.h.size = 0x18;
						pMsg.subcode = 0x04;
						pMsg.Dir = lpObj->Dir;
						pMsg.MapX = (BYTE)lpObj->X;
						pMsg.MapY = (BYTE)lpObj->Y;
						pMsg.Life = (WORD)lpObj->Life;
						pMsg.Mana = (WORD)lpObj->Mana;
						pMsg.Exp = lpObj->Experience;
						pMsg.MapNumber = lpObj->MapNumber;
						pMsg.Money = lpObj->Money;
						pMsg.wShield = lpObj->iShield;
						pMsg.BP = lpObj->BP;

						lpObj->PathCount = 0;

						DataSend(n,(unsigned char *)&pMsg,pMsg.h.size);

						gObjViewportListProtocolCreate(lpObj);

						if(DragonEvent->GetState())
						{
							if(DragonEvent->GetMapNumber() == lpObj->MapNumber)
							{
								GCMapEventStateSend(lpObj->MapNumber,1,1);
							}
						}

						gEledoradoEvent.CheckGoldDercon(lpObj->MapNumber);

 
						if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE )
						{
							GCAnsCsNotifyStart(lpObj->m_Index, CHECK_CLASS(g_CastleSiege.GetCastleState(), CASTLESIEGE_STATE_STARTSIEGE));

							if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
							{
								g_CastleSiege.NotifySelfCsJoinSide(lpObj->m_Index);
								g_CastleSiege.NotifyCsSelfLeftTime(lpObj->m_Index);
							}
						}


					}
					else
					{
						if(gObjMonsterRegen(lpObj)==0)
						{
							continue;
						}
						CreateFrustrum(lpObj->X,lpObj->Y,n);
					}

					lpObj->DieRegen = 0;
					lpObj->m_State = 1;
				}
			}
		}
	}

	for(int n = 0; n < MAX_NUMBER_MAP; n++)
	{
		MapC[n].StateSetDestroy();
	}
}






void gObjSecondProc()
{
	if(gDisconnect == 1)
		return;

	LPOBJ lpObj;


#if (MP==1)
#pragma omp parallel for private(lpObj)
#endif
	for(int n = 0; n < OBJMAX;n++)
	{
		lpObj = &gObj[n];

		if(lpObj->Connected == PLAYER_PLAYING)
		{
			if(lpObj->m_bMapSvrMoveQuit == 1)
			{
				if(GetTickCount() - lpObj->m_dwMapSvrQuitTick > 30000)
				{
					gObjDel(lpObj->m_Index);
					continue;
				}
			}

			gObjSkillUseProc(lpObj);
			gObjSkillBeAttackProc(lpObj);

			if(lpObj->Type == OBJ_NPC && lpObj->Class == 229)
			{
				gQeustNpcTeleport.Run(n);
			}

			if(lpObj->Type == OBJ_MONSTER)
			{
				if(lpObj->Class == 275)
				{
					gObjRefillMonsterHP(lpObj,giKundunRefillHPSec);
				}
 
				if(lpObj->Class == 283 )
				{
					g_CsNPC_GuardianStatue.GuardianStatueAct(lpObj->m_Index);
					continue;
				}

				if(lpObj->Class == 278 )
				{
					g_CsNPC_LifeStone.LifeStoneAct(lpObj->m_Index);
					continue;
				}

				if(lpObj->Class == 285)
				{
					g_CsNPC_Guardian.GuardianAct(lpObj->m_Index);
					continue;
				}

 
				if(lpObj->Class == 288)
				{
					g_CsNPC_CannonTower.CannonTowerAct(lpObj->m_Index);
					continue;
				}

				g_Crywolf.CrywolfMonsterAct(lpObj->m_Index);


			}

			if(lpObj->Type == OBJ_NPC)
			{
 
				if ( CHECK_LIMIT2(lpObj->Class, 204, 210) )
				{
					g_Crywolf.CrywolfNpcAct(lpObj->m_Index);
				}

				if ( lpObj->Class == 216 )
				{
					g_CsNPC_CastleCrown.CastleCrownAct(lpObj->m_Index);
					continue;
				}

				if ( CHECK_LIMIT2(lpObj->Class, 217, 219) )
				{
					g_CsNPC_CastleCrownSwitch.CastleCrownSwitchAct(lpObj->m_Index);
					continue;
				}



				if(lpObj->Class == 221 || lpObj->Class == 222)
				{
					g_CsNPC_Weapon.WeaponAct(lpObj->m_Index);
				}
			}

			if(lpObj->Type == OBJ_USER)
			{
				gObjManaPotionFill(lpObj);
				gObjRestPotionFill(lpObj);

				gObjCheckXYMapTile(lpObj,3);

				if(lpObj->ChatLimitTime > 0)
				{
					lpObj->ChatLimitTimeSec++;

					if(lpObj->ChatLimitTimeSec > 60)
					{
						lpObj->ChatLimitTimeSec = 0;
						lpObj->ChatLimitTime--;

						if(lpObj->ChatLimitTime < 1)
						{
							lpObj->ChatLimitTime = 0;
							MsgOutput(lpObj->m_Index,"Your level should be at least level 100");
						}
					}
				}

				if(g_iUseCharacterAutoRecuperationSystem != 0)
				{
					if(lpObj->Level <= g_iCharacterRecuperationMaxLevel)
					{
						gProcessAutoRecuperation(lpObj);
					}
				}
	
				if(lpObj->Type == OBJ_USER)
				{
					gObjShieldAutoRefill(lpObj);
				}
	
				if(lpObj->Type == OBJ_USER && lpObj->m_LastTeleportTime > 0)
				{
					lpObj->m_LastTeleportTime--;
				}
	
				gObjDelayLifeCheck(n);
				gObjSecondDurDown(lpObj);
	
				if(lpObj->PartyNumber >= 0)
				{
					gParty.PartyMemberLifeSend(lpObj->PartyNumber);
				}
	
				if(lpObj->m_ShopTime >= 1 && lpObj->m_ShopTime < 255)
				{
					lpObj->m_ShopTime++;
				}
	
				int BattleGround = 1;
				int m_BattleTimer = gCheckBattleGroundTimer();
	
				if((lpObj->Authority & 2) == 2)
				{
					BattleGround = 0;
					GCTimeViewSend(lpObj->m_Index,m_BattleTimer);
				}
	
				if(lpObj->MapNumber == MAP_INDEX_BATTLESOCCER && BattleGround == 1)
				{
					BattleGround = 1;
	
					if(lpObj->lpGuild != 0)
					{
						if(lpObj->lpGuild->WarState != 0)
						{
							int CheckBattleGround = gCheckBattleGround(lpObj);
	
							if(CheckBattleGround != lpObj->lpGuild->BattleGroundIndex)
							{
								if(lpObj->lpGuild->WarType == 1)
								{
									BattleGround = 0;
								}
								else
								{
									BattleGround = 0;
								}
							}
							else
							{
								BattleGround = 0;
							}
						}
					}
					else
					{
						BattleGround = 1;
					}
	
					if(BattleGround != 0)
					{
						int CheckBattleGround = gCheckBattleGround(lpObj);
		
						if(CheckBattleGround >= 0)
						{
							gObjMoveGate(lpObj->m_Index,17);
						}	
					}
				}
			}
		}

		if(lpObj->Connected >= PLAYER_LOGGED && 
				lpObj->Type == OBJ_USER &&
				lpObj->CloseCount > 0)
		{
			if(lpObj->CloseCount == 1)
			{
				if(lpObj->CloseType == 1)
				{
					if(gObjGameClose(lpObj->m_Index) == 1)
					{
						GCCloseMsgSend(lpObj->m_Index,1);
						GJUpdateMatchDBUserCharacters(lpObj);
					}
				}
				else if(lpObj->CloseType == 0)
				{
					GCCloseMsgSend(lpObj->m_Index,0);
					CloseClient(lpObj->m_Index);
				}
				else if(lpObj->CloseType == 2)
				{
					GCCloseMsgSend(lpObj->m_Index,2);
				}
			}
			else
			{
				char Msg[128];
				wsprintf(Msg, "You have %d second(s) left before exiting the game.",lpObj->CloseCount-1);
				GCServerMsgStringSend(Msg,lpObj->m_Index,1);
			}
			lpObj->CloseCount--;
		}
		if(lpObj->Connected == PLAYER_PLAYING &&
			lpObj->Type == OBJ_USER)
		{
			if(GetTickCount() - lpObj->AutoSaveTime > 600000)
			{
				GJSetCharacterInfo(lpObj,n,0);
				lpObj->AutoSaveTime = GetTickCount();
			}

			if(lpObj->CheckSumTime > 0 && GetTickCount() - lpObj->CheckSumTime > 3000)
			{
				if (!gObj[n].bot)
					CloseClient(n);
			}

			gObjPkDownTimeCheck(lpObj,1);
			gObjInterfaceTimeCheck(lpObj);
			gObjTimeCheckSelfDefense(lpObj);
		}

		if(lpObj->Connected == PLAYER_CONNECTED ||
			lpObj->Connected == PLAYER_LOGGED ||
			lpObj->Connected == PLAYER_PLAYING)
		{
			if(lpObj->Type == OBJ_USER)
			{
				if(lpObj->Connected >= PLAYER_LOGGED)
				{
					if(GetTickCount() - lpObj->ConnectCheckTime > 60000)
					{
						if (!gObj[n].bot)
						{
							ResponErrorCloseClient(n);
							LogAdd("Game working response error causes conclusion (%d)(%s)(%s)(%s)",lpObj->m_Index,lpObj->AccountID,lpObj->Name,lpObj->Ip_addr);
						}

					}
				}
				else
				{
					if(GetTickCount() - lpObj->ConnectCheckTime > 30000)
					{
						ResponErrorCloseClient(n);
						LogAdd("Response error after connection causes conclusion (%d)(%s)(%s)(%s)",lpObj->m_Index,lpObj->AccountID,lpObj->Name,lpObj->Ip_addr);
					}
				}
			}
		}
	}


	gGameServerAuth.SendInfo();
}






void gObjManaPotionFill(LPOBJ lpObj)
{
	lpObj->m_ManaFillCount++;

	double tmana;
	int ChangeMana = 0;

	if(lpObj->m_ManaFillCount > 2)
	{
		lpObj->m_ManaFillCount = 0;

		int BP,AddBP;
		BYTE MapAttr;
		int rBP,CurBP;

		if(lpObj->MaxMana + lpObj->AddMana > lpObj->Mana)
		{
			tmana = lpObj->Mana;
			tmana += (lpObj->MaxMana + lpObj->AddMana)*0.037f;

			tmana += lpObj->m_JewelOfHarmonyEffect.HJOpAddRefillMP;

			if(lpObj->MaxMana + lpObj->AddMana < tmana)
			{
				tmana = lpObj->MaxMana + lpObj->AddMana;
			}

			lpObj->Mana = tmana;
			ChangeMana = 1;
		}

		BP = lpObj->MaxBP + lpObj->AddBP;

		if(lpObj->BP < BP)
		{
			MapAttr = MapC[lpObj->MapNumber].GetAttr((short &)lpObj->X,(short &)lpObj->Y);
			rBP = 2;

			if((MapAttr & 1) != 0)
			{
				rBP = 5;
			}

			if(lpObj->Class == CLASS_KNIGHT)
			{
				AddBP = rBP +(BP * 5 / 100);
			}
			else
			{
				AddBP = rBP +(BP * 3 / 100);
			}

			if(lpObj->m_iPotionSoulTime > 0)
			{
				AddBP += 8;
			}

			AddBP += lpObj->SetOpIncAGValue;

			if(AddBP < 1)
			{
				AddBP = 1;
			}

			CurBP = lpObj->BP;
			CurBP += AddBP;

			if(CurBP > BP)
			{
				CurBP = BP;
			}

			lpObj->BP = CurBP;

			ChangeMana = 1;
		}

		if(ChangeMana != 0)
		{
			GCManaSend(lpObj->m_Index,(short)lpObj->Mana,255,0,lpObj->BP);
		}
	}
}



//------------------------------------------------------------


void gObjRestPotionFill(LPOBJ lpObj)
{
	if(lpObj->m_Rest != 0)
	{
		double tlife;
		double tmana;
		int percent = 3;
		lpObj->m_LifeFillCount++;

		if(lpObj->m_LifeFillCount > 4)
		{
			lpObj->m_LifeFillCount = 0;

			tlife = lpObj->Life;

			if(lpObj->pInventory[10].IsItem() == 1)
			{
				if(lpObj->pInventory[10].m_Option3 != 0 && lpObj->pInventory[10].m_Type != ITEMGET(13,24))
				{
					percent += lpObj->pInventory[10].m_Option3;
				}
			}
			else if(lpObj->pInventory[11].IsItem() == 1)
			{
				if(lpObj->pInventory[11].m_Option3 != 0 && lpObj->pInventory[11].m_Type != ITEMGET(13,24))
				{
					percent += lpObj->pInventory[11].m_Option3;
				}
			}
			else if(lpObj->pInventory[9].IsItem() == 1)
			{
				if(lpObj->pInventory[9].m_Option3 != 0 && lpObj->pInventory[9].m_Type != ITEMGET(13,28))
				{
					percent += lpObj->pInventory[9].m_Option3;
				}
			}

			tlife += (lpObj->MaxLife + lpObj->AddLife)*percent / 100.0f;
			tlife += lpObj->m_JewelOfHarmonyEffect.HJOpAddRefillHP;
			
			if((lpObj->MaxLife + lpObj->AddLife) < tlife)
			{
				tlife = lpObj->MaxLife + lpObj->AddLife;
			}

		lpObj->Life = tlife;

		GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,255,0,lpObj->iShield);

		tmana = lpObj->Mana + lpObj->AddMana;
		tmana += (lpObj->MaxMana + lpObj->AddMana) * 3.0f / 100.0f;
		tmana += lpObj->m_JewelOfHarmonyEffect.HJOpAddRefillMP;

		if((lpObj->MaxMana + lpObj->AddMana) < tmana)
		{
			tmana = lpObj->MaxMana + lpObj->AddMana;
		}

		lpObj->Mana = tmana;

		GCManaSend(lpObj->m_Index,(short)lpObj->Mana,255,0,lpObj->BP);
		}
	}
	else
	{
		int percent = 0;
		double tlife;
		if(lpObj->pInventory[10].IsItem() == 1)
		{
			if(lpObj->pInventory[10].m_Option3 != 0 && lpObj->pInventory[10].m_Durability != 0.0f && lpObj->pInventory[10].m_Type != ITEMGET(13,24))
			{
				percent += lpObj->pInventory[10].m_Option3;
			}
		}

		if(lpObj->pInventory[11].IsItem() == 1)
		{
			if(lpObj->pInventory[11].m_Option3 != 0 && lpObj->pInventory[11].m_Durability != 0.0f && lpObj->pInventory[11].m_Type != ITEMGET(13,24))
			{
				percent += lpObj->pInventory[11].m_Option3;
			}
		}

		if(lpObj->pInventory[9].IsItem() == 1)
		{
			if(lpObj->pInventory[9].m_Option3 != 0 && lpObj->pInventory[9].m_Durability != 0.0f && lpObj->pInventory[9].m_Type != ITEMGET(13,28))
			{
				percent += lpObj->pInventory[9].m_Option3;
			}
		}

		if(lpObj->pInventory[7].IsItem() == 1)
		{
			if(lpObj->pInventory[7].m_Option3 != 0 && lpObj->pInventory[7].m_Special[2] == 85 && lpObj->pInventory[7].m_Durability != 0.0f)
			{
				percent += lpObj->pInventory[7].m_Option3;
			}
		}

		if(percent != 0)
		{
			lpObj->m_LifeFillCount++;

			if(lpObj->m_LifeFillCount > 6)
			{
				lpObj->m_LifeFillCount = 0;
				tlife = lpObj->Life;

				tlife += (lpObj->MaxLife +lpObj->AddLife) * percent / 100.f;
				tlife += lpObj->m_JewelOfHarmonyEffect.HJOpAddRefillHP;

				if((lpObj->MaxLife + lpObj->AddLife) < tlife)
				{
					tlife = lpObj->MaxLife + lpObj->AddLife;
				}

				lpObj->Life = tlife;

				GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,255,0,lpObj->iShield);
			}
		}
	}

	if(lpObj->iFillShield > 0)
	{
		int iFillSDPoint = 0;
		if(lpObj->iFillShieldCount <= 0)
		{
			lpObj->iFillShieldCount = 1;
		}

		iFillSDPoint = lpObj->iFillShieldMax / lpObj->iFillShieldCount;

		lpObj->iShield += iFillSDPoint;

		lpObj->iFillShield -= iFillSDPoint;

		if(lpObj->iFillShield < iFillSDPoint)
		{
			iFillSDPoint = lpObj->iFillShield;
			lpObj->iFillShield = 0;

			if(iFillSDPoint < 0)
			{
				iFillSDPoint = 0;
			}
		}

		if(lpObj->iShield > (lpObj->iMaxShield + lpObj->iAddShield))
		{
			lpObj->iShield = lpObj->iMaxShield + lpObj->iAddShield;

			lpObj->iFillShield = 0;
			lpObj->iFillShieldMax = 0;
		}

		GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,255,0,lpObj->iShield);
	}

	if(lpObj->FillLife > 0)
	{
		double cur = lpObj->FillLifeMax * 34.0f / 100.0f;

		if(lpObj->FillLifeCount == 2)
		{
			cur = lpObj->FillLifeMax * 54.0f / 100.0f;
		}

		if(lpObj->FillLifeCount == 4)
		{
			cur = lpObj->FillLifeMax * 25.0f / 100.0f;
		}

		if(lpObj->FillLife < cur)
		{
			cur = lpObj->FillLife;
			lpObj->FillLife = 0;

			if(cur < 0)
			{
				cur = 0;
			}
		}
		else
		{
			lpObj->FillLife -= cur;
		}

		lpObj->Life += cur;

		if((lpObj->MaxLife + lpObj->AddLife) < lpObj->Life)
		{
			lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
			lpObj->FillLife = 0;
		}

		GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,255,0,lpObj->iShield);
	}
}



//------------------------------------------------------------


void gObjUseDrink(LPOBJ lpObj, int level)
{
	switch (level)
	{
	case 0:
		{
			GCItemUseSpecialTimeSend(lpObj->m_Index, 0, gAleTime);
		}
		break;

	case 1:
		{
			GCItemUseSpecialTimeSend(lpObj->m_Index, 0, gOliveOfLoveTime);
		}
		break;

	case 2:
		{
			GCItemUseSpecialTimeSend(lpObj->m_Index, 1, 90);
			lpObj->m_SkillAttack2 = 1;
			lpObj->m_SkillAttackTime2 = 90;
		}
		break;

	case 0x4D:
		{
			GCItemUseSpecialTimeSend(lpObj->m_Index, 2, gSoulPotionTime);
		}
		break;

	default:
		{
			GCItemUseSpecialTimeSend(lpObj->m_Index, 0, gDefaultPotionTime);
		}
		break;
	}
}

//------------------------------------------------------------


void gObjViewportListProtocolDestroy(LPOBJ lpObj)
{
	PBMSG_COUNT pCount;
	const int lsendbuf = sizeof(pViewportDestroy) + sizeof(pCount) + 1;
	int lOfs,count;

	BYTE sendBuf[lsendbuf];
	count = 0;
	lOfs = 4;

	pViewportDestroy.NumberH = SET_NUMBERH(lpObj->m_Index);
	pViewportDestroy.NumberL = SET_NUMBERL(lpObj->m_Index);


	memcpy(&sendBuf[lOfs],&pViewportDestroy,sizeof(pViewportDestroy));

	lOfs += 2;
	count += 1;

	pCount.h.c = 0xC1;
	pCount.h.headcode = 20;
	pCount.h.size = lOfs;
	pCount.count = count;

	memcpy(sendBuf,&pCount,sizeof(pCount));

	if(count < 1)	{
		return;
	}

	MsgSendV2(lpObj,sendBuf,lOfs);
}


//------------------------------------------------------------


void gObjViewportListProtocolCreate(LPOBJ lpObj)
{
	int n,tObjNum;
	int lOfs,count,moncount;
	PWMSG_COUNT pwCount;

	const int lsendbuf = sizeof(pwCount) + sizeof(pViewportCreateChange) + 1;
	BYTE sendbuf[lsendbuf];

	count = 0;
	moncount = 0;
	lOfs = sizeof(pwCount);

	if(lpObj->Type == OBJ_USER)
	{
		if(lpObj->m_Change >= 0)
		{
			pViewportCreateChange.NumberH = SET_NUMBERH(lpObj->m_Index);
			pViewportCreateChange.NumberL = SET_NUMBERL(lpObj->m_Index);

			pViewportCreateChange.NumberH |= 0x80;

			pViewportCreateChange.X = (BYTE)lpObj->X;
			pViewportCreateChange.Y = (BYTE)lpObj->Y;

			pViewportCreateChange.TX = (BYTE)lpObj->TX;
			pViewportCreateChange.TY = (BYTE)lpObj->TY;

			pViewportCreateChange.SkinH = SET_NUMBERH((lpObj->m_Change & 0xFFFF) & 0xFFFF);
			pViewportCreateChange.SkinL = SET_NUMBERL((lpObj->m_Change & 0xFFFF) & 0xFFFF);

			pViewportCreateChange.ViewSkillState = lpObj->m_ViewSkillState;
			pViewportCreateChange.DirAndPkLevel = lpObj->Dir << 4;
			pViewportCreateChange.DirAndPkLevel |= lpObj->m_PK_Level & 0x0F;

			if(CC_MAP_RANGE(lpObj->MapNumber))
			{
				pViewportCreateChange.ViewSkillState = 0;
			}

			memcpy(pViewportCreateChange.Id,lpObj->Name,sizeof(pViewportCreateChange.Id));
			memcpy(pViewportCreateChange.CharSet,lpObj->CharSet,sizeof(pViewportCreateChange.CharSet)); //New for Fix Rings of Transformation
			memcpy(&sendbuf[lOfs],&pViewportCreateChange,sizeof(pViewportCreateChange));

			lOfs += sizeof(pViewportCreateChange);
			count += 1;

			pwCount.h.headcode = 0x45;
		}
		else
		{
			pViewportCreate.NumberH = SET_NUMBERH(lpObj->m_Index);
			pViewportCreate.NumberL = SET_NUMBERL(lpObj->m_Index);

			//lpObj->CharSet[0] &= 0xF0;

			if(lpObj->m_State == 1 && lpObj->Teleport==0)
			{
				pViewportCreate.NumberH |= 0x80;
			}

			pViewportCreate.ViewSkillState = lpObj->m_ViewSkillState;

			//lpObj->CharSet[0] |= lpObj->m_ViewState & 0x0F;

			pViewportCreate.X = (BYTE)lpObj->X;
			pViewportCreate.Y = (BYTE)lpObj->Y;
			pViewportCreate.TX = (BYTE)lpObj->TX;
			pViewportCreate.TY = (BYTE)lpObj->TY;

			pViewportCreate.DirAndPkLevel = lpObj->Dir << 4;
			pViewportCreate.DirAndPkLevel |= lpObj->m_PK_Level & 0x0F;

			if(CC_MAP_RANGE(lpObj->MapNumber))
			{
				pViewportCreate.ViewSkillState = 0;
			}

			memcpy(pViewportCreate.CharSet,lpObj->CharSet,sizeof(pViewportCreate.CharSet));
			memcpy(pViewportCreate.Id,lpObj->Name,sizeof(pViewportCreate.Id));
			memcpy(&sendbuf[lOfs],&pViewportCreate,sizeof(pViewportCreate));

			lOfs += sizeof(pViewportCreate);
			count += 1;

			pwCount.h.headcode = 0x12;
		}

		pwCount.h.c = 0xC2;
		pwCount.h.sizeH = SET_NUMBERH(lOfs);
		pwCount.h.sizeL = SET_NUMBERL(lOfs);
		pwCount.count = count;

		memcpy(sendbuf,&pwCount,sizeof(pwCount));

		DataSend(lpObj->m_Index,sendbuf,lOfs);

		if(lpObj->GuildNumber != 0)
		{
			GuildInfoOfs = 5;

			PMSG_SIMPLE_GUILDVIEWPORT pGuild;

			pGuild.GuildNumber = lpObj->lpGuild->Number;
			pGuild.NumberH = SET_NUMBERH(lpObj->m_Index) & 0x7F;
			pGuild.NumberL = SET_NUMBERL(lpObj->m_Index);

			if(strcmp(lpObj->lpGuild->Names[0],lpObj->Name) == 0)
			{
				pGuild.NumberH |= 0x80;
			}

			pGuild.btGuildType = lpObj->lpGuild->btGuildType;
			pGuild.btGuildStatus = lpObj->GuildStatus;

			memcpy(&GuildInfoBuf[GuildInfoOfs],&pGuild,sizeof(pGuild));

			GuildInfoOfs += sizeof(pGuild);

			PMSG_SIMPLE_GUILDVIEWPORT_COUNT pwCount;

			pwCount.h.c = 0xC2;
			pwCount.h.headcode = 0x65;
			pwCount.h.sizeH = SET_NUMBERH(GuildInfoOfs);
			pwCount.h.sizeL = SET_NUMBERL(GuildInfoOfs);
			pwCount.Count = 1;

			memcpy(GuildInfoBuf,&pwCount,sizeof(pwCount));

			DataSend(lpObj->m_Index,GuildInfoBuf,GuildInfoOfs);
		}

		for(n = 0; n < MAX_VIEWPORT; n++)
		{
			if(lpObj->VpPlayer2[n].state != 0)
			{
				tObjNum = lpObj->VpPlayer2[n].number;

				if(tObjNum >= 0)
				{
					if(lpObj->VpPlayer2[n].type == OBJ_USER)
					{
						DataSend(tObjNum,sendbuf,lOfs);

						if(GuildInfoCount != 0)
						{
							DataSend(tObjNum,GuildInfoBuf,GuildInfoOfs);
						}

						if(GuildUserCount != 0)
						{
							DataSend(tObjNum,GuildUserBuf,GuildUserOfs);
						}
					}
				}
			}
		}
	}
	else
	{
		count = 0;
	
		if(lpObj->m_RecallMon >= 0)
		{
			pCallMonsterViewportCreate.NumberH = SET_NUMBERH(lpObj->m_Index);
			pCallMonsterViewportCreate.NumberL = SET_NUMBERL(lpObj->m_Index);
	
			if(lpObj->m_State == 1)
			{
				pCallMonsterViewportCreate.NumberH |= 0x80;
			}
	
			pCallMonsterViewportCreate.Type_HI = SET_NUMBERH(lpObj->Class);
			pCallMonsterViewportCreate.Type_LO = SET_NUMBERL(lpObj->Class);
			pCallMonsterViewportCreate.ViewState = lpObj->m_ViewSkillState;
	
			pCallMonsterViewportCreate.X = (BYTE)lpObj->X;
			pCallMonsterViewportCreate.Y = (BYTE)lpObj->Y;
	
			pCallMonsterViewportCreate.TX = (BYTE)lpObj->TX;
			pCallMonsterViewportCreate.TY = (BYTE)lpObj->TY;
	
			pCallMonsterViewportCreate.Path = lpObj->Dir << 4;
	
			if(lpObj->m_RecallMon < OBJMAX-1)
			{
				memcpy(pCallMonsterViewportCreate.Id,gObj[lpObj->m_RecallMon].Name,sizeof(pCallMonsterViewportCreate.Id));
			}
			else
			{
				memset(pCallMonsterViewportCreate.Id,0x00,sizeof(pCallMonsterViewportCreate.Id));
			}
	
			memcpy(&sendbuf[lOfs],&pCallMonsterViewportCreate,sizeof(pCallMonsterViewportCreate));
	
			lOfs += sizeof(pCallMonsterViewportCreate);
			count += 1;
		}
		else
		{
			pMonsterViewportCreate.NumberH = SET_NUMBERH(lpObj->m_Index);
			pMonsterViewportCreate.NumberL = SET_NUMBERL(lpObj->m_Index);
	
			if(lpObj->m_State == 1 && lpObj->Teleport == 0)
			{
				pMonsterViewportCreate.NumberH |= 0x80;
				pMonsterViewportCreate.NumberH |= 0x40;
			}
	
			pMonsterViewportCreate.Type_HI = SET_NUMBERH(lpObj->Class);
			pMonsterViewportCreate.Type_LO = SET_NUMBERL(lpObj->Class);
	
			pMonsterViewportCreate.ViewState = lpObj->m_ViewSkillState;
			pMonsterViewportCreate.X = (BYTE)lpObj->X;
			pMonsterViewportCreate.Y = (BYTE)lpObj->Y;
			pMonsterViewportCreate.TX = (BYTE)lpObj->TX;
			pMonsterViewportCreate.TY = (BYTE)lpObj->TY;
	
			pMonsterViewportCreate.Path = lpObj->Dir << 4;
	
			memcpy(&sendbuf[lOfs],&pMonsterViewportCreate,sizeof(pMonsterViewportCreate));
			lOfs += sizeof(pMonsterViewportCreate);
			moncount += 1;
		}
	
		if(count > 0)
		{
			PWMSG_COUNT pwCount;
	
			pwCount.h.c = 0xC2;
			pwCount.h.headcode = 0x1F;
			pwCount.h.sizeH = SET_NUMBERH(lOfs);
			pwCount.h.sizeL = SET_NUMBERL(lOfs);
			pwCount.count = count;
	
			memcpy(sendbuf,&pwCount,sizeof(pwCount));
			MsgSendV2(lpObj,sendbuf,lOfs);
		}
	
		if(moncount > 0)
		{
			PWMSG_COUNT pwCount;
	
			pwCount.h.c = 0xC2;
			pwCount.h.headcode = 0x13;
			pwCount.h.sizeH = SET_NUMBERH(lOfs);
			pwCount.h.sizeL = SET_NUMBERL(lOfs);
			pwCount.count = moncount;
	
			memcpy(sendbuf,&pwCount,sizeof(pwCount));
			MsgSendV2(lpObj,sendbuf,lOfs);
		}
	}
	//delete[] sendbuf;
}


//------------------------------------------------------------


void gObjViewportListProtocol(short aIndex)
{
	if(gObj[aIndex].Connected != PLAYER_PLAYING)
	{
		return;
	}
	//---
	PBMSG_COUNT pCount;
	//---#optimize
	const int lsendbuf = (sizeof(pViewportCreate) + sizeof(pViewportDestroy) + sizeof(pCount) + 1) * MAX_VIEWPORT ;
	const int lMonstersendbuf = (sizeof(pCount) + sizeof(pMonsterViewportCreate) + 1) * MAX_VIEWPORT ;
	const int lcallMonstersendbuf = (sizeof(pCount) + sizeof(pCallMonsterViewportCreate) + 1 ) * MAX_VIEWPORT;
	const int lItembuf = (sizeof(pItemViewportDestroy) + sizeof(pItemCount) + sizeof(pItemViewportCreate) + 1 ) * MAX_VIEWPORT; 
	BYTE sendbuf[lsendbuf];
	//BYTE *sendbuf = new BYTE[sizeof(pCount) + sizeof(pViewportCreate) + sizeof(pViewportDestroy) + 10];
	BYTE Monstersendbuf[lMonstersendbuf];
	//BYTE *Monstersendbuf = new BYTE[sizeof(pCount) + sizeof(pMonsterViewportCreate) + 40 ];
	BYTE callMonstersendbuf[lcallMonstersendbuf];
	//BYTE *callMonstersendbuf = new BYTE[sizeof(pCount) + sizeof(pCallMonsterViewportCreate) + 40 ];
	BYTE Itembuf[lItembuf];
	//BYTE *Itembuf = new BYTE[sizeof(pCount) + sizeof(pItemViewportDestroy) + sizeof(pItemCount) + sizeof(pItemViewportCreate) + 40 ];
	BYTE count,monstercount,callmonstercount;
	//---
	short tObjNum;
	//---
	int n;
	int lOfs_Item,count_Item,ItemStructSize = sizeof(PMSG_ITEMVIEWPORTCREATE),lOfs,MonlOfs,callMonlOfs;
	int pMsgSize;
	//---
	LPOBJ lpTargetObj,lpObj = &gObj[aIndex];
	//---
	GuildInfoOfs = 0;
	GuildInfoCount = 0;
	GuildUserOfs = 0;
	GuildUserCount = 0;
	ChangeCount = 0;
	GuildInfoOfs = 5;
	GuildUserOfs = 5;
	lOfsChange = 5;

	lOfs = 4;
	lOfs_Item = 5;
	count = 0;
	count_Item = 0;

	if(lpObj->Type == OBJ_USER)
	{
		for(n = 0; n < MAX_VIEWPORT;n++)
		{
			if(lpObj->VpPlayer[n].state == 3)
			{
				tObjNum = lpObj->VpPlayer[n].number;

				if(tObjNum >= 0)
				{
					switch(lpObj->VpPlayer[n].type)
					{
					case 1:
					case 2:
					case 3:
						pViewportDestroy.NumberH = SET_NUMBERH(tObjNum);
						pViewportDestroy.NumberL = SET_NUMBERL(tObjNum);

						memcpy(&sendbuf[lOfs],&pViewportDestroy,sizeof(pViewportDestroy));
						lOfs += sizeof(pViewportDestroy);
						count += 1;
						break;
					case 5:
						pItemViewportDestroy.NumberH = SET_NUMBERH(tObjNum);
						pItemViewportDestroy.NumberL = SET_NUMBERL(tObjNum);

						memcpy(&Itembuf[lOfs_Item],&pItemViewportDestroy,sizeof(pItemViewportDestroy));

						lOfs_Item += sizeof(pItemViewportDestroy);
						count_Item += 1;
						break;
					}
				}

				lpObj->VpPlayer[n].state = 0;
				lpObj->VpPlayer[n].number = -1;
				lpObj->VPCount -= 1;
			}
		}

		if(count > 0)
		{
			pCount.h.c = 0xC1;
			pCount.h.headcode = 0x14;
			pCount.h.size = lOfs;
			pCount.count = count;

			memcpy(sendbuf,&pCount,sizeof(pCount));
			DataSend(aIndex,sendbuf,lOfs);
		}

		if(count_Item > 0)
		{
			pItemCount.h.c = 0xC2;
			pItemCount.h.headcode = 0x21;
			pItemCount.h.sizeH = SET_NUMBERH(lOfs_Item);
			pItemCount.h.sizeL = SET_NUMBERL(lOfs_Item);
			pItemCount.count = count_Item;

			memcpy(Itembuf,&pItemCount,sizeof(pItemCount));
			DataSend(aIndex,Itembuf,lOfs_Item);
		}

		//------------------------------------------------------------

		count = 0;
		monstercount = 0;
		count_Item = 0;
		callmonstercount = 0;
		lOfs = 5;
		MonlOfs = lOfs;
		callMonlOfs = MonlOfs;
		lOfs_Item = 5;
		pMsgSize = 44;

		for(n = 0; n < MAX_VIEWPORT;n++)
		{
			if(lpObj->VpPlayer[n].state == 1)
			{
				tObjNum = lpObj->VpPlayer[n].number;

				if(tObjNum >= 0)
				{
					switch(lpObj->VpPlayer[n].type)
					{
					case 1:
						lpTargetObj = &gObj[tObjNum];

						if(lpTargetObj->m_Change >= 0)
						{
							pViewportCreateChange.NumberH = SET_NUMBERH(tObjNum);
							pViewportCreateChange.NumberL = SET_NUMBERL(tObjNum);

							//lpTargetObj->CharSet[0] &= 0xF0;

							if(lpTargetObj->m_State == 1 && lpTargetObj->Teleport == 0)
							{
								pViewportCreateChange.NumberH |= 0x80;
							}

							pViewportCreateChange.X = (BYTE)lpTargetObj->X;
							pViewportCreateChange.Y = (BYTE)lpTargetObj->Y;
							pViewportCreateChange.TX = (BYTE)lpTargetObj->TX;
							pViewportCreateChange.TY = (BYTE)lpTargetObj->TY;
							pViewportCreateChange.SkinH = SET_NUMBERH((lpTargetObj->m_Change & 0xFFFF) & 0xFFFF);
							pViewportCreateChange.SkinL = SET_NUMBERL((lpTargetObj->m_Change & 0xFFFF) & 0xFFFF);									
							pViewportCreateChange.ViewSkillState = lpTargetObj->m_ViewSkillState;
							pViewportCreateChange.DirAndPkLevel = lpTargetObj->Dir << 4;
							pViewportCreateChange.DirAndPkLevel |= lpTargetObj->m_PK_Level & 0x0F;

							if(CC_MAP_RANGE(lpTargetObj->MapNumber))
							{
								pViewportCreateChange.ViewSkillState = 0;
							}


							if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
							{
								BYTE btJoinSide = lpTargetObj->m_btCsJoinSide;

								if ( btJoinSide < 0 )
									btJoinSide = 0;

								if ( btJoinSide > 2 )
									btJoinSide = 2;

								switch ( btJoinSide )
								{
								case 1:	
									pViewportCreate.ViewSkillState |= 0x40000;
									lpTargetObj->m_ViewSkillState |= 0x40000;
									break;
								case 2:
									{
										switch (lpTargetObj->m_btCsJoinSide)
										{
										case 2:
											{
												pViewportCreate.ViewSkillState |= 0x80000;
												lpTargetObj->m_ViewSkillState |= 0x80000;
											}
											break;

										case 3:
											{
												pViewportCreate.ViewSkillState |= 0x400000;
												lpTargetObj->m_ViewSkillState |= 0x400000;
											}
											break;

										case 4:
											{
												pViewportCreate.ViewSkillState |= 0x800000;
												lpTargetObj->m_ViewSkillState |= 0x800000;
											}
											break;
										}
									}
									break;
								default:
									pViewportCreate.ViewSkillState &= ~0xC0000;
									lpTargetObj->m_ViewSkillState &= ~0xC0000;
									pViewportCreate.ViewSkillState &= ~0xC00000;
									lpTargetObj->m_ViewSkillState &= ~0xC00000;
								}
							}


							memcpy(pViewportCreateChange.Id,lpTargetObj->Name,sizeof(pViewportCreateChange.Id));
							memcpy(&SendGBufChange[lOfsChange],&pViewportCreateChange,sizeof(pViewportCreateChange));
							lOfsChange += sizeof(pViewportCreateChange);
							ChangeCount +=1;
						}
						else
						{
							pViewportCreate.NumberH = SET_NUMBERH(tObjNum);
							pViewportCreate.NumberL = SET_NUMBERL(tObjNum);

							//lpTargetObj->CharSet[0] &= 0xF0;

							if(lpTargetObj->m_State == 1 && lpTargetObj->Teleport == 0)
							{
								pViewportCreate.NumberH |= 0x80;
							}

							pViewportCreate.ViewSkillState = lpTargetObj->m_ViewSkillState;
							//lpTargetObj->CharSet[0] |= lpTargetObj->m_ViewState & 0x0F;

							pViewportCreate.X = (BYTE)lpTargetObj->X;
							pViewportCreate.Y = (BYTE)lpTargetObj->Y;
							pViewportCreate.TX = (BYTE)lpTargetObj->TX;
							pViewportCreate.TY = (BYTE)lpTargetObj->TY;

							pViewportCreate.DirAndPkLevel = lpTargetObj->Dir << 4;
							pViewportCreate.DirAndPkLevel |= lpTargetObj->m_PK_Level & 0x0F;

							if(CC_MAP_RANGE(lpTargetObj->MapNumber))
							{
								pViewportCreate.ViewSkillState = 0;
							}


							if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
							{
								BYTE btJoinSide = lpTargetObj->m_btCsJoinSide;
								if ( btJoinSide < 0 )
									btJoinSide = 0;

								if ( btJoinSide > 2 )
									btJoinSide = 2;

								switch ( btJoinSide )
								{
								case 1:	
									pViewportCreate.ViewSkillState |= 0x40000;
									lpTargetObj->m_ViewSkillState |= 0x40000;
									break;
								case 2:
									{
										switch (lpTargetObj->m_btCsJoinSide)
										{
										case 2:
											{
												pViewportCreate.ViewSkillState |= 0x80000;
												lpTargetObj->m_ViewSkillState |= 0x80000;
											}
											break;

										case 3:
											{
												pViewportCreate.ViewSkillState |= 0x400000;
												lpTargetObj->m_ViewSkillState |= 0x400000;
											}
											break;

										case 4:
											{
												pViewportCreate.ViewSkillState |= 0x800000;
												lpTargetObj->m_ViewSkillState |= 0x800000;
											}
											break;
										}
									}
									break;
								default:
									pViewportCreate.ViewSkillState &= ~0xC0000;
									lpTargetObj->m_ViewSkillState &= ~0xC0000;
									pViewportCreate.ViewSkillState &= ~0xC00000;
									lpTargetObj->m_ViewSkillState &= ~0xC00000;
								}
							}


							memcpy(pViewportCreate.CharSet,lpTargetObj->CharSet,sizeof(pViewportCreate.CharSet));
							memcpy(pViewportCreate.Id,lpTargetObj->Name,sizeof(pViewportCreate.Id));
							memcpy(&sendbuf[lOfs],&pViewportCreate,sizeof(pViewportCreate));

							lOfs += sizeof(pViewportCreate);
							count += 1;
						}

						if(lpTargetObj->lpGuild != 0)
						{
							PMSG_SIMPLE_GUILDVIEWPORT pGuild;

							pGuild.GuildNumber = lpTargetObj->lpGuild->Number;
							pGuild.NumberH = SET_NUMBERH(lpTargetObj->m_Index) & 0x7F;
							pGuild.NumberL = SET_NUMBERL(lpTargetObj->m_Index);

							pGuild.btGuildStatus = lpTargetObj->GuildStatus;
							pGuild.btGuildType = lpTargetObj->lpGuild->btGuildType;

							if(lpObj->lpGuild != 0)
							{
								pGuild.btGuildRelationShip = gObjGetRelationShip(lpObj,lpTargetObj);
							}
							else
							{
								pGuild.btGuildRelationShip = 0;
							}

							if(strcmp(lpTargetObj->lpGuild->Names[0],lpTargetObj->Name)==0)
							{
								pGuild.NumberH |= 0x80;
							}

							memcpy(&GuildInfoBuf[GuildInfoOfs],&pGuild,sizeof(pGuild));
							GuildInfoOfs += sizeof(pGuild);
							GuildInfoCount += 1;
						}
						else//#error ������ ���� if (false)
						{

							PMSG_GUILDVIEWPORT_USER pGuildUserViewport;

							if(ViewGuildMng.Add(lpTargetObj->GuildNumber,lpTargetObj->m_Index) == 1 && lpTargetObj->lpGuild != 0)
							{
								PMSG_GUILDVIEWPORT pGuildViewport;

								pGuildViewport.NumberH = SET_NUMBERH(lpTargetObj->lpGuild->Number);
								pGuildViewport.NumberL = SET_NUMBERL(lpTargetObj->lpGuild->Number);

								memcpy(pGuildViewport.GuildName, lpTargetObj->lpGuild->Name, sizeof(pGuildViewport.GuildName) );
								memcpy(pGuildViewport.Mark,lpTargetObj->lpGuild->Mark,sizeof(pGuildViewport.Mark));
								memcpy(&GuildInfoBuf[GuildInfoOfs],&pGuildViewport,sizeof(pGuildViewport));

								GuildInfoOfs += sizeof(pGuildViewport);
								GuildInfoCount += 1;
							}

							pGuildUserViewport.NumberH = SET_NUMBERH(lpTargetObj->m_Index) & 0x7F;
							pGuildUserViewport.NumberL = SET_NUMBERL(lpTargetObj->m_Index);

							if(lpTargetObj->lpGuild != 0 && strcmp(lpTargetObj->lpGuild->Names[0],lpTargetObj->Name) == 0)
							{
								pGuildUserViewport.NumberH |= 0x80;
							}

							if(lpTargetObj->lpGuild != 0)
							{
								pGuildUserViewport.GNumberH = SET_NUMBERH(lpTargetObj->lpGuild->Number);
								pGuildUserViewport.GNumberL = SET_NUMBERL(lpTargetObj->lpGuild->Number);

								memcpy(&GuildUserBuf[GuildUserOfs],&pGuildUserViewport,sizeof(pGuildUserViewport));

								GuildUserOfs += sizeof(pGuildUserViewport);
								GuildUserCount += 1;
							}
						}

						break;
					case 2:
					case 3:
						lpTargetObj = &gObj[tObjNum];

						if(lpTargetObj->m_RecallMon >= 0)
						{
							pCallMonsterViewportCreate.NumberH = SET_NUMBERH(tObjNum);
							pCallMonsterViewportCreate.NumberL = SET_NUMBERL(tObjNum);

							if(lpTargetObj->m_State == 1)
							{
								pCallMonsterViewportCreate.NumberH |= 0x80;
							}

							pCallMonsterViewportCreate.Type_HI = SET_NUMBERH(lpTargetObj->Class);
							pCallMonsterViewportCreate.Type_LO = SET_NUMBERL(lpTargetObj->Class);

							pCallMonsterViewportCreate.ViewState = lpTargetObj->m_ViewSkillState;
							pCallMonsterViewportCreate.X = (BYTE)lpTargetObj->X;
							pCallMonsterViewportCreate.Y = (BYTE)lpTargetObj->Y;
							pCallMonsterViewportCreate.TX = (BYTE)lpTargetObj->TX;
							pCallMonsterViewportCreate.TY = (BYTE)lpTargetObj->TY;
							pCallMonsterViewportCreate.Path = lpTargetObj->Dir << 4;

							if(lpTargetObj->m_RecallMon < OBJMAX-1)
							{
								memcpy(pCallMonsterViewportCreate.Id,gObj[lpTargetObj->m_RecallMon].Name,sizeof(pCallMonsterViewportCreate.Id));
							}
							else
							{
								memset(pCallMonsterViewportCreate.Id,0x00,sizeof(pCallMonsterViewportCreate.Id));
							}

							memcpy(&callMonstersendbuf[callMonlOfs],&pCallMonsterViewportCreate,sizeof(pCallMonsterViewportCreate));
							callMonlOfs += sizeof(pCallMonsterViewportCreate);
							callmonstercount += 1;
						}
						else
						{
							pMonsterViewportCreate.NumberH = SET_NUMBERH(tObjNum);
							pMonsterViewportCreate.NumberL = SET_NUMBERL(tObjNum);

							if(lpTargetObj->m_State == 1)
							{
								pMonsterViewportCreate.NumberH |= 0x80;

								if(lpTargetObj->Teleport != 0)
								{
									pMonsterViewportCreate.NumberH |= 0x40;
								}
							}

							pMonsterViewportCreate.Type_HI = SET_NUMBERH(lpTargetObj->Class);
							pMonsterViewportCreate.Type_LO = SET_NUMBERL(lpTargetObj->Class);

							pMonsterViewportCreate.ViewState = lpTargetObj->m_ViewSkillState;
							pMonsterViewportCreate.X = (BYTE)lpTargetObj->X;
							pMonsterViewportCreate.Y = (BYTE)lpTargetObj->Y;
							pMonsterViewportCreate.TX = (BYTE)lpTargetObj->TX;
							pMonsterViewportCreate.TY = (BYTE)lpTargetObj->TY;
							pMonsterViewportCreate.Path = lpTargetObj->Dir << 4;

							switch ( lpTargetObj->Class )
							{
							case 278:
								{
									if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
									{
										if ( lpObj->m_btCsJoinSide == lpTargetObj->m_btCsJoinSide )
											pMonsterViewportCreate.Type_HI |= 0x80;
									}

									if ( lpObj->lpGuild && lpTargetObj->lpGuild )
									{
										if ( lpObj->lpGuild == lpTargetObj->lpGuild )
										{
											pMonsterViewportCreate.Type_HI |= 0x80;
										}
									}

									pMonsterViewportCreate.Type_HI |= ((lpTargetObj->m_btCreationState << 4) & 0x70);
								}
								break;

							case 277:
								{
									if ( lpTargetObj->m_btCsGateOpen == 0 ) 
										pMonsterViewportCreate.ViewState &= ~0x20000;
									else
										pMonsterViewportCreate.ViewState |= 0x20000;
								}
								break;

							case 216:
								{
									if ( g_CastleSiege.GetRegCrownAvailable() == FALSE )
										pMonsterViewportCreate.ViewState &= ~0x20000;
									else
										pMonsterViewportCreate.ViewState |= 0x20000;
								}
								break;
							}


							memcpy(&Monstersendbuf[MonlOfs],&pMonsterViewportCreate,sizeof(pMonsterViewportCreate));
							MonlOfs += sizeof(pMonsterViewportCreate);
							monstercount += 1;
						}
						break;
					case 5:
						pItemViewportCreate.NumberH = SET_NUMBERH(tObjNum);
						pItemViewportCreate.NumberL = SET_NUMBERL(tObjNum);

						if(MapC[lpObj->MapNumber].m_cItem[tObjNum].m_State == 1)
						{
							pItemViewportCreate.NumberH |= 0x80;
						}

						pItemViewportCreate.px = MapC[lpObj->MapNumber].m_cItem[tObjNum].px;
						pItemViewportCreate.py = MapC[lpObj->MapNumber].m_cItem[tObjNum].py;

						if(MapC[lpObj->MapNumber].m_cItem[tObjNum].m_Type == ITEMGET(14,15))//zen
						{
							WORD MoneyHW = SET_NUMBERHW(MapC[lpObj->MapNumber].m_cItem[tObjNum].m_BuyMoney);
							WORD MoneyLW = SET_NUMBERLW(MapC[lpObj->MapNumber].m_cItem[tObjNum].m_BuyMoney);

							pItemViewportCreate.ItemInfo[0] = BYTE(MapC[lpObj->MapNumber].m_cItem[tObjNum].m_Type)%255;
							pItemViewportCreate.ItemInfo[1] = SET_NUMBERL(MoneyHW);
							pItemViewportCreate.ItemInfo[2] = SET_NUMBERH(MoneyLW);
							pItemViewportCreate.ItemInfo[4] = SET_NUMBERL(MoneyLW);
							pItemViewportCreate.ItemInfo[3] = 0;
							pItemViewportCreate.ItemInfo[5] = (MapC[lpObj->MapNumber].m_cItem[tObjNum].m_Type & 0x1E00) >> 5;
							pItemViewportCreate.ItemInfo[6] = 0;

							memcpy(&Itembuf[lOfs_Item],&pItemViewportCreate,sizeof(pItemViewportCreate));
							lOfs_Item += ItemStructSize;
						}
						else
						{
							ItemByteConvert(pItemViewportCreate.ItemInfo, (MapC[lpObj->MapNumber].m_cItem[tObjNum]));
							memcpy(&Itembuf[lOfs_Item],&pItemViewportCreate,sizeof(pItemViewportCreate));
							lOfs_Item += ItemStructSize;
						}

						count_Item ++;

						break;
					}
				}
				lpObj->VpPlayer[n].state = 2;
			}
		}
		//---
		if(count > 0)
		{
			PWMSG_COUNT pCount;

			pCount.h.c = 0xC2;
			pCount.h.headcode = 0x12;
			pCount.h.sizeH = SET_NUMBERH(lOfs);
			pCount.h.sizeL = SET_NUMBERL(lOfs);
			pCount.count = count;

			memcpy(sendbuf,&pCount,sizeof(pCount));
			DataSend(aIndex,(unsigned char *)&sendbuf,lOfs);
		}

		if(ChangeCount > 0)
		{
			PWMSG_COUNT pCount;

			pCount.h.c = 0xC2;
			pCount.h.headcode = 0x45;
			pCount.h.sizeH = SET_NUMBERH(lOfsChange);
			pCount.h.sizeL = SET_NUMBERL(lOfsChange);
			pCount.count = ChangeCount;

			memcpy(SendGBufChange,&pCount,sizeof(pCount));
			DataSend(aIndex,(unsigned char *)&SendGBufChange,lOfsChange);
		}

		if(monstercount > 0)
		{
			PWMSG_COUNT pCount;

			pCount.h.c = 0xC2;
			pCount.h.headcode = 0x13;
			pCount.h.sizeH = SET_NUMBERH(MonlOfs);
			pCount.h.sizeL = SET_NUMBERL(MonlOfs);
			pCount.count = monstercount;

			memcpy(Monstersendbuf,&pCount,sizeof(pCount));
			DataSend(aIndex,(unsigned char *)&Monstersendbuf,MonlOfs);
		}	

		if(callmonstercount > 0)
		{
			PWMSG_COUNT pCount;

			pCount.h.c = 0xC2;
			pCount.h.headcode = 0x1F;
			pCount.h.sizeH = SET_NUMBERH(callMonlOfs);
			pCount.h.sizeL = SET_NUMBERL(callMonlOfs);
			pCount.count = callmonstercount;

			memcpy(callMonstersendbuf,&pCount,sizeof(pCount));
			DataSend(aIndex,(unsigned char *)&callMonstersendbuf,callMonlOfs);
		}

		if(count_Item > 0)
		{
			PWMSG_COUNT pCount;

			pCount.h.c = 0xC2;
			pCount.h.headcode = 0x20;
			pCount.count = count_Item;
			pCount.h.sizeH = SET_NUMBERH(lOfs_Item);
			pCount.h.sizeL = SET_NUMBERL(lOfs_Item);

			memcpy(Itembuf,&pCount,sizeof(pCount));
			DataSend(aIndex,(unsigned char *)&Itembuf,lOfs_Item);
		}

		if(GuildInfoCount != 0)
		{
			PWMSG_COUNT pCount;

			pCount.h.headcode = 0x65;
			pCount.h.c = 0xC2;
			pCount.h.sizeH = SET_NUMBERH(GuildInfoOfs);
			pCount.h.sizeL = SET_NUMBERL(GuildInfoOfs);
			pCount.count = GuildInfoCount;

			memcpy(GuildInfoBuf,&pCount,sizeof(pCount));
			DataSend(aIndex,(unsigned char *)&GuildInfoBuf,GuildInfoOfs);
		}
		//---
	}
	else if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
	{
		for(n = 0; n < MAX_VIEWPORT_MONSTER;n++)
		{
			if(lpObj->VpPlayer[n].state == 1)
			{
				lpObj->VpPlayer[n].state = 2;
			}

			if(lpObj->VpPlayer[n].state == 3)
			{
				lpObj->VpPlayer[n].state = 0;
				lpObj->VpPlayer[n].number = -1;
				lpObj->VPCount -= 1;
			}
		}
	}

// 	delete[] sendbuf;
// 
// 	delete[] Monstersendbuf;
// 
// 	delete[] callMonstersendbuf;
// 
// 	delete[] Itembuf;
}




//------------------------------------------------------------


void gObjSkillUseProc(LPOBJ lpObj)//#info skill time function
{
	if (lpObj == NULL)
		return;
	//---
	if(lpObj->m_SkillAttackTime > 0)
	{
		lpObj->m_SkillAttackTime--;

		if(lpObj->m_SkillAttackTime == 0)
		{
			lpObj->m_SkillAttack = 0;
			lpObj->m_ViewSkillState &= ~4;

			GCMagicCancelSend(lpObj,28);
		}
	}
	//---
	if(lpObj->m_SkillAttackTime2 > 0)
	{
		lpObj->m_SkillAttackTime2--;

		if(lpObj->m_SkillAttackTime2 == 0)
		{
			lpObj->m_SkillAttack2 = 0;
			lpObj->m_SkillAttackTime2 = 0;
		}
	}
	//---
	if(lpObj->m_SkillDefenseTime > 0)
	{
		lpObj->m_SkillDefenseTime--;

		if(lpObj->m_SkillDefenseTime == 0)
		{
			lpObj->m_SkillDefense = 0;
			lpObj->m_ViewSkillState &= ~8;

			GCMagicCancelSend(lpObj,27);
		}
	}
	//---
	if(lpObj->m_WizardSkillDefenseTime > 0)
	{
		lpObj->m_WizardSkillDefenseTime--;

		if(lpObj->m_WizardSkillDefenseTime == 0)
		{
			lpObj->m_WizardSkillDefense = 0;
			lpObj->m_ViewSkillState &= ~256;

			GCMagicCancelSend(lpObj,16);
		}
	}
	//---
	if(lpObj->m_SkillAddLifeTime > 0)
	{
		lpObj->m_SkillAddLifeTime--;

		if(lpObj->m_SkillAddLifeTime == 0)
		{
			lpObj->AddLife -= lpObj->m_SkillAddLife;

			if(lpObj->AddLife < 0)
			{
				lpObj->AddLife = 0;
			}

			GCReFillSend(lpObj->m_Index,(WORD)lpObj->MaxLife+lpObj->AddLife,0xFE,0,lpObj->iMaxShield+lpObj->iAddShield);

			if(lpObj->Life > lpObj->MaxLife + lpObj->AddLife)
			{
				lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
				GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,0xFF,0,lpObj->iShield);
			}

			lpObj->m_SkillAddLife = 0;
			lpObj->m_ViewSkillState &= ~16;

			GCMagicCancelSend(lpObj,48);
		}
	}
	//---
	if(lpObj->m_SkillHardenTime > 0)
	{
		lpObj->m_SkillHardenTime--;

		if(lpObj->m_SkillHardenTime <= 0)
		{
			lpObj->m_SkillHarden = 0;
			lpObj->m_ViewSkillState &= ~32;

			GCMagicCancelSend(lpObj,51);
		}
	}
	//---
	if(lpObj->m_SkillMagumReduceDefenseTime > 0)
	{
		lpObj->m_SkillMagumReduceDefenseTime--;

		if(lpObj->m_SkillMagumReduceDefenseTime == 0)
		{
			lpObj->m_SkillMagumReduceDefense = 0;
			lpObj->m_ViewSkillState &= ~64;

			GCMagicCancelSend(lpObj,55);
		}
	}
	//---
	if(lpObj->Class == 77)
	{
		lpObj->m_SkyBossMonSheildTime++;

		if(lpObj->m_SkyBossMonSheildTime > 5)
		{
			lpObj->m_SkyBossMonSheildTime = 0;

			if(lpObj->m_SkyBossMonSheild != 0)
			{
				lpObj->m_SkyBossMonSheild = 0;
				lpObj->m_ViewSkillState &= ~128;

				GCMagicCancelSend(lpObj,16);
			}
			else
			{
				lpObj->m_SkyBossMonSheild = 1;
				lpObj->m_ViewSkillState |= 128;

				GCMagicAttackNumberSend(lpObj,16,lpObj->m_Index,1);
			}
		}
	}
	//---
	if(lpObj->m_iSkillNPCHelpTime > 0)
	{
		if( (int)GetTickCount() > lpObj->m_iSkillNPCHelpTime + 60000 * gNewbieBaffTime)
		{
			lpObj->m_iSkillNPCHelpTime = 0;
			lpObj->m_iSkillNPCDefense = 0;
			lpObj->m_iSkillNPCAttack = 0;

			lpObj->m_ViewSkillState &= ~0x2000000;

			GCStateInfoSend(lpObj,0,0x2000000);
		}
	}
	//---
	if(lpObj->SkillRecallParty_Time != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->SkillRecallParty_Time--;

		if(lpObj->SkillRecallParty_Time == 0)
		{
			int m_check1 = gMoveCommand.CheckMainToMove(lpObj);
			int m_check2 = gMoveCommand.CheckEquipmentToMove(lpObj,lpObj->SkillRecallParty_MapNumber);
			int m_check3 = gMoveCommand.CheckInterfaceToMove(lpObj);

			if(m_check1 == false
				|| m_check2 == false
				|| m_check3 == false)
			{
				GCServerMsgStringSend("Summoning canceled.",lpObj->m_Index,1);
			}
			else
			{
				gObjRecall(lpObj->m_Index,(int&)lpObj->SkillRecallParty_MapNumber,(int&)lpObj->SkillRecallParty_X,(int&)lpObj->SkillRecallParty_Y);
			}
		}
		else if(lpObj->SkillRecallParty_Time <= 5)
		{
			char szMsg[128];
			wsprintf(szMsg,"Will be summoned in %d seconds.",lpObj->SkillRecallParty_Time);

			GCServerMsgStringSend(szMsg,lpObj->m_Index,1);
		}
	}
	//---
	if(lpObj->SkillAddCriticalDamageTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->SkillAddCriticalDamageTime--;

		if(lpObj->SkillAddCriticalDamageTime == 0)
		{
			lpObj->SkillAddCriticalDamage = 0;

			MsgOutput(lpObj->m_Index,"The Critical Damage spell has diminished.");

			lpObj->m_ViewSkillState &= ~0x800;
			GCMagicCancelSend(lpObj,64);
		}
	}
	//---
	TMonsterSkillElementInfo::CheckSkillElementInfoProc(lpObj);
	//---
	if(lpObj->m_iSkillStunTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_iSkillStunTime--;

		if(lpObj->m_iSkillStunTime == 0)
		{
			MsgOutput(lpObj->m_Index,"The effects of the Stern have diminished.");
			lpObj->m_ViewSkillState &= ~0x1000;

			GCStateInfoSend(lpObj,0,0x1000);
		}
	}
	//---
	if(lpObj->m_iSkillBrandOfSkillTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_iSkillBrandOfSkillTime--;

		if(lpObj->m_iSkillBrandOfSkillTime == 0)
		{
			lpObj->m_ViewSkillState &= ~0x200;
			GCStateInfoSend(lpObj,0,0x200);
		}
	}
	//---
	if(lpObj->m_iSkillInvisibleTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_iSkillInvisibleTime--;

		if(lpObj->m_iSkillInvisibleTime == 0)
		{
			lpObj->m_ViewSkillState &= ~0x4000;
			GCStateInfoSend(lpObj,0,0x4000);
		}
	}
	//---
	if(lpObj->m_iSkillManaSwellTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_iSkillManaSwellTime--;

		if(lpObj->m_iSkillManaSwellTime == 0)
		{
			lpObj->AddMana -= lpObj->m_iSkillManaSwell;

			if(lpObj->AddMana < 0)
			{
				lpObj->AddMana = 0;
			}

			GCManaSend(lpObj->m_Index,(short)lpObj->MaxMana+lpObj->AddMana,0xFE,0,lpObj->MaxBP+lpObj->AddBP);

			if(lpObj->Mana > lpObj->MaxMana + lpObj->AddMana)
			{
				lpObj->Mana = lpObj->MaxMana + lpObj->AddMana;
				GCManaSend(lpObj->m_Index,(short)lpObj->Mana,0xFF,0,lpObj->BP);
			}

			lpObj->m_iSkillManaSwell = 0;

			lpObj->m_ViewSkillState &= ~0x2000;
			GCStateInfoSend(lpObj,0,0x2000);
		}
	}
	//---
	if(lpObj->m_iPotionBlessTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_iPotionBlessTime--;

		if(lpObj->m_iPotionBlessTime == 0)
		{
			MsgOutput(lpObj->m_Index,"The effects of the Potion of Bless have diminished.");

			lpObj->m_ViewSkillState &= ~0x8000;
			GCStateInfoSend(lpObj,0,0x8000);
		}
	}
	//---
	if(lpObj->m_iPotionSoulTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_iPotionSoulTime--;

		if(lpObj->m_iPotionSoulTime == 0)
		{
			MsgOutput(lpObj->m_Index,"The effects of the Potion of Soul have diminished.");

			lpObj->m_ViewSkillState &= ~0x10000;
			GCStateInfoSend(lpObj,0,0x10000);
		}
	}
	//---
	if(lpObj->Type == OBJ_USER && lpObj->m_iItemEffectValidTime > 0)
	{
		lpObj->m_iItemEffectValidTime--;

		if(lpObj->m_iItemEffectValidTime == 0)
		{
			g_ItemAddOption.ClearItemEffect(lpObj,1);

			GCReFillSend(lpObj->m_Index,(WORD)lpObj->MaxLife+lpObj->AddLife,0xFE,0,lpObj->iMaxShield+lpObj->iAddShield);
			GCManaSend(lpObj->m_Index,(short)lpObj->MaxMana+lpObj->AddMana,0xFE,0,lpObj->MaxBP);
		}
	}
	//---
	if(lpObj->m_iMuseElfInfinityArrowSkillTime != 0 && lpObj->Type == OBJ_USER)
	{
		lpObj->m_iMuseElfInfinityArrowSkillTime--;

		if(lpObj->m_iMuseElfInfinityArrowSkillTime == 0)
		{
			lpObj->m_ViewSkillState &= ~0x4000000;
			GCStateInfoSend(lpObj,0,0x4000000);
		}
	}
	//---
	if(lpObj->m_SkillNumber == 18)
	{
		if(GetTickCount() > lpObj->m_SkillTime)
		{
			lpObj->m_SkillNumber = 0;
		}
	}
	//---
}



//------------------------------------------------------------


void gObjSkillBeAttackProc(LPOBJ lpObj)
{
	int ad,iShieldDamage = 0;

	if(lpObj->m_PoisonBeattackCount > 0)
	{
		lpObj->m_PoisonBeattackCount--;

		if(lpObj->m_PoisonBeattackCount % 3 == 0)
		{
			if(lpObj->Life > 0.0)
			{
				ad = int(lpObj->Life * 3 / 100);
			}
			else
			{
				ad = 1;
			}

			if(g_ShieldSystemOn == 1)
			{
				if(lpObj->Type == OBJ_USER && lpObj->lpAttackObj->Type == OBJ_USER)
				{
					if(lpObj->iShield > ad)
					{
						lpObj->iShield -= ad;
						iShieldDamage = ad;
						ad = 0;
					}
					else
					{
						ad -= lpObj->iShield;
						iShieldDamage = lpObj->iShield;
						lpObj->iShield = 0;

						lpObj->Life -= ad;

						if(lpObj->Life < 0)
						{
							lpObj->Life = 0;
						}
					}
				}
				else
				{
					lpObj->Life -= ad;

					if(lpObj->Life < 0)
					{
						lpObj->Life = 0;
					}
				}
			}
			else
			{
				lpObj->Life -= ad;

				if(lpObj->Life < 0)
				{
					lpObj->Life = 0;
				}
			}

			if(lpObj->lpAttackObj != 0)
			{
				gObjLifeCheck(lpObj,lpObj->lpAttackObj,ad,2,0,0,1,iShieldDamage);
			}

			if(lpObj->m_PoisonBeattackCount <= 0)
			{
				lpObj->lpAttackObj = 0;
				lpObj->m_ViewSkillState &= ~1;
				lpObj->m_ViewState = 0;

				if(lpObj->m_PoisonType == 38)
				{
					GCStateInfoSend(lpObj,0,1);
				}
				else
				{
					GCMagicCancelSend(lpObj,1);
				}

				lpObj->m_PoisonType = 0;
			}
		}
	}
	else if(lpObj->m_ColdBeattackCount > 0)
	{
		lpObj->m_ColdBeattackCount--;

		if(lpObj->m_ColdBeattackCount <= 0)
		{
			lpObj->lpAttackObj = 0;
			lpObj->DelayActionTime = 0;
			lpObj->DelayLevel = 0;

			lpObj->m_ViewSkillState &= ~2;
			lpObj->m_ViewState = 0;

			if(lpObj->m_IceType == 39)
			{
				GCStateInfoSend(lpObj,0,2);
			}
			else
			{
				GCMagicCancelSend(lpObj,7);
			}

			lpObj->m_IceType = 0;
		}
	}
	else if(lpObj->m_ImmuneToMagicCount > 0)
	{
		lpObj->m_ImmuneToMagicCount--;

		if(lpObj->m_ImmuneToMagicCount <= 0)
		{
			lpObj->m_ViewSkillState &= ~0x80;
			GCStateInfoSend(lpObj,1,0x80);
		}
	}
	else if(lpObj->m_ImmuneToHarmCount > 0)
	{
		lpObj->m_ImmuneToHarmCount--;

		if(lpObj->m_ImmuneToHarmCount <= 0)
		{
			lpObj->m_ViewSkillState &= ~8;
			GCStateInfoSend(lpObj,0,8);
		}
	}
}

//------------------------------------------------------------


void gObjTeleportMagicUse(int aIndex, BYTE x, BYTE y)	// Check if x and y are BYTE
{
	if ( !OBJMAX_RANGE(aIndex) )
		return;

	LPOBJ lpObj = &gObj[aIndex];

	if(lpObj->Teleport != 0 || lpObj->Connected != PLAYER_PLAYING)
	{
		return;
	}

	int RangeX = lpObj->X - x;//#info check this antihack
	RangeX = abs(RangeX);

	int RangeY = lpObj->Y - y;
	RangeY = abs(RangeY);

	if (RangeX > 10 || RangeY > 10)
	{
		CloseClient(aIndex);
		return;
	}

	lpObj->TeleportTime = GetTickCount();
	lpObj->PathCount = 0;
	lpObj->Teleport = 1;
	lpObj->m_StateSub = 1;
	lpObj->m_ViewState = 1;

	lpObj->X = x;
	lpObj->Y = y;
	lpObj->TX = x;
	lpObj->TY = y;

	MapC[lpObj->MapNumber].ClearStandAttr(lpObj->m_OldX,lpObj->m_OldY);
	MapC[lpObj->MapNumber].SetStandAttr(lpObj->TX,lpObj->TY);

	lpObj->m_OldX = lpObj->TX;
	lpObj->m_OldY = lpObj->TY;

	gObjViewportListProtocolDestroy(lpObj);
}


//------------------------------------------------------------


void gObjCantMove(short& x, short& y,BYTE& mapNumber, BYTE& dir, int& movefail,int& gt, LPOBJ& lpObj)
{
	x = lpObj->X;
	y = lpObj->Y;
	mapNumber = lpObj->MapNumber;
	dir = lpObj->Dir;
	movefail = 1;

	lpObj->RegenMapNumber = lpObj->MapNumber;
	lpObj->RegenMapX = (BYTE)x;
	lpObj->RegenMapY = (BYTE)y;

	gObjClearViewport(lpObj);

	GCTeleportSend(lpObj,gt,mapNumber,(BYTE)lpObj->X,(BYTE)lpObj->Y,lpObj->Dir);

	if(lpObj->m_Change >= 0)
	{
		gObjViewportListProtocolCreate(lpObj);
	}

	lpObj->RegenOk = 1;
}


//------------------------------------------------------------


BOOL gObjMoveGate(int aIndex, int gt)
{

	if(aIndex < 0 || aIndex > OBJMAX - 1)
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	//---
	BYTE mapNumber = 0;
	BYTE dir = 0;
	//---
	short x,y;
	short level;
	//---
	int result;
	int userlevel = lpObj->Level;
	int movefail = 0;
	//---

	if(lpObj->SkillRecallParty_Time != 0)
	{
		lpObj->SkillRecallParty_Time = 0;
		GCServerMsgStringSend("Summoning cancelled.",aIndex,1);
	}

	if(lpObj->Type == OBJ_USER)
	{
		gDarkSpirit[lpObj->m_Index].SetMode(CDarkSpirit::ePetItem_Mode::PetItem_Mode_Normal,-1);
	}

	if(BC_MAP_RANGE(lpObj->MapNumber))
	{
		if(g_BloodCastle.GetCurrentState(lpObj->MapNumber-11) == BC_STATE_PLAYING)
		{
			g_BloodCastle.SearchUserDropQuestItem(lpObj->m_Index);
		}
		else
		{
			g_BloodCastle.SearchUserDeleteQuestItem(lpObj->m_Index);
		}
	}

	if(lpObj->RegenOk != 0 || gGateC.IsGate(gt) == false)
	{
		if (lpObj->RegenOk != 0)
			LogAdd("Regen OK %s %d",__FILE__,__LINE__);
		else
			LogAdd("Can't find gate number. %d (%s %d)",gt,__FILE__,__LINE__);

		gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

		return false;
	}

	if(gt >= 58 && gt <= 61)
	{
		if(lpObj->m_bDevilSquareAuth == 0)
		{
			LogAdd("[DevilSquare] [%s][%s] Not Used DevilSquare Invitation In DevilSquare",lpObj->AccountID,lpObj->Name);
			return false;
		}
		else
		{
			lpObj->m_bDevilSquareAuth = 0;
		}
	}

	lpObj->m_MoveGateNumber = gt;

	result = gGateC.GetGate(gt,(short &)x,(short &)y,(BYTE &)mapNumber,(BYTE &)dir,(short &)level);

	if(result < 0)
	{
		LogAdd("error : %d (%s %d)",result,__FILE__,__LINE__);

		gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

		return false;
	}

	if(BC_MAP_RANGE(mapNumber)
		|| CC_MAP_RANGE(mapNumber)
		|| DS_MAP_RANGE(mapNumber))
	{
		if(lpObj->m_iSkillNPCHelpTime > 0)
		{
			lpObj->m_iSkillNPCHelpTime = 0;
			lpObj->m_iSkillNPCDefense = 0;
			lpObj->m_iSkillNPCAttack = 0;

			lpObj->m_ViewSkillState &= ~0x2000000;
			GCStateInfoSend(lpObj,0,0x2000000);
		}
	}

 
	if ( result == 97 )
	{
		if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
		{
			if ( lpObj->m_btCsJoinSide != 1 && g_CastleSiege.GetCastleTowerAccessable() == FALSE )
			{
				GCServerMsgStringSend("The Guardian Statue still stands! You may not enter.", lpObj->m_Index, 1);

				gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

				return false;
			}

			if ( lpObj->m_btCsJoinSide == 0 )
			{
				GCServerMsgStringSend("Only the Siege Warfare participants may enter.", lpObj->m_Index, 1);

				gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

				return false;
			}
		}
		else if ( g_CastleSiege.CheckCastleOwnerUnionMember(lpObj->m_Index) == FALSE )
		{
			GCServerMsgStringSend("Only the Guild members of the Castle Lord may enter.", lpObj->m_Index, 1);

			gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

			return false;
		}
	}


	if(mapNumber == MAP_INDEX_ATHLANSE)
	{
		if(lpObj->pInventory[8].IsItem())
		{
			if(lpObj->pInventory[8].m_Type == ITEMGET(13,2))
			{
				GCServerMsgStringSend("You can't enter this area using a Unicorn",lpObj->m_Index,1);

				gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

				return false;
			}

			if(lpObj->pInventory[8].m_Type == ITEMGET(13,3))
			{
				GCServerMsgStringSend("You are currently not able to warp.", lpObj->m_Index, 1);

				gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

				return false;
			}
		}
	}

	if(mapNumber == MAP_INDEX_ICARUS || mapNumber == MAP_INDEX_KANTURU_BOSS)
	{
		if(!(lpObj->pInventory[8].m_Type == ITEMGET(13,3)
			|| lpObj->pInventory[7].m_Type == ITEMGET(13,30)
			|| lpObj->pInventory[8].m_Type == ITEMGET(13,37)
			|| (lpObj->pInventory[7].m_Type >= ITEMGET(12,0) && lpObj->pInventory[7].m_Type <=ITEMGET(12,6)) 
			|| (lpObj->pInventory[7].m_Type >= ITEMGET(12,36) && lpObj->pInventory[7].m_Type <=ITEMGET(12,40)) )
			|| lpObj->pInventory[8].m_Type == ITEMGET(13,2)
			|| lpObj->pInventory[11].m_Type == ITEMGET(13,10)
			|| lpObj->pInventory[10].m_Type == ITEMGET(13,10)
			|| lpObj->pInventory[10].m_Type == ITEMGET(13,39)
			|| lpObj->pInventory[11].m_Type == ITEMGET(13,39)
			|| lpObj->pInventory[10].m_Type == ITEMGET(13,40)
			|| lpObj->pInventory[11].m_Type == ITEMGET(13,40))
		{
			GCServerMsgStringSend("You are currently not able to warp.", lpObj->m_Index, 1);

			gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

			return false;
		}

		if(lpObj->m_RecallMon >= 0)
		{
			GCRecallMonLife(aIndex,60,0);
			gObjMonsterCallKill(aIndex);
		}
	}

	if(!KALIMA_MAP_RANGE(mapNumber) && KALIMA_MAP_RANGE(lpObj->MapNumber))
	{
		int iKalimaGateIndex = lpObj->m_iKalimaGateIndex;

		if(g_KalimaGate.DeleteKalimaGate(lpObj->m_Index))
		{
			LogAdd("[Kalima] [%s][%s] Kalima Gate Vanished - User MoveGate (SummonIndex:%d, EnterCount:%d)",lpObj->AccountID,lpObj->Name,iKalimaGateIndex,gObj[iKalimaGateIndex].m_cKalimaGateEnterCount);
		}
	}

	if(g_iBlockKanturuMapEnter == 1)
	{
		x = lpObj->X;
		y = lpObj->Y;
		mapNumber = lpObj->MapNumber;
		dir = lpObj->Dir;
		level = lpObj->Level;

		if(gGateC.GetGate(gt,(short &)x,(short &)y,(BYTE &)mapNumber,(BYTE &)dir,(short &)level) != -1)
		{
			if(mapNumber >= MAP_INDEX_KANTURU1 && mapNumber <= MAP_INDEX_KANTURU_BOSS)
			{
				GCServerMsgStringSend("You are currently not able to warp.", lpObj->m_Index, 1);

				gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

				return false;
			}
		}
	}

	if(g_iBlockCastleSiegeMapEnter == 1)
	{
		x = lpObj->X;
		y = lpObj->Y;
		mapNumber = lpObj->MapNumber;
		dir = lpObj->Dir;
		level = lpObj->Level;

		if(gGateC.GetGate(gt,(short &)x,(short &)y,(BYTE &)mapNumber,(BYTE &)dir,(short &)level) != -1)
		{
			if(mapNumber == MAP_INDEX_CASTLESIEGE
				|| mapNumber == MAP_INDEX_CASTLEHUNTZONE
				|| mapNumber == MAP_INDEX_CRYWOLF_FIRSTZONE
				|| mapNumber == MAP_INDEX_CRYWOLF_SECONDZONE)
			{
				GCServerMsgStringSend("You are currently not able to warp.", lpObj->m_Index, 1);

				gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);

				return false;
			}
		}
	}

	if(lpObj->Class == 4 || lpObj->Class == 3)
	{
		if(level > 0)
		{
			level = (level / 3)*2;
		}
	}

	if(level != 0)
	{
		if(userlevel < level)
		{
			char szTemp[128];
			wsprintf(szTemp, "You must be over level %d to can access this location.",level);
			GCServerMsgStringSend(szTemp,aIndex,1);

			x = lpObj->X;
			y = lpObj->Y;
			mapNumber = lpObj->MapNumber;
			dir = lpObj->Dir;
			movefail = 1;
		}
	}

	if(lpObj->m_IfState.use != 0 || lpObj->DieRegen != 0)
	{
		x = lpObj->X;
		y = lpObj->Y;
		mapNumber = lpObj->MapNumber;
		dir = lpObj->Dir;
		movefail = 1;
	}

	lpObj->m_State = 32;

	if(movefail == 0)
	{
		if(gGateC.GetGate(gt,(short &)x,(short &)y,(BYTE &)mapNumber,(BYTE &)dir,(short &)level) != -1)
		{
			if(lpObj->MapNumber != mapNumber)
			{
				if(MapNumberCheck(mapNumber)== 0)
				{
					LogAdd("error-L3 : %s %d",__FILE__,__LINE__);
					return false;
				}

				short sSvrCode = g_MapServerManager.CheckMoveMapSvr(lpObj->m_Index,mapNumber,lpObj->m_sPrevMapSvrCode);

				if(sSvrCode != gGameServerCode)
				{
					if(sSvrCode == -1)
					{
						LogAdd("[MapServerMng] Map Server Move Fail : CheckMoveMapSvr() == -1 [%s][%s] (%d)",lpObj->AccountID,lpObj->Name,lpObj->m_Index);
						return false;
					}

					if(gGateC.CheckGateLevel(aIndex,gt) == 0)
					{

						gObjCantMove(x,y,mapNumber,dir,movefail,gt,lpObj);
 
						if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE && g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
						{
							g_CastleSiege.NotifySelfCsJoinSide(aIndex);
							g_CastleSiege.NotifyCsSelfLeftTime(aIndex);
						}

						return false;
					}


					GJReqMapSvrMove(lpObj->m_Index,sSvrCode,mapNumber,(BYTE)x,(BYTE)y);
					LogAdd("[MapServerMng] Request to Move Map Server : (%d) - [%s][%s] (%d)",sSvrCode,lpObj->AccountID,lpObj->Name,lpObj->m_Index);
					return false;
				}
			}
		}

		if( lpObj->MapNumber == 41 || lpObj->MapNumber == 42 ) //Party on Barracks or Refugee Map Preventions (HermeX Fix)
		{
			if ( lpObj->PartyNumber >= 0 )
			{
				PMSG_PARTYDELUSER pMsg;
				int pindex = gParty.GetIndex(lpObj->PartyNumber, lpObj->m_Index, lpObj->DBNumber);

				if ( pindex >= 0 )
				{
					pMsg.Number = pindex;
					CGPartyDelUser(&pMsg, lpObj->m_Index);
				}
			}
		}


		LogAdd("[MoveMap][%s][%s] : (Before:Map:%d X:%d Y:%d) -> (New Map:%d X:%d Y:%d)",lpObj->AccountID,lpObj->Name,lpObj->MapNumber,lpObj->X,lpObj->Y,mapNumber,x,y);

		lpObj->X = x;
		lpObj->Y = y;
		lpObj->TX = x;
		lpObj->TY = y;
		lpObj->MapNumber = mapNumber;
		lpObj->Dir = dir;
		lpObj->PathCount = 0;
		lpObj->Teleport = 0;

		gObjClearViewport(lpObj);
		GCTeleportSend(lpObj,gt,mapNumber,(BYTE)lpObj->X,(BYTE)lpObj->Y,lpObj->Dir);

		if(lpObj->m_Change >= 0)
		{
			gObjViewportListProtocolCreate(lpObj);
		}

		lpObj->RegenMapNumber = mapNumber;
		lpObj->RegenMapX = (BYTE)x;
		lpObj->RegenMapY = (BYTE)y;
		lpObj->RegenOk = 1;

	}
	else
	{
		GCTeleportSend(lpObj,gt,mapNumber,(BYTE)lpObj->X,(BYTE)lpObj->Y,lpObj->Dir);
		lpObj->RegenOk = 1;

 
		if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE && g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
		{
			g_CastleSiege.NotifySelfCsJoinSide(aIndex);
			g_CastleSiege.NotifyCsSelfLeftTime(aIndex);
		}

	}

	if(movefail != 0)
	{
		return false;
	}

	if(lpObj->Type == OBJ_USER)
	{
		lpObj->m_LastTeleportTime = 10;
	}

	return true;
}


//------------------------------------------------------------


void gObjTeleport(int aIndex, int map, int x, int y)
{

	if(aIndex < 0 || aIndex > OBJMAX - 1)
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return;

	if(MapNumberCheck(map)==0)
	{
		LogAdd("error-L3 : %s %d",__FILE__,__LINE__);
		return;
	}

	if(gObj[aIndex].MapNumber != map)
	{
		short sSvrCode = g_MapServerManager.CheckMoveMapSvr(lpObj->m_Index,map,lpObj->m_sPrevMapSvrCode);

		if(sSvrCode != gGameServerCode)
		{
			if(sSvrCode == -1)
			{
				LogAdd("[MapServerMng] Map Server Move Fail : CheckMoveMapSvr() == -1 [%s][%s] (%d)",lpObj->AccountID,lpObj->Name,lpObj->m_Index);
				return;
			}

			GJReqMapSvrMove(lpObj->m_Index,sSvrCode,map,x,y);
			LogAdd("[MapServerMng] Request to Move Map Server : (%d) - [%s][%s] (%d)",sSvrCode,lpObj->AccountID,lpObj->Name,lpObj->m_Index);
			return;
		}
	}

	if(lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 1)
	{
		CGTradeCancelButtonRecv(lpObj->m_Index);
	}

	if(lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 6)
	{
		CGWarehouseUseEnd(lpObj->m_Index);
	}

	lpObj->m_State = 32;
	gObj[aIndex].X = x;
	gObj[aIndex].Y = y;

	gObj[aIndex].TX = x;
	gObj[aIndex].TY = y;	

	gObj[aIndex].MapNumber = map;
	gObj[aIndex].PathCount = 0;
	gObj[aIndex].Teleport = 0;

	gObjClearViewport(&gObj[aIndex]);

	GCTeleportSend(&gObj[aIndex],1,map,(BYTE)gObj[aIndex].X,(BYTE)gObj[aIndex].Y,gObj[aIndex].Dir);

	if(lpObj->m_Change >= 0)
	{
		gObjViewportListProtocolCreate(&gObj[aIndex]);
	}

	gObj[aIndex].RegenMapNumber = map;
	gObj[aIndex].RegenMapX = x;
	gObj[aIndex].RegenMapY = y;
	gObj[aIndex].RegenOk = 1;
}



//------------------------------------------------------------




void gObjMoveDataLoadingOK(int aIndex)
{
	if(gObj[aIndex].RegenOk == 1)
	{
		gObj[aIndex].RegenOk = 2;
	}
}



//------------------------------------------------------------


class CMagicInf* gObjGetMagic(LPOBJ lpObj, int mIndex)
{
	if ( mIndex < 0 || mIndex > MAX_MAGIC-1 )
	{
		LogAdd("Number of magic exceeds. (%s %d)", __FILE__, __LINE__);
		return NULL;
	}

	if ( lpObj->Magic[mIndex].IsMagic() == FALSE )
	{
		return NULL;
	}

	return &lpObj->Magic[mIndex];
}


//------------------------------------------------------------


CMagicInf * gObjGetMagicSearch(LPOBJ lpObj, BYTE skillnumber)
{
	if (lpObj == NULL)
		return false;

	if(skillnumber == 58)
	{
		skillnumber = 40;
	}

	for(int n = 0; n < MAGIC_SIZE;n++)
	{
		if(lpObj->Magic[n].IsMagic() == 1)
		{
			if(lpObj->Magic[n].m_Skill == skillnumber)
			{
				if(gObjMagicEnergyCheck(lpObj,lpObj->Magic[n].m_Skill) == 0)
				{
					GCServerMsgStringSend("You cannot use that skill.",lpObj->m_Index,1);
					return false;
				}
				else
				{
					return &lpObj->Magic[n];
				}
			}
		}
	}
	return false;
}



//------------------------------------------------------------



int	gObjMagicManaUse(LPOBJ lpObj, CMagicInf * lpMagic)
{
	
	if(lpObj->Type != OBJ_USER && lpObj->Connected != PLAYER_PLAYING)
	{
		return false;
	}
	
	if(lpMagic == NULL)
	{
		return false;
	}

	double mana = lpObj->Mana;

	mana -= MagicDamageC.SkillGetMana(lpMagic->m_Skill);

	if(mana < 0)
	{
		return -1;
	}

	return (int)mana;
}


//------------------------------------------------------------


int  gObjMagicBPUse(LPOBJ lpObj, CMagicInf * lpMagic)
{
	if (lpObj == NULL)
		return -1;

	int bp = lpObj->BP;

	if(lpObj->Type != OBJ_USER)
	{
		return false;
	}

	if(lpMagic == 0)
	{
		return false;
	}

	bp -= MagicDamageC.SkillGetBP(lpMagic->m_Skill);

	if(lpObj->BP < 0)
	{
		return -1;
	}

	return bp;
}

//------------------------------------------------------------

struct PMSG_POSMAGIC_RESULT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x2>

struct PMSG_POSMAGIC_COUNT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char MagicNumber;
  /*<thisrel this+0x6>*/ /*|0x1|*/ unsigned char MapX;
  /*<thisrel this+0x7>*/ /*|0x1|*/ unsigned char MapY;
  /*<thisrel this+0x8>*/ /*|0x1|*/ unsigned char Count;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x9>

//---------------------------------------------------------------------------

void gObjMagicAddEnergyCheckOnOff(int flag)
{
	g_EnergyCheckOn = flag;
}



//------------------------------------------------------------


int  gObjMagicAdd(LPOBJ lpObj, BYTE Type, BYTE Index, BYTE Level, BYTE & SkillNumber)
{
	if (lpObj == NULL)
		return -1;

	int skill,n;

	skill = GetSkillNumberInex(Type,Index,Level);

	if(skill < 0)
	{
		LogAdd("error-L2: Doesn't have the skill");
		return -1;
	}

	if(g_EnergyCheckOn == 1)
	{
		const int reqeng = MagicDamageC.SkillGetRequireEnergy(skill);

		if(reqeng < 0)
		{
			LogAdd("error-L2: Skill energy not enough");
			return -1;
		}

		if((lpObj->Energy + lpObj->AddEnergy) < reqeng)
		{
			LogAdd("error-L2: Skill energy not enough");
			return -1;
		}
	}

	const int reqleadership = MagicDamageC.GetskillRequireLeadership(skill);

	if(reqleadership < 0)
	{
		LogAdd("error-L2: Skill Leadership not enough");
		return -1;
	}

	if( (lpObj->Leadership + lpObj->AddLeadership) < reqleadership)
	{
		LogAdd("error-L2: Skill Leadership not enough");
		return -1;
	}

	if(MagicDamageC.SkillGetRequireClass(lpObj->Class,lpObj->ChangeUP,skill) < 1)
	{
		LogAdd("error-L2: His class is not allowed to use the skill");
		return -1;
	}

	for(n = 0; n < MAGIC_SIZE; n++)
	{
		if(lpObj->Magic[n].IsMagic() == 1)
		{
			skill = GetSkillNumberInex(Type,Index,Level);

			if(skill < 0)
			{
				LogAdd("Skill index error (%s %d)",__FILE__,__LINE__);
				return -1;
			}

			if(lpObj->Magic[n].m_Skill == skill)
			{
				LogAdd("Same skill already exists");
				return -1;
			}
		}
	}

	skill = -1;

	for(n = 0; n < MAGIC_SIZE; n++)
	{
		if(lpObj->Magic[n].IsMagic() == 0)
		{
			skill = lpObj->Magic[n].Set(Type,Index,Level);
			if(skill < 0)
			{
				LogAdd("Same magic already exists %s %d",__FILE__,__LINE__);
				return -1;
			}
			else
			{
				lpObj->MagicCount++;
				SkillNumber = skill;
				return n;
			}
		}
	}


	LogAdd("No space to add magic. %s %d",__FILE__,__LINE__);
	return -1;
}



//------------------------------------------------------------


int  gObjMagicDel(LPOBJ lpObj, BYTE aSkill, BYTE Level)
{
	if (lpObj == NULL)
		return -1;

	for(int n = 0; n < MAGIC_SIZE; n++)
	{
		if(lpObj->Magic[n].IsMagic() == 1)
		{
			if(lpObj->Magic[n].m_Skill == aSkill)
			{
				lpObj->Magic[n].Clear();
				return n;
			}
		}
	}
	return -1;
}

//------------------------------------------------------------

int gObjMagicAdd(LPOBJ lpObj, BYTE aSkill, BYTE Level)
{
	if (lpObj == NULL)
		return -1;

	int skill = -1;
	int n;

	if(g_EnergyCheckOn == TRUE)
	{
		const int reqeng = MagicDamageC.SkillGetRequireEnergy(aSkill);

		if(reqeng < 0)
		{
			LogAdd("error-L2: Skill energy not enough");
			return -1;
		}

		if( (lpObj->Energy + lpObj->AddEnergy) < reqeng)
		{
			LogAdd("error-L2: Skill energy not enough");
			return -1;
		}
	}

	if(MagicDamageC.SkillGetRequireClass(lpObj->Class,lpObj->ChangeUP,aSkill) < 1)
	{
		LogAdd("error-L2: His class is not allowed to use the skill");
		return -1;
	}

	for(n = 0; n < MAGIC_SIZE; n++)
	{
		if(lpObj->Magic[n].IsMagic() == 1)
		{
			if(lpObj->Magic[n].m_Skill == aSkill)
			{
				LogAdd("Same skill already exists. %d %d",lpObj->Magic[n].m_Skill,aSkill);
				return -1;
			}
		}
	}

	for(n = 0; n < MAGIC_SIZE; n++)
	{
		if(lpObj->Magic[n].IsMagic() == 0)
		{
			skill = lpObj->Magic[n].Set(aSkill,Level);
			if(skill < 0)
			{
				LogAdd("Same magic already exists %s %d",__FILE__,__LINE__);
				return -1;
			}
			else
			{
				lpObj->MagicCount++;
				return n;
			}
		}
	}

	LogAdd("No space to add magic. %s %d",__FILE__,__LINE__);
	return -1;
}


//------------------------------------------------------------


int gObjWeaponMagicAdd(LPOBJ lpObj, BYTE aSkill, BYTE Level)
{
	if (lpObj == NULL)
		return -1;

	if(MagicDamageC.SkillGetRequireClass(lpObj->Class,lpObj->ChangeUP,aSkill) < 1)
	{
		return -1;
	}

	int skill = -1;

	for(int n = 0; n < MAGIC_SIZE; n++)
	{
		if(lpObj->Magic[n].IsMagic() == FALSE)
		{
			skill = lpObj->Magic[n].Set(aSkill,Level);

			if(skill < 0)
			{
				LogAdd("Same magic already exists %s %d",__FILE__,__LINE__);
				return -1;
			}
			else
			{
				lpObj->MagicCount++;
				return n;
			}
		}
	}
	LogAdd("No space to add magic. %s %d",__FILE__,__LINE__);
	return -1;
}

//------------------------------------------------------------



int gObjMonsterMagicAdd(LPOBJ lpObj, BYTE aSkill, BYTE Level)
{
	int skill = -1;

	for (int n=0; n < MAGIC_SIZE ; n++)
	{
		if ( lpObj->Magic[n].IsMagic() == FALSE )
		{
			skill = lpObj->Magic[n].Set(aSkill, Level);

			if ( skill < 0 )
			{
				LogAdd("Same magic already exists %s %d",__FILE__, __LINE__);
				return -1;
			}
			else
			{
				lpObj->MagicCount++;
				return n;
			}
		}
	}

	LogAdd("No space to add magic. %s %d", __FILE__, __LINE__);
	return -1;
}


//------------------------------------------------------------

BOOL gObjMagicEnergyCheck(LPOBJ lpObj , BYTE aSkill)
{
	if (lpObj == NULL)
		return false;

	const int reqeng = MagicDamageC.SkillGetRequireEnergy(aSkill);

	if(reqeng < 0)
	{
		return false;
	}

	if((lpObj->Energy + lpObj->AddEnergy) < reqeng)
	{
		return false;
	}

	const int reqlevel = MagicDamageC.SkillGetRequireLevel(aSkill);

	if(lpObj->Level < reqlevel)
	{
		return false;
	}

	return true;
}


//---------------------------------------


int gObjFenrirHeal(LPOBJ lpObj, const int Target)
{
	CItem * ItemFenrir = &lpObj->pInventory[Target];

	if(ItemFenrir->m_Durability >= 255)
	{
		return false;
	}

	if(Random(0,10000) < g_iFenrirRepairRate)
	{
		const int iAddDur = Random(0,150) + 50;

		if((ItemFenrir->m_Durability + iAddDur) > 255)
		{
			ItemFenrir->m_Durability = 255.0;
		}
		else
		{
			ItemFenrir->m_Durability += iAddDur;
		}

		MsgOutput(lpObj->m_Index,"The life of Fenrir is %d",int(ItemFenrir->m_Durability));

		LogAdd("[FENRIR REPAIR][SUCCESS] [%s][%s] - %d/255 (+%d)",lpObj->AccountID,lpObj->Name,ItemFenrir->m_Durability,iAddDur);
	}
	else
	{
		MsgOutput(lpObj->m_Index,"The regeneration of life has failed");

		LogAdd("[FENRIR REPAIR][FAILED] [%s][%s] - %d/255 (+%d)",lpObj->AccountID,lpObj->Name,ItemFenrir->m_Durability);
	}

	return true;
}


//------------------------------------------------------------


BOOL gObjItemLevelUp(LPOBJ lpObj, int source, int target)
{

	if(source < 0 || source > MAIN_INVENTORY_SIZE -1)
	{
		return false;
	}

	if(target < 0 || target > MAIN_INVENTORY_SIZE -1)
	{
		return false;
	}

	if(lpObj->pInventory[source].IsItem() == 0)
	{
		return false;
	}

	if(lpObj->pInventory[target].IsItem() == 0)
	{
		return false;
	}

	if(lpObj->pInventory[target].m_Type == ITEMGET(13,37))
	{
		if (gObjFenrirHeal(lpObj,target) )
			return true;
		else
			return false;
	}

	if(  !( lpObj->pInventory[target].m_Type <= ITEMGET(12,6) || ( lpObj->pInventory[target].m_Type >= ITEMGET(12,36) && lpObj->pInventory[target].m_Type <= ITEMGET(12,40) )  || lpObj->pInventory[target].m_Type == ITEMGET(13,30)   )

		|| lpObj->pInventory[target].m_Type == ITEMGET(4,7)
		|| lpObj->pInventory[target].m_Type == ITEMGET(4,15) )
	{
		if (gCanAccessoriesUp)
		{
			if ( !(lpObj->pInventory[target].m_Type == ITEMGET(13,8) || lpObj->pInventory[target].m_Type == ITEMGET(13,9) 
				|| lpObj->pInventory[target].m_Type == ITEMGET(13,12) || lpObj->pInventory[target].m_Type == ITEMGET(13,13) 
				|| (lpObj->pInventory[target].m_Type >= ITEMGET(13,21) && lpObj->pInventory[target].m_Type <= ITEMGET(13,28)) ) )
			{
				return false;
			}
		}
		else
			return false;
	}

	const int _r = Random(0,99);

	if (_r<BlessSuccessRate)
	{
		lpObj->pInventory[target].m_Level++;
		
	}
	else
	{
		if (lpObj->pInventory[target].m_Level > 0)
			lpObj->pInventory[target].m_Level--;	
	}

	if(lpObj->pInventory[target].m_Level > MaxBlessItemUp)
	{
		lpObj->pInventory[target].m_Level = MaxBlessItemUp;
	}
	else
	{
		gObjMakePreviewCharSet(lpObj->m_Index);
	}

	LogAdd("***0556*** [%s][%s] Before using Jewel of Bless : (%s)serial:(%d)(%d)",lpObj->AccountID,lpObj->Name,lpObj->pInventory[target].GetName(),lpObj->pInventory[target].m_Number,lpObj->pInventory[target].m_Level);

	double levelitemdur = ItemGetDurability(lpObj->pInventory[target].m_Type,lpObj->pInventory[target].m_Level,lpObj->pInventory[target].IsExtItem(),lpObj->pInventory[target].IsSetItem());

	lpObj->pInventory[target].m_Durability = levelitemdur * lpObj->pInventory[target].m_Durability / lpObj->pInventory[target].m_BaseDurability;

	lpObj->pInventory[target].Convert(
			lpObj->pInventory[target].m_Type,
			lpObj->pInventory[target].m_Option1,
			lpObj->pInventory[target].m_Option2,
			lpObj->pInventory[target].m_Option3,
			lpObj->pInventory[target].m_NewOption,
			lpObj->pInventory[target].m_SetOption,
			lpObj->pInventory[target].m_ItemOptionEx,
			CURRENT_DB_VERSION);

	LogAdd("[%s][%s]After using Jewel of Bless(%d) : (%s) serial:(%d)(%d)",lpObj->AccountID,lpObj->Name,lpObj->pInventory[source].m_Number,
			lpObj->pInventory[target].GetName(),lpObj->pInventory[target].m_Number,lpObj->pInventory[target].m_Level);
	return true;

}


//------------------------------------------------------------


BOOL gObjItemRandomLevelUp(LPOBJ lpObj, int source, int target)
{

	if(source < 0 || source > MAIN_INVENTORY_SIZE -1)
	{
		return false;
	}

	if(target < 0 || target > MAIN_INVENTORY_SIZE -1)
	{
		return false;
	}

	if(lpObj->pInventory[source].IsItem() == 0)
	{
		return false;
	}

	if(lpObj->pInventory[target].IsItem() == 0)
	{
		return false;
	}

	if(  !( lpObj->pInventory[target].m_Type <= ITEMGET(12,6) || ( lpObj->pInventory[target].m_Type >= ITEMGET(12,36) && lpObj->pInventory[target].m_Type <= ITEMGET(12,40) )  || lpObj->pInventory[target].m_Type == ITEMGET(13,30)   )

		|| lpObj->pInventory[target].m_Type == ITEMGET(4,7)
		|| lpObj->pInventory[target].m_Type == ITEMGET(4,15) )
	{
		if (gCanAccessoriesUp)
		{
			if ( !(lpObj->pInventory[target].m_Type == ITEMGET(13,8) || lpObj->pInventory[target].m_Type == ITEMGET(13,9) 
				|| lpObj->pInventory[target].m_Type == ITEMGET(13,12) || lpObj->pInventory[target].m_Type == ITEMGET(13,13) 
				|| (lpObj->pInventory[target].m_Type >= ITEMGET(13,21) && lpObj->pInventory[target].m_Type <= ITEMGET(13,28)) ) )
			{
				return false;
			}
		}
		else
			return false;
	}

	if(lpObj->pInventory[target].m_Level >= MaxSoulItemUp)
	{
		return false;
	}

	LogAdd("***0558*** [%s][%s] Before using Jewel of Soul : (%s)serial:(%d)(%d)",
		lpObj->AccountID,lpObj->Name,lpObj->pInventory[target].GetName(),
		lpObj->pInventory[target].m_Number,lpObj->pInventory[target].m_Level);

	const int _r = Random(0,99);

	if(lpObj->pInventory[target].m_Option2)
	{
		if(_r < SoulSuccessRateWithLuck)
		{
			lpObj->pInventory[target].m_Level++;
		}
		else
		{
			if(lpObj->pInventory[target].m_Level >= 7)
			{
				lpObj->pInventory[target].m_Level = 0;
			}
			else
			{
				lpObj->pInventory[target].m_Level--;

				if(lpObj->pInventory[target].m_Level < 0)
				{
					lpObj->pInventory[target].m_Level = 0;
				}
			}
		}
	}
	else
	{
		if(_r < SoulSuccessRate)
		{
			lpObj->pInventory[target].m_Level++;
		}
		else
		{
			if(lpObj->pInventory[target].m_Level >= 7)
			{
				lpObj->pInventory[target].m_Level = 0;
			}
			else
			{
				lpObj->pInventory[target].m_Level--;

				if(lpObj->pInventory[target].m_Level < 0)
				{
					lpObj->pInventory[target].m_Level = 0;
				}
			}
		}
	}

	if(lpObj->pInventory[target].m_Level > MaxSoulItemUp)
	{
		lpObj->pInventory[target].m_Level = MaxSoulItemUp;
	}
	else
	{
		gObjMakePreviewCharSet(lpObj->m_Index);
	}

	const double levelitemdur = ItemGetDurability(lpObj->pInventory[target].m_Type,lpObj->pInventory[target].m_Level,lpObj->pInventory[target].IsExtItem(),lpObj->pInventory[target].IsSetItem());

	lpObj->pInventory[target].m_Durability = levelitemdur * lpObj->pInventory[target].m_Durability / lpObj->pInventory[target].m_BaseDurability;

	lpObj->pInventory[target].Convert(
			lpObj->pInventory[target].m_Type,
			lpObj->pInventory[target].m_Option1,
			lpObj->pInventory[target].m_Option2,
			lpObj->pInventory[target].m_Option3,
			lpObj->pInventory[target].m_NewOption,
			lpObj->pInventory[target].m_SetOption,
			lpObj->pInventory[target].m_ItemOptionEx,
			CURRENT_DB_VERSION);

	LogAdd("[%s][%s]After using Jewel of Soul (%d) : (%s) serial:(%d)(%d)",lpObj->AccountID,lpObj->Name,lpObj->pInventory[source].m_Number,
			lpObj->pInventory[target].GetName(),lpObj->pInventory[target].m_Number,lpObj->pInventory[target].m_Level);

	if(g_kJewelOfHarmonySystem.IsStrengthenByJewelOfHarmony(&lpObj->pInventory[target])== 1)
	{
		if(g_kJewelOfHarmonySystem.IsActive(&lpObj->pInventory[target]) == 0)
		{
			GCServerMsgStringSend("Because the goods rank is lower than strengthens the condition, is unable to use.",lpObj->m_Index,1);
		}
	}

	return true;
}


//------------------------------------------------------------



BOOL gObjItemRandomOption3Up(LPOBJ lpObj, int source, int target)
{

	if(source < 0 || source > MAIN_INVENTORY_SIZE -1)
	{
		return false;
	}

	if(target < 0 || target > MAIN_INVENTORY_SIZE -1)
	{
		return false;
	}

	if(lpObj->pInventory[source].IsItem() == 0)
	{
		return false;
	}

	if(lpObj->pInventory[target].IsItem() == 0)
	{
		return false;
	}
																																																			//cape of lord										
    if(  !( lpObj->pInventory[target].m_Type <= ITEMGET(12,6) || ( lpObj->pInventory[target].m_Type >= ITEMGET(12,36) && lpObj->pInventory[target].m_Type <= ITEMGET(12,40) )  || lpObj->pInventory[target].m_Type == ITEMGET(13,30)   )
                 
            || lpObj->pInventory[target].m_Type == ITEMGET(4,7)
            || lpObj->pInventory[target].m_Type == ITEMGET(4,15) )
    {
		if (gCanAccessoriesLifeUp)
		{
			if ( !(lpObj->pInventory[target].m_Type == ITEMGET(13,8) || lpObj->pInventory[target].m_Type == ITEMGET(13,9) 
				|| lpObj->pInventory[target].m_Type == ITEMGET(13,12) || lpObj->pInventory[target].m_Type == ITEMGET(13,13) 
				|| (lpObj->pInventory[target].m_Type >= ITEMGET(13,21) && lpObj->pInventory[target].m_Type <= ITEMGET(13,28)) ) )
			{
				return false;
			}
		}
		else
            return false;
    }

	LogAdd("***0576*** [%s][%s] Before using Jewel of Life : (%s)serial:(%d)(%d)",
		lpObj->AccountID,lpObj->Name,
		lpObj->pInventory[target].GetName(),
		lpObj->pInventory[target].m_Number,
		lpObj->pInventory[target].m_Option3);

	

	if(lpObj->pInventory[target].m_Option3 == 0)
	{
													// 2nd WINGS																					// 3rd WINGS
		if(lpObj->pInventory[target].m_Type >= ITEMGET(12,3) && lpObj->pInventory[target].m_Type <= ITEMGET(12,6) || lpObj->pInventory[target].m_Type >= ITEMGET(12,36) && lpObj->pInventory[target].m_Type <= ITEMGET(12,40) )
		{
			lpObj->pInventory[target].m_NewOption &= 0xDF;

			if(Random(0,1))
			{
				lpObj->pInventory[target].m_NewOption |= 0x20;
			}
		}
	}


	if(lpObj->pInventory[target].m_Option3 < MaxLifeItemUp)
	{
		const int _r = Random(0,99);

		if(_r < LifeSuccessRate)
		{
			lpObj->pInventory[target].m_Option3++;	
		}
		else
		{
			lpObj->pInventory[target].m_Option3 = 0;
		}
	}
	else
	{
		return false;
	}

	gObjMakePreviewCharSet(lpObj->m_Index);

	const double levelitemdur = ItemGetDurability(lpObj->pInventory[target].m_Type,lpObj->pInventory[target].m_Level,lpObj->pInventory[target].IsExtItem(),lpObj->pInventory[target].IsSetItem());

	lpObj->pInventory[target].m_Durability = levelitemdur * lpObj->pInventory[target].m_Durability / lpObj->pInventory[target].m_BaseDurability;

	lpObj->pInventory[target].Convert(
			lpObj->pInventory[target].m_Type,
			lpObj->pInventory[target].m_Option1,
			lpObj->pInventory[target].m_Option2,
			lpObj->pInventory[target].m_Option3,
			lpObj->pInventory[target].m_NewOption,
			lpObj->pInventory[target].m_SetOption,
			lpObj->pInventory[target].m_ItemOptionEx,
			CURRENT_DB_VERSION);

	LogAdd("[%s][%s]After using Jewel of Life (%d) : (%s)serial:(%d)(%d)",
		lpObj->AccountID,lpObj->Name,
		lpObj->pInventory[source].m_Number,
			lpObj->pInventory[target].GetName(),
			lpObj->pInventory[target].m_Number,lpObj->pInventory[target].m_Option3);

	unsigned char NewOption[8];

	ItemIsBufExOption(NewOption,&lpObj->pInventory[target]);

	LogAdd("[%s][%s] JewelofLife Result [%d,%s,%d,%d,%d,%d]serial:[%d] dur:[%d] Ex:[%d,%d,%d,%d,%d,%d,%d]",
			lpObj->AccountID,lpObj->Name,target,lpObj->pInventory[target].GetName(),
			lpObj->pInventory[target].m_Level,lpObj->pInventory[target].m_Option1,lpObj->pInventory[target].m_Option2,
			lpObj->pInventory[target].m_Option3,lpObj->pInventory[target].m_Number,
			BYTE(lpObj->pInventory[target].m_Durability),NewOption[0],NewOption[1],NewOption[2],NewOption[3],
			NewOption[4],NewOption[5],NewOption[6]);

	return true;
}



//------------------------------------------------------------


void gObjAbilityReSet(LPOBJ lpObj)
{
	lpObj->LevelUpPoint = (lpObj->Level - 1) * 5;

	lpObj->Strength = DCInfo.DefClass[lpObj->Class].Strength;
	lpObj->Dexterity = DCInfo.DefClass[lpObj->Class].Dexterity;
	lpObj->Vitality = DCInfo.DefClass[lpObj->Class].Vitality;
	lpObj->Energy = DCInfo.DefClass[lpObj->Class].Energy;

	lpObj->MaxLife = DCInfo.DefClass[lpObj->Class].MaxLife;
	lpObj->MaxMana = DCInfo.DefClass[lpObj->Class].MaxMana;

	if(lpObj->Class == CLASS_WIZARD)
	{
		lpObj->MaxLife += (lpObj->Level -1) / 2;
		lpObj->MaxMana += 2 * (lpObj->Level -1);

		lpObj->Life = lpObj->MaxLife;
		lpObj->Mana = lpObj->MaxMana;
	}
	else
	{
		lpObj->MaxLife += 2 * (lpObj->Level - 1);
		lpObj->MaxMana += (lpObj->Level - 1) / 2;

		lpObj->Life = lpObj->MaxLife;
		lpObj->Mana = lpObj->MaxMana;
	}

	CloseClient(lpObj->m_Index);
}


//------------------------------------------------------------



BOOL gObjTargetGuildWarCheck(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if(lpObj->Type != OBJ_USER)
	{
		return false;
	}

	if(lpTargetObj->Type != OBJ_USER)
	{
		return false;
	}

	if(lpObj->GuildNumber < 1 || lpTargetObj->GuildNumber < 1)
	{
		return false;
	}

	if(lpObj->lpGuild->WarState != 1 || lpTargetObj->lpGuild->WarState != 1)
	{
		return false;
	}

	if(strcmp(lpObj->lpGuild->TargetGuildName,lpTargetObj->lpGuild->Name))
	{
		return false;
	}
	return true;
}



//------------------------------------------------------------


void gObjGuildWarEndSend(LPOBJ lpObj, BYTE Result1, BYTE Result2)
{
	if(lpObj == 0 || lpObj->lpGuild == 0 || lpObj->lpGuild->WarState != 1 || lpObj->lpGuild->lpTargetGuildNode == 0)
	{
		LogAdd("error-L3 : %s %d",__FILE__,__LINE__);
		return;
	}

	if(Result1 == 1)
	{
		gObjGuildWarItemGive(lpObj->lpGuild,lpObj->lpGuild->lpTargetGuildNode);
	}
	else if(Result1 == 3)
	{
		gObjGuildWarItemGive(lpObj->lpGuild->lpTargetGuildNode,lpObj->lpGuild);
	}

	for(int n = 0; n < MAX_USER_GUILD;n++)
	{
		if(lpObj->lpGuild->Use[n] && lpObj->lpGuild->Index[n] >= 0)
		{
			gObj[lpObj->lpGuild->Index[n]].IsInBattleGround = 0;
			GCGuildWarEnd(lpObj->lpGuild->Index[n],Result1,lpObj->lpGuild->lpTargetGuildNode->Name);
		}

		if(lpObj->lpGuild->lpTargetGuildNode->Use[n] && lpObj->lpGuild->lpTargetGuildNode->Index[n] >= 0)
		{
			gObj[lpObj->lpGuild->lpTargetGuildNode->Index[n]].IsInBattleGround = 0;
			GCGuildWarEnd(lpObj->lpGuild->lpTargetGuildNode->Index[n],Result2,lpObj->lpGuild->Name);
		}
	}
}


//------------------------------------------------------------


void gObjGuildWarEndSend(_GUILD_INFO_STRUCT * lpGuild1, _GUILD_INFO_STRUCT * lpGuild2, BYTE Result1, BYTE Result2)
{
	if(lpGuild1 == 0 || lpGuild2 == 0)
	{
		return;
	}

	if(lpGuild1->WarState != 1 || lpGuild2->WarState != 1)
	{
		return;
	}

	for(int n = 0; n < MAX_USER_GUILD;n++)
	{
		if(lpGuild1->Use[n] && lpGuild1->Index[n] >= 0)
		{
			gObj[lpGuild1->Index[n]].IsInBattleGround = 0;
			GCGuildWarEnd(lpGuild1->Index[n],Result1,lpGuild2->Name);
		}
	}

	for(int n = 0; n < MAX_USER_GUILD;n++)
	{
		if(lpGuild2->Use[n] && lpGuild2->Index[n] >= 0)
		{
			gObj[lpGuild2->Index[n]].IsInBattleGround = 0;
			GCGuildWarEnd(lpGuild2->Index[n],Result2,lpGuild1->Name);
		}
	}
}



//------------------------------------------------------------


void gObjGuildWarEnd(_GUILD_INFO_STRUCT * lpGuild, _GUILD_INFO_STRUCT * lpTargetGuild)
{
	if(lpGuild == 0 || lpTargetGuild == 0)
	{
		return;
	}

	lpGuild->WarDeclareState = 0;
	lpGuild->WarState = 0;

	if(lpTargetGuild != 0)
	{
		lpTargetGuild->WarDeclareState = 0;
		lpTargetGuild->WarState = 0;

		if(lpGuild->lpTargetGuildNode != 0)
		{
			_GUILD_INFO_STRUCT * lpTguild = lpGuild->lpTargetGuildNode;

			lpGuild->lpTargetGuildNode = 0;
			lpTguild->lpTargetGuildNode = 0;
		}
	}
	else
	{
		lpGuild->lpTargetGuildNode = 0;
	}
}



//------------------------------------------------------------



BOOL gObjGuildWarProc(_GUILD_INFO_STRUCT * lpGuild1, _GUILD_INFO_STRUCT * lpGuild2, int score)
{
	if(lpGuild1 == 0 || lpGuild2 == 0)
	{
		return false;
	}

	int totalscore;
	int n;
	int maxscore;
	char szTemp[50];


	totalscore = 1;
	maxscore = 20;

	lpGuild1->PlayScore += score;

	wsprintf(szTemp,"%s ( %d ) VS %s ( %d )",lpGuild1->Name,lpGuild1->PlayScore,lpGuild2->Name,lpGuild2->PlayScore);
	LogAdd(szTemp);

	if(lpGuild1->WarType == 1)
	{
		SetBattleTeamScore(lpGuild1->BattleGroundIndex,lpGuild1->BattleTeamCode,lpGuild1->PlayScore);
		maxscore = 100;
	}
	else
	{
		maxscore = 20;
	}

	cManager.BattleInfoSend(GetBattleTeamName(0,0),GetBattleTeamScore(0,0),GetBattleTeamName(0,1),GetBattleTeamScore(0,1));

	if(lpGuild1->PlayScore >= maxscore)
	{
		if(lpGuild1->PlayScore > maxscore && lpGuild2->PlayScore == 0)
		{
			totalscore = 3;
		}
		else if(lpGuild1->PlayScore > maxscore && lpGuild2->PlayScore <= 10)
		{
			totalscore = 2;
		}

		lpGuild1->TotalScore += totalscore;
		DGGuildScoreUpdate(lpGuild1->Name,lpGuild1->TotalScore);
		DGGuildScoreUpdate(lpGuild2->Name,lpGuild2->TotalScore);

		return true;
	}

	for(n = 0; n < MAX_USER_GUILD; n++)
	{
		if(lpGuild1->Use[n] && lpGuild1->Index[n] >= 0)
		{
			GCGuildWarScore(lpGuild1->Index[n]);
		}
	}

	for(n = 0; n < MAX_USER_GUILD; n++)
	{
		if(lpGuild2->Use[n] && lpGuild2->Index[n] >= 0)
		{
			GCGuildWarScore(lpGuild2->Index[n]);
		}
	}
	return false;
}



//------------------------------------------------------------



BOOL gObjGuildWarCheck(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if(gObjTargetGuildWarCheck(lpObj,lpTargetObj) == false)
	{
		return false;
	}

	int score = 1;//1 ���� �� ������ ��������

	if(strcmp(lpTargetObj->Name,lpTargetObj->lpGuild->Names[0])==0)
	{
		score = 2;// 2 ����� �� �������� �������� ���
	}

	_GUILD_INFO_STRUCT * lpGuild = lpObj->lpGuild;
	_GUILD_INFO_STRUCT * lpTargetGuild = lpTargetObj->lpGuild;

	if(gObjGuildWarProc(lpGuild,lpTargetGuild,score) == TRUE)
	{
		if(lpGuild->WarType == 1)
		{
			gObjGuildWarEndSend(lpGuild,lpTargetGuild,1,0);
			gBattleGroundEnable(lpGuild->BattleGroundIndex,0);
			gObjGuildWarEnd(lpGuild,lpTargetGuild);
			cManager.BattleInfoSend(GetBattleTeamName(0,0),255,GetBattleTeamName(0,1),255);
		}
		else
		{
			gObjGuildWarEndSend(lpObj,1,0);
			gObjAddMsgSendDelay(lpObj,4,lpObj->m_Index,2000,0);
		}
	}
	return true;
}



//------------------------------------------------------------



BOOL gObjGuildWarMasterClose(LPOBJ lpObj)
{
	if(lpObj->GuildNumber < 1)//�������� �� ������ ���� �����
	{
		return false;
	}

	if(strcmp(lpObj->lpGuild->Names[0],lpObj->Name))//�������� �� �� ��
	{
		return false;
	}

	gObjGuildWarEndSend(lpObj,3,2);

	if(lpObj->lpGuild->WarType == 1 && lpObj->lpGuild->BattleGroundIndex < 1)
	{
		gBattleGroundEnable(lpObj->lpGuild->BattleGroundIndex,0);
		cManager.BattleInfoSend(GetBattleTeamName(0,0),255,GetBattleTeamName(0,1),255);
	}
	gObjGuildWarEnd(lpObj->lpGuild,lpObj->lpGuild->lpTargetGuildNode);
	return true;
}



//------------------------------------------------------------



bool gObjGuildWarItemGive(_GUILD_INFO_STRUCT * lpWinGuild, _GUILD_INFO_STRUCT * lpLoseGuild)
{
	if (!gIsGuildWarReward)
		return false;
	int n;
	int r_userindex[MAX_USER_GUILD];
	int r_usercount = 0;

	for(n = 0; n < MAX_USER_GUILD; n++)
	{
		if(lpLoseGuild->Use[n] > 0)
		{
			if (gObj[lpLoseGuild->Index[n]].Connected == PLAYER_PLAYING)
			{
				r_userindex[r_usercount] = lpLoseGuild->Index[n];
				r_usercount++;
			}

		}
	}

	if(r_usercount < 1)
	{
		LogAdd("error2: No user in the loser guild  is in game.. %s %d",__FILE__,__LINE__);
		return false;
	}

	int lose_user = r_userindex[Random(0,r_usercount-1)];

	if(lose_user < 0)
	{
		LogAdd("error2: No user in the loser guild  is in game.. %s %d",__FILE__,__LINE__);
		return false;
	}

	if(gObj[lose_user].Connected != PLAYER_PLAYING)
	{
		LogAdd("error2: No user in the loser guild  is in game.. %s %d",__FILE__,__LINE__);
		return false;
	}

	r_usercount = 0;

	for(n = 0; n < MAX_USER_GUILD;n++)
	{
		if(lpWinGuild->Use[n] > 0)
		{
			if (gObj[lpWinGuild->Index[n] ].Connected == PLAYER_PLAYING) 
			{
				r_userindex[r_usercount] = lpWinGuild->Index[n];
				r_usercount++;
			}

		}
	}

	if(r_usercount < 1)
	{
		LogAdd("error2: No user in the winner guild is in game");
		return false;
	}

	int win_user = r_userindex[Random(0,r_usercount-1)];

	if(win_user < 0)
	{
		LogAdd("error2: No user in the winner guild is in game");
		return false;
	}

	if(gObj[win_user].Connected != PLAYER_PLAYING)
	{
		LogAdd("error2: No user in the winner guild is in game");
		return false;
	}

	LPOBJ lpLoseObj = &gObj[lose_user];
	LPOBJ lpWinObj = &gObj[win_user];

	int count = 24;

	int number;

	while (1)
	{
		number = Random(0,71);
		if (lpLoseObj->pInventory[number].IsItem() )
			break;
	}

	if(gObjInventoryInsertItem(win_user,lpLoseObj->pInventory[number]) != -1)
	{

	}
	else
	{
		ItemSerialCreateSend(win_user,lpWinObj->MapNumber,(BYTE)lpWinObj->X,(BYTE)lpWinObj->Y,(BYTE)lpLoseObj->pInventory[number].m_Type,(BYTE)lpLoseObj->pInventory[number].m_Level,(BYTE)lpLoseObj->pInventory[number].m_Durability,lpLoseObj->pInventory[number].m_Option1,lpLoseObj->pInventory[number].m_Option2,lpLoseObj->pInventory[number].m_Option3,-1,lpLoseObj->pInventory[number].m_NewOption,lpLoseObj->pInventory[number].m_SetOption);
	}

	gObjInventoryDeleteItem(lose_user,number);

	return true;
}



//------------------------------------------------------------


int gObjGetPkTime(LPOBJ lpObj, int& hour, int& min)
{
	if (lpObj == NULL)
		return false;

	int pktime = 0;

	if(lpObj->m_PK_Time > 0)
	{
		pktime = lpObj->m_PK_Time / 60;
	}

	if(lpObj->m_PK_Level == 4)
	{
		hour = (180 - pktime) / 60;
		min = (180 - pktime) % 60;
		return true;
	}

	if(lpObj->m_PK_Level == 5)
	{
		hour = (360 - pktime) / 60;
		min = (360 - pktime) % 60;
		return true;
	}

	if(lpObj->m_PK_Level >= 6)
	{
		hour = (((lpObj->m_PK_Count - 3) * 60 + 540) - pktime) / 60;
		min = (((lpObj->m_PK_Count - 3) * 60 + 540) - pktime) % 60;
		return true;
	}

	return false;
}



//------------------------------------------------------------



BOOL gObjMonsterCall(int aIndex, int MonsterType, int x, int y)
{

	if(!OBJMAX_RANGE(aIndex))
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	if(lpObj->MapNumber == MAP_INDEX_ICARUS)
	{
		return false;
	}

	if(lpObj->m_RecallMon >= 0)
	{

		GCRecallMonLife(aIndex,60,0);
		gObjMonsterCallKill(aIndex);
		return false;
	}

	int result = gObjAddCallMon();

	if(result >= 0)
	{
		LPOBJ lpTargetObj = &gObj[result];

		lpTargetObj->X = x;
		lpTargetObj->Y = y;

		lpTargetObj->MTX = x;
		lpTargetObj->MTY = y;
		lpTargetObj->Dir = 2;

		lpTargetObj->MapNumber = lpObj->MapNumber;

		gObjSetMonster(result,MonsterType);//��������� �������

		lpTargetObj->m_RecallMon = aIndex;
		lpTargetObj->m_Attribute = 100;

		lpTargetObj->TargetNumber = -1;
		lpTargetObj->m_ActState.Emotion = 0;
		lpTargetObj->m_ActState.Attack = 0;
		lpTargetObj->m_ActState.EmotionCount = 0;

		lpTargetObj->PathCount = 0;

		lpObj->m_RecallMon = result;
		lpTargetObj->m_MoveRange = 15;

		GCRecallMonLife(lpTargetObj->m_RecallMon,(int)lpTargetObj->MaxLife,(int)lpTargetObj->Life);
		LogAdd("[Summon Monster] [%s][%s] Try to Summon Monster - Succeed (SummonIndex:%d)",lpObj->AccountID,lpObj->Name,result);
		return true;
	}
	return false;
}



//------------------------------------------------------------


void gObjMonsterCallKill(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	LogAdd("[Summon Monster] [%s][%s] Try to Kill Summoned Monster",lpObj->AccountID,lpObj->Name);

	if(lpObj->m_RecallMon < 0)
	{
		return;
	}

	int callmon = lpObj->m_RecallMon;

	if(callmon < 0 || callmon > OBJMAX -1 )
	{
		return;
	}

	if(gObj[callmon].Type != OBJ_MONSTER)
	{
		return;
	}

	if(gObj[callmon].m_RecallMon != aIndex)
	{
		return;
	}

	if(lpObj->m_RecallMon >= 0)
	{
		if(gObjIsConnected(lpObj->m_RecallMon)==1)
		{
			LogAdd("[Summon Monster] [%s][%s] Try to Kill Summoned Monster - Found Summoned Monster (SummonIndex:%d)",lpObj->AccountID,lpObj->Name,lpObj->m_RecallMon);
			gObj[lpObj->m_RecallMon].m_RecallMon = -1;
		}
	}

	lpObj->m_RecallMon = -1;
	gObjDel(callmon);

	LogAdd("[Summon Monster] [%s][%s] Try to Kill Summoned Monster - Finished to Kill Summoned Monster (SummonIndex:%d)",lpObj->AccountID,lpObj->Name,callmon);
}



//------------------------------------------------------------



BOOL gObjCheckTeleportArea(int aIndex, BYTE x, BYTE y)
{
	LPOBJ lpObj = &gObj[aIndex];

	if(x < (lpObj->X - 8)
		|| x > (lpObj->X + 8)
		|| y < (lpObj->Y - 8)
		|| y > (lpObj->Y + 8))
	{
		return false;
	}

	int mapnumber = lpObj->MapNumber;

	if(mapnumber < 0 || mapnumber >= MAX_NUMBER_MAP)
	{
		return false;
	}

	unsigned char attr = MapC[mapnumber].GetAttr(x,y);

	if(attr)
	{
		return false;
	}

	attr = MapC[mapnumber].GetAttr(lpObj->X,lpObj->Y);

	if(attr & 1)
	{
		return false;
	}

	return true;
}


//------------------------------------------------------------



BOOL gObjCheckAttackAreaUsedPath(int aIndex, int TarObjIndex)
{
	int X,Y;

	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTargetObj = &gObj[TarObjIndex];

	if(lpObj->PathCount > 1)
	{
		 X = lpObj->PathX[lpObj->PathCount-1];
		 Y = lpObj->PathY[lpObj->PathCount-1];
	}
	else
	{
		return false;
	}

	if(lpTargetObj->X < (X - 10)
		|| lpTargetObj->X > (X + 10)
		|| lpTargetObj->Y < (Y - 10)
		|| lpTargetObj->Y > (Y + 10))
	{
		return false;
	}
	return true;
}



//------------------------------------------------------------


BOOL gObjCheckattackAreaUsedViewPort(int aIndex, int TarObjIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTargetObj = &gObj[TarObjIndex];

	if(lpTargetObj->m_Index == lpObj->m_Index)
	{
		return true;
	}

	int MVL = MAX_VIEWPORT;

	if(lpObj->Type == OBJ_MONSTER)
	{
		MVL = MAX_VIEWPORT_MONSTER;
	}

	for(int n = 0; n < MVL;n++)
	{
		if(lpObj->VpPlayer[n].state)
		{
			if(lpObj->VpPlayer[n].number == lpTargetObj->m_Index)
			{
				return true;
			}
		}

		if(lpObj->VpPlayer2[n].state)
		{
			if(lpObj->VpPlayer2[n].number == lpTargetObj->m_Index)
			{
				return true;
			}
		}
	}
	return false;
}



//------------------------------------------------------------



int  gObjCheckAttackArea(int aIndex, int TarObjIndex)
{

	if(gObjCheckattackAreaUsedViewPort(aIndex,TarObjIndex)==0)
	{
		return 1;
	}

	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTargetObj = &gObj[TarObjIndex];

	int mapnumber = lpObj->MapNumber;

	if(mapnumber < 0 || mapnumber >= MAX_NUMBER_MAP)
	{
		return 2;
	}

	int tarmapnumber = lpTargetObj->MapNumber;

	if(tarmapnumber < 0 || tarmapnumber >= MAX_NUMBER_MAP)
	{
		return 3;
	}

	if(tarmapnumber != mapnumber)
	{
		return 4;
	}
 
	unsigned char attr = MapC[mapnumber].GetAttr(lpTargetObj->X,lpTargetObj->Y);

	if(attr && !(attr&2))
	{
		return 5;
	}


	return false;
}


//------------------------------------------------------------



BOOL gUserFindDevilSquareInvitation(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	const int Item1 = ITEMGET(14,19);
	const int Item2 = ITEMGET(13,46);

	for(int n = 0; n < MAIN_INVENTORY_SIZE; n++)
	{
		if(lpObj->pInventory[n].IsItem() )
		{
			if(lpObj->pInventory[n].m_Type == Item1 )
			{
				return true;
			}

			if(lpObj->pInventory[n].m_Type == Item2 )
			{
				return true;
			}
		}
	}
	return false;
}



//------------------------------------------------------------



BOOL gUserFindDevilSquareKeyEyes(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	bool bFindKey = 0;
	bool bFindEyes = 0;
	const int Item1 = ITEMGET(14,17);
	const int Item2 = ITEMGET(14,18);

	for(int n = 0; n < MAIN_INVENTORY_SIZE; n++)
	{
		if(lpObj->pInventory[n].IsItem() )
		{
			if(lpObj->pInventory[n].m_Type == Item1 )
			{
				bFindEyes = true;
				if(bFindKey != false && bFindEyes != false)
				{
					return true;
				}
			}

			if(lpObj->pInventory[n].m_Type == Item2 )
			{
				bFindKey = true;
				if(bFindKey != false && bFindEyes != false)
				{
					return true;
				}
			}
		}
	}


	return false;
}



//------------------------------------------------------------



void gObjSendUserStatistic(int aIndex, int startLevel, int endLevel)
{
	if(gDisconnect)
	{
		return;
	}

	if(endLevel < startLevel)
	{
		endLevel = MAX_CHAR_LEVEL;
	}

	LPOBJ lpObj;
	int sClassCount[6];

	sClassCount[CLASS_WIZARD] = 0;
	sClassCount[CLASS_KNIGHT] = 0;
	sClassCount[CLASS_ELF] = 0;
	sClassCount[CLASS_MAGUMSA] = 0;
	sClassCount[CLASS_DARKLORD] = 0;

	for(int n = OBJ_STARTUSERINDEX; n < OBJMAX; n++)
	{
		lpObj = &gObj[n];

		if(lpObj->Connected == PLAYER_PLAYING)
		{
			if(lpObj->Level >= startLevel && lpObj->Level <= endLevel)
			{
				sClassCount[lpObj->Class]++;
			}

			sClassCount[5]++;
		}
	}

	MsgOutput(gObj[aIndex].m_Index,"[%d]-[%d] Total %d %s %d %s %d %s %d %s %d %s %d",startLevel,endLevel,sClassCount[5],
		"Dark Wizard",sClassCount[CLASS_WIZARD],
		"Dark Knight",sClassCount[CLASS_KNIGHT],
		"Elf",sClassCount[CLASS_ELF],
		"Magic Gladiator",sClassCount[CLASS_MAGUMSA],
		"Dark Lord",sClassCount[CLASS_DARKLORD]);
}



//------------------------------------------------------------


LPOBJ gObjFind(char * targetcharname)
{
	if ( gDisconnect == TRUE )
	{
		return NULL;
	}

	LPOBJ lpObj;

	for (int n = OBJ_STARTUSERINDEX ; n < OBJMAX; n++)
	{
		lpObj = &gObj[n];

		if ( lpObj->Connected == PLAYER_PLAYING )
		{
			if ( lpObj->Name[0] == targetcharname[0] )
			{
				if ( strcmp(lpObj->Name, targetcharname) == 0 )
				{
					return lpObj;
				}
			}
		}
	}

	return NULL;

}



//------------------------------------------------------------


BOOL gObjFind10EventChip(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	int count = 0;
	const int Item = ITEMGET(14,21);

	for(int n = 0; n < MAIN_INVENTORY_SIZE; n++)
	{
		if(lpObj->pInventory[n].IsItem() )
		{
			if(lpObj->pInventory[n].m_Type == Item)
			{
				count++;

				if(count == 10)
				{
					return true;
				}
			}
		}
	}
	return false;
}


//------------------------------------------------------------



BOOL gObjDelete10EventChip(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	int count = 0;
	const int Item = ITEMGET(14,21); 

	for(int n = 0; n < MAIN_INVENTORY_SIZE;n++)
	{
		if(lpObj->pInventory[n].IsItem())
		{
			if(lpObj->pInventory[n].m_Type == Item)
			{
				gObjInventoryDeleteItem(aIndex,n);
				GCInventoryItemDeleteSend(aIndex,n,1);
				LogAdd("[EventChip] [%s][%s] Delete Rena (%d)",lpObj->AccountID,lpObj->Name,n);
				count++;

				if(count == 10)
				{
					return true;
				}
			}
		}
	}
	return false;
}


//------------------------------------------------------------


void gObjSetPosition(int aIndex, int x, int y)
{

	if(!OBJMAX_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return;

	PMSG_POSISTION_SET pMove;

	pMove.h.c = 0xC1;
	pMove.h.headcode = P_DAMAGE;
	pMove.h.size = sizeof(pMove);

	pMove.X = x;
	pMove.Y = y;

	lpObj->m_Rest = 0;


	MapC[lpObj->MapNumber].ClearStandAttr(lpObj->m_OldX,lpObj->m_OldY);
	MapC[lpObj->MapNumber].SetStandAttr(x,y);

	lpObj->m_OldX = x;
	lpObj->m_OldY = y;

	RecvPositionSetProc(&pMove,lpObj->m_Index);
}


//------------------------------------------------------------



int  gObjGetItemCountInEquipment(int aIndex, int itemtype, int itemindex, int itemlevel) //������� �-��� ���������� ������� ���� �� ��������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return 0;

	int count = 0;
	const int Item = itemtype * MAX_SUBTYPE_ITEMS + itemindex;

	for ( int n = 0; n < MAX_PLAYER_EQUIPMENT ; n++ )
	{
		if ( lpObj->pInventory[n].IsItem() )
		{
			if ( lpObj->pInventory[n].m_Type == Item )
			{
				if ( itemlevel != -1 )
				{
					if (  lpObj->pInventory[n].m_Level != itemlevel )
					{
						continue;
					}
					else
						count++;
				}
				else
					count++;				
			}
		}
	}

	return count;
}



//------------------------------------------------------------



int  gObjGetItemCountInIventory(int aIndex, int itemtype, int itemindex, int itemlevel)//������� �-��� ���������� ������� ���� � ��������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return 0;

	int count = 0;

	const int Item = ITEMGET(itemtype,itemindex);

	for ( int n = 0; n < MAIN_INVENTORY_SIZE ; n++ )
	{
		if ( lpObj->pInventory[n].IsItem() )
		{
			if ( lpObj->pInventory[n].m_Type == Item )
			{
				if ( itemlevel != -1 )
				{
					if (  lpObj->pInventory[n].m_Level != itemlevel )
					{
						continue;
					}
					else
						count++;
				}
				else
					count++;
			}
		}
	}

	return count;
}



//------------------------------------------------------------


int gObjGetItemCountInIventory(int aIndex, int itemnum)//������� �-��� ���������� ������� ���� � ��������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return 0;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return 0;

	int count = 0;

	for ( int n=0; n < MAIN_INVENTORY_SIZE; n++)
	{
		if ( lpObj->pInventory[n].IsItem() )
		{
			if ( lpObj->pInventory[n].m_Type == itemnum )
			{
				count++;
			}
		}
	}

	return count;

}



//------------------------------------------------------------


int  gObjGetManaItemPos(int aIndex)	//����������� � �������� ������� ����� ������� ����� �������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return -1;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return -1;

	const int SmallMP = ITEMGET(14,4);
	const int MedMP = ITEMGET(14,5);
	const int LargeMP =  ITEMGET(14,6);

	for ( int n=0; n < MAIN_INVENTORY_SIZE; n++)
	{
		if ( lpObj->pInventory[n].IsItem() )
		{
			if ( lpObj->pInventory[n].m_Type == SmallMP || lpObj->pInventory[n].m_Type == MedMP || lpObj->pInventory[n].m_Type == LargeMP )
			{
				return n;
			}
		}
	}

	return -1;
}


//------------------------------------------------------------



void gObjDelteItemCountInInventory(int aIndex, int itemtype, int itemindex, int count)//��������� ����� � ���������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return;

	int delcount = 0;
	const int Item = itemtype * 512 + itemindex;
	for(int n = 0; n < MAIN_INVENTORY_SIZE; n++)
	{
		if(lpObj->pInventory[n].IsItem() )
		{
			if(lpObj->pInventory[n].m_Type == Item)
			{
				gObjInventoryDeleteItem(aIndex,n);
				GCInventoryItemDeleteSend(aIndex,n,1);
				LogAdd("[DeleteItem] [%s][%s] Delete (%d,%d)(%d)",lpObj->AccountID,lpObj->Name,itemtype,itemindex,n);
				delcount++;

				if(delcount == count)
				{
					return;
				}
			}
		}
	}
}


//------------------------------------------------------------


void gObjGetStatPointState(int aIndex, short& AddPoint, short& MaxAddPoint, short& MinusPoint, short& MaxMinusPoint)//���������� ����� ��� ������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return;

	if(lpObj->Level < 6)
	{
		AddPoint = 0;
		MaxAddPoint = 0;
	}

	int total_point = lpObj->Strength + lpObj->Dexterity + lpObj->Vitality + lpObj->Energy + lpObj->Leadership + lpObj->LevelUpPoint;

	if (lpObj->Class == CLASS_DARKLORD)
		total_point += lpObj->Leadership;

	int ori_point;

	if(lpObj->Class == CLASS_DARKLORD || lpObj->Class == CLASS_MAGUMSA)
	{
		ori_point = DCInfo.GetDefPoint(lpObj->Class) + (lpObj->Level - 1) * 7;
	}
	else
	{
		ori_point = DCInfo.GetDefPoint(lpObj->Class) + (lpObj->Level - 1) * 5;
	}

	if(g_QuestInfo.GetQuestState(lpObj,0) == 2)
	{
		ori_point+= 10;
	}

	if(g_QuestInfo.GetQuestState(lpObj,1) == 2)
	{
		ori_point+= 10;
	}

	if(g_QuestInfo.GetQuestState(lpObj,2) == 2)
	{
		ori_point+= lpObj->Level - 220;
	}

	    //Season3 Quest MaxPoint Calculation
    if(g_QuestInfo.GetQuestState(lpObj,4) == 2)
    {
            ori_point+= 20;
    }

    if(g_QuestInfo.GetQuestState(lpObj,5) == 2)
    {
            ori_point+= 20;
    }

    if(g_QuestInfo.GetQuestState(lpObj,6) == 2)
    {
            ori_point+= 30;
    }

	int addpoint = ori_point;

	addpoint += gStatMng.GetMaxStat(lpObj->Level,lpObj->Class);

	AddPoint = total_point - ori_point;
	MaxAddPoint = gStatMng.GetMaxStat(lpObj->Level,lpObj->Class);
	MinusPoint = lpObj->iFruitPoint;
	MaxMinusPoint = gStatMng.GetMaxMinusStat(lpObj->Level,lpObj->Class);
}


//------------------------------------------------------------



BOOL gObjCheckStatPointUp(int aIndex)//�������� �� ����� ������ "�����" �� ���������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	int total_point = lpObj->Strength + lpObj->Dexterity + lpObj->Vitality + lpObj->Energy + lpObj->Leadership + lpObj->LevelUpPoint;

	if (lpObj->Class == CLASS_DARKLORD)
		total_point += lpObj->Leadership;

	int ori_point;

	if(lpObj->Class == CLASS_DARKLORD || lpObj->Class == CLASS_MAGUMSA)
	{
		ori_point = DCInfo.GetDefPoint(lpObj->Class) + (lpObj->Level - 1) * 7;
	}
	else
	{
		ori_point = DCInfo.GetDefPoint(lpObj->Class) + (lpObj->Level - 1) * 5;
	}

	if(g_QuestInfo.GetQuestState(lpObj,0) == 2)
	{
		ori_point+= 10;
	}

	if(g_QuestInfo.GetQuestState(lpObj,1) == 2)
	{
		ori_point+= 10;
	}

	if(g_QuestInfo.GetQuestState(lpObj,2) == 2)
	{
		ori_point+= lpObj->Level - 220;
	}


    //Season3 Quest MaxPoint Calculation
    if(g_QuestInfo.GetQuestState(lpObj,4) == 2)
    {
            ori_point+= 20;
    }

    if(g_QuestInfo.GetQuestState(lpObj,5) == 2)
    {
            ori_point+= 20;
    }

    if(g_QuestInfo.GetQuestState(lpObj,6) == 2)
    {
            ori_point+= 30;
	}


	ori_point += gStatMng.GetMaxStat(lpObj->Level,lpObj->Class);

	if(total_point < ori_point)
	{
		return true;
	}
	return false;
}



//------------------------------------------------------------


BOOL gObjCheckStatPointDown(int aIndex)//�������� �� ����� ������ "�����" �� ���������
{
	if(!OBJMAX_RANGE(aIndex))
	{
		return false;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return false;

	int total_point = lpObj->Strength + lpObj->Dexterity + lpObj->Vitality + lpObj->Energy + lpObj->LevelUpPoint;

	if (lpObj->Class == CLASS_DARKLORD)
		total_point += lpObj->Leadership;

	int ori_point;

	if(lpObj->Class == CLASS_DARKLORD || lpObj->Class == CLASS_MAGUMSA)
	{
		ori_point = DCInfo.GetDefPoint(lpObj->Class) + (lpObj->Level - 1) * 7;
	}
	else
	{
		ori_point = DCInfo.GetDefPoint(lpObj->Class) + (lpObj->Level - 1) * 5;
	}

	if(g_QuestInfo.GetQuestState(lpObj,0) == 2)
	{
		ori_point+= 10;
	}

	if(g_QuestInfo.GetQuestState(lpObj,1) == 2)
	{
		ori_point+= 10;
	}

    //Aplied Webzen Fix for MaxPoint Calculation
    if(g_QuestInfo.GetQuestState(lpObj,2) == 2)
    {
            ori_point+= lpObj->Level - 220;
    }

    //Season3 Quest MaxPoint Calculation
    if(g_QuestInfo.GetQuestState(lpObj,4) == 2)
    {
            ori_point+= 20;
    }

    if(g_QuestInfo.GetQuestState(lpObj,5) == 2)
    {
            ori_point+= 20;
    }

    if(g_QuestInfo.GetQuestState(lpObj,6) == 2)
    {
            ori_point+= 30;
    }

	ori_point += gStatMng.GetMaxStat(lpObj->Level,lpObj->Class);

	if(total_point > ori_point)
	{
		return true;
	}
	return false;
}


//------------------------------------------------------------


struct PMSG_USE_STAT_FRUIT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char result;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char btStatValue;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char btFruitType;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};

void gObjUsePlusStatFruit(int aIndex,int pos)//������������ ������ �� ���� ��� �����
{


	//�������� �������� �� ��������� ������
	if(!OBJMAX_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return;

	int iItemLevel = lpObj->pInventory[pos].m_Level;
	int iItemSerial = lpObj->pInventory[pos].m_Number;
	int iCharacterClass = lpObj->Class;

	PMSG_USE_STAT_FRUIT pResult;

	PHeadSetB((LPBYTE)&pResult,0x2C,sizeof(pResult));

	pResult.result = 5;
	pResult.btFruitType = iItemLevel;
	pResult.btStatValue = 0;

	if(lpObj->Level < FruitPlusMinUseLevel || iItemLevel > 4)//�������� �� ���������� ����� ����������� ��� �� "�������" ������ ������
	{
		pResult.result = 5;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}

	if(iItemLevel == 4 && lpObj->Class != 4)//���� ����� �� ������� ��� ����� ��������� �� ��
	{
		pResult.result = 5;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}

	/*for(int iItemIndex = 0; iItemIndex < INVETORY_WEAR_SIZE; iItemIndex++)//����... ������ ���� ������ �� ��������, � ���� � ������ �� �� ���� �����
	{
		if(lpObj->pInventory[iItemIndex].IsItem())
		{
			pResult.result = 16;
			DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
			return;
		}
	}*/

	if(gObjCheckStatPointUp(aIndex) == false)
	{
		pResult.result = 33;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}


	LogAdd("[StatUp] [%s][%s] Use StatUpItem Level:%d Pos:%d serial:%d",
		lpObj->AccountID,lpObj->Name,iItemLevel,pos,iItemSerial);

	gObjInventoryItemSet(aIndex,pos,0xFF);
	lpObj->pInventory[pos].Clear();
	GCInventoryItemDeleteSend(aIndex,pos,1);

	short AddPoint;
	short MaxAddPoint;
	short MinusPoint;
	short MaxMinusPoint;

	gObjGetStatPointState(aIndex,(short &)AddPoint,(short &)MaxAddPoint,(short &)MinusPoint,(short &)MaxMinusPoint);

	int iSuccessRate = 0;

	if (!gFruiteSuccessType)
	{
		if(AddPoint <= 10)
		{
			iSuccessRate = 100;
		}
		else if((AddPoint - 10) < (MaxAddPoint * (double)0.1))
		{
			iSuccessRate = 90;
		}
		else if((AddPoint - 10) < (MaxAddPoint * (double)0.3))
		{
			iSuccessRate = 80;
		}
		else if((AddPoint - 10) < (MaxAddPoint * (double)0.5))
		{
			iSuccessRate = 70;
		}
		else if((AddPoint - 10) < (MaxAddPoint * (double)0.8))
		{
			iSuccessRate = 60;
		}
		else
		{
			iSuccessRate = 50;
		}
	}
	else
	{
		iSuccessRate = gFruitMaxSuccessRate;
	}



	int iIncStat = 0;

	if(Random(0,99) < iSuccessRate)
	{
		iSuccessRate = Random(0,99);

		int AddStat = 0;

		if(iSuccessRate < 70)
		{
			AddStat = 1;
		}
		else if(iSuccessRate < 95)
		{
			AddStat = 2;
		}
		else
		{
			AddStat = 3;
		}

		if((AddStat + AddPoint) > MaxAddPoint)
		{
			AddStat = 1;
		}

		pResult.result = 0;
		pResult.btStatValue = AddStat;
		pResult.btFruitType = iItemLevel;

		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		iIncStat = AddStat;

		LogAdd("[StatUp] [%s][%s] Success [%d][%d] %d",
			lpObj->AccountID,lpObj->Name,iItemLevel,iIncStat,iItemSerial);
	}
	else
	{
		pResult.result = 1;
		pResult.btStatValue = 0;
		pResult.btFruitType = iItemLevel;

		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);

		LogAdd("[StatUp] [%s][%s] Fail [%d] %d",
			lpObj->AccountID,lpObj->Name,iItemLevel,iItemSerial);
		return;
	}

	switch(iItemLevel)
	{
	case 4: 
		lpObj->Leadership += iIncStat;	
		break;
	case 3: 
		lpObj->Strength += iIncStat;	
		break;
	case 2: 
		lpObj->Dexterity += iIncStat;	
		break;
	case 1:
		lpObj->Vitality += iIncStat;
		lpObj->MaxLife += lpObj->VitalityToLife * iIncStat;
		break;
	case 0:
		lpObj->Energy += iIncStat;
		lpObj->MaxMana += lpObj->EnergyToMana * iIncStat;
		gObjSetBP(aIndex);
		break;

	default : 
		break;
	}

	gObjCalCharacter(aIndex);
	GCReFillSend(aIndex,WORD(lpObj->MaxLife + lpObj->AddLife),0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);
	gObjSetBP(aIndex);
	GCManaSend(aIndex,short(lpObj->MaxMana + lpObj->AddMana),0xFE,0,lpObj->MaxBP + lpObj->AddBP);
}


//------------------------------------------------------------


void gObjUseMinusStatFruit(int aIndex, int pos)//������������ ������ ��� ���������� �����
{
	//�������� �������� �� ��������� ������
	if(!OBJMAX_RANGE(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Connected != PLAYER_PLAYING)
		return;

	int iItemLevel = lpObj->pInventory[pos].m_Level;
	int iItemSerial = lpObj->pInventory[pos].m_Number;
	int iCharacterClass = lpObj->Class;

	PMSG_USE_STAT_FRUIT pResult;

	PHeadSetB((LPBYTE)&pResult,0x2C,sizeof(pResult));

	pResult.result = 5;
	pResult.btFruitType = iItemLevel;
	pResult.btStatValue = 0;

	if(lpObj->Level < FruitMinusMinUseLevel || iItemLevel > 4)//�������� �� ���������� ����� ����������� ��� �� "�������" ������ ������
	{
		pResult.result = 5;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}

	if(iItemLevel == 4 && lpObj->Class != 4)//���� ����� �� ������� ��� ����� ��������� �� ��
	{
		pResult.result = 5;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}

	/*for(int iItemIndex = 0; iItemIndex < INVETORY_WEAR_SIZE; iItemIndex++)//����... ������ ���� ������ �� ��������, � ���� � ������ �� �� ���� �����
	{
		if(lpObj->pInventory[iItemIndex].IsItem())
		{
			pResult.result = 16;
			DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
			return;
		}
	}*/

	if(gObjCheckStatPointDown(aIndex) == false)
	{
		pResult.result = 33;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}

	int iDefaultStat = 0;
	int iPresentStat = 0;

	switch (iItemLevel)
	{
	case 0:
		{
			iDefaultStat = DCInfo.DefClass[iCharacterClass].Energy;
			iPresentStat = lpObj->Energy;
		}
		break;
		
	case 1:
		{
			iDefaultStat = DCInfo.DefClass[iCharacterClass].Vitality;
			iPresentStat = lpObj->Vitality;
		}
		break;

	case 2:
		{
			iDefaultStat = DCInfo.DefClass[iCharacterClass].Dexterity;
			iPresentStat = lpObj->Dexterity;
		}
		break;

	case 3:
		{
			iDefaultStat = DCInfo.DefClass[iCharacterClass].Strength;
			iPresentStat = lpObj->Strength;
		}
		break;

	case 4:
		{
			iDefaultStat = DCInfo.DefClass[iCharacterClass].Leadership;
			iPresentStat = lpObj->Leadership;
		}
		break;

	default:
		break;
	}

	if(iPresentStat <= iDefaultStat)
	{
		pResult.result = 38;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}

	short AddPoint;
	short MaxAddPoint;
	short MinusPoint;
	short MaxMinusPoint = 0;

	gObjGetStatPointState(aIndex,(short &)AddPoint,(short &)MaxAddPoint,(short &)MinusPoint,(short &)MaxMinusPoint);

	if(MinusPoint >= MaxMinusPoint || MinusPoint < 0)
	{
		pResult.result = 37;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		return;
	}

	LogAdd("[StatDown] [%s][%s] Use StatDownItem Level:%d Pos:%d serial:%d",
		lpObj->AccountID,lpObj->Name,iItemLevel,pos,iItemSerial);

	gObjInventoryItemSet(aIndex,pos,0xFF);
	lpObj->pInventory[pos].Clear();
	GCInventoryItemDeleteSend(aIndex,pos,1);

	int iDecStat = 0;
	int bSuccess = 0;
	int iSuccessRate = 0;

	if (!gFruiteSuccessType)
		iSuccessRate = 100 - lpObj->Level / 6;
	else
		iSuccessRate = gFruitMaxSuccessRate;

	if(iSuccessRate < 0)
	{
		iSuccessRate = 0;
	}

	if(Random(0,99) < iSuccessRate)
	{
		bSuccess = 1;
	}

	if(MinusPoint <= 10)
	{
		bSuccess = 1;
	}

	if(bSuccess)
	{
		iSuccessRate = Random(0,99);

		if(iSuccessRate < 50)
		{
			iDecStat = 1;
		}
		else if(iSuccessRate < 75)
		{
			iDecStat = 3;
		}
		else if(iSuccessRate < 91)
		{
			iDecStat = 5;
		}
		else if(iSuccessRate < 98)
		{
			iDecStat = 7;
		}
		else
		{
			iDecStat = 9;
		}

		if((MinusPoint + iDecStat) >= MaxMinusPoint)
		{
			iDecStat = MaxMinusPoint - MinusPoint;
		}

		if((iPresentStat - iDecStat) < iDefaultStat)
		{
			iDecStat = iPresentStat - iDefaultStat;
		}

		pResult.result = 3;
		pResult.btFruitType = iItemLevel;
		pResult.btStatValue = iDecStat;

		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		LogAdd("[StatDown] [%s][%s] Success [%d][%d] %d",
			lpObj->AccountID,lpObj->Name,iItemLevel,iDecStat,iItemSerial);
	}
	else
	{
		pResult.result = 4;
		pResult.btFruitType = iItemLevel;
		pResult.btStatValue = 0;
		DataSend(aIndex,(unsigned char *)&pResult,pResult.h.size);
		LogAdd("[StatDown] [%s][%s] Fail [%d] %d",
			lpObj->AccountID,lpObj->Name,iItemLevel,iItemSerial);
		return;
	}

	switch(iItemLevel)
	{
	case 4:	
		lpObj->Leadership -= iDecStat;	
		break;
	case 3: 
		lpObj->Strength -= iDecStat;	
		break;
	case 2: 
		lpObj->Dexterity -= iDecStat;	
		break;
	case 1:

		lpObj->Vitality -= iDecStat;
		lpObj->MaxLife -= lpObj->VitalityToLife *iDecStat;
		break;

	case 0:
		lpObj->Energy -= iDecStat;
		lpObj->MaxMana -= lpObj->EnergyToMana * iDecStat;
		gObjSetBP(aIndex);
		break;

	default:
		break;
	}

	int iOldLevelUpPoint = lpObj->LevelUpPoint;
	lpObj->LevelUpPoint += iDecStat;

	int iOldFruitPoint = lpObj->LevelUpPoint;
	lpObj->iFruitPoint += iDecStat;

	LogAdd("[StatDown] [%s][%s] MinusStat[%d] -> LevelUpPoint Old(%d)/New(%d)  FruitPoint Old(%d)/New(%d)",
		lpObj->AccountID,lpObj->Name,iDecStat,iOldLevelUpPoint,lpObj->LevelUpPoint,iOldFruitPoint,lpObj->iFruitPoint);

	gObjCalCharacter(aIndex);
	GCReFillSend(lpObj->m_Index,WORD(lpObj->MaxLife + lpObj->AddLife),0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);
	gObjSetBP(aIndex);
	GCManaSend(lpObj->m_Index,short(lpObj->MaxMana + lpObj->AddMana),0xFE,0,lpObj->MaxBP);
}


//------------------------------------------------------------


void gObjCalcMaxLifePower(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	switch(lpObj->Class)
	{
	case CLASS_WIZARD:
			lpObj->m_MaxLifePower = lpObj->Level + lpObj->Vitality + 110;
		break;
	case CLASS_KNIGHT:
			lpObj->m_MaxLifePower = lpObj->Level*2 + lpObj->Vitality + 60;
		break;
	case CLASS_ELF:
			lpObj->m_MaxLifePower = lpObj->Level + lpObj->Vitality + 80;
		break;
	case CLASS_MAGUMSA:
	case CLASS_DARKLORD:
			lpObj->m_MaxLifePower = lpObj->Level + lpObj->Vitality + 110;
		break;
	default :
		lpObj->m_MaxLifePower = 0;
		break;
	}
}



//------------------------------------------------------------


void gObjDelayLifeCheck(int aIndex)//�������� ����� ������
{
	LPOBJ lpObj = &gObj[aIndex];

	if(lpObj->m_CheckLifeTime > 0)
	{
		lpObj->m_CheckLifeTime--;

		if(lpObj->m_CheckLifeTime <= 0)
		{
			lpObj->m_CheckLifeTime = 0;

			if(lpObj->Life < 0)
			{
				lpObj->Life = 0;
			}

			if(lpObj->lpAttackObj != 0)
			{
				gObjLifeCheck(lpObj,lpObj->lpAttackObj,0,1,0,0,0,0);//���� ������ ����� ����� ���������� ����� (�� �� ����)
			}
		}
	}
}



//------------------------------------------------------------


BOOL gObjDuelCheck(LPOBJ lpObj)//�������� �� ������ ������� ���������� � ����
{
	BOOL bRetVal = FALSE;

	if ( lpObj->Type == OBJ_USER )
	{
		int iDuelIndex = lpObj->m_iDuelUser;
		if (  OBJMAX_RANGE(iDuelIndex) )
		{
			bRetVal = TRUE;
		}
	}

	return bRetVal;
}



//------------------------------------------------------------


BOOL gObjDuelCheck(LPOBJ lpObj, LPOBJ lpTargetObj)//�������� �� 2 ������ ���������� � ����
{
	BOOL bRetVal = FALSE;

	if ( lpObj->Type == OBJ_USER && lpTargetObj->Type == OBJ_USER)
	{
		if ( lpObj->m_iDuelUser == lpTargetObj->m_Index && lpTargetObj->m_iDuelUser == lpObj->m_Index)
		{
			bRetVal = TRUE;
		}
	}

	return bRetVal;

}


//------------------------------------------------------------


void gObjResetDuel(LPOBJ lpObj)//��������� ��������� ��� ����
{
	int iDuelIndex = lpObj->m_iDuelUser;

	if ( OBJMAX_RANGE(iDuelIndex))
	{
		lpObj->m_iDuelUser = -1; //������������ ���������� ������� �����������
		lpObj->m_iDuelUserReserved = -1;
		lpObj->m_btDuelScore = 0;//����
		lpObj->m_iDuelTickCount = 0;//��� ���������� ��������
		gDarkSpirit[lpObj->m_Index].ReSetTarget(iDuelIndex);//��������� ������
		gDarkSpirit[iDuelIndex].ReSetTarget(lpObj->m_Index);//� � ��� ��������� � ��� ������ "��������"
		gObj[iDuelIndex].m_iDuelUser = -1;
		gObj[iDuelIndex].m_iDuelUserReserved = -1;
		gObj[iDuelIndex].m_iDuelUserRequested = -1;
		gObj[iDuelIndex].m_iDuelTickCount = 0;
	}
}



//------------------------------------------------------------


void gObjSendDuelEnd(LPOBJ lpObj)//����������� ������ �� �������� ����
{
	PMSG_ANS_END_DUEL pMsg;
	if(gObjIsConnected(lpObj->m_Index) == 0)
	{
		return;
	}

	if(lpObj->Type != OBJ_USER)
	{
		return;
	}

	if(lpObj->CloseCount >= 0)
	{
		return;
	}

	lpObj->m_iDuelUser = -1;
	lpObj->m_iDuelUserReserved = -1;
	lpObj->m_iDuelUserRequested = -1;
	lpObj->m_btDuelScore = 0;
	lpObj->m_iDuelTickCount = 0;

	pMsg.h.c = 0xC1;
	pMsg.h.headcode = 0xAB;
	pMsg.h.size = sizeof(pMsg);

	pMsg.NumberH = SET_NUMBERH(lpObj->m_iDuelUser);
	pMsg.NumberL = SET_NUMBERL(lpObj->m_iDuelUser);

	memcpy(pMsg.szName,gObj[lpObj->m_iDuelUser].Name,10);
	DataSend(lpObj->m_Index,(unsigned char *)&pMsg,pMsg.h.size);
}



//------------------------------------------------------------


void gObjCheckAllUserDuelStop()//�������� �� �������� ���� ���� ���� �� ���������� �� ������ 1��
{
	for(int i = OBJ_STARTUSERINDEX; i < OBJMAX; i++)
	{
		if(gObj[i].Connected == PLAYER_PLAYING)
		{
			if(gObj[i].Type == OBJ_USER)
			{
				if(OBJMAX_RANGE(gObj[i].m_iDuelUser))
				{
					if(GetTickCount() - gObj[i].m_iDuelTickCount > 60000) //���� �� ������ 1 �� ����� ������ �� ���� �� ����� �����������
					{
						gObjSendDuelEnd(&gObj[gObj[i].m_iDuelUser]);
						gObjSendDuelEnd(&gObj[i]);
						gObjResetDuel(&gObj[i]);
					}
				}
			}
		}
	}
}



//------------------------------------------------------------

void SkillFrustrum(BYTE bangle, int aIndex)//#error NOT USED!
{
	LPOBJ lpObj = &gObj[aIndex];

	double p[MAX_ARRAY_FRUSTRUM][3];

	p[0][0] = -6;
	p[0][1] = 6;
	p[0][2] = 0;
	p[1][0] = 6;
	p[1][1] = 6;
	p[1][2] = 0;
	p[2][0] = 1;
	p[2][1] = 0;
	p[2][2] = 0;
	p[3][0] = -1;
	p[3][1] = 0;
	p[3][2] = 0;

	double Angle[0x3];

	Angle[0] = 0;
	Angle[1] = 0;
	Angle[2] = bangle * 360 / 255;

	double Matrix[3][MAX_ARRAY_FRUSTRUM];

	AngleMatrix(Angle,Matrix);

	double vFrustrum[MAX_ARRAY_FRUSTRUM][3];

	for(int i = 0; i < MAX_ARRAY_FRUSTRUM; i++)
	{
		VectorRotate((const double *)&p[i],(const double *)&Matrix[0],(double *)&vFrustrum[i]);

		lpObj->fSkillFrustrumX[i] = (int)vFrustrum[i][0] + lpObj->X;
		lpObj->fSkillFrustrumY[i] = (int)vFrustrum[i][1] + lpObj->Y;
	}
}



//------------------------------------------------------------


BOOL SkillTestFrustrum(int x, int y,int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	int j = 3;

	for(int i = 0; i < MAX_ARRAY_FRUSTRUM; j = i,i++)
	{
		if((lpObj->fSkillFrustrumX[i]- x) * (lpObj->fSkillFrustrumY[j]-y) - (lpObj->fSkillFrustrumX[j]-x) * (lpObj->fSkillFrustrumY[i]-y) < 0.0)
		{
			return false;
		}
	}
	return true;
}


//------------------------------------------------------------


BOOL gObjCheckMaxZen(int aIndex, int nAddZen)
{
	if ( !OBJMAX_RANGE(aIndex) )
		return FALSE;

	LPOBJ lpObj = &gObj[aIndex];
	
	unsigned long _Money = lpObj->Money + nAddZen;

	if ( _Money > MAX_ZEN )
	{
		GCServerMsgStringSend("You have exceeded the amount of Zen you can possess.", aIndex, 1);
		return FALSE;
	}

	return TRUE;
}



//------------------------------------------------------------


void MakeRandomSetItem(int aIndex)
{
	int itemnum = gSetItemOption.GenRandomItemNum();

	int SetOption = gSetItemOption.GenSetOption(itemnum);

	int option1rand;
	int option2rand;
	int option3rand;
	int optionc;
	int Option1 = 0;
	int Option2 = 0;
	int Option3 = 0;

	option1rand = 6;
	option2rand = 4;

	option3rand = Random(0,99);
	optionc = Random(0,2);

	if(Random(0,99) < option2rand)
	{
		Option2 = 1;
	}

	switch(optionc)
	{
	case 0: 
		if(option3rand < 4)
		{
			Option3 = 3;
		}
		break;
	case 1:
		if(option3rand < 8)
		{
			Option3 = 2;
		}
		break;
	case 2: 
		if(option3rand < 12)
		{
			Option3 = 1;
		}
		break;
	default: break;
	}

	Option1 = 1;

	ItemSerialCreateSend(aIndex,gObj[aIndex].MapNumber,(BYTE)gObj[aIndex].X,(BYTE)gObj[aIndex].Y,itemnum,0,0,Option1,Option2,Option3,aIndex,0,SetOption);
	LogAdd("[Chaos Castle] [%s][%s] Winner Set Item itemnum:[%d] skill:[%d] luck:[%d] option:[%d] SetOption:[%d]",gObj[aIndex].AccountID,gObj[aIndex].Name,
		itemnum,Option1,Option2,Option3,SetOption);
}



//------------------------------------------------------------


void MakeRewardSetItem(int aIndex, BYTE cDropX, BYTE cDropY, int iRewardType, int iMapnumber)
{
	int itemnum = gSetItemOption.GenRandomItemNum();

	int SetOption = gSetItemOption.GenSetOption(itemnum);

	int option1rand;
	int option2rand;
	int option3rand;
	int optionc;
	int Option1 = 0;
	int Option2 = 0;
	int Option3 = 0;

	option1rand = 6;
	option2rand = 4;

	option3rand = Random(0,99);
	optionc = Random(0,2);

	if(Random(0,99) < option2rand)
	{
		Option2 = 1;
	}

	switch(optionc)
	{
	case 0: 
		if(option3rand < 4)
		{
			Option3 = 3;
		}
		break;
	case 1:
		if(option3rand < 8)
		{
			Option3 = 2;
		}
		break;
	case 2: 
		if(option3rand < 12)
		{
			Option3 = 1;
		}
		break;
	default: break;
	}

	Option1 = 1;

	if(cDropX == 0 && cDropY == 0)
	{
		cDropX = (BYTE)gObj[aIndex].X;
		cDropY = (BYTE)gObj[aIndex].Y;
	}

	ItemSerialCreateSend(aIndex,iMapnumber,cDropX,cDropY,itemnum,0,0,Option1,Option2,Option3,aIndex,0,SetOption);

	if(iRewardType == 1)
	{
		LogAdd("[Reward][KUNDUN] [%s][%s] Set Item itemnum:[%d] skill:[%d] luck:[%d] option:[%d] SetOption:[%d]",
			gObj[aIndex].AccountID,gObj[aIndex].Name,itemnum,Option1,Option2,Option3,SetOption);
	}
	else
	{
		LogAdd("[Reward][Etc] [%s][%s] Set Item itemnum:[%d] skill:[%d] luck:[%d] option:[%d] SetOption:[%d]",
			gObj[aIndex].AccountID,gObj[aIndex].Name,itemnum,Option1,Option2,Option3,SetOption);
	}		
}



//------------------------------------------------------------


void gObjRecall(int aIndex, int mapnumber, int x, int y)
{
	if(gObj[aIndex].MapNumber != mapnumber)
	{
		gObj[aIndex].X = x;
		gObj[aIndex].Y = y;

		gObj[aIndex].TX = x;
		gObj[aIndex].TY = y;	

		gObj[aIndex].MapNumber = mapnumber;

		gObj[aIndex].PathCount = 0;
		gObj[aIndex].Teleport = 0;

		gObjClearViewport(&gObj[aIndex]);
		GCTeleportSend(&gObj[aIndex],-1,mapnumber,(BYTE)gObj[aIndex].X,(BYTE)gObj[aIndex].Y,gObj[aIndex].Dir);

		if(gObj[aIndex].m_Change >= 0)
		{
			gObjViewportListProtocolCreate(&gObj[aIndex]);
		}

		gObj[aIndex].RegenMapNumber = mapnumber;
		gObj[aIndex].RegenMapX = x;
		gObj[aIndex].RegenMapY = y;
		gObj[aIndex].RegenOk = 1;
	}
	else
	{
		PMSG_MAGICATTACK_RESULT pAttack;

		PHeadSetBE((unsigned char *)&pAttack,0x19,sizeof(pAttack));

		pAttack.MagicNumber = 6;
		pAttack.SourceNumberH = SET_NUMBERH(aIndex);
		pAttack.SourceNumberL = SET_NUMBERL(aIndex);
		pAttack.TargetNumberH = SET_NUMBERH(aIndex);
		pAttack.TargetNumberL = SET_NUMBERL(aIndex);

		DataSend(aIndex,(unsigned char *)&pAttack,pAttack.h.size);
		MsgSendV2(&gObj[aIndex],(unsigned char*)&pAttack,pAttack.h.size);
		gObjTeleportMagicUse(aIndex,x,y);
	}
}



//------------------------------------------------------------


void gObjSetExpPetItem(int aIndex, int exp)
{
	LPOBJ lpObj = &gObj[aIndex];

	if(lpObj->Class != 4)	
	{
		return;
	}

	exp *= (int)gDarkSpiritAddExperience;

	if(lpObj->pInventory[8].m_Type == ITEMGET(13,4) && lpObj->pInventory[1].m_Type == ITEMGET(13,5)) //���� ����� ���� � ����� �� ��� �������� � 2 ���� ������ �����
	{
		int addexp = exp / 10;

		if(lpObj->pInventory[1].AddPetItemExp(addexp))
		{
			if(gObjIsItemPut(lpObj,&lpObj->pInventory[1],1) == 0)
			{
				lpObj->pInventory[1].PetItemLevelDown(addexp);
				MsgOutput(aIndex,"Exp is unobtainable because you are unable to command the Raven.");
			}
			else
			{
				LogAdd("[%s][%s][PetItemLevelUp] [%s] Level:[%d]Exp:[%d]AddExp:[%d]",
					lpObj->AccountID,lpObj->Name,lpObj->pInventory[1].GetName(),lpObj->pInventory[1].m_PetItem_Level,lpObj->pInventory[1].m_PetItem_Exp,addexp);
				CDarkSpirit::SendLevelmsg(lpObj->m_Index,1,0,0xFE);
			}
		}

		if(lpObj->pInventory[8].AddPetItemExp(addexp))
		{
			if(gObjIsItemPut(lpObj,&lpObj->pInventory[8],8) == 0)
			{
				lpObj->pInventory[8].PetItemLevelDown(addexp);
				MsgOutput(aIndex,"Exp is unobtainable because you are unable to command the Horse.");
			}
			else
			{
				LogAdd("[%s][%s][PetItemLevelUp] [%s] Level:[%d]Exp:[%d]AddExp:[%d]",
					lpObj->AccountID,lpObj->Name,lpObj->pInventory[8].GetName(),lpObj->pInventory[8].m_PetItem_Level,lpObj->pInventory[8].m_PetItem_Exp,addexp);
				CDarkSpirit::SendLevelmsg(lpObj->m_Index,8,1,0xFE);
			}
		}
	}
	else if(lpObj->pInventory[8].m_Type == ITEMGET(13,4))
	{
		int addexp = exp / 20 ;

		if(lpObj->pInventory[8].AddPetItemExp(addexp))
		{
			if(gObjIsItemPut(lpObj,&lpObj->pInventory[8],8) == 0)
			{
				lpObj->pInventory[8].PetItemLevelDown(addexp);
				MsgOutput(aIndex,"Exp is unobtainable because you are unable to command the Horse.");
			}
			else
			{
				LogAdd("[%s][%s][PetItemLevelUp] [%s] Level:[%d]Exp:[%d]AddExp:[%d]",
					lpObj->AccountID,lpObj->Name,lpObj->pInventory[8].GetName(),lpObj->pInventory[8].m_PetItem_Level,lpObj->pInventory[8].m_PetItem_Exp,addexp);
				CDarkSpirit::SendLevelmsg(lpObj->m_Index,8,1,0xFE);
			}
		}
	}
	else if(lpObj->pInventory[1].m_Type == ITEMGET(13,5))
	{
		int addexp = exp / 20 ;

		if(lpObj->pInventory[1].AddPetItemExp(addexp))
		{
			if(gObjIsItemPut(lpObj,&lpObj->pInventory[1],1) == 0)
			{
				lpObj->pInventory[1].PetItemLevelDown(addexp);
				MsgOutput(aIndex,"Exp is unobtainable because you are unable to command the Raven.");
			}
			else
			{
				LogAdd("[%s][%s][PetItemLevelUp] [%s] Level:[%d]Exp:[%d]AddExp:[%d]",
					lpObj->AccountID,lpObj->Name,lpObj->pInventory[1].GetName(),lpObj->pInventory[1].m_PetItem_Level,lpObj->pInventory[1].m_PetItem_Exp,addexp);
				CDarkSpirit::SendLevelmsg(lpObj->m_Index,1,0,0xFE);
			}
		}
	}
}



//------------------------------------------------------------


BOOL gObjGetRandomItemDropLocation(int iMapNumber, BYTE& cX, BYTE& cY, int iRangeX, int iRangeY, int iLoopCount)
{
	int iUX = cX;
	int iUY = cY;

	if ( iRangeX <= 0 )
	{
		iRangeX = 1;
	}

	if ( iRangeY <= 0 )
	{
		iRangeY = 1;
	}

	if ( iLoopCount <= 0 )
	{
		iLoopCount = 1;
	}

	while ( iLoopCount-- > 0 )
	{
		cX =  Random(0,(iRangeX) ) * ((Random(0,1)==0)?-1:1) + iUX;
		cY =  Random(0,(iRangeY) ) * ((Random(0,1)==0)?-1:1) + iUY;

		BYTE attr = MapC[iMapNumber].GetAttr(cX, cY);

		if ( (attr&4) != 4 && (attr&8) != 8)
		{
			return TRUE;
		}
	}

	return FALSE;
}



//------------------------------------------------------------



BOOL gObjGetRandomFreeLocation(int iMapNumber, BYTE &cX, BYTE & cY, int iRangeX, int iRangeY, int iLoopCount)
{
	int iUX = cX;
	int iUY = cY;

	if ( iRangeX <= 0 )
	{
		iRangeX = 1;
	}

	if ( iRangeY <= 0 )
	{
		iRangeY = 1;
	}

	if ( iLoopCount <= 0 )
	{
		iLoopCount = 1;
	}
	int S,F,C;
	S=ReadTSC();
	while ( iLoopCount-- > 0 )
	{
		cX =  Random(0,(iRangeX) ) * ((Random(0,1)==0)?-1:1) + iUX;
		cY =  Random(0,(iRangeY) ) * ((Random(0,1)==0)?-1:1) + iUY;

		BYTE attr = MapC[iMapNumber].GetAttr(cX, cY);

		if ( attr == 0 )
		{
			F=ReadTSC();
			C=F-S;
			return TRUE;
		}
	}
	F=ReadTSC();
	C=F-S;
	return FALSE;
}



//------------------------------------------------------------



int gObjCheckAttackTypeMagic(int iClass, int iSkill)
{
	if ( iSkill == 0 )
	{
		return 0;
	}

	return MagicDamageC.GetSkillType(iSkill);
}


//------------------------------------------------------------


 

int gObjGetRandomFreeArea(int iMapNumber,unsigned char & cX,unsigned char & cY,int iSX,int iSY,int iDX,int iDY,int iLoopCount)
{
	if(iSX <= 0)
		iSX = 1;

	if(iSY <= 0)
		iSY = 1;

	if(iDX <= 0)
		iDX = 1;

	if(iDY <= 0)
		iDY = 1;

	if(iSX >= 256)
		iSX = 255;

	if(iSY >= 256)
		iSY = 255;

	if(iDX >= 256)
		iDX = 255;

	if(iDY >= 256)
		iDY = 255;

	if(iLoopCount <= 0)
		iLoopCount = 1;

	while(iLoopCount-- > 0)
	{
		cX = Random(iSX,iDX);
		cY = Random(iSY,iDY);

		BYTE btMapAttr = MapC[iMapNumber].GetAttr(cX,cY);

		if(!btMapAttr)
			return TRUE;
	}

	return FALSE;
}



//------------------------------------------------------------


void gObjGetGuildUnionName(LPOBJ lpObj, char* szUnionName, int iUnionNameLen)
{
	szUnionName[0] = 0;
	
	if ( lpObj->lpGuild == NULL )
	{
		return;
	}

	if ( lpObj->lpGuild->iGuildUnion == 0 )
	{
		return;
	}

	TUnionInfo * pUnionInfo = UnionManager.SearchUnion(lpObj->lpGuild->iGuildUnion);

	if ( pUnionInfo != NULL )
	{
		memcpy(szUnionName, pUnionInfo->m_szMasterGuild, iUnionNameLen);
	}
}



//------------------------------------------------------------


BOOL gObjCheckRival(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if (lpObj==NULL || lpTargetObj==NULL)
		return FALSE;

	if(lpTargetObj->Type != OBJ_USER)
	{
		return false;
	}

	if(lpObj->Type != OBJ_USER)
	{
		return false;
	}

	if(lpTargetObj->lpGuild == 0 || lpObj->lpGuild == 0)
	{
		return false;
	}

	if(lpTargetObj->lpGuild->iGuildRival == 0 || lpObj->lpGuild->iGuildRival == 0)
	{
		return false;
	}

	int iUnion = !lpObj->lpGuild->iGuildUnion ? lpObj->lpGuild->Number : lpObj->lpGuild->iGuildUnion;

	if(UnionManager.GetGuildRelationShip(iUnion,lpTargetObj->lpGuild->Number) == 2)
	{
		return true;
	}
	return false;
}



//------------------------------------------------------------


int gObjGetRelationShip(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	if ( lpObj == NULL || lpTargetObj == NULL )
	{
		return false;
	}

	if ( lpObj->lpGuild == NULL || lpTargetObj->lpGuild == NULL )
	{
		return 0;
	}

	int iUnion = (!lpObj->lpGuild->iGuildUnion) ? lpObj->lpGuild->Number : lpObj->lpGuild->iGuildUnion;

	return UnionManager.GetGuildRelationShip(iUnion, lpTargetObj->lpGuild->Number);
}

struct PMSG_UNION_VIEWPORT_NOTIFY_COUNT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x4|*/ struct PWMSG_HEAD h;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char btCount;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x5>

struct PMSG_UNION_VIEWPORT_NOTIFY {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char btNumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char btNumberL;
  /*<thisrel this+0x4>*/ /*|0x4|*/ int iGuildNumber;
  /*<thisrel this+0x8>*/ /*|0x1|*/ unsigned char btGuildRelationShip;
  /*<thisrel this+0x9>*/ /*|0x8|*/ char szUnionName[8];

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x14>

void gObjNotifyUpdateUnionV1(LPOBJ lpObj)
{
	if(lpObj == 0)
	{
		return;
	}

	char cBUFFER_V1[6000];
	int iVp1Count = 0;

	memset(cBUFFER_V1,0x00,sizeof(cBUFFER_V1));

	PMSG_UNION_VIEWPORT_NOTIFY_COUNT * lpMsg = (PMSG_UNION_VIEWPORT_NOTIFY_COUNT *)&cBUFFER_V1;
	PMSG_UNION_VIEWPORT_NOTIFY * lpMsgBody = (PMSG_UNION_VIEWPORT_NOTIFY * )&cBUFFER_V1[sizeof(PMSG_UNION_VIEWPORT_NOTIFY_COUNT)];

	LPOBJ lpTargetObj;

	for(int n = 0; n < MAX_VIEWPORT; n++)
	{
		if(!OBJMAX_RANGE(lpObj->VpPlayer[n].number))
		{
			continue;
		}

		if(lpObj->VpPlayer[n].state == 2 && lpObj->VpPlayer[n].type == OBJ_USER)
		{
			lpTargetObj = &gObj[lpObj->VpPlayer[n].number];

			if(lpTargetObj == 0)
			{
				continue;
			}

			if(lpTargetObj->lpGuild == 0)
			{
				continue;
			}

			gObjGetGuildUnionName(lpTargetObj,lpMsgBody[iVp1Count].szUnionName,sizeof(lpMsgBody[iVp1Count].szUnionName));

			lpMsgBody[iVp1Count].btGuildRelationShip = gObjGetRelationShip(lpObj,lpTargetObj);
			lpMsgBody[iVp1Count].btNumberL = SET_NUMBERL(WORD(lpTargetObj->m_Index));
			lpMsgBody[iVp1Count].btNumberH = SET_NUMBERH(WORD(lpTargetObj->m_Index));
			lpMsgBody[iVp1Count].iGuildNumber = lpTargetObj->lpGuild->Number;
			iVp1Count++;
		}
	}

	if(iVp1Count > 0 && iVp1Count <= MAX_VIEWPORT)
	{
		lpMsg->btCount = iVp1Count;

		PHeadSetW((unsigned char *)lpMsg,0x67,iVp1Count * sizeof(PMSG_UNION_VIEWPORT_NOTIFY) + sizeof(PMSG_UNION_VIEWPORT_NOTIFY_COUNT));

		DataSend(lpObj->m_Index,(unsigned char *)lpMsg,((lpMsg->h.sizeL & 0xFF) & 0xFF | ((lpMsg->h.sizeH & 0xFF) & 0xFF) << 8) & 0xFFFF);
	}
	else
	{
		if(iVp1Count != 0)
		{
			LogAdd("[Union ViewPort] ERROR : iVp1Count is OUT of BOUND: %d",iVp1Count);
		}
	}
}



//------------------------------------------------------------



void gObjNotifyUpdateUnionV2(LPOBJ lpObj)
{
	if(lpObj == 0)
	{
		return;
	}

	if(lpObj->lpGuild == 0)
	{
		return;
	}

	char cBUFFER_V2[100] = {0};

	PMSG_UNION_VIEWPORT_NOTIFY_COUNT * lpMsg2 = (PMSG_UNION_VIEWPORT_NOTIFY_COUNT *)&cBUFFER_V2;
	PMSG_UNION_VIEWPORT_NOTIFY * lpMsgBody2 = (PMSG_UNION_VIEWPORT_NOTIFY *)&cBUFFER_V2[sizeof(PMSG_UNION_VIEWPORT_NOTIFY_COUNT)];

	gObjGetGuildUnionName(lpObj,lpMsgBody2->szUnionName,sizeof(lpMsgBody2->szUnionName));
	lpMsgBody2->btNumberL = SET_NUMBERL(WORD(lpObj->m_Index));
	lpMsgBody2->btNumberH = SET_NUMBERH(WORD(lpObj->m_Index));

	lpMsgBody2->iGuildNumber = lpObj->lpGuild->Number;
	lpMsgBody2->btGuildRelationShip = 0;
	lpMsg2->btCount = 1;

	PHeadSetW((unsigned char *)lpMsg2,0x67,sizeof(lpMsg2) + sizeof(lpMsgBody2[0])+1);

	DataSend(lpObj->m_Index,(unsigned char *)lpMsg2,((lpMsg2->h.sizeL & 0xFF) & 0xFF | ((lpMsg2->h.sizeH & 0xFF) & 0xFF) << 8) & 0xFFFF);

	for(int n = 0; n < MAX_VIEWPORT; n++)
	{
		if(lpObj->VpPlayer2[n].type == OBJ_USER && lpObj->VpPlayer2[n].state != 0)
		{
			LPOBJ lpTargetObj = &gObj[lpObj->VpPlayer2[n].number];

			if(lpTargetObj->lpGuild != 0)
			{
				lpMsgBody2->btGuildRelationShip = gObjGetRelationShip(lpTargetObj,lpObj);
			}

			if(lpMsgBody2->btGuildRelationShip != 1)
			{
				DataSend(lpObj->VpPlayer2[n].number,(unsigned char *)lpMsg2,((lpMsg2->h.sizeL & 0xFF) & 0xFF | ((lpMsg2->h.sizeH & 0xFF) & 0xFF) << 8) & 0xFFFF);
			}
		}
	}
}



//------------------------------------------------------------



void gObjUnionUpdateProc(int iIndex)
{

	if ( gObjIsConnected(iIndex) == FALSE )
	{
		return;
	}

	LPOBJ lpObj = &gObj[iIndex];

	if ( lpObj->Type != OBJ_USER )
	{
		return;
	}

	if ( lpObj->RegenOk > 0 )
	{
		return;
	}

	if ( lpObj->CloseCount > -1 )
		return;

	if ( lpObj->lpGuild == NULL )
	{
		return;
	}

	if ( lpObj->lpGuild->CheckTimeStamp(lpObj->iGuildUnionTimeStamp) != FALSE )
	{
		return;
	}

	lpObj->iGuildUnionTimeStamp = lpObj->lpGuild->GetTimeStamp();
	gObjNotifyUpdateUnionV1(lpObj);
	gObjNotifyUpdateUnionV2(lpObj);

}

// _GUILD_INFO_STRUCT 0x4e0a10


//------------------------------------------------------------

void gObjSetKillCount(int aIndex, int iOption)	// Option : [0 : SetToZero] [1 : Increase] [2 : Decrease]
{
	if ( gObjIsConnected(aIndex) == FALSE )
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if ( iOption== 1 )
	{
		if ( lpObj->m_btKillCount <= 254 )
		{
			lpObj->m_btKillCount++;
		}
	}
	else if ( iOption == 2 )
	{
		if ( lpObj->m_btKillCount > 0 )
		{
			lpObj->m_btKillCount--;
		}
	}
	else if ( iOption == 0 )
	{
		lpObj->m_btKillCount = 0;
	}

	PMSG_KILLCOUNT pMsg = {0};
	PHeadSubSetB((LPBYTE)&pMsg, 0xB8,0x01, sizeof(pMsg));
	pMsg.btKillCount = lpObj->m_btKillCount;
	
	DataSend( aIndex, (UCHAR*)&pMsg, sizeof(pMsg));
}

//------------------------------------------------------------

struct PMSG_NOTIFY_REGION_OF_WEAPON {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x4|*/ struct PBMSG_HEAD2 h;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char btWeaponType;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char btPointX;
  /*<thisrel this+0x6>*/ /*|0x1|*/ unsigned char btPointY;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x7>

struct PMSG_NOTIFY_TARGET_OF_WEAPON {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x4|*/ struct PBMSG_HEAD2 h;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x6>*/ /*|0x1|*/ unsigned char btWeaponType;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x7>

struct PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY_COUNT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x4|*/ struct PWMSG_HEAD h;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char btCount;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x5>

struct PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char btObjType;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char btObjClassH;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char btObjClassL;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char btObjIndexH;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char btObjIndexL;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char btX;
  /*<thisrel this+0x6>*/ /*|0x1|*/ unsigned char btY;
  /*<thisrel this+0x7>*/ /*|0x11|*/ unsigned char CharSet[17];
  /*<thisrel this+0x18>*/ /*|0x4|*/ unsigned long dwViewSkillState;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};
// <size 0x1c>

//------------------------------------------------------------


void gObjNotifyUseWeaponV1(LPOBJ lpOwnerObj, LPOBJ lpWeaponObj, int iTargetX, int iTargetY)
{
	if(lpOwnerObj == 0)
	{
		return;
	}

	if(lpWeaponObj == 0)
	{
		return;
	}

	PMSG_NOTIFY_REGION_OF_WEAPON pNotifyRegionMsg = {0};

	PHeadSubSetB((unsigned char *)&pNotifyRegionMsg,0xB7,2,sizeof(pNotifyRegionMsg));

	pNotifyRegionMsg.btPointX = iTargetX;
	pNotifyRegionMsg.btPointY = iTargetY;

	PMSG_NOTIFY_TARGET_OF_WEAPON pNotifyTargetMsg = {0};

	PHeadSubSetB((unsigned char *)&pNotifyTargetMsg,0xB7,3,sizeof(pNotifyTargetMsg));

	if(lpWeaponObj->Class == 0xDD)
	{
		pNotifyRegionMsg.btWeaponType = 1;
		pNotifyTargetMsg.btWeaponType = 1;
	}
	else if(lpWeaponObj->Class == 0xDE)
	{
		pNotifyRegionMsg.btWeaponType = 2;
		pNotifyTargetMsg.btWeaponType = 2;
	}

	char cBUFFER_V1[6000];
	int iVp1Count = 0;

	memset(cBUFFER_V1,0x00,sizeof(cBUFFER_V1));

	PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY_COUNT * lpMsg = (PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY_COUNT *)&cBUFFER_V1;
	PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY * lpMsgBody = (PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY *)&cBUFFER_V1[sizeof(PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY_COUNT)];

	LPOBJ lpTargetObj;

	for(int n = 0; n < OBJMAX;n++)
	{
		lpTargetObj = &gObj[n];

		if (lpTargetObj->Connected != PLAYER_PLAYING)
			continue;

		if(lpOwnerObj->MapNumber != lpTargetObj->MapNumber)
		{
			continue;
		}

		if(abs(lpTargetObj->X - iTargetX) > 6)
		{
			continue;
		}

		if(abs(lpTargetObj->Y - iTargetY) > 6)
		{
			continue;
		}

		lpMsgBody[iVp1Count].btObjClassH = SET_NUMBERH(lpTargetObj->Class);
		lpMsgBody[iVp1Count].btObjClassL = SET_NUMBERL(lpTargetObj->Class);
		lpMsgBody[iVp1Count].btObjIndexH = SET_NUMBERH(lpTargetObj->m_Index);
		lpMsgBody[iVp1Count].btObjIndexL = SET_NUMBERL(lpTargetObj->m_Index);
		lpMsgBody[iVp1Count].btX = (BYTE)lpTargetObj->X;
		lpMsgBody[iVp1Count].btY = (BYTE)lpTargetObj->Y;
		lpMsgBody[iVp1Count].dwViewSkillState = lpTargetObj->m_ViewSkillState;

		if(lpTargetObj->Type == OBJ_USER)
		{
			lpMsgBody[iVp1Count].btObjType = OBJ_USER;
			lpMsgBody[iVp1Count].btObjClassH = CS_SET_CLASS(lpTargetObj->Class);
			lpMsgBody[iVp1Count].btObjClassL = 0;

			memcpy(lpMsgBody[iVp1Count].CharSet,&lpTargetObj->CharSet[1],sizeof(lpMsgBody[iVp1Count].CharSet));

			DataSend(lpTargetObj->m_Index,(unsigned char *)&pNotifyRegionMsg,sizeof(pNotifyRegionMsg));

			if(abs(lpTargetObj->X - iTargetX) > 3)
			{
				continue;
			}

			if(abs(lpTargetObj->Y - iTargetY) > 3)
			{
				continue;
			}

			pNotifyTargetMsg.NumberH = SET_NUMBERH(lpTargetObj->m_Index);
			pNotifyTargetMsg.NumberL = SET_NUMBERL(lpTargetObj->m_Index);

		}
		else if(lpTargetObj->Type == OBJ_MONSTER)
		{
			lpMsgBody[iVp1Count].btObjType = OBJ_MONSTER;
			memset(lpMsgBody[iVp1Count].CharSet,0x00,sizeof(lpMsgBody[iVp1Count].CharSet));
		}
		else
		{
			lpMsgBody[iVp1Count].btObjType = OBJ_NPC;
			memset(lpMsgBody[iVp1Count].CharSet,0x00,sizeof(lpMsgBody[iVp1Count].CharSet));
		}

		iVp1Count++;

	}

	if(iVp1Count > 0 && iVp1Count <= 100)
	{
		lpMsg->btCount = iVp1Count;
		PHeadSetW((unsigned char *)lpMsg,0x68,iVp1Count * sizeof(PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY) + sizeof(PMSG_WEAPON_OWNER_VIEWPORT_NOTIFY_COUNT));

		DataSend(lpOwnerObj->m_Index,(unsigned char *)lpMsg,((lpMsg->h.sizeL & 0xFF) & 0xFF | ((lpMsg->h.sizeH & 0xFF) & 0xFF) << 8) & 0xFFFF);
	}
}



//------------------------------------------------------------



void gObjNotifyUseWeaponDamage(LPOBJ lpWeaponObj, int iTargetX, int iTargetY)
{
	if ( lpWeaponObj->Class == 221 || lpWeaponObj->Class == 222)
	{
		LPOBJ lpObj;

		for ( int i=0;i<OBJMAX;i++)
		{
			lpObj = &gObj[i];

			if ( lpWeaponObj->MapNumber != lpObj->MapNumber )
			{
				continue;
			}

			if ( abs(lpObj->X - iTargetX) > 3 )
			{
				continue;
			}

			if ( abs(lpObj->Y - iTargetY) > 3 )
			{
				continue;
			}

			g_CsNPC_Weapon.AddWeaponDamagedTargetInfo(lpWeaponObj->m_Index, i, 100);
		}
	}

}



//------------------------------------------------------------


void gObjUseBlessAndSoulPotion(int aIndex, int iItemLevel)
{
	if (!UserRange(aIndex))
		return;

	LPOBJ lpObj = &gObj[aIndex];

	switch (iItemLevel)
	{
	case 0:// Bless Potion
		lpObj->m_iPotionBlessTime = gBlessPotionTime;
		lpObj->m_ViewSkillState |= 0x8000;
		GCStateInfoSend(lpObj, 1, 0x8000);
		break;
	case 1:// Soul Potion
		lpObj->m_iPotionSoulTime = gSoulPotionTime;
		lpObj->m_ViewSkillState |= 0x10000;
		GCStateInfoSend(lpObj,  1, 0x10000);
		gObjUseDrink(lpObj, 0x4D);
		break;
	default:
		break;
	}
}

//------------------------------------------------------------


void gObjWeaponDurDownInCastle(LPOBJ lpObj, LPOBJ lpTargetObj, int iDecValue)
{
	if(lpObj->Type == OBJ_MONSTER || lpObj->Type == OBJ_NPC)
	{
		return;

	}

	CItem * Right = &lpObj->pInventory[0];
	CItem * Left = &lpObj->pInventory[1];

	bool bIsRightDurDown = false;
	bool bIsLeftDurDown = false;


	switch (lpObj->Class)
	{
	case 1:
	case 3:
	case 4:
		if(Right->m_Type >= ITEMGET(0,0) && Right->m_Type < ITEMGET(4,0) //�� ������ �� �����
			&& Left->m_Type >= ITEMGET(0,0) && Left->m_Type < ITEMGET(4,0))
		{
			bIsRightDurDown = true;
			bIsLeftDurDown = true;
		}
	default:
		break;
	}


	if(Left->m_Type >= ITEMGET(4,0) && Left->m_Type < ITEMGET(4,7)//��� ����
		|| Left->m_Type == ITEMGET(4,17)
		|| Left->m_Type == ITEMGET(4,20)
		|| Left->m_Type == ITEMGET(4,21)
		|| Left->m_Type == ITEMGET(4,22))
	{
		bIsLeftDurDown = true;
	}
	else if(Right->m_Type >= 0 && Right->m_Type < ITEMGET(6,0))//������ ����� ������ � ������ ����
	{
		bIsRightDurDown = true;
	}


	if(bIsRightDurDown)
	{
		int iRet = Right->SimpleDurabilityDown(iDecValue);

		if(iRet != 0)
		{
			GCItemDurSend(lpObj->m_Index,0,(BYTE)Right->m_Durability,0);

			if(iRet == 2)
			{
				gObjCalCharacter(lpObj->m_Index);
			}
		}
	}

	if(bIsLeftDurDown)
	{
		int iRet = Left->SimpleDurabilityDown(iDecValue); 

		if(iRet != 0)
		{
			GCItemDurSend(lpObj->m_Index,1,(BYTE)Left->m_Durability,0);

			if(iRet == 2)
			{
				gObjCalCharacter(lpObj->m_Index);
			}
		}
	}
}


//------------------------------------------------------------

void gObjReady4Relife(LPOBJ lpObj)
{
	gObjCalCharacter(lpObj->m_Index);
	GCReFillSend(lpObj->m_Index,WORD(lpObj->MaxLife + lpObj->AddLife),0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);
}

//------------------------------------------------------------

void gObjCheckTimeOutValue(LPOBJ lpObj, DWORD& rNowTick)
{
	long lTick;
	long lSecond;

	lTick = rNowTick - lpObj->m_dwLastCheckTick;
	lSecond = lTick / 1000;

	if(lSecond == 0)
	{
		return;
	}

	lpObj->m_dwLastCheckTick = rNowTick;
}


//------------------------------------------------------------

void MsgOutput(int aIndex, char* msg, ...) 
{
	char szBuffer[512]={0};
	va_list pArguments;

	va_start(pArguments, msg );
	vsprintf_s(szBuffer, msg, pArguments);
	va_end(pArguments);
	
	GCServerMsgStringSend(&szBuffer[0], aIndex, 1);
}


//------------------------------------------------------------

void gProcessAutoRecuperation(LPOBJ lpObj)
{
	if(lpObj->Life == (lpObj->MaxLife + lpObj->AddLife) &&
		lpObj->Mana == (lpObj->MaxMana + lpObj->AddMana) &&
		lpObj->BP == (lpObj->MaxBP + lpObj->AddBP) )
	{
		lpObj->m_iAutoRecuperationTime = GetTickCount();
		return;
	}

	if(( GetTickCount() - lpObj->m_iAutoRecuperationTime ) >= 10000 && ( GetTickCount() - lpObj->m_iAutoRecuperationTime ) < 15000)
	{
		if(lpObj->Life < ( lpObj->MaxLife + lpObj->AddLife ) )
		{
			lpObj->Life += 1.0;

			if(lpObj->Life > (lpObj->MaxLife + lpObj->AddLife))
			{
				lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
			}

			GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,0xFF,0,lpObj->iShield);
		}

		if(lpObj->Mana < ( lpObj->MaxMana + lpObj->AddMana ) || lpObj->BP < ( lpObj->MaxBP + lpObj->AddBP) )
		{
			lpObj->Mana += 1.0;

			if(lpObj->Mana > (lpObj->MaxMana + lpObj->AddMana))
			{
				lpObj->Mana = lpObj->MaxMana + lpObj->AddMana;
			}

			lpObj->BP += 1;

			if(lpObj->BP > (lpObj->MaxBP + lpObj->AddBP))
			{
				lpObj->BP = lpObj->MaxBP + lpObj->AddBP;
			}

			GCManaSend(lpObj->m_Index,short(lpObj->Mana),0xFF,0,lpObj->BP);
		}
	}
	else if(( GetTickCount() - lpObj->m_iAutoRecuperationTime ) >= 15000 && ( GetTickCount() - lpObj->m_iAutoRecuperationTime ) < 25000)
	{
		if(lpObj->Life < ( lpObj->MaxLife + lpObj->AddLife ) )
		{
			lpObj->Life += 5.0;

			if(lpObj->Life > (lpObj->MaxLife + lpObj->AddLife))
			{
				lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
			}

			GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,0xFF,0,lpObj->iShield);
		}

		if(lpObj->Mana < ( lpObj->MaxMana + lpObj->AddMana ) || lpObj->BP < ( lpObj->MaxBP + lpObj->AddBP) )
		{
			lpObj->Mana += 5.0;

			if(lpObj->Mana > (lpObj->MaxMana + lpObj->AddMana))
			{
				lpObj->Mana = lpObj->MaxMana + lpObj->AddMana;
			}

			lpObj->BP += 5;

			if(lpObj->BP > (lpObj->MaxBP + lpObj->AddBP))
			{
				lpObj->BP = lpObj->MaxBP + lpObj->AddBP;
			}

			GCManaSend(lpObj->m_Index,(short)lpObj->Mana,0xFF,0,lpObj->BP);
		}
	}
	else if(( GetTickCount() - lpObj->m_iAutoRecuperationTime ) >= 25000)
	{
		if(lpObj->Life < ( lpObj->MaxLife + lpObj->AddLife ) )
		{
			lpObj->Life += 10.0;

			if(lpObj->Life > (lpObj->MaxLife + lpObj->AddLife))
			{
				lpObj->Life = lpObj->MaxLife + lpObj->AddLife;
			}

			GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,0xFF,0,lpObj->iShield);
		}

		if(lpObj->Mana < ( lpObj->MaxMana + lpObj->AddMana ) || lpObj->BP < ( lpObj->MaxBP + lpObj->AddBP) )
		{
			lpObj->Mana += 10.0;

			if(lpObj->Mana > (lpObj->MaxMana + lpObj->AddMana))
			{
				lpObj->Mana = lpObj->MaxMana + lpObj->AddMana;
			}

			lpObj->BP += 10;

			if(lpObj->BP > (lpObj->MaxBP + lpObj->AddBP))
			{
				lpObj->BP = lpObj->MaxBP + lpObj->AddBP;
			}

			GCManaSend(lpObj->m_Index,(short)lpObj->Mana,0xFF,0,lpObj->BP);
		}
	}
}

//------------------------------------------------------------

void gObjShieldAutoRefill(LPOBJ lpObj)
{
	int iRefillPoint = 0;
	int iShieldRefillOption = 0;

	if(g_ShieldSystemOn == 0)
	{
		return;
	}

	if(g_ShieldAutoRefillOn == 0)
	{
		return;
	}

	if(g_ShieldAutoRefillOnSafeZone == 1)
	{
		unsigned char btMapAttribute = MapC[lpObj->MapNumber].GetAttr(lpObj->X,lpObj->Y);

		if((btMapAttribute & 1) != 1 && lpObj->m_ItemOptionExFor380.OpRefillOn == 0)
		{
			lpObj->dwShieldAutoRefillTimer = GetTickCount();
			return;
		}
	}

	if(lpObj->iShield >= (lpObj->iMaxShield + lpObj->iAddShield))
	{
		lpObj->dwShieldAutoRefillTimer = GetTickCount();
		return;
	}

	iShieldRefillOption = lpObj->m_ItemOptionExFor380.OpAddRefillSD;

	int iRefillExpression = 0;

	double fRefillExpressionA = (lpObj->iMaxShield + lpObj->iAddShield) / 30;
	double fRefillExpressionB = iShieldRefillOption + 100;

	iRefillExpression = int(((fRefillExpressionA * fRefillExpressionB) / 100.0) / 25.0);

	unsigned long dwTick = GetTickCount() - lpObj->dwShieldAutoRefillTimer;

	if(dwTick >= 25000)
	{
		iRefillPoint = iRefillExpression * 3; 
	}
	else if(dwTick >= 15000)
	{
		iRefillPoint = (iRefillExpression * 25) / 10;
	}
	else if(dwTick >= 10000)
	{
		iRefillPoint = iRefillExpression * 2;
	}
	else
	{
		return;
	}

	iRefillExpression++;

	if(iRefillPoint == 0)
	{
		return;
	}

	lpObj->iShield += iRefillPoint;

	if(lpObj->iShield > (lpObj->iMaxShield + lpObj->iAddShield))
	{
		lpObj->iShield = lpObj->iMaxShield + lpObj->iAddShield;
	}

	GCReFillSend(lpObj->m_Index,(WORD)lpObj->Life,0xFF,0,lpObj->iShield);
}

//------------------------------------------------------------

int gObjCheckOverlapItemUsingDur(int iUserIndex, int iMaxOverlapped, int iItemType, int iItemLevel)
{
	if (!UserRange(iUserIndex))
		return -1;

	LPOBJ lpObj=&gObj[iUserIndex];

	if (lpObj->Type!=OBJ_USER)
		return -1;

	for(int x = INVETORY_WEAR_SIZE; x < MAIN_INVENTORY_SIZE; x++)
	{
		if(lpObj->pInventory[x].IsItem() == 1
			&& lpObj->pInventory[x].m_Type == (short)iItemType
			&& lpObj->pInventory[x].m_Level == (short)iItemLevel)
		{
			int iITEM_DUR = (int)lpObj->pInventory[x].m_Durability;

			if( iITEM_DUR<0?FALSE:iITEM_DUR>iMaxOverlapped-1?FALSE:TRUE )
			{
				return x;
			}
		}
	}

	return -1;

}

//------------------------------------------------------------

int gObjOverlapItemUsingDur(class CItem* lpItem, int iMapNumber, int iItemNumber, int iUserIndex, int iMaxOverlapped, int iItemType, int iItemLevel)
{
	if (!UserRange(iUserIndex))
		return -1;

	int iInventoryIndex,iItemDur;

	LPOBJ lpObj=&gObj[iUserIndex];

	for(int iLoop = 0; iLoop < MAIN_INVENTORY_SIZE; iLoop ++)
	{
		iInventoryIndex = gObjCheckOverlapItemUsingDur(iUserIndex,iMaxOverlapped,iItemType,iItemLevel);

		if(MAIN_INVENTORY_RANGE(iInventoryIndex))
		{
			iItemDur = int(lpObj->pInventory[iInventoryIndex].m_Durability + lpItem->m_Durability);

			if(iItemDur <= iMaxOverlapped)
			{
				if(MapC[iMapNumber].ItemGive(iUserIndex,iItemNumber,1) == 1)
				{
					return iInventoryIndex;
				}
			}
			else
			{
				lpItem->m_Durability = iItemDur - iMaxOverlapped;
				lpObj->pInventory[iInventoryIndex].m_Durability = iMaxOverlapped;

				GCItemDurSend(iUserIndex,iInventoryIndex,(BYTE)lpObj->pInventory[iInventoryIndex].m_Durability,0);
			}
		}
		else
		{
			return -1;
		}
	}
	return -1;
}

//------------------------------------------------------------

bool gObjCheckSerial0ItemList(class CItem* lpItem)
{
	if(gItemSerialCheck == 0)
	{
		return false;
	}

	if(lpItem->m_Type == ITEMGET(14,13)
		|| lpItem->m_Type == ITEMGET(14,14)
		|| lpItem->m_Type == ITEMGET(14,16)
		|| lpItem->m_Type == ITEMGET(14,22)
		|| lpItem->m_Type == ITEMGET(12,15)
		|| lpItem->m_Type == ITEMGET(12,30)
		|| lpItem->m_Type == ITEMGET(12,31)
		|| lpItem->m_Type == ITEMGET(14,31))
	{
		if(lpItem->GetNumber() == 0 )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------

bool gObjCheckInventorySerial0Item(LPOBJ lpObj)
{
	if(gItemSerialCheck == 0)
	{
		return true;
	}

	int iCount = 0;
	int iItemSerial=0;

	for(int i = 0; i < INVENTORY_SIZE; i++)
	{
		if(lpObj->pInventory[i].IsItem() == 0)
		{
			continue;
		}

		if(gObjCheckSerial0ItemList(&lpObj->pInventory[i]) == 0 )
		{
			continue;
		}

		iItemSerial = lpObj->pInventory[i].GetNumber();

		if(iItemSerial == 0)
		{
			LogAdd("[ANTI-HACK][Serial 0 Item] (%s)(%s) Item(%s) Pos(%d)",
				lpObj->AccountID,lpObj->Name,lpObj->pInventory[i].GetName(),i);
			iCount++;
		}
	}


	if(iCount > 0)
	{
		return true;
	}
	else
		return false;
}


//------------------------------------------------------------


BOOL gCheckSkillDistance(int aIndex, int aTargetIndex, int iSkillNum)
{
	if (!ObjectRange(aIndex) || !ObjectRange(aTargetIndex))
	{
		LogAdd("[SKILL DISTANCE CHECK]  Invalid Character index:  attacker(%d), target(%d), skillnum:%d ",
			aIndex,
			aTargetIndex,
			iSkillNum); 
		return FALSE;
	}

	if ( !g_iSkillDistanceCheck  )
		return TRUE;

	if ( iSkillNum == 40 )//??
		return TRUE;

	int iSkillDistance = MagicDamageC.GetSkillDistance(iSkillNum);

	if ( iSkillDistance == -1 )
		return FALSE;

	iSkillDistance += g_iSkillDistanceCheckTemp;
	LPOBJ lpObj = &gObj[aIndex];
	LPOBJ lpTargetObj = &gObj[aTargetIndex];

	if ( abs(lpObj->X - lpTargetObj->X) > iSkillDistance ||
		 abs(lpObj->Y - lpTargetObj->Y) > iSkillDistance )
	{
		LogAdd("[SKILL DISTANCE CHECK] [%s][%s] Invalid Skill attacker(%d, %d), defender(%d, %d), skillnum:%d skilldistance:%d",
			lpObj->AccountID, lpObj->Name,
			lpObj->X, lpObj->Y, 
			lpTargetObj->X, lpTargetObj->Y,
			iSkillNum, iSkillDistance);

		return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------

void gObjSaveChaosBoxItemList(LPOBJ lpObj)
{
	unsigned char ExOption[8];
	for(int n = 0; n < CHAOS_BOX_SIZE;n++)
	{
		if(lpObj->pChaosBox[n].IsItem() == 1)
		{
			ItemIsBufExOption(ExOption,&lpObj->pChaosBox[n]);

			LogAdd("[ChaosBoxItemList][Lost ItemList] [%s][%s] [%d,%s,%d,%d,%d,%d] Serial:[%d][%d] Ex:[%d,%d,%d,%d,%d,%d,%d] Set:[%d] 380:[%d] HO:[%d,%d]",
				lpObj->AccountID,lpObj->Name,n,lpObj->pChaosBox[n].GetName(),lpObj->pChaosBox[n].m_Level,lpObj->pChaosBox[n].m_Option1,lpObj->pChaosBox[n].m_Option2,lpObj->pChaosBox[n].m_Option3,lpObj->pChaosBox[n].m_Number,
				(int)lpObj->pChaosBox[n].m_Durability,ExOption[0],ExOption[1],ExOption[2],ExOption[3],ExOption[4],ExOption[5],ExOption[6],lpObj->pChaosBox[n].m_SetOption,
				lpObj->pChaosBox[n].m_ItemOptionEx >> 7,g_kJewelOfHarmonySystem.GetItemStrengthenOption(&lpObj->pChaosBox[n]),g_kJewelOfHarmonySystem.GetItemOptionLevel(&lpObj->pChaosBox[n]));
		}
	}
}

//------------------------------------------------------------

void Print(int aIndex,int Type, char* Text)
{
	std::vector<std::string> text;
	std::string txt=Text;
	std::string tmp;
	int i=0;
	int found=0;

	if (!UserRange(aIndex))
		return;

	char buf[15]={0};

	while (1)
	{
		found=txt.find("(n)");
		if (found!=std::string::npos)
		{
			tmp.append(txt,0,found);
			text.push_back(tmp);
			tmp="";
			txt.erase(0,found+3);
			continue;
		}
		else
		{
			if (!txt.empty())
				text.push_back(txt);

			break;
		}

	}


	for ( i=0; i < (int)text.size(); i++)
	{
		while (1)
		{
			found=text[i].find("(Nick)");
			if (found!=std::string::npos)
			{
				text[i].replace(found,strlen("(Nick)"),gObj[aIndex].Name);
			}
			else
				break;
		}

		while (1)
		{
			found=text[i].find("(Strong)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Strength,buf,10);
				text[i].replace(found,strlen("(Strong)"),buf);
			}
			else
				break;
		}

		
		while (1)
		{
			found=text[i].find("(Agility)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Dexterity,buf,10);
				text[i].replace(found,strlen("(Agility)"),buf);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(Vitality)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Vitality,buf,10);
				text[i].replace(found,strlen("(Vitality)"),buf);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(Energy)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Energy,buf,10);
				text[i].replace(found,strlen("(Energy)"),buf);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(Command)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Leadership,buf,10);
				text[i].replace(found,strlen("(Command)"),buf);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(Account)");
			if (found!=std::string::npos)
			{
				text[i].replace(found,strlen("(Account)"),gObj[aIndex].AccountID);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(GuildName)");
			if (found!=std::string::npos)
			{
				text[i].replace(found,strlen("(GuildName)"),gObj[aIndex].GuildName);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(Level)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Level,buf,10);
				text[i].replace(found,strlen("(Level)"),buf);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(Money)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Money,buf,10);
				text[i].replace(found,strlen("(Money)"),buf);
			}
			else
				break;
		}


		while (1)
		{
			found=text[i].find("(Resets)");
			if (found!=std::string::npos)
			{
				_itoa_s(gObj[aIndex].Resets,buf,10);
				text[i].replace(found,strlen("(Resets)"),buf);
			}
			else
				break;
		}

		while (1)
		{
			found=text[i].find("(UsersOnline)");
			if (found!=std::string::npos)
			{
				_itoa_s(TotalOnline,buf,10);
				text[i].replace(found,strlen("(UsersOnline)"),buf);
			}
			else
				break;
		}

		while (1)
		{
			found=text[i].find("(GMOnline)");
			if (found!=std::string::npos)
			{
				_itoa_s(TotalGMOnline,buf,10);
				text[i].replace(found,strlen("(GMOnline)"),buf);
			}
			else
				break;
		}

		while (1)
		{
			found=text[i].find("(GMOnlineList)");
			if (found!=std::string::npos)
			{
				std::string List;
				for (std::list<std::string>::iterator iter=GMOnline.begin(); iter!=GMOnline.end(); iter++)
				{
					List+=*iter;
					if (iter==--GMOnline.end())
						List+=" .";
					else
						List+=" ,";
				}
				text[i].replace(found,strlen("(GMOnlineList)"),List.c_str());
			}
			else
				break;
		}
		
	}

	for ( i=0; i < (int)text.size(); i++)
	{
		GCServerMsgStringSend((char*)text[i].c_str(), aIndex, Type);
	}

	

}

//------------------------------------------------------------

void PrintAll(int Type, char* Text)
{
	for (int i=OBJ_STARTUSERINDEX;i<OBJMAX;i++)
	{
		if (gObj[i].Connected==PLAYER_PLAYING)
			Print(i,Type,Text);
	}
}

//------------------------------------------------------------

void GlobalMsg(int aIndex,std::string Message)
{
	PMSG_CHATDATA_WHISPER pWhisper;
	int len;

	if (!UserRange(aIndex))
		return;

	LPOBJ lpObj = &gObj[aIndex];

	if ( PacketCheckTime(lpObj) == FALSE )
	{
		return;
	}

	if ( lpObj->ChatLimitTime > 0 )
	{
		MsgOutput(lpObj->m_Index, "Chat Block: %d minute(s) remaining.", lpObj->ChatLimitTime);
		return;
	}

	if ( (lpObj->Penalty & 2) == 2 )
	{
		return;
	}

	PHeadSetB((LPBYTE)&pWhisper, 0x02, sizeof(pWhisper));
	memcpy(pWhisper.id,gObj[aIndex].Name,sizeof(pWhisper.id));
	//strcpy_s(pWhisper.id, sizeof(pWhisper.id), gObj[aIndex].Name);
	strcpy_s(pWhisper.chatmsg, sizeof(pWhisper.chatmsg),Message.c_str());
	len = strlen(pWhisper.chatmsg);

	if ( len > 0 )
	{
		pWhisper.h.size -= sizeof(pWhisper.chatmsg);
		pWhisper.h.size += len + 1;

		for ( int n = OBJ_STARTUSERINDEX ; n < OBJMAX ; n++)
		{
			if ( gObj[n].Connected == PLAYER_PLAYING )
			{
				DataSend(n, (UCHAR*)&pWhisper , pWhisper.h.size );
			}
		}
	}

}

//---------------------------------------------------------------------------

void Refresh(std::string &TableName, std::string &TableTime,char* Name)
{
	char BD[128]={0};
	char BD2[128]={0};

	SYSTEMTIME m_time;//���������� ���
	SYSTEMTIME t;//�� ���� ����� ��� �������� ����
	std::vector<int> i_time;//����� ��� ���������� ����
	int element=0;//���� ������� ��������� ������� (����� ���������� ���)
	std::vector<char*> name;
	std::vector<char*> time;
	std::vector<std::string> T_Time;
	std::vector<std::string> T_Name;

	strcpy_s(BD, sizeof(BD),TableName.c_str());
	strcpy_s(BD2, sizeof(BD2), TableTime.c_str());

	char *tmp="";
	char *tok;
	tmp=strtok_s(BD,"|",&tok);

	while (tmp!=NULL)
	{
		name.push_back(tmp);
		tmp=strtok_s(NULL,"|",&tok);
	}


	char* tmp2="";
	char *tok2;
	tmp2=strtok_s(BD2,"|",&tok2);

	while (tmp2 != NULL)
	{
		time.push_back(tmp2);
		tmp2=strtok_s(NULL,"|",&tok2);
	}

	if (name.size()!=time.size())
		return;

	if (name.size() < 5)
	{
		sprintf_s(BD,sizeof(BD),"%s%s|",TableName.c_str(),Name);
		GetLocalTime(&t);
		sprintf_s(BD2,sizeof(BD2),"%s%d.%d.%d.%d.%d.%d|",TableTime.c_str(),t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);
		TableName=BD;
		TableTime=BD2;
		return;
	}

	for (int i=0; i < (int)time.size(); i++)
	{
		T_Time.push_back(time[i]);
		T_Name.push_back(name[i]);
	}

	for (int i=0; i < (int)time.size(); i++)
	{

		i_time.clear();
		char *tok3;
		tmp=strtok_s(time[i],".",&tok3);
		while (tmp!=NULL)
		{
			i_time.push_back(atoi(tmp));
			tmp=strtok_s(NULL,".",&tok3);
		}
		if (i_time.size()!=6) //���������� �� ���� 6 �������� ������ �������� ���� ����������
			return;
		t.wDay=i_time[0];
		t.wMonth=i_time[1];
		t.wYear=i_time[2];
		t.wHour=i_time[3];
		t.wMinute=i_time[4];
		t.wSecond=i_time[5];

		if (i==0)
		{
			m_time=t;
			continue;
		}

		if ( DataEcval(m_time,t) == 1)//1 - ������ ������, ������� 2�� �������
		{
			m_time=t;
			element=i;
		}

	}

	GetLocalTime(&t);//t-����� �� ������� ����� ��������������� � ����� �����
	sprintf_s(BD,sizeof(BD),"%d.%d.%d.%d.%d.%d",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);

	T_Name[element]=Name;
	T_Time[element]=BD;
	sprintf_s(BD,sizeof(BD),"%s|%s|%s|%s|%s|",T_Name[0].c_str(),T_Name[1].c_str(),T_Name[2].c_str(),T_Name[3].c_str(),T_Name[4].c_str());
	sprintf_s(BD2,sizeof(BD2),"%s|%s|%s|%s|%s|",T_Time[0].c_str(),T_Time[1].c_str(),T_Time[2].c_str(),T_Time[3].c_str(),T_Time[4].c_str());
	TableName=BD;
	TableTime=BD2;

}

//------------------------------------------------------------

bool ObjectRange(int aIndex)
{
	if ( (unsigned int)aIndex > OBJMAX )
		return false;
	else
		return true;
}

//------------------------------------------------------------

bool UserRange(int aIndex)
{

	if ( aIndex < OBJ_STARTUSERINDEX || aIndex > OBJMAX )
		return false;
	else
		return true;
}

//------------------------------------------------------------

bool FixWarpIfUserDie(int aIndex)
{

	if (!OBJMAX_RANGE(aIndex))
		return false;

	LPOBJ lpObj=&gObj[aIndex];

	int mapnum = lpObj->MapNumber;
	int x = lpObj->X;
	int y = lpObj->Y;

	if(lpObj->Type == OBJ_USER)
	{
		if(g_iUseCharacterAutoRecuperationSystem != 0 && lpObj->Level <= g_iCharacterRecuperationMaxLevel)
		{
			lpObj->m_iAutoRecuperationTime = GetTickCount();
		}
		else
		{
			lpObj->m_iAutoRecuperationTime = 0;
		}

		lpObj->dwShieldAutoRefillTimer = GetTickCount();


		gDarkSpirit[lpObj->m_Index].SetMode(CDarkSpirit::ePetItem_Mode::PetItem_Mode_Normal,-1);

		if(lpObj->KillerType == 3)
		{
			MapC[lpObj->MapNumber].GetRandomLengthPos((short &)lpObj->X,(short &)lpObj->Y,18);
		}
		else if(lpObj->KillerType == 2)
		{
			int w_Type = 0;

			if(lpObj->lpGuild != 0)
			{
				if(lpObj->lpGuild->WarType == 1)
				{
					w_Type = 1;
				}
			}

			if(w_Type == 0)
			{
				MapC[lpObj->MapNumber].GetRandomLengthPos((short &)lpObj->X,(short &)lpObj->Y,18);
			}
			else if(lpObj->lpGuild->WarState)
			{
				int BattleGroundIndex = lpObj->lpGuild->BattleGroundIndex;
				gBattleGetTeamPosition(BattleGroundIndex,lpObj->lpGuild->BattleTeamCode,(short &)lpObj->X,(short &)lpObj->Y);
			}
		}
		else if(lpObj->MapNumber == MAP_INDEX_LORENCIA || lpObj->MapNumber == MAP_INDEX_DUNGEON || 
			lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE1 || lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE2 ||
			lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE3 || lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE4 ||
			lpObj->MapNumber == MAP_INDEX_ILLUSIONTEMPLE5)
		{
			lpObj->MapNumber = MAP_INDEX_LORENCIA;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
		else if(DS_MAP_RANGE(lpObj->MapNumber))
		{
			g_DevilSquare.DieProcDevilSquare(lpObj);
			lpObj->MapNumber = MAP_INDEX_NORIA;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
		else if(lpObj->MapNumber == MAP_INDEX_ICARUS)
		{
			lpObj->MapNumber = MAP_INDEX_DEVIAS;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
		else if(BC_MAP_RANGE(lpObj->MapNumber))
		{
			lpObj->MapNumber = MAP_INDEX_DEVIAS;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
		else if(CC_MAP_RANGE(lpObj->MapNumber))
		{
			lpObj->MapNumber = MAP_INDEX_DEVIAS;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
		else if(KALIMA_MAP_RANGE(lpObj->MapNumber))
		{
			lpObj->MapNumber = MAP_INDEX_DEVIAS;
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
 
		else if(lpObj->MapNumber == MAP_INDEX_CASTLEHUNTZONE)
		{
			int mgt = 106;
			short x,y,level;
			BYTE map = lpObj->MapNumber,dir;
			int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

			if(result >= 0)
			{
				lpObj->MapNumber = map;
				lpObj->X = x;
				lpObj->Y = y;
			}
		}
		else if(lpObj->MapNumber == MAP_INDEX_CASTLESIEGE)
		{
			if ( g_CsNPC_LifeStone.SetReSpawnUserXY(lpObj->m_Index) == FALSE )
			{
				int mgt = 100;
				if ( lpObj->m_btCsJoinSide == 1 )
					mgt = 105;
				else
					mgt = 100;

				short x,y,level;
				BYTE map = lpObj->MapNumber,dir;
				int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

				if(result >= 0)
				{
					lpObj->MapNumber = map;
					lpObj->X = x;
					lpObj->Y = y;
				}
			}
		}

		else if(lpObj->MapNumber == MAP_INDEX_AIDA)
		{
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}
		else if(lpObj->MapNumber == MAP_INDEX_CRYWOLF_FIRSTZONE)
		{
 
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);

			if ( g_Crywolf.GetCrywolfState() == 4 )
			{
				int mgt = 118;
				short x,y,level;
				BYTE map = lpObj->MapNumber,dir;
				int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

				if(result >= 0)
				{
					lpObj->MapNumber = map;
					lpObj->X = x;
					lpObj->Y = y;
				}
				else
				{
					MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
				}
			}
			else
			{
				MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
			}

		}
 
		else if(lpObj->MapNumber == MAP_INDEX_KANTURU_BOSS)
		{
			int mgt = 137;
			short x,y,level;
			BYTE map = lpObj->MapNumber,dir;
			int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

			if(result >= 0)
			{
				lpObj->MapNumber = map;
				lpObj->X = x;
				lpObj->Y = y;
			}

			g_KanturuBattleUserMng.DeleteUserData(lpObj->m_Index);
		}
		else if(lpObj->MapNumber == MAP_INDEX_KANTURU1)
		{
			int mgt = 138;
			short x,y,level;
			BYTE map = lpObj->MapNumber,dir;

			int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

			if(result >= 0)
			{
				lpObj->MapNumber = map;
				lpObj->X = x;
				lpObj->Y = y;
			}
		}
		else if(lpObj->MapNumber == MAP_INDEX_KANTURU2)
		{
			int mgt = 139;
			short x,y,level;
			BYTE map = lpObj->MapNumber,dir;

			int result = gGateC.GetGate(mgt,(short &)x,(short &)y,(BYTE &)map,(BYTE &)dir,(short &)level);

			if(result >= 0)
			{
				lpObj->MapNumber = map;
				lpObj->X = x;
				lpObj->Y = y;
			}
		}

		else
		{
			MapC[lpObj->MapNumber].GetMapPos(lpObj->MapNumber,(short &)lpObj->X,(short &)lpObj->Y);
		}

		short m_Result = g_MapServerManager.CheckMoveMapSvr(lpObj->m_Index,lpObj->MapNumber,lpObj->m_sPrevMapSvrCode);

		if(m_Result != gGameServerCode )
		{
			if(m_Result == -1)
			{
				LogAdd("[MapServerMng] Map Server Move Fail : CheckMoveMapSvr() == -1 [%s][%s] (%d)",lpObj->AccountID,lpObj->Name,lpObj->m_Index);
				return false;
			}

			int _map = lpObj->MapNumber;
			int _x = lpObj->X;
			int _y = lpObj->Y;

			lpObj->MapNumber = mapnum;
			lpObj->X = x;
			lpObj->Y = y;

			GJReqMapSvrMove(lpObj->m_Index,m_Result,_map,_x,_y);
			LogAdd("[MapServerMng] Request to Move Map Server : (%d) - [%s][%s] (%d)",m_Result,lpObj->AccountID,lpObj->Name,lpObj->m_Index);
			return true;
		}

		lpObj->TX = lpObj->X;
		lpObj->TY = lpObj->Y;

 
		if ( lpObj->MapNumber == MAP_INDEX_CASTLESIEGE )
		{
			GCAnsCsNotifyStart(lpObj->m_Index, CHECK_CLASS(g_CastleSiege.GetCastleState(), CASTLESIEGE_STATE_STARTSIEGE));

			if ( g_CastleSiege.GetCastleState() == CASTLESIEGE_STATE_STARTSIEGE )
			{
				g_CastleSiege.NotifySelfCsJoinSide(lpObj->m_Index);
				g_CastleSiege.NotifyCsSelfLeftTime(lpObj->m_Index);
			}
		}

	}

	return true;

}



//------------------------------------------------------------

bool InitIDR( LPSTR name )
{
	int Token;

	IDR_Type.clear();
	IDR_Index.clear();
	IDR_Level.clear();
	IDR_Dur.clear();
	IDR_Skill.clear();
	IDR_Luck.clear();
	IDR_Opt.clear();
	IDR_Exc.clear();
	IDR_Anc.clear();
	IDR_DropRate.clear();
	IDR_MobMinLvl.clear();
	IDR_MobMaxLvl.clear();
	IDR_DropMap.clear();

	if ( fopen_s(&SMDFile,name, "r") != 0 )
	{
		MsgBox("Item Drop Rate data load error %s", name);
		return FALSE;
	}
#ifndef PUBLIC
	while ( true )
	{
		Token = GetToken();

		if ( Token == 2 )
		{
			break;
		}

		if ( Token == 1 )
		{
			IDR_Type.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Index.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Level.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Dur.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Skill.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Luck.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Opt.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Exc.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Anc.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_DropRate.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_MobMinLvl.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_MobMaxLvl.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_DropMap.push_back((int)TokenNumber);

		}
	}
#else
	int Count = 25;
	while ( Count-- )
	{
		Token = GetToken();

		if ( Token == 2 )
		{
			break;
		}

		if ( Token == 1 )
		{
			IDR_Type.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Index.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Level.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Dur.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Skill.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Luck.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Opt.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Exc.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_Anc.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_DropRate.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_MobMinLvl.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_MobMaxLvl.push_back((int)TokenNumber);

			Token = GetToken();
			IDR_DropMap.push_back((int)TokenNumber);

		}
	}
#endif


	fclose(SMDFile);
	return true;	
}

//------------------------------------------------------------

bool LoadMysteryShop(char *file)
{
	int Token;

	gMysteryShop_Type.clear();
	gMysteryShop_Index.clear();
	gMysteryShop_Level.clear();
	gMysteryShop_Dur.clear();
	gMysteryShop_Skill.clear();
	gMysteryShop_Luck.clear();
	gMysteryShop_Opt.clear();
	gMysteryShop_Exc.clear();
	gMysteryShop_Anc.clear();	
	gMysteryShop_AverageLvl.clear();
	gMysteryShop_AroundLvl.clear();
	gMysteryShop_AverageRes.clear();
	gMysteryShop_AroundRes.clear();
	gMysteryShop_InsertRate.clear();

	if ( fopen_s(&SMDFile,file, "r") != 0 )
	{
		MsgBox("Mystery Shop data load error %s", file);
		return FALSE;
	}

	while ( true )
	{
		Token = GetToken();

		if ( Token == 2 )
		{
			break;
		}

		if ( Token == 1 )
		{
			gMysteryShop_Type.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Index.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Level.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Dur.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Skill.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Luck.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Opt.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Exc.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_Anc.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_AverageLvl.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_AroundLvl.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_AverageRes.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_AroundRes.push_back((int)TokenNumber);

			Token = GetToken();
			gMysteryShop_InsertRate.push_back((int)TokenNumber);

		}
	}

	fclose(SMDFile);
	return true;	
}

//------------------------------------------------------------

bool InitAntiBadWords( LPSTR name )
{
	int Token;

	AntiMat.clear();
	BanHours.clear();

	if ( fopen_s(&SMDFile,name, "r") != 0 )
	{
		MsgBox("Anti Bad Words data load error %s", name);
		return FALSE;
	}

	while ( true )
	{
		Token = GetToken();

		if ( Token == 0 )
		{
			if ( strcmp("end", TokenString) == 0 )
			{
				break;
			}
		}

		AntiMat.push_back(TokenString);

		Token = GetToken();
		BanHours.push_back((int)TokenNumber);

	}

	fclose(SMDFile);
	return true;	
}

//------------------------------------------------------

bool RefreshMysteryShop()
{
	/*if (SQL.m_SQLSTMTHandle  == NULL || !gMysteryShopOnOff)
		return false;
	//---
	LPOBJ lpObj;
	//---
	int Number = 1;//���������� ����� ������ � ��
	int ItemsInShop = 0;//������ ��������� ����� � ���
	int DBLevel = 0;//����� ������ ���� �������� � ��
	int old_DBLevel = -1;
	int Rand = 0;//��������� ����� � �������� - 0;gMysteryShop_Type.size()-1
	//---
	char SQLBuf[10]={0};//��� ����������� � ������ � SQLString
	//---
	std::string Nick;//��� ������ ����� � ��
	std::string old_Nick = "-1";
	std::string SQLString;//����� ��� ��
	//---
	std::vector<std::string> ListNames;
	while (1)
	{
		Nick = "";
		DBLevel = -1;//��������� �������� �����
		lpObj = NULL;

		Nick = SQL.GetFieldChar("MuOnline.dbo.Character","Name","WHERE Number = '%d'",Number);
		DBLevel = SQL.GetFieldInt("MuOnline.dbo.Character","cLevel","WHERE Number = '%d'",Number);
		Number++;

		if ( Nick.empty() || DBLevel == -1 )//���� �� ������ ��������� ������ � �� - ��������
			break;

		if (old_DBLevel == DBLevel && old_Nick == Nick)
			break;

		old_Nick = Nick;
		old_DBLevel = DBLevel;

		ListNames.push_back(Nick);//���������� ��������� ��������� � ������ ��������� ��� ���� ���� ��������� ���� ������� ������� � ��

		SQLString = "UPDATE MuOnline.dbo.Character SET MysteryShop=('";//�������� ���������� ������ ��� ��

		for (ItemsInShop = 0 ; ItemsInShop != gMysteryShopMaxItems; )//���������� �� ��������� ������
		{
			Rand = Random(0,gMysteryShop_Type.size()-1);//�������� ��������� �� � ������
			if ( (DBLevel >= gMysteryShop_AverageLvl[Rand] - gMysteryShop_AroundLvl[Rand]) && (DBLevel <= gMysteryShop_AverageLvl[Rand] + gMysteryShop_AroundLvl[Rand]) )
			{
				if (Random(0,99) < gMysteryShop_InsertRate[Rand])
				{
					_itoa_s(gMysteryShop_Type[Rand],SQLBuf,10);
					SQLString += SQLBuf;
					SQLString += " ";

					_itoa_s(gMysteryShop_Index[Rand],SQLBuf,10);
					SQLString += SQLBuf;
					SQLString += " ";

					_itoa_s(gMysteryShop_Level[Rand],SQLBuf,10);
					SQLString += SQLBuf;
					SQLString += " ";

					_itoa_s(gMysteryShop_Dur[Rand],SQLBuf,10);
					SQLString += SQLBuf;
					SQLString += " ";

					_itoa_s(gMysteryShop_Skill[Rand],SQLBuf,10);
					SQLString += SQLBuf;
					SQLString += " ";

					_itoa_s(gMysteryShop_Luck[Rand],SQLBuf,10);
					SQLString += SQLBuf;
					SQLString += " ";

					_itoa_s(gMysteryShop_Opt[Rand],SQLBuf,10);
					SQLString += SQLBuf;
					SQLString += " ";

					
					ItemsInShop++;
				}
			}
		}
		SQLString += "') WHERE Name=('";
		SQLString += Nick;
		SQLString += "')";

		SQL.Execute((LPTSTR)SQLString.c_str());//��������� ������ ����� �������� � ��. ��� ����� � ������ � �� ��� ������ ��������. 
		//� ���� �� ����� � ��� �� � ����� ������ �� ��������. ���� ��������� ����� ����� ������ � �� � ������� ���� �������

	}

	for (int i = OBJ_STARTUSERINDEX; i < OBJMAX; i++)
	{
		lpObj = &gObj[i];
		if (lpObj->Connected != PLAYER_PLAYING || lpObj->Type != OBJ_USER)//���� ����� �� � �� �� ���� ������� ���������� ���� �������
			continue;

		for (int a = 0; a < ListNames.size(); a++)//���� � �� ������� ���� ��������� ������� ��� �������� ������ ������ � ������ ������
		{
			if (ListNames[a].compare(lpObj->Name) == 0 )
			{
				lpObj->MysteryShop.ClearShop();

				UserLoadMysteryShopFromDB(lpObj);

				ListNames[a].clear();
			}
		}
	}*/

	return true;
}



//------------------------------------------------------------



void UserLoadMysteryShopFromDB(LPOBJ lpObj)
{
	/*if (lpObj == NULL || !gMysteryShopOnOff)
		return;

	char * Token = "";
	char * tok;
	int Type = 0 , Index = 0, Level = 0 , Dur = 0, Opt1 = 0, Opt2 = 0, Opt3 = 0;
	std::string SQLString = SQL.GetFieldChar("MuOnline.dbo.Character","MysteryShop","WHERE Name = '%s'",lpObj->Name);

	lpObj->MysteryShop.ClearShop();
		
	Token = strtok_s( (char*) SQLString.c_str()," ",&tok);

	while (Token != NULL)
	{
		Type = atoi(Token);
		Token = strtok_s(NULL," ",&tok);

		Index = atoi(Token);
		Token = strtok_s(NULL," ",&tok);

		Level = atoi(Token);
		Token = strtok_s(NULL," ",&tok);

		Dur = atoi(Token);
		Token = strtok_s(NULL," ",&tok);

		Opt1 = atoi(Token);
		Token = strtok_s(NULL," ",&tok);

		Opt2 = atoi(Token);
		Token = strtok_s(NULL," ",&tok);

		Opt3 = atoi(Token);
		Token = strtok_s(NULL," ",&tok);

		lpObj->MysteryShop.InsertItem(Type,Index,Level,Dur,Opt1,Opt2,Opt3);
	}*/

}


//------------------------------------------------------------


void UserSaveMysteryShopFromDB(LPOBJ lpObj)
{
	/*if (lpObj == NULL || !gMysteryShopOnOff)
		return;

	std::string SQLString = "UPDATE MuOnline.dbo.Character SET MysteryShop=('";//����� ���� �� ����� ��������� ���� �� �����

	for (int i = 0 ; i < lpObj->MysteryShop.Type.size(); i++)
	{
		if ( lpObj->MysteryShop.Type[i] == -1 )
			continue;
		else
		{
			SQLString += lpObj->MysteryShop.Type[i];
			SQLString += " ";

			SQLString += lpObj->MysteryShop.Index[i];
			SQLString += " ";

			SQLString += lpObj->MysteryShop.Level[i];
			SQLString += " ";

			SQLString += lpObj->MysteryShop.Dur[i];
			SQLString += " ";

			SQLString += lpObj->MysteryShop.Opt1[i];
			SQLString += " ";

			SQLString += lpObj->MysteryShop.Opt2[i];
			SQLString += " ";

			SQLString += lpObj->MysteryShop.Opt3[i];
			SQLString += " ";
		}
	}
	SQLString += "') WHERE Name=('";
	SQLString += lpObj->Name;
	SQLString += "')";

	SQL.Execute((LPTSTR)SQLString.c_str());*/
}

//------------------------------------------------------------

void LoadUserBuff(char* name,int aIndex)
{
// 	std::string str = SQL.GetFieldChar("MuOnline.dbo.Character","Buff","WHERE Name = '%s'",name);
// 	if (str.empty())
// 		return;
// 	LPOBJ lpObj = &gObj[aIndex];
// 	char *buf = new char[str.length() + 1];
// 	strcpy(buf,str.c_str());
// 	char* tok;
// 	char *token = "";
// 	token = strtok_s(buf,"|",&tok);
// 	lpObj->m_ViewSkillState = atoi(token);
// 	if (lpObj->m_ViewSkillState == 0)
// 	{
// 		delete[] buf;
// 		return;
// 	}
// 
// 	GCStateInfoSend(lpObj,1,lpObj->m_ViewSkillState);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iMuseElfInfinityArrowSkillTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iSkillNPCHelpTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iSkillNPCDefense = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iSkillNPCAttack = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_ImmuneToMagicCount = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_ImmuneToHarmCount = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iSkillBrandOfSkillTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iSkillStunTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iSkillInvisibleTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iSkillManaSwellTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iPotionBlessTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iPotionSoulTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_iItemEffectValidTime = atoi(token);
// 
// 	token = strtok_s(NULL,"|",&tok);
// 	lpObj->m_wItemEffectType = atoi(token);
// 
// 	delete[] buf;
}

void SaveUserBuff(char* name,int aIndex)
{
// 	std::string str;
// 	LPOBJ lpObj = &gObj[aIndex];
// 	char buf[15];
// 
// 	_itoa_s(lpObj->m_ViewSkillState,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iMuseElfInfinityArrowSkillTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iSkillNPCHelpTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iSkillNPCDefense,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iSkillNPCAttack,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_ImmuneToMagicCount,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_ImmuneToHarmCount,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iSkillBrandOfSkillTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iSkillStunTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iSkillInvisibleTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iSkillManaSwellTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iPotionBlessTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iPotionSoulTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_iItemEffectValidTime,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	_itoa_s(lpObj->m_wItemEffectType,buf,10);
// 	str += buf;
// 	str += "|";
// 
// 	std::string str2 = "UPDATE MuOnline.dbo.Character SET Buff=('" ;
// 	str2 += str;
// 	str2 += "') WHERE Name=('";
// 	str2 += name;
// 	str2 += "')";
// 
// 	SQL.Execute((LPSTR)str2.c_str());

}