#include "Player.h"
#include "Vector2.h"
#include "Application2D.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "SceneHandler.h"
#include <iostream>

using namespace std;
Player::Player()
{
	m_2drenderer = new aie::Renderer2D();
	m_texture = new aie::Texture("./textures/player_ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_vPosition = new Vector2(100, 100);
	m_iLives = 6;
	m_iScore = 0;
	m_bullet = new Bullet(*m_vPosition, Direction::UP);
	m_bulletActive = false;
	SceneHandler::player = this;
}

Player::Player(Vector2 a_position)
{
	m_2drenderer = new aie::Renderer2D();
	m_texture = new aie::Texture("./textures/player_ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_vPosition = new Vector2(a_position);
	m_iLives = 6;
	m_iScore = 0;
}


Player::~Player()
{
	delete m_vPosition;
	delete m_bullet;
	//delete m_texture;
	//delete m_2drenderer;
	//delete m_font;
}

void Player::Draw()
{
	m_2drenderer->drawSprite(m_texture, m_vPosition->x, m_vPosition->y, 0, 0, 0, 0);
	char score[16];
	sprintf_s(score, 16, "Lives: %i", m_iLives);
	m_2drenderer->drawText(m_font, score, 30, 20);
	m_2drenderer->end();
	if (m_bulletActive) {
		m_bullet->Draw();
	}
}

void Player::Update(float deltatime)
{
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && m_vPosition->x > 50)
		m_vPosition->x -= m_iSpeed;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && m_vPosition->x < 1230)
		m_vPosition->x += m_iSpeed;
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		if (!m_bulletActive) {
			m_bulletActive = true;
			m_bullet->ChangePosition(*m_vPosition);
		}
	}

	if (m_bulletActive) 
	{
		m_bullet->Update(deltatime);
		if (m_bullet->GetPosition().y >= 720)
		{
			BulletToggle();
		}
	}
}

void Player::BulletToggle()
{
	m_bulletActive = false;
}

bool Player::CollisionCheck(float a_x, float a_y)
{
	if (m_vPosition->x > a_x - m_texture->getWidth() / 2 &&
		m_vPosition->x < a_x + m_texture->getWidth() / 2 &&
		m_vPosition->y > a_y - m_texture->getHeight() / 2 &&
		m_vPosition->y < a_y + m_texture->getHeight() / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::CollisionCheck(Bullet a_EnemyBullet)
{
	
	if (m_vPosition->x > a_EnemyBullet.GetPosition().x - m_texture->getWidth() / 2 &&
		m_vPosition->x < a_EnemyBullet.GetPosition().x + m_texture->getWidth() / 2 &&
		m_vPosition->y > a_EnemyBullet.GetPosition().y - m_texture->getHeight() / 2 &&
		m_vPosition->y < a_EnemyBullet.GetPosition().y + m_texture->getHeight() / 2)
	{
		m_iLives--;
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::IsDead()
{
	if (m_iLives == -1)
	{
		return true;
	}
	else return false;
}

Vector2 Player::GetPosition()
{
	return *m_vPosition;
}

Bullet * Player::GetBullet()
{
	return m_bullet;
}
