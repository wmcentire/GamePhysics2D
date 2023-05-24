#pragma once
#include <glm/glm.hpp>

struct Contact {
	class Body* bodyA{ nullptr };
	class Body* bodyB{ nullptr };

	float depth{ 0 };
	glm::vec2 normal{ 0,0 };
};