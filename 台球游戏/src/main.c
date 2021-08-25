//===========================================================================
//
//  ��Ȩ�����ߣ� �����裬���ݶ�
//  ��;������ѧϰʹ��
//
//===========================================================================
#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sundry.h"
#include <math.h>
#include "page.h"
#include"music.h"
#include"billiards.h"
#include "button.h"



#define REFRESH 1
#define CURSOR 2 //�����������




extern HINSTANCE hInst;


double cx=0, cy=0;
// �û�������¼���Ӧ����
double MouseX=8;
double MouseY=6;
int MouseButton, MouseEvent, KeyPress, KeyEvent;
void KeyboardEventProcess(int key, int event);
void MouseEventProcess(int x, int y, int button, int event);
void TimerEventProcess(int timerID);
void CharEventProcess(char ch);




/* ����ʼ��ִ��һ�� */
void Main()
{
	SetWindowSize(16, 12);
	InitGraphics();// ͼ�γ�ʼ��
	cx = GetWindowWidth() / 2; cy = GetWindowHeight() / 2;

	InitialBallList();
	InitialTableColor();
	InitialButton(ButtonList);
	InitialOpeningPage();

	SetWindowTitle("̨����Ϸ");
	SetPenSize(1);      // ���û��ʴ�ϸ

	registerTimerEvent(TimerEventProcess);      // ��ʱ��
	registerMouseEvent(MouseEventProcess);      // ���
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerCharEvent(CharEventProcess);
	startTimer(REFRESH, T);// ���ù����˸Ƶ��
	startTimer(CURSOR, 200);// ���ù����˸Ƶ��
	
	ShowBilliardTable(cx, cy, SNOOKER);
	IntialSound();
	mciSendString("play .\\data\\music\\bgm.mp3 repeat", NULL, 0, NULL);
}



void MouseEventProcess(int x, int y, int button, int event)
{

	MouseX = ScaleXInches(x);
	MouseY = ScaleYInches(y);
	MouseButton = button;
	MouseEvent = event;
	CueAngle = atan2((MouseY - BallList->y), (MouseX - BallList->x));

	uiGetMouse(x, y, button, event);

	ButtonActive(MouseX, MouseY, MouseButton, MouseEvent);
	
	HitWhiteBall();
}



void TimerEventProcess(int timerID)
{
	ShowPage(timerID);
}



/*
 * ����: KeyboardEventProcess
 * �÷�: KeyboardEventProcess(int key, int event)
 * -----------------------------------
 * �˺�����������Ӧ�����ݴ�����KeyPress��KeyEvent�����������������»�����ͼ
 */
void KeyboardEventProcess(int key, int event)
{
	KeyPress = key;
	KeyEvent = event;
	uiGetKeyboard(key, event);
}



void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
}



