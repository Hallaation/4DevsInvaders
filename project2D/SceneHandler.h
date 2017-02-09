#pragma once

#include <vector>
#include "Bullet.h"
#include "Shield.h"
#include "Player.h"
#include "EnemyManager.h"

static struct SceneHandler
{
	static std::vector<Bullet>* bullets;
	//std::vector<Enemy> aliens;
	static EnemyManager * enemyManager;
	static std::vector<Shield>* shields;
	static Player* player;

	static void Update()
	{
		// if (aliens.size > 0 && player.health > 0)
		if (true)
		{
			for each (Bullet shot in (*bullets))
			{
				for each (Shield shield in (*shields))
				{
					shield.CheckCollision(shot);
				}

				// check if bullets have collided with enemies
				enemyManager->CollisionCheck(shot);

				player->CollisionCheck(shot.GetPosition().x, shot.GetPosition().y);
			}
		}

		//else if (aliens.size > 0 && player.health <= 0)
		//{
			// Display game-over screen
		//}

		//else 
		//{
		//	// Display game-win screen :)
		//}
	}
};