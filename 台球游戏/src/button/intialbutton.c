#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"button.h"
#include "page.h"
#include "boolean.h"




void InitButtonColors(void)
{
	DefineColor("LightBlue0", 0.33, 0.8, 0.78);
	DefineColor("eyellow", 0.98, 0.87, 0.43);
	DefineColor("LightGreen1", 0.28, 0.67, 0.46);
	DefineColor("PapayaWhip", 1, .85, .725);
	DefineColor("DarkGoldenrod2", .90, .70, .133);
	DefineColor("DarkGoldenrod3", .80, .620, .113);
	DefineColor("Red4", .63, 0, 0);
	DefineColor("Red3", .76, 0, 0);
	DefineColor("Red2", .92, 0, 0);
	DefineColor("PeachPuff", 1, .92, .83);
	DefineColor("Grey41", .41, .41, .41);
	DefineColor("Grey61", .61, .61, .61);
	DefineColor("Grey91", .91, .91, .91);
	DefineColor("NightBlue", .1294, .1137, .3294);
	DefineColor("CornflowerBlue", .392, .584, 0.929);
	DefineColor("RoyalBlue", .2549, .41176, .8039);
	DefineColor("Blue1", .2, .8, 1);
	DefineColor("Blue2", .2, 1, 1);
	DefineColor("DeepBlue2", 0.1, 0.22, 0.28);                                //NEW
	DefineColor("DeepBlue", 0.1, 0.41, 0.62);                                 //NEW
}



