#ifndef _Levels_H_
#define _Levels_H_

/// \file  Levels.h
/// \Contains all functions for all levels
/// \author Callum Berger

#include <allegro.h>
#include "ObjectClasses.h"
#include "LevelFunctions.h"
#include <stdlib.h>
#include <fstream> 
#include <iostream> 

#define GAME_LEVEL_1 1
#define GAME_LEVEL_2 2
#define GAME_LEVEL_3 3
#define GAME_LEVEL_4 4
#define GAME_LEVEL_5 5

//struct used to set all variables used within the Levels
struct LevelVars
{
	BITMAP *m_Defaultfloor;
	BITMAP *m_Door_open;
	BITMAP *m_Level;
	int m_Game_level;
}lvl;

//function used to create the first level and loop the user through a set of functions to play the level
void Level1 ( void )
{
	Game_vals.m_Reset = true;
	while (Game_vals.m_Reset == true)
	{
		Game_vals.m_Reset = false;
		lvl.m_Game_level = GAME_LEVEL_1;
		Char.SetCharacterValues (280, 400, 40, 40, 0);
		Box.SetBoxValues ( 120, 120, 0, 0, 40 , 40, false);
		SwitchBox.Set_values ( 440, 120 );

		BitmapLoading();

		blit( lvl.m_Level, screen, 0, 0, 0, 0, lvl.m_Level->w, lvl.m_Level->h );
		rest(1000);

		Game_vals.m_Game_end = false;

		for ( int i = 0; i < 31; i++)
		{
			Box.m_Wall_collision_box_x[i] = 0;
			Box.m_Wall_collision_box_y[i] = 0;
		}

		while( !key[KEY_ESC] )
		{
			KeyboardResponse();
			Blitting();
			if(( Box.m_box_x[0] == SwitchBox.m_Switch_x ) && ( Box.m_box_y[0] == SwitchBox.m_Switch_y ) || ( Char.m_character_x == SwitchBox.m_Switch_x ) && ( Char.m_character_y == SwitchBox.m_Switch_y ))
			{
				Box.m_active = true;
			}
			else
			{
				Box.m_active = false;
			}
			if (Game_vals.m_Game_end == true)
			{
				break;
			}
			if (key[KEY_R])
			{
				Game_vals.m_Reset = true;
				break;
			}
		}

		if ( Game_vals.m_Game_end == true )
		{
			Level2();
		}
	}
}

//function used to create the Second level and loop the user through a set of functions to play the level
void Level2 ( void )
{
	Game_vals.m_Reset = true;
	while (Game_vals.m_Reset == true)
	{
		Game_vals.m_Reset = false;
		lvl.m_Game_level = GAME_LEVEL_2;
		Char.SetCharacterValues (280, 400, 40, 40, 0);
		Box.SetBoxValues ( 480, 80, 0, 0, 40 ,40, false);
		SwitchBox.Set_values ( 80, 360 );
		set_wall_collision_values_Level_2();

		BitmapLoading();

		blit( lvl.m_Level, screen, 0, 0, 0, 0, lvl.m_Level->w, lvl.m_Level->h );
		rest(1000);

		Game_vals.m_Game_end = false;

		while( !key[KEY_ESC] )
		{
			KeyboardResponse();
			Blitting();
			if(( Box.m_box_x[0] == SwitchBox.m_Switch_x ) && ( Box.m_box_y[0] == SwitchBox.m_Switch_y ) || ( Char.m_character_x == SwitchBox.m_Switch_x ) && ( Char.m_character_y == SwitchBox.m_Switch_y ))
			{
				Box.m_active = true;
			}
			else
			{
				Box.m_active = false;
			}
			if (Game_vals.m_Game_end == true)
			{
				break;
			}
			if (key[KEY_R])
			{
				Game_vals.m_Reset = true;
				break;
			}
		}

		if ( Game_vals.m_Game_end == true )
		{
			Level3();
		}
	}
}

