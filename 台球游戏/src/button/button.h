//===========================================================================
//
//  版权所有者： 吕蓝翔，李逸东
//  仅供学习使用
//
//===========================================================================
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>

#define BUTTONTOTALNUMBER 34 // 按钮总数量

// 定义按钮数据类型
typedef struct {
	double width;// 按钮宽
	double height;// 按钮高
	double x;// 按钮中心位置
	double y;
	char str[20];// 显示的字符串
	int state;// 此时的状态：未选中、鼠标悬浮、按下
	int style;// 按钮的样式，决定按钮画出来是什么样的

}mybutton;
// 按钮样式SNOOKER
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
	NORMAL,// 正常未被选中
	CLICK,// 被点击时
	ACTIVE// 鼠标悬浮在按钮之上
};
//按钮序号，和初始化按钮对应,命名规则为“大写的按钮名称_序号”
enum ButtonNumber 
{
	//主页面
	SNOOKER_BUTTON=0,
	SIDEPOCKET_BUTTON,
	AMERICAN_BUTTON,
	ENTERTAINMENT_BUTTON,
	NEWGAME,
	LOADGAME,
	SETTING_HPAGE,
	//菜单页面
	MENU,
	CONTINUE,
	RESTART,
	SAVE,
	LOAD,
	SETTING_MPAGE,
	RETURN_TO_HOME,
	EXIT,
	//设置页面
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
	//登录页面
	LOGIN,
	REGISTER_LPAGE,
	VISITOR,
	//注册页面
	REGISTER_RPAGE,
	CANCEL,
	//游戏页面
	OPTIONS,
	REGRET,
	

};
extern mybutton ButtonList[BUTTONTOTALNUMBER];
extern int ButtonIndex;
// 定义一个按钮数组

void InitButtonColors(void);

// 初始化所有按钮，即填入信息
void InitialButton(mybutton* ButtonList);

// 判断鼠标选中了哪个按钮,若无选中，返回-1
int SelectWhichButton(double x, double y);

// 依据button的style绘制一个没被选中的按钮

void ShowNormalButton(mybutton* ButtonInstance);


// 依据button的style绘制一个被点击的按钮
void ShowClickButton(mybutton* ButtonInstance);


// 依据button的style绘制一个鼠标悬浮在按钮时的按钮
void ShowActiveButton(mybutton* ButtonInstance);


// 依据样式和选中状态绘制一个按钮
void ShowButton(mybutton* ButtonInstance);

// 依据样式和选中状态,和此时的页面状态画出这个页面所有的按钮
void ShowPageButton(mybutton* ButtonInstance, int page);

void ButtonActive(double x, double y, int button, int event);

#endif // !__BUTTON_H__
