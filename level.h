// ไม่ได้ใช้ เอาไปรวมกับ แชมป์แล้ว
#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <string>
//#include "z.h" // ตามแชท


using namespace std;

class Player {
private:
    int level;
    int xp;
    int xptolevelup;
    string name;
    Stats stats;  // ออบเจ็กต์ Stats ใช้จัดการค่า health, attack, etc.
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
    //void equipItem(const Equipment& item);  // สวมใส่ไอเทมที่ได้รับ
};

#endif
