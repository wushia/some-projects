//===========================================================================
//
//  ��Ȩ�����ߣ� �����裬���ݶ�
//  ����ѧϰʹ��
//
//===========================================================================
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>

#define BUTTONTOTALNUMBER 34 // ��ť������

// ���尴ť��������
typedef struct {
	double width;// ��ť��
	double height;// ��ť��
	double x;// ��ť����λ��
	double y;
	char str[20];// ��ʾ���ַ���
	int state;// ��ʱ��״̬��δѡ�С��������������
	int style;// ��ť����ʽ��������ť��������ʲô����

}mybutton;
// ��ť��ʽSNOOKER
enum ButtonStyle
{
	STYLERED,
	STYLEDARK,
	STYLEGREY,
	STYLEBLUE,
	ONOFF,
	HIGHLOW
};

enum ButtonState
{
	NORMAL,// ����δ��ѡ��
	CLICK,// �����ʱ
	ACTIVE// ��������ڰ�ť֮��
};
//��ť��ţ��ͳ�ʼ����ť��Ӧ,��������Ϊ����д�İ�ť����_��š�
enum ButtonNumber 
{
	//��ҳ��
	SNOOKER_BUTTON=0,
	SIDEPOCKET_BUTTON,
	AMERICAN_BUTTON,
	ENTERTAINMENT_BUTTON,
	NEWGAME,
	LOADGAME,
	SETTING_HPAGE,
	//�˵�ҳ��
	MENU,
	CONTINUE,
	RESTART,
	SAVE,
	LOAD,
	SETTING_MPAGE,
	RETURN_TO_HOME,
	EXIT,
	//����ҳ��
	SETTING_SPAGE,
	SOUND,
	SOUND_ONOFF,
	FRICTION,
	FRICTION_HIGHT_LOW,
	GUIDE_LINE,
	GUIDE_LINE_ON_OFF,
	STRENGTH,
	STRENGTH_HIGH_LOW,
	CHANGE_ACCOUNT,
	CLOSE_ACCOUNTS,
	RETURN,
	//��¼ҳ��
	LOGIN,
	REGISTER_LPAGE,
	VISITOR,
	//ע��ҳ��
	REGISTER_RPAGE,
	CANCEL,
	//��Ϸҳ��
	OPTIONS,
	REGRET,
	

};
extern mybutton ButtonList[BUTTONTOTALNUMBER];
extern int ButtonIndex;
// ����һ����ť����

void InitButtonColors(void);

// ��ʼ�����а�ť����������Ϣ
void InitialButton(mybutton* ButtonList);

// �ж����ѡ�����ĸ���ť,����ѡ�У�����-1
int SelectWhichButton(double x, double y);

// ����button��style����һ��û��ѡ�еİ�ť

void ShowNormalButton(mybutton* ButtonInstance);


// ����button��style����һ��������İ�ť
void ShowClickButton(mybutton* ButtonInstance);


// ����button��style����һ����������ڰ�ťʱ�İ�ť
void ShowActiveButton(mybutton* ButtonInstance);


// ������ʽ��ѡ��״̬����һ����ť
void ShowButton(mybutton* ButtonInstance);

// ������ʽ��ѡ��״̬,�ʹ�ʱ��ҳ��״̬�������ҳ�����еİ�ť
void ShowPageButton(mybutton* ButtonInstance, int page);

void ButtonActive(double x, double y, int button, int event);

#endif // !__BUTTON_H__
