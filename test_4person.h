#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

struct R {
    int D,d,h;
};
R t;
class Equipment {
    int hpmax;
    int atk;
    int def;
    int magic;
public:
    Equipment(int h, int a, int d, int m) : hpmax(h), atk(a), def(d), magic(m) {}

    vector<int> getStat() {
        return {hpmax, atk, def, magic};
    }
};

class Stats {
public:
    int hp;
    int hpmax;
    int attack;
    int defense;
    int magic;
    vector<Equipment*> equipmentList; // รายการอุปกรณ์

    Stats(int hpmax, int attack, int defense, int magic)
        : hpmax(hpmax), attack(attack), defense(defense), magic(magic) {
        hp = hpmax;
    }

    void start() {
        hp = hpmax;
    }

    // แสดงค่าค่าสถานะ
    void showStats() const {
        cout << "HP: " << hp << "/" << hpmax << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Magic: " << magic << endl;
    }

    // เพิ่มค่าสถานะ
    void increaseStat(int choice) {
        switch (choice) {
            case 1: hpmax += 10; hp = hpmax; break;
            case 2: attack += 2; break;
            case 3: defense += 2; break;
            case 4: magic += 2; break;
            default: cout << "Invalid choice!" << endl; break;
        }
    }

    // ใส่อุปกรณ์
    void equip(Equipment* eq) {
        if (equipmentList.size() >= 3) {
            cout << "Cannot equip more than 3 items." << endl;
            return;
        }
        equipmentList.push_back(eq);
        vector<int> stat = eq->getStat();
        hpmax += stat[0];
        attack += stat[1];
        defense += stat[2];
        magic += stat[3];

        if (hp > hpmax) hp = hpmax; // ปรับ HP ไม่ให้เกิน
    }

    // ถอดอุปกรณ์
    void unequip(int index) {
        if (index < 0 || index >= equipmentList.size()) {
            cout << "Invalid equipment index." << endl;
            return;
        }

        vector<int> stat = equipmentList[index]->getStat();
        hpmax -= stat[0];
        attack -= stat[1];
        defense -= stat[2];
        magic -= stat[3];

        equipmentList.erase(equipmentList.begin() + index);

        if (hp > hpmax) hp = hpmax; // ปรับ HP ไม่ให้เกิน
    }

