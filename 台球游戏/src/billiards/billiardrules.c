#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"billiards.h"
#include "sundry.h"



int GameState, GameProcess;
int RuleFlag = 0;


ballin *BallInList = NULL;//存储本次进球的球信息，因为实际击球可能多个球进洞


//初始化游戏过程中状态变量
void InitialRule(void) 
{
	GameState = 0;
	GameProcess = 0;
	RuleFlag = 0;
	score[0] = 0;
	score[1] = 0;
}


//斯若克彩球进洞复位
static void ResetBall(billiardball *   BilliardBall) 
{
	switch (BilliardBall->id) {
	case 1:
		BilliardBall->x = cx - TableWidth / 2 + 2.9;
		BilliardBall->y = cy - 4 * BallRadius;
		BilliardBall->state = OUTHOLE;
		break;
	case 17:
		BilliardBall->x = cx - TableWidth / 2 + 2.9;
		BilliardBall->y = cy;
		BilliardBall->state = OUTHOLE;
		break;
	case 18:
		BilliardBall->x = cx - TableWidth / 2 + 2.9;
		BilliardBall->y = cy - 8 * BallRadius;
		BilliardBall->state = OUTHOLE;
		break;
	case 19:
		BilliardBall->x = cx - TableWidth / 2 + 2.9;
		BilliardBall->y = cy + 8 * BallRadius;
		BilliardBall->state = OUTHOLE;
		break;
	case 20:
		BilliardBall->x = cx;
		BilliardBall->y = cy;
		BilliardBall->state = OUTHOLE;
		break;
	case 21:
		BilliardBall->x = cx + TableWidth / 2 - 2.97 - 4 * BallRadius;
		BilliardBall->y = cy;
		BilliardBall->state = OUTHOLE;
		break;
	case 22:
		BilliardBall->x = cx + TableWidth / 2 - 2.8 + 8 * BallRadius;
		BilliardBall->y = cy;
		BilliardBall->state = OUTHOLE;
		break;
	}

}



//增加一个进洞的球的信息
void AddBallInList(struct billiardballnode * BilliardBall) 
{
	ballin * head = BallInList;
	if (!BallInList) 
	{
		BallInList = (ballin *)malloc(sizeof(ballin));
		BallInList->BilliardBall = BilliardBall;
		BallInList->next = NULL;
		if (!BallInList)
			exit(0);
		return;
	}

	while (head->next) 
	{
		head = head->next;
	}
	head->next = (ballin *)malloc(sizeof(ballin));
	head->next->BilliardBall = BilliardBall;
	head->next->next = NULL;
}



//删除进洞球链表
void ResetBallInList(void) 
{
	ballin * head = BallInList;
	while (head) 
	{
		head = BallInList->next;
		free(BallInList);
		BallInList = head;
	}
	//BallInList = NULL;
}




//计算斯诺克比分
int ComputeSnookerScore(void) 
{
	ballin * head = BallInList;
	static int sum = 0;
	int Illegal = 0;
	static int ColorBall[6] = { 1,1,1,1,1,1 };
	//状态转换，判断红球是否全部进洞
	if (sum >= 16) 
	{
		GameProcess = 1;//不同积分模式
		sum = 16;
	}//红球未完全进洞时，需要击打一下红球，再打一下彩球
	if (!GameProcess) 
	{
		while (head) 
		{
			if (head->BilliardBall->id > 1 && head->BilliardBall->id < 17) 
			{
				sum++;
				if (!RuleFlag) 
				{
					score[Player] += 1;//红球进洞加一分
					RuleFlag = 1;
				}
				else 
				{
					score[Player] -= 4;
					RuleFlag = 0;
					Illegal = 1;
				}
			}
			else if (head->BilliardBall->id == 1) 
			{
				score[Player] -= 4;
				RuleFlag = 0;
				Illegal = 1;
				ResetBall(head->BilliardBall);
			}
			else 
			{
				if (RuleFlag) 
				{
					score[Player] += 7;
					RuleFlag = 0;
				}
				else 
				{
					score[Player] -= 4;
					RuleFlag = 0;
					Illegal = 1;
				}
				ResetBall(head->BilliardBall);
			}
			head = head->next;
		}
	}
	else 
	{
		while (head) 
		{
			if (head->BilliardBall->id == 1) 
			{
				score[Player] -= 4;
				Illegal = 1;
				ResetBall(head->BilliardBall);
			}
			else 
			{
				if (head->BilliardBall->id == 17 || ColorBall[head->BilliardBall->id - 18] == 0) 
				{
					score[Player] += head->BilliardBall->id - 15;
					ColorBall[head->BilliardBall->id - 17] = 0;
				}
				else 
				{
					score[Player] -= head->BilliardBall->id - 15;
					ResetBall(head->BilliardBall);
					Illegal = 1;
				}
			}
			head = head->next;
		}
	}
	score[Player] = score[Player] < 0 ? 0 : score[Player];
	if (!BallInList || Illegal) 
	{
		return 1;
	}
	return 0;
}



