#ifndef _ObjectClasses_H_
#define _ObjectClasses_H_

/// \file  ObjectClasses.h
/// \Contains all classes for objects and game values
/// \author Callum Berger

#include <allegro.h>

//Box Class containing all variables and functions to do with the Box object

class BoxObject
{
public:

	void SetBoxValues ( int, int, int, int, int, int, bool);

	int m_x_before[2];
	int m_x_after[2];
	int m_y_before[2];
	int m_y_after[2];
	int m_box_x[2];
	int m_box_y[2];
	int m_box_box_w;
	int m_box_box_h;
	bool m_active;
	int m_Wall_collision_box_x[50];
	int m_Wall_collision_box_y[50];
	int m_ArrayCounter;
	BITMAP *m_box;
	SAMPLE *m_BoxSlide;

	/*void Set_m_x_before ( float, int );
	void Set_m_x_after ( float, int );
	void Set_m_y_before ( float, int );
	void Set_m_y_after ( float, int );
	void Set_m_box_x ( float, int );
	void Set_m_box_y ( float, int );
	void Set_m_box_box_w ( float );
	void Set_m_box_box_h ( float );
	void Set_m_active ( float );
	void Set_m_Wall_collision_box_x ( float, int );
	void Set_m_Wall_collision_box_y ( float, int );
	void Set_m_ArrayCounter ( float );
	void Set_m_box ( BITMAP );
	void Set_m_BoxSlide ( SAMPLE );

	float Get_m_x_before ( void ) const;
	float Get_m_x_after ( void ) const;
	float Get_m_y_before ( void ) const;
	float Get_m_y_after ( void ) const;
	float Get_m_box_x ( void ) const;
	float Get_m_box_y ( void ) const;
	float Get_m_box_box_w ( void ) const;
	float Get_m_box_box_h ( void ) const;
	float Get_m_active ( void ) const;
	float Get_m_Wall_collision_box_x ( void ) const;
	float Get_m_Wall_collision_box_y ( void ) const;
	float Get_m_ArrayCounter ( void ) const;
	BITMAP Get_m_box ( void ) const;
	SAMPLE Get_m_BoxSlide ( void ) const;*/

private:

	
} Box;

//function used to set all variables within the Box Class
void BoxObject::SetBoxValues ( int x1, int y1, int x2, int y2, int w, int h, bool v)
{
	m_box_x[0] = x1;
	m_box_y[0] = y1;
	m_box_x[1] = x2;
	m_box_y[1] = y2;
	m_box_box_w = w;
	m_box_box_h = h;
	m_active = v;
}

//Character Class containing all variables and functions to do with the Character object

class Character
{
public:

	void SetCharacterValues ( int, int, int, int, int );
	void ForwardCharacterAnimation ( void );
	void BackwardsCharacterAnimation ( void );
	void LeftCharacterAnimation ( void );
	void RightCharacterAnimation ( void );
int m_character_x;
	int m_character_y;
	int m_character_box_w;
	int m_character_box_h;
	int m_footstep;
	int m_x_before;
	int m_x_after;
	int m_y_before;
	int m_y_after;

	BITMAP *m_test;

	SAMPLE *m_Walking[2];
private:

	

} Char;

//function used to set all variables within the Character Class
void Character::SetCharacterValues( int x, int y, int w, int h, int f )
{
	m_character_x = x;
	m_character_y = y;
	m_character_box_w = w;
	m_character_box_h = h;
	m_footstep = f;
}

//Switch Class containing all variables and functions to do with the Switch object

class SwitchPanel
{
public:

	int m_Switch_x;
	int m_Switch_y;
	int m_Switch2_x;
	int m_Switch2_y;

	BITMAP *m_Switch;

	void Set_values ( int, int );
	void Set_values_2 ( int, int );

private:

} SwitchBox;

//function used to set the first variables within the SwitchPanel Class
void SwitchPanel::Set_values( int x, int y )
{
	m_Switch_x = x;
	m_Switch_y = y;
}

//function used to set the second variables within the SwitchPanel Class
void SwitchPanel::Set_values_2( int x, int y )
{
	m_Switch2_x = x;
	m_Switch2_y = y;
}

//Game Values Class containing all variables and functions to do with the Game Values

class Game_values
{
public:

	void Set_vals ( bool, bool, bool );
bool m_Exit;
	bool m_Game_end;
	bool m_Reset;
	SAMPLE *m_BackgroundMusic;
private:

	

} Game_vals;

//function used to set all variables within the Game_values Class
void Game_values::Set_vals ( bool exit, bool end, bool R )
{
	m_Exit = exit;
	m_Game_end = end;
	m_Reset = R;
}

#endif //_ObjectClasses_H_