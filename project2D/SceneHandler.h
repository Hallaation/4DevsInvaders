#pragma once

#include <vector>
#include "Bullet.h"
#include "Shield.h"
#include "Player.h"
#include "Enemy.h"

struct SceneHandler
{
	static std::vector<Bullet>* bullets;
	static std::vector<Enemy>* aliens;
	static std::vector<Shield>* shields;
	static Player* player;
	static int scoreNumeric;

	static void StartUp()
	{
		bullets = new std::vector<Bullet>();
		aliens = new std::vector<Enemy>();
		shields = new std::vector<Shield>();
	}

	static void Update()
	{
		if (aliens->size() > 0 /*&& player->health > 0*/)
		{
			for each (Bullet shot in (*bullets))
			{
				for each (Shield shield in (*shields))
				{
					shield.CheckCollision(shot);
				}

				for each (Enemy alien in (*aliens))
				{
					//
				}

				player->CollisionCheck(shot);
			}
		}

		else if (aliens->size() > 0 /*&& player.health <= 0*/)
		{
			// Display game-over screen
		}
		
		else 
		{
			// Display game-win screen :)
		}
	}

	static void Shutdown()
	{
		delete bullets;
		bullets = nullptr;

		delete aliens;
		aliens = nullptr;

		delete shields;
		shields = nullptr;
	}
};