#ifndef PUT_H
  	#define PUT_H
	
	#include "create.h"
	#include "random.h"

	void put_LairAndCheese	(int matrix[9][9], int lairCount, int cheeseCount)
	{
		int j = random(1, 7);
		int i = random(1, 7);

		if (matrix[i][j] == 2)
		{
			if (lairCount == 1)
			{
				create_Cheese(i, j);
				matrix[i][j] = 4;
				cheeseCount++;
			}
			if (lairCount == 0)
			{
				create_Lair(i, j);
				matrix[i][j] = 3;
				lairCount++;
			}
		}

		if (cheeseCount == 0 || lairCount == 0)
			put_LairAndCheese(matrix, lairCount, cheeseCount);
	}

	void put_MouseInLair	(int matrix[9][9], ALLEGRO_DISPLAY* display)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] == 3) 
				{
					create_Mouse(i, j);
					i = 9;
					j = 9;
				}
			}
		}
	}

	void put_LimitAndWalls	(int matrix[9][9], ALLEGRO_DISPLAY* display)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i == 0 || j == 0 || i == 8 || j == 8)
					matrix[i][j] = -1;
				else 
					matrix[i][j] = randomExcept(0, 2, 1);
			}
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] == 2)
					create_LightRectangle (i, j);
				if (matrix[i][j] == 0)
					create_DarkRectangle(i, j);
			}
		}
	}

#endif