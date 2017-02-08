#pragma once
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();


	void startup();
	void Update(float deltatime);
	void Draw();
	void shutdown();

private:
	std::vector<std::shared_ptr<Enemy>>	m_vEnemies;

	Enemy* m_UFO;
	Enemy* m_enemy;

	const int m_iRows = 5;
	const int m_iColumns = 11;
	glm::vec2 * m_startPosition;

	// private functions
	void changeDirection();
};

