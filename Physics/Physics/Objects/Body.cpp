#include "Body.h"
#include "../../Engine/Integrator.h"
#include "Shape.h"
#include "CircleShape.h"
#include "../../Engine/World.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	if (type != DYNAMIC) return;

	// gravy
	//ApplyForce(World::gravity * gravityScale * mass);

	Integrator::ExplicitEuler(*this, dt);
	ClearForce();
	// damping
	velocity *= (1.0f / (1.0f + dt * damping));
}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = this->position - body->position;// <get direction vector of the two bodies>
	float distance = glm::length(direction);// <get length of direction vector>
	
	float radius = static_cast<CircleShape*>(this->shape)->radius + static_cast<CircleShape*>(body->shape)->radius;// <get the radius of this shape and the other shape and add them>
	return distance <= radius;
}
