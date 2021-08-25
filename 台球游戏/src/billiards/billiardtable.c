#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include"billiards.h"
#include "sundry.h"




double TableWidth, TableHeight, HoleRadius;
double CueAngle;




void InitialTableColor(void)
{
	DefineColor("LightGolden", 0.93, 0.87, 0.5);
	DefineColor("SpringGreen3", 0, 0.5, 0.23);
	DefineColor("SpringGreen4", 0.01, 0.52, 0.24);
	DefineColor("SpringGreen2", 0.03, 0.54, 0.26);
	DefineColor("SpringGreen1", 0.02, 0.53, 0.25);
	DefineColor("DarkGreen", 0.13, 0.54, 0.13);
	DefineColor("Silver", 0.8, 0.8, 0.8);
	DefineColor("DeepGrey", 0.13, 0.13, 0.13);
	DefineColor("DarkTurquoise", 0.23, 0.47, 0.66);
	DefineColor("DarkTurquoise2", 0.25, 0.49, 0.68);
	DefineColor("DarkTurquoise1", 0.26, 0.50, 0.69);
	DefineColor("DarkTurquoise", 0.27, 0.51, 0.70);
	DefineColor("SteelBlue", 0.15, 0.47, 0.74);
	DefineColor("Wheat1", 1, 0.9, 0.74);
	DefineColor("Sienna3", 0.63, 0.18, 0.04);
	DefineColor("GreyGreen", 0.16, 0.46, 0.33);
	DefineColor("DarkTurquoise2", 0.18, 0.48, 0.35);
	DefineColor("DarkTurquoise1", 0.19, 0.49, 0.36);
	DefineColor("DarkTurquoise", 0.2, 0.5, 0.37);
	DefineColor("DarkGreen", 0.13, 0.32, 0.23);
	DefineColor("DarkYellow", 0.78, 0.58, 0.17);
	DefineColor("Tan", 0.5, 0.27, 0.02);
	DefineColor("LightYellow", 0.87, 0.80, 0.33);
}


void InitialTable(void) 
{
	InitialTableColor();
	switch (BilliardbMode) {
		case SNOOKER:                                    //snooker
			TableWidth = 12, TableHeight = 6;
			break;

		case SIDE_POCKET:		                          //花式九球
			TableWidth = 10.8; TableHeight = 6;
			break;

		case AMERICAN:									  //美式落袋
			TableWidth = 11; TableHeight = 6;
			break;
	}
}


void DrawDecoration1(double tempx, double tempy, int isX)
{
	int i = 1;
	double gap = (TableWidth / 2 - 1.1) / 3;

	if (isX) {
		gap = (TableWidth / 2 - 1.1) / 3;
		for (i = 1; i < 3; i++)
		{
			tempx += gap;
			MovePen(tempx + 0.05, tempy);
			DrawArc(0.05, 0, 360);
		}
	}
	else {
		gap = (TableHeight - 1.6) / 3;
		for (i = 1; i < 3; i++)
		{
			tempy += gap;
			MovePen(tempx + 0.05, tempy);
			DrawArc(0.05, 0, 360);
		}
	}
}


