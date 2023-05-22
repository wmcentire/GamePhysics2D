#include "World.h"
#include "../Physics/Objects/Body.h"
#include "../Physics/Forces/ForceGenerator.h"
#include "../Physics/Objects/Joint.h"
#include <iostream>

glm::vec2 World::gravity{ 0, -9.8f };

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
		std::vector<Body*> bodies(m_bodies.begin(), m_bodies.end()); 
		for (auto forceGenerator : m_forceGenerators)
		{
			forceGenerator->Apply(bodies);
		}
	}
	// apply joint force
	for (auto joint : m_joints) joint->Step(dt);
	// integrate
	for (auto& i : m_bodies)
	{
		i->Step(dt);
	}
}
void World::Draw(Graphics* graphics)
{
	for (auto joint : m_joints) joint->Draw(graphics);
	for (auto forcegenerator : m_forceGenerators) forcegenerator->Draw(graphics);
	for (auto body : m_bodies)
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

void World::AddJoint(Joint* joint)
{
	m_joints.push_back(joint);
}

void World::RemoveJoint(Joint* joint)
{
	m_joints.remove(joint);
}

void World::AddForceGenerator(ForceGenerator* fg)
{
	m_forceGenerators.push_back(fg);
}
