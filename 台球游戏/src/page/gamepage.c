#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include "page.h"
#include <string.h>
#include"billiards.h"
#include "sundry.h"
#include"button.h"
#include "imgui.h"

bool isShowLine = 1;


//ÏÔÊ¾ÓÎÏ·Ò³Ãæ
void ShowGamePage(void) 
{
	ShowBilliardTable(cx, cy, BilliardbMode);

	HitAllBilliardBall(BallList);

	ReboundAllBilliardBall(BallList);

	MoveAllBilliard(BallList);

	ShowAllBilliardBall(BallList);

	if (IfStop(BallList) && BallList->state == OUTHOLE)
	{
		ShowBilliardCue(BallList->x + (MouseX - BallList->x) * 0.3, BallList->y + (MouseY - BallList->y) * 0.3, CueAngle * 180 / PI, 1);
		if (isShowLine) 
			ShowSightLine(BallList->x, BallList->y, MouseX, MouseY, 1);
	}

	GameRule(BilliardbMode);
	ShowPageButton(ButtonList, GAMEPAGE);
}
