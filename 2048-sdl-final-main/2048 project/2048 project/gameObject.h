#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

class GameObject
{
public:

	SDL_Rect rect;

	GameObject(int x, int y, int w, int h);

	void Draw(SDL_Renderer* renderer, SDL_Texture* texture);

};
