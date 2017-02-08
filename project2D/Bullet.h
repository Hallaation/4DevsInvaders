#pragma once
#include "Vector2.h"
#include "Texture.h"
#include "Renderer2D.h"

// Direction Velocity Direction
enum class Direction { UP, DOWN };

using namespace aie;

class Bullet
{
public:
	
	Bullet();
	Bullet(Vector2 position, Direction direction);
	~Bullet();
	
	void update(const float deltaTime);
	void draw(Renderer2D& render);

	Vector2 GetPosition();

private:
	const Vector2 GetDirection();

	// Texture
	Texture* m_texture = nullptr;
	// Position
	Vector2 m_position;

	// Speed
	const float m_speed = 250.0f;

	// Bullet Direction
	Direction m_direction;
};