void DrawSnookerTable(double x, double y)
{
	double x0; double y0;
	x0 = x - TableWidth / 2;
	y0 = y - TableHeight / 2;
	HoleRadius = 0.3;
	//DefineColor("LightGolden", 0.93, 0.87, 0.5);      //画白边
	SetPenColor("LightGolden");
	StartFilledRegion(1);
	SetPenSize(1);
	MovePen(x0, y0);
	DrawRoundBox(x0, y0, TableWidth, TableHeight, 0.2);
	EndFilledRegion();
	SetPenSize(2);
	SetPenColor("Brown");                                             //画外侧
	MovePen(x0 + 0.8, y0);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + TableWidth / 2 + 0.3, y0);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + 0.8, y0 + TableHeight - 0.3);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + TableWidth / 2 + 0.3, y0 + TableHeight - 0.3);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0, y0 + 0.8);
	StartFilledRegion(1);
	DrawBox(0.3, TableHeight - 1.6);
	EndFilledRegion();

	MovePen(x0 + TableWidth - 0.3, y0 + 0.8);
	StartFilledRegion(1);
	DrawBox(0.3, TableHeight - 1.6);
	EndFilledRegion();


	//DefineColor("SpringGreen3", 0, 0.5, 0.23);                  //画内侧    
	SetPenColor("SpringGreen3");
	StartFilledRegion(1);
	MovePen(x0 + 0.3, y0 + 0.3);
	DrawBox(TableWidth - 0.6, TableHeight - 0.6);
	EndFilledRegion();

	//DefineColor("SpringGreen4", 0.01, 0.52, 0.24);
	SetPenColor("SpringGreen4");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 10, y0 + TableHeight / 2);
	DrawEllipticalArc(0.4* TableWidth, 0.4 * TableHeight, 180, 360);
	EndFilledRegion();

	//DefineColor("SpringGreen1", 0.02, 0.53, 0.25);
	SetPenColor("SpringGreen1");
	StartFilledRegion(1);
	MovePen(x0 + 0.2* TableWidth, y0 + TableHeight / 2);
	DrawEllipticalArc(0.3 * TableWidth, TableHeight * 0.3, 180, 360);
	EndFilledRegion();

	//DefineColor("SpringGreen2", 0.03, 0.54, 0.26);
	SetPenColor("SpringGreen2");
	StartFilledRegion(1);
	MovePen(x0 + 0.3*TableWidth, y0 + TableHeight / 2);
	DrawEllipticalArc(0.2* TableWidth, TableHeight / 5, 180, 360);
	EndFilledRegion();

	SetPenColor("White");     //////////////////////开球线
	SetPenSize(1);
	MovePen(x0 + 2.9, y0 + 0.5);
	DrawLine(0, TableHeight - 1);
	MovePen(x0 + 2.9, y + 8 * BallRadius);
	DrawArc(8 * BallRadius, 90, 180);


	//DefineColor("DarkGreen", 0.13, 0.54, 0.13);			   //画边边
	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + 0.7, y0 + 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.2, 0.1, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.2, 0.1, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + 0.7, y0 + TableHeight - 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.2, 0.1, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.2, 0.1, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.3, y0 + 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.1, 0.2, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.1, 0.2, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.3, y0 + TableHeight - 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.1, 0.2, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.1, 0.2, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + 0.3, y0 + 0.7);
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, 0.2, 0.2, 0.2, 1);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, 0.2, 0.2, 0.2, 1);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.3, y0 + 0.7);
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, -0.2, 0.2, 0.2, 1);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, -0.2, 0.2, 0.2, 1);


	SetPenColor("Black");                          //画球洞
	StartFilledRegion(1);
	MovePen(x0 + 0.4 + 0.3, y0 + 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.25, y0 + 0.3);
	DrawArc(0.25, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.4 + 0.3, y0 + 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + 0.4 + 0.3, y0 + TableHeight - 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.25, y0 + TableHeight - 0.3);
	DrawArc(0.25, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.4 + 0.3, y0 + TableHeight - 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	SetPenColor("Black");
	SetPenSize(3);
	DrawRoundBox(x0, y0, TableWidth, TableHeight, 0.2);
}


