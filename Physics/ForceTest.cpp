#include "ForceTest.h"
#include "Body.h"
#include "CircleShape.h"
#include "GravityField.h"
#include <iostream>

void ForceTest::Initialize()
{
	Test::Initialize();
	auto forceGen = new GravityField(200);
	m_world->AddForceGenerator(forceGen);
	//World::gravity = { 4, 9.8f };
}

void ForceTest::Update()
{
	Test::Update();
	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity{ 0, 0 }; //  = randomUnitCircle() * randomf(100, 200);

		float size = randomf(1, 8);
		auto body = new Body(new CircleShape(size * 2, {randomf(), randomf(), randomf(), 1}), m_input->GetMousePosition(), velocity, size);
		body->damping = 1;
		body->gravityScale = 10;
		m_world->AddBody(body);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(),randomf(),randomf(),1 });
}
