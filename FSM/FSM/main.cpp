#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include <Animation/AnimatedSprite.h>
#include <GameObject/Player.h>
#include <Input/Input.h>
#include <FSM/State.h>
#include <Debug/Debug.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const int SPRITE_SIZE = 510;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

SDL_Rect srcRect;
SDL_Rect destRect;

State current;

bool init()
{
	//Initialization flag
	bool success = true;


	srcRect.x = 5;
	srcRect.y = 550;
	srcRect.w = 160;
	srcRect.h = 240;

	destRect.x = 100;	// dest
	destRect.y = 100;	// dest
	destRect.w = 1211;	// dest
	destRect.h = 797;	// dest


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface("spritesheet.png");
	if (gPNGSurface == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

int main(int argc, char* args[])
{

	Input * inputHandler = new Input();

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			int counter = 0;
			int repeater = 0;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				inputHandler->handleInput(e);

				if (inputHandler->getCurrent() == inputHandler->IDLE)
				{
					srcRect.y = 550;
				}
				if (inputHandler->getCurrent() == inputHandler->JUMP)
				{
					srcRect.y = 20;
				}
				if (inputHandler->getCurrent() == inputHandler->CLIMB)
				{
					srcRect.y = 275;
				}

				if (counter > 200)
				{

					srcRect.x = srcRect.x + 205;
					counter = 0;
				}
				else
				{
					counter++;
				}
				

				if (srcRect.x > 797)
				{
					srcRect.x = 5;
					if (inputHandler->getCurrent() == inputHandler->CLIMB || inputHandler->getCurrent() == inputHandler->JUMP && repeater > 10)
					{
						inputHandler->setCurrent(inputHandler->IDLE);
						repeater = 0;
					}
					repeater++;
				}

				//Apply the PNG image
				SDL_BlitSurface(gPNGSurface, &srcRect, gScreenSurface, &destRect);
				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}