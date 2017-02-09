#pragma once

#include <vector>
#include "Bullet.h"
#include "Shield.h"
#include "Player.h"
#include "EnemyManager.h"

class SceneHandler
{
	public:
		static std::vector<Bullet>* bullets;
		static std::vector<Enemy>* aliens;
		static EnemyManager * enemyManager;		
		static std::vector<Shield>* shields;
		static Player* player;
		static float scoreNumeric;

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

				// check if bullets have collided with enemies
				enemyManager->CollisionCheck(shot);

					player->CollisionCheck(shot.GetPosition().x, shot.GetPosition().y);
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

		static char* GetScoreAlpha()
		{
			float scoreCopy = scoreNumeric;
			unsigned int signlessScore = *(unsigned int*)(&scoreCopy);
			unsigned int exponent = signlessScore >> 24;
			unsigned char maxRadix = (char)pow(10, exponent);
			unsigned int scoreNumericIntegral = (int)scoreNumeric;

			char radixes[7] = { ((char)(scoreNumericIntegral % maxRadix / maxRadix)) + 48, 
								((char)(scoreNumericIntegral % (maxRadix / 10) / (maxRadix / 10))) + 48,
								((char)(scoreNumericIntegral % (maxRadix / 100) / (maxRadix / 100))) + 48, 
								((char)(scoreNumericIntegral % (maxRadix / 1000) / (maxRadix / 1000))) + 48, 
								((char)(scoreNumericIntegral % (maxRadix / 10000) / (maxRadix / 10000))) + 48, 
								((char)(scoreNumericIntegral % (maxRadix / 100000) / (maxRadix / 10000))) + 48, 
								((char)(scoreNumericIntegral % (maxRadix / 1000000) / (maxRadix / 100000))) + 48 };
			return radixes;
		}

	private:
		static unsigned char scoreAlpha[7];
};
