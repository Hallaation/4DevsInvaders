#pragma once
#include "Vector2.h"
#include "Renderer2D.h"

// Direction Velocity Direction
enum class Direction { UP, DOWN };

class Bullet
{
public:
	
	Bullet();
	Bullet(Vector2 position, Direction direction);
	~Bullet();
	
	void Update(const float deltaTime);
	void Draw();

	Vector2 GetPosition();
	Direction GetDirection();

private:
	const Vector2 BulletDirection();

	aie::Renderer2D* m_2Drender;

	// Bullet Posiiton
	Vector2 m_position;
	// Bullet Fire Direction
	Direction m_direction;

	// Speed
	const float m_speed = 350.0f;
	// Bullet Width
	const float m_bulletWidth = 10.0f;
	// Bullet Height
	const float m_bulletHeight = 20.0f;
};

