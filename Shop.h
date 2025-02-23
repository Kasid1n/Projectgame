#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Equipment.h"
#include "level.h"

using namespace std;

class NPC {
private:
    string npcname;            //std ::string npcname ;
    vector<string> sellItem;  //std::vector<std::string> sellItem;
    vector<int> ItemPrice;  //std
    vector<Equipment> ItemStats; // std

public:
    NPC(string name); //std::string name
    void shop();
    void sellItemToPlayer(Player &player);
};

#endif 