#ifndef CREATEFORMS_H
	#define CREATEFORMS_H
	#define time 100

	void createRectangleLight	(int multiWidth,int i, int j)
	{
		int cordX1 = (i + 1) * multiWidth;
		int cordY1 = (j + 1) * multiWidth;
		int cordX2 = cordX1 + multiWidth;
		int cordY2 = cordY1 + multiWidth;

		ALLEGRO_COLOR lightBrown = al_map_rgb(210, 180, 140);
		al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, lightBrown);
	}

	void createRectangleDark	(int multiWidth, int i, int j)
	{
		int cordX1 = (i + 1) * multiWidth;
		int cordY1 = (j + 1) * multiWidth;
		int cordX2 = cordX1 + multiWidth;
		int cordY2 = cordY1 + multiWidth;

		ALLEGRO_COLOR darkBrown = al_map_rgb(139, 69, 19);
		al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, darkBrown);
	}

	void createLair				(int i, int j) 
	{
		al_init_image_addon;
		ALLEGRO_BITMAP* lair = al_load_bitmap("edit/img/toca.png");

		int cordX1 = (i + 1) * 100;
		int cordY1 = (j + 1) * 100;
		al_draw_bitmap(lair, cordX1, cordY1, NULL);
	}

	void createCheese			(int i, int j)
	{
		al_init_image_addon;
		ALLEGRO_BITMAP* cheese = al_load_bitmap("edit/img/queijo.png");

		int cordX1 = (i + 1) * 100;
		int cordY1 = (j + 1) * 100;
		al_draw_bitmap(cheese, cordX1, cordY1, NULL);
	}

	int createMoveToLeft		(int i, int j,ALLEGRO_COLOR cor)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");

		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time);

		al_draw_filled_rectangle(x1, y1, x2, y2, cor);

		x1 = (i + 1 - 1) * 100;
		y1 = (j + 1) * 100;

		al_draw_bitmap(mouse, x1, y1, NULL);
		return 0;
	}

	int createMoveToUp			(int i, int j,ALLEGRO_COLOR cor)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");

		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time);

		al_draw_filled_rectangle(x1, y1, x2, y2, cor);

		x1 = (i + 1) * 100;
		y1 = (j + 1 - 1 ) * 100;

		al_draw_bitmap(mouse, x1, y1, NULL);
		return 1;
	}

	int createMoveToRight		(int i,int j,ALLEGRO_COLOR cor)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");

		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time);

		al_draw_filled_rectangle(x1, y1, x2, y2, cor);

		x1 = (i + 1 + 1) * 100;
		y1 = (j + 1) * 100;

		al_draw_bitmap(mouse, x1, y1, NULL);
		return 2;
	}

	int createMoveToDown		(int i, int j,ALLEGRO_COLOR cor)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");

		int x1 = (i + 1) * 100;
		int y1 = (j + 1) * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time);

		al_draw_filled_rectangle(x1, y1, x2, y2, cor);

		x1 = (i + 1) * 100;
		y1 = (j + 1 + 1) * 100;

		al_draw_bitmap(mouse, x1, y1, NULL);
		return 3;
	}







#endif