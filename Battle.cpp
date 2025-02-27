
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Stats {
public:
    int hp;
    int hpmax;
    int attack;
    int defense;
    int magic;
    
    Stats(int hpmax, int attack, int defense, int magic)
        : hpmax(hpmax), attack(attack), defense(defense), magic(magic) {
        hp = hpmax;
    }

    void start() {
        hp = hpmax;
    }
//ค่าสถานะ
    void showStats() const {
        cout << "HP: " << hp << "/" << hpmax << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Magic: " << magic << endl;
    }
//เพื่มค่าสถานะ
    void increaseStat(int choice) {
        switch (choice) {
            case 1: hpmax += 10; hp = hpmax; break;
            case 2: attack += 2; break;
            case 3: defense += 2; break;
            case 4: magic += 2; break;
            default: cout << "Invalid choice!" << endl; break;
        }
    }
};

class Player {
public:
    int level;
    int xp;
    int xptolevelup;
    int statPoints;
    string name;
    Stats stats;
    int gold;

int hpmax=stats.hpmax,hp=stats.hp,attack=stats.attack,defense=stats.defense,magic=stats.magic;
    Player(string playerName, int hpmax, int attack, int defense, int magic)
        : name(playerName), stats(hpmax, attack, defense, magic), gold(0) {
        level = 1;
        xp = 0;
        xptolevelup = 100;
        statPoints = 0;
    }
//ระบบเพื่ม XP
    void addXp(int xpGained) {
        xp += xpGained;
        while (xp >= xptolevelup) {
            levelUp();
        }
    }
//ระยย gold
    void addGold(int goldGained) {
        gold += goldGained;
    }
//แสดงสถานะ
    void showStatus() const {
        cout << name << " is level " << level << endl;
        cout << "XP: " << xp << "/" << xptolevelup << endl;
        cout << "Stat Points: " << statPoints << endl;
        cout << "Gold: " << gold << endl;
        stats.showStats();
    }

    int getLevel() const {
        return level;
    }
//ระบบการเพื่มlevel
private:
    void levelUp() {
        level++;
        xp -= xptolevelup;
        xptolevelup += (50 * level) + (rand() % 99 + 1);
        statPoints += 3;
        cout << name << " reached level " << level << "!!!!" << endl;
        distributeStatPoints();
        showStatus();
    }
//เพื่มค่าสถาน
    void distributeStatPoints() {
        while (statPoints > 0) {
            cout << "You have " << statPoints << " stat points to distribute." << endl;
            cout << "1. HP\n2. Attack\n3. Defense\n4. Magic\nChoose a stat to increase: ";
            int choice;
            cin >> choice;
            stats.increaseStat(choice);
            statPoints--;
        }
    }
//reset
public:
    void dead() {
        level = 1;
        xp = 0;
        xptolevelup = 100;
        statPoints = 0;
        stats.start();
        showStatus();
    }
};
//มอน
class Monster {
public:
    string name;
    int level;
    Stats stats;
    int goldDrop;
    int xpDrop;
//ค่าสถานะมอน
    int hpmax=stats.hpmax,hp=stats.hp,attack=stats.attack,defense=stats.defense,magic=stats.magic;
    Monster(string monsterName, int monsterLevel, int hpmax, int attack, int defense, int magic, int gold, int xp)
        : name(monsterName), level(monsterLevel), stats(hpmax, attack, defense, magic), goldDrop(gold * monsterLevel), xpDrop(xp * monsterLevel) {}

    void showStatus() const {
        cout << "Monster: " << name << " (Level " << level << ")" << endl;
        stats.showStats();
        cout << "Gold Drop: " << goldDrop << endl;
        cout << "XP Drop: " << xpDrop << endl;
    }

    int getGoldDrop() const {
        return goldDrop;
    }

