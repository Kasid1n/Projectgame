/*
 level(xp)
 addlevel
 xptoup
 levelup ---->> statup++ ---->>enemy++
 ***dead*** re ?? 
 -ดู class -
 ---randdom name ..
*/ 
#include "level.h"
#include "Equipment.h"

Player::Player(string Playername, int hpmax, int attack, int defense, int magic) {
    name = Playername;
    level = 1;
    xp = 0;
    xptolevelup = 100;
    hp = hpmax;
    hpmax = hpmax;  //chat บอกให้ใส่ this
    this->attack = attack;
    this->defense = defense;
    this->magic = magic;
    gold = 0;
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
    cout << "HP: " << hp << "/" << hpmax << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Magic: " << magic << endl;
    cout << "Gold: " << gold << endl;
}

void Player::levelup() {
    if (level < 100) {
        level++;
        xp -= xptolevelup;
        xptolevelup += (50 * level) + (rand() % 99 + 1);
        cout << name << " reached level " << level << "!!!!" << endl;
        showstatus();
    }
}

void Player::dead() {
    level = 1;
    xp = 0;
    xptolevelup = 100;
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
    vector<int> stats = item.getStat();
    hpmax += stats[0];
    attack += stats[1];
    defense += stats[2];
    magic += stats[3];
}




