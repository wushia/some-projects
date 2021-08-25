//===========================================================================
//
//  版权所有者： 吕蓝翔，李逸东
//  用途：仅供学习使用
//
//===========================================================================
#ifndef __BILLIARDS_H__
#define __BILLIARDS_H__

#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"billiards.h"
#include "sundry.h"



#define T 0.0002 //刷新间隔
#define A (FrictionFlag?-25000:-15000)//阻尼大小
#define CUELENGTH 10 //球杆长度



//游戏模式
enum billiardbmode
{
	SNOOKER,
	SIDE_POCKET,
	AMERICAN,
	ENTERTAINMENT
};


//球状态
enum BilliardBallState
{
	INHOLE,
	OUTHOLE
};


//玩家操作状态
enum 
{
	PA,//玩家A操作状态
	PAWAITING,//等待进球状态
	PB,//玩家B操作状态
	PBWAITING,
	GAMEOVE//游戏结束状态
};


//斯诺克游戏状态
enum 
{
	REDBALLOUT,
	REDBALLIN
};




//台球节点
typedef struct billiardballnode
{
	double radius;//球的半径
	double x;//位置坐标
	double y;
	double angle;//弧度
	double v;//速度
	int id;
	int state;//在桌上，进球
	struct billiardballnode * next;
}billiardball;


//游戏信息
typedef struct billiardimformation 
{
	int Player;
	int score[2];
	int BilliardbMode;
	int GameState;
	int GameProcess;
	int RuleFlag;
	struct billiardballnode* BallList;//使用链表指针通用于各种游戏模式（不同游戏模式台区格式不同），且减少结构体内存
} gameimfor;


//进球信息节点
typedef struct ballinode
{
	struct billiardballnode * BilliardBall;
	struct ballinode  * next;
}ballin;




extern int Player, score[2], BilliardbMode, StrengthFlag, FrictionFlag;
//用于存档
extern double BallRadius;
extern billiardball *BallList;
extern int GameState, GameProcess, RuleFlag;
extern ballin * BallInList;
extern double TableWidth, TableHeight, HoleRadius;
extern double CueAngle;




/*
 * initialbilliardball
 * ----------------------------------------------------------------------------------------------------------
 */

 //创建一个台球节点
billiardball * InitialBilliardBall(double radius, double x, double y, double angle, double v, int id, int state);

 //填入台球信息
billiardball * InitialBilliardBall(double radius, double x, double y, double angle, double v, int id, int state);

billiardball * InitialSnookerBallList(void);

billiardball * InitialAmericanBallList(void);

//删除台球链表
void ResetBallList(void);

void InitialBallList(void);



/*
 * billiardball
 * ----------------------------------------------------------------------------------------------------------
 */

double GetBallsDistance(billiardball * BilliardBall_1, billiardball * BilliardBall_2);

void HitAllBilliardBall(billiardball *  BallList);

void ReboundAllBilliardBall(billiardball *  BallList);

void MoveAllBilliard(billiardball *  BallList);

int IFValidClick(void);

int IfStop(billiardball * BilliardList);

int IfInHole(billiardball * BilliardBall);

void HitWhiteBall(void);


/*
 * billiardtable
 * ----------------------------------------------------------------------------------------------------------
 */
 //以（x,y）为中心，画一个角度为angle,样式为style的球杆
void InitialTableColor(void);
void InitialTable(void);
void ShowBilliardTable(double x, double y, int style);
void ShowBilliardCue(double x, double y, double angle, int style);
void ShowSightLine(double x1, double y1, double x2, double y2, int style);



/*
 * showbilliardball
 * ----------------------------------------------------------------------------------------------------------
 */

 //绘制斯若克形式台球
void ShowSnookerBilliard(billiardball * BilliardBall);

//显示SidePocket形式的台球
void ShowSidePocketBilliard(billiardball * BilliardBall);

void ShowAmericanBilliard(billiardball * BilliardBall);

void ShowAllBilliardBall(billiardball * BallList);



/*
 * billiardrules
 * ----------------------------------------------------------------------------------------------------------
 */

 //初始化游戏过程中状态变量
void InitialRule(void);

void AddBallInList(struct billiardballnode * BilliardBall);

static void ResetBall(struct billiardballnode * BilliardBall);

int ComputeSnookerScore(void);

void ChangeSnookerState(void);

//计分
int ComputeSidePocketScore(void);

//改变SidePocket状态，四个状态，PA操作状态，PA回合球运动状态，PB操作状态，PB回合球运动状态
void ChangeSidePocketState(void);

//计分
int ComputeAmericanScore(void);

//改变American状态，四个状态，PA操作状态，PA回合球运动状态，PB操作状态，PB回合球运动状态
void ChangeAmericanState(void);

//Entertain计分
int ComputeEntertainScore(void);

//改变Entertain状态，四个状态，PA操作状态，PA回合球运动状态，PB操作状态，PB回合球运动状态
void ChangeEntertainState(void);



/*
 * billiards
 * ----------------------------------------------------------------------------------------------------------
 */

//初始化结构体，使指针有指向的地方
void InitialGameImfor(void);
//游戏信息存入缓存区
void SaveGameImfor(void);
//从缓存区里读取信息
void ReadGameImfor(void);

void SaveImfor(void); // 存档

void LoadImfor(void);// 读档



#endif