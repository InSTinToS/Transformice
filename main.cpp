#include <allegro5/allegro.h>
#include <allegro5/display.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include <iostream> 
#include <time.h>


#include "formWall.h"


using namespace std;

int main()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	int width = 900;
	int height = 900;
	int tamFont = 32;
	int blockAmount = 48;
	float x1, x2, y1, y2, posTexto, border;

	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	ALLEGRO_FONT* font = al_load_font("edit/font/soopafre.ttf", tamFont, NULL);
	ALLEGRO_COLOR		lightBrown = al_map_rgb(210, 180, 140);
	ALLEGRO_COLOR		darkBrown = al_map_rgb(139, 69, 19);
	ALLEGRO_COLOR		skyBlue = al_map_rgb(176, 224, 230);

	posTexto = (height * 0.05) - (tamFont / 2) - 5;
	border = ((width * 0.05) / 5);
	x1 = 100;
	y1 = 100;
	x2 = 800;
	y2 = 800;

	al_draw_filled_rectangle(0, 0, width, height, skyBlue);
	al_draw_filled_rectangle(x1, y1, x2, y2, lightBrown);
	al_draw_rectangle(x1, y1, x2, y2, darkBrown, border);

	formWall(darkBrown);

	al_draw_text(font, darkBrown, width / 2, posTexto, ALLEGRO_ALIGN_CENTRE, "T R A N S 4 M I C E (4 == FOUR != A ) ");

	al_flip_display();
	al_rest(5);
	al_destroy_display(display);
	return 0;
}