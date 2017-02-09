#pragma once

#include <list>
#include "Bullet.h"
#include "Shield.h"
#include "Player.h"
#include "EnemyManager.h"

struct SceneHandler
{
	static Bullet bullets[200];
	static char hiddenBullets;
	static char activeBullets;
	
	static Enemy aliens[40];
	static char hiddenAliens;

	static Shield shields[4];
	static char hiddenShields;

	static Player* player;
	static int scoreNumeric;

	static void RemoveBullet()
	{
		hiddenBullets += 1;
	}

	static void RemoveAlien()
	{
		hiddenAliens += 1;
	}

	static void RemoveShield()
	{
		hiddenShields += 1;
	}

	static void Update()
	{
		if (hiddenAliens > 0 /*&& player->health > 0*/)
		{
			for each (Bullet shot in bullets)
			{
				for each (Shield shield in shields)
				{
					shield.CheckCollision(shot);
				}

				for each (Enemy alien in aliens)
				{
					//
				}

				player->CollisionCheck(shot);
			}
		}

		else if (hiddenAliens == 40 /*&& player.health <= 0*/)
		{
			// Display game-over screen
		}
		
		else 
		{
			// Display game-win screen :)
		}
	}
};
