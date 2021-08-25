#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"billiards.h"
#include "sundry.h"
#include "page.h"




int score[2] = { 0,0 };
int Player;
int BilliardbMode = SIDE_POCKET;
//用于存储两步情况，存于内存中
gameimfor GameCache[2];//循环栈
int GameImforIndex = 0;//指示此时缓存区的位置，栈顶
int StrengthFlag, FrictionFlag;
char FileName[65] = "";//存储存档的文件名




//显示游戏比分
void ShowScore(void) {
	char s1[4];
	char s2[4];
	sprintf(s1, "%.3d", score[0]);
	sprintf(s2, "%.3d", score[1]);
	StartFilledRegion(1);
	SetPenColor("Black");
	MovePen(6.5, 10.4);
	DrawBox(3, 1.6);
	EndFilledRegion();

	SetPenSize(3);
	SetPenColor("White");
	MovePen(6.5, 11.3);
	DrawBox(3, 0.7);
	MovePen(6.5, 10.4);
	DrawBox(1.5, 0.9);
	MovePen(8, 10.4);
	DrawBox(1.5, 0.9);

	SetPointSize(45);
	SetPenColor("Green");
	MovePen(7.25 - TextStringWidth(s1) / 2, 11.3 - 0.9 * 3 / 4 - GetFontDescent());
	DrawTextString(s1);
	MovePen(8.75 - TextStringWidth(s2) / 2, 11.3 - 0.9 * 3 / 4 - GetFontDescent());
	DrawTextString(s2);

	SetPointSize(35);
	SetPenColor("Red");

	switch (BilliardbMode) 
	{
		case SNOOKER:
			MovePen(8 - TextStringWidth("SNOOKER") / 2, 12 - 0.8 / 2 - GetFontDescent());
			DrawTextString("SNOOKER");
			break;
		case SIDE_POCKET:
			MovePen(8 - TextStringWidth("SIDEPOCKET") / 2, 12 - 0.8 / 2 - GetFontDescent());
			DrawTextString("SIDEPOCKET");
			break;
		case AMERICAN:
			MovePen(8 - TextStringWidth("AMERICAN") / 2, 12 - 0.8 / 2 - GetFontDescent());
			DrawTextString("AMERICAN");
			break;
	}

	SetPenColor("White");
	SetPointSize(22);
	MovePen(7.25 - TextStringWidth("P1") / 2, 11.3 - 0.9 * 1 / 4 - GetFontDescent());
	DrawTextString("P1");
	MovePen(8.75 - TextStringWidth("P2") / 2, 11.3 - 0.9 * 1 / 4 - GetFontDescent());
	DrawTextString("P2");
	SetPointSize(45);
}


//显示P1
void ShowP1(void) 
{
	StartFilledRegion(1);
	SetPenColor("Black");
	MovePen(3.5, 10.7);
	DrawBox(1, 1);
	EndFilledRegion();
	SetPenSize(3);
	SetPenColor("Blue");
	MovePen(3.5, 10.7);
	DrawBox(1, 1);
	MovePen(4 - TextStringWidth("P1") / 2, 11.1 - GetFontDescent());
	DrawTextString("P1");
}


//显示P2
void ShowP2(void) 
{
	StartFilledRegion(1);
	SetPenColor("Black");
	MovePen(12.5, 10.7);
	DrawBox(1, 1);
	EndFilledRegion();
	SetPenSize(3);
	SetPenColor("Red");
	MovePen(12.5, 10.7);
	DrawBox(1, 1);
	MovePen(13 - TextStringWidth("P2") / 2, 11.1 - GetFontDescent());
	DrawTextString("P2");
}


//控制P1,P2显示
void ShowTurn(void) 
{
	switch (Player)
	{
	case 0:
		ShowP1();
		break;
	case 1:
		ShowP2();
		break;
	}
}


//删除链表
static void DeleteBallList(billiardball* BallList) 
{
	billiardball* head = BallList;
	while (head) 
	{
		head = BallList->next;
		free(BallList);
		BallList = head;
	}
}


//创建链表
static billiardball* CreateBallList(void)
{
	billiardball* BallList = NULL;
	switch (BilliardbMode) 
	{
	case SNOOKER:
		BallList = InitialSnookerBallList();
		break;
	case SIDE_POCKET:
		BallList = InitialSidePocketBallList();
		break;
	case AMERICAN:
		BallList = InitialAmericanBallList();
		break;
	case ENTERTAINMENT:
		BallList = InitialAmericanBallList();;
		break;
	}
	return BallList;
}


//复制链表
static void CopyBallList(billiardball* BallList_1, billiardball* BallList_2)
{
	while (BallList_1)
	{
		BallList_1->radius = BallList_2->radius;
		BallList_1->x = BallList_2->x;
		BallList_1->y = BallList_2->y;
		BallList_1->angle = BallList_2->angle;
		BallList_1->v = BallList_2->v;
		BallList_1->id = BallList_2->id;
		BallList_1->state = BallList_2->state;
		BallList_1 = BallList_1->next;
		BallList_2 = BallList_2->next;
	}
}


