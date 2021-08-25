//===========================================================================
//
//  ��Ȩ�����ߣ� �����裬���ݶ�
//  ��;������ѧϰʹ��
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



#define T 0.0002 //ˢ�¼��
#define A (FrictionFlag?-25000:-15000)//�����С
#define CUELENGTH 10 //��˳���



//��Ϸģʽ
enum billiardbmode
{
	SNOOKER,
	SIDE_POCKET,
	AMERICAN,
	ENTERTAINMENT
};


//��״̬
enum BilliardBallState
{
	INHOLE,
	OUTHOLE
};


//��Ҳ���״̬
enum 
{
	PA,//���A����״̬
	PAWAITING,//�ȴ�����״̬
	PB,//���B����״̬
	PBWAITING,
	GAMEOVE//��Ϸ����״̬
};


//˹ŵ����Ϸ״̬
enum 
{
	REDBALLOUT,
	REDBALLIN
};




//̨��ڵ�
typedef struct billiardballnode
{
	double radius;//��İ뾶
	double x;//λ������
	double y;
	double angle;//����
	double v;//�ٶ�
	int id;
	int state;//�����ϣ�����
	struct billiardballnode * next;
}billiardball;


//��Ϸ��Ϣ
typedef struct billiardimformation 
{
	int Player;
	int score[2];
	int BilliardbMode;
	int GameState;
	int GameProcess;
	int RuleFlag;
	struct billiardballnode* BallList;//ʹ������ָ��ͨ���ڸ�����Ϸģʽ����ͬ��Ϸģʽ̨����ʽ��ͬ�����Ҽ��ٽṹ���ڴ�
} gameimfor;


//������Ϣ�ڵ�
typedef struct ballinode
{
	struct billiardballnode * BilliardBall;
	struct ballinode  * next;
}ballin;




extern int Player, score[2], BilliardbMode, StrengthFlag, FrictionFlag;
//���ڴ浵
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

 //����һ��̨��ڵ�
billiardball * InitialBilliardBall(double radius, double x, double y, double angle, double v, int id, int state);

 //����̨����Ϣ
billiardball * InitialBilliardBall(double radius, double x, double y, double angle, double v, int id, int state);

billiardball * InitialSnookerBallList(void);

billiardball * InitialAmericanBallList(void);

//ɾ��̨������
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
 //�ԣ�x,y��Ϊ���ģ���һ���Ƕ�Ϊangle,��ʽΪstyle�����
void InitialTableColor(void);
void InitialTable(void);
void ShowBilliardTable(double x, double y, int style);
void ShowBilliardCue(double x, double y, double angle, int style);
void ShowSightLine(double x1, double y1, double x2, double y2, int style);



/*
 * showbilliardball
 * ----------------------------------------------------------------------------------------------------------
 */

 //����˹������ʽ̨��
void ShowSnookerBilliard(billiardball * BilliardBall);

//��ʾSidePocket��ʽ��̨��
void ShowSidePocketBilliard(billiardball * BilliardBall);

void ShowAmericanBilliard(billiardball * BilliardBall);

void ShowAllBilliardBall(billiardball * BallList);



/*
 * billiardrules
 * ----------------------------------------------------------------------------------------------------------
 */

 //��ʼ����Ϸ������״̬����
void InitialRule(void);

void AddBallInList(struct billiardballnode * BilliardBall);

static void ResetBall(struct billiardballnode * BilliardBall);

int ComputeSnookerScore(void);

void ChangeSnookerState(void);

//�Ʒ�
int ComputeSidePocketScore(void);

//�ı�SidePocket״̬���ĸ�״̬��PA����״̬��PA�غ����˶�״̬��PB����״̬��PB�غ����˶�״̬
void ChangeSidePocketState(void);

//�Ʒ�
int ComputeAmericanScore(void);

//�ı�American״̬���ĸ�״̬��PA����״̬��PA�غ����˶�״̬��PB����״̬��PB�غ����˶�״̬
void ChangeAmericanState(void);

//Entertain�Ʒ�
int ComputeEntertainScore(void);

//�ı�Entertain״̬���ĸ�״̬��PA����״̬��PA�غ����˶�״̬��PB����״̬��PB�غ����˶�״̬
void ChangeEntertainState(void);



/*
 * billiards
 * ----------------------------------------------------------------------------------------------------------
 */

//��ʼ���ṹ�壬ʹָ����ָ��ĵط�
void InitialGameImfor(void);
//��Ϸ��Ϣ���뻺����
void SaveGameImfor(void);
//�ӻ��������ȡ��Ϣ
void ReadGameImfor(void);

void SaveImfor(void); // �浵

void LoadImfor(void);// ����



#endif