
#include <allegro5/allegro.h>
#include <allegro5/display.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include <windows.h>

#include "formWall.h"

int main()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	int width = 1000;
	int height = 1000;
	int tamFont = 32;
	float posTexto, border;

	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	ALLEGRO_FONT* font = al_load_font("edit/font/soopafre.ttf", tamFont, NULL);

	ALLEGRO_COLOR skyBlue = al_map_rgb(176, 224, 230);
	ALLEGRO_COLOR darkBrown = al_map_rgb(139, 69, 19);

	posTexto = (height * 0.05) - (tamFont / 2) - 5;
	border = ((width * 0.05) / 5);

	al_draw_filled_rectangle(0, 0, width, height, skyBlue);
	al_draw_text(font, darkBrown, width / 2, posTexto, ALLEGRO_ALIGN_CENTRE, "T R A N S F O R M I C E  ");

	formWall(100, display);
	al_rest(5);

	return 0;
}