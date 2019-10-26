#ifndef MOVEMOUSE_H
	#define MOVEMOUSE_H
	
	void putMouseInLair(int matrix[7][7]) 
	{
		ALLEGRO_BITMAP* mouse = NULL;
		mouse = al_load_bitmap("edit/img/rato.png");

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (matrix[i][j] == 3) {
					int cordX1 = (i + 1) * 100;
					int cordY1 = (j + 1) * 100;
					al_draw_bitmap(mouse, cordX1, cordY1, NULL);
				}
			}
		}
	}

	void moveMouse(int matrix[7][7]) 
	{
		putMouseInLair(matrix);
	}

#endif 

