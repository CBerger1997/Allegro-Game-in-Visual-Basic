/// @file LevelInitialisation.cpp
/// @initialises the game, setting all game values in the game values class and intalling all allegro sections, such as keyboard, mouse and sound

//Additional File Includes
#include <allegro.h>
#include "MenuFunctions.h"
#include "Levels.h"
#include <stdlib.h>

//struct used to set all variables used within the menu
struct MenuValues
{
	BITMAP *m_MenuFloor;
}MenuVals;

//main function containing all allegro install and some variable initialisation
int main ( void )
{
	allegro_init();
	install_keyboard();
	install_mouse();
	install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL );
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 480, 0, 0);
	/*Char.m_Walking[0] = load_sample( "Assets/Walking.wav" );
	Char.m_Walking[1] = load_sample( "Assets/Walking2.wav" );
	Game_vals.m_BackgroundMusic = load_sample ("Assets/Background Music.wav" );
	Box.m_BoxSlide = load_sample( "Assets/Move Box.wav" );*/
	srand( time( NULL ) );
	show_mouse(screen);
	Menu();

	return 0;
}
END_OF_MAIN()

/*Menu function used to load and display the menu along with mouse collision*/
void Menu ( void )
{
	/*play_sample( Game_vals.m_BackgroundMusic , 255, 128, 1000, 100 );*/
	Game_vals.Set_vals ( true, false, true );
	MenuVals.m_MenuFloor = load_bitmap( "Assets/MenuBack.bmp", NULL );

	while( Game_vals.m_Exit == true )
	{
		if(mouse_b & 1)
		{
			Menu_collision();
		}

		MenuBlitting();
	}
}

//function used to display all bitmaps on the screen during the Menu
void MenuBlitting ( void )
{
	BITMAP *buffer;

	buffer = create_bitmap( SCREEN_W, SCREEN_H );
	clear_to_color( buffer, makecol( 255, 0, 255 ) );	
	blit( MenuVals.m_MenuFloor, buffer, 0, 0, 0, 0, MenuVals.m_MenuFloor->w, MenuVals.m_MenuFloor->h );
	blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
	clear_bitmap( buffer );

	destroy_bitmap ( buffer );
}

//function used to manage mouse collision with colour on bitmaps
void Menu_collision ( void )
{
	int r, g, b, colour;

	colour = _getpixel32(screen, mouse_x, mouse_y);
	r = getr32(colour);
	g = getg32(colour);
	b = getb32(colour);

	if (((r == 0) && (g == 0) && (b == 0)) || ((r == 255) && (g == 255) && (b == 255)))
	{
		if ((mouse_y > 150) && (mouse_y < 177) && (mouse_x > 182) && (mouse_x < 417))
				Level1();

			if ((mouse_y > 244 && mouse_y < 271) && (mouse_x > 182) && (mouse_x < 417))
				Instructions();

			if ((mouse_y > 339) && (mouse_y < 366) && (mouse_x > 182) && (mouse_x < 417))
				Game_vals.m_Exit = false;
	}
}

//function used to display the Instructions page and all collision on that page
void Instructions ( void )
{
	BITMAP *m_instrucBack;

	m_instrucBack = load_bitmap( "Assets/InstructionsBack.bmp", NULL );

	int r, g, b, colour;
	BITMAP *m_buffer;

	while( !key [ KEY_ESC ] )
	{


		m_buffer = create_bitmap( SCREEN_W, SCREEN_H );
		clear_to_color( m_buffer, makecol( 255, 0, 255 ) );	
		blit( m_instrucBack, m_buffer, 0, 0, 0, 0, m_instrucBack->w, m_instrucBack->h );
		blit( m_buffer, screen, 0, 0, 0, 0, m_buffer->w, m_buffer->h );
		clear_bitmap( m_buffer );

		destroy_bitmap ( m_buffer );

		colour = _getpixel32(screen, mouse_x, mouse_y);
		r = getr32(colour);
		g = getg32(colour);
		b = getb32(colour);

		if (((r == 0) && (g == 0) && (b == 0)) || ((r == 255) && (g == 255) && (b == 255)))
		{
			if ((mouse_y > 299) && (mouse_y < 330) && (mouse_x > 263) && (mouse_x < 341))
				if (mouse_b & 1 )

					break;
		}
	}


}