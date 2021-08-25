#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include "page.h"
#include <string.h>
#include"billiards.h"
#include "sundry.h"
#include"button.h"
#include "imgui.h"




int PageMode = OPENINGPAGE;//ҳ��ģʽ
int SaveFlag = 1;//ָʾ�Ƿ�洢��Ϸ��Ϣ




//��ʾ��ҳ��
void ShowHomePage(void) 
{
	ShowBackGround();
	TableWidth = 10.8; TableHeight = 6;
	DrawAmericanTable(cx, cy);

	MovePen(cx - 2.3, cy + 4);
	SetPointSize(100);
	SetPenColor("White");
	DrawTextString("BILLIARD");

	ShowPageButton(ButtonList, HOMEPAGE);
}



//��ʾ�˵�ҳ��
void ShowMenuPage(void) //  box 8��10
{
	{
		SetPenColor("DeepBlue2");
		MovePen(cx - 4 - 0.16, cy - 5 - 0.16);
		StartFilledRegion(1);
		DrawBox(8, 10);
		EndFilledRegion();

		SetPenColor("DeepBlue");
		MovePen(cx - 4, cy - 5);
		StartFilledRegion(1);
		DrawBox(8, 10);
		EndFilledRegion();

		SetPenColor("Black");
		SetPenSize(4);
		DrawBox(8, 10);
	} //�����ÿ�
	ShowPageButton(ButtonList, MENUPAGE);
}



//����ҳ��
void ShowSettingPage() 
{

	{
		SetPenColor("DeepBlue2");
		MovePen(cx - 4 - 0.16, cy - 5 - 0.16);
		StartFilledRegion(1);
		DrawBox(8, 10);
		EndFilledRegion();

		SetPenColor("DeepBlue");
		MovePen(cx - 4, cy - 5);
		StartFilledRegion(1);
		DrawBox(8, 10);
		EndFilledRegion();

		SetPenColor("Black");
		SetPenSize(4);
		DrawBox(8, 10);
	} //�����ÿ�

	ShowPageButton(ButtonList, SETTINGPAGE);
}



