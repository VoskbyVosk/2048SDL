#pragma once
#include "gameObject.h"

class Cell : public GameObject
{
public :
	int value;
	
	Cell();
	Cell(int x, int y, int w, int h);

	int getValue();

	void setValue(int new_value);

	bool isEmpty();
};

