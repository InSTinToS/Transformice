#include <allegro5/allegro.h>
#include <allegro5/display.h>

int main () 
{
	al_init();
	int width = 1080;
	int height = 720;

	ALLEGRO_DISPLAY* display = NULL;
	
	display = al_create_display(1080, 720);
	al_clear_to_color(al_map_rgb(176, 224, 230));
	al_flip_display();
	al_rest(2);
	al_destroy_display(display);
	
	return 0;
}