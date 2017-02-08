#pragma once
#include <cstring>
#include "Application2D.h"
#include "Bullet.h"
#include <vector>
class Vector2;


class Player
{
public:
	Player();
	Player(Vector2 a_position);
	~Player();


	void Draw();
	void Update(float deltatime);
	
	int GetScore()                {return m_iScore;}

	void SetScore(int a_iScore)   {m_iScore = a_iScore;}

	bool CollisionCheck(float a_x, float a_y);
	bool CollisionCheck(Bullet aEnemyBullet);
	bool IsDead();
	Vector2 GetPosition();
private:
	Vector2*            m_vPosition;
	std::vector<Bullet>  m_bullets;
	aie::Texture*        m_texture;
	aie::Renderer2D*     m_2drenderer;
	aie::Font*           m_font;

	int                 m_iLives;
	int                 m_iScore;
	const float         m_iSpeed = 5;

};