//function used to create the Third level and loop the user through a set of functions to play the level
void Level3 ( void )
{
	Game_vals.m_Reset = true;
	while (Game_vals.m_Reset == true)
	{
		Game_vals.m_Reset = false;
		lvl.m_Game_level = GAME_LEVEL_3;
		Char.SetCharacterValues (280, 400, 40, 40, 0);
		Box.SetBoxValues ( 80, 360, 0, 0, 40 ,40, false);
		SwitchBox.Set_values ( 480, 320 );
		set_wall_collision_values_Level_3();

		BitmapLoading();

		blit( lvl.m_Level, screen, 0, 0, 0, 0, lvl.m_Level->w, lvl.m_Level->h );
		rest(1000);

		Game_vals.m_Game_end = false;

		while( !key[KEY_ESC] )
		{
			KeyboardResponse();
			Blitting();
			if(( Box.m_box_x[0] == SwitchBox.m_Switch_x ) && ( Box.m_box_y[0] == SwitchBox.m_Switch_y ) || ( Char.m_character_x == SwitchBox.m_Switch_x ) && ( Char.m_character_y == SwitchBox.m_Switch_y ))
			{
				Box.m_active = true;
			}
			else
			{
				Box.m_active = false;
			}
			if (Game_vals.m_Game_end == true)
			{
				break;
			}
			if (key[KEY_R])
			{
				Game_vals.m_Reset = true;
				break;
			}
		}

		if ( Game_vals.m_Game_end == true )
		{
			Level4();
		}
	}
}

//function used to create the Fourth level and loop the user through a set of functions to play the level
void Level4 ( void )
{
	Game_vals.m_Reset = true;
	while (Game_vals.m_Reset == true)
	{
		Game_vals.m_Reset = false;
		lvl.m_Game_level = GAME_LEVEL_4;
		Char.SetCharacterValues (280, 400, 40, 40, 0);
		Box.SetBoxValues ( 120, 320, 440, 120, 40 ,40, false);
		SwitchBox.Set_values ( 40, 120 );
		SwitchBox.Set_values_2 ( 520, 120 );
		set_wall_collision_values_Level_4();

		BitmapLoading();

		blit( lvl.m_Level, screen, 0, 0, 0, 0, lvl.m_Level->w, lvl.m_Level->h );
		rest(1000);

		Game_vals.m_Game_end = false;

		while( !key[KEY_ESC] )
		{
			KeyboardResponse();
			Blitting();
			if((( Box.m_box_x[0] == SwitchBox.m_Switch_x ) && ( Box.m_box_y[0] == SwitchBox.m_Switch_y ) || ( Char.m_character_x == SwitchBox.m_Switch_x ) && ( Char.m_character_y == SwitchBox.m_Switch_y ))
				&& (( Box.m_box_x[1] == SwitchBox.m_Switch2_x ) && ( Box.m_box_y[1] == SwitchBox.m_Switch2_y ) || ( Char.m_character_x == SwitchBox.m_Switch2_x ) && ( Char.m_character_y == SwitchBox.m_Switch2_y )))
			{
				Box.m_active = true;
			}
			else
			{
				Box.m_active = false;
			}
			if (Game_vals.m_Game_end == true)
			{
				break;
			}
			if (key[KEY_R])
			{
				Game_vals.m_Reset = true;
				break;
			}
		}

		if ( Game_vals.m_Game_end == true )
		{
			Level5();
		}
	}
}

//function used to create the Fifth level and loop the user through a set of functions to play the level
void Level5 ( void )
{
	Game_vals.m_Reset = true;
	while (Game_vals.m_Reset == true)
	{
		Game_vals.m_Reset = false;
		lvl.m_Game_level = GAME_LEVEL_5;
		Char.SetCharacterValues (280, 400, 40, 40, 0);
		Box.SetBoxValues ( 80, 160, 480, 160, 40 ,40, false);
		SwitchBox.Set_values ( 520, 40 );
		SwitchBox.Set_values_2 ( 160, 280 );
		set_wall_collision_values_Level_5();

		BitmapLoading();

		blit( lvl.m_Level, screen, 0, 0, 0, 0, lvl.m_Level->w, lvl.m_Level->h );
		rest(1000);

		Game_vals.m_Game_end = false;

		while( !key[KEY_ESC] )
		{
			KeyboardResponse();
			Blitting();
			if((( Box.m_box_x[0] == SwitchBox.m_Switch_x ) && ( Box.m_box_y[0] == SwitchBox.m_Switch_y ) || ( Char.m_character_x == SwitchBox.m_Switch_x ) && ( Char.m_character_y == SwitchBox.m_Switch_y ))
				&& (( Box.m_box_x[1] == SwitchBox.m_Switch2_x ) && ( Box.m_box_y[1] == SwitchBox.m_Switch2_y ) || ( Char.m_character_x == SwitchBox.m_Switch2_x ) && ( Char.m_character_y == SwitchBox.m_Switch2_y )))
			{
				Box.m_active = true;
			}
			else
			{
				Box.m_active = false;
			}
			if (Game_vals.m_Game_end == true)
			{
				break;
			}
			if (key[KEY_R])
			{
				Game_vals.m_Reset = true;
				break;
			}
		}
	}
	lvl.m_Level = load_bitmap ( "Assets/The End.bmp", NULL );
	blit( lvl.m_Level, screen, 0, 0, 0, 0, lvl.m_Level->w, lvl.m_Level->h );
		rest(1000);
}

