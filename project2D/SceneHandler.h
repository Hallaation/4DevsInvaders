#pragma once

#include <vector>
#include "Bullet.h"
#include "Shield.h"
#include "Player.h"

static struct SceneHandler
{
	static std::vector<Bullet>* bullets;
	//std::vector<Enemy> aliens;
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

				//for each (Enemy alien in aliens)
				//{
				//
				//}

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