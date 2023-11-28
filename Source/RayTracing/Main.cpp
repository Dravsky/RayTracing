#include "Renderer.h"
#include "MathUtils.h"
#include "Random.h"
#include "Color.h"
#include "Canvas.h"

int main(int argc, char** argv)
{
	std::cout << "Hello world!\n";
	seedRandom((unsigned int)time(nullptr));
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray Tracer", 400, 300);

	Canvas canvas(400, 300, renderer);

	bool quit = false;
	while (!quit)
	{
		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++) canvas.DrawPoint({ random(0, 400), random(0, 300)}, { random01(), random01(), random01(), 1});
		canvas.Update();

		renderer.PresentCanvas(canvas);
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
	}

	renderer.Shutdown();

	return 0;
}