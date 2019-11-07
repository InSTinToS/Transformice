#ifndef RANDOM_H
	#define RANDOM_H
	
	#include <time.h>
	#include <windows.h>

	int random		(int min,int max)
	{
		static int Init = 0;

		if (Init == 0) 
		{
			srand(time(NULL));
			Init = 1;
		}

		return (rand() % (max - min + 1) + min);
	}

	int randomForb	(int min,int max,int forb)
	{
		int num = random(min, max);
		if (num != forb)
			return num;
		else
			randomForb(min,max, forb);
	}

#endif