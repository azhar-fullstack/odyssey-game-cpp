#pragma once
#include <vector>
#include "Entity.h"

class Game {
public:
    Game();
    void loadGameData();
    void playGame();

private:
    std::vector<Entity> players;
    std::vector<Entity> enemies;
};
