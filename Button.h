#pragma once
#include "graphics.h"
#include <cstring>

#define NORMAL 0
#define HOVER 1
#define ACTIVE 2

class Button{
	public:
		int x,
			y;
		int width,
			height;
		char content[20];
		
		int color = BLACK,
			bgColor = LIGHTGRAY,
			bdColor = BLUE,
			bdSize = 2;
			
		int hvColor = BLACK,
			hvBgColor = BLUE,
			hvBdColor = BLACK,
			hvBdSize = 2;
			
		int atColor = WHITE,
			atBgColor = BLUE,
			atBdColor = BLACK,
			atBdSize = 2;
		
		int crColor = {},
			crBgColor = {},
			crBdColor = {},
			crBdSize = {};
			
		int id = -1;
			
		bool mode = 0;
			
		Button(){
			x = 0;
			y = 0;
			width = 0;
			height = 0;
		}
			
		Button(const int& sx, const int& sy, const int& swidth, const int& sheight, const char* scontent="Button"){
			x = sx;
			y = sy;
			width = swidth;
			height = sheight;
			strcpy(content, scontent);
		}
			
		bool isSelect(){
			int mx = getx(),
				my = gety();
			return mx > x - crBdSize && mx < x + width + crBdSize && my > y - crBdSize && my < y + height + crBdSize;
		}
		
		int display(const int &status){
			if(status == NORMAL){
				crColor = color;
				crBgColor = bgColor;
				crBdColor= bdColor;
				crBdSize = bdSize;
			}
			else if(status == HOVER){
				crColor = hvColor;
				crBgColor = hvBgColor;
				crBdColor= hvBdColor;
				crBdSize = hvBdSize;
			}
			else if(status == ACTIVE){
				crColor = atColor;
				crBgColor = atBgColor;
				crBdColor= atBdColor;
				crBdSize = atBdSize;
			}
			
			setfillstyle(SOLID_FILL,crBgColor);
			bar(x, y, x + width, y + height);
			
			int th = textheight(content) / 2;
			moveto(x + width / 2, y + height / 2 + th);
			setusercharsize(1, 5, 2, 5);
			settextjustify(CENTER_TEXT, VCENTER_TEXT);
			settextstyle(BOLD_FONT, LEFT_RIGHT, 1);
			setcolor(crColor);
			setbkcolor(crBgColor);
			outtext(content);
			
			setcolor(crBdColor);
			setlinestyle(SOLID_LINE,0,crBdSize);
			rectangle(x, y, x + width, y + height);
			return 1;
		}
};

