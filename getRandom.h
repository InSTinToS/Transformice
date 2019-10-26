#ifndef GETRANDOM_H
	#define GETRANDOM_H

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