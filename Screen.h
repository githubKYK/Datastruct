#pragma once
#include "graphics.h"
#include "Button.h"
#include <cstring>

class Screen{
	public:
		char name[10];
		
		Button *listButton;
		int numButton = 0;
	
		Screen(){
			
		}
	
		Screen(char* sname = "SCR"){
			strcpy(name,sname);
		}
		
		~Screen(){
			if(listButton){
				delete[] listButton;
			}
		}
	
		void display(){
			for(int i = 0; i < numButton; i++){
				listButton[i].display(listButton[i].mode);
			}
		}
};
