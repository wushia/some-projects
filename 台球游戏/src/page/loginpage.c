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

char Password[10] = "";//����
char UserName[5] = "";//�˺�
char NewName[5] = "";
char NewPassword[10] = "";
int NewUserNum;
int UserNum;


//��¼ҳ��
void ShowLoginPage()
{
	DisplayClear();

	SetPenColor("eyellow");
	MovePen(0, 0);
	StartFilledRegion(0.9);
	DrawBox(16, 12);
	EndFilledRegion();

	SetPenColor("LightGreen1");
	MovePen(cx - 2.5, cy + 3.9);
	StartFilledRegion(0.9);
	DrawBox(5, 1.2);
	EndFilledRegion();

	SetPenColor("Black");
	SetPenSize(5);
	DrawBox(5, 1.2);

	MovePen(cx - 6, cy - 0.5);
	SetPenSize(2);
	SetPenColor("LightBlue0");
	StartFilledRegion(0.9);
	DrawBox(11.6, 4);
	EndFilledRegion();

	SetPenColor("Black");
	SetPenSize(5);
	MovePen(cx - 6, cy - 0.5);
	DrawBox(11.6, 4);

	SetPenSize(2);
	SetPointSize(100);
	MovePen(cx - TextStringWidth("LOG IN") / 2, cy + 4);
	SetPenColor("Black");
	DrawTextString("LOG IN");
	SetPointSize(30);

	drawLabel(cx - 2.5 - TextStringWidth("UserName"), cy + 2.4, "UserName");
	textbox(GenUIID(0), cx, cy + 2.3, 4, 0.5, UserName, 5);
	SetPenColor("Black");
	drawLabel(cx - 2.5 - TextStringWidth("Password"), cy + 0.4, "Password");
	textbox(GenUIID(1), cx, cy + 0.3, 4, 0.5, Password, 10);


	ShowPageButton(ButtonList, LOGINPAGE);
}


//�ж������˺��Լ��������ȷ��
int Login(void)
{
	UserNum = ChartoInt(UserName);
	if (strcmp(UserName, "") == 0) 
	{
		return PASSWORD_ERROR;
	}
	FILE* Fpassword;
	if ((Fpassword = fopen(".\\data\\account\\password.bat", "ab")) == NULL) 
	{
		exit(1);
	}
	fclose(Fpassword);

	char TruePassword[10] = { 0 };
	if ((Fpassword = fopen(".\\data\\account\\password.bat", "rb")) == NULL) 
	{
		exit(1);
	}
	fseek(Fpassword, UserNum * 10L, 0);//��һλΪ�˺�����
	fread(TruePassword, 9, 1, Fpassword);
	if (strcmp(Password, TruePassword) == 0)
	{
		fclose(Fpassword);

		return PASSWORD_CORRECT;
	}
	else
	{
		fclose(Fpassword);
		return PASSWORD_ERROR;
	}

}

//��ʾע��ҳ��
void ShowRegisterPage() 
{
	int i;
	DisplayClear();

	SetPenColor("eyellow");
	MovePen(0, 0);
	StartFilledRegion(0.9);
	DrawBox(16, 12);
	EndFilledRegion();

	SetPenColor("LightGreen1");
	MovePen(cx - 3.3, cy + 3.9);
	StartFilledRegion(0.9);
	DrawBox(6.6, 1.2);
	EndFilledRegion();

	SetPenColor("Black");
	SetPenSize(5);
	DrawBox(6.6, 1.2);

	MovePen(cx - 6, cy - 0.5);
	SetPenSize(2);
	SetPenColor("LightBlue0");
	StartFilledRegion(0.9);
	DrawBox(11.6, 4);
	EndFilledRegion();

	SetPenColor("Black");
	SetPenSize(5);
	MovePen(cx - 6, cy - 0.5);
	DrawBox(11.6, 4);

	SetPenSize(2);
	SetPointSize(100);
	MovePen(cx - TextStringWidth("REGISTER") / 2, cy + 4);
	DrawTextString("REGISTER");

	SetPointSize(30);
	drawLabel(cx - 2.5 - TextStringWidth("newUserName"), cy + 2.4, "newUserName");
	textbox(GenUIID(0), cx, cy + 2.3, 4, 0.5, NewName, 5);
	SetPenColor("Black");
	drawLabel(cx - 2.5 - TextStringWidth("NewPassword"), cy + 0.4, "NewPassword");
	textbox(GenUIID(1), cx, cy + 0.3, 4, 0.5, NewPassword, 10);
	NewUserNum = ChartoInt(NewName);

	ShowPageButton(ButtonList, REGISTERPAGE);
}

//ɾ����ǰ�˺�
int CloseAccount(void) 
{
	char OldPassWord[10];
	int Num = 0;//�ڼ�������
	UserNum = ChartoInt(UserName);
	FILE* Fpassword1;
	if ((Fpassword1 = fopen(".\\data\\account\\password1.bat", "wb+")) == NULL) 
	{
		exit(1);
	}
	FILE* Fpassword;
	if ((Fpassword = fopen(".\\data\\account\\password.bat", "rb+")) == NULL) 
	{
		exit(1);
	}
	rewind(Fpassword);
	while (!feof(Fpassword)) 
	{
		if (Num == UserNum) 
		{
			Num++;
			fseek(Fpassword, 10L, 1);
			fseek(Fpassword1, 10L, 1);
			continue;//��UserNum���˺����벻����
		}
		fread(OldPassWord, 10L, 1, Fpassword);
		fwrite(OldPassWord, 10L, 1, Fpassword1);
		Num++;
	}
	fclose(Fpassword);
	fclose(Fpassword1);
	remove(".\\data\\account\\password.bat");
	rename(".\\data\\account\\password1.bat", ".\\data\\account\\password.bat");
}

//�����˺�ע��
int Register(void)
{
	char TruePassword[10] = { 0 };
	NewUserNum = ChartoInt(NewName);
	if (strcmp(NewName, "") == 0)//������
	{
		return NOINPUT;
	}
	if (!NewUserNum) //0000�Ѿ���ע����
	{
		return USER_REGISTERED;
	}
	FILE* Fpassword;
	//ȷ���������ļ�
	if ((Fpassword = fopen(".\\data\\account\\password.bat", "ab+")) == NULL) {
		exit(1);
	}
	fclose(Fpassword);

	if ((Fpassword = fopen(".\\data\\account\\password.bat", "rb+")) == NULL) {
		exit(1);
	}
	rewind(Fpassword);
	fseek(Fpassword, (NewUserNum) * 10L, 0);//��һλΪ�˺�����
	fread(TruePassword, 10, 1, Fpassword);
	if (!strcmp(TruePassword, "")) //���˺���Ч
	{
		fseek(Fpassword, (NewUserNum) * 10L, 0);
		fwrite(NewPassword, 10, 1, Fpassword);
		fseek(Fpassword, 0, 0);//��һλΪ�˺�����
		fclose(Fpassword);
		return REGISTER_SUCCESS;
	}
	else
	{
		fclose(Fpassword);
		return USER_REGISTERED;
	}
}
