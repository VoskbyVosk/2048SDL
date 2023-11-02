#pragma once

#include "cell.h"

const int size_gridC = 4;

class Grid 
{

public:

	int starting;
	
	Cell grid[size_gridC][size_gridC];

	Grid();

	int randomNumberC(int number);
	void clearTableC(int starting);

	int moveUpC();
	int moveDownC();
	int moveLeftC();
	int moveRightC();

	int newTilesC();

	bool testInGridC(int i, int j);
	bool testWin();
	bool testLooseC();
};

