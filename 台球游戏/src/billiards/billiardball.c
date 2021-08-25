#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"billiards.h"
#include "sundry.h"
#include"button.h"
#include"music.h"
#include "page.h"


double BallRadius = 0.18;//̨��뾶
double Loss = 0.9;//������ʧ



/*
 * ����: GetNextCoordinates
 * �÷�: GetNextCoordinates(billiardball * BilliardBall, double * x, double * y) 
 * ---------------------------------------
 * ��ȡ̨����һ������
 */
static void GetNextCoordinates(billiardball * BilliardBall, double *x, double * y) 
{
	if ((T * A + BilliardBall->v) <= 0)
	{
		*x = BilliardBall->v*cos(BilliardBall->angle)*BilliardBall->v*cos(BilliardBall->angle) / 2 / A + BilliardBall->x;
		*y = BilliardBall->v*sin(BilliardBall->angle)*BilliardBall->v*sin(BilliardBall->angle) / 2 / A + BilliardBall->y;
		return;
	}
	*x = T * T*A / 2 * cos(BilliardBall->angle) + BilliardBall->v*T*cos(BilliardBall->angle) + BilliardBall->x;
	*y = T * T*A / 2 * sin(BilliardBall->angle) + BilliardBall->v*T*sin(BilliardBall->angle) + BilliardBall->y;
}



/*
 * ����: MoveBilliard
 * �÷�: MoveBilliard(billiardball * BilliardBall)
 * ---------------------------------------
 * ʹ����̨���˶�
 */
static void MoveBilliard(billiardball * BilliardBall)
{
	if (IfInHole(BilliardBall) != -1)
	{	//��һ�ν���
		if (BilliardBall->state == OUTHOLE) 
		{
			BilliardBall->state = INHOLE;
			BilliardBall->v = 0;
			BilliardBall->angle = 0;
			AddBallInList(BilliardBall);//��������
		}
	}
	//��һ�̻�ֹͣ
	if ((T * A + BilliardBall->v) <= 0)
	{
		BilliardBall->v = 0;
		BilliardBall->angle = 0;
		GetNextCoordinates(BilliardBall, &BilliardBall->x, &BilliardBall->y);
		return;
	}

	GetNextCoordinates(BilliardBall, &BilliardBall->x, &BilliardBall->y);
	BilliardBall->v = T * A + BilliardBall->v;
}



/*
 * ����: MoveAllBilliard
 * �÷�: MoveAllBilliard(billiardball *  BallList)
 * ---------------------------------------
 * �ƶ����е���
 */
void MoveAllBilliard(billiardball *  BallList)
{
	while (BallList) 
	{
		MoveBilliard(BallList);
		BallList = BallList->next;
	}
}



/*
 * ����: MoveAllBilliard
 * �÷�: MoveAllBilliard(billiardball *  BallList)
 * ---------------------------------------
 * �ƶ����е���
 */
void HitWhiteBall(void)
{
	if (PageMode != GAMEPAGE)
		return;

	if ( IfStop(BallList) && MouseEvent == BUTTON_DOWN && IFValidClick()) 
	{
		SaveGameImfor();
		PlaySoundEffect();
		//PlaySoundEffect(POOLTOBALL);
		BallList->v = sqrt(DISTANCE(MouseX, MouseY, BallList->x, BallList->y)) > 2 ? 800 : 300 * sqrt(DISTANCE(MouseX, MouseY, BallList->x, BallList->y));
		BallList->angle = PI + CueAngle;
		ShowBilliardCue(BallList->x + (MouseX - BallList->x) * 0.2, BallList->y + (MouseY - BallList->y) * 0.2, CueAngle * 180 / PI, 1);
		ShowBilliardCue(BallList->x + (MouseX - BallList->x) * 0.1, BallList->y + (MouseY - BallList->y) * 0.1, CueAngle * 180 / PI, 1);
		ShowBilliardCue(BallList->x, BallList->y, CueAngle * 180 / PI, 1);
	}
	if (IfStop(BallList)) {
		SaveFlag = 1;
	}
}



/*
 * ����: ReboundBilliardBall
 * �÷�: ReboundBilliardBall(billiardball * BilliardBall)
 * ---------------------------------------
 * ����һ����
 */
