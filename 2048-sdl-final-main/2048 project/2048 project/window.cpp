#include "window.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
using namespace std;

Window::Window() {
        
        int flags = 0;
        flags = SDL_WINDOW_RESIZABLE;

        if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

            window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, flags);
            if (window) {
                SDL_SetWindowMinimumSize(window, 800, 800);
                SDL_SetWindowMaximumSize(window, 800, 800);
            }
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {
                SDL_RenderPresent(renderer);
                isRunning = 1;
            }

        }
}

void Window::loadBmpImg() {

    SDL_Surface* S0 = SDL_LoadBMP("img/board.bmp");
    SDL_Texture* Bmp0 = SDL_CreateTextureFromSurface(renderer, S0);
    tabBmpImg[0] = Bmp0;
    SDL_FreeSurface(S0);

    SDL_Surface* S1 = SDL_LoadBMP("img/tile_2.bmp");
    SDL_Texture* Bmp1 = SDL_CreateTextureFromSurface(renderer, S1);
    tabBmpImg[1] = Bmp1;
    SDL_FreeSurface(S1);

    SDL_Surface* S2 = SDL_LoadBMP("img/tile_4.bmp");
    SDL_Texture* Bmp2 = SDL_CreateTextureFromSurface(renderer, S2);
    tabBmpImg[2] = Bmp2;
    SDL_FreeSurface(S2);

    SDL_Surface* S3 = SDL_LoadBMP("img/tile_8.bmp");
    SDL_Texture* Bmp3 = SDL_CreateTextureFromSurface(renderer, S3);
    tabBmpImg[3] = Bmp3;
    SDL_FreeSurface(S3);

    SDL_Surface* S4 = SDL_LoadBMP("img/tile_16.bmp");
    SDL_Texture* Bmp4 = SDL_CreateTextureFromSurface(renderer, S4);
    tabBmpImg[4] = Bmp4;
    SDL_FreeSurface(S4);

    SDL_Surface* S5 = SDL_LoadBMP("img/tile_32.bmp");
    SDL_Texture* Bmp5 = SDL_CreateTextureFromSurface(renderer, S5);
    tabBmpImg[5] = Bmp5;
    SDL_FreeSurface(S5);

    SDL_Surface* S6 = SDL_LoadBMP("img/tile_64.bmp");
    SDL_Texture* Bmp6 = SDL_CreateTextureFromSurface(renderer, S6);
    tabBmpImg[6] = Bmp6;
    SDL_FreeSurface(S6);

    SDL_Surface* S7 = SDL_LoadBMP("img/tile_128.bmp");
    SDL_Texture* Bmp7 = SDL_CreateTextureFromSurface(renderer, S7);
    tabBmpImg[7] = Bmp7;
    SDL_FreeSurface(S7);

    SDL_Surface* S8 = SDL_LoadBMP("img/tile_256.bmp");
    SDL_Texture* Bmp8 = SDL_CreateTextureFromSurface(renderer, S8);
    tabBmpImg[8] = Bmp8;
    SDL_FreeSurface(S8);

    SDL_Surface* S9 = SDL_LoadBMP("img/tile_512.bmp");
    SDL_Texture* Bmp9 = SDL_CreateTextureFromSurface(renderer, S9);
    tabBmpImg[9] = Bmp9;
    SDL_FreeSurface(S9);

    SDL_Surface* S10 = SDL_LoadBMP("img/tile_1024.bmp");
    SDL_Texture* Bmp10 = SDL_CreateTextureFromSurface(renderer, S10);
    tabBmpImg[10] = Bmp10;
    SDL_FreeSurface(S10);

    SDL_Surface* S11 = SDL_LoadBMP("img/tile_2048.bmp");
    SDL_Texture* Bmp11 = SDL_CreateTextureFromSurface(renderer, S11);
    tabBmpImg[11] = Bmp11;
    SDL_FreeSurface(S11);

    SDL_Surface* S12 = SDL_LoadBMP("img/tile_4096.bmp");
    SDL_Texture* Bmp12 = SDL_CreateTextureFromSurface(renderer, S12);
    tabBmpImg[12] = Bmp12;
    SDL_FreeSurface(S12);

    SDL_Surface* S13 = SDL_LoadBMP("img/tile_0.bmp");
    SDL_Texture* Bmp13 = SDL_CreateTextureFromSurface(renderer, S13);
    tabBmpImg[13] = Bmp13;
    SDL_FreeSurface(S13);


    SDL_Surface* S14 = SDL_LoadBMP("img/space.bmp");
    SDL_Texture* Bmp14 = SDL_CreateTextureFromSurface(renderer, S14);
    tabBmpImg[14] = Bmp14;
    SDL_FreeSurface(S14);

    SDL_Surface* S15 = SDL_LoadBMP("img/lost.bmp");
    SDL_Texture* Bmp15 = SDL_CreateTextureFromSurface(renderer, S15);
    tabBmpImg[15] = Bmp15;
    SDL_FreeSurface(S15);

    SDL_Surface* S16 = SDL_LoadBMP("img/win.bmp");
    SDL_Texture* Bmp16 = SDL_CreateTextureFromSurface(renderer, S16);
    tabBmpImg[16] = Bmp16;
    SDL_FreeSurface(S16);
}

