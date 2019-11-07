
#include <allegro5/allegro.h>
#include <allegro5/display.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include <iostream>
#include <windows.h>

#include "put.h"
#include "movement.h"

using namespace std;

int findMouseI	(int matrix[9][9], int prop)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 3) 
			{
				create_Mouse(i, j, prop);
				return i;
			}
		}
	}
}

int findMouseJ	(int matrix[9][9], int prop)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 3) 
			{
				create_Mouse(i, j, prop);
				return j;
			}
		}
	}
}

int main()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	int choice;
	int matrix[9][9];
	float txtPosY, border, txtPosX;

	int width    = 900;
	int height   = 900;
	int fontSize = 40;
	int prop 	 = 100;

	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	ALLEGRO_FONT* font = al_load_font("edit/font/soopafre.ttf", fontSize, NULL);
	ALLEGRO_COLOR skyBlue = al_map_rgb(176, 224, 230);
	ALLEGRO_COLOR darkBrown = al_map_rgb(139, 69, 19);
	ALLEGRO_COLOR lightBrown = al_map_rgb(210, 180, 140);

	txtPosY = (height * 0.05) - (fontSize / 2) - 5;
	txtPosX = (width/2) + 10;
	border  = ((width * 0.05) / 5);

	al_draw_filled_rectangle(0, 0, width, height, skyBlue);
	al_draw_filled_rectangle(100, 250, width-100, height-100, lightBrown);

	al_draw_text(font, darkBrown, txtPosX, txtPosY, ALLEGRO_ALIGN_CENTRE, "T R A N S F O R M I C E  ");
	al_draw_text(font, darkBrown, txtPosX, 100, ALLEGRO_ALIGN_CENTRE, "ESCOLHA SEU MODO DE JOGO");
	al_draw_text(font, darkBrown, txtPosX, 300, ALLEGRO_ALIGN_CENTRE, "1. RATO ALEATORIO");
	al_draw_text(font, darkBrown, txtPosX, 400, ALLEGRO_ALIGN_CENTRE, "2. RATO INTELIGENTE");
	al_draw_text(font, darkBrown, txtPosX, height-200, ALLEGRO_ALIGN_CENTRE, "ESC. SAIR");
	
	al_flip_display();
	Sleep(30);

	al_draw_filled_rectangle(0, 0, width, height, skyBlue);
	al_draw_text(font, darkBrown, txtPosX, txtPosY, ALLEGRO_ALIGN_CENTRE, "T R A N S F O R M I C E  ");
	create_Border(width, height, 100);
	put_LimitAndWalls(matrix, prop, display);
	put_LairAndCheese(matrix, prop, 0, 0);
	put_MouseInLair(matrix, prop, display);

	int i = findMouseI(matrix, prop);
	int j = findMouseJ(matrix, prop);

	masterMove(matrix, i, j, prop);

	Sleep(1000);
	al_destroy_display(display);

	return 0;
}
