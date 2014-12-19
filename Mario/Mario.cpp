// TEST

extern"C"{
#include "MonochromeLib.h"
#include "fxlib.h"
#include "stdio.h"
#include "stdlib.h"
#include "SPRITE.h" // sprite de tout
}

#include <iostream>
#include <math.h>

void JouerLevel(int Largeur,int Hauteur,char *Carte){
	

	float x = (Hauteur-1)*Largeur+3;
	int a = 0;
	int i = 0;
	int x2 = 0;

	while(1){
		for(i=(int)x-(Largeur*6)-4;i<=((int)x+Hauteur+12);i++){

			switch (Carte[i]){

				case 1: ML_bmp_or_cl(tile_01,(a%18)*8+x2-8,(a/18)*8,8,8);
						break;
				case 2: ML_bmp_or_cl(tile_02,(a%18)*8+x2-8,(a/18)*8,8,8);
						break;
				case 3: ML_bmp_or_cl(tile_03,(a%18)*8+x2-8,(a/18)*8,8,8);
						break;
				case 4: ML_bmp_or_cl(tile_04,(a%18)*8+x2-8,(a/18)*8,8,8);
						break;
				case 5: ML_bmp_or_cl(tile_05,(a%18)*8+x2-8,(a/18)*8,8,8);
						break;
				case 6: ML_bmp_or_cl(tile_06,(a%18)*8+x2-8,(a/18)*8,8,8);
						break;
				case 7: ML_bmp_or_cl(tile_07,(a%18)*8+x2-8,(a/18)*8,8,8);
						break;
			}

			a++;

			if((a%18)==0) i+=Largeur-18;

		}

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