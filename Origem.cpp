#include <allegro5/allegro.h>
#include <allegro5/display.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include <iostream>   
#include <time.h>

#include "getRandom.h"
#include "formWall.h"

using namespace std;

int main()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();


	int vetorx[7];
	int vetory[7];
	int width = 900;
	int height = 900;
	int tamFont = 32;
	int blockAmount = 48;
	

	float x1, x2, y1, y2, posTexto, border;

	posTexto = (height * 0.05) - (tamFont / 2) - 5;
	border = ((width * 0.05) / 5);
	x1 = 100;
	y1 = 100;
	x2 = 800;
	y2 = 800;



	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_BITMAP* mouse = NULL;
	ALLEGRO_BITMAP* cheese = NULL;
	ALLEGRO_BITMAP* lair = NULL;
	ALLEGRO_COLOR lightBrown = al_map_rgb(210, 180, 140);
	ALLEGRO_COLOR darkBrown = al_map_rgb(139, 69, 19);
	ALLEGRO_COLOR skyBlue = al_map_rgb(176, 224, 230);

	display = al_create_display(width, height);
	font = al_load_font("edit/font/soopafre.ttf", tamFont, NULL);
	mouse = al_load_bitmap("edit/img/rato.png");
	cheese = al_load_bitmap("edit/img/queijo.png");
	lair = al_load_bitmap("edit/img/toca.png");

	al_draw_filled_rectangle	(0, 0, width, height, skyBlue);
	al_draw_filled_rectangle	(x1, y1, x2, y2, lightBrown);
	al_draw_rectangle			(x1, y1, x2, y2, darkBrown, border);

	formWall(darkBrown);


	al_draw_bitmap(mouse, 400, 360, NULL);
	al_draw_bitmap(cheese, 300, 360, NULL);
	al_draw_bitmap(lair, 200, 360, NULL);
	al_draw_text(font, darkBrown, width / 2, posTexto, ALLEGRO_ALIGN_CENTRE, "T R A N S F O R M I C E");

	al_flip_display();
	al_rest(5);
	al_destroy_display(display);
	
	return 0;
}