//function used to load bitmaps for each level
void BitmapLoading ( void )
{
	Char.m_test = load_bitmap( "Assets/Character.bmp", NULL );
	if ( lvl.m_Game_level == 1 )
	{
		lvl.m_Defaultfloor = load_bitmap( "Assets/Level1floor.bmp", NULL );
		lvl.m_Level = load_bitmap( "Assets/Level 1.bmp", NULL );
	}
	else if ( lvl.m_Game_level == 2 )
	{
		lvl.m_Defaultfloor = load_bitmap( "Assets/Level2floor.bmp", NULL );
		lvl.m_Level = load_bitmap( "Assets/Level 2.bmp", NULL );
	}
	else if ( lvl.m_Game_level == 3 )
	{
		lvl.m_Defaultfloor = load_bitmap( "Assets/Level3floor.bmp", NULL );
		lvl.m_Level = load_bitmap( "Assets/Level 3.bmp", NULL );
	}
	else if ( lvl.m_Game_level == 4 )
	{
		lvl.m_Defaultfloor = load_bitmap( "Assets/Level4floor.bmp", NULL );
		lvl.m_Level = load_bitmap( "Assets/Level 4.bmp", NULL );
	}
	else if ( lvl.m_Game_level == 5 )
	{
		lvl.m_Defaultfloor = load_bitmap( "Assets/Level5floor.bmp", NULL );
		lvl.m_Level = load_bitmap( "Assets/Level 5.bmp", NULL );
	}

	Box.m_box = load_bitmap( "Assets/box.bmp", NULL );

	SwitchBox.m_Switch = load_bitmap( "Assets/FloorSwitch.bmp", NULL );

	lvl.m_Door_open = load_bitmap( "Assets/Door_open.bmp", NULL );
}   

//function used to respond to user keyboard input and character movement
void KeyboardResponse( void )
{
	if( key[KEY_A] )
	{
		Char.LeftCharacterAnimation();
	}

	if ( key[KEY_D] )
	{
		Char.RightCharacterAnimation();
	}

	if( key[KEY_W] )
	{
		Char.ForwardCharacterAnimation();
	}

	if ( key[KEY_S] )
	{
		Char.BackwardsCharacterAnimation();
	}

}

//function used to display the bitmaps used for the current level
void Blitting ( void )
{

	BITMAP *buffer;

	buffer = create_bitmap( SCREEN_W, SCREEN_H );
	clear_to_color( buffer, makecol( 255, 0, 255 ) );
	masked_blit( Char.m_test, buffer, 0, 0, Char.m_character_x, Char.m_character_y, Char.m_test->w, Char.m_test->h );
	blit( lvl.m_Defaultfloor, buffer, 0, 0, 0, 0, lvl.m_Defaultfloor->w, lvl.m_Defaultfloor->h );
	blit( SwitchBox.m_Switch, buffer, 0, 0, SwitchBox.m_Switch_x, SwitchBox.m_Switch_y, SwitchBox.m_Switch->w, SwitchBox.m_Switch->h );
	if (( lvl.m_Game_level == 4 ) || ( lvl.m_Game_level == 5 ))
	{
		blit( SwitchBox.m_Switch, buffer, 0, 0, SwitchBox.m_Switch2_x, SwitchBox.m_Switch2_y, SwitchBox.m_Switch->w, SwitchBox.m_Switch->h );
	}
	draw_sprite( buffer, Char.m_test, Char.m_character_x, Char.m_character_y );
	if( Box.m_active == true )
	{
		blit( lvl.m_Door_open, buffer, 0, 0, 280, 0, lvl.m_Door_open->w, lvl.m_Door_open->h );
	}
	blit( Box.m_box, buffer, 0, 0, Box.m_box_x[0], Box.m_box_y[0], Box.m_box->w, Box.m_box->h );
	if (( lvl.m_Game_level == 4 ) || ( lvl.m_Game_level == 5 ))
	{
		blit( Box.m_box, buffer, 0, 0, Box.m_box_x[1], Box.m_box_y[1], Box.m_box->w, Box.m_box->h );
	}
	blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
	clear_bitmap( buffer );

	destroy_bitmap ( buffer );
}

