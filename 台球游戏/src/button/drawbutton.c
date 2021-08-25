#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"button.h"
#include "page.h"
#include "boolean.h"


// 依据button的style绘制一个没被选中的按钮
void ShowNormalButton(mybutton* ButtonInstance)
{
	int x1, y1;
	switch (ButtonInstance->style)
	{
	case STYLERED://红色风格按钮
	{
		SetPenColor("Red4");
		StartFilledRegion(0.9);//上半个矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red3");
		StartFilledRegion(0.9);//下半个矩形区域涂色
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		SetPointSize(20);
		DrawTextString(ButtonInstance->str);
		break;
	}

	case ONOFF:
	{
		SetPenColor("Red4");
		StartFilledRegion(0.9);//上半个矩形区域涂色
		MovePen(ButtonInstance->x, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red3");
		StartFilledRegion(0.9);//下半个矩形区域涂色
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();


		SetPenColor("Red3");
		StartFilledRegion(0.9);

		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red2");
		StartFilledRegion(0.9);
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();

		SetPenColor("Black");//边框加黑线
		SetPenSize(2);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height);


		MovePen(ButtonInstance->x - ButtonInstance->width / 4 - TextStringWidth("ON") / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString("ON");

		MovePen(ButtonInstance->x + ButtonInstance->width / 4 - TextStringWidth("OFF") / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		DrawTextString("OFF");
		break;
	}

	case HIGHLOW:
	{
		SetPenColor("Red4");
		StartFilledRegion(0.9);//上半个矩形区域涂色
		MovePen(ButtonInstance->x, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red3");
		StartFilledRegion(0.9);//下半个矩形区域涂色
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();


		SetPenColor("Red3");
		StartFilledRegion(0.9);

		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red2");
		StartFilledRegion(0.9);
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();

		SetPenColor("Black");//边框加黑线
		SetPenSize(2);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height);


		MovePen(ButtonInstance->x - ButtonInstance->width / 4 - TextStringWidth("HI") / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString("HI");

		MovePen(ButtonInstance->x + ButtonInstance->width / 4 - TextStringWidth("LOW") / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		DrawTextString("LOW");
		break;
	}

	case STYLEDARK://褐色风格
	{
		SetPenColor("DarkGoldenrod2");
		StartFilledRegion(0.9);//矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		EndFilledRegion();
		SetPenColor("PeachPuff");//矩形区域画边框
		SetPenSize(4);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		SetPointSize(80);
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent() - 0.1);
		SetPenColor("Black");
		DrawTextString(ButtonInstance->str);
		break;
	}

	case STYLEGREY://灰色风格
	{
		SetPenColor("Grey41");
		StartFilledRegion(0.9);//矩形加两个半圆区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 90, -180);
		DrawLine(-ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, -90, -180);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 2, 90, 180);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 270, 180);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		SetPenColor("Grey91");//画区域边框
		SetPenSize(7);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 90, -180);
		DrawLine(-ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, -90, -180);
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString(ButtonInstance->str);
		break;
	}

	case STYLEBLUE:
	{
		SetPenColor("NightBlue");//底层深色
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2 - ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, -ButtonInstance->height + ButtonInstance->height / 6);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height - ButtonInstance->height / 6);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX(), GetCurrentY() + ButtonInstance->height - ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 7 / 6);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 7 / 6);
		EndFilledRegion();
		SetPenColor("CornflowerBlue");//上层浅色
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2 - ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, -ButtonInstance->height * 1 / 3);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height * 1 / 3);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 2);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 1 / 2);
		EndFilledRegion();
		//下层颜色
		SetPenColor("RoyalBlue");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y - ButtonInstance->height / 2 + ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, ButtonInstance->height * 1 / 3);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 3);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() - ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 1 / 2);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 2);
		EndFilledRegion();
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString(ButtonInstance->str);
		break;
	}
	}
}

