#pragma once

#include "Application2D.h"
#include "Texture.h"
#include "Vector2.h"

class Bullet;
class Shield
{
public:
	Shield(Vector2 pos);
	~Shield();

	// Check whether a bullet has collided
	// with the shield; if it has, and the
	// shield hasn't been destroyed yet,
	// destroy it
	void CheckCollision(Bullet shot);

	// Draw the shield sprite in the window
	void Draw();

private:
	aie::Texture sprite;
	Vector2 physVerts[4];
	Vector2 pos;
	float width;
	float height;
	bool isDestroyed;
};