//function used to detect character and box collision
void bounding_box_collision( void )
{
	for ( int i = 0; i < 2; i++ )
	{
		if ((Char.m_character_x < Box.m_box_x[i] + Box.m_box_box_w - 1) && (Char.m_character_x - Box.m_box_x[i] < 40) && (Char.m_character_x - Box.m_box_x[i] > 0) && (Char.m_character_y == Box.m_box_y[i])) // is character on the right side of box?
		{
			if( Box.m_box_x[i] <= 40 )
			{
				Box.m_box_x[i] = 40;
				Char.m_character_x += 10;
			}
			else
			{
				Box.m_box_x[i] -= 10;
				bounding_wall_collision_box();
				bounding_box_on_box_collision(i);

			}
		}


		if ((Char.m_character_y < Box.m_box_y[i] + Box.m_box_box_h - 1) && (Char.m_character_y - Box.m_box_y[i] < 40) && (Char.m_character_y - Box.m_box_y[i] > 0) && (Char.m_character_x == Box.m_box_x[i])) // is character under box?
		{
			if( Box.m_box_y[i] <= 40 )
			{
				Box.m_box_y[i] = 40;
				Char.m_character_y += 10;
			}
			else
			{
				Box.m_box_y[i] -= 10;
				bounding_wall_collision_box();
				bounding_box_on_box_collision(i);
			}
		}


		if ((Box.m_box_x[i] < Char.m_character_x + Char.m_character_box_w - 1) && (Box.m_box_x[i] - Char.m_character_x < 40) && (Box.m_box_x[i] - Char.m_character_x > 0) && (Char.m_character_y == Box.m_box_y[i])) // is box on the right side of character?
		{
			if( Box.m_box_x[i] >= 520 )
			{
				Box.m_box_x[i] = 520;
				Char.m_character_x -= 10;
			}
			else
			{
				Box.m_box_x[i] += 10;
				bounding_wall_collision_box();
				bounding_box_on_box_collision(i);
			}
		}


		if ((Box.m_box_y[i] < Char.m_character_y + Char.m_character_box_h - 1) && (Box.m_box_y[i] - Char.m_character_y < 40) && (Box.m_box_y[i] - Char.m_character_y > 0) && (Char.m_character_x == Box.m_box_x[i]))   // is box under character?
		{
			if( Box.m_box_y[i] >= 400 )
			{
				Box.m_box_y[i] = 400;
				Char.m_character_y -= 10;
			}
			else
			{
				Box.m_box_y[i] += 10;
				bounding_wall_collision_box();
				bounding_box_on_box_collision(i);
			}
		}
	}
}

//function used to detect character and wall collision
void bounding_wall_collision( void )
{
	for ( int i = 0; i < Box.m_ArrayCounter; i++ )
	{
		if ((Char.m_character_x < Box.m_Wall_collision_box_x[i] + Box.m_box_box_w - 1) && (Char.m_character_x - Box.m_Wall_collision_box_x[i] < 40) && (Char.m_character_x - Box.m_Wall_collision_box_x[i] > 0) && (Char.m_character_y == Box.m_Wall_collision_box_y[i])) // is character on the right side of box?
		{
			Char.m_character_x += 10;
		}

		if ((Char.m_character_y < Box.m_Wall_collision_box_y[i] + Box.m_box_box_h - 1) && (Char.m_character_y - Box.m_Wall_collision_box_y[i] < 40) && (Char.m_character_y - Box.m_Wall_collision_box_y[i] > 0) && (Char.m_character_x == Box.m_Wall_collision_box_x[i])) // is character under box?
		{
			Char.m_character_y += 10;
		}

		if ((Box.m_Wall_collision_box_x[i] < Char.m_character_x + Char.m_character_box_w - 1) && (Box.m_Wall_collision_box_x[i] - Char.m_character_x < 40) && (Box.m_Wall_collision_box_x[i] - Char.m_character_x > 0) && (Char.m_character_y == Box.m_Wall_collision_box_y[i])) // is box on the right side of character?
		{
			Char.m_character_x -= 10;
		}

		if ((Box.m_Wall_collision_box_y[i] < Char.m_character_y + Char.m_character_box_h - 1) && (Box.m_Wall_collision_box_y[i] - Char.m_character_y < 40) && (Box.m_Wall_collision_box_y[i] - Char.m_character_y > 0) && (Char.m_character_x == Box.m_Wall_collision_box_x[i]))   // is box under character?
		{
			Char.m_character_y -= 10;
		}

	}

}

