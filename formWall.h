#ifndef FORMWALL_H
	#define FORMWALL_H

	void formWall(ALLEGRO_COLOR cor) {
		const int size = 7;
		int matrix[size][size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = getRandom();
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
	}

#endif