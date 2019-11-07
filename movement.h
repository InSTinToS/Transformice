#ifndef MOVEMENT_H
	#define MOVEMENT_H

	#include "random.h"
	#include "create.h"
	
	using namespace std;

	bool cheeseVerify		(int matrix[9][9], int i, int j)
	{
		if(matrix[i][j] == 4)
			return true;
		return false;
	}

	int threeWallsVerify	(int matrix[9][9], int i, int j)
	{
		int counterWalls = 0;
		if(matrix[i - 1][j] < 1)
			counterWalls++;
			
		if(matrix[i][j - 1] < 1)
			counterWalls++;
			
		if(matrix[i + 1][j] < 1)
			counterWalls++;
			
		if(matrix[i][j + 1] < 1)
			counterWalls++;
		return counterWalls;
	}

	int makeChoice			(int matrix[9][9],int i, int j)
	{
		int choice = random(0,3);
		switch (choice)
		{
			case 0:
				if (matrix[i - 1][j] >= 2)
					return choice;
			break;

			case 1:
				if (matrix[i][j - 1] >= 2)
					return choice;
			break;

			case 2:
				if (matrix[i + 1][j] >= 2)
					return choice;
			break;

			case 3:
				if (matrix[i][j + 1] >= 2)
					return choice;
			break;
		}
		return makeChoice(matrix, i, j);
	}

	void retreatMove		(int matrix[9][9], int i, int j, int prop, int capture, int aux)
	{
		switch (aux)
		{
			case 0:
				i = i - 1;
				create_MoveToRight	(i, j, prop, matrix, true);
			break;

			case 1:
				j = j - 1;
				create_MoveToDown	(i, j, prop, matrix, true);
			break;
			
			case 2:
				i = i + 1;
				create_MoveToLeft	(i, j, prop, matrix, true);
			break;

			case 3:
				j = j + 1;
				create_MoveToUp		(i, j, prop, matrix, true);
			break;
		}
	}

	int generalMove			(int matrix[9][9], int i, int j, int prop)
	{
		int choice = makeChoice(matrix, i, j);
		bool capture = cheeseVerify(matrix, i, j);
	
		switch (choice)
		{
			case 0:
					if (capture == false)
					{
						create_MoveToLeft		(i, j, prop, matrix, capture);
						int aux = generalMove	(matrix, --i, j, prop);
						retreatMove				(matrix, i, j, prop, capture, aux);
						return choice;
					}
					else
					{
						create_MoveToLeft		(i, j, prop, matrix, capture);
						return 0;
					}
			break;

			case 1:
					if (capture == false)
					{
						create_MoveToUp			(i, j, prop, matrix, capture);
						int aux = generalMove	(matrix, i, --j, prop);
						retreatMove				(matrix, i, j, prop, capture, aux);
						return choice;
					}
					else
					{
						create_MoveToUp			(i, j, prop, matrix, capture);
						return 1;
					}
			break;

			case 2:
					if (capture == false)
					{
						create_MoveToRight		(i, j, prop, matrix, capture);
						int aux = generalMove	(matrix, ++i, j, prop);
						retreatMove				(matrix, i, j, prop, capture, aux);
						return choice;
					}
					else
					{
						create_MoveToRight		(i, j, prop, matrix, capture);
						return 2;
					}
			break;

			case 3:
					if (capture == false)
					{
						create_MoveToDown		(i, j, prop, matrix, capture);
						int aux = generalMove	(matrix, i, ++j, prop);
						retreatMove				(matrix, i, j, prop, capture, aux);
						return choice;
					}
					else
					{	
						create_MoveToDown		(i, j, prop, matrix, capture);
						return 3;
					}
			break;
		}
	}

	void masterMove			(int matrix[9][9], int i, int j, int prop)
	{
		retreatMove(matrix, i, j, prop, true, generalMove(matrix, i, j, prop));
	}

#endif 