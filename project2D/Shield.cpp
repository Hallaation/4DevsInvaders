#include "SceneHandler.h"
#include "Bullet.h"
#include "Shield.h"

Shield::Shield(Vector2 position)
{
	sprite = new aie::Texture("../bin/textures/shieldSprite.png");

	float xDiff = (float)(0.5 * sprite->getWidth());
	float yDiff = (float)(0.5 * sprite->getHeight());

	float negaXDiff = xDiff * -1;
	float negaYDiff = yDiff * -1;

	physVerts[0] = position + (0.8f * Vector2(xDiff, yDiff));
	physVerts[1] = position + (0.8f * Vector2(xDiff, negaYDiff));
	physVerts[2] = position + (0.8f * Vector2(negaXDiff, negaYDiff));
	physVerts[3] = position + (0.8f * Vector2(negaXDiff, yDiff));

	pos = position;

	width = sprite->getWidth();
	height = sprite->getHeight();
	lives = 5;
	isDestroyed = false;
}

Shield::~Shield()
{
}

void Shield::CheckCollision(Bullet& shotBy)
{
	if (lives == 0)
	{
		isDestroyed = true;
	}

	bool xIntersection = shotBy.GetPosition().x > physVerts[3].x && shotBy.GetPosition().x < physVerts[1].x;
	bool yIntersection = shotBy.GetPosition().y > physVerts[1].y && shotBy.GetPosition().y < physVerts[3].y;
	bool isIntersecting = xIntersection && yIntersection;
	if (!isDestroyed && isIntersecting)
	{
		SceneHandler::RemoveShield();
  		lives -= 1;
		shotBy.m_bulletActive = false;
		shotBy.ChangePosition(Vector2(10000, 10000));
	}
}

void Shield::Draw(aie::Renderer2D& renderer)
{
	if (!isDestroyed)
	{
		renderer.drawSprite(sprite, pos.x, pos.y, (float)width, (float)height);
	}
}