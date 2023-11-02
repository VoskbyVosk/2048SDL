#include "cell.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"

Cell::Cell(int x, int y, int w, int h) : GameObject(x, y, w, h)
{
	value = 0;
}

Cell::Cell() : GameObject(0, 0, 0, 0)
{
	value = 0;
}

int Cell::getValue() {
	return value;
}

void Cell::setValue(int new_value) {
	value = new_value;
}

bool Cell::isEmpty() {
	if (value == 0) {
		return true;
	} else {
		return false;
	}
}