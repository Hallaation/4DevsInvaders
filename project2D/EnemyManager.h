#pragma once
#include "Enemy.h"
#include <iostream>

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	// main functions
	void startup();
	void Update(float deltatime);
	void Draw(aie::Renderer2D& renderer);
	void shutdown();

	bool CollisionCheck(Bullet bullet);
	int enemyCount();
	void UFODirection(float deltatime);

private:
	std::vector<std::shared_ptr<Enemy>>	m_vEnemies;

	Enemy* m_UFO;
	Enemy* m_enemy;

	float m_iUFOTimer;
	const int m_iUFOInterval = 5;
	const int m_iRows = 5;
	const int m_iColumns = 11;
	glm::vec2 * m_startPosition;

	// private functions
	void changeDirection();
};

