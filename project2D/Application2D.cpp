#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "EnemyManager.h"
#include "SceneHandler.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {
}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();
	//
	//m_texture = new aie::Texture("./textures/numbered_grid.tga");
	//m_shipTexture = new aie::Texture("./textures/player_ship.png");
	//
	//
	//m_audio = new aie::Audio("./audio/powerup.wav");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_player = new Player();

	// initialise enemies
	m_enemyManager = new EnemyManager();
	m_enemyManager->startup();

	// Initialise shields
	SceneHandler::shields[0] = (Shield(Vector2(100, 200)));
	SceneHandler::shields[1] = (Shield(Vector2(300, 200)));
	SceneHandler::shields[2] = (Shield(Vector2(500, 200)));
	SceneHandler::shields[3] = (Shield(Vector2(700, 200)));

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {

	delete m_player;
	m_enemyManager->shutdown();
	delete m_font;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->Update(deltaTime);

	SceneHandler::Update();
	//for each (Bullet bullet in SceneHandler::bullets)
	//{
	//	bullet.Update(deltaTime);
	//}

	/*// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;
	*/

	// example of audio
	//if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	//	m_audio->play();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	if (input->isKeyDown(aie::INPUT_KEY_J))
		m_depth++;
}

void Application2D::draw() {

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// wipe the screen to the background colour
	clearScreen();
	m_2dRenderer->begin();

	//for each (Bullet bullet in SceneHandler::bullets)
	//{
	//	//bullet.Draw(*m_2dRenderer);
	//}

	char score[15];
	sprintf_s(score, 14, "SCORE: %i", SceneHandler::scoreNumeric);

	if (SceneHandler::globalGameOver)
	{
		m_2dRenderer->drawText(m_font, "GAME OVER", getWindowWidth() / 2.2, getWindowHeight() / 2);
		m_2dRenderer->drawText(m_font, score, getWindowWidth() / 2.2, getWindowHeight() / 2 - 30);
	}

	else if (SceneHandler::globalGameVictory)
	{
		m_2dRenderer->drawText(m_font, "VICTORY", getWindowWidth() / 2.2, getWindowHeight() / 2);
		m_2dRenderer->drawText(m_font, score, getWindowWidth() / 2.285, getWindowHeight() / 2 - 30);
	}

	else 
	{
		// Draw player
		m_player->Draw(*m_2dRenderer);

		// draw enemies
		m_enemyManager->Draw(*m_2dRenderer);

		// Draw shields
		for each (Shield shield in SceneHandler::shields)
		{
			shield.Draw(*m_2dRenderer);
		}

		m_2dRenderer->drawText(m_font, score, 0, 0);
	}

	/*
	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites

	// demonstrate animation
	m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	// demonstrate spinning sprite
	m_2dRenderer->setUVRect(0,0,1,1);
	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 20, m_timer, 1);

	// draw a thin line
	m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	*/

	m_2dRenderer->end();
}
