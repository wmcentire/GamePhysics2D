#include "AreaForce.h"
#include "../Objects/Body.h"
#include <glm/glm.hpp>
#include "glm/gtx/quaternion.hpp"

void AreaForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		// <check if body is intersecting, continue if not>
		if (!body->Intersects(this->m_body)) continue;
		glm::quat q = glm::angleAxis(glm::radians(m_angle), glm::vec3{ 0, 0, 1 });
		glm::vec2 force = q * glm::vec3{ 1, 0, 0 };
		body->ApplyForce(force * m_forceMagnitude); // <scale the force with the force magnitude>
	}
}
