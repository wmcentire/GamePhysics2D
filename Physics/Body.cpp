#include "Body.h"
#include "Integrator.h"
#include "Shape.h"
#include "World.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	if (type != DYNAMIC) return;

	// gravy
	ApplyForce(World::gravity * gravityScale * mass);

	//cock and balls
	Integrator::ExplicitEuler(*this, dt);
	ClearForce();
	// damping
	velocity *= (1.0f / (1.0f + (damping * dt)));
}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}