//改变斯诺克状态，四个状态，PA操作状态，PA回合球运动状态，PB操作状态，PB回合球运动状态
void ChangeSnookerState(void) 
{
	switch (GameState) 
	{
	case PA:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PAWAITING;
		}
		break;
	case PAWAITING:

		if (IfStop(BallList))
		{
			if (ComputeSnookerScore()) 
			{
				GameState = PB;
				RuleFlag = 0;
				Player = 1;
			}
			else 
			{
				GameState = PA;
			}
			ResetBallInList();
		}

		break;
	case PB:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PBWAITING;
		}
		break;
	case PBWAITING:
		if (IfStop(BallList))
		{
			if (ComputeSnookerScore()) 
			{
				GameState = PA;
				RuleFlag = 0;
				Player = 0;
			}
			else 
			{
				GameState = PB;
			}
			ResetBallInList();
		}

		break;
	}
}

//计分
int ComputeSidePocketScore(void) 
{
	ballin * head = BallInList;
	int Illegal = 0, i;
	static int ColorBall[9] = { 1,1,1,1,1,1,1,1,1 };
	if (RuleFlag < 5 && !BallInList) 
	{
		RuleFlag++;
		return 0;
	}
	else if (!BallInList) 
	{
		RuleFlag = 0;
		for (i = 0; i < 9; i++) 
		{
			ColorBall[i] = 1;
		}
		return 1;
	}
	if (head->BilliardBall->id == 2 || ColorBall[head->BilliardBall->id - 3] == 0) 
	{
		ColorBall[head->BilliardBall->id - 2] = 0;
		RuleFlag = 0;
	}
	else 
	{
		RuleFlag = 0;
		for (i = 0; i < 9; i++) 
		{
			ColorBall[i] = 1;
		}
		return 1;
	}
	if (ColorBall[8] == 0) 
	{
		score[Player] += 1;
	}
	return 0;
}



//改变SidePocket状态，四个状态，PA操作状态，PA回合球运动状态，PB操作状态，PB回合球运动状态
void ChangeSidePocketState(void) 
{
	switch (GameState) 
	{
	case PA:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PAWAITING;
		}
		break;
	case PAWAITING:

		if (IfStop(BallList))
		{
			if (ComputeSidePocketScore()) 
			{
				GameState = PB;
				RuleFlag = 0;
				Player = 1;
				InitialBallList();
			}
			else 
			{
				GameState = PA;
			}
			ResetBallInList();
		}

		break;
	case PB:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PBWAITING;
		}
		break;
	case PBWAITING:
		if (IfStop(BallList))
		{
			if (ComputeSidePocketScore()) 
			{
				GameState = PA;
				RuleFlag = 0;
				Player = 0;
				InitialBallList();
			}
			else 
			{
				GameState = PB;
			}
			ResetBallInList();
		}

		break;
	}
}



