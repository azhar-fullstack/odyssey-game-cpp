#pragma once
#include <vector>
#include <iostream>

class Map {
public:
    Map(int size);
    void displayMap() const;
    void movePlayer(int& playerX, int& playerY, int deltaX, int deltaY);

private:
    std::vector<std::vector<char>> tiles;
};