void DrawSidepocketTable(double x, double y)
{
	double x0, y0;
	x0 = x - TableWidth / 2;
	y0 = y - TableHeight / 2;

	//DefineColor("Silver", 0.8, 0.8, 0.8);      //画白边
	SetPenColor("Silver");
	StartFilledRegion(1);
	SetPenSize(1);
	MovePen(x0, y0);
	DrawRoundBox(x0, y0, TableWidth, TableHeight, 0.2);
	EndFilledRegion();
	SetPenSize(2);
	//DefineColor("DeepGrey", 0.13, 0.13, 0.13);
	SetPenColor("DeepGrey");		                  //外侧轮廓
	MovePen(x0 + 0.8, y0);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + TableWidth / 2 + 0.3, y0);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + 0.8, y0 + TableHeight - 0.3);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + TableWidth / 2 + 0.3, y0 + TableHeight - 0.3);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0, y0 + 0.8);
	StartFilledRegion(1);
	DrawBox(0.3, TableHeight - 1.6);
	EndFilledRegion();

	MovePen(x0 + TableWidth - 0.3, y0 + 0.8);
	StartFilledRegion(1);
	DrawBox(0.3, TableHeight - 1.6);
	EndFilledRegion();      // DefineColor("DarkTurquoise", 0.27, 0.51, 0.70);


	//DefineColor("DarkTurquoise", 0.23, 0.47, 0.66);                  //画内侧    
	SetPenColor("DarkTurquoise");
	StartFilledRegion(1);
	MovePen(x0 + 0.3, y0 + 0.3);
	DrawBox(TableWidth - 0.6, TableHeight - 0.6);
	EndFilledRegion();

	//DefineColor("DarkTurquoise2", 0.25, 0.49, 0.68);
	SetPenColor("DarkTurquoise2");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 10, y0 + TableHeight / 2);
	DrawEllipticalArc(0.4 * TableWidth, 0.4 * TableHeight, 180, 360);
	EndFilledRegion();

	//DefineColor("DarkTurquoise1", 0.26, 0.50, 0.69);
	SetPenColor("DarkTurquoise1");
	StartFilledRegion(1);
	MovePen(x0 + 0.2 * TableWidth, y0 + TableHeight / 2);
	DrawEllipticalArc(0.3 * TableWidth, TableHeight * 0.3, 180, 360);
	EndFilledRegion();

	//DefineColor("DarkTurquoise", 0.27, 0.51, 0.70);
	SetPenColor("DarkTurquoise");
	StartFilledRegion(1);
	MovePen(x0 + 0.3 * TableWidth, y0 + TableHeight / 2);
	DrawEllipticalArc(0.2 * TableWidth, TableHeight / 5, 180, 360);
	EndFilledRegion();




	//DefineColor("SteelBlue", 0.15, 0.47, 0.74);			   //画边边
	SetPenColor("SteelBlue");
	StartFilledRegion(1);
	MovePen(x0 + 0.7, y0 + 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.2, 0.1, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.2, 0.1, 0);

	SetPenColor("SteelBlue");
	StartFilledRegion(1);
	MovePen(x0 + 0.7, y0 + TableHeight - 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.2, 0.1, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.2, 0.1, 0);

	SetPenColor("SteelBlue");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.3, y0 + 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.1, 0.2, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.1, 0.2, 0);

	SetPenColor("SteelBlue");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.3, y0 + TableHeight - 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.1, 0.2, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.1, 0.2, 0);

	SetPenColor("SteelBlue");
	StartFilledRegion(1);
	MovePen(x0 + 0.3, y0 + 0.7);
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, 0.2, 0.2, 0.2, 1);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, 0.2, 0.2, 0.2, 1);

	SetPenColor("SteelBlue");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.3, y0 + 0.7);
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, -0.2, 0.2, 0.2, 1);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, -0.2, 0.2, 0.2, 1);


	SetPenColor("Black");                               //画球洞
	StartFilledRegion(1);
	MovePen(x0 + 0.4 + 0.3, y0 + 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.25, y0 + 0.3);
	DrawArc(0.25, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.4 + 0.3, y0 + 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + 0.4 + 0.3, y0 + TableHeight - 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.25, y0 + TableHeight - 0.3);
	DrawArc(0.25, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.4 + 0.3, y0 + TableHeight - 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	double tempx = x0 + 0.8, tempy = y0 + 0.15;             //加些细节
	SetPenColor("Silver");
	DrawDecoration1(tempx, tempy, 1);
	tempx = x0 + TableWidth / 2 + 0.3;
	DrawDecoration1(tempx, tempy, 1);
	tempy = y0 + TableHeight - 0.15;
	DrawDecoration1(tempx, tempy, 1);
	tempx = x0 + 0.8;
	DrawDecoration1(tempx, tempy, 1);
	tempx = x0 + 0.15; tempy = y0 + 0.8;
	DrawDecoration1(tempx, tempy, 0);
	tempx = x0 + TableWidth - 0.15;
	DrawDecoration1(tempx, tempy, 0);

	SetPenColor("Black");
	SetPenSize(3);
	DrawRoundBox(x0, y0, TableWidth, TableHeight, 0.2);

	SetPenColor("White");     //////////////////////开球线
	SetPenSize(1);
	MovePen(x0 + TableWidth / 4, y0 + 0.5);
	DrawLine(0, TableHeight - 1);
}


