#include "JointTest.h"
#include "CircleShape.h"
#include "World.h"
#include "Body.h"
#include "Joint.h"

#define SPRING_STIFFNESS 200
#define SPRING_LENGTH 100
#define BODY_DAMPING 40
#define CHAIN_SIZE 4

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 100 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);

	auto prevBody1 = m_anchor;
	auto prevBody2 = m_anchor;

	// chain
	for (int i = 0; i < CHAIN_SIZE; i++) {
		auto body1 = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 300, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		auto body2 = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 500, 200 }, { 0, 0 }, 1, Body::DYNAMIC);

		body1->gravityScale = 250;
		body1->damping = BODY_DAMPING;
		m_world->AddBody(body1);
		body2->gravityScale = 250;
		body2->damping = BODY_DAMPING;
		m_world->AddBody(body2);

		auto joint = new Joint(body2, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		auto joint1 = new Joint(prevBody1, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		auto joint2 = new Joint(prevBody2, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		auto joint3 = new Joint(prevBody2, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		auto joint4 = new Joint(prevBody1, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);
		m_world->AddJoint(joint1);
		m_world->AddJoint(joint2);
		m_world->AddJoint(joint3);
		m_world->AddJoint(joint4);

		prevBody1 = body1;
		prevBody2 = body2;
	}
	
}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_input->GetMousePosition();
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}