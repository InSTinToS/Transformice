#ifndef GETRANDOM_H
	#define GETRANDOM_H


	int generateRandom	(int min,int max)
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
		int num = generateRandom(min, max);
		if (num != forb)
			return num;
		else
			getRandomForb(min,max, forb);
	}

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

#endif