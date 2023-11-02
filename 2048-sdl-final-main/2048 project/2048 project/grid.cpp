#include "grid.h"
#include <iostream>
#include "time.h"
#include <list>
using namespace std;

Grid::Grid() {

    starting = 2;
    int count = 0;
    int count_x = 100;
    int count_y = 100;
    srand(time(NULL));

    for (int j = 0; j < size_gridC; ++j)
    {
        for (int i = 0; i < size_gridC; ++i)
        {
            grid[j][i] = Cell(count_x, count_y, 150, 150);
            
            count_x += 150;
        }
        count_x = 100;
        count_y += 150;
    }

    int test_starting_tiles;
    int x, y;

    for (int i = 0; i < starting; ++i) {

        test_starting_tiles = 0;

        while (test_starting_tiles == 0) {
            x = randomNumberC(size_gridC);
            y = randomNumberC(size_gridC);
            if (grid[x][y].isEmpty() == true) {
                test_starting_tiles = 1;
            }
        }
        grid[x][y].setValue(2);
    }
}


int Grid::randomNumberC(int number){
    int randomnumber;
    randomnumber = rand() % number;
    return(randomnumber);
}

void Grid::clearTableC(int starting) {
    for (int j = 0; j < size_gridC; ++j)
    {
        for (int i = 0; i < size_gridC; ++i)
        {
            grid[j][i].setValue(0);
        }
    }

    int test_starting_tiles;
    int x, y;

    for (int i = 0; i < starting; ++i) {

        test_starting_tiles = 0;

        while (test_starting_tiles == 0) {
            x = randomNumberC(size_gridC);
            y = randomNumberC(size_gridC);
            if (grid[x][y].isEmpty() == true) {
                test_starting_tiles = 1;
            }
        }
        grid[x][y].setValue(2);
    }
}


bool Grid::testInGridC(int i, int j) {
    if (i > 3 || i < 0 || j>3 || j < 0) {
        return false;
    }
    else {
        return true;
    }
}

