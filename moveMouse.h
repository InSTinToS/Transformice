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

	void generalMove(int matrix[9][9], int i, int j, ALLEGRO_BITMAP* mouse, ALLEGRO_DISPLAY* display, int vector[],int k, int capture, int verify)
	{
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);
		ALLEGRO_COLOR pink = al_map_rgb(255, 0, 127);
		ALLEGRO_COLOR yellow = al_map_rgb(249, 166, 2);

		int counterWalls =  verificaSaida(matrix, i, j);

		if(capture == 1)
		{
			if (verify == 0) {
				cout << "primeiro vector: ";
				cout << vector[k] << endl;
				cout << "primeiro k: ";
				cout << "k = " << k << endl;
				k = k - 1;
			}
			cout << "k = " << k << endl;
			cout << vector[k] << endl;

			if (vector[k] == 0)
			{
				cout << "moveu para: " << createMoveToRight(i , j, yellow) << endl;
				al_flip_display;
				generalMove(matrix, ++i, j, mouse, display, vector, --k, 1, 1);
			}
			else if (vector[k] == 1)
			{
				cout << "moveu para: " << createMoveToDown(i , j, yellow) << endl;
				al_flip_display;
				generalMove(matrix, i, ++j, mouse, display, vector, --k, 1, 1);
			}
			else if (vector[k] == 2)
			{
				cout << "moveu para: " << createMoveToLeft(i , j, yellow) << endl;
				al_flip_display;
				generalMove(matrix, --i, j, mouse, display, vector, --k, 1, 1);
			}
			else if (vector[k] == 3)
			{
				cout << "moveu para: " << createMoveToUp(i , j, yellow) << endl;
				al_flip_display;
				generalMove(matrix, i, --j, mouse, display, vector, --k, 1, 1);
			}
			else if (k == -1)
			{
				cout << "k == -1";
			}
			else
			{
				cout << "algo deu errado";
			}
		}
		
		else if(counterWalls == 3)
		{
			if(matrix[i - 1][j] > 0 )
			{
				vector[k] = createMoveToLeft(i , j, pink);
				al_flip_display();
				matrix[i][j] = 0;
				capture = verificaQueijo(matrix, i, j);
				generalMove(matrix, --i, j, mouse, display,vector, ++k, capture, 0);
			}
				
			if(matrix[i][j - 1] > 0)
			{
				vector[k] = createMoveToUp(i , j, pink);
				al_flip_display();
				capture = verificaQueijo(matrix, i, j);
				matrix[i][j] = 0;
				generalMove(matrix, i, --j, mouse, display,vector, ++k, capture, 0);
			}
				
			if(matrix[i + 1][j] > 0)
			{
				vector[k] = createMoveToRight(i , j, pink);
				al_flip_display();
				capture = verificaQueijo(matrix, i, j);
				matrix[i][j] = 0;
				generalMove(matrix, ++i, j, mouse, display,vector, ++k, capture, 0);
			}
				
			if(matrix[i][j + 1] > 0)
			{
				vector[k] = createMoveToDown(i , j, pink);
				al_flip_display();
				capture = verificaQueijo(matrix, i, j); 
				matrix[i][j] = 0;
				generalMove(matrix, i, ++j, mouse, display,vector, ++k, capture, 0);
			}
		}

		else if (counterWalls < 3)
		{
			int choice = getRandom(0,3);
			switch (choice)
			{
				case 0:
					if (matrix[i - 1][j] >= 1)
					{
						vector[k] = createMoveToLeft(i, j, blue);
						al_flip_display();
						capture = verificaQueijo(matrix, i, j);
						matrix[i][j] = 1;
						generalMove(matrix, --i, j, mouse, display, vector, ++k, capture, 0);
					}
					else
						generalMove(matrix, i, j, mouse, display, vector,k, capture, 0);
				break;

				case 1:
					if (matrix[i][j - 1] >= 1)
					{
						vector[k] = createMoveToUp(i, j, blue);
						al_flip_display();
						capture = verificaQueijo(matrix, i, j);
						matrix[i][j] = 1;
						generalMove(matrix, i, --j, mouse, display,vector, ++k, capture, 0);
					}
					else
						generalMove(matrix, i, j, mouse, display, vector, k, capture, 0);
				break;

				case 2:
					if (matrix[i + 1][j] >= 1)
					{
						vector[k] = createMoveToRight(i, j, blue);
						al_flip_display();
						capture = verificaQueijo(matrix, i, j);
						matrix[i][j] = 1;
						generalMove(matrix, ++i, j, mouse, display, vector, ++k, capture, 0);
					}
					else
						generalMove(matrix, i, j, mouse, display, vector, k, capture, 0);
				break;

				case 3:
					if (matrix[i][j + 1] >= 1)
					{
						vector[k] = createMoveToDown(i, j, blue);
						al_flip_display();
						capture = verificaQueijo(matrix, i, j);
						matrix[i][j] = 1;
						generalMove(matrix, i, ++j, mouse, display, vector, ++k, capture, 0);
					}
					else
						generalMove(matrix, i, j, mouse, display, vector, k, capture, 0);
				break;
			}
		}
		
		Sleep(1000);
		al_destroy_display(display);
	}
#endif 