    int getXpDrop() const {
        return xpDrop;
    }
};
//มอนแบบสุ่ม จะมีโอกาสเจอขึ้นอยู่กับ Level
class MonsterFactory {
public:
    static Monster randMonster(int level) {
        int randNum = rand() % 100;
        if (level >= 10 && randNum >= 70) return Monster("Spider", level, 100 + level * 10, 20 + level * 2, 12 + level, 8 + level / 2, 200, 300);
        if (level >= 7 && randNum >= 40) return Monster("Harpy.", level, 80 + level * 8, 15 + level * 2, 10 + level, 6 + level / 2, 100, 150);
        if (level >= 6 && randNum >= 20) return Monster("Hound", level, 60 + level * 6, 10 + level * 2, 8 + level, 4 + level / 2, 50, 80);
        if (level >= 5 && randNum >= 10) return Monster("Warrior-Skeleton", level, 60 + level * 6, 10 + level * 2, 8 + level, 4 + level / 2, 50, 80);
        return Monster("Skeleton", level, 1 + level * 5, 1 + level * 1, 6 + level, 1 + level / 1, 1, 1);
    }
//ส่วนของบอสที่เอาไว้จบเกม
    static Monster bossMonster1() {
        static Monster fixedMonster("ApocalypseSoulsBoss", 11, 111, 11, 11, 11, 111, 111);
        return fixedMonster;
    }
    static Monster bossMonster2() {
        static Monster fixedMonster("Dragonlord", 22, 222, 22, 22, 22, 222, 222);
        return fixedMonster;
    }
};

int AttackChoice() {/*อันนี้ช้อยของเพลเยอร์*/
    int achoice = 0;
    cout << "You're Attacker\n";//turn+P
    while (achoice < 1 || achoice > 4) {
        cout << "Press 1. Attack Press 2.Skill Press 3. Ultimate Press 4.Heal \n"; //ขออยู่บรรทัดเดียวกัน
        cin >> achoice;
    }
    return achoice;}
