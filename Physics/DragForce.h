#pragma once
#include "ForceGenerator.h"

class DragForce : public ForceGenerator
{
public:
	// <constructor>
	DragForce(class Body* body, float drag) : 
		ForceGenerator(body),
	    m_drag{drag}
	{}

	// <Apply() method>
	virtual void Apply(std::vector<class Body*> bodies) override;

private:
	float m_drag{ 0 };
};