    // นับจำนวนอุปกรณ์ที่สวมใส่
    int getEquipmentCount() {
        return equipmentList.size();
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
    vector<Equipment> inventory;

int hpmax=stats.hpmax,hp=stats.hp,attack=stats.attack,defense=stats.defense,magic=stats.magic;
    Player(string playerName, int hpmax, int attack, int defense, int magic)
        : name(playerName), stats(hpmax, attack, defense, magic), gold(0) {
        level = 1;
        xp = 0;
        xptolevelup = 100;
        statPoints = 0;
    }
    ////////
    int getGold() {
        return gold;
    }

    void updateGold(int amount) {
        gold += amount;
    }

    void equipItem(Equipment item) {
        inventory.push_back(item);  // เพิ่มไอเทมเข้าไปใน inventory ของผู้เล่น
    }
    ///////
//ระบบเพื่ม XP
    void addXp(int xpGained) {
        xp += xpGained;
    
    while (xp >= xptolevelup && level < 100) {
        levelUp();
    }

    if (level >= 100) {
        xp = xptolevelup; // ป้องกัน XP เกินลิมิต
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
        if (level >= 7 && randNum >= 40) return Monster("Harpy", level, 80 + level * 8, 15 + level * 2, 10 + level, 6 + level / 2, 100, 150);
        if (level >= 6 && randNum >= 20) return Monster("Hound", level, 60 + level * 6, 10 + level * 2, 8 + level, 4 + level / 2, 50, 80);
        if (level >= 5 && randNum >= 10) return Monster("Warrior-Skeleton", level, 60 + level * 6, 10 + level * 2, 8 + level, 4 + level / 2, 50, 80);
        return Monster("Skeleton", level, 1 + level * 5, 1 + level * 1, 6 + level, 1 + level / 1, 1000, 1);
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
    static Monster bossMonster() {
        int randomValue = rand() % 10; // สุ่มค่า 0-9

        if (randomValue < 6) { // ถ้าค่าที่สุ่มได้น้อยกว่า 6 (0,1,2,3,4,5)
            return bossMonster1(); // 60% ที่จะได้ ApocalypseSoulsBoss
        } else { // ถ้าค่าที่สุ่มได้เป็น 6,7,8,9
            return bossMonster2(); // 40% ที่จะได้ Dragonlord
        }
    }
};

int AttackChoice() {/*อันนี้ช้อยของเพลเยอร์*/
    int achoice = 0;
    cout << "You're Attacker\n";//turn+P
    while (achoice < 1 || achoice > 4) {
        cout << "Press 1. Attack Press 2.Skill Press 3. Ultimate Press 4.Heal "; //ขออยู่บรรทัดเดียวกัน
        cin >> achoice;
    }
    return achoice;}
int DefenseChoice() {/*อันนี้ช้อยของเพลเยอร์*/
    int dchoice = 0;
    cout << "You're The Defender\n";//turn+P
    while (dchoice < 1 || dchoice > 4) {
        cout << "Press 1.Block(against Attack) Press 2.Dodge(against Weapon SKill) Press 3.Parry(against ultimate) Press 4. Give up";
        cin >> dchoice;
    }
    return dchoice;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ของเจต
/*เป็นระบบการต่อสู้ คำนวน*/
R battlesys(Player &A, Monster &B, int attack) {/*เพราะมอนกับผู้เล่นมันคนละคลาสกัน เลยต้องทำ2อัน*/ /*อันนี้สำหรับคนตีมอนกัน*/
    cout <<endl;
    int defense = rand() % 3 + 1;

    //cout << A.name << " Hp: " << A.hp << endl;
    //cout << B.name << " Hp: " << B.hp << endl;
    
    int dmg = 0, def = B.defense, temp, rdmg, hp;
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
            t.h=hp;
            A.hp += hp;
            if (A.hp > A.hpmax) A.hp = A.hpmax;
            cout << A.name << " heals +" << hp << " Hp\n";
            
    }
    switch (defense) {/*อันนี้ 1-3ทำให้มัน coutเฉยๆว่าเลือกอะไรไป*/
        case 1://cout << B.name << " blocks!\n";
        break;
        case 2://cout << B.name << " dodges!\n";
        break;
        case 3://cout << B.name << " counters!\n";
        break;
        case 4:
            //cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered==true) {/*รีเทินดาเมทของอันติ*/
        A.hp -= dmg;
    } else {/*โดนดาเมทธรรมดา*/
        B.hp -= dmg;
    }
    /*cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
    cout <<endl;*/
    t.D=dmg;
    t.d=defense;

    return t;
}

R battlesys(Monster &A, Player &B, int defense) {/*มอนกันคนตี*/ /*ด้านในเหมือนด้านบน แค่สลับinputเฉยๆ*/
    cout <<endl;
    int attack = rand() % 4 + 1;
    
    //cout << A.name << " Hp: " << A.hp << endl;
    //cout << B.name << " Hp: " << B.hp << endl;
    
    int dmg = 0, def = B.defense, temp, rdmg, hp;
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
           // cout << A.name << " heals +" << hp << " Hp\n";
            
    }
    switch (defense) {
        case 1://cout << B.name << " blocks!\n"; 
        break;
        case 2://cout << B.name << " dodges!\n"; 
        break;
        case 3://cout << B.name << " counters!\n"; 
        break;
        case 4:
            //cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered==true) {
        A.hp -= dmg;
    } else {
        B.hp -= dmg;
    }
   /* cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
    cout <<endl;*/

    t.D=dmg;
    t.d=attack;

    return t;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ของมิค


//guitar

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

    NPC::NPC(string name) {
        npcname = name;
    
        if (npcname == "A") {
            // รายการของไอเทมที่ A สามารถขาย
            vector<string> possibleItems = {"Axe", "SuperAxe", "Sword"};
            int numItems = rand() % 3 + 1;  // ขาย 1 ถึง 3 ไอเทม
    
            for (int i = 0; i < numItems; i++) {
                int randIndex = rand() % possibleItems.size(); 
                sellItem.push_back(possibleItems[randIndex]); // เพิ่ม item ที่สุ่มไปขาย
                int price = rand() % 11 + 15;  // ราคาของไอเทมสุ่มจาก 15 ถึง 25
                ItemPrice.push_back(price);
    
                // กำหนด stat ของ item
            if (possibleItems[randIndex] == "Axe") {
                ItemStats.push_back(Equipment(0, rand()%5 +10, 0, 0));
            } else if (possibleItems[randIndex] == "SuperAxe") {
                ItemStats.push_back(Equipment(0, rand()%8 +10, 0, 0));
            } else if (possibleItems[randIndex] == "Sword") {
                ItemStats.push_back(Equipment(0, rand()%10 +10, 0, 0));
            }
            }
        }
        else if (npcname == "B") {
            // รายการของไอเทมที่ B สามารถขาย
            vector<string> possibleItems = {"Shield", "Better Shield","Armor"};
            int numItems = rand() % 3 + 1;  // ขาย 1 ถึง 3 ไอเทม
    
            for (int i = 0; i < numItems; i++) {
                int randIndex = rand() % possibleItems.size();
                sellItem.push_back(possibleItems[randIndex]);
                int price = rand() % 11 + 20;  // ราคาของไอเทมสุ่มจาก 20 ถึง 30
                ItemPrice.push_back(price);
    
                // กำหนดสถิติของไอเทมที่ขาย
                if (possibleItems[randIndex] == "Shield") {
                    ItemStats.push_back(Equipment(0, 0, rand()%5 +10, 0));
                } else if (possibleItems[randIndex] == "Better Shield") {
                    ItemStats.push_back(Equipment(0, 0, rand() % 8 +10, 0));
                } else if (possibleItems[randIndex] == "Armor") {
                    ItemStats.push_back(Equipment(0, 0, rand()%10 + 10, 0));
                }
            }
        }
        else if (npcname == "Secretmaster") {
            vector<string> secretItems = {"Attack Potion", "Heal Potion", "Defense Potion", "Necklace"};
            int numItems = rand() % 4 + 1;
    
            for (int i = 0; i < numItems; i++) {
                int randIndex = rand() % secretItems.size();
                sellItem.push_back(secretItems[randIndex]);
                int price = rand() % 21 + 10;  // ราคาของไอเทมสุ่มจาก 10 ถึง 30
                ItemPrice.push_back(price);
    
                if (secretItems[randIndex] == "Attack Potion") {
                    ItemStats.push_back(Equipment(0, rand()%5 +10, 0, 0));
                } else if (secretItems[randIndex] == "Heal Potion") {
                    ItemStats.push_back(Equipment(rand()%10 +10, 0, 0, 0));
                } else if (secretItems[randIndex] == "Defense Potion"){
                    ItemStats.push_back(Equipment(0, 0, rand()%5 +10, 0));
                } else {
                    ItemStats.push_back(Equipment(0, 0, 0, rand()%5 + 10 )) ;
                }
            }
        }
    }
    
    void NPC::shop() { // ขาย ดูว่าสุ่มได้ npc ตัวไหนขายตามนั้น
        cout << npcname << "'s Shop\n";
    for (size_t i = 0; i < sellItem.size(); i++) {
        cout << i + 1 << ". " << sellItem[i] << "  ( Price: " << ItemPrice[i] << " )\n";
             // ใช้ getStat() เพื่อดึงค่า stats
             vector<int> stats = ItemStats[i].getStat();  
             cout << "Attack+: " << stats[1] << " ";
             cout << "Defense+: " << stats[2] << " ";
             cout << "Health+: " << stats[0] << " ";
             cout << "Magic+: " << stats[3] << endl;
         }
    }
    
    void NPC::sellItemToPlayer(Player &player) {
        cout << npcname << " offers the following items for sale:" << endl;
        for (int i = 0; i < sellItem.size(); i++) {
            cout << i + 1 << ". " << sellItem[i] << " - Price: " << ItemPrice[i] << " Gold" << endl;
        }
        
    
        int itemChoice;
        cout << "Enter the number of the item you want to buy (or 0 to exit): ";
        cin >> itemChoice;
    
        if (itemChoice == 0) {
            cout << "Exiting the shop..." << endl;
            return;
        }
    
        // ตรวจสอบว่าไอเทมที่เลือกถูกต้อง
        if (itemChoice < 1 || itemChoice > sellItem.size()) {
            cout << "Invalid choice!" << endl;
            return;
        }
    
        // ตรวจสอบว่าเพียงพอทองหรือไม่
        int itemPrice = ItemPrice[itemChoice - 1];
        if (player.getGold() < itemPrice) {
            cout << "You don't have enough gold to buy this item!" << endl;
            return;
        }
    
        // ลดทองจากผู้เล่น
        player.updateGold(-itemPrice);
    
        // เอาไอเทมที่ซื้อมาเพิ่มเข้าไปใน inventory
        Equipment purchasedItem = ItemStats[itemChoice - 1];
        player.equipItem(purchasedItem);
    
        // เพิ่ม stat จากไอเทมที่ซื้อ
        vector<int> itemStats = purchasedItem.getStat();
        player.stats.hpmax += itemStats[0];
        player.stats.attack += itemStats[1];
        player.stats.defense += itemStats[2];
        player.stats.magic += itemStats[3];
    }
    
    NPC getRandomNPC() {
        vector<string> npcNames = {
            "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",  // 10 ครั้ง (50%)
            "B", "B", "B", "B", "B", "B", "B",                  // 7 ครั้ง (35%)
            "Secretmaster", "Secretmaster", "Secretmaster"      // 3 ครั้ง (15%)
        };
        
        int randomIndex = rand() % npcNames.size(); // สุ่ม NPC ตามอัตราส่วน
        return NPC(npcNames[randomIndex]);
    }

// int main() {
//     int WR=0;
//     srand(time(0));
//     string playerName;
//     cout << "Enter player name: ";
//     getline(cin, playerName); //ตั้งชื่อ
//     Player player(playerName, 100, 20, 10, 5);
//     player.showStatus();
//     player.addXp(100); 
//     int playerLevel = player.getLevel();
//     Monster randomMon = MonsterFactory::randMonster(playerLevel);
//     Monster fixedMon = MonsterFactory::bossMonster();
//     randomMon.showStatus();
//     fixedMon.showStatus();
//     player.addGold(randomMon.getGoldDrop());// จำเป็นต้องเอาใส่โค้ตหลักไม่งั้น Gold ไม่เพื่ม
//     player.addXp(randomMon.getXpDrop());// จำเป็นต้องเอาใส่โค้ตหลักไม่งั้น XP ไม่เพื่ม
//     player.showStatus();
//     int attackChoice;
//     std::cout << "Choose attack: (1) Attack, (2) Skill, (3) Ultimate, (4) Heal\n";
//     std::cin >> attackChoice;

//     R result = battlesys(player, randomMon, attackChoice); // เรียกใช้ battlesys

//     std::cout << "You dealt " << result.D << " damage!\n";
//     switch(WR){
//         case 1:cout<<"player win"; break;
//         case 2:cout<<"monster win";break;}
//          cout << "\n--- Player Status After Battle ---\n";
//     player.showStatus();
//     cout << "\n--- Visiting a Shop ---\n";
//     NPC shopNPC = getRandomNPC();
//     shopNPC.sellItemToPlayer(player);
//     cout << "\n--- Player Status After Shopping ---\n";
//     player.showStatus();
    

//     return 0;
// }
