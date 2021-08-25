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
//������
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
{                                                 //d1�ϵ�,d2�µ�,h��,x1��(��)��б�ߵ�xͶӰ,x2��(��)��
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
/* direction �������(�Ƕ���)=>������: direction*PI/180*/
void forward(double direction, double distance) { //�ص�ǰ�����ߣ�����Ϊdistance����distanceΪ����ʱ����

	double dx, dy;
	dx = distance * cos(direction * PI / 180);
	dy = distance * sin(direction * PI / 180);
	DrawLine(dx, dy);
}
void turn(double direction, double angle) {//˳ʱ����ת�Ƕ�angle���Ƕȵ�λΪDEG����angleΪ����ʱ��ʱ����ת

	direction -= angle;
}
void move(double x0, double y0, double direction, double distance) {//�ص�ǰ�����ƶ��ʣ������ߣ�������Ϊdistance����distanceΪ����ʱ����

	double dx, dy;
	dx = distance * cos(direction * PI / 180);
	dy = distance * sin(direction * PI / 180);
	MovePen(x0 + dx, y0 + dy);
}

int ChartoInt(char* a) {// a�ж�������
	int item;
	int i;
	int mynumber = 0;
	for (i = 0; i < strlen(a); i++) {
		item = (int) a[i] - '0';
		mynumber = mynumber * 10 + item;
	}
	return mynumber;
}



void DrawRoundTriangle(double l, double r) {// l����ǰ�ȼ�ȥ�뾶
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
 * ����: GetAngle
 * �÷�: GetAngle(double x1, double y1, double x2, double y2)
 * ---------------------------------------
 * ��ȡ�����н�
 */
double GetAngle(double x1, double y1, double x2, double y2)
{
	if (x1 == x2 && y1 == y2)
		return 0;
	return atan2(y2 - y1, x2 - x1);
}

