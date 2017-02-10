#pragma once

#include <list>
#include "Bullet.h"
#include "Shield.h"
#include "Player.h"
#include "EnemyManager.h"

struct SceneHandler
{
	static Bullet bullets[10];
	static char hiddenBullets;
	static char activeBullets;

	static Enemy aliens[40];
	static char hiddenAliens;

	static Shield shields[4];
	static char hiddenShields;

	static Player* player;
	static int scoreNumeric;

	static bool globalGameOver;
	static bool globalGameVictory;

	static void RemoveBullet()
	{
		hiddenBullets += 1;
		activeBullets -= 1;
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
		bool playerWinning = player->GetLives() > 0;
		if (hiddenAliens != 40 && playerWinning)
		{
			for (short i = 0; i < 4; i += 1)
			{
				shields[i].CheckCollision(*player->GetBullet());
			}

			for (short i = 0; i < 40; i += 1)
			{
				aliens[i].Update(0.01);

				if (!aliens[i].isDead())
				{
					aliens[i].collisionCheck(*player->GetBullet());
					player->CollisionCheck(aliens[i].GetBullet());

					for (short j = 0; j < 4; j += 1)
					{
						shields[j].CheckCollision(aliens[i].GetBullet());
					}
				}
			}
		}

		else if (hiddenAliens < 40 && !playerWinning)
		{
			globalGameOver = true;
			globalGameVictory = false;
		}

		else if (hiddenAliens == 40 && playerWinning)
		{
			globalGameOver = false;
			globalGameVictory = true;
		}
	}
};
