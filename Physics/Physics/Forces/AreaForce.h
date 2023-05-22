#pragma once
#include "ForceGenerator.h"
class AreaForce : public ForceGenerator
{
public:
	AreaForce(class Body* body, float magnitude, float angle) : // <take in the pointer to a body, force magnitude and angle>
		ForceGenerator(body),
		m_forceMagnitude{magnitude},
		m_angle{angle}
	{}
	void Apply(std::vector<class Body*> bodies) override;
private:
	float m_forceMagnitude{ 1 };
	float m_angle{ 0 };
};