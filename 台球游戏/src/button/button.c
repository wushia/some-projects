#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"button.h"
#include "page.h"
#include "boolean.h"

mybutton ButtonList[BUTTONTOTALNUMBER];
int ButtonIndex;

/*
 * 函数: ShowButton
 * 用法: ShowButton(mybutton* ButtonInstance) 
 * ---------------------------------------
 * 依据按钮状态显示按钮
 */
void ShowButton(mybutton* ButtonInstance) 
{
	SetPointSize(20);
	switch (ButtonInstance->state) {
	case NORMAL:
		ShowNormalButton(ButtonInstance);
		break;
	case CLICK:
		ShowClickButton(ButtonInstance);
		break;
	case ACTIVE:
		ShowActiveButton(ButtonInstance);
		break;
	}
}


/*
 * 函数: ShowPageButton
 * 用法: ShowPageButton(mybutton* ButtonInstance, int page)
 * ---------------------------------------
 * 依据界面显示按钮
 */
void ShowPageButton(mybutton* ButtonInstance, int page) 
{
	int i;
	switch (page) 
	{
		case HOMEPAGE:
			for (i = SNOOKER_BUTTON; i <= SETTING_HPAGE; i++)
			{
				ShowButton(ButtonInstance + i);
			}
			break;
		case GAMEPAGE:
			for (i = OPTIONS; i <= REGRET; i++)
			{
				ShowButton(ButtonInstance + i);
			}
			break;
		case MENUPAGE:
			for (i = MENU; i <= EXIT; i++)
			{
				ShowButton(ButtonInstance + i);
			}
			break;
		case SETTINGPAGE:
			for (i = SETTING_SPAGE; i <= RETURN; i++)
			{
				ShowButton(ButtonInstance + i);
			}
			break;
		case LOGINPAGE:
			for (i = LOGIN; i <= VISITOR; i++)
			{
				ShowButton(ButtonInstance + i);
			}
			break;

		case REGISTERPAGE:
			for (i = REGISTER_RPAGE; i <= CANCEL; i++)
			{
				ShowButton(ButtonInstance + i);
			}
			break;
	}
}