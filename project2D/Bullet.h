#pragma once
#include "Vector2.h"
#include "Renderer2D.h"

// Direction Velocity Direction
enum class Direction { UP, DOWN };

#define BULLET_SPEED 3000.0f
#define BULLET_WIDTH 10.0f
#define BULLET_HEIGHT 20.0f

class Bullet
{
public:
	Bullet();
	Bullet(Vector2 position, Direction direction);
	~Bullet();

	void Update(const float deltaTime);
	void Draw(aie::Renderer2D& m_2Drender);

	Vector2 GetPosition();
	Direction GetDirection();
	void ChangePosition(Vector2 a_position);
	bool m_bulletActive;
private:
	const Vector2 BulletDirection();
	// Bullet Posiiton
	Vector2 m_position;
	// Bullet Fire Direction
	Direction m_direction;
};

