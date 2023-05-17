#pragma once
#include "glm/glm.hpp"
#include <list>
#include <vector>
class World
{
public:
	~World();

	void Step(float dt);
	void Draw(class Graphics* graphics);

	void AddBody(class Body* body);
	void RemoveBody(class Body* body);

	void AddJoint(class Joint* joint);
	void RemoveJoint(class Joint* joint);

	void AddForceGenerator(class ForceGenerator* fg);

public:
	static glm::vec2 gravity;

private:
	std::list<class Body*> m_bodies;
	std::vector<class ForceGenerator*> m_forceGenerators;
	std::list<class Joint*> m_joints;
};