#include "Bullet.h"
#include "SceneHandler.h"

Bullet::Bullet()
{
	m_position = Vector2(0, 0);
	m_direction = Direction::UP;
	m_bulletActive = false;
}

// Vector2: Starting Position | Direction: Enum Bullet Movement Direction
Bullet::Bullet(Vector2 position, Direction direction)
{
	m_direction = direction;
	m_position = position;
	m_bulletActive = false;
	if (direction == Direction::DOWN)
	{
		//SceneHandler::bullets[SceneHandler::activeBullets++] = *this;
	}
}

Bullet::~Bullet()
{
	//delete m_2Drender;
}

void Bullet::Update(const float deltaTime)
{
	Vector2 velocity = BulletDirection();
	velocity = (velocity * BULLET_SPEED) * deltaTime;
	SceneHandler::activeBullets -= 1;
	SceneHandler::hiddenBullets += 1;
	m_position = m_position + velocity;

	if (m_position.y >= 720 || m_position.y <= 0)
	{
		m_bulletActive = false;
	}
}

void Bullet::Draw(aie::Renderer2D& m_2Drender)
{
	m_2Drender.drawBox(m_position.x, m_position.y, BULLET_WIDTH, BULLET_HEIGHT);
}

Vector2 Bullet::GetPosition()
{
	return m_position;
}

Direction Bullet::GetDirection()
{
	return m_direction;
}

void Bullet::ChangePosition(Vector2 a_position)
{
	m_position = a_position;
}

const Vector2 Bullet::BulletDirection()
{
	// 1 = up | -1 = down
	switch (m_direction)
	{
        case Direction::UP: 
			return Vector2(0, 1);

        case Direction::DOWN: 
			return Vector2(0, -1);

        default: 
			return Vector2(0, 0);
	}
}
