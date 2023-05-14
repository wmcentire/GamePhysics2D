#include "World.h"
#include "Body.h"
#include "ForceGenerator.h"
#include <iostream>

glm::vec2 World::gravity{ 0, 9.8 };

World::~World()
{
	// <delete all the objects>
	// <clear the objects form the list clear()>
	for (auto& i : m_bodies)
	{
		delete i;
	}
	m_bodies.clear();
}
void World::Step(float dt)
{
	if (!m_bodies.empty() && !m_forceGenerators.empty()) {
		std::vector<Body*> bodies(m_bodies.begin(), m_bodies.end()); // < use 2. Using Range Constructor https://www.techiedelight.com/convert-list-to-vector-cpp/>
		for (auto forceGenerator : m_forceGenerators)
		{
			forceGenerator->Apply(bodies);
		}
	}
	
	// <call Step() on all the objects>
	for (auto& i : m_bodies)
	{
		i->Step(dt);
	}
}
void World::Draw(Graphics* graphics)
{
	// <call Draw() on all the objects>
	for (auto& body : m_bodies)
	{
		body->Draw(graphics);
	}
}
void World::AddBody(Body* po)
{
	// <push back the po onto objects list>
	m_bodies.push_back(po);
}
void World::RemoveBody(Body* po)
{
	// <remove po from the objects list>
	m_bodies.remove(po);
}

void World::AddForceGenerator(ForceGenerator* fg)
{
	m_forceGenerators.push_back(fg);
}
