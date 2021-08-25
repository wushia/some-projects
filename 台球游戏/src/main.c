//===========================================================================
//
//  版权所有者： 吕蓝翔，李逸东
//  用途：仅供学习使用
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
#define CURSOR 2 //光标计数器序号




extern HINSTANCE hInst;


double cx=0, cy=0;
// 用户的鼠标事件响应函数
double MouseX=8;
double MouseY=6;
int MouseButton, MouseEvent, KeyPress, KeyEvent;
void KeyboardEventProcess(int key, int event);
void MouseEventProcess(int x, int y, int button, int event);
void TimerEventProcess(int timerID);
void CharEventProcess(char ch);




/* 仅初始化执行一次 */
void Main()
{
	SetWindowSize(16, 12);
	InitGraphics();// 图形初始化
	cx = GetWindowWidth() / 2; cy = GetWindowHeight() / 2;

	InitialBallList();
	InitialTableColor();
	InitialButton(ButtonList);
	InitialOpeningPage();

	SetWindowTitle("台球游戏");
	SetPenSize(1);      // 设置画笔粗细

	registerTimerEvent(TimerEventProcess);      // 定时器
	registerMouseEvent(MouseEventProcess);      // 鼠标
	registerKeyboardEvent(KeyboardEventProcess);// 键盘
	registerCharEvent(CharEventProcess);
	startTimer(REFRESH, T);// 设置光标闪烁频率
	startTimer(CURSOR, 200);// 设置光标闪烁频率
	
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
 * 函数: KeyboardEventProcess
 * 用法: KeyboardEventProcess(int key, int event)
 * -----------------------------------
 * 此函数将键盘响应的数据传给，KeyPress和KeyEvent，并依据新数据重新绘制整图
 */
void KeyboardEventProcess(int key, int event)
{
	KeyPress = key;
	KeyEvent = event;
	uiGetKeyboard(key, event);
}



void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI字符输入
}



