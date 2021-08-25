#include <stdio.h>
#include "graphics.h"
#include "extgraph.h"
#include <windows.h>
#include<math.h>
#include"sundry.h"
#define pi 3.1415926535

enum {
	BallTimer = 3,
	CurtainTimer
};

static double x = 0, y = 0;
static double ShiverDis = 0.03;     //球的位移量
static double CurtainX = 0;         //黑幕位置(字显现)

static void DrawCue_Opening(double startx, double starty) 
{
	double direction = 20;
	DefineColor("Silver", 0.8, 0.8, 0.8);
	SetPenColor("Silver");
	StartFilledRegion(1);
	MovePen(startx, starty);
	forward(direction, 6.3);
	DrawArc(0.13, direction - 59.1, 120);
	forward(direction + 1.8, -6.3);
	DrawLine(startx - GetCurrentX(), starty - GetCurrentY());
	EndFilledRegion();


	startx -= 0.05;
	starty += 0.1;
	direction = 30;
	DefineColor("Silver", 0.8, 0.8, 0.8);
	SetPenColor("Silver");
	StartFilledRegion(1);
	MovePen(startx, starty);
	forward(direction, 6.3);
	DrawArc(0.13, direction - 59.1, 120);
	forward(direction + 1.8, -6.3);
	DrawLine(startx - GetCurrentX(), starty - GetCurrentY());
	EndFilledRegion();
}

static void DrawBall_Opening(double ballx, double bally)  //画中间的球
{
	MovePen(ballx + 0.5, bally + 0.26);
	SetPenColor("Red");
	StartFilledRegion(1);
	DrawArc(0.5, 0, 360);
	EndFilledRegion();

	MovePen(ballx, bally + 0.4);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawArc(0.2, 0, 360);
	EndFilledRegion();

	MovePen(ballx - 0.2, bally + 0.4);
	SetPenColor("Black");
	SetPenSize(4);
	DrawEllipticalArc(0.08, 0.07, -90, 360);
	MovePen(ballx - 0.2, bally + 0.42);
	DrawEllipticalArc(0.09, 0.07, 90, 360);
}

static void DrawLetterB(double sx, double sy) 
{
	MovePen(sx, sy);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.5, 0.7);
	EndFilledRegion();

	MovePen(sx + 0.1, sy + 0.1);
	SetPenColor("Black");
	StartFilledRegion(1);
	DrawBox(0.3, 0.2);
	EndFilledRegion();

	MovePen(sx + 0.1, sy + 0.4);
	StartFilledRegion(1);
	DrawBox(0.3, 0.2);
	EndFilledRegion();

	MovePen(sx + 0.4, sy + 0.3);
	StartFilledRegion(1);
	DrawBox(0.1, 0.1);
	EndFilledRegion();
}
static void DrawLetterA(double sx, double sy) 
{
	MovePen(sx, sy);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.5, 0.7);
	EndFilledRegion();

	MovePen(sx + 0.1, sy);
	SetPenColor("Black");
	StartFilledRegion(1);
	DrawBox(0.3, 0.3);
	EndFilledRegion();

	MovePen(sx + 0.1, sy + 0.4);
	StartFilledRegion(1);
	DrawBox(0.3, 0.2);
	EndFilledRegion();

}
static void DrawLetterR(double sx, double sy) 
{
	MovePen(sx, sy);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.5, 0.7);
	EndFilledRegion();

	MovePen(sx + 0.1, sy);
	SetPenColor("Black");
	StartFilledRegion(1);
	DrawBox(0.3, 0.3);
	EndFilledRegion();

	MovePen(sx + 0.1, sy + 0.4);
	StartFilledRegion(1);
	DrawBox(0.3, 0.2);
	EndFilledRegion();

	MovePen(sx + 0.4, sy + 0.3);
	StartFilledRegion(1);
	DrawBox(0.1, 0.1);
	EndFilledRegion();
}
static void DrawLetterD(double sx, double sy) 
{
	MovePen(sx, sy);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.5, 0.7);
	EndFilledRegion();

	MovePen(sx + 0.1, sy + 0.1);
	SetPenColor("Black");
	StartFilledRegion(1);
	DrawBox(0.3, 0.5);
	EndFilledRegion();

	MovePen(sx + 0.4, sy);
	StartFilledRegion(1);
	DrawBox(0.1, 0.1);
	EndFilledRegion();

	MovePen(sx + 0.4, sy + 0.6);
	StartFilledRegion(1);
	DrawBox(0.1, 0.1);
	EndFilledRegion();
}
static void DrawTitle1(double titlex, double titley) 
{

	DrawLetterB(titlex, titley);

	titlex += 0.7;            //I
	MovePen(titlex, titley);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.1, 0.7);
	EndFilledRegion();

	titlex += 0.3;               //L
	MovePen(titlex, titley);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.1, 0.7);
	EndFilledRegion();
	StartFilledRegion(1);
	DrawBox(0.5, 0.1);
	EndFilledRegion();

	titlex += 0.7;              //L
	MovePen(titlex, titley);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.1, 0.7);
	EndFilledRegion();
	StartFilledRegion(1);
	DrawBox(0.5, 0.1);
	EndFilledRegion();

	titlex += 0.7;            //I
	MovePen(titlex, titley);
	SetPenColor("White");
	StartFilledRegion(1);
	DrawBox(0.1, 0.7);
	EndFilledRegion();

	titlex += 0.3;
	DrawLetterA(titlex, titley);
	titlex += 0.7;
	DrawLetterR(titlex, titley);
	titlex += 0.7;
	DrawLetterD(titlex, titley);
}

static void Display() {
	double cx = x + GetWindowWidth() / 2;
	double cy = y + GetWindowHeight() / 2;
	DisplayClear();

	MovePen(x, y);
	SetPenColor("Black");
	StartFilledRegion(1);
	DrawBox(16, 12);
	EndFilledRegion();


	MovePen(cx, cy - 1.5);
	DefineColor("Yellow1", 0.8, 0.75, 0.23);
	SetPenColor("Yellow1");
	StartFilledRegion(1);
	DrawRoundTriangle(4, 0.6);    // 边长4+0.6*1.73*2=6.08，重心1.76
	EndFilledRegion();

	MovePen(cx, cy - 1.1);
	SetPenColor("Black");
	StartFilledRegion(1);
	DrawRoundTriangle(4, 0.2);
	EndFilledRegion();


	DrawCue_Opening(cx - 2, cy - 1);
	DrawBall_Opening(cx + ShiverDis, cy + ShiverDis);


	SetPenColor("White");
	MovePen(cx - TextStringWidth(" [PRESS LEFT_BUTTON TO START] ") / 2, cy - 2);
	DrawTextString(" [PRESS LEFT_BUTTON TO START] ");

	SetPenSize(1);
	DrawTitle1(cx - 2.3, cy - 3);

	MovePen(cx - 4 + CurtainX, cy - 3);
	StartFilledRegion(1);
	DrawBox(10, 0.73);
	EndFilledRegion();
}

void InitialOpeningPage(void)
{
	startTimer(BallTimer, 500);
	startTimer(CurtainTimer, 50);
}

void DisPlayOpeningPage(int  timerID)
{
	switch (timerID)
	{
	case BallTimer:

		ShiverDis *= -1;
		Display();
		break;

	case CurtainTimer:
		if (CurtainX < 20) {
			CurtainX += 0.1;
		}
		Display();
		break;
	}
}


