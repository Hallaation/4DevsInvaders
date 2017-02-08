#include "Bullet.h"

Bullet::Bullet()
{
	m_position = Vector2(0, 0);
	m_direction = Direction::UP;
}

// Vector2: Starting Position | Direction: Enum Bullet Movement Direction
Bullet::Bullet(Vector2 position, Direction direction)
{
	m_direction = direction;
	m_position = position;
}

Bullet::~Bullet()
{
	if(m_texture != nullptr)
		delete m_texture;
}

void Bullet::update(const float deltaTime)
{
	Vector2 velocity = GetDirection();
	velocity = (velocity * m_speed) * deltaTime;

	m_position = m_position + velocity;
}

void Bullet::draw(Renderer2D& render)
{
	// Test
	render.drawBox(m_position.x, m_position.y, 10, 10);

	// Texture
	// render.drawSprite(m_texture, m_position.x, m_position.y);
}

Vector2 Bullet::GetPosition()
{
	return m_position;
}

const Vector2 Bullet::GetDirection()
{
	// 1 = up | -1 = down
	switch (m_direction)
	{
	case Direction::UP: return Vector2(0, 1);
	case Direction::DOWN: return Vector2(0, -1);
	}
}
