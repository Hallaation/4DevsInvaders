#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Bullet.h"

#include <glm/glm.hpp>
#include <memory>
#include <vector>

class Enemy
{
public:
	Enemy::Enemy() {}
	Enemy(bool UFO, float speed, float xPos, float yPos);
	~Enemy();

	void InitTextures();
	std::shared_ptr<glm::vec2> position();
	std::shared_ptr<aie::Texture> texture(int id);

	// direction related
	bool hitEdge();
	bool hitEdge(bool swap);
	void changeDirection();

	bool collisionCheck(Bullet& bullet);
	bool isDead();
	void setDead(bool status);

	void shot(float deltatime);

	void Draw(aie::Renderer2D& renderer);
	void Update(float deltatime);

	Bullet& GetBullet();


private:
	std::vector<std::shared_ptr<aie::Texture>>	m_vTextures;
	std::shared_ptr<aie::Renderer2D>			m_spRenderer;
	std::shared_ptr<glm::vec2>					m_spPosition;
	Bullet m_bullet;
	int		m_iTexture;
	int		m_iTextureSize;
	float	m_fMaxRight;
	float	m_fMaxLeft;
	float	m_fTimer;
	bool	m_bMoveRight;
	float	m_fSpeed;
	bool	m_bScreenEdge;
	bool	m_bUFO;
	bool	m_bCanShoot;
	bool	m_bDead;
	bool	m_bHitEdge;

	int m_iHealth;
	float m_fTime;
	float m_fTimers;
	// private functions
	void textureSwap(float deltatime);
	void moveEnemy(float deltatime);
	void enemyDirection();
};

