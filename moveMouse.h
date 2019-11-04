#ifndef MOVEMOUSE_H
	#define MOVEMOUSE_H

	#include "getRandom.h"
	#include "create.h"

	using namespace std;

	bool verificaQueijo(int matrix[9][9], int i, int j)
	{
		if(matrix[i][j] == 4)
			return true;
		return false;
	}

	int verificaSaida(int matrix[9][9], int i, int j)
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

	void retro (int aux, int i, int j, ALLEGRO_COLOR blue)
	{
		switch (aux)
		{
			case 0:
				i = i - 1;
				createMoveToRight(i, j, blue);
			break;

			case 1:
				j = j - 1;
				createMoveToDown(i, j, blue);
			break;
			
			case 2:
				i = i + 1;
				createMoveToLeft(i, j, blue);
			break;

			case 3:
				j = j + 1;
				createMoveToUp(i, j, blue);
			break;
		}
	}

	int formaChoice(int matrix[9][9],int i, int j)
	{
		int choice = getRandom(0,3);
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
		return formaChoice(matrix, i, j);
	}

	int generalMove(int matrix[9][9], int i, int j)
	{
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);
		ALLEGRO_COLOR pink = al_map_rgb(255, 0, 127);
		ALLEGRO_COLOR yellow = al_map_rgb(249, 166, 2);

		int choice = formaChoice(matrix, i, j);
		int capture = verificaQueijo(matrix, i, j);
	
		switch (choice)
		{
			case 0:
					if (capture == false)
					{
						createMoveToLeft(i,j,blue);
						int aux = generalMove(matrix, --i, j);
						retro(aux, i, j, blue);
						return choice;
					}
					else
					{
						createMoveToLeft(i, j, blue);
						return 0;
					}
			break;

			case 1:
					if (capture == false)
					{
						createMoveToUp(i,j,blue);
						int aux = generalMove(matrix, i, --j);
						retro(aux, i, j, blue);
						return choice;
					}
					else
					{
						createMoveToUp(i, j, blue);
						return 1;
					}
			break;

			case 2:
					if (capture == false)
					{
						createMoveToRight(i,j,blue);
						int aux = generalMove(matrix, ++i, j);
						retro(aux, i, j, blue);
						return choice;
					}
					else
					{
						createMoveToRight(i, j, blue);
						return 2;
					}
			break;

			case 3:
					if (capture == false)
					{
						createMoveToDown(i,j,blue);
						int aux = generalMove(matrix, i, ++j);
						retro(aux, i, j, blue);
						return choice;
					}
					else
					{	
						createMoveToDown(i, j, blue);
						return 3;
					}
			break;
		}
	}

	void masterMove(int matrix[9][9], int i, int j, ALLEGRO_DISPLAY* display)
	{
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);
		retro (generalMove(matrix, i, j), i, j, blue);
		Sleep(1000);
		al_destroy_display(display);
	}

#endif 