void DrawAmericanTable(double x, double y) {
	double x0, y0;
	x0 = x - TableWidth / 2;
	y0 = y - TableHeight / 2;


	//DefineColor("Wheat1", 1, 0.9, 0.74);      //画白边
	SetPenColor("Wheat1");
	StartFilledRegion(1);
	SetPenSize(1);
	DrawRoundBox(x0, y0, TableWidth, TableHeight, 0.2);
	EndFilledRegion();
	SetPenSize(2);

	//DefineColor("Sienna3", 0.63, 0.18, 0.04);
	SetPenColor("Sienna3");		                  //外侧轮廓
	MovePen(x0 + 0.8, y0);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + TableWidth / 2 + 0.3, y0);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + 0.8, y0 + TableHeight - 0.3);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0 + TableWidth / 2 + 0.3, y0 + TableHeight - 0.3);
	StartFilledRegion(1);
	DrawBox(TableWidth / 2 - 1.1, 0.3);
	EndFilledRegion();

	MovePen(x0, y0 + 0.8);
	StartFilledRegion(1);
	DrawBox(0.3, TableHeight - 1.6);
	EndFilledRegion();

	MovePen(x0 + TableWidth - 0.3, y0 + 0.8);
	StartFilledRegion(1);
	DrawBox(0.3, TableHeight - 1.6);
	EndFilledRegion();

	SetPenColor("GreyGreen");
	StartFilledRegion(1);
	MovePen(x0 + 0.3, y0 + 0.3);
	DrawBox(TableWidth - 0.6, TableHeight - 0.6);
	EndFilledRegion();

	//DefineColor("DarkTurquoise2", 0.18, 0.48, 0.35);
	SetPenColor("DarkTurquoise2");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 10, y0 + TableHeight / 2);
	DrawEllipticalArc(0.4 * TableWidth, 0.4 * TableHeight, 180, 360);
	EndFilledRegion();

	//DefineColor("DarkTurquoise1", 0.19, 0.49, 0.36);
	SetPenColor("DarkTurquoise1");
	StartFilledRegion(1);
	MovePen(x0 + 0.2 * TableWidth, y0 + TableHeight / 2);
	DrawEllipticalArc(0.3 * TableWidth, TableHeight * 0.3, 180, 360);
	EndFilledRegion();

	//DefineColor("DarkTurquoise", 0.2, 0.5, 0.37);
	SetPenColor("DarkTurquoise");
	StartFilledRegion(1);
	MovePen(x0 + 0.3 * TableWidth, y0 + TableHeight / 2);
	DrawEllipticalArc(0.2 * TableWidth, TableHeight / 5, 180, 360);
	EndFilledRegion();

	//DefineColor("DarkGreen", 0.13, 0.32, 0.23);			   //画边边
	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + 0.7, y0 + 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.2, 0.1, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.2, 0.1, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + 0.7, y0 + TableHeight - 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.2, 0.1, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.2, 0.1, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.3, y0 + 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.1, 0.2, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, 0.2, 0.1, 0.2, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.3, y0 + TableHeight - 0.3);
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.1, 0.2, 0);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableWidth / 2 - 1.3, TableWidth / 2 - 1, -0.2, 0.1, 0.2, 0);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + 0.3, y0 + 0.7);
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, 0.2, 0.2, 0.2, 1);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, 0.2, 0.2, 0.2, 1);

	SetPenColor("DarkGreen");
	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.3, y0 + 0.7);
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, -0.2, 0.2, 0.2, 1);
	EndFilledRegion();
	SetPenColor("Black");
	MyDrawEdge(TableHeight - 1.8, TableHeight - 1.4, -0.2, 0.2, 0.2, 1);

	SetPenColor("Black");                          //画球洞
	StartFilledRegion(1);
	MovePen(x0 + 0.4 + 0.3, y0 + 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.25, y0 + 0.3);
	DrawArc(0.25, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.4 + 0.3, y0 + 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + 0.4 + 0.3, y0 + TableHeight - 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth / 2 + 0.25, y0 + TableHeight - 0.3);
	DrawArc(0.25, 0, 360);
	EndFilledRegion();

	StartFilledRegion(1);
	MovePen(x0 + TableWidth - 0.4 + 0.3, y0 + TableHeight - 0.4);
	DrawArc(0.3, 0, 360);
	EndFilledRegion();

	//DefineColor("DarkYellow", 0.78, 0.58, 0.17);                       //加点装饰
	SetPenColor("DarkYellow");
	MovePen(x0 + TableWidth / 4, y0);
	StartFilledRegion(1);
	DrawBox(0.3, 0.2);
	EndFilledRegion();
	SetPenColor("Black");
	DrawBox(0.3, 0.2);

	SetPenColor("Black");
	SetPenSize(3);
	DrawRoundBox(x0, y0, TableWidth, TableHeight, 0.2);
}


