#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "grid.h"
#include "cell.h"
#include "gameObject.h"

const int texture_count = 17;

class Window
{

public :

	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Texture* tabBmpImg[texture_count];
	int isRunning;

	Window();

	int gameLoop();

	void loadBmpImg();
	void showTable(Cell grid[size_gridC][size_gridC], int lost);
	void display();

};