static void ReboundBilliardBall(billiardball * BilliardBall)
{
	double x, y, l = 0;
	GetNextCoordinates(BilliardBall, &x, &y);

	if ((l = LineDistance(-PI / 4, cx - TableWidth / 2 + 0.5, cy + TableHeight / 2 - 0.9, x, y)) <= BilliardBall->radius && x <= cx - TableWidth / 2 + 0.5)
	{
		BilliardBall->angle = 3 * PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(PI / 4);
		return;
	}
	if ((l = LineDistance(-PI / 4, cx - TableWidth / 2 + 0.7, cy + TableHeight / 2 - 0.3, x, y)) <= BilliardBall->radius && x <= cx - TableWidth / 2 + 0.9)
	{
		BilliardBall->angle = 3 * PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(5 * PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(5 * PI / 4);
		return;
	}
	if ((l = LineDistance(PI / 4, cx + TableWidth / 2 - 0.7, cy + TableHeight / 2 - 0.3, x, y)) <= BilliardBall->radius && x >= cx + TableWidth / 2 - 0.9)
	{
		BilliardBall->angle = PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(-PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(-PI / 4);
		return;
	}
	if ((l = LineDistance(PI / 4, cx + TableWidth / 2 - 0.5, cy + TableHeight / 2 - 0.9, x, y)) <= BilliardBall->radius && x >= cx + TableWidth / 2 - 0.5)
	{
		BilliardBall->angle = PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(3 * PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(3 * PI / 4);
		return;
	}
	if ((l = LineDistance(-PI / 4, cx + TableWidth / 2 - 0.5, cy - TableHeight / 2 + 0.9, x, y)) <= BilliardBall->radius && x >= cx + TableWidth / 2 - 0.5)
	{
		BilliardBall->angle = 3 * PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(5 * PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(5 * PI / 4);
		return;
	}
	if ((l = LineDistance(-PI / 4, cx + TableWidth / 2 - 0.7, cy - TableHeight / 2 + 0.3, x, y)) <= BilliardBall->radius &&x >= cx + TableWidth / 2 - 0.9)
	{
		BilliardBall->angle = 3 * PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(PI / 4);
		return;
	}
	if ((l = LineDistance(PI / 4, cx - TableWidth / 2 + 0.5, cy - TableHeight / 2 + 0.9, x, y)) <= BilliardBall->radius && x <= cx - TableWidth / 2 + 0.5)
	{
		BilliardBall->angle = PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(-PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(-PI / 4);
		return;
	}
	if ((l = LineDistance(PI / 4, cx - TableWidth / 2 + 0.7, cy - TableHeight / 2 + 0.3, x, y)) <= BilliardBall->radius && x <= cx - TableWidth / 2 + 0.9)
	{
		BilliardBall->angle = PI / 2 - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + (BilliardBall->radius - l)*cos(3 * PI / 4);
		BilliardBall->y = BilliardBall->y + (BilliardBall->radius - l)*sin(3 * PI / 4);
		return;
	}

	if (x <= cx + 0.25 && x >= cx - 0.25)
	{
		return;
	}


	if ((l = x - cx + TableWidth / 2 - 0.5) <= BilliardBall->radius  && y <= cy + TableHeight / 2 - 0.9 &&  y >= cy - TableHeight / 2 + 0.9)
	{
		BilliardBall->angle = PI - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x + BilliardBall->radius - l;

	}
	else if ((l = x - cx - TableWidth / 2 + 0.5) >= -BilliardBall->radius && y <= cy + TableHeight / 2 - 0.9 &&  y >= cy - TableHeight / 2 + 0.9)
	{
		BilliardBall->angle = -PI - BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->x = BilliardBall->x - BilliardBall->radius - l;
	}
	else if ((l = y - cy - TableHeight / 2 + 0.5) >= -BilliardBall->radius && x <= cx + TableWidth / 2 - 0.9 && x >= cx - TableWidth / 2 + 0.9)
	{
		BilliardBall->angle = -BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->y = BilliardBall->y - BilliardBall->radius - l;
	}
	else if ((l = y - cy + TableHeight / 2 - 0.5) <= BilliardBall->radius && x <= cx + TableWidth / 2 - 0.9 && x >= cx - TableWidth / 2 + 0.9)
	{
		BilliardBall->angle = -BilliardBall->angle;
		BilliardBall->v = Loss * BilliardBall->v;
		BilliardBall->y = BilliardBall->y + BilliardBall->radius - l;
	}

}



/*
 * ����: ReboundAllBilliardBall
 * �÷�: ReboundAllBilliardBall(billiardball *  BallList) 
 * ---------------------------------------
 * ����������
 */
void  ReboundAllBilliardBall(billiardball *  BallList) 
{
	while (BallList) 
	{
		ReboundBilliardBall(BallList);
		BallList = BallList->next;
	}
}


/*
 * ����: GetBallsDistance
 * �÷�: GetBallsDistance(billiardball * BilliardBall_1, billiardball * BilliardBall_2)
 * ---------------------------------------
 * ��ȡ��������
 */
double GetBallsDistance(billiardball * BilliardBall_1, billiardball * BilliardBall_2)
{
	double x, y, x1, y1, x2, y2;
	GetNextCoordinates(BilliardBall_1, &x1, &y1);
	GetNextCoordinates(BilliardBall_2, &x2, &y2);
	x = x2 - x1;
	y = y2 - y1;
	return sqrt(x*x + y * y);
}



/*
 * ����: HitBilliardBall
 * �÷�: HitBilliardBall(billiardball * BilliardBall_1, billiardball * BilliardBall_2)
 * ---------------------------------------
 * ʹ������ײ
 */
static void HitBilliardBall(billiardball * BilliardBall_1, billiardball * BilliardBall_2)
{
	if (!BilliardBall_1 || !BilliardBall_2) 
	{
		return;
	}

	double l = GetBallsDistance(BilliardBall_1, BilliardBall_2);

	if (l <= 2 * BilliardBall_1->radius && BilliardBall_1->state == OUTHOLE && BilliardBall_2->state == OUTHOLE)
	{

		double angle, vx, vy, ux, uy;
		angle = GetAngle(BilliardBall_1->x, BilliardBall_1->y, BilliardBall_2->x, BilliardBall_2->y);//pi/2
		vx = BilliardBall_1->v*cos(BilliardBall_1->angle - angle);//v
		vy = BilliardBall_1->v*sin(BilliardBall_1->angle - angle);//0
		ux = BilliardBall_2->v*cos(BilliardBall_2->angle - angle);//-v
		uy = BilliardBall_2->v*sin(BilliardBall_2->angle - angle);//0
		BilliardBall_1->angle = GetAngle(0, 0, ux, vy) + angle;//-pi/2
		BilliardBall_2->angle = GetAngle(0, 0, vx, uy) + angle;//pi/2
		BilliardBall_1->v = 0.99 * sqrt(ux*ux + vy * vy);
		BilliardBall_2->v = 0.99 * sqrt(vx*vx + uy * uy);
		BilliardBall_1->x = BilliardBall_1->x - (2 * BilliardBall_1->radius - l)*cos(angle) / 2;
		BilliardBall_1->y = BilliardBall_1->y - (2 * BilliardBall_1->radius - l)*sin(angle) / 2;
		BilliardBall_2->x = BilliardBall_2->x + (2 * BilliardBall_2->radius - l)*cos(angle) / 2;
		BilliardBall_2->y = BilliardBall_2->y + (2 * BilliardBall_2->radius - l)*sin(angle) / 2;
	}
}



/*
 * ����: HitAllBilliardBall
 * �÷�: HitAllBilliardBall(billiardball *  BallList)
 * ---------------------------------------
 * ��������ײ
 */
void HitAllBilliardBall(billiardball *  BallList)
{
	billiardball *  BallList_1 = BallList, *BallList_2 = BallList;
	while (BallList_1) 
	{
		BallList_2 = BallList;
		if (1 || BallList_1->v)
		{
			while (BallList_2)
			{
				if (BallList_1 == BallList_2)
				{
					BallList_2 = BallList_2->next;
					continue;
				}
				HitBilliardBall(BallList_1, BallList_2);
				BallList_2 = BallList_2->next;
			}
		}
		BallList_1 = BallList_1->next;
	}
}



/*
 * ����: IfInHole
 * �÷�: IfInHole(billiardball * BilliardBall)
 * ---------------------------------------
 * �ж��Ƿ��������ͬ����Ų�ͬ
 */
int IfInHole(billiardball * BilliardBall)
{
	double x, y;
	x = BilliardBall->x;
	y = BilliardBall->y;
	if (DISTANCE(x, y, cx - TableWidth / 2 + 0.4, TableHeight / 2 + cy - 0.4) < HoleRadius)
	{
		return 1;
	}
	if (DISTANCE(x, y, cx, TableHeight / 2 + cy - 0.3) < 0.25)
	{
		return 2;
	}
	if (DISTANCE(x, y, cx + TableWidth / 2 - 0.4, TableHeight / 2 + cy - 0.4) < HoleRadius)
	{
		return 3;
	}
	if (DISTANCE(x, y, cx + TableWidth / 2 - 0.4, -TableHeight / 2 + cy + 0.4) < HoleRadius)
	{
		return 4;
	}
	if (DISTANCE(x, y, cx, -TableHeight / 2 + cy + 0.3) < 0.25)
	{
		return 5;
	}
	if (DISTANCE(x, y, cx - TableWidth / 2 + 0.4, -TableHeight / 2 + cy + 0.4) < HoleRadius)
	{
		return 6;

	}
	return -1;

}


/*
 * ����: IfStop
 * �÷�: IfStop(billiardball * BilliardList) 
 * ---------------------------------------
 * �ж��Ƿ�̨��ȫ��ֹͣ
 */
int IfStop(billiardball * BilliardList) 
{
	while (BilliardList) 
	{
		if (BilliardList->v != 0)
			return 0;
		BilliardList = BilliardList->next;
	}
	return 1;
}



/*
 * ����: IFValidClick
 * �÷�: IFValidClick(void) 
 * ---------------------------------------
 * �жϻ�������Ƿ���Ч
 */
int IFValidClick(void) 
{
	if ( (ButtonIndex <= EXIT && ButtonIndex > -1) || ButtonIndex== OPTIONS|| ButtonIndex== REGRET)
	{
		return 0;
	}
	return 1;
}