int Grid::moveUpC() {
    list<int> list_col{};
    int test = 0;
    int count;
    for (int i = 0; i < 4; ++i) {
        count = 0;
        for (int j = 0; j < 4; ++j) {
            if (grid[j][i].isEmpty() == false) {
                list_col.push_back(grid[j][i].getValue());
                if (count > 0) {
                    test = 1;
                }
            } else {
                count += 1;
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 0; l < size_gridC; l++) {
            grid[l][i].setValue(list_col.front());
            list_col.pop_front();
            if (testInGridC(i, l - 1) == true && grid[l - 1][i].getValue() == grid[l][i].getValue() && grid[l - 1][i].isEmpty() == false && grid[l][i].isEmpty() == false) {
                grid[l - 1][i].setValue(grid[l][i].getValue() * 2);
                grid[l][i].setValue(0);
                test = 1;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[j][i].isEmpty() == true && grid[j + 1][i].isEmpty() == false) {
                grid[j][i].setValue(grid[j + 1][i].getValue());
                grid[j + 1][i].setValue(0);
                test = 1;
            }
        }
    }
    return test;
}

int Grid::moveDownC() {
    list<int> list_col{};
    int test = 0;
    int count;
    for (int i = 0; i < 4; ++i) {
        count = 0;
        for (int j = 3; j > -1; --j) {
            if (grid[j][i].isEmpty() == false) {
                list_col.push_back(grid[j][i].getValue());
                if (count > 0) {
                    test = 1;
                }
            } else {
                count += 1;
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 3; l > -1; l--) {
            grid[l][i].setValue(list_col.front());
            list_col.pop_front();
            if (testInGridC( i, l + 1) == true && grid[l + 1][i].getValue() == grid[l][i].getValue() && grid[l + 1][i].isEmpty() == false && grid[l][i].isEmpty() == false) {
                grid[l + 1][i].setValue(grid[l][i].getValue() * 2);
                grid[l][i].setValue(0);
                test = 1;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j > 0; --j) {
            if (grid[j][i].isEmpty() == true && grid[j - 1][i].isEmpty() == false) {
                grid[j][i].setValue(grid[j - 1][i].getValue());
                grid[j - 1][i].setValue(0);
                test = 1;
            }
        }
    }
    return test;
}

int Grid::moveLeftC() {
    list<int> list_col{};
    int test = 0;
    int count;
    for (int i = 0; i < 4; ++i) {
        count = 0;
        for (int j = 0; j < 4; ++j) {
            if ((grid[i][j].isEmpty() == false)) {
                list_col.push_back(grid[i][j].getValue());
                if (count > 0) {
                    test = 1;
                }
            } else {
                count += 1;
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 0; l < size_gridC; l++) {
            grid[i][l].setValue(list_col.front());
            list_col.pop_front();
            if (testInGridC( i, l - 1) == true && grid[i][l - 1].getValue() == grid[i][l].getValue() && grid[i][l - 1].isEmpty() == false && grid[i][l].isEmpty() == false) {
                grid[i][l - 1].setValue(grid[i][l].getValue() * 2);
                grid[i][l].setValue(0);
                test = 1;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((grid[i][j].isEmpty() == true && grid[i][j + 1].isEmpty() == false)) {
                grid[i][j].setValue(grid[i][j + 1].getValue());
                grid[i][j + 1].setValue(0);
                test = 1;
            }
        }
    }
    return test;
}

int Grid::moveRightC() {
    list<int> list_col{};
    int test = 0;
    int count;
    for (int i = 0; i < 4; ++i) {
        count = 0;
        for (int j = 3; j > -1; --j) {
            if ((grid[i][j].isEmpty() == false)) {
                list_col.push_back(grid[i][j].getValue());
                if (count > 0) {
                    test = 1;
                }
            } else {
                count += 1;
            }
        }
        while (list_col.size() < size_gridC) {
            list_col.push_back(0);
        }
        for (int l = 3; l > -1; l--) {
            grid[i][l].setValue(list_col.front());
            list_col.pop_front();
            if (testInGridC( i, l + 1) == true && grid[i][l + 1].getValue() == grid[i][l].getValue() && grid[i][l + 1].isEmpty() == false && grid[i][l].isEmpty() == false) {
                grid[i][l + 1].setValue(grid[i][l].getValue() * 2);
                grid[i][l].setValue(0);
                test = 1;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j > 0; --j) {
            if ((grid[i][j].isEmpty() == true && grid[i][j - 1].isEmpty() == false)) {
                grid[i][j].setValue(grid[i][j - 1].getValue());
                grid[i][j - 1].setValue(0);
                test = 1;
            }
        }
    }
    return test;
}

int Grid::newTilesC() {
    int count = 0;
    int count_random = 0;
    int random_coord;
    for (int i = 0; i < size_gridC; ++i) {
        for (int j = 0; j < size_gridC; ++j)
        {
            if (grid[i][j].isEmpty() == true) {
                count += 1;
            }
        }
    }
    if (count == 0) {
        return 0;
    }

    if (count == 1) {
        random_coord = 0;
    } else {
        random_coord = randomNumberC(count);
    }
    for (int i = 0; i < size_gridC; ++i) {
        for (int j = 0; j < size_gridC; ++j) {
            if (grid[i][j].isEmpty() == true) {
                if (count_random == random_coord) {
                    if (randomNumberC(3) == 0) {
                        grid[i][j].setValue(4);
                    } else {
                        grid[i][j].setValue(2);
                    }
                }
                count_random += 1;
            }
        }
    }
    return 1;
}


bool Grid::testWin() {
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i)
        {
            if (grid[i][j].getValue() == 2048) {
                return true;

            }
        }
    }
    return false;
}

bool Grid::testLooseC() {
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i)
            {
                if (grid[i][j].isEmpty() == true) {
                    return false;
                }
                if (grid[i][j - 1].getValue() == grid[i][j].getValue() && testInGridC(i, j - 1) == true || grid[i - 1][j].getValue() == grid[i][j].getValue() && testInGridC(i - 1, j) == true || grid[i + 1][j].getValue() == grid[i][j].getValue() && testInGridC(i + 1, j) == true || grid[i][j + 1].getValue() == grid[i][j].getValue() && testInGridC(i, j + 1) == true) {
                    return false;
                }            
            }
        }
        return true;
 }

