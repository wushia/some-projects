#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"button.h"
#include "page.h"
#include "boolean.h"





/*
 * 函数: SelectWhichButton
 * 用法: SelectWhichButton(double x, double y)
 * ---------------------------------------
 * 依据页面，以及鼠标位置动作，判断哪个按钮被选择
 */
int SelectWhichButton(double x, double y)
{
	int i = 0;
	switch (PageMode) 
	{
		case HOMEPAGE:
			for (i = SNOOKER_BUTTON; i <= SETTING_HPAGE; i++)
			{
				if ((fabs(x - (ButtonList + i)->x) <= ((ButtonList + i)->width / 2)) && (fabs(y - (ButtonList + i)->y) <= ((ButtonList + i)->height / 2))) 
				{
					return i;
				}
			}
			break;
		case GAMEPAGE:
			for (i = OPTIONS; i <= REGRET; i++)
			{
				if ((fabs(x - (ButtonList + i)->x) <= ((ButtonList + i)->width / 2)) && (fabs(y - (ButtonList + i)->y) <= ((ButtonList + i)->height / 2))) 
				{
					return i;
				}
			}
			break;
		case MENUPAGE:
			for (i = MENU; i <= EXIT; i++)
			{
				if ((fabs(x - (ButtonList + i)->x) <= ((ButtonList + i)->width / 2)) && (fabs(y - (ButtonList + i)->y) <= ((ButtonList + i)->height / 2))) 
				{
					return i;
				}
			}
			break;
		case SETTINGPAGE:
			for (i = SETTING_SPAGE; i <= RETURN; i++)
			{
				if ((fabs(x - (ButtonList + i)->x) <= ((ButtonList + i)->width / 2)) && (fabs(y - (ButtonList + i)->y) <= ((ButtonList + i)->height / 2))) 
				{
					return i;
				}
			}
			break;
		case LOGINPAGE:
			for (i = LOGIN; i <= VISITOR; i++)
			{
				if ((fabs(x - (ButtonList + i)->x) <= ((ButtonList + i)->width / 2)) && (fabs(y - (ButtonList + i)->y) <= ((ButtonList + i)->height / 2))) 
				{
					return i;
				}
			}
			break;
		case REGISTERPAGE:
			for (i = REGISTER_RPAGE; i <= CANCEL; i++) 
			{
				if ((fabs(x - (ButtonList + i)->x) <= ((ButtonList + i)->width / 2)) && (fabs(y - (ButtonList + i)->y) <= ((ButtonList + i)->height / 2))) 
				{
					return i;
				}
			}
	}
	return -1;
}


/*
 * 函数: ButtonActive
 * 用法: ButtonActive(double x, double y, int button, int event) 
 * ---------------------------------------
 * 按钮状态变换
 */
void ButtonActive(double x, double y, int button, int event) 
{
	ButtonIndex = SelectWhichButton(x, y);
	int i;
	static bool isClick[8] = { 0,0,0,0,0,0,0,0 };//判断上次循环是否按下这个按钮
	static int index = 0;
	if (index == SNOOKER_BUTTON && isClick[0]) {
		ButtonList[index].state = CLICK;
	}
	else if (index == SIDEPOCKET_BUTTON && isClick[1]) {
		ButtonList[index].state = CLICK;
	}
	else if (index == AMERICAN_BUTTON && isClick[2]) {
		ButtonList[index].state = CLICK;
	}
	else if (index == ENTERTAINMENT_BUTTON && isClick[3]) {
		ButtonList[index].state = CLICK;
	}
	else if (index == SOUND_ONOFF && isClick[4]) {
		ButtonList[index].state = CLICK;
	}
	else if (index == GUIDE_LINE_ON_OFF && isClick[5]) {
		ButtonList[index].state = CLICK;
	}
	else if (index == FRICTION_HIGHT_LOW && isClick[6]) {
		ButtonList[index].state = CLICK;
	}
	else if (index == STRENGTH_HIGH_LOW && isClick[7]) {
		ButtonList[index].state = CLICK;
	}
	else {
		ButtonList[index].state = NORMAL;
	}


	//某些按钮不变，起到标签作用
	if (ButtonIndex != -1 && ButtonIndex != MENU && ButtonIndex != SETTING_SPAGE && ButtonIndex != SOUND && ButtonIndex != GUIDE_LINE && ButtonIndex != FRICTION && ButtonIndex != STRENGTH)
	{
		if (event == BUTTON_DOWN) 
		{
			ButtonList[ButtonIndex].state = CLICK;
			if (ButtonIndex <= ENTERTAINMENT_BUTTON)
			{
				isClick[ButtonIndex] = 1;
				for (i = 0; i <= ENTERTAINMENT_BUTTON; i++)
				{
					if (ButtonIndex != i) 
					{
						ButtonList[i].state = NORMAL;
					}

				}
			}
			if (ButtonIndex == SOUND_ONOFF) isClick[4] = !isClick[4];
			if (ButtonIndex == GUIDE_LINE_ON_OFF) isClick[5] = !isClick[5];
			if (ButtonIndex == FRICTION_HIGHT_LOW) isClick[6] = !isClick[6];
			if (ButtonIndex == STRENGTH_HIGH_LOW) isClick[7] = !isClick[7];
		}
		else if (ButtonIndex != SOUND_ONOFF && ButtonIndex != GUIDE_LINE_ON_OFF && ButtonIndex != FRICTION_HIGHT_LOW && ButtonIndex != STRENGTH_HIGH_LOW) 
		{
			ButtonList[ButtonIndex].state = ACTIVE;
		}
	}
	index = ButtonIndex;
}