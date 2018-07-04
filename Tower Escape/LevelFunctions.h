#ifndef _LevelFunctions_H_
#define _LevelFunctions_H_

/// \file  LevelFunctions.h
/// \initialises all functions for the Levels
/// \author Callum Berger

//initialising functions for the levels
void KeyboardResponse( void );
void bounding_box_collision ( void );
void Blitting ( void );
void BitmapLoading ( void );
void bounding_wall_collision_box( void );
void bounding_wall_collision( void );
void bounding_box_on_box_collision( int );
void SoundCheck ( void );
void Level1 ( void );
void Level2 ( void );
void Level3 ( void );
void Level4 ( void );
void Level5 ( void );
void set_wall_collision_values_Level_2 ( void );
void set_wall_collision_values_Level_3 ( void );
void set_wall_collision_values_Level_4 ( void );
void set_wall_collision_values_Level_5 ( void );

#endif //_LevelFunctions_H_