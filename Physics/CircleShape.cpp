#include "CircleShape.h"
#include "Graphics.h"

void CircleShape::Draw(Graphics* graphics, const glm::vec2& position)
{
	graphics->DrawFilledCircle(position, radius, color);
}