//初始化结构体，使指针有指向的地方
void InitialGameImfor(void) 
{
	DeleteBallList(GameCache[0].BallList);
	DeleteBallList(GameCache[1].BallList);
	GameCache[0].BallList = CreateBallList();
	GameCache[1].BallList = CreateBallList();
}


//游戏信息存入缓存区
void SaveGameImfor(void) 
{
	GameImforIndex = !GameImforIndex;
	CopyBallList(GameCache[GameImforIndex].BallList, BallList);
	GameCache[GameImforIndex].Player = Player;
	GameCache[GameImforIndex].score[0] = score[0];
	GameCache[GameImforIndex].score[1] = score[1];
	GameCache[GameImforIndex].BilliardbMode = BilliardbMode;
	GameCache[GameImforIndex].GameState = GameState;
	GameCache[GameImforIndex].GameProcess = GameProcess;
	GameCache[GameImforIndex].RuleFlag = RuleFlag;
}


void CreateFileName(int BilliardbMode) 
{
	strcpy(FileName, ".\\data\\account\\");
	strcat(FileName, UserName);
	switch (BilliardbMode)
	{
	case SNOOKER:
		strcat(FileName, "_snooker.bat");
		break;
	case SIDE_POCKET:
		strcat(FileName, "_sidepocket.txt");
		break;
	case AMERICAN:
		strcat(FileName, "_american.txt");
		break;
	case ENTERTAINMENT:
		strcat(FileName, "_entertain.txt");
		break;
	}
}


//从缓存区里读取信息
void ReadGameImfor(void) 
{
	CopyBallList(BallList, GameCache[GameImforIndex].BallList);
	Player = GameCache[GameImforIndex].Player;
	score[0] = GameCache[GameImforIndex].score[0];
	score[1] = GameCache[GameImforIndex].score[1];
	BilliardbMode = GameCache[GameImforIndex].BilliardbMode;
	GameState = GameCache[GameImforIndex].GameState;
	GameProcess = GameCache[GameImforIndex].GameProcess;
	RuleFlag = GameCache[GameImforIndex].RuleFlag;
	GameImforIndex = !GameImforIndex;
}


void SaveImfor(void) 
{
	FILE* save;
	int times = 0;
	CreateFileName(BilliardbMode);
	if ((save = fopen(FileName, "wb+")) == NULL) 
	{
		exit(1);
	}

	fwrite(&GameCache[GameImforIndex].Player, sizeof(int), 1, save);
	fwrite(GameCache[GameImforIndex].score, sizeof(int), 2, save);
	fwrite(&GameCache[GameImforIndex].BilliardbMode, sizeof(int), 1, save);
	fwrite(&GameCache[GameImforIndex].GameState, sizeof(int), 1, save);
	fwrite(&GameCache[GameImforIndex].GameProcess, sizeof(int), 1, save);
	fwrite(&GameCache[GameImforIndex].RuleFlag, sizeof(int), 1, save);

	billiardball* p = NULL;
	for (p = GameCache[GameImforIndex].BallList; p != NULL; p = p->next) 
	{
		fwrite(&p->radius, sizeof(double), 1, save);
		fwrite(&p->x, sizeof(double), 1, save);
		fwrite(&p->y, sizeof(double), 1, save);
		fwrite(&p->angle, sizeof(double), 1, save);
		fwrite(&p->v, sizeof(double), 1, save);
		fwrite(&p->id, sizeof(int), 1, save);
		fwrite(&p->state, sizeof(int), 1, save);
	}
	fclose(save);
}


void LoadImfor(void) 
{
	FILE* save;
	int times = 0;
	CreateFileName(BilliardbMode);
	
	if ((save = fopen(FileName, "ab+")) == NULL) 
	{
		MovePen(GetWindowWidth() / 2 - 2, 0);
		DrawTextString("Can't open GameSave.txt!");
		exit(1);
	}
	fclose(save);
	if ((save = fopen(FileName, "rb+")) == NULL) 
	{
		MovePen(GetWindowWidth() / 2 - 2, 0);
		DrawTextString("Can't open GameSave.txt!");
		exit(1);
	}

	fread(&GameCache[GameImforIndex].Player, sizeof(int), 1, save);
	fread(GameCache[GameImforIndex].score, sizeof(int), 2, save);
	fread(&GameCache[GameImforIndex].BilliardbMode, sizeof(int), 1, save);
	fread(&GameCache[GameImforIndex].GameState, sizeof(int), 1, save);
	fread(&GameCache[GameImforIndex].GameProcess, sizeof(int), 1, save);
	fread(&GameCache[GameImforIndex].RuleFlag, sizeof(int), 1, save);

	billiardball* p = NULL;
	for (p = GameCache[GameImforIndex].BallList; p != NULL; p = p->next) 
	{
		fread(&p->radius, sizeof(double), 1, save);
		fread(&p->x, sizeof(double), 1, save);
		fread(&p->y, sizeof(double), 1, save);
		fread(&p->angle, sizeof(double), 1, save);
		fread(&p->v, sizeof(double), 1, save);
		fread(&p->id, sizeof(int), 1, save);
		fread(&p->state, sizeof(int), 1, save);
	}
	fclose(save);
	ReadGameImfor();
}
