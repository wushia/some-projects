//===========================================================================
//
//  ��Ȩ�����ߣ� �����裬���ݶ�
//  ��;������ѧϰʹ��
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
	OPENINGPAGE,//��������
	LOGINPAGE,//��¼ҳ��
	REGISTERPAGE,//ע��ҳ��
	HOMEPAGE,//��ҳ
	GAMEPAGE,//˹ŵ����Ϸ��
	MENUPAGE,                                            //NEW
	SETTINGPAGE,//����ҳ��
	ACCOUNTPAGE
};

enum Login_State {
	PASSWORD_CORRECT,//������ȷ
	PASSWORD_ERROR,
	UNREGISTER,
	NOINPUT
};

enum Register_State {
	REGISTER_SUCCESS,
	USER_REGISTERED
};
extern int PageMode, SaveFlag;//ҳ��ģʽ
extern char Password[10], UserName[5];
extern bool isShowLine;


extern char* Users[10];
extern char* Passwords[10];
extern char Password[10] ;//����
extern char UserName[5] ;//�˺�
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