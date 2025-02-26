#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "level.h"
#include "z.cpp"  // ใช้ Equipment จาก z.cpp

using namespace std;

class NPC {
private:
    string npcname;   //ชื่อ
    vector<string> sellItem;  // ขายของ
    vector<int> ItemPrice;  // ราคา
    vector<Equipment> ItemStats;  // addstat

public:
    NPC(string name);
    void shop();
    void sellItemToPlayer(Player &player);
};

#endif
