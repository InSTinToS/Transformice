#ifndef FORMWALL_H
	#define FORMWALL_H
	
	#include "moveMouse.h"
	#include "getRandom.h"
	
	using namespace std;
	void putObjects(int matrix[9][9], int lairCount, int cheeseCount)
	{
		al_init_image_addon;

		ALLEGRO_BITMAP* lair = al_load_bitmap("edit/img/toca.png");
		ALLEGRO_BITMAP* cheese = al_load_bitmap("edit/img/queijo.png");

		int j = getRandom(0, 6);
		int i = getRandom(0, 6);

		if (matrix[i][j] == 0)
		{
			if (lairCount == 1)
			{
				int cordX1 = (i + 1) * 100;
				int cordY1 = (j + 1) * 100;
				al_draw_bitmap(cheese, cordX1, cordY1, NULL);
				matrix[i][j] = 2;
				cheeseCount++;
			}
			if (lairCount == 0)
			{
				int cordX1 = (i + 1) * 100;
				int cordY1 = (j + 1) * 100;
				al_draw_bitmap(lair, cordX1, cordY1, NULL);
				matrix[i][j] = 3;
				lairCount++;
			}
		}

		cout << "Cont cheese: " << cheeseCount << "\t" << "Cont mouse: " << lairCount << endl;

		if (cheeseCount == 0 || lairCount == 0)
			putObjects(matrix, lairCount, cheeseCount);
		else {
			cout << "(formWall.h)" << endl;
		}
	}

	void formWall(ALLEGRO_COLOR cor)
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
				if (matrix[i][j] == 0) {
					int cordX1 = (i + 1) * 100;
					int cordY1 = (j + 1) * 100;
					int cordX2 = cordX1 + 100;
					int cordY2 = cordY1 + 100;

					ALLEGRO_COLOR		lightBrown = al_map_rgb(210, 180, 140);
					al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, lightBrown);
				}

				if (matrix[i][j] == 1) {
					int cordX1 = (i + 1) * 100;
					int cordY1 = (j + 1) * 100;
					int cordX2 = cordX1 + 100;
					int cordY2 = cordY1 + 100;
					al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, cor);
				}

				if (matrix[i][j] == 9)
				{
					int cordX1 = (i + 1) * 100;
					int cordY1 = (j + 1) * 100;
					int cordX2 = cordX1 + 100;
					int cordY2 = cordY1 + 100;
					
					ALLEGRO_COLOR black = al_map_rgb(255,255,255);
					al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, black);
				}
			}
		}

		putObjects(matrix,0,0);
		moveMouse(matrix);
	}
	

#endif