#include "Joint.h"
#include "Body.h"
#include "Graphics.h"

Joint::Joint(Body* bodyA, Body* bodyB, float stiffness, float restLength) : 
	m_bodyA{bodyA},
	m_bodyB{bodyB},
	m_stiffness{stiffness},
	m_restLength{restLength}
{
	if (m_restLength == 0) m_restLength = glm::distance(m_bodyA->position, m_bodyB->position);
}

Joint::~Joint() {
	delete m_bodyA;
	delete m_bodyB;
}

void Joint::Step(float dt)
{
	glm::vec2 direction = m_bodyA->position - m_bodyB->position;
	float length = glm::length(direction);

	float x = length - m_restLength;
	if (x < 0) return;
	float f = -m_stiffness * x;

	glm::vec2 ndirection = glm::normalize(direction);

	m_bodyA->ApplyForce(ndirection * f);
	m_bodyB->ApplyForce(-ndirection * f);
}

void Joint::Draw(Graphics* graphics)
{
	graphics->DrawLine(m_bodyA->position, m_bodyB->position, glm::vec4{ 1 });
}