//function used to detect box and box collision
void bounding_box_on_box_collision( int i )
{

	int j;

	if ( i == 0 )
	{
		j = 1;
	}
	else
	{
		j = 0;
	}

	if ((Box.m_box_x[i] < Box.m_box_x[j] + Box.m_box_box_w - 1) && (Box.m_box_x[i] - Box.m_box_x[j] < 40) && (Box.m_box_x[i] - Box.m_box_x[j] > 0) && (Box.m_box_y[i] == Box.m_box_y[j])) // is character on the right side of box?
	{
		Char.m_character_x += 10;
		Box.m_box_x[i] += 10;
	}

	if ((Box.m_box_y[i] < Box.m_box_y[j] + Box.m_box_box_h - 1) && (Box.m_box_y[i] - Box.m_box_y[j] < 40) && (Box.m_box_y[i] - Box.m_box_y[j] > 0) && (Box.m_box_x[i] == Box.m_box_x[j])) // is character under box?
	{
		Char.m_character_y += 10;
		Box.m_box_y[i] += 10;
	}

	if ((Box.m_box_x[j] < Box.m_box_x[i] + Char.m_character_box_w - 1) && (Box.m_box_x[j] - Box.m_box_x[i] < 40) && (Box.m_box_x[j] - Box.m_box_x[i] > 0) && (Box.m_box_y[i] == Box.m_box_y[j])) // is box on the right side of character?
	{
		Char.m_character_x -= 10;
		Box.m_box_x[i] -= 10;
	}

	if ((Box.m_box_y[j] < Box.m_box_y[i] + Char.m_character_box_h - 1) && (Box.m_box_y[j] - Box.m_box_y[i] < 40) && (Box.m_box_y[j] - Box.m_box_y[i]> 0) && (Box.m_box_x[i] == Box.m_box_x[j])) // is box under character?
	{
		Char.m_character_y -= 10;
		Box.m_box_y[i] -= 10;
	}

}

//function used to detect box and wall collision
void bounding_wall_collision_box( void )
{
	for ( int i = 0; i < Box.m_ArrayCounter; i++ )
	{
		for ( int j = 0; j < 2; j++ )
		{
			if ((Box.m_box_x[j] < Box.m_Wall_collision_box_x[i] + Box.m_box_box_w - 1) && (Box.m_box_x[j] - Box.m_Wall_collision_box_x[i] < 40) && (Box.m_box_x[j] - Box.m_Wall_collision_box_x[i] > 0) && (Box.m_box_y[j] == Box.m_Wall_collision_box_y[i])) // is character on the right side of box?
			{
				Char.m_character_x += 10;
				Box.m_box_x[j] += 10;
			}

			if ((Box.m_box_y[j] < Box.m_Wall_collision_box_y[i] + Box.m_box_box_h - 1) && (Box.m_box_y[j] - Box.m_Wall_collision_box_y[i] < 40) && (Box.m_box_y[j] - Box.m_Wall_collision_box_y[i] > 0) && (Box.m_box_x[j] == Box.m_Wall_collision_box_x[i])) // is character under box?
			{
				Char.m_character_y += 10;
				Box.m_box_y[j] += 10;
			}

			if ((Box.m_Wall_collision_box_x[i] < Box.m_box_x[j] + Char.m_character_box_w - 1) && (Box.m_Wall_collision_box_x[i] - Box.m_box_x[j] < 40) && (Box.m_Wall_collision_box_x[i] - Box.m_box_x[j] > 0) && (Box.m_box_y[j] == Box.m_Wall_collision_box_y[i])) // is box on the right side of character?
			{
				Char.m_character_x -= 10;
				Box.m_box_x[j] -= 10;
			}

			if ((Box.m_Wall_collision_box_y[i] < Box.m_box_y[j] + Char.m_character_box_h - 1) && (Box.m_Wall_collision_box_y[i] - Box.m_box_y[j] < 40) && (Box.m_Wall_collision_box_y[i] - Box.m_box_y[j] > 0) && (Box.m_box_x[j] == Box.m_Wall_collision_box_x[i]))   // is box under character?
			{
				Char.m_character_y -= 10;
				Box.m_box_y[j] -= 10;
			}
		}
	}
}

