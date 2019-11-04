#ifndef PUT_H
	#define PUT_H
	
	#include "create.h"
	#include "moveMouse.h"

	void put_Lair_and_Cheese	(int matrix[9][9], int lairCount, int cheeseCount)
	{
		int j = getRandom(1, 7);
		int i = getRandom(1, 7);

		if (matrix[i][j] == 2)
		{
			if (lairCount == 1)
			{
				createCheese(i, j);
				matrix[i][j] = 4;
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
			put_Lair_and_Cheese(matrix, lairCount, cheeseCount);
	}

	void put_MouseInLair	(int matrix[9][9], ALLEGRO_DISPLAY* display)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] == 3) 
				{
					int cordX1 = (i + 1) * 100;
					int cordY1 = (j + 1) * 100;
				
					al_draw_bitmap(mouse, cordX1, cordY1, NULL);
					al_flip_display();
					
					int vector[1000];
					generalMove(matrix, i, j, mouse, display, vector, 0, 0, 0);

					i = 9;
					j = 9;
				}
			}
		}
	}

	void put_Limit_and_Walls	(int multiWidth, ALLEGRO_DISPLAY* display)
	{
		int matrix[9][9];

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i == 0 || j == 0 || i == 8 || j == 8)
					matrix[i][j] = -1;
				else 
					matrix[i][j] = getRandomForb(0, 2, 1);
			}
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (matrix[i][j] == 2)
					createLightRectangle(multiWidth, i, j);
				if (matrix[i][j] == 0)
					createDarkRectangle(multiWidth, i, j);
			}
		}

		put_Lair_and_Cheese(matrix, 0, 0);
		put_MouseInLair(matrix, display);
	}


#endif