//以(x,y)为中心画，样式为styled的球桌；
void ShowBackGround(void) 
{
	SetPenSize(1);
	//DefineColor("Tan", 0.5, 0.27, 0.02);
	SetPenColor("Tan");
	StartFilledRegion(1);
	MovePen(0, 0);
	DrawBox(GetWindowWidth(), GetWindowHeight());
	EndFilledRegion();
	SetPenColor("Black");
	double backx, backy;
	double boxl = 1, boxh = 1.6;
	for (backx = 0; backx < GetWindowWidth(); backx += 2 * boxl) 
	{
		for (backy = 0; backy < GetWindowHeight(); backy += boxh) 
		{
			MovePen(backx, backy);
			DrawBox(boxl, boxh);
		}
		for (backy = boxh / 2; backy < GetWindowHeight(); backy += boxh) 
		{
			MovePen(backx + boxl, backy);
			DrawBox(boxl, boxh);
		}
	}
}


void ShowBilliardTable(double x, double y, int style)
{

	ShowBackGround();
	ShowScore();
	ShowTurn();
	switch (style) 
	{
		case SNOOKER:                                    //snooker
			TableWidth = 12, TableHeight = 6;
			DrawSnookerTable(x, y);
			break;

		case SIDE_POCKET:		                          //花式九球
			TableWidth = 10.8; TableHeight = 6;
			DrawSidepocketTable(x, y);
			break;

		case AMERICAN:									  //美式落袋
			TableWidth = 11; TableHeight = 6;
			DrawAmericanTable(x, y);
			break;

		case ENTERTAINMENT:									  //美式落袋
			TableWidth = 10.8; TableHeight = 6;
			DrawSidepocketTable(x, y);
			break;
	}
}


//以（x,y）为中心，画一个角度为angle(x正半轴为0度，逆时针为正，单位DEG角度制),样式为style的球杆
void ShowBilliardCue(double x, double y, double angle, int style)
{
	double CueAngle = 1;                 //球杆杆体的角度
	double LineAngle1 = angle - CueAngle / 2;
	double LineAngle2 = angle + CueAngle / 2;
	double CenterX = x - 2 * cos(angle * PI / 180);
	double CenterY = y - 2 * sin(angle * PI / 180);

	MovePen(x + 0.2, y);
	//DrawArc(0.2, 0, 360);

	switch (style) 
	{
	case 1:


		move(CenterX, CenterY, LineAngle1, 2.5);
		SetPenColor("Brown");
		SetPenSize(1);
		StartFilledRegion(1);
		forward(LineAngle1, 4);
		DrawArc(6.5, LineAngle1, CueAngle);
		forward(LineAngle2, -4);
		DrawArc(2.5, LineAngle2, -CueAngle);
		EndFilledRegion();

		DefineColor("LightYellow", 0.87, 0.80, 0.33);
		SetPenColor("LightYellow");

		StartFilledRegion(1);
		forward(LineAngle1, 2);
		DrawArc(4.5, LineAngle1, CueAngle);
		forward(LineAngle2, -2);
		DrawArc(2.5, LineAngle2, -CueAngle);
		EndFilledRegion();

		SetPenColor("Black");
		SetPenSize(2);
		move(CenterX, CenterY, LineAngle1, 2.5);                                   //最后一个参数由球的半径决定，后面再改
		forward(LineAngle1, 4);
		DrawArc(6.5, LineAngle1, CueAngle);

		forward(LineAngle2, -4);
		DrawArc(2.5, LineAngle2, -CueAngle);
	}
}


void ShowSightLine(double x1, double y1, double x2, double y2, int style)
{
	SetPenColor("white");
	SetPenSize(1);
	MovePen(x1, y1);
	forward(CueAngle * 180 / PI + 180, DISTANCE(x1, y1, x2, y2)*1.5);

	DrawArc(BallList->radius, CueAngle * 180 / PI, 360);
}