//计分
int ComputeAmericanScore(void) 
{
	ballin * head = BallInList;
	int Illegal = 0, i;
	static int ColorBall_1[7] = { 1,1,1,1,1,1,1 };
	static int ColorBall_2[7] = { 1,1,1,1,1,1,1 };
	if (!BallInList)
		return 1;
	switch (Player) 
	{
	case 0:
		if ((head->BilliardBall->id == 2 || ColorBall_1[head->BilliardBall->id - 3] == 0) && head->BilliardBall->id < 10) 
		{
			ColorBall_1[head->BilliardBall->id - 2] = 0;
			score[Player] += 1;
		}
		else 
		{
			for (i = 0; i < 7; i++) 
			{
				ColorBall_1[i] = 1;
				ColorBall_2[i] = 1;
			}
			InitialBallList();
			return 1;
		}
		break;
	case 1:
		if ((head->BilliardBall->id == 10 || ColorBall_2[head->BilliardBall->id - 11] == 0) && head->BilliardBall->id >= 10) 
		{
			ColorBall_2[head->BilliardBall->id - 11] = 0;
			score[Player] += 1;
		}
		else 
		{
			for (i = 0; i < 7; i++) 
			{
				ColorBall_1[i] = 1;
				ColorBall_2[i] = 1;
			}
			InitialBallList();
			return 1;
		}
		break;
	}

	return 0;
}



//改变American状态，四个状态，PA操作状态，PA回合球运动状态，PB操作状态，PB回合球运动状态
void ChangeAmericanState(void) 
{
	switch (GameState) 
	{
	case PA:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PAWAITING;
		}
		break;
	case PAWAITING:

		if (IfStop(BallList))
		{
			if (ComputeAmericanScore()) 
			{
				GameState = PB;
				Player = 1;
			}
			else 
			{
				GameState = PA;
			}
			ResetBallInList();
		}

		break;
	case PB:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PBWAITING;
		}
		break;
	case PBWAITING:
		if (IfStop(BallList))
		{
			if (ComputeAmericanScore()) 
			{
				GameState = PA;
				Player = 0;
			}
			else 
			{
				GameState = PB;
			}
			ResetBallInList();
		}

		break;
	}
}



//Entertain计分
int ComputeEntertainScore(void) 
{
	ballin * head = BallInList;
	int Illegal = 0, i;
	if (!BallInList)
		return 1;
	while (head) 
	{
		score[Player] += head->BilliardBall->id;
		if (head->BilliardBall->id == 1) 
		{
			head->BilliardBall->x = cx - TableWidth / 4;
			head->BilliardBall->y = cy;
			head->BilliardBall->v = 0;
			head->BilliardBall->state = OUTHOLE;
			return 1;
		}
		head = head->next;
	}
	return 0;
}



//改变Entertain状态，四个状态，PA操作状态，PA回合球运动状态，PB操作状态，PB回合球运动状态
void ChangeEntertainState(void) 
{
	switch (GameState) 
	{
	case PA:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PAWAITING;
		}
		break;
	case PAWAITING:

		if (IfStop(BallList))
		{
			if (ComputeEntertainScore()) 
			{
				GameState = PB;
				Player = 1;
			}
			else 
			{
				GameState = PA;
			}
			ResetBallInList();
		}

		break;
	case PB:
		if (MouseEvent == BUTTON_DOWN)
		{
			GameState = PBWAITING;
		}
		break;
	case PBWAITING:
		if (IfStop(BallList))
		{
			if (ComputeEntertainScore()) 
			{
				GameState = PA;
				Player = 0;
			}
			else 
			{
				GameState = PB;
			}
			ResetBallInList();
		}

		break;
	}
}
//规则选择，不同游戏模式选择不同状态
void GameRule(int GameMode) 
{
	switch (GameMode) 
	{
	case SNOOKER:
		ChangeSnookerState();
		break;
	case SIDE_POCKET:
		ChangeSidePocketState();
		break;
	case AMERICAN:
		ChangeAmericanState();
		break;
	case ENTERTAINMENT:
		ChangeEntertainState();
		break;
	}
}