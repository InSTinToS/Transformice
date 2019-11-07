#ifndef CREATE_H
	#define CREATE_H

	#define time2 200

	void create_Border			(int width, int height, int prop)
	{
		int cordX1 = prop;
		int cordY1 = prop;
		int cordX2 = height - prop;
		int cordY2 = width  - prop;

		ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
		al_draw_rectangle(cordX1, cordY1, cordX2, cordY2, black, 15);
	}

	void create_LightRectangle	(int i, int j, int prop)
	{
		int cordX1 = i * prop;
		int cordY1 = j * prop;
		int cordX2 = cordX1 + prop;
		int cordY2 = cordY1 + prop;

		ALLEGRO_COLOR lightBrown = al_map_rgb(210, 180, 140);
		al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, lightBrown);
	}

	void create_DarkRectangle	(int i, int j, int prop)
	{
		int cordX1 = i * prop;
		int cordY1 = j * prop;
		int cordX2 = cordX1 + prop;
		int cordY2 = cordY1 + prop;

		ALLEGRO_COLOR darkBrown = al_map_rgb(139, 69, 19);
		al_draw_filled_rectangle(cordX1, cordY1, cordX2, cordY2, darkBrown);
	}

	void create_Mouse 			(int i, int j, int prop)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");

		int cordX1 = i * prop;
		int cordY1 = j * prop;
	
		al_draw_bitmap(mouse, cordX1, cordY1, NULL);
		al_flip_display();
	}

	void create_Lair			(int i, int j, int prop) 
	{
		al_init_image_addon;
		ALLEGRO_BITMAP* lair = al_load_bitmap("edit/img/toca.png");

		int cordX1 = i * prop;
		int cordY1 = j * prop;
		al_draw_bitmap(lair, cordX1, cordY1, NULL);
	}

	void create_Cheese			(int i, int j, int prop)
	{
		al_init_image_addon;
		ALLEGRO_BITMAP* cheese = al_load_bitmap("edit/img/queijo.png");

		int cordX1 = i * prop;
		int cordY1 = j * prop;
		al_draw_bitmap(cheese, cordX1, cordY1, NULL);
	}

	void create_MoveToLeft		(int i, int j, int prop, int matrix[9][9], bool capture)
	{
		ALLEGRO_BITMAP* mouse 		 = 	al_load_bitmap("edit/img/rato.png");
		ALLEGRO_BITMAP* mouseCheese  = 	al_load_bitmap("edit/img/ratoCheese.png");
		ALLEGRO_BITMAP* mouseCheese2 = 	al_load_bitmap("edit/img/ratoCheese2.png");	
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);

		int x1 = i * prop;
		int y1 = j * prop;
		int x2 = x1 + prop;
		int y2 = y1 + prop;

		Sleep(time2);

		if (matrix[i][j] != 3)
			al_draw_filled_rectangle(x1, y1, x2, y2, blue);
		else
		{
			create_LightRectangle(i, j, prop);
			create_Lair(i, j, prop);
		}

		x1 = (i - 1)* prop;
		y1 = j * prop;

		if (capture == false)
		{
			al_draw_bitmap(mouse, x1, y1, NULL);
			al_flip_display();
		}
		else
		{
			al_draw_bitmap(mouseCheese, x1, y1, NULL);
			al_flip_display();
			Sleep(time2);
			if (matrix[i][j] != 3)
			{
				al_draw_filled_rectangle(x1, y1, x2, y2, blue);
				al_flip_display();
			}
			else
			{
				create_LightRectangle(i, j, prop);
				create_Lair(i, j, prop);
			}
			al_draw_bitmap(mouseCheese2, x1, y1, NULL);
			al_flip_display();
		}
	}

	void create_MoveToUp		(int i, int j, int prop, int matrix[9][9], bool capture)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");
		ALLEGRO_BITMAP* mouseCheese = al_load_bitmap("edit/img/ratoCheese.png");
		ALLEGRO_BITMAP* mouseCheese2 = al_load_bitmap("edit/img/ratoCheese2.png");
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);

		int x1 = i * prop;
		int y1 = j * prop;
		int x2 = x1 + prop;
		int y2 = y1 + prop;

		Sleep(time2);

		if (matrix[i][j] != 3)
		{
			al_draw_filled_rectangle(x1, y1, x2, y2, blue);
		}
		else
		{
			create_LightRectangle(i, j, prop);
			create_Lair(i, j, prop);
		}

		x1 = i * prop;
		y1 = (j - 1) * prop;

		if (capture == false)
		{
			al_draw_bitmap(mouse, x1, y1, NULL);
			al_flip_display();
		}
		else
		{
			al_draw_bitmap(mouseCheese, x1, y1, NULL);
			al_flip_display();
			Sleep(time2);
			if (matrix[i][j] != 3)
			{
				al_draw_filled_rectangle(x1, y1, x2, y2, blue);
				al_flip_display();
			}
			else
			{
				create_LightRectangle(i, j, prop);
				create_Lair(i, j, prop);
			}
			al_draw_bitmap(mouseCheese2, x1, y1, NULL);
			al_flip_display();
		}
	}

	void create_MoveToRight		(int i, int j, int prop, int matrix[9][9], bool capture)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");
		ALLEGRO_BITMAP* mouseCheese = al_load_bitmap("edit/img/ratoCheese.png");
		ALLEGRO_BITMAP* mouseCheese2 = al_load_bitmap("edit/img/ratoCheese2.png");
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);

		int x1 = i * prop;
		int y1 = j * prop;
		int x2 = x1 + prop;
		int y2 = y1 + prop;

		Sleep(time2);

		if (matrix[i][j] != 3)
			al_draw_filled_rectangle(x1, y1, x2, y2, blue);
		else
		{
			create_LightRectangle(i, j, prop);
			create_Lair(i, j, prop);
		}
		
		x1 = (i + 1) * prop;
		y1 = j  * prop;

		if (capture == false)
		{
			al_draw_bitmap(mouse, x1, y1, NULL);
			al_flip_display();
		}
		else
		{
			al_draw_bitmap(mouseCheese, x1, y1, NULL);
			al_flip_display();
			Sleep(time2);
			if (matrix[i][j] != 3)
			{
				al_draw_filled_rectangle(x1, y1, x2, y2, blue);
				al_flip_display();
			}
			else
			{
				create_LightRectangle(i, j, prop);
				create_Lair(i, j, prop);
			}
			al_draw_bitmap(mouseCheese2, x1, y1, NULL);
			al_flip_display();
		}
	}

	void create_MoveToDown		(int i, int j, int prop, int matrix[9][9], bool capture)
	{
		ALLEGRO_BITMAP* mouse = al_load_bitmap("edit/img/rato.png");
		ALLEGRO_BITMAP* mouseCheese = al_load_bitmap("edit/img/ratoCheese.png");
		ALLEGRO_BITMAP* mouseCheese2 = al_load_bitmap("edit/img/ratoCheese2.png");
		ALLEGRO_COLOR blue = al_map_rgb(60, 0, 180);

		int x1 = i * prop;
		int y1 = j * prop;
		int x2 = x1 + prop;
		int y2 = y1 + prop;

		Sleep(time2);

		if (matrix[i][j] != 3)
			al_draw_filled_rectangle(x1, y1, x2, y2, blue);
		else
		{
			create_LightRectangle(i, j, prop);
			create_Lair(i, j, prop);
		}

		x1 = i * prop;
		y1 = (j + 1) * prop;

		if (capture == false)
		{
			al_draw_bitmap(mouse, x1, y1, NULL);
			al_flip_display();
		}
		else
		{
			al_draw_bitmap(mouseCheese, x1, y1, NULL);
			al_flip_display();
			Sleep(time2);
			if (matrix[i][j] != 3)
			{
				al_draw_filled_rectangle(x1, y1, x2, y2, blue);
				al_flip_display();
			}
			else
			{
				create_LightRectangle(i, j, prop);
				create_Lair(i, j, prop);
			}
			al_draw_bitmap(mouseCheese2, x1, y1, NULL);
			al_flip_display();
		}
	}

#endif