#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include"gameObject.h"

GameObject::GameObject(int x, int y, int w, int h){
	this->rect.x = x;
	this->rect.y = y;
	this->rect.h = h;
	this->rect.w = w;
}

void GameObject::Draw(SDL_Renderer* renderer, SDL_Texture* texture) {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}
