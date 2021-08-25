#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"billiards.h"
#include "sundry.h"
#include"button.h"
#include"music.h"




//定义一个台球链表
billiardball *BallList = NULL;
//创建一个台球节点
billiardball * InitialBilliardBall(double radius, double x, double y, double angle, double v, int id, int state)
{
	billiardball *BilliardBall = (billiardball *)malloc(sizeof(billiardball));
	BilliardBall->radius = radius;
	BilliardBall->x = x;
	BilliardBall->y = y;
	BilliardBall->angle = angle;
	BilliardBall->v = v;
	BilliardBall->id = id;
	BilliardBall->state = state;
	BilliardBall->next = NULL;
	return BilliardBall;
}



//删除台球链表
void ResetBallList(void) 
{
	billiardball * head = BallList;
	while (head) 
	{
		head = BallList->next;
		free(BallList);
		BallList = head;
	}
}
//初始化斯诺克台球信息，即创建链表，填入信息
billiardball * InitialSnookerBallList(void)
{
	TableWidth = 12, TableHeight = 6;
	billiardball *head, *BilliardBall;
	head = InitialBilliardBall(BallRadius, cx - TableWidth / 2 + 2.9, cy - 4 * BallRadius, 0, 0, 1, OUTHOLE);
	BilliardBall = head;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2 * BallRadius - 2.9, cy, 0, 0, 2, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9, cy + BallRadius, 0, 0, 3, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9, cy - BallRadius, 0, 0, 4, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 2 * BallRadius, cy + 2 * BallRadius, 0, 0, 5, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 2 * BallRadius, cy, 0, 0, 6, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 2 * BallRadius, cy - 2 * BallRadius, 0, 0, 7, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 4 * BallRadius, cy + 3 * BallRadius, 0, 0, 8, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 4 * BallRadius, cy + BallRadius, 0, 0, 9, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 4 * BallRadius, cy - BallRadius, 0, 0, 10, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 4 * BallRadius, cy - 3 * BallRadius, 0, 0, 11, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 6 * BallRadius, cy + 4 * BallRadius, 0, 0, 12, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 6 * BallRadius, cy + 2 * BallRadius, 0, 0, 13, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 6 * BallRadius, cy, 0, 0, 14, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 6 * BallRadius, cy - 2 * BallRadius, 0, 0, 15, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.9 + 6 * BallRadius, cy - 4 * BallRadius, 0, 0, 16, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx - TableWidth / 2 + 2.9, cy, 0, 0, 17, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx - TableWidth / 2 + 2.9, cy - 8 * BallRadius, 0, 0, 18, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx - TableWidth / 2 + 2.9, cy + 8 * BallRadius, 0, 0, 19, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx, cy, 0, 0, 20, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.97 - 4 * BallRadius, cy, 0, 0, 21, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 2 - 2.8 + 8 * BallRadius, cy, 0, 0, 22, OUTHOLE);
	return head;

}



billiardball * InitialSidePocketBallList(void)
{
	TableWidth = 10.8; TableHeight = 6;
	BallRadius = 0.18;
	billiardball *head, *BilliardBall;
	head = InitialBilliardBall(BallRadius, cx - TableWidth / 4, cy, 0, 0, 1, OUTHOLE);
	BilliardBall = head;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4, cy, 0, 0, 2, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + BallRadius * sqrt(3), cy - BallRadius, 0, 0, 3, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + BallRadius * sqrt(3), cy + BallRadius, 0, 0, 4, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 2 * BallRadius * sqrt(3), cy - 2 * BallRadius, 0, 0, 5, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 2 * BallRadius * sqrt(3), cy, 0, 0, 6, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 2 * BallRadius * sqrt(3), cy + 2 * BallRadius, 0, 0, 7, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 3 * BallRadius * sqrt(3), cy - BallRadius, 0, 0, 8, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 3 * BallRadius * sqrt(3), cy + BallRadius, 0, 0, 9, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 4 * BallRadius * sqrt(3), cy, 0, 0, 10, OUTHOLE);
	return head;
}




billiardball * InitialAmericanBallList(void)
{
	TableWidth = 12, TableHeight = 6;
	BallRadius = 0.2;
	billiardball *head, *BilliardBall;
	head = InitialBilliardBall(BallRadius, cx - TableWidth / 4, cy, 0, 0, 1, OUTHOLE);
	BilliardBall = head;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 - 2 * BallRadius, cy, 0, 0, 2, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4, cy + BallRadius, 0, 0, 3, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4, cy - BallRadius, 0, 0, 4, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 2 * BallRadius, cy + 2 * BallRadius, 0, 0, 5, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 2 * BallRadius, cy, 0, 0, 6, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 2 * BallRadius, cy - 2 * BallRadius, 0, 0, 7, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 4 * BallRadius, cy + 3 * BallRadius, 0, 0, 8, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 4 * BallRadius, cy + BallRadius, 0, 0, 9, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 4 * BallRadius, cy - BallRadius, 0, 0, 10, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 4 * BallRadius, cy - 3 * BallRadius, 0, 0, 11, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 6 * BallRadius, cy + 4 * BallRadius, 0, 0, 12, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 6 * BallRadius, cy + 2 * BallRadius, 0, 0, 13, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 6 * BallRadius, cy, 0, 0, 14, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 6 * BallRadius, cy - 2 * BallRadius, 0, 0, 15, OUTHOLE);
	BilliardBall = BilliardBall->next;
	BilliardBall->next = InitialBilliardBall(BallRadius, cx + TableWidth / 4 + 6 * BallRadius, cy - 4 * BallRadius, 0, 0, 16, OUTHOLE);
	BilliardBall = BilliardBall->next;
	return head;
}



//初始化
void InitialBallList(void)
{
	ResetBallList();
	switch (BilliardbMode) 
	{
	case SNOOKER:
		BallList = InitialSnookerBallList();
		TableWidth = 12, TableHeight = 6;
		break;
	case SIDE_POCKET:
		BallList = InitialSidePocketBallList();
		TableWidth = 10.8; TableHeight = 6;
		break;
	case AMERICAN:
		BallList = InitialAmericanBallList();
		TableWidth = 11; TableHeight = 6;
		break;
	case ENTERTAINMENT:
		BallList = InitialAmericanBallList();
		TableWidth = 11; TableHeight = 6;
		break;
	}
}