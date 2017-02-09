#include "SceneHandler.h"

std::vector<Bullet>* SceneHandler::bullets = nullptr;
std::vector<Shield>* SceneHandler::shields = nullptr;
std::vector<Enemy>* SceneHandler::aliens = nullptr;
//EnemyManager* SceneHandler::enemyManager = nullptr;
Player* SceneHandler::player = nullptr;
int SceneHandler::scoreNumeric = 0;