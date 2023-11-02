#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "window.h"
#include <SDL.h>
#undef main

int main() {
    Window window;
    window.gameLoop();
}
