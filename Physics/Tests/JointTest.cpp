#include "JointTest.h"
#include "../Physics/Objects/CircleShape.h"
#include "../Engine/World.h"
#include "../Physics/Objects/Body.h"
#include "../Physics/Objects/Joint.h"

#define SPRING_STIFFNESS 50
#define SPRING_LENGTH 2
#define BODY_DAMPING 10
#define CHAIN_SIZE 4

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(0.5, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);

	auto prevBody1 = m_anchor;
	auto prevBody2 = m_anchor;

	// chain
	for (int i = 0; i < CHAIN_SIZE; i++) {
		auto body1 = new Body(new CircleShape(0.5, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
		//auto body2 = new Body(new CircleShape(0.5, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);

		body1->damping = BODY_DAMPING;
		m_world->AddBody(body1);
		//body2->damping = BODY_DAMPING;
		//m_world->AddBody(body2);

		auto joint = new Joint(body1, prevBody1, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		//auto joint = new Joint(body2, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		//auto joint1 = new Joint(prevBody1, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		//auto joint2 = new Joint(prevBody2, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		//auto joint3 = new Joint(prevBody2, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		//auto joint4 = new Joint(prevBody1, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		//m_world->AddJoint(joint);
		//m_world->AddJoint(joint1);
		//m_world->AddJoint(joint2);
		//m_world->AddJoint(joint3);
		//m_world->AddJoint(joint4);

		prevBody1 = body1;
		//prevBody2 = body2;
	}
	
}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_graphics->ScreenToWorld( m_input->GetMousePosition());
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