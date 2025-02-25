/*
 level(xp)
 addlevel
 xptoup
 levelup ---->> statup++ ---->>enemy++
 ***dead*** re ?? 
 -ดู class -
 ---randdom name ..

✅ เพิ่มระบบขายไอเท็มกลับร้านค้า
✅ เพิ่มระบบ Inventory ให้ผู้เล่นเก็บไอเท็มก่อนสวมใส่
✅ เพิ่มระบบโจมตีหรือใช้ไอเท็ม
✅ เพิ่มระบบบันทึกและโหลดข้อมูลตัวละคร
*/ 
#include "level.h"
#include "Equipment.h"
#include <ctime>

Player::Player(string Playername, int hpmax, int attack, int defense, int magic) {
    this->name = Playername;
    this->hpmax = hpmax;
    this->hp = hpmax;  // กำหนดค่าเริ่มต้นให้ hp = hpmax
    this->attack = attack;
    this->defense = defense;
    this->magic = magic;
    this->level = 1;
    this->xp = 0;
    this->xptolevelup = 100;
    this->gold = 0;
}


void Player::addxp(int xpgained) {      //เพิ่ม xp และให้เวลตัน 100
    xp += xpgained;
    while (xp >= xptolevelup && level < 100) {
        levelup();
    }
    if (level == 100) {
        xp = xptolevelup;
    }
}

void Player::showstatus() const {  //แสดงค่าสถานะ
    cout << name << " is level " << level << endl;
    cout << name << " xp is " << xp << endl;
    cout << "HP: " << hp << "/" << hpmax << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Magic: " << magic << endl;
    cout << "Gold: " << gold << endl;
}

void Player::levelup() {  //เวลอัพ
    if (level < 100) {
        level++;
        xp -= xptolevelup;
        xptolevelup += (100 * level); //ใส่มั่ว
        cout << name << " reached level " << level << "!!!!" << endl;
        showstatus();
    }
}

void Player::dead() {  //ตาย re ค่า
    level = 1;
    xp = 0;
    xptolevelup = 100;
    hp = hpmax = 100 ;
    attack = 10 ;
    defense = 5 :
    magic = 5 ;
    gold  =  0 ;
    showstatus();
}

int Player::getLevel() const {  
    return level;
}

int Player::getGold() const {
    return gold;
}

void Player::updateGold(int amount) {  
    gold += amount;
}

void Player::equipItem(const Equipment& item) {  // ใส่ของจากร้านค้า
    vector<int> stats = item.getStat();
    hpmax += stats[0];
    attack += stats[1];
    defense += stats[2];
    magic += stats[3];
}




