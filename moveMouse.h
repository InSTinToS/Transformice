#ifndef MOVEMOUSE_H
	#define MOVEMOUSE_H
	//MOVIMENTOS
	void moveRight(int matrix[9][9],int i, int j,ALLEGRO_COLOR lightBrown,ALLEGRO_BITMAP* mouse)
	{
		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(500);
		al_draw_filled_rectangle(x1, y1, x2, y2, lightBrown);
		x1 = (i + 1 + 1) * 100;
		y1 = (j + 1) * 100;
		al_draw_bitmap(mouse, x1, y1, NULL);
		al_flip_display();
	}
	void moveDown(int matrix[9][9], int i, int j, ALLEGRO_COLOR lightBrown, ALLEGRO_BITMAP* mouse)
	{
		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(500);
		al_draw_filled_rectangle(x1, y1, x2, y2, lightBrown);
		x1 = (i + 1) * 100;
		y1 = (j + 1 + 1) * 100;
		al_draw_bitmap(mouse, x1, y1, NULL);
		al_flip_display();
	}
	void moveLeft(int matrix[9][9], int i, int j, ALLEGRO_COLOR lightBrown, ALLEGRO_BITMAP* mouse)
	{
		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(500);
		al_draw_filled_rectangle(x1, y1, x2, y2, lightBrown);
		x1 = (i + 1 - 1) * 100;
		y1 = (j + 1) * 100;
		al_draw_bitmap(mouse, x1, y1, NULL);
		al_flip_display();
	}
	void moveUp(int matrix[9][9], int i, int j, ALLEGRO_COLOR lightBrown, ALLEGRO_BITMAP* mouse)
	{
		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(500);
		al_draw_filled_rectangle(x1, y1, x2, y2, lightBrown);
		x1 = (i + 1) * 100;
		y1 = (j + 1 - 1) * 100;
		al_draw_bitmap(mouse, x1, y1, NULL);
		al_flip_display();
	}
	//MOVIMENTO GERAL
	void move(int matrix[9][9], int i, int j, ALLEGRO_BITMAP* mouse)
	{
		ALLEGRO_COLOR lightBrown = al_map_rgb(000, 000, 100);
		int counter = 0;
		if (matrix[i + 1][j] != 1)
			counter++;
		if (matrix[i][j + 1] != 1)
			counter++;
		if (matrix[i - 1][j] != 1)
			counter++;
		if (matrix[i][j - 1] != 1)
			counter++;
		if (counter == 3)
			matrix[i][j] = 5;

		if (matrix[i + 1][j] == 0)
		{
			moveRight(matrix, i, j, lightBrown, mouse);
			move(matrix, ++i, j, mouse);
		}

		if (matrix[i][j + 1] == 0)
		{
			moveDown(matrix, i, j, lightBrown, mouse);
			move(matrix, i, ++j, mouse);
		}

		if (matrix[i - 1][j] == 0) {
			moveLeft(matrix, i, j, lightBrown, mouse);
			move(matrix, --i, j, mouse);
		}

		if (matrix[i][j - 1] == 0)
		{
			moveUp(matrix, i, j, lightBrown, mouse);
			move(matrix, i, --j, mouse);
		}
		
	}
	//RATO NO LAR 
	void putMouseInLair(int matrix[9][9], ALLEGRO_BITMAP* mouse)
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
					move(matrix, i, j, mouse);

					i = 9;
					j = 9;
				}
			}
		}
	}
	//MAIN
	void moveMouse(int matrix[9][9]) 
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");
		putMouseInLair(matrix, mouse);
	}

#endif 

