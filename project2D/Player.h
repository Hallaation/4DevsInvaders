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

	void Draw(aie::Renderer2D& renderer);
	void Update(float deltatime);

	int GetScore() { return m_iScore; }
	int GetLives();

	void SetScore(int a_iScore) { m_iScore = a_iScore; }
	void AddScore(int a_iScore) { m_iScore += a_iScore; }
	void BulletToggle();

	bool CollisionCheck(float a_x, float a_y);
	bool CollisionCheck(Bullet& aEnemyBullet);
	bool IsDead();
	Vector2 GetPosition();
	Bullet* GetBullet();

private:
	Vector2*            m_vPosition;
	aie::Texture*       m_texture;
	aie::Renderer2D*    m_2drenderer;
	aie::Font*          m_font;

	Bullet*              m_bullet;
	int                 m_iLives;
	int                 m_iScore;
	float				m_iSpeed;
	bool                m_bulletActive;
};

