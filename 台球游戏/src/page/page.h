//===========================================================================
//
//  版权所有者： 吕蓝翔，李逸东
//  用途：仅供学习使用
//
//===========================================================================
#ifndef __PAGE_H__
#define __PAGE_H__
#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include "sundry.h"
#include <math.h>
#include"button.h"
#include "imgui.h"


enum {
	OPENINGPAGE,//开场动画
	LOGINPAGE,//登录页面
	REGISTERPAGE,//注册页面
	HOMEPAGE,//主页
	GAMEPAGE,//斯诺克游戏界
	MENUPAGE,                                            //NEW
	SETTINGPAGE,//设置页面
	ACCOUNTPAGE
};

enum Login_State {
	PASSWORD_CORRECT,//密码正确
	PASSWORD_ERROR,
	UNREGISTER,
	NOINPUT
};

enum Register_State {
	REGISTER_SUCCESS,
	USER_REGISTERED
};
extern int PageMode, SaveFlag;//页面模式
extern char Password[10], UserName[5];
extern bool isShowLine;


extern char* Users[10];
extern char* Passwords[10];
extern char Password[10] ;//密码
extern char UserName[5] ;//账号
extern char NewName[5] ;
extern char NewPassword[10] ;
extern int NewUserNum;
extern int UserNum;

void ShowLoginPage(void);
void ShowHomePage(void);
void ShowRegisterPage(void);
void ShowGamePage(void);

void ShowMenuPage(void);                                  //NEW

void ShowSettingPage(void);
void ShowPage(int timerID);


#endif