//function used to set the wall collision values for level 2
void set_wall_collision_values_Level_2 ( void )
{
	int m_Array[100];
	int m_counter = 0;
	int m_counter_x = 0;
	int m_counter_y = 0;

	Box.m_ArrayCounter = 0;

	std::ifstream Level_file( "Floor2.txt" );

	if ( Level_file.is_open() ) 
	{
		while( !Level_file.eof())
		{				

			Level_file >> m_Array[m_counter];		
			m_counter++;
			if ( Level_file.eof() )
			{
				break;
			}
		}
	}

	for( int i = 0; i <= m_counter; i++ )
	{
		if ( i % 2 == 0)
		{
			Box.m_Wall_collision_box_x[m_counter_x] = m_Array[i];
			m_counter_x++;
			Box.m_ArrayCounter++;
		}
		if ( i % 2 == 1)
		{
			Box.m_Wall_collision_box_y[m_counter_y] = m_Array[i];
			m_counter_y++;
		}
	}
}

//function used to set the wall collision values for level 3
void set_wall_collision_values_Level_3 ( void )
{
	int m_Array[100];
	int m_counter = 0;
	int m_counter_x = 0;
	int m_counter_y = 0;

	Box.m_ArrayCounter = 0;

	std::ifstream Level_file( "Floor3.txt" );

	if ( Level_file.is_open() ) 
	{
		while( !Level_file.eof())
		{				

			Level_file >> m_Array[m_counter];		
			m_counter++;
			if ( Level_file.eof() )
			{
				break;
			}
		}
	}

	for( int i = 0; i <= m_counter; i++ )
	{
		if ( i % 2 == 0)
		{
			Box.m_Wall_collision_box_x[m_counter_x] = m_Array[i];
			m_counter_x++;
			Box.m_ArrayCounter++;
		}
		if ( i % 2 == 1)
		{
			Box.m_Wall_collision_box_y[m_counter_y] = m_Array[i];
			m_counter_y++;
		}
	}
}

//function used to set the wall collision values for level 4
void set_wall_collision_values_Level_4 ( void )
{
	int m_Array[100];
	int m_counter = 0;
	int m_counter_x = 0;
	int m_counter_y = 0;

	Box.m_ArrayCounter = 0;

	std::ifstream Level_file( "Floor4.txt" );

	if ( Level_file.is_open() ) 
	{
		while( !Level_file.eof())
		{				

			Level_file >> m_Array[m_counter];		
			m_counter++;
			if ( Level_file.eof() )
			{
				break;
			}
		}
	}

	for( int i = 0; i <= m_counter; i++ )
	{
		if ( i % 2 == 0)
		{
			Box.m_Wall_collision_box_x[m_counter_x] = m_Array[i];
			m_counter_x++;
			Box.m_ArrayCounter++;
		}
		if ( i % 2 == 1)
		{
			Box.m_Wall_collision_box_y[m_counter_y] = m_Array[i];
			m_counter_y++;
		}
	}
}

//function used to set the wall collision values for level 5
void set_wall_collision_values_Level_5 ( void )
{
	int m_Array[100];
	int m_counter = 0;
	int m_counter_x = 0;
	int m_counter_y = 0;

	Box.m_ArrayCounter = 0;

	std::ifstream Level_file( "Floor5.txt" );

	if ( Level_file.is_open() ) 
	{
		while( !Level_file.eof())
		{				

			Level_file >> m_Array[m_counter];		
			m_counter++;
			if ( Level_file.eof() )
			{
				break;
			}
		}
	}

	for( int i = 0; i <= m_counter; i++ )
	{
		if ( i % 2 == 0)
		{
			Box.m_Wall_collision_box_x[m_counter_x] = m_Array[i];
			m_counter_x++;
			Box.m_ArrayCounter++;
		}
		if ( i % 2 == 1)
		{
			Box.m_Wall_collision_box_y[m_counter_y] = m_Array[i];
			m_counter_y++;
		}
	}
}

