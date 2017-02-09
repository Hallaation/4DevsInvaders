#include "Enemy.h"
#include <iostream>

Enemy::Enemy(bool UFO, float speed, float xPos, float yPos)
{
	m_bUFO			= UFO;
	m_bMoveRight	= true;
	m_fSpeed		= speed;
	m_bScreenEdge	= false;
	m_bCanShoot		= false;
	m_bDead			= false;
	m_spPosition	= std::make_shared<glm::vec2>(xPos,yPos);
	m_spRenderer	= std::make_shared<aie::Renderer2D>();
	m_iTexture		= 0;
	m_iTextureSize	= 50;
	m_fTimer		= 0;
	InitTextures();
}

Enemy::~Enemy()
{
}

void Enemy::InitTextures()
{
	if (m_bUFO)
	{
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/UFO.png"));
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/UFO_Dead.png"));
	}
	else
	{
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/Enemy1_0.png"));
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/Enemy1_1.png"));
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/Enemy_Explode.png"));
	}
}

std::shared_ptr<glm::vec2> Enemy::position()
{
	return m_spPosition;
}

std::shared_ptr<aie::Texture> Enemy::texture(int id)
{
	return m_vTextures[id];
}

bool Enemy::hitEdge()
{
	return m_bHitEdge;
}

bool Enemy::hitEdge(bool swap)
{
	m_bHitEdge = swap;
	return m_bHitEdge;
}

void Enemy::changeDirection()
{
	m_bMoveRight = !m_bMoveRight;
}

bool Enemy::collisionCheck(Bullet bullet)
{
	if (m_spPosition->x > bullet.GetPosition().x - m_iTextureSize / 2 &&
		m_spPosition->x < bullet.GetPosition().x + m_iTextureSize / 2 &&
		m_spPosition->y > bullet.GetPosition().y - m_iTextureSize / 2 &&
		m_spPosition->y < bullet.GetPosition().y + m_iTextureSize / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// update enemy 
void Enemy::Update(float deltatime)
{	
	// skip if UFO
	if (!m_bUFO) {
		// check enemy direction
		enemyDirection();
		// animate enemy
		textureSwap(deltatime);
	}
	// update enemy position
	moveEnemy(deltatime);
}

/// draw enemy to screen
void Enemy::Draw()
{
	m_spRenderer.get()->begin();

	if (!m_bDead)
	{
		m_spRenderer->drawSprite(m_vTextures[m_iTexture].get(), m_spPosition->x, m_spPosition->y, m_iTextureSize, m_iTextureSize, 0, 0);
	}
	else
	{
		m_spRenderer->drawSprite(m_vTextures.back().get(), m_spPosition->x, m_spPosition->y, m_iTextureSize, m_iTextureSize, 0, 0);
	}

	m_spRenderer.get()->end();
}
/// swap enemies texture overtime
void Enemy::textureSwap(float deltatime)
{
	if (m_fTimer <= 1.5) {
		m_fTimer += deltatime;
	}
	else {
		m_fTimer = 0;
		// swap texture
		m_iTexture = (m_iTexture == 0 ? 1 : 0);
	}
}

void Enemy::moveEnemy(float deltatime)
{
	// move right
	if (m_bMoveRight && m_spPosition->x < 1400) {
		m_spPosition->x += m_fSpeed * deltatime;
	}
	// move left
	if (!m_bMoveRight && m_spPosition->x > -100) {
		m_spPosition->x -= m_fSpeed * deltatime;
	}
}

void Enemy::enemyDirection()
{
	// if moving left and hits the left edge, move right
	if (!m_bMoveRight && m_spPosition->x < 50) {
		m_bHitEdge = true;
	}
	// if moving right and hits the right edge, move left
	if (m_bMoveRight && m_spPosition->x > 1250) {
		m_bHitEdge = true;
	}
}