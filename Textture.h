#pragma once
#include "graphics.h"

class Textture{
	public:
		int x = 0,
			y = 0;
		int width = 0,
			height = 0;
		char* content;
		
		int color = BLACK,
			bgColor = LIGHTGRAY,
			bdColor = BLUE,
			bdSize = 2;
			
		int atColor = WHITE,
			atBgColor = BLUE,
			atBdColor = BLACK,
			atBdSize = 2;
		
		int crColor = {},
			crBgColor = {},
			crBdColor = {},
			crBdSize = {};
		
		bool isSelect(){
			int mx = getx(),
				my = gety();
			return mx > x - crBdSize && mx < x + width + crBdSize && my > y - crBdSize && my < y + height + crBdSize;
		}
			
		Textture(const int& sx, const int& sy, const int& swidth, const int& sheight, const char* scontent="Textture"){
			x = sx;
			y = sy;
			width = swidth;
			height = sheight;
			strcpy(content, scontent);
		}
		
		Textture(){
			
		}
		
		
};