void Window::display() {
    SDL_RenderPresent(renderer);
}

void Window::showTable(Cell grid[size_gridC][size_gridC], int lost) {

    // board on screen

    SDL_Rect rect_board;
    SDL_Texture* board = NULL;

    rect_board.x = 0;
    rect_board.y = 0;
    rect_board.w = 800;
    rect_board.h = 800;

    board = tabBmpImg[0];
    SDL_RenderCopy(renderer, board, NULL, &rect_board);

    if (lost == 1) {

        rect_board.x = 0;
        rect_board.y = 0;
        rect_board.w = 800;
        rect_board.h = 100;

        board = tabBmpImg[15];
        SDL_RenderCopy(renderer, board, NULL, &rect_board);

    }
    else if (lost == 2) {

        rect_board.x = 0;
        rect_board.y = 0;
        rect_board.w = 800;
        rect_board.h = 100;

        board = tabBmpImg[16];
        SDL_RenderCopy(renderer, board, NULL, &rect_board);
    }

    rect_board.x = 0;
    rect_board.y = 700;
    rect_board.w = 800;
    rect_board.h = 100;

    board = tabBmpImg[14];
    SDL_RenderCopy(renderer, board, NULL, &rect_board);

    // end of board 

    SDL_Texture* Number = NULL;

    SDL_Rect rect_number;
    rect_number.w = 150;
    rect_number.h = 150;
    rect_number.x = 100;
    rect_number.y = 100;

    for (int i = 0; i < size_gridC; ++i)
    {
        for (int j = 0; j < size_gridC; ++j)
        {

            switch (grid[j][i].getValue()) {
            case 0:
                Number = tabBmpImg[13];
                break;

            case 2:
                Number = tabBmpImg[1];
                break;

            case 4:
                Number = tabBmpImg[2];
                break;

            case 8:
                Number = tabBmpImg[3];
                break;

            case 16:
                Number = tabBmpImg[4];
                break;

            case 32:
                Number = tabBmpImg[5];
                break;

            case 64:
                Number = tabBmpImg[6];
                break;

            case 128:
                Number = tabBmpImg[7];
                break;

            case 256:
                Number = tabBmpImg[8];
                break;

            case 512:
                Number = tabBmpImg[9];
                break;

            case 1024:
                Number = tabBmpImg[10];
                break;

            case 2048:
                Number = tabBmpImg[11];
                break;

            case 4096:
                Number = tabBmpImg[12];
                break;
            }

            grid[j][i].Draw(renderer, Number);
            rect_number.y = rect_number.y + 150;
        }
        rect_number.y = 100;
        rect_number.x = rect_number.x + 150;
    }
    display();
}

int Window::gameLoop(){
    srand(time(NULL));

    Grid grid;

    loadBmpImg();

    int valid_play;
    int end_of_game = 0;
    int lost = 0;

    while (isRunning == 1) {

        while (end_of_game == 0) {

            SDL_Event event;

            while (SDL_PollEvent(&event))
            {

                valid_play = 0;

                showTable(grid.grid, lost);

                if (grid.testLooseC() == true) {
                    lost = 1;
                }
                if (grid.testWin() == true) {
                    lost = 2;
                }

                switch (event.type)
                {
                case SDL_KEYDOWN:


                    if (event.key.keysym.sym == SDLK_SPACE) {
                        grid.clearTableC(grid.starting);
                        lost = 0;
                    }

                    if (event.key.keysym.sym == SDLK_UP && lost == 0) {
                        if (grid.moveUpC() == 1) {
                            valid_play = 1;
                        }
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_DOWN && lost == 0) {
                        if (grid.moveDownC() == 1) {
                            valid_play = 1;
                        }
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT && lost == 0) {
                        if (grid.moveRightC() == 1) {
                            valid_play = 1;
                        }
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_LEFT && lost == 0) {
                        if (grid.moveLeftC() == 1) {
                            valid_play = 1;
                        }
                        break;
                    }

                case SDL_QUIT:
                    end_of_game = 0;
                    isRunning = 0;
                    break;

                default:
                    break;
                }

                if (valid_play == 1) {
                    grid.newTilesC();
                }
            }
        }
        return 0;
    }
}


