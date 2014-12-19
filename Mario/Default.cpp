/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   Project name : Mario			                             */
/*	 Autor : Xavier Bruni										 */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
extern"C"{
#include "fxlib.h"
#include "memory.h"
#include "MonochromeLib.h"
}

#include <iostream>
#include "Map.hpp"

extern "C"{
	int AddIn_main(int isAppli, unsigned short OptionNum)
	{
    	unsigned int key;

    	Bdisp_AllClr_DDVRAM();

    	Map(1);

    	while(1){
        	GetKey(&key);
    	}

    	return 1;
	}

	#pragma section _BR_Size
	unsigned long BR_Size;
	#pragma section


	#pragma section _TOP

	int InitializeSystem(int isAppli, unsigned short OptionNum)
	{
    	return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
	}

	#pragma section

}
