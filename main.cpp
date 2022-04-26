
#include "include/Screen.h"
#include "include/Button.h"
#include<iostream>

using namespace std;

void fc(int x, int y){
	cout<<x<<":"<<y<<'\n';
}

int main(){

	initwindow(900,500);
	
	registermousehandler(WM_MOUSEWHEEL,fc);
	
	getch();
	closegraph();
	return 0;
	

}
