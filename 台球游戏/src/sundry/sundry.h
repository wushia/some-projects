//===========================================================================
//
//  版权所有者： 吕蓝翔，李逸东
//  用途：仅供学习使用
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
//输入直线角度，经过的点，和要计算距离的点（x2,y2）获得（x2,y2）与直线的距离
double LineDistance(double angle, double x1, double y1, double x2, double y2);
extern double cx, cy, MouseX, MouseY;
extern int MouseButton, MouseEvent, KeyPress, KeyEvent;

void DrawBox(double x, double y);
void DrawRoundBox(double x0, double y0, double x, double y, double r);
//d1上底,d2下底,h高,x1左(下)边斜线的x投影,x2右(上)边
void MyDrawEdge(double d1, double d2, double h, double x1, double x2, int i);
// direction 方向变量(角度制)=>弧度制: direction*PI/180,沿当前方向画线，长度为distance，当distance为负数时后退
void forward(double direction, double distance);
//顺时针旋转角度angle，角度单位为DEG，当angle为负数时逆时针旋转
void turn(double direction, double angle);
//沿当前方向移动笔（不画线），长度为distance，当distance为负数时后退
void move(double x0, double y0, double direction, double distance);

int ChartoInt(char* a);
void DrawTitle1(double titlex, double titley);
void DrawRoundTriangle(double l, double r);
void MyDrawText(double x, double y, int PointSize, char *color, char *str);

double GetAngle(double x1, double y1, double x2, double y2);



#endif