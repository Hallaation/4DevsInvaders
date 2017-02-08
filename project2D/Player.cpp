#include "Player.h"
#include "Vector2.h"
#include "Application2D.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
Player::Player()
{
	m_texture = new aie::Texture("./textures/player_ship.png");
	m_iLives = 6;
	m_iScore = 0;
	m_vPosition = new Vector2(100,100);
	m_2drenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_SpeedModifier = 1;
}


Player::~Player()
{
	delete m_vPosition;
	delete m_texture;
	delete m_2drenderer;
	delete m_font;
}

void Player::Draw()
{
	aie::Input* input = aie::Input::getInstance();
	m_2drenderer->begin();
	m_2drenderer->drawSprite(m_texture, m_vPosition->x, m_vPosition->y, 0, 0, 0, 0);
	char score[16];
	sprintf_s(score, 16, "Lives: %i", m_iLives);
	m_2drenderer->drawText(m_font, score, 30,20);
	m_2drenderer->end();
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
		std::cout << "shoot bullet" << std::endl;
	}

}

void Player::CollisionCheck(float a_x, float a_y)
{
}

