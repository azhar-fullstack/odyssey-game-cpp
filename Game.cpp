#include "Game.h"
#include <iostream>

Game::Game() {
    loadGameData();
}

void Game::loadGameData() {
    players.emplace_back("Hero", 100, 10, 'H', true, "None", 50, std::vector<std::string>{"Sword", "Shield"});
    enemies.emplace_back("Monster", 120, 15, 'H', false, "Fire", 0, std::vector<std::string>{"Claws"});
}

void Game::playGame() {
    int currentPlayerIndex = 0;
    int currentEnemyIndex = 0;
    Entity& currentPlayer = players[currentPlayerIndex];
    Entity& currentEnemy = enemies[currentEnemyIndex];

    while (currentPlayer.getHp() > 0 && currentEnemy.getHp() > 0) {
        currentPlayer.takeTurn(currentEnemy);
        if (currentEnemy.getHp() > 0) {
            currentEnemy.takeTurn(currentPlayer);
        }
    }

    if (currentPlayer.getHp() > 0) {
        std::cout << currentPlayer.getName() << " wins the game!" << std::endl;
    } else {
        std::cout << currentEnemy.getName() << " wins the game!" << std::endl;
    }
}
