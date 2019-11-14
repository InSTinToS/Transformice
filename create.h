#ifndef CREATE_H
	#define CREATE_H

	#define time2 200

	void create_Border			(int width, int height)
	{
		int cordX1 = 100;
		int cordY1 = 100;
		int cordX2 = height - 100;
		int cordY2 = width  - 100;

		ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
		al_draw_rectangle(cordX1, cordY1, cordX2, cordY2, black, 15);
	}

	void create_LightRectangle	(int i, int j)
	{
		int cordX1 = i * 100;
		int cordY1 = j * 100;
		int cordX2 = cordX1 + 100;
		int cordY2 = cordY1 + 100;

		ALLEGRO_COLOR lightBrown = al_map_rgb(210, 180, 140);
		al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, lightBrown);
	}

	void create_DarkRectangle	(int i, int j)
	{
		int cordX1 = i * 100;
		int cordY1 = j * 100;
		int cordX2 = cordX1 + 100;
		int cordY2 = cordY1 + 100;
		
		ALLEGRO_COLOR darkBrown = al_map_rgb(139, 69, 19);
		al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, darkBrown);
	}

	void create_Mouse 			(int i, int j)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");

		int cordX1 = i * 100;
		int cordY1 = j * 100;
	
		al_draw_bitmap(mouse, cordX1, cordY1, NULL);
	}

	void create_Lair			(int i, int j) 
	{
		al_init_image_addon;
		ALLEGRO_BITMAP* lair = al_load_bitmap("edit/img/toca.png");

		int cordX1 = i * 100;
		int cordY1 = j * 100;

		al_draw_bitmap(lair, cordX1, cordY1, NULL);
	}

	void create_Cheese			(int i, int j)
	{
		al_init_image_addon;
		ALLEGRO_BITMAP* cheese = al_load_bitmap("edit/img/queijo.png");

		int cordX1 = i * 100;
		int cordY1 = j * 100;

		al_draw_bitmap(cheese, cordX1, cordY1, NULL);
	}

	void noPaintLair			(int matrix[9][9], int i, int j, int x1, int x2, int y1, int y2);
	void drawMove				(int matrix[9][9], int i, int j, int x1, int x2, int y1, int y2, bool capture);

	void create_MoveToLeft		(int i, int j, int matrix[9][9], bool capture)
	{
		int x1 = i * 100;
		int y1 = j * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time2);

		noPaintLair(matrix,  i,  j, x1, x2,  y1,  y2);
		x1 = (i - 1) * 100;
		y1 = j * 100;
		drawMove( matrix, i, j, x1, x2, y1, y2, capture);
	}

	void create_MoveToUp		(int i, int j, int matrix[9][9], bool capture)
	{

		int x1 = i * 100;
		int y1 = j * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time2);

		noPaintLair(matrix,  i,  j, x1, x2,  y1,  y2);	
		x1 = i * 100;
		y1 = (j - 1) * 100;
		drawMove( matrix, i, j, x1, x2, y1, y2, capture);
	}

	void create_MoveToRight		(int i, int j, int matrix[9][9], bool capture)
	{

		int x1 = i * 100;
		int y1 = j * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time2);

		noPaintLair(matrix,  i,  j, x1, x2,  y1,  y2);		
		x1 = (i + 1) * 100;
		y1 = j  * 100;
		drawMove( matrix, i, j, x1, x2, y1, y2, capture);
	}

	void create_MoveToDown		(int i, int j, int matrix[9][9], bool capture)
	{
		int x1 = i * 100;
		int y1 = j * 100;
		int x2 = x1 + 100;
		int y2 = y1 + 100;

		Sleep(time2);

		noPaintLair(matrix,  i,  j, x1, x2,  y1,  y2);
		x1 = i * 100;
		y1 = (j + 1) * 100;
		drawMove( matrix, i, j, x1, x2, y1, y2, capture);
	}

	void noPaintLair			(int matrix[9][9], int i, int j, int x1, int x2, int y1, int y2)
	{
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);

		if (matrix[i][j] != 3)
			al_draw_filled_rectangle(x1, y1, x2, y2, blue);
		else
		{
			create_LightRectangle(i, j);
			create_Lair(i, j);
		}

	}

	void drawMove				(int matrix[9][9], int i, int j, int x1, int x2, int y1, int y2, bool capture)
	{
		ALLEGRO_BITMAP* mouse 		 = 	al_load_bitmap("edit/img/rato.png");
		ALLEGRO_BITMAP* mouseCheese  = 	al_load_bitmap("edit/img/ratoCheese.png");
		ALLEGRO_BITMAP* mouseCheese2 = 	al_load_bitmap("edit/img/ratoCheese2.png");	
		ALLEGRO_COLOR   blue = al_map_rgb(60, 0, 180);

		if (capture == false)
		{
			al_draw_bitmap(mouse, x1, y1, NULL);
			al_flip_display();
		}
		else
		{
			al_draw_filled_rectangle(x1, y1, x2, y2, blue);
			al_draw_bitmap(mouseCheese, x1, y1, NULL);
			al_flip_display();
			Sleep(time2);
			al_draw_filled_rectangle(x1, y1, x2, y2, blue);
			al_draw_bitmap(mouseCheese2, x1, y1, NULL);
			al_flip_display();
		}
	}

#endif