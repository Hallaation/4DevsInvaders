#include "SceneHandler.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	m_startPosition = new glm::vec2(60, 500);
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::startup()
{
	// enemy test
	m_UFO = new Enemy(true, 30, 100, 600);

	int xPos = (int)m_startPosition->x;
	int yPos = (int)m_startPosition->y;

	for (int r = 0; r < 40; r++){
		SceneHandler::aliens[r] = Enemy(false, 15.0f, (float)xPos, (float)yPos);
		xPos = (int)m_startPosition->x + (r % 10 == 0) * 60;
		yPos -= 60;
	}
}

void EnemyManager::Update(float deltatime)
{
	// update ufo
	//m_UFO->Update(deltatime);

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
	//m_UFO->Draw();
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

void EnemyManager::changeDirection()
{
	for each(Enemy alien in SceneHandler::aliens)
	{
		alien.changeDirection();
	}
}


