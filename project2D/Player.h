#pragma once
#include <cstring>
#include "Application2D.h"
class Vector2;

class Player
{
public:
	Player();
	~Player();
	aie::Texture*        m_texture;
	aie::Renderer2D*     m_2drenderer;
	aie::Font*           m_font;

	void Draw();
	void Update(float deltatime);
	
	int GetScore()                {return m_iScore;}

	void SetScore(int a_iScore)   {m_iScore = a_iScore;}

	void CollisionCheck(float a_x, float a_y);
protected:
	Vector2*    m_vPosition;
	int         m_iLives;
	int         m_iScore;

	const float m_iSpeed = 5;
	float m_SpeedModifier;
	

};

