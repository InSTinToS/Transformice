#ifndef GETRANDOM_H
	#define GETRANDOM_H

		int getRandom()
		{
			static int Init = 0;

			int min = 0;
			int max = 1;

			if (Init == 0) 
			{
				srand(time(NULL));
				Init = 1;
			}

			return (rand() % (max - min + 1) + min);
		}

#endif