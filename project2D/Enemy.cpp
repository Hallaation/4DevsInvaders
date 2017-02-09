#include "Enemy.h"
#include "SceneHandler.h"
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
	//m_bullet		= new Bullet(Vector2(m_spPosition->x, m_spPosition->y), Direction::DOWN);
	m_bBulletAlive	= false;
	InitTextures();
}

Enemy::~Enemy()
{
	//delete m_bullet;
}

void Enemy::InitTextures()
{
	if (m_bUFO)
	{
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/UFO.png"));
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/UFO_Dead.png"));
		m_fMaxLeft = -50;
		m_fMaxRight = 1300;
	}
	else
	{
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/Enemy1_0.png"));
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/Enemy1_1.png"));
		m_vTextures.push_back(std::make_shared<aie::Texture>("./textures/Enemy_Explode.png"));
		m_fMaxLeft = 50;
		m_fMaxRight = 1200;
	}
}

/// update enemy
void Enemy::Update(float deltatime)
{
	// skip if UFO
	if (!m_bUFO) {
		// animate enemy
		textureSwap(deltatime);
		// check enemy direction
		enemyDirection();
		// shoot bullet
		//if (!m_bBulletAlive){
		//	shot(deltatime);
		//}
	}
	// update enemy position
	moveEnemy(deltatime);
}

/// draw enemy to screen
void Enemy::Draw(aie::Renderer2D& renderer)
{
	if (!m_bDead)
	{
		renderer.drawSprite(m_vTextures[m_iTexture].get(), m_spPosition->x, m_spPosition->y, m_iTextureSize, m_iTextureSize, 0, 0);
	}
	else
	{
		//renderer.drawSprite(m_vTextures.back().get(), m_spPosition->x, m_spPosition->y, m_iTextureSize, m_iTextureSize, 0, 0);
	}

	// draw bullet is there is one
	//if (m_bBulletAlive) {
	//	m_bullet->Draw();
	//}
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
		// Destroy/de-activate bullet here...
		SceneHandler::RemoveAlien();
		SceneHandler::scoreNumeric += 1;
		SceneHandler::aliens[SceneHandler::hiddenAliens - 1].setDead(true);
	}

	return m_bDead;
}

bool Enemy::isDead()
{
	return m_bDead;
}

void Enemy::setDead(bool status)
{
	m_bDead = status;
}

/// shoot bullet
void Enemy::shot(float deltatime)
{
	if (m_bBulletAlive)
	{
		//m_bullet->Update(deltatime);
		//if (m_bullet->GetPosition().y <= 0)
		//{
		//	m_bBulletAlive = false;
		//}
	}
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
	if (m_bMoveRight && m_spPosition->x < m_fMaxRight) {
		m_spPosition->x += m_fSpeed * deltatime;
	}
	// move left
	if (!m_bMoveRight && m_spPosition->x > m_fMaxLeft) {
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
	if (m_bMoveRight && m_spPosition->x > 1200) {
		m_bHitEdge = true;
	}
}
