#include "Entity.h"
#include "HealthComponent.h"
#include "HealthSystem.h"
#include "PositionComponent.h"
#include "PositionSystem.h"
#include "ControlComponent.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AISystem.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;


int main(int argc, char* argv[])
{
	//Start up SDL and create window
	int quit = 0;
	SDL_Event event;

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	Entity player;
	Entity alien;
	Entity dog;
	Entity cat;

	std::shared_ptr<HealthComponent> phc;
	phc = std::make_shared<HealthComponent>();
	std::shared_ptr<ControlComponent> pcc;
	pcc = std::make_shared<ControlComponent>();
	std::shared_ptr<PositionComponent> ppc;
	ppc = std::make_shared<PositionComponent>(5, 5);
	player.addComponent(phc);
	player.addComponent(ppc);
	
	std::shared_ptr<HealthComponent> ahc;
	ahc = std::make_shared<HealthComponent>();
	std::shared_ptr<PositionComponent> apc;
	apc = std::make_shared<PositionComponent>(200, 200);
	player.addComponent(ahc);
	alien.addComponent(apc);

	std::shared_ptr<HealthComponent> dhc;
	dhc = std::make_shared<HealthComponent>();
	std::shared_ptr<PositionComponent> dpc;
	dpc = std::make_shared<PositionComponent>(400, 400);
	dog.addComponent(dhc);
	dog.addComponent(dpc);
	dog.addComponent(pcc);

	std::shared_ptr<HealthComponent> chc;
	chc = std::make_shared<HealthComponent>();
	std::shared_ptr<PositionComponent> cpc;
	cpc = std::make_shared<PositionComponent>(600, 600);
	cat.addComponent(chc);
	cat.addComponent(cpc);

	HealthSystem hs;
	PositionSystem ps;
	ControlSystem cs;
	RenderSystem rs;
	AISystem as;

	ps.addEntity(player);
	as.addEntity(player);
	rs.addEntity(player);
	hs.addEntity(player);

	ps.addEntity(alien);
	as.addEntity(alien);
	rs.addEntity(alien);
	hs.addEntity(alien);

	ps.addEntity(dog);
	cs.addEntity(dog);
	rs.addEntity(dog);
	hs.addEntity(dog);
	
	ps.addEntity(cat);
	as.addEntity(cat);
	rs.addEntity(cat);
	hs.addEntity(cat);

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{	

			//User requests quit
			if (event.type == SDL_QUIT)
			{
				quit = 1;
			}

			cs.update(event);		
		}

		hs.update();
		ps.update();
		as.update();
		rs.update(window);

		SDL_UpdateWindowSurface(window);
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}