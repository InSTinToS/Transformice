
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
#include "validator.h"

using namespace std;

int findLairI_CreateMouse	(int matrix[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 3) 
			{
				create_Mouse(i, j);
				return i;
			}
		}
	}
}

int findLairJ_CreateMouse 	(int matrix[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (matrix[i][j] == 3) 
			{
				create_Mouse(i, j);
				return j;
			}
		}
	}
}


void create (int matrix[9][9], ALLEGRO_DISPLAY* display)
{
	put_LimitAndWalls			(matrix, display);
	put_LairAndCheese			(matrix, 0, 0);
	put_MouseInLair				(matrix, display);

	Sleep(3);
	al_flip_display();

	int i = findLairI_CreateMouse(matrix);
	int j = findLairJ_CreateMouse(matrix);

	if (validate(matrix, i ,j) == true)
		cout << "Mapa Possivel Criado" << endl;
	else
	{
		cout << "Mapa Impossivel Criado" << endl;
		create(matrix, display);
	}
}

int main()
{

	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	int   choice;
	int   matrix[9][9];
	float txtPosY, border, txtPosX;

	int width    = 900;
	int height   = 900;
	int fontSize = 40;

	clock_t t;

	ALLEGRO_DISPLAY* display	= al_create_display(width, height);
	ALLEGRO_FONT* font			= al_load_font("edit/font/soopafre.ttf", fontSize, NULL);
	ALLEGRO_COLOR skyBlue 		= al_map_rgb(176, 224, 230);
	ALLEGRO_COLOR darkBrown 	= al_map_rgb(139, 69, 19);
	ALLEGRO_COLOR lightBrown 	= al_map_rgb(210, 180, 140);

	txtPosY = (height * 0.05) - (fontSize / 2) - 5;
	txtPosX = (width/2) + 10;
	border  = ((width * 0.05) / 5);

	al_draw_filled_rectangle(0, 0, width, height, skyBlue);
	al_draw_filled_rectangle(100, 250, width-100, height-100, lightBrown);

	al_draw_text	(font, darkBrown, txtPosX, txtPosY, ALLEGRO_ALIGN_CENTRE, "T R A N S F O R M I C E  ");
	al_draw_text	(font, darkBrown, txtPosX, 100, ALLEGRO_ALIGN_CENTRE, "ESCOLHA SEU MODO DE JOGO");
	al_draw_text	(font, darkBrown, txtPosX, 300, ALLEGRO_ALIGN_CENTRE, "1. RATO ALEATORIO");
	al_draw_text	(font, darkBrown, txtPosX, 400, ALLEGRO_ALIGN_CENTRE, "2. RATO INTELIGENTE");
	al_draw_text	(font, darkBrown, txtPosX, height-200, ALLEGRO_ALIGN_CENTRE, "ESC. SAIR");
	
	al_flip_display();



	al_draw_filled_rectangle	(0, 0, width, height, skyBlue);
	al_draw_text				(font, darkBrown, txtPosX, txtPosY, ALLEGRO_ALIGN_CENTRE, "T R A N S F O R M I C E  ");
	create_Border				(width, height);


	create(matrix, display);

	int i = findLairI_CreateMouse(matrix);
	int j = findLairJ_CreateMouse(matrix);

	t = clock();
	masterMove(matrix, i, j);
	t = clock() - t;

	Sleep(1000);
	al_destroy_display(display);
	/* horário final menos inicial*/

	cout << (float)t / CLOCKS_PER_SEC << " segundos";
	
	/* Type cast */
	return 0;
}
