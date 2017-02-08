#include "EnemyManager.h"



EnemyManager::EnemyManager()
{

}


EnemyManager::~EnemyManager()
{
}

void EnemyManager::startup()
{
	// enemy test
	m_UFO = new Enemy(true, 30, 100, 500);

	for (int r = 0; r < m_iRows; r++){
		for (int c = 0; c < m_iColumns; c++){
			m_vEnemies.push_back(std::make_shared<Enemy>(false, 15, 100, 400));
		}
	}
}

void EnemyManager::Update(float deltatime)
{
	m_UFO->Update(deltatime);
	m_enemy->Update(deltatime);
}

void EnemyManager::Draw()
{
	m_UFO->Draw();
	m_enemy->Draw();
}

void EnemyManager::shutdown()
{
	delete m_UFO;
	delete m_enemy;
}
