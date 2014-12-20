
extern"C"{
#include "MonochromeLib.h"
#include "fxlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "SPRITE.h" // sprite de tout
#include <math.h>
}

#include <iostream>

static int SysCallCode[] = {0xD201422B,0x60F20000,0x80010070};
static int (*SysCall)(int R4, int R5, int R6, int R7, int FNo ) = (void*)&SysCallCode;

void JouerLevel(int Largeur,int Hauteur,char *Carte){
	

	float x = (Hauteur-1)*Largeur+3;
	int a = 0;
	int i = 0;
	int x2 = 0;
	int FPS = 0;
	int temps = RTC_getTicks();
	char buffer[50];

	while(1){
		for(i=(int)x-(Largeur*6)-4;i<=((int)x+Hauteur+12);i++){
		ML_bmp_or_cl(*(tile+Carte[i]),(a%18)*8+x2-8,(a/18)*8,8,8);
			
			a++;

			if((a%18)==0) i+=Largeur-18;

		}
	
		
		
		FPS ++;
		if (RTC_getTicks() >= temps + 128){
			temps = RTC_getTicks();
			sprintf(buffer,"%d",FPS);
			FPS = 0;
		}
		
		PrintMini(1,1,buffer,1);
		
		ML_display_vram();
		ML_clear_vram();
		a = 0;

		Sleep(30);

		if(IsKeyDown(KEY_CTRL_RIGHT)){
			x2--;
			if (x2==-8){
				x++;
				x2=0;
			}
		}

		if(IsKeyDown(KEY_CTRL_LEFT)){
			x2++;
			if (x2==8){
				x--;
				x2=0;
			}
		}
		

	}
}

void Action(){
	
}

int RTC_getTicks(void)
{
    return (*SysCall)(0, 0, 0, 0, 0x3B);
}
