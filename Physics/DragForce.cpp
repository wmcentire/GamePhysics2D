#include "DragForce.h"
#include "Body.h"
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>

void DragForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		// <check if body is intersecting, continue if not>
		if (!body->Intersects(this->m_body)) continue;
		if (body->velocity == glm::vec2{ 0,0 }) continue;

		float f = m_drag * 0.5f * glm::length2(body->velocity); // <compute the drag force using 0.5f * length sqr * m_drag>
		glm::vec2 force = glm::normalize(body->velocity);
		body->ApplyForce(force * -f); // <scale the force with - f>
	}
}
