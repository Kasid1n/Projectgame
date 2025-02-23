#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class Player {
private:
    int level;
    int xp;
    int xptolevelup;
    string name;
    int hp;
    int hpmax;
    int attack;
    int defense;
    int magic;
    int gold ;

    void levelup();

public:
    Player(string Playername, int hpmax, int attack, int defense, int magic); //std
    void addxp(int xpgained);
    void showstatus() const;
    void dead();
    int getLevel() const;
    int getGold() const;
    void updateGold(int amount);
    void equipItem(const Equipment& item);
};

#endif
  