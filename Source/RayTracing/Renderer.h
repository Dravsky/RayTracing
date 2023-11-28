#pragma once
#include <string>
#include <iostream>
#include <SDL.h>

namespace lola 
{
	class Renderer
	{
	public:
		Renderer() = default;

		bool Initialize();
		void Shutdown();
		bool CreateWindow(const std::string& title, int width, int height);

	private:
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;
	};
}