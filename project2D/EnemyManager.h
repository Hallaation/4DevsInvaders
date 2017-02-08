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
	std::vector<std::shared_ptr<aie::Texture>>	m_vEnemies;

	Enemy* m_UFO;
	Enemy* m_enemy;
};

