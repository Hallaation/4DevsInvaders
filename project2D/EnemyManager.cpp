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
	m_UFO = new Enemy(true, 50, 100, 600);

	int xPos = m_startPosition->x;
	int yPos = m_startPosition->y;

	for (int r = 0; r < m_iRows; r++){
		for (int c = 0; c < m_iColumns; c++){
			m_vEnemies.push_back(std::make_shared<Enemy>(false, 15, xPos, yPos));
			xPos += 60;
		}
		xPos = m_startPosition->x;
		yPos -= 60;
	}
}

void EnemyManager::Update(float deltatime)
{
	// update ufo
	m_UFO->Update(deltatime);
	UFODirection(deltatime);

	// update enemies
	for (auto e : m_vEnemies)
	{
		e.get()->Update(deltatime);
	}
	
	// have any enemies hit the edge
	// update enemies
	for (auto e : m_vEnemies)
	{
		if (e.get()->hitEdge()) {
			e.get()->hitEdge(false);
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
	for (auto e : m_vEnemies)
	{
		e.get()->Draw();
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
	for (int i = 0; i < m_vEnemies.size(); i++)
	{
		if (m_vEnemies[i].get()->collisionCheck(bullet)) {
			result = true;
			m_vEnemies.erase(m_vEnemies.begin() + i);
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
	for (auto e : m_vEnemies)
	{
		e.get()->changeDirection();
	}
}


