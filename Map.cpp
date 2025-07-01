#include "Map.h"

Map::Map(int size) : tiles(size, std::vector<char>(size, 'N')) {
    tiles[3][3] = 'S';  // Special tile
    tiles[1][1] = 'I';  // Island tile
}

void Map::displayMap() const {
    for (const auto& row : tiles) {
        for (char tile : row) {
            std::cout << tile << " ";
        }
        std::cout << std::endl;
    }
}

void Map::movePlayer(int& playerX, int& playerY, int deltaX, int deltaY) {
    int newX = std::max(0, std::min(playerX + deltaX, static_cast<int>(tiles.size()) - 1));
    int newY = std::max(0, std::min(playerY + deltaY, static_cast<int>(tiles[0].size()) - 1));
    playerX = newX;
    playerY = newY;
    std::cout << "Player moved to (" << newX << ", " << newY << ")\n";
    char tileType = tiles[newX][newY];
    switch(tileType) {
        case 'I':
            std::cout << "Landed on an Island tile!" << std::endl;
            // Trigger island event
            break;
        case 'S':
            std::cout << "Landed on a Special tile!" << std::endl;
            // Trigger special event
            break;
        default:
            std::cout << "Moved to a Normal tile." << std::endl;
    }
}
