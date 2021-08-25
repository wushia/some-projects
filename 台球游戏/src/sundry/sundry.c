#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include "sundry.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")


double LineDistance(double angle, double x1, double y1, double x2, double y2)
{
	angle = angle - atan2(y2 - y1, x2 - x1);
	return fabs(sin(angle))*DISTANCE(x1, y1, x2, y2);
}
//画矩形
void DrawBox(double x, double y)
{
	DrawLine(x, 0);
	DrawLine(0, y);
	DrawLine(-x, 0);
	DrawLine(0, -y);
}
void DrawRoundBox(double x0, double y0, double x, double y, double r)
{
	MovePen(x0 + r, y0);
	DrawLine(x - 2 * r, 0);
	DrawArc(r, -90, 90);
	DrawLine(0, y - 2 * r);
	DrawArc(r, 0, 90);
	DrawLine(-x + 2 * r, 0);
	DrawArc(r, 90, 90);
	DrawLine(0, -y + 2 * r);
	DrawArc(r, 180, 90);

}
void MyDrawEdge(double d1, double d2, double h, double x1, double x2, int i)
{                                                 //d1上底,d2下底,h高,x1左(下)边斜线的x投影,x2右(上)边
	if (i == 0)
	{
		DrawLine(x1, h);
		DrawLine(d1, 0);
		DrawLine(x2, -h);
		DrawLine(-d2, 0);
	}
	else if (i == 1) {
		DrawLine(h, x1);
		DrawLine(0, d1);
		DrawLine(-h, x2);
		DrawLine(0, -d2);
	}

}
/* direction 方向变量(角度制)=>弧度制: direction*PI/180*/
void forward(double direction, double distance) { //沿当前方向画线，长度为distance，当distance为负数时后退

	double dx, dy;
	dx = distance * cos(direction * PI / 180);
	dy = distance * sin(direction * PI / 180);
	DrawLine(dx, dy);
}
void turn(double direction, double angle) {//顺时针旋转角度angle，角度单位为DEG，当angle为负数时逆时针旋转

	direction -= angle;
}
void move(double x0, double y0, double direction, double distance) {//沿当前方向移动笔（不画线），长度为distance，当distance为负数时后退

	double dx, dy;
	dx = distance * cos(direction * PI / 180);
	dy = distance * sin(direction * PI / 180);
	MovePen(x0 + dx, y0 + dy);
}

int ChartoInt(char* a) {// a中都是数字
	int item;
	int i;
	int mynumber = 0;
	for (i = 0; i < strlen(a); i++) {
		item = (int) a[i] - '0';
		mynumber = mynumber * 10 + item;
	}
	return mynumber;
}



void DrawRoundTriangle(double l, double r) {// l代入前先减去半径
	DrawLine(l / 2, 0);
	DrawArc(r, -90, 120);
	DrawLine(-l / 2, l / 2 * 1.73);
	DrawArc(r, 30, 120);
	DrawLine(-l / 2, -l / 2 * 1.73);
	DrawArc(r, 150, 120);
	DrawLine(l / 2, 0);
}
void MyDrawText(double x, double y, int PointSize, char *color, char *str) 
{
	MovePen(x, y);
	SetPointSize(PointSize);
	SetPenColor(color);
	DrawTextString(str);
}


/*
 * 函数: GetAngle
 * 用法: GetAngle(double x1, double y1, double x2, double y2)
 * ---------------------------------------
 * 获取两点间夹角
 */
double GetAngle(double x1, double y1, double x2, double y2)
{
	if (x1 == x2 && y1 == y2)
		return 0;
	return atan2(y2 - y1, x2 - x1);
}

