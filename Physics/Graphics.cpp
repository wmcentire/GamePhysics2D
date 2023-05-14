#include "Graphics.h"
#include "Primitives.h"
#include <SDL.h>

Graphics::Graphics()
{
	SDL_Init(SDL_INIT_VIDEO);

}

Graphics::~Graphics()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

/// <summary>
/// takes in screen name, width, and height
/// </summary>
/// <param name="title"></param>
/// <param name="w"></param>
/// <param name="h"></param>
void Graphics::CreateWindow(const char* title, int w, int h)
{
	m_window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		w,
		h,
		SDL_WINDOW_SHOWN
	);

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

/// <summary>
/// sets the color to black
/// </summary>
void Graphics::Clear() {
	SDL_RenderClear(m_renderer);
}

/// <summary>
/// uh presents the screen
/// </summary>
void Graphics::Present() {
	SDL_RenderPresent(m_renderer);
}
/// <summary>
/// takes in a normalized vector4 and converts them into 0-255, then applies them.
/// </summary>
/// <param name="color"></param>
void Graphics::SetColor(const glm::vec4& color)
{
	glm::ivec4 iColor = ConvertColor(color);
	SDL_SetRenderDrawColor(m_renderer, iColor.r, iColor.g, iColor.b, iColor.a);


}

void Graphics::DrawPoint(const glm::ivec2& point, const glm::vec4& color) {
	SetColor(color);
	SDL_RenderDrawPoint(m_renderer, point.x, point.y);
}

void Graphics::DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color) {
	SetColor(color);
	SDL_RenderDrawLine(m_renderer,start.x,start.y,end.x,end.y);
}

void Graphics::DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
	glm::ivec4 icolor = ConvertColor(color);
	circleRGBA(m_renderer,point.x,point.y,radius,icolor.r,icolor.g,icolor.b,icolor.a);
}

void Graphics::DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
	glm::ivec4 icolor = ConvertColor(color);
	filledCircleRGBA(m_renderer, point.x, point.y, radius, icolor.r, icolor.g, icolor.b, icolor.a);
}

glm::vec4 Graphics::ConvertColor(const glm::vec4& color) {
	glm::ivec4 iColor;
	iColor.r = (int)(color.r * 255);
	iColor.g = (int)(color.g * 255);
	iColor.b = (int)(color.b * 255);
	iColor.a = (int)(color.a * 255);
	return iColor;
}