int DefenseChoice() {/*อันนี้ช้อยของเพลเยอร์*/
    int dchoice = 0;
    cout << "You're The Defender\n";//turn+P
    while (dchoice < 1 || dchoice > 4) {
        cout << "Press 1.Block(against Attack) Press 2.Dodge(against Weapon SKill) Press 3.Parry(against ultimate) Press 4. Give up\n";
        cin >> dchoice;
    }
    return dchoice;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*เป็นระบบการต่อสู้ คำนวน*/
void battlesys(Player &A, Monster &B, int attack) {/*เพราะมอนกับผู้เล่นมันคนละคลาสกัน เลยต้องทำ2อัน*/ /*อันนี้สำหรับคนตีมอนกัน*/
    cout <<endl;
    int defense = rand() % 3 + 1;
    cout << A.name << " Hp: " << A.hp << endl;
    cout << B.name << " Hp: " << B.hp << endl;
    
    float dmg = 0, def = defense, temp, rdmg, hp;
    bool countered = false;

    switch (attack) {/*ตี*/
        case 1:
            cout << A.name << " attacks!\n"; //upP2
            dmg = A.attack;
            rdmg = rand() % 31 - 15;
            dmg += dmg * (rdmg / 100);

            if(defense==attack){/*กัน*/
                temp = rand() % 30 + 1;
                dmg -= dmg * ((50 + temp) / 100);
            }
            break;
        case 2:
            cout << A.name << " uses skill!\n";
            dmg = A.magic;
            def = 0;
            temp = rand() % 3 + 1;
            if (temp == 1) dmg = 0;
            
            if(defense==attack){/*กัน*/
                temp = rand() % 4 + 1;
                if (temp != 1) dmg = 0;
            }
            break;
        case 3:
            cout << A.name << " uses ultimate!\n";
            dmg = (A.attack + A.magic) * 2;

            if(defense==attack){/*กัน*/
                countered = true;/*ถ้ากดกัน ตรงกับอันติจะรีเทินดาเมท*/
            }
            break;
        case 4:
            temp = rand() % 20 + 1;
            hp = A.hpmax * ((20 + temp) / 100.0);
            A.hp += hp;
            if (A.hp > A.hpmax) A.hp = A.hpmax;
            cout << A.name << " heals +" << hp << " Hp\n";
            return;
    }
    switch (defense) {/*อันนี้ 1-3ทำให้มัน coutเฉยๆว่าเลือกอะไรไป*/
        case 1:cout << B.name << " blocks!\n";break;
        case 2:cout << B.name << " dodges!\n";break;
        case 3:cout << B.name << " counters!\n";break;
        case 4:
            cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered==true) {/*รีเทินดาเมทของอันติ*/
        A.hp -= dmg;
    } else {/*โดนดาเมทธรรมดา*/
        B.hp -= dmg;
    }
    cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
    cout <<endl;
}

void battlesys(Monster &A, Player &B, int defense) {/*มอนกันคนตี*/ /*ด้านในเหมือนด้านบน แค่สลับinputเฉยๆ*/
    cout <<endl;
    int attack = rand() % 4 + 1;
    cout << A.name << " Hp: " << A.hp << endl;
    cout << B.name << " Hp: " << B.hp << endl;
    
    float dmg = 0, def = B.defense, temp, rdmg, hp;
    bool countered = false;

    switch (attack) {
        case 1:
            cout << A.name << " attacks!\n";
            dmg = A.attack;
            rdmg = rand() % 31 - 15;
            dmg += dmg * (rdmg / 100);

            if(defense==attack){
                temp = rand() % 30 + 1;
                dmg -= dmg * ((50 + temp) / 100);
            }
            break;
        case 2:
            cout << A.name << " uses skill!\n";
            dmg = A.magic;
            def = 0;
            temp = rand() % 3 + 1;
            if (temp == 1) dmg = 0;
            
            if(defense==attack){
                temp = rand() % 4 + 1;
                if (temp != 1) dmg = 0;
            }
            break;
        case 3:
            cout << A.name << " uses ultimate!\n";
            dmg = (A.attack + A.magic) * 2;

            if(defense==attack){
                countered = true;
            }
            break;
        case 4:
            temp = rand() % 20 + 1;
            hp = A.hpmax * ((20 + temp) / 100.0);
            A.hp += hp;
            if (A.hp > A.hpmax) A.hp = A.hpmax;
            cout << A.name << " heals +" << hp << " Hp\n";
            return;
    }
    switch (defense) {
        case 1:cout << B.name << " blocks!\n";break;
        case 2:cout << B.name << " dodges!\n";break;
        case 3:cout << B.name << " counters!\n";break;
        case 4:
            cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered==true) {
        A.hp -= dmg;
    } else {
        B.hp -= dmg;
    }
    cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
    cout <<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void battle(Player &player, Monster &enemy) {//ฟังก์ชั่นbattle ใช้วนจนhpฝ่ายนึงหมด
    int WR;
    cout << "Battle begins: " << player.name << " vs " << enemy.name << "!\n";

    int rcoin = rand() % 2, coin = 2;
    string scoin;
    
    do {/*สุ่มเหรียญ*/
        cout << "Pick head or tail: ";
        cin >> scoin;
        if (scoin == "head") coin = 0;
        else if (scoin == "tail") coin = 1;
        else cout << "Error. Try Again\n";
    } while (coin == 2);

    int round = 1;
    while (player.hp > 0 && enemy.hp > 0) {/*ถ้าเลือดหมดจะจบ*/
        cout<<endl;
        int attack, defense;

        cout << "Round: " << round << endl;

        if (coin == rcoin) {//สำหรับเหรีียญตรง จะได้เป็นattackerก่อน
            attack = AttackChoice();
            battlesys(player/*คนตี*/, enemy/*คนกัน*/, attack/*ช้อยตีว่ากดตีแบบไยกัน*/);
            if (enemy.hp <= 0 || player.hp <= 0) break;
            defense = DefenseChoice();
            battlesys(enemy, player, defense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
        } else {//เหรียญไม่ตรง
            defense = DefenseChoice();
            battlesys(enemy, player, defense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
            attack = AttackChoice();
            battlesys(player, enemy, attack);
            if (enemy.hp <= 0 || player.hp <= 0) break;
        }
        round++;
    }

    if (player.hp > 0){WR=1; cout << "\n" << player.name << " wins!\n";}/*เช็คว่าใครชนะ*/
    else {WR=2; cout << "\n" << enemy.name << " wins!\n";}
    cout<<endl;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 

// int main() {
//     int WR=0;
//     srand(time(0));
//     string playerName;
//     cout << "Enter player name: ";
//     getline(cin, playerName); //ตั้งชื่อ
//     Player player(playerName, 100, 20, 10, 5);
//     player.showStatus();
//     player.addXp(200); 
//     int playerLevel = player.getLevel();
//     Monster randomMon = MonsterFactory::randMonster(playerLevel);
//     Monster fixedMon = MonsterFactory::bossMonster1();
//     randomMon.showStatus();
//     fixedMon.showStatus();
//     player.addGold(randomMon.getGoldDrop());// จำเป็นต้องเอาใส่โค้ตหลักไม่งั้น Gold ไม่เพื่ม
//     player.addXp(randomMon.getXpDrop());// จำเป็นต้องเอาใส่โค้ตหลักไม่งั้น XP ไม่เพื่ม
//     player.showStatus();
//     battle(player, randomMon);
//     switch(WR){
//         case 1:cout<<"player win"; break;
//         case 2:cout<<"monster win";break;}

//     return 0;
// }