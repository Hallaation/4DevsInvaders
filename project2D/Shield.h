#pragma once

#include "Application2D.h"
#include "Texture.h"
#include "Vector2.h"

class Bullet;
class Shield
{
public:
	Shield() {}
	Shield(Vector2 pos);
	~Shield();

	// Check whether a bullet has collided
	// with the shield; if it has, and the
	// shield hasn't been destroyed yet,
	// destroy it
	void CheckCollision(Bullet& shotBy);

	// Draw the shield sprite in the window
	void Draw(aie::Renderer2D& renderer);

	// Stores whether or not the shield's
	// been hit by a bullet
	bool isDestroyed;

private:
	aie::Texture* sprite;
	Vector2 physVerts[4];
	Vector2 pos;
	int width;
	int height;
	char lives;
};