void InitialButton(mybutton* ButtonList)
{
	InitButtonColors();

	//主页面
	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 - 3;
		ButtonList->y = GetWindowHeight() / 2 - 3.5;
		strcpy(ButtonList->str, "SNOOKER");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[0]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 3.5;
		strcpy(ButtonList->str, "SIDEPOCKET");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[1]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 - 3;
		ButtonList->y = GetWindowHeight() / 2 - 4.5;
		strcpy(ButtonList->str, "AMERICAN");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[2]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 4.5;
		strcpy(ButtonList->str, "ENTERTAINMENT");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[3]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 + 3;
		ButtonList->y = GetWindowHeight() / 2 - 3.5;
		strcpy(ButtonList->str, "NEWGAME");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[4]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 + 3;
		ButtonList->y = GetWindowHeight() / 2 - 4.5;
		strcpy(ButtonList->str, "LOADGAME");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[5]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = 2;
		ButtonList->y = GetWindowHeight() - 1;
		strcpy(ButtonList->str, "SETTINGS");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[31]
	ButtonList++;


	//菜单页面
	{
		ButtonList->width = 5;
		ButtonList->height = 1;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 + 5;
		strcpy(ButtonList->str, "MENU");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEDARK;
	}//ButtonList[6]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 + 3;
		strcpy(ButtonList->str, "Continue");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEGREY;
	}//ButtonList[7]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 + 2;
		strcpy(ButtonList->str, "Restart");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEGREY;
	}//ButtonList[8]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 + 1;
		strcpy(ButtonList->str, "Save");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEGREY;
	}//ButtonList[9]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2;
		strcpy(ButtonList->str, "Load");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEGREY;
	}//ButtonList[10]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 1;
		strcpy(ButtonList->str, "Settings");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEGREY;
	}//ButtonList[11]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 2;
		strcpy(ButtonList->str, "Return to HOME");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEGREY;
	}//ButtonList[12]
	ButtonList++;


	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 3;
		strcpy(ButtonList->str, "Exit");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEGREY;
	}//ButtonList[13]
	ButtonList++;


	//设置页面
	{
		ButtonList->width = 6;
		ButtonList->height = 1;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 + 5;
		strcpy(ButtonList->str, "SETTING");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEDARK;
	}//ButtonList[14]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 - 1.5;
		ButtonList->y = GetWindowHeight() / 2 + 3;
		strcpy(ButtonList->str, "Sound");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[15]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 + 1.5;
		ButtonList->y = GetWindowHeight() / 2 + 3;
		strcpy(ButtonList->str, "SoundONOFF");
		ButtonList->state = NORMAL;
		ButtonList->style = ONOFF;
	}//ButtonList[16]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 - 1.5;
		ButtonList->y = GetWindowHeight() / 2 + 2;
		strcpy(ButtonList->str, "Friction");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[17]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 + 1.5;
		ButtonList->y = GetWindowHeight() / 2 + 2;
		strcpy(ButtonList->str, "FrictionHIGHTLOW");
		ButtonList->state = NORMAL;
		ButtonList->style = HIGHLOW;
	}//ButtonList[18]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 - 1.5;
		ButtonList->y = GetWindowHeight() / 2 + 1;
		strcpy(ButtonList->str, "Guide Line");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[19]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 + 1.5;
		ButtonList->y = GetWindowHeight() / 2 + 1;
		strcpy(ButtonList->str, "GuideLineONOFF");
		ButtonList->state = NORMAL;
		ButtonList->style = ONOFF;
	}//ButtonList[20]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 - 1.5;
		ButtonList->y = GetWindowHeight() / 2;
		strcpy(ButtonList->str, "Strength");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[21]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2 + 1.5;
		ButtonList->y = GetWindowHeight() / 2;
		strcpy(ButtonList->str, "StrengthHIGHTLOW");
		ButtonList->state = NORMAL;
		ButtonList->style = HIGHLOW;
	}//ButtonList[22]
	ButtonList++;

	{
		ButtonList->width = 5;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 1;
		strcpy(ButtonList->str, "Change Account");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[23]
	ButtonList++;

	{
		ButtonList->width = 5;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 2;
		strcpy(ButtonList->str, "Close Accounts");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[24]
	ButtonList++;

	{
		ButtonList->width = 5;
		ButtonList->height = 0.5;
		ButtonList->x = GetWindowWidth() / 2;
		ButtonList->y = GetWindowHeight() / 2 - 4;
		strcpy(ButtonList->str, "Return");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[25]
	ButtonList++;


	//登录页面
	{
		ButtonList->width = 3;
		ButtonList->height = 0.7;
		ButtonList->x = 11.7;
		ButtonList->y = 4;
		strcpy(ButtonList->str, "Login");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[26]
	ButtonList++;

	{
		ButtonList->width = 3;
		ButtonList->height = 0.7;
		ButtonList->x = 4;
		ButtonList->y = 4;
		strcpy(ButtonList->str, "Register");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[27]
	ButtonList++;

	{
		ButtonList->width = 2.4;
		ButtonList->height = 0.7;
		ButtonList->x = 14;
		ButtonList->y = 2;
		strcpy(ButtonList->str, "Visitor to login ->");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[28]
	ButtonList++;


	//注册页面
	{
		ButtonList->width = 3;
		ButtonList->height = 0.7;
		ButtonList->x = 4;
		ButtonList->y = 4;
		strcpy(ButtonList->str, "register");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[29]
	ButtonList++;

	{
		ButtonList->width = 3;
		ButtonList->height = 0.7;
		ButtonList->x = 11.7;
		ButtonList->y = 4;
		strcpy(ButtonList->str, "CANCEL");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLEBLUE;
	}//ButtonList[30]
	ButtonList++;


	//游戏页面
	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = 2;
		ButtonList->y = GetWindowHeight() - 1;
		strcpy(ButtonList->str, "OPTIONS");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[31]
	ButtonList++;

	{
		ButtonList->width = 2;
		ButtonList->height = 0.5;
		ButtonList->x = 2;
		ButtonList->y = GetWindowHeight() - 2;
		strcpy(ButtonList->str, "Regret");
		ButtonList->state = NORMAL;
		ButtonList->style = STYLERED;
	}//ButtonList[32]
	ButtonList++;
}