#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<ctime>
#include<iostream>
//suply with a SDL window
class SDLManager
{
public:
	SDLManager();
	~SDLManager();
private:
	SDL_Window*window;
	SDL_Renderer*renderer;
	int width;
	int height;
};

