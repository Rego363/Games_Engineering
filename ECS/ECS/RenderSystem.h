#pragma once

#include <iostream>
#include "Entity.h"
#include <vector>
#include <iterator>
#include <SDL.h>

class RenderSystem
{
	std::vector<Entity> entities;
	SDL_Surface* screenSurface = NULL;
	int m_colour = 0;

public:
	void addEntity(Entity e) { 
		entities.push_back(e); 
		m_colour = entities.size();
	};
	void update(SDL_Window* window)
	{
		//std::cout << "Render System Update" << std::endl;
		// Loop through Entities with
		// RenderComponents and update

		screenSurface = SDL_GetWindowSurface(window);

		//Fill the surface white
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));


		std::vector<Entity>::iterator iter = entities.begin();
		for (; iter != entities.end(); iter++)
		{
			int pos = std::distance(entities.begin(), iter);
			std::vector<std::shared_ptr<Component>> comps = (*iter).getComponents();
			//std::vector<Component>::iterator compIter = (*iter).getComponents().begin(); //comps.begin();
			//for (; compIter != (*iter).getComponents().end(); compIter++)
			for (std::shared_ptr<Component> compIter : (*iter).getComponents())
			{
				
				if ((*compIter).id == 3)
				{
					auto p = dynamic_cast<PositionComponent *>(&(*compIter));
					//Update the surface

					SDL_Rect rect = {p->getX(), p->getY(), 100, 100 };

					SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF));
					
					switch (std::distance(entities.begin(), iter))
					{
					case 0:
						SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
						break;
					case 1:
						SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0x00));
						break;
					case 2:
						SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF));
						break;
					case 3:
						SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));
						break;
					case 4:
						SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
						break;
					case 5:
						SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0xFF));
						break;
					case 6:
						SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
						break;
					}

				}
			}
		}

		// TBI
	}
};