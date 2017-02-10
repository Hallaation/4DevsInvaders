#include "SceneHandler.h"

Bullet SceneHandler::bullets[10];
Enemy SceneHandler::aliens[40];
Shield SceneHandler::shields[4];
Player* SceneHandler::player = nullptr;
int SceneHandler::scoreNumeric = 0;
char SceneHandler::activeBullets = 0;
char SceneHandler::hiddenBullets = 0;
char SceneHandler::hiddenAliens = 0;
char SceneHandler::hiddenShields = 0;

bool SceneHandler::globalGameOver = false;
bool SceneHandler::globalGameVictory = false;