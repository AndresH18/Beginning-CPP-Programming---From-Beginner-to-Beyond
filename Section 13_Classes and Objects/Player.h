//
// Created by andre on 2/8/2021.
//

#ifndef SECTION_13_CLASSES_AND_OBJECTS_PLAYER_H
#define SECTION_13_CLASSES_AND_OBJECTS_PLAYER_H


#include <string>

class Player {
private:
    std::string name;
    int health;
public:
    int xp;

    Player(); // constructor
    Player(std::string name); // constructor
    Player(std::string name, int health, int xp); // constructor
    Player(const Player &source); // Copy-Constructor

    ~Player();

    void damage(int d);

    bool is_dead();

};


#endif //SECTION_13_CLASSES_AND_OBJECTS_PLAYER_H
