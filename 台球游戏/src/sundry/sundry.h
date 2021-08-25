//===========================================================================
//
//  ��Ȩ�����ߣ� �����裬���ݶ�
//  ��;������ѧϰʹ��
//
//===========================================================================
#ifndef __SUNDRY_H__
#define __SUNDRY_H__
#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846 
#define DISTANCE(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
//����ֱ�߽Ƕȣ������ĵ㣬��Ҫ�������ĵ㣨x2,y2����ã�x2,y2����ֱ�ߵľ���
double LineDistance(double angle, double x1, double y1, double x2, double y2);
extern double cx, cy, MouseX, MouseY;
extern int MouseButton, MouseEvent, KeyPress, KeyEvent;

void DrawBox(double x, double y);
void DrawRoundBox(double x0, double y0, double x, double y, double r);
//d1�ϵ�,d2�µ�,h��,x1��(��)��б�ߵ�xͶӰ,x2��(��)��
void MyDrawEdge(double d1, double d2, double h, double x1, double x2, int i);
// direction �������(�Ƕ���)=>������: direction*PI/180,�ص�ǰ�����ߣ�����Ϊdistance����distanceΪ����ʱ����
void forward(double direction, double distance);
//˳ʱ����ת�Ƕ�angle���Ƕȵ�λΪDEG����angleΪ����ʱ��ʱ����ת
void turn(double direction, double angle);
//�ص�ǰ�����ƶ��ʣ������ߣ�������Ϊdistance����distanceΪ����ʱ����
void move(double x0, double y0, double direction, double distance);

int ChartoInt(char* a);
void DrawTitle1(double titlex, double titley);
void DrawRoundTriangle(double l, double r);
void MyDrawText(double x, double y, int PointSize, char *color, char *str);

double GetAngle(double x1, double y1, double x2, double y2);



#endif