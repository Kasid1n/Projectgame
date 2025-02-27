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
//#include "Equipment.h"
//#include "z.h" // ตามแชท
#include "z.cpp"  // เชื่อมโยงกับ Stats และ Equipment
#include <ctime>

Player::Player(string Playername, int hpmax, int attack, int defense, int magic)
    : stats(hpmax, attack, defense, magic) {  // เริ่มต้น Stats ในคอนสตรัคเตอร์
    this->name = Playername;
    this->level = 1;
    this->xp = 0;
    this->xptolevelup = 100;
    this->gold = 0;
}

void Player::addxp(int xpgained) { 
    xp += xpgained;
    while (xp >= xptolevelup && level < 100) {
        levelup();
    }
    if (level == 100) {
        xp = xptolevelup;
    }
}

void Player::showstatus() const {
    cout << name << " is level " << level << endl;
    cout << name << " xp is " << xp << endl;
    //stats.printStats();  // แสดงสถานะจากคลาส Stats  เจอปัยหา
    cout << "Gold: " << gold << endl;
}

void Player::levelup() {
    if (level < 100) {
        level++;
        xp -= xptolevelup;
        xptolevelup += (100 * level);
        cout << name << " reached level " << level << "!!!!" << endl;
        showstatus();
    }
}

void Player::dead() {
    level = 1;
    xp = 0;
    xptolevelup = 100;
    stats = Stats(100, 10, 5, 5);  // รีเซ็ตสถานะ
    gold = 0;
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

void Player::equipItem(const Equipment& item) {
    stats.equip(new Equipment(item));  // สวมใส่ไอเทมโดยส่งไปยัง Stats
}

// ใช้เพื่อ compile g++ z.cpp level.cpp -o level



