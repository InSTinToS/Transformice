	#ifndef FORMWALL_H
	#define FORMWALL_H

	using namespace std;
	void putObjects(int matrix[7][7], int mouseCount, int cheeseCount);
	void formWall(ALLEGRO_COLOR cor)
	{
		const int size = 7;
		int matrix[size][size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = getRandom(0,1);
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (matrix[i][j] == 1) {
					int cordX1 = (i + 1) * 100;
					int cordY1 = (j + 1) * 100;
					int cordX2 = cordX1 + 100;
					int cordY2 = cordY1 + 100;
					al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, cor);
				}
			}
		}
		putObjects(matrix,0,0);
	}
	
	void putObjects(int matrix[7][7], int mouseCount, int cheeseCount)
	{
		al_init_image_addon;

		ALLEGRO_BITMAP* mouse = NULL;
		ALLEGRO_BITMAP* lair = NULL;
		ALLEGRO_BITMAP* cheese = NULL;

		mouse = al_load_bitmap("edit/img/rato.png");
		lair = al_load_bitmap("edit/img/toca.png");
		cheese = al_load_bitmap("edit/img/queijo.png");

		int j = getRandom(0, 6);
		int i = getRandom(0, 6);

		if (matrix[i][j] == 0)
		{
			if (mouseCount == 1)
			{
				int cordX1 = (i + 1) * 100;
				int cordY1 = (j + 1) * 100;
				al_draw_bitmap(cheese, cordX1, cordY1, NULL);
				cheeseCount++;
			}
			if (mouseCount == 0)
			{
				int cordX1 = (i + 1) * 100;
				int cordY1 = (j + 1) * 100;
				al_draw_bitmap(lair, cordX1, cordY1, NULL);
				al_draw_bitmap(mouse, cordX1, cordY1, NULL);
				mouseCount++;
			}
		}

		cout << "Cont cheese: " << cheeseCount << "\t" << "Cont mouse: " << mouseCount << endl;

		if (cheeseCount == 0 || mouseCount == 0) {
			putObjects(matrix, mouseCount, cheeseCount);
		}
		else {
			cout << "(formWall.h)" << endl;
		}
	}
	#endif