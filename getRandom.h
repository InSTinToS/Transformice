#ifndef GETRANDOM_H
	#define GETRANDOM_H
	
	#include <windows.h>
	#include <iostream>
	
	int getRandom(int min,int max)
	{
		static int Init = 0;

		if (Init == 0) 
		{
			srand(time(NULL));
			Init = 1;
		}

		return (rand() % (max - min + 1) + min);
	}

	int getRandomForb(int min,int max,int forb)
	{
		int num = getRandom(min, max);
		if (num != forb)
			return num;
		else
			getRandomForb(min,max, forb);
	}

#endif