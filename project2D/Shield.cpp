#include "Shield.h"

Shield::Shield(Vector2 position)
{
	sprite = aie::Texture("..\bin\textures\shield.png");

	float xDiff = 0.5 * sprite.getWidth();
	float yDiff = 0.5 * sprite.getHeight();

	float negaXDiff = xDiff * -1;
	float negaYDiff = yDiff * -1;

	physVerts[0] = position + (0.8 * Vector2(xDiff, yDiff));
	physVerts[1] = position + (0.8 * Vector2(xDiff, negaYDiff));
	physVerts[2] = position + (0.8 * Vector2(negaXDiff, negaYDiff));
	physVerts[3] = position + (0.8 * Vector2(negaXDiff, yDiff));

	pos = position;

	width = sprite.getWidth();
	height = sprite.getHeight();
	isDestroyed = false;
}

void Shield::CheckCollision(Bullet shotBy)
{
	bool isIntersecting;
	if (!isDestroyed)
	{
		// AABB check here
	}
}

void Shield::Draw()
{
	if (!isDestroyed)
	{
		aie::Renderer2D().drawSprite(&sprite, pos.data[0], pos.data[1], width, height);
	}
}

Shield::~Shield()
{
}