//function used to move the character forward
void Character::ForwardCharacterAnimation ( void )
{
	for (int i = 0; i < 2; i++ )
	{
		Box.m_x_before[i] = Box.m_box_x[i];
		Box.m_y_before[i] = Box.m_box_y[i];
	}

	Char.m_x_before = Char.m_character_x;
	Char.m_y_before = Char.m_character_y;

	for( int i = 0; i < 4; i++ )
	{
		if(( m_character_y <= 40 ) && (Box.m_active == false ) || ( m_character_x != 280 ) && ( m_character_y == 40 ))
		{
			m_character_y = 40;
			break;
		}
		else
		{
			Blitting();
			m_character_y -= 10;
			bounding_box_collision();
			bounding_wall_collision();

			if ( i == 0)
			{
				SoundCheck();
			}

			rest(50);

			if( m_character_y == 0 )
			{
				Game_vals.m_Game_end = true;
			}

		}
	}

}

//function used to move the character backwards
void Character::BackwardsCharacterAnimation ( void )
{
	for (int i = 0; i < 2; i++ )
	{
		Box.m_x_before[i] = Box.m_box_x[i];
		Box.m_y_before[i] = Box.m_box_y[i];
	}

	Char.m_x_before = Char.m_character_x;
	Char.m_y_before = Char.m_character_y;

	for( int i = 0; i < 4; i++ )
	{
		if( m_character_y >= 400 )
		{
			m_character_y = 400;
			break;
		}
		else
		{	
			if ( i == 0)
			{
				SoundCheck();
			}

			Blitting();
			m_character_y += 10;
			bounding_box_collision();
			bounding_wall_collision();

			if ( i == 0)
			{
				SoundCheck();
			}

			rest(50);
		}
	}

}

//function used to move the character left
void Character::LeftCharacterAnimation ( void )
{

	for (int i = 0; i < 2; i++ )
	{
		Box.m_x_before[i] = Box.m_box_x[i];
		Box.m_y_before[i] = Box.m_box_y[i];
	}

	Char.m_x_before = Char.m_character_x;
	Char.m_y_before = Char.m_character_y;

	for( int i = 0; i < 4; i++ )
	{
		if( m_character_x <= 40 )
		{
			m_character_x = 40;
			break;
		}
		else
		{
			if ( i == 0)
			{
				SoundCheck();
			}
			Blitting();
			m_character_x -= 10;
			bounding_box_collision();
			bounding_wall_collision();

			if ( i == 0)
			{
				SoundCheck();
			}

			rest(50);			
		}
	}

}

//function used to move the character right
void Character::RightCharacterAnimation ( void )
{

	for (int i = 0; i < 2; i++ )
	{
		Box.m_x_before[i] = Box.m_box_x[i];
		Box.m_y_before[i] = Box.m_box_y[i];
	}

	Char.m_x_before = Char.m_character_x;
	Char.m_y_before = Char.m_character_y;

	for( int i = 0; i < 4; i++ )
	{
		if( m_character_x >= 520 )
		{
			m_character_x = 520;
			break;
		}
		else
		{
			if ( i == 0)
			{
				SoundCheck();
			}
			Blitting();
			m_character_x += 10;
			bounding_box_collision();
			bounding_wall_collision();

			if ( i == 0)
			{
				SoundCheck();
			}

			rest(50);
		}
	}

}

//function used to check whether to play character movement sound and box movement sound
void SoundCheck ( void )
{
	for (int i = 0; i < 2; i++)
	{
		Box.m_x_after[i] = Box.m_box_x[i];
		Box.m_y_after[i] = Box.m_box_y[i];
	}

	Char.m_x_after = Char.m_character_x;
	Char.m_y_after = Char.m_character_y;

	if (( Box.m_x_before[0] != Box.m_x_after[0]) || ( Box.m_x_before[1] != Box.m_x_after[1]) || ( Box.m_y_before[0] != Box.m_y_after[0]) || ( Box.m_y_before[1] != Box.m_y_after[1]))
	{
		/*play_sample*/( Box.m_BoxSlide , 255, 128, 1000, 0 );
	}
	if (( Char.m_x_before != Char.m_x_after) || ( Char.m_y_before != Char.m_y_after))
	{
		if ( Char.m_footstep == 0 )
		{
			/*play_sample*/( Char.m_Walking[Char.m_footstep] , 255, 128, 1000, 0 );

			Char.m_footstep += 1;
		}
		else
		{
			/*play_sample*/( Char.m_Walking[Char.m_footstep] , 255, 128, 1000, 0 );

			Char.m_footstep -= 1;
		}
	}
}

#endif //_Levels_H_