// 依据button的style绘制一个被点击的按钮
void ShowClickButton(mybutton* ButtonInstance)
{
	double buttony_temp;

	switch (ButtonInstance->style)
	{
	case STYLERED://被点击后颜色变化，边框加黑线
	{


		SetPenColor("Red3");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red2");
		StartFilledRegion(0.9);
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		DrawTextString(ButtonInstance->str);
		SetPenColor("Black");//边框加黑线
		SetPenSize(0.01);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		SetPointSize(20);
		DrawTextString(ButtonInstance->str);
		break;
	}
	case ONOFF:
	{


		SetPenColor("Red4");
		StartFilledRegion(0.9);//上半个矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red3");
		StartFilledRegion(0.9);//下半个矩形区域涂色
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();


		SetPenColor("Red3");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red2");
		StartFilledRegion(0.9);
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();

		SetPenColor("Black");//边框加黑线
		SetPenSize(2);
		MovePen(ButtonInstance->x, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height);

		MovePen(ButtonInstance->x - ButtonInstance->width / 4 - TextStringWidth("ON") / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString("ON");

		MovePen(ButtonInstance->x + ButtonInstance->width / 4 - TextStringWidth("OFF") / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		DrawTextString("OFF");
		break;
	}

	case HIGHLOW:
	{


		SetPenColor("Red4");
		StartFilledRegion(0.9);//上半个矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red3");
		StartFilledRegion(0.9);//下半个矩形区域涂色
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();


		SetPenColor("Red3");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red2");
		StartFilledRegion(0.9);
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();

		SetPenColor("Black");//边框加黑线
		SetPenSize(2);
		MovePen(ButtonInstance->x, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width / 2, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width / 2, 0);
		DrawLine(0, ButtonInstance->height);

		MovePen(ButtonInstance->x - ButtonInstance->width / 4 - TextStringWidth("HI") / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString("HI");

		MovePen(ButtonInstance->x + ButtonInstance->width / 4 - TextStringWidth("LOW") / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		DrawTextString("LOW");
		break;
	}
	case STYLEDARK://被点击后边框颜色变化，边框加黑线
	{

		SetPenColor("DarkGoldenrod3");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		EndFilledRegion();
		SetPenColor("PapayaWhip");
		SetPenSize(4);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		SetPenColor("Black");
		SetPenSize(0.01);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("Black");
		SetPointSize(20);
		DrawTextString(ButtonInstance->str);
		break;
	}
	case STYLEGREY:
	{
		SetPenColor("Grey41");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 90, -180);
		DrawLine(-ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, -90, -180);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 2, 90, 180);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 270, 180);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		SetPenColor("Grey61");
		SetPenSize(7);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 90, -180);
		DrawLine(-ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, -90, -180);
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString(ButtonInstance->str);
		SetPenColor("Black");//边框加黑线
		SetPenSize(0.01);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 90, -180);
		DrawLine(-ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, -90, -180);
		break;
	}
	case STYLEBLUE:
	{
		buttony_temp = ButtonInstance->y;
		ButtonInstance->y -= ButtonInstance->height / 6;

		SetPenColor("NightBlue");//底层深色
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2 - ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, -ButtonInstance->height + ButtonInstance->height * 4 / 15);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height - ButtonInstance->height * 4 / 15);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height + ButtonInstance->height * 4 / 15);
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX(), GetCurrentY() + ButtonInstance->height - ButtonInstance->height * 4 / 15);
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 16 / 15);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 16 / 15);
		EndFilledRegion();
		SetPenColor("Blue2");//上层浅色
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2 - ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, -ButtonInstance->height * 1 / 3);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height * 1 / 3);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 2);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 1 / 2);
		EndFilledRegion();
		//下层颜色
		SetPenColor("Blue1");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y - ButtonInstance->height / 2 + ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, ButtonInstance->height * 1 / 3);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 3);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() - ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 1 / 2);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 2);
		EndFilledRegion();
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		ButtonInstance->y = buttony_temp;
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString(ButtonInstance->str);


		break;
	}
	}
}