//���غ�����ѡ����ʾ��ͬҳ�棬�Լ�ʵ�ְ�ť�Ľ���
void ShowPage(int timerID) 
{
	int LoginState,RegisterState;
	switch (PageMode) 
	{
		case OPENINGPAGE:
			DisPlayOpeningPage(timerID);
			if (MouseEvent == BUTTON_UP)
				PageMode = LOGINPAGE;
			break;
		case HOMEPAGE:

			ShowHomePage();
			if (ButtonIndex <= ENTERTAINMENT && ButtonList[ButtonIndex].state == CLICK && MouseEvent == BUTTON_DOWN) 
			{
				BilliardbMode = ButtonIndex;
			}
			else if (ButtonIndex == NEWGAME && ButtonList[ButtonIndex].state == CLICK) 
			{
				PageMode = GAMEPAGE;
				InitialBallList();
				InitialRule();
				InitialGameImfor();
			}
			else if (ButtonIndex == LOADGAME && ButtonList[ButtonIndex].state == CLICK) 
			{
				PageMode = GAMEPAGE;
				InitialBallList();
				InitialRule();
				InitialGameImfor();
				LoadImfor();
			}
			else if (ButtonIndex == SETTING_HPAGE && ButtonList[ButtonIndex].state == CLICK)
			{
				PageMode = SETTINGPAGE;
			}
			break;
		case SETTINGPAGE:
			ShowSettingPage();
			if (ButtonIndex == RETURN && ButtonList[ButtonIndex].state == CLICK) 
			{
				PageMode = MENUPAGE;
			}
			else if (ButtonIndex == SOUND_ONOFF && ButtonList[ButtonIndex].state == CLICK) //����
			{
				mciSendString("pause .\\data\\music\\bgm.mp3 ", NULL, 0, NULL);
			}
			else if (ButtonIndex == SOUND_ONOFF && ButtonList[ButtonIndex].state == NORMAL) //����
			{
				mciSendString("play .\\data\\music\\bgm.mp3 repeat", NULL, 0, NULL);
			}
			else if (ButtonIndex == GUIDE_LINE_ON_OFF && ButtonList[ButtonIndex].state == CLICK) //������
			{
				isShowLine = 0;
			}
			else if (ButtonIndex == GUIDE_LINE_ON_OFF && ButtonList[ButtonIndex].state == NORMAL) 
			{
				isShowLine = 1;
			}
			else if (ButtonIndex == FRICTION_HIGHT_LOW && ButtonList[ButtonIndex].state == CLICK) 
			{
				StrengthFlag = 1;
			}
			else if (ButtonIndex == FRICTION_HIGHT_LOW && ButtonList[ButtonIndex].state == NORMAL) 
			{
				StrengthFlag = 0;
			}
			else if (ButtonIndex == STRENGTH_HIGH_LOW && ButtonList[ButtonIndex].state == CLICK) 
			{
				FrictionFlag = 0;
			}
			else if (ButtonIndex == STRENGTH_HIGH_LOW && ButtonList[ButtonIndex].state == NORMAL) 
			{
				FrictionFlag = 1;
			}
			else if (ButtonIndex == CHANGE_ACCOUNT && ButtonList[ButtonIndex].state == CLICK) 
			{
				PageMode = LOGINPAGE;
			}
			else if (ButtonIndex == CLOSE_ACCOUNTS && ButtonList[ButtonIndex].state == CLICK) 
			{
				CloseAccount();
				PageMode = LOGINPAGE;
			}
			break;
		case GAMEPAGE:

			ShowGamePage();
			if (ButtonIndex == REGRET && ButtonList[ButtonIndex].state == CLICK) 
			{
				ReadGameImfor();
			}
			if (ButtonIndex == OPTIONS && ButtonList[ButtonIndex].state == CLICK) {
				PageMode = MENUPAGE;
			}
			break;
		case MENUPAGE:
			ShowMenuPage();
			if (ButtonIndex == RETURN_TO_HOME && ButtonList[ButtonIndex].state == CLICK) {
				PageMode = HOMEPAGE;
			}
			else if (ButtonIndex == CONTINUE && ButtonList[ButtonIndex].state == CLICK) {
				PageMode = GAMEPAGE;
			}
			else if (ButtonIndex == SETTING_MPAGE && ButtonList[ButtonIndex].state == CLICK) {
				PageMode = SETTINGPAGE;
			}
			else if (ButtonIndex == RESTART && ButtonList[ButtonIndex].state == CLICK) {
				PageMode = GAMEPAGE;
				InitialBallList();
				InitialRule();
			}
			else if (ButtonIndex == SAVE && ButtonList[ButtonIndex].state == CLICK) {
				SaveImfor();
			}
			else if (ButtonIndex == LOAD && ButtonList[ButtonIndex].state == CLICK) {
				LoadImfor();
				PageMode = GAMEPAGE;
			}
			else if (ButtonIndex == EXIT && ButtonList[ButtonIndex].state == CLICK) {
				exit(1);
			}
			break;


		case LOGINPAGE:
			ShowLoginPage();
		
			if (ButtonIndex == LOGIN && ButtonList[ButtonIndex].state == CLICK) {
				if (Login() == PASSWORD_CORRECT ) {
					PageMode = HOMEPAGE;
				}
				else {
					MyDrawText(cx, cy + 2, 20, "Black","Password Wrong!");
				}

			}
			else if (ButtonIndex == VISITOR && ButtonList[ButtonIndex].state == CLICK) {////////////////�ο͵�¼��ֱ�ӽ���
				PageMode = HOMEPAGE;
				strcpy(UserName, "0000");
			}
			else if (ButtonIndex == REGISTER_LPAGE && ButtonList[ButtonIndex].state == CLICK) {
				PageMode = REGISTERPAGE;
			}
			break;


		case REGISTERPAGE:
			ShowRegisterPage();
			if (ButtonIndex == CANCEL && ButtonList[ButtonIndex].state == CLICK)
			{
				PageMode = LOGINPAGE;
			}

			else if (ButtonIndex == REGISTER_RPAGE && ButtonList[ButtonIndex].state == CLICK)
			{

				if (Register() == REGISTER_SUCCESS) {
					PageMode = LOGINPAGE;
				}
				else {
					MyDrawText(cx, cy + 2, 20, "Black", "This Username is occupied!");
				}
			}
	}
}