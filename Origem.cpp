#include <allegro5/allegro.h>
#include <allegro5/display.h>
#include <allegro5/allegro_primitives.h>

int main () 
{
	al_init();
	al_init_primitives_addon();

	int width = 1080;
	int height = 720;
	float x1, x2, y1, y2,porcent;

	porcent = 0.1;
	x1 = width	* porcent;
	y1 = height * porcent;
	x2 = width	-(width * porcent);
	y2 = height	-(height * porcent);


	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_COLOR lightBrown = al_map_rgb(210, 180, 140);
	ALLEGRO_COLOR darkBrown = al_map_rgb(139, 69, 19);
	ALLEGRO_COLOR skyBlue = al_map_rgb(176, 224, 230);

	display = al_create_display(width, height);
	al_draw_filled_rectangle(0,0, width, height, skyBlue);
	al_draw_filled_rectangle(x1, y1, x2, y2, lightBrown);
	al_draw_rectangle(x1, y1, x2, y2, darkBrown,10);


	al_flip_display();
	al_rest(2);
	al_destroy_display(display);
	

	return 0;
}