// 依据button的style绘制一个鼠标悬浮在按钮时的按钮
void ShowActiveButton(mybutton* ButtonInstance)
{
	switch (ButtonInstance->style)
	{
	case STYLERED://悬浮时颜色变化
	{
		SetPenColor("Red3");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red2");
		StartFilledRegion(0.9);
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		SetPointSize(20);
		DrawTextString(ButtonInstance->str);
		break;
	}

	case ONOFF:
	{
		SetPenColor("Red4");
		StartFilledRegion(0.9);//上半个矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red3");
		StartFilledRegion(0.9);//下半个矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();


		MovePen(ButtonInstance->x - ButtonInstance->width / 4 - TextStringWidth("ON") / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString("ON");

		MovePen(ButtonInstance->x + ButtonInstance->width / 4 - TextStringWidth("OFF") / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		DrawTextString("OFF");
		break;
	}

	case HIGHLOW:
	{
		SetPenColor("Red4");
		StartFilledRegion(0.9);//上半个矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();
		SetPenColor("Red3");
		StartFilledRegion(0.9);//下半个矩形区域涂色
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height / 2);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height / 2);
		EndFilledRegion();


		MovePen(ButtonInstance->x - ButtonInstance->width / 4 - TextStringWidth("HI") / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString("HI");

		MovePen(ButtonInstance->x + ButtonInstance->width / 4 - TextStringWidth("LOW") / 2, ButtonInstance->y - GetFontDescent());
		SetPenColor("White");
		DrawTextString("LOW");
		break;
	}


	case STYLEDARK://悬浮时边框颜色变化
	{
		SetPenColor("DarkGoldenrod3");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		EndFilledRegion();
		SetPenColor("PapayaWhip");
		SetPenSize(4);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height);
		DrawLine(-ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height);
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("Black");
		DrawTextString(ButtonInstance->str);
		break;
	}
	case STYLEGREY://悬浮时边框颜色变化
	{
		SetPenColor("Grey41");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 90, -180);
		DrawLine(-ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, -90, -180);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 2, 90, 180);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 270, 180);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		SetPenColor("Grey61");
		SetPenSize(7);
		DrawLine(ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, 90, -180);
		DrawLine(-ButtonInstance->width, 0);
		DrawArc(ButtonInstance->height / 2, -90, -180);
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString(ButtonInstance->str);
		break;
	}
	case STYLEBLUE:
	{
		SetPenColor("NightBlue");//底层深色
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2 - ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, -ButtonInstance->height + ButtonInstance->height / 6);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height - ButtonInstance->height / 6);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX(), GetCurrentY() - ButtonInstance->height + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX(), GetCurrentY() + ButtonInstance->height - ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 7 / 6);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 7 / 6);
		EndFilledRegion();
		SetPenColor("Blue2");//上层浅色
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y + ButtonInstance->height / 2 - ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, -ButtonInstance->height * 1 / 3);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, ButtonInstance->height * 1 / 3);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() + ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 2);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 1 / 2);
		EndFilledRegion();
		//下层颜色
		SetPenColor("Blue1");
		StartFilledRegion(0.9);
		MovePen(ButtonInstance->x - ButtonInstance->width / 2, ButtonInstance->y - ButtonInstance->height / 2 + ButtonInstance->height / 6);
		DrawArc(ButtonInstance->height / 6, 180, 360);
		EndFilledRegion();
		StartFilledRegion(0.9);
		DrawLine(0, ButtonInstance->height * 1 / 3);
		DrawLine(ButtonInstance->width, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 3);
		DrawLine(-ButtonInstance->width, 0);
		EndFilledRegion();
		MovePen(GetCurrentX() + ButtonInstance->width, GetCurrentY());
		StartFilledRegion(0.9);
		DrawArc(ButtonInstance->height / 6, 0, 360);
		EndFilledRegion();
		MovePen(GetCurrentX() - ButtonInstance->height / 6, GetCurrentY() - ButtonInstance->height / 6);
		StartFilledRegion(0.9);
		DrawLine(-ButtonInstance->width + ButtonInstance->height / 3, 0);
		DrawLine(0, ButtonInstance->height * 1 / 2);
		DrawLine(ButtonInstance->width - ButtonInstance->height / 3, 0);
		DrawLine(0, -ButtonInstance->height * 1 / 2);
		EndFilledRegion();
		MovePen(ButtonInstance->x - TextStringWidth(ButtonInstance->str) / 2, ButtonInstance->y - GetFontDescent());
		SetPointSize(20);
		SetPenColor("White");
		DrawTextString(ButtonInstance->str);

		break;
	}
	}
}