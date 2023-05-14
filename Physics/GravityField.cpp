#include "GravityField.h"
#include "Body.h"

void GravityField::Apply(std::vector<class Body*> bodies)
{
	for (size_t i = 0; i < bodies.size() - 1; i++)
	{
		for (size_t j = i + 1; j < bodies.size(); j++)
		{
			Body* bodyA = bodies[i];
			Body* bodyB = bodies[j];
			// apply gravitational force
			glm::vec2 direction = bodyA->position - bodyB->position; // <body a position – body b position>
			float distance = glm::length(direction);
			if (distance == 0) continue;
			distance = glm::max(1.0f, distance);

			float force = m_strength * ((bodyA->mass * bodyB->mass) / distance);

			glm::vec2 ndirection = glm::normalize(direction);
			bodyA->ApplyForce(ndirection * force); // <multiply the normalized direction by force>
			bodyB->ApplyForce(ndirection * force); //<multiply the normalized direction by force>
		}
	}
}


