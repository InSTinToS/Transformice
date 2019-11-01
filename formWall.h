#ifndef FORMWALL_H
	#define FORMWALL_H
	
	#include "moveMouse.h"

	void putObjects	(int matrix[9][9], int lairCount, int cheeseCount)
	{
		int j = getRandom(1, 7);
		int i = getRandom(1, 7);

		if (matrix[i][j] == 2)
		{
			if (lairCount == 1)
			{
				createCheese(i, j);
				matrix[i][j] = 3;
				cheeseCount++;
			}
			if (lairCount == 0)
			{
				createLair(i, j);
				matrix[i][j] = 4;
				lairCount++;
			}
		}

		if (cheeseCount == 0 || lairCount == 0)
			putObjects(matrix, lairCount, cheeseCount);
	}

	void formWall	(int multiWidth, ALLEGRO_DISPLAY* display)
	{
		int matrix[9][9];
		int counterWalls=0;
		int wallLimit=20;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i == 0 || j == 0 || i == 8 || j == 8)
					matrix[i][j] = -1;
				else 
				{
					matrix[i][j] = getRandomForb(0, 2, 1);
				}
			}
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] == 2)
					createRectangleLight(multiWidth, i, j);
				if (matrix[i][j] == 0)
					createRectangleDark(multiWidth, i, j);
			}
		}

		putObjects(matrix,0,0);
		moveMouse(matrix, display);
	}
	
#endif