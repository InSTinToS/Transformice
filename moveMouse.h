#ifndef MOVEMOUSE_H
	#define MOVEMOUSE_H

	#include "getRandom.h"
	#include "createForms.h"

	void generalMove(int matrix[9][9], int i, int j, ALLEGRO_BITMAP* mouse, ALLEGRO_DISPLAY* display, int last)
	{
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);
		ALLEGRO_COLOR pink = al_map_rgb(255,0,127);

		int counterWalls = 0 ;

		if(matrix[i - 1][j] < 1)
			counterWalls++;
			
		if(matrix[i][j - 1] < 1)
			counterWalls++;
			
		if(matrix[i + 1][j] < 1)
			counterWalls++;
			
		if(matrix[i][j + 1] < 1)
			counterWalls++;

		// criar parede se for sem saida cor rosa
		if(counterWalls==3)
		{
			if(matrix[i - 1][j] > 0 )
			{
				matrix[i][j] = 0;
				last = 0;
				createMoveToLeft(i , j, pink);				
				al_flip_display();
				generalMove(matrix, --i, j, mouse, display, last);
			}
				
			if(matrix[i][j - 1]> 0)
			{
				createMoveToUp(i , j, pink);
				al_flip_display();
				matrix[i][j] = 0;
				last=1;
				generalMove(matrix, i, --j, mouse, display,last);
			}
				
			if(matrix[i + 1][j]> 0)
			{
				createMoveToRight(i , j, pink);
				al_flip_display();
				matrix[i][j] = 0;
				last=2;
				generalMove(matrix, ++i, j, mouse, display,last);
			}
				
			if(matrix[i][j + 1] > 0)
			{
				createMoveToDown(i , j, pink);
				al_flip_display();
				matrix[i][j] = 0;
				last=3;
				generalMove(matrix, i, ++j, mouse, display,last);
			}
		}
		// escolhas normais aleatorias
		else if (counterWalls < 3)
		{
			int choice = getRandom(0,3);
			switch (choice)
			{
				case 0:
					if (matrix[i - 1][j] >= 1 && last != 2)
					{
						matrix[i][j] = 1;
						last = 	createMoveToLeft(i, j, blue);;
						al_flip_display();
						generalMove(matrix, --i, j, mouse, display,last);
					}
					else
						generalMove(matrix, i, j, mouse, display,last);
					break;

				case 1:
					if (matrix[i][j - 1] >= 1 && last != 3)
					{
						matrix[i][j] = 1;
						last = 	createMoveToUp(i, j, blue);;
						al_flip_display();
						generalMove(matrix, i, --j, mouse, display,last);
					}
					else
						generalMove(matrix, i, j, mouse, display,last);
					break;

				case 2:
					if (matrix[i + 1][j] >= 1 && last != 0)
					{
						matrix[i][j] = 1;
						last = 	createMoveToRight(i, j, blue);;
						al_flip_display();
						generalMove(matrix, ++i, j, mouse, display,last);
					}
					else
						generalMove(matrix, i, j, mouse, display,last);
					break;
				case 3:
					if (matrix[i][j + 1] >= 1 && last != 1)
					{
						matrix[i][j] = 1;
						last = 	createMoveToDown(i, j, blue);;
						al_flip_display();
						generalMove(matrix, i, ++j, mouse, display,last);
					}
					else
						generalMove(matrix, i, j, mouse, display,last);
					break;
			}
		}
		Sleep(1000);
		al_destroy_display(display);
	}

	void putMouseInLair	(int matrix[9][9], ALLEGRO_BITMAP* mouse,ALLEGRO_DISPLAY* display)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] == 4) 
				{
					int cordX1 = (i + 1) * 100;
					int cordY1 = (j + 1) * 100;
				
					al_draw_bitmap(mouse, cordX1, cordY1, NULL);
					al_flip_display();
					generalMove(matrix, i, j, mouse,display,-1);

					i = 9;
					j = 9;
				}
			}
		}
	}

	void moveMouse		(int matrix[9][9],ALLEGRO_DISPLAY* display) 
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");
		putMouseInLair(matrix, mouse, display);
	}

#endif 

