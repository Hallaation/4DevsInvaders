#include "SceneHandler.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	m_startPosition = new glm::vec2(51, 500);
	m_iUFOTimer = 0;
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::startup()
{
	// enemy test
	m_UFO = new Enemy(true, 30, 100, 600);


	int xPos = m_startPosition->x;
	int yPos = m_startPosition->y;

	for (int r = 0; r < m_iRows; r++){
		for (int c = 0; c < m_iColumns; c++)
		{
			SceneHandler::aliens[c + r] = Enemy(false, 15.0f, (float)xPos, (float)yPos);
			xPos += 60;
		}
		xPos = (int)m_startPosition->x;
		yPos -= 60;
	}
}

void EnemyManager::Update(float deltatime)
{
	// update ufo
	m_UFO->Update(deltatime);
	UFODirection(deltatime);

	// update enemies
	for each(Enemy alien in SceneHandler::aliens)
	{
		alien.Update(deltatime);
	}
	
	// have any enemies hit the edge
	// update enemies
	for each(Enemy alien in SceneHandler::aliens)
	{
		if (alien.hitEdge()) 
		{
			alien.hitEdge(false);
			changeDirection();
			break;
		}
	}
}

void EnemyManager::Draw()
{
	// draw ufo
	m_UFO->Draw();
	// draw enemies
	for each(Enemy alien in SceneHandler::aliens)
	{
		alien.Draw();
	}
}

void EnemyManager::shutdown()
{
	if (m_UFO != nullptr)
	{
		delete m_UFO;
	}
	m_vEnemies.erase(m_vEnemies.begin(), m_vEnemies.end());
}

bool EnemyManager::CollisionCheck(Bullet bullet)
{
	bool result = false;
	int pos = 0;

	// check if bullet hit any enemies
	for each (Enemy alien in SceneHandler::aliens)
	{
		if (alien.collisionCheck(bullet)) {
			result = true;
			SceneHandler::RemoveAlien();
			break;
		}
	}

	// check if bullet hit ufo
	if (m_UFO->collisionCheck(bullet)) {
		result = true;
	}

	return result;
}

int EnemyManager::enemyCount()
{
	return m_vEnemies.size();
}

void EnemyManager::UFODirection(float deltatime)
{
	// if moving left and hits the left edge, move right
	if (!m_UFO->hitEdge() && (m_UFO->position()->x > 1300 || m_UFO->position()->x < -30)) {
		m_UFO->hitEdge(true);
	}

	if (m_UFO->hitEdge())
	{
		m_iUFOTimer += deltatime;
	}

	if (m_iUFOTimer >= m_iUFOInterval) {
		m_UFO->changeDirection();
		m_iUFOTimer = 0;
		m_UFO->hitEdge(false);
	}
}

void EnemyManager::changeDirection()
{
	for each(Enemy alien in SceneHandler::aliens)
	{
		alien.changeDirection();
	}
}


