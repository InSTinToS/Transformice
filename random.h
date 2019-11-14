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
	
	/* 
		Linha 7 até 18 
		Ref: https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1042005782&id=1043284385 
	*/

	int randomExcept	(int min,int max,int except)
	{
		int num = random(min, max);
		if (num != except)
			return num;
		else
			randomExcept(min,max, except);
	}

#endif