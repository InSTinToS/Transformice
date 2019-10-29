#ifndef MOVEMOUSE_H
	#define MOVEMOUSE_H
	
	#include <allegro5/allegro_image.h>
	#include "createForms.h"

	using namespace std;

	void generalMove(int matrix[9][9], int i, int j, int verificaToca, ALLEGRO_BITMAP* mouse)
	{
		int verificaRepete = 0;

		if (matrix[i + 1][j] == 1 || matrix[i + 1][j] == 9)
			verificaRepete++;
		if (matrix[i][j + 1] == 1 || matrix[i][j + 1] == 9)
			verificaRepete++;
		if (matrix[i - 1][j] == 1 || matrix[i - 1][j] == 9)
			verificaRepete++;
		if (matrix[i][j - 1] == 1 || matrix[i][j - 1] == 9)
			verificaRepete++;

		if (verificaRepete == 4)
			al_draw_filled_rectangle(0, 0, 100, 100, al_map_rgb(255, 0, 0));

		if (verificaRepete == 3)
		{
			if (matrix[i + 1][j] == 5)
			{
				createMoveToRight(i, j);
				if (verificaToca == 0)
				{
					createLair(i, j);
					verificaToca++;
				}
				al_flip_display();
				matrix[i][j] = 5;
				generalMove(matrix, ++i, j, verificaToca, mouse);
			}

			if (matrix[i][j + 1] == 5)
			{
				createMoveToDown(i, j);
				if (verificaToca == 0)
				{
					createLair(i, j);
					verificaToca++;
				}
				al_flip_display();
				matrix[i][j] = 5;
				generalMove(matrix, i, ++j, verificaToca, mouse);
			}

			if (matrix[i - 1][j] == 5) {
				createMoveToLeft(i, j);
				if (verificaToca == 0)
				{
					createLair(i, j);
					verificaToca++;
				}
				al_flip_display();
				matrix[i][j] = 5;
				generalMove(matrix, --i, j, verificaToca, mouse);
			}

			if (matrix[i][j - 1] == 5)
			{
				createMoveToUp(i, j);
				if (verificaToca == 0)
				{
					createLair(i, j);
					verificaToca++;
				}
				al_flip_display();
				matrix[i][j] = 5;
				generalMove(matrix, i, --j, verificaToca, mouse);
			}
		}

		if (matrix[i + 1][j] == 8)
		{
			createMoveToRight(i, j);
			if (verificaToca == 0)
			{
				createLair(i, j);
				verificaToca++;
			}
			al_flip_display();
			matrix[i][j] = 5;
			generalMove(matrix, ++i, j, verificaToca, mouse);
		}

		if (matrix[i][j + 1] == 0)
		{
			createMoveToDown(i, j);
			if (verificaToca == 0)
			{
				createLair(i, j);
				verificaToca++;
			}
			al_flip_display();
			matrix[i][j] = 5;
			generalMove(matrix, i, ++j, verificaToca, mouse);
		}

		if (matrix[i - 1][j] == 0) {
			createMoveToLeft(i, j);
			if (verificaToca == 0)
			{
				createLair(i, j);
				verificaToca++;
			}
			al_flip_display();
			matrix[i][j] = 5;
			generalMove(matrix, --i, j, verificaToca, mouse);
		}

		if (matrix[i][j - 1] == 0)
		{
			createMoveToUp(i, j);
			if (verificaToca == 0)
			{
				createLair(i, j);
				verificaToca++;
			}
			al_flip_display();
			matrix[i][j] = 5;
			generalMove(matrix, i, --j, verificaToca, mouse);
		}
	}

	void putMouseInLair	(int matrix[9][9], ALLEGRO_BITMAP* mouse)
	{
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
					generalMove(matrix, i, j, 0, mouse);

					i = 9;
					j = 9;
				}
			}
		}
	}

	void moveMouse		(int matrix[9][9]) 
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");
		putMouseInLair(matrix, mouse);
	}

#endif 

