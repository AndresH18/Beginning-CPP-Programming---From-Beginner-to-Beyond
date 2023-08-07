//
// Created by andre on 2/8/2021.
//
#include <iostream>
#include <utility>
#include "Player.h"

using namespace std;


Player::Player() {
    cout << "Player constructor called with no Arguments" << endl;
    name = "no name";
    xp = 0;
    health = 10;
}

Player::Player(std::string name_val) {
    cout << "Player constructor called with 1 argument" << endl;
    this->name = name_val;
    xp = 0;
    health = 10;
}

Player::Player(std::string name_val, int health_val, int xp_val) {
    cout << "Player constructor called with 3 arguments" << endl;
    name = name_val;
    xp = xp_val;
}

Player::~Player() {
    cout << "Player Destructor Called for: " << name << endl;
}

void Player::damage(int d) {
    health -= d;
}

bool Player::is_dead() {
    return health <= 0;
}

Player::Player(const Player &source)
        : name{source.name},
          health{source.health},
          xp{source.xp} {

}
