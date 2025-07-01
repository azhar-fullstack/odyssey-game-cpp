#include "Entity.h"
#include <cstdlib>  // For rand()
#include <algorithm>  // For std::max

Entity::Entity(std::string name, double hp, double defense, char condition, bool advantage, std::string elementalWeakness, int gold, std::vector<std::string> inventory)
: name(name), hp(hp), defense(defense), condition(condition), advantage(advantage), elementalWeakness(elementalWeakness), gold(gold), inventory(inventory) {}

std::string Entity::getName() const { return name; }
double Entity::getHp() const { return hp; }
void Entity::setHp(double hp) { this->hp = std::max(0.0, hp); }
double Entity::getDefense() const { return defense; }
void Entity::setDefense(double defense) { this->defense = defense; }
char Entity::getCondition() const { return condition; }
void Entity::setCondition(char condition) { this->condition = condition; }
int Entity::getGold() const { return gold; }
void Entity::setGold(int gold) { this->gold = gold; }

void Entity::attack(Entity& target) {
    int baseDamage = rand() % 15 + 10;  // Random damage between 10 and 25
    double effectiveDefense = target.getDefense() * 0.75;  // 75% effectiveness of defense
    double damageDealt = std::max(1.0, baseDamage - effectiveDefense);  // Ensure minimum damage of 1
    target.setHp(target.getHp() - damageDealt);
    std::cout << name << " attacks " << target.getName() << " and deals " << damageDealt << " damage!" << std::endl;
    if (target.getHp() <= 0) {
        std::cout << target.getName() << " has been defeated!" << std::endl;
    }
}

void Entity::specialAttack(Entity& target) {
    std::cout << name << " uses a special attack!" << std::endl;
    attack(target);  // Reuse attack logic for simplicity
}

bool Entity::usePotion() {
    if (!inventory.empty()) {
        std::cout << name << " uses a potion to restore health." << std::endl;
        setHp(getHp() + 20);  // Assume potion adds 20 HP
        inventory.pop_back();  // Remove a potion from inventory
        return true;
    }
    return false;
}

void Entity::swapWeapon() {
    if (inventory.size() > 1) {
        std::swap(inventory[0], inventory[1]);
        std::cout << name << " swaps weapons: " << inventory[0] << " <-> " << inventory[1] << std::endl;
    }
}

void Entity::printStats() const {
    std::cout << "Player: " << name << "\n"
              << "HP: " << hp << "\n"
              << "Defense: " << defense << "\n"
              << "Condition: " << condition << "\n"
              << "Gold held: " << gold << std::endl;
}

void Entity::takeTurn(Entity& enemy) {
    printStats();
    enemy.printStats();
    std::cout << "Which action would you like to take?\n"
              << "1. Attack\n"
              << "2. Use Potion\n"
              << "3. Swap Weapon\n"
              << "4. Attempt to Run\n"
              << "5. Special Attack\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            attack(enemy);
            break;
        case 2:
            if (!usePotion()) {
                std::cout << "No potions left to use.\n";
            }
            break;
        case 3:
            swapWeapon();
            break;
        case 4:
            std::cout << name << " attempts to run away!\n";
            // Implement running logic here
            break;
        case 5:
            specialAttack(enemy);
            break;
        default:
            std::cout << "Invalid choice!\n";
    }
}
