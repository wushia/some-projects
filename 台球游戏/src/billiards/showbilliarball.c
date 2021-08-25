#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"billiards.h"
#include "sundry.h"
#include"button.h"
#include"music.h"


char SnookerColor[][12] = { "White","Red","Red","Red","Red","Red","Red", "Red","Red", "Red","Red", "Red", "Red","Red" ,"Red" ,"Red" , "Brown", "Yellow","Green" ,"Blue" ,"Magenta" ,"Black" };
char SidePocketColor[][12] = { "White","Yellow","Blue","Red","Violet","Magenta","Green","Brown","Black", "Orange" };
char AmericanColor[][12] = { "White","Yellow","Blue","Red","Violet","Magenta","Green","Brown","Black","Yellow","Blue","Red","Violet","Magenta","Green","Brown" };

//绘制斯若克形式台球
void ShowSnookerBilliard(billiardball * BilliardBall)
{
	if (BilliardBall->state == INHOLE)
	{
		return;
	}
	SetPenColor(SnookerColor[BilliardBall->id - 1]);
	//SetPenColor("red");
	int i = 1;
	StartFilledRegion(1);
	MovePen(BilliardBall->x, BilliardBall->y + BilliardBall->radius);
	SetPenSize(0.5);
	DrawArc(BilliardBall->radius / i, 90, 360);
	EndFilledRegion();
	SetPenColor("White");
	MovePen(BilliardBall->x, BilliardBall->y + BilliardBall->radius);
	SetPenSize(1);
	DrawArc(BilliardBall->radius / i, 90, 360);

}



//显示SidePocket形式的台球
void ShowSidePocketBilliard(billiardball * BilliardBall)
{
	char num[4];
	sprintf(num, "%d", BilliardBall->id - 1);
	if (BilliardBall->state == INHOLE)
	{
		return;
	}
	SetPenColor(SidePocketColor[BilliardBall->id - 1]);
	StartFilledRegion(1);
	MovePen(BilliardBall->x, BilliardBall->y + BilliardBall->radius);
	SetPenSize(0.5);
	DrawArc(BilliardBall->radius, 90, 360);
	EndFilledRegion();



	if (BilliardBall->id == 1)
		return;
	if (BilliardBall->id == 10) {
		SetPenColor("White");
		StartFilledRegion(1);
		MovePen(BilliardBall->x + BilliardBall->radius / 2, BilliardBall->y - BilliardBall->radius*sin(PI / 3));
		SetPenSize(1);
		DrawArc(BilliardBall->radius, -60, 120);
		DrawLine(0, -BilliardBall->radius);
		EndFilledRegion();

		StartFilledRegion(1);
		MovePen(BilliardBall->x - BilliardBall->radius / 2, BilliardBall->y + BilliardBall->radius*sin(PI / 3));
		SetPenSize(1);
		DrawArc(BilliardBall->radius, 120, 120);
		DrawLine(0, BilliardBall->radius);
		EndFilledRegion();
	}
	SetPenColor("Black");
	MovePen(BilliardBall->x, BilliardBall->y + BilliardBall->radius);
	SetPenSize(2);
	DrawArc(BilliardBall->radius, 90, 360);

	if (BilliardBall->v) {
		return;
	}
	SetPenColor("White");
	StartFilledRegion(1);
	MovePen(BilliardBall->x + BilliardBall->radius / 2, BilliardBall->y);
	DrawArc(BilliardBall->radius / 2, 0, 360);
	EndFilledRegion();
	SetPenColor("Black");
	SetPointSize(2);
	MovePen(BilliardBall->x - TextStringWidth(num) / 2, BilliardBall->y - GetFontHeight() / 2.5);
	DrawTextString(num);
}




void ShowAmericanBilliard(billiardball * BilliardBall)
{
	char num[4];
	sprintf(num, "%d", BilliardBall->id - 1);
	if (BilliardBall->state == INHOLE)
	{
		return;
	}
	SetPenColor(AmericanColor[BilliardBall->id - 1]);
	StartFilledRegion(1);
	MovePen(BilliardBall->x, BilliardBall->y + BilliardBall->radius);
	SetPenSize(0.5);
	DrawArc(BilliardBall->radius, 90, 360);
	EndFilledRegion();

	if (BilliardBall->id == 1)
		return;
	if (BilliardBall->id > 9) {
		SetPenColor("White");
		StartFilledRegion(1);
		MovePen(BilliardBall->x + BilliardBall->radius / 2, BilliardBall->y - BilliardBall->radius*sin(PI / 3));
		SetPenSize(1);
		DrawArc(BilliardBall->radius, -60, 120);
		DrawLine(0, -BilliardBall->radius);
		EndFilledRegion();

		StartFilledRegion(1);
		MovePen(BilliardBall->x - BilliardBall->radius / 2, BilliardBall->y + BilliardBall->radius*sin(PI / 3));
		SetPenSize(1);
		DrawArc(BilliardBall->radius, 120, 120);
		DrawLine(0, BilliardBall->radius);
		EndFilledRegion();
	}
	SetPenColor("Black");
	MovePen(BilliardBall->x, BilliardBall->y + BilliardBall->radius);
	SetPenSize(2);
	DrawArc(BilliardBall->radius, 90, 360);

	if (BilliardBall->v) {
		return;
	}
	SetPenColor("White");
	StartFilledRegion(1);
	MovePen(BilliardBall->x + BilliardBall->radius / 2, BilliardBall->y);
	DrawArc(BilliardBall->radius / 2, 0, 360);
	EndFilledRegion();
	SetPenColor("Black");
	SetPointSize(2);
	MovePen(BilliardBall->x - TextStringWidth(num) / 2, BilliardBall->y - GetFontHeight() / 2.5);
	DrawTextString(num);
}

void ShowAllBilliardBall(billiardball * BallList)
{
	switch (BilliardbMode) {
	case SNOOKER:
		while (BallList) {
			ShowSnookerBilliard(BallList);
			BallList = BallList->next;
		}
		break;
	case SIDE_POCKET:
		while (BallList) {
			ShowSidePocketBilliard(BallList);
			BallList = BallList->next;
		}
		break;
	case AMERICAN:
		while (BallList) {
			ShowAmericanBilliard(BallList);
			BallList = BallList->next;
		}
		break;
	case ENTERTAINMENT:
		while (BallList) {
			ShowAmericanBilliard(BallList);
			BallList = BallList->next;
		}
		break;
	}
}