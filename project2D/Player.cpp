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
	m_texture = new aie::Texture("./textures/player_ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_vPosition = new Vector2(100, 100);

	SceneHandler::bullets[0] = Bullet(*m_vPosition, Direction::UP);
	m_bullet = &SceneHandler::bullets[0];
	m_iLives = 6;
	m_iScore = 0;
	m_iSpeed = 2000;
	m_bulletActive = false;
	SceneHandler::player = this;
}

Player::Player(Vector2 a_position)
{
	m_texture = new aie::Texture("./textures/player_ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_vPosition = new Vector2(a_position);
	m_iLives = 6;
	m_iScore = 0;
}


Player::~Player()
{
	delete m_vPosition;
	delete m_font;
	delete m_texture;
}

void Player::Draw(aie::Renderer2D& renderer)
{
	renderer.drawSprite(m_texture, m_vPosition->x, m_vPosition->y, 0, 0, 0, 0);
	char score[16];
	sprintf_s(score, 16, "Lives: %i", m_iLives);
	renderer.drawText(m_font, score, 30, 20);
	if (m_bullet->m_bulletActive) {
		m_bullet->Draw(renderer);
	}
}

int Player::GetLives()
{
	return m_iLives;
}

void Player::Update(float deltatime)
{
	aie::Input* input = aie::Input::getInstance();
	//SceneHandler::scoreNumeric = m_iScore;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && m_vPosition->x > 50)
		m_vPosition->x -= m_iSpeed * deltatime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && m_vPosition->x < 1230)
		m_vPosition->x += m_iSpeed * deltatime;
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		if (!m_bullet->m_bulletActive) {
			m_bullet->m_bulletActive = true;
			m_bullet->ChangePosition(*m_vPosition);
		}
	}

	if (m_bullet->m_bulletActive)
	{
		m_bullet->Update(deltatime);
		if (m_bullet->GetPosition().y >= 720)
		{
			m_bullet->m_bulletActive = false;
			m_bullet->ChangePosition(Vector2(0, 0));
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
		m_vPosition->y > a_y + m_texture->getHeight() / 2 &&
		m_vPosition->y < a_y - m_texture->getHeight() / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::CollisionCheck(Bullet& a_EnemyBullet)
{
	if (a_EnemyBullet.GetDirection() == Direction::DOWN)
	{
		if (m_vPosition->x > a_EnemyBullet.GetPosition().x - m_texture->getWidth() / 2 &&
			m_vPosition->x < a_EnemyBullet.GetPosition().x + m_texture->getWidth() / 2 &&
			m_vPosition->y > a_EnemyBullet.GetPosition().y - m_texture->getHeight() / 2 &&
			m_vPosition->y < a_EnemyBullet.GetPosition().y + m_texture->getHeight() / 2)
		{
			a_EnemyBullet.m_bulletActive = false;
			a_EnemyBullet.ChangePosition(Vector2(10000, 10000));
			m_iLives--;
			return true;
		}
		else
		{
			return false;
		}
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
