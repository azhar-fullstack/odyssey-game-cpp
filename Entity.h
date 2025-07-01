#pragma once
#include <string>
#include <vector>
#include <iostream>

class Entity {
public:
    Entity(std::string name, double hp, double defense, char condition, bool advantage, std::string elementalWeakness, int gold, std::vector<std::string> inventory);

    std::string getName() const;
    double getHp() const;
    void setHp(double hp);
    double getDefense() const;
    void setDefense(double defense);
    char getCondition() const;
    void setCondition(char condition);
    int getGold() const;
    void setGold(int gold);

    void attack(Entity& target);
    void specialAttack(Entity& target);
    bool usePotion();
    void swapWeapon();
    void takeTurn(Entity& enemy);
    void printStats() const;

private:
    std::string name;
    double hp;
    double defense;
    char condition;
    bool advantage;
    std::string elementalWeakness;
    int gold;
    std::vector<std::string> inventory;
};
