#ifndef FORMWALL_H
	#define FORMWALL_H
	
	#include "moveMouse.h"
	#include "getRandom.h"
	#include "createForms.h"

	using namespace std;

	void putObjects	(int matrix[9][9], int lairCount, int cheeseCount)
	{
		int j = getRandom(1, 7);
		int i = getRandom(1, 7);

		if (matrix[i][j] == 0)
		{
			if (lairCount == 1)
			{
				createCheese(i, j);
				matrix[i][j] = 2;
				cheeseCount++;
			}
			if (lairCount == 0)
			{
				createLair(i, j);
				matrix[i][j] = 3;
				lairCount++;
			}
		}

		if (cheeseCount == 0 || lairCount == 0)
			putObjects(matrix, lairCount, cheeseCount);
	}

	void formWall	(int multiWidth)
	{
		const int size = 9;
		int matrix[size][size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == 0 || j == 0 || i == 8 || j == 8)
					matrix[i][j] = 9;
				else 
					matrix[i][j] = getRandom(0, 1);
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] == 0)
					createRectangleLight(multiWidth, i, j);
				if (matrix[i][j] == 1)
					createRectangleDark(multiWidth, i, j);
			}
		}

		putObjects(matrix,0,0);
		moveMouse(matrix);
	}
	
#endif