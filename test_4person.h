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
    string itemName;
public:
    Equipment(int h, int a, int d, int m) : hpmax(h), atk(a), def(d), magic(m) {}

    vector<int> getStat() const{
        return {hpmax, atk, def, magic};
    }
    string name; // ชื่อของไอเทม

    string getItemName() const {
        return name;  // ส่งคืนชื่อของไอเทม
    }
    bool operator==(const Equipment& other) const {
        return (hpmax == other.hpmax && atk == other.atk && def == other.def && magic == other.magic);
    }
    Equipment(string name, int h, int a, int d, int m) 
        : itemName(name), hpmax(h), atk(a), def(d), magic(m) {}

    string getItemName() { return itemName; }
};

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
    vector<Equipment*> equipmentList = {nullptr, nullptr, nullptr};
    int getEquipmentCount() const {
        return equipmentList.size();
    }

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

    
    void showInventory() {
        cout << "\n--- Inventory ---\n";
        if (inventory.empty()) {
            cout << "Inventory is empty.\n";
        } else {
            for (size_t i = 0; i < inventory.size(); i++) {
                cout << i + 1 << ". " << inventory[i].getItemName() << "\n";
            }
        }
    }

    void showEquipment() {
        cout << "\n--- Equipped Items ---\n";
        for (size_t i = 0; i < equipmentList.size(); i++) {
            if (equipmentList[i] != nullptr) { 
                cout << i + 1 << ". " << equipmentList[i]->getItemName() << "\n";
            } else {
                cout << i + 1 << ". (Empty Slot)\n";
            }
        }
    }
    
    void equipItem(const Equipment& item) {
        cout << "DEBUG: Equipment list size before equip: " << equipmentList.size() << endl;
    
        // หากช่องอุปกรณ์เต็ม ให้ผู้เล่นเลือกช่องที่จะแทนที่
        if (equipmentList.size() >= 3) {
            cout << "Equipment slots are full. Choose an item to replace (0-2) or cancel (-1): ";
            int choice;
            cin >> choice;
    
            // ตรวจสอบการเลือก
            if (choice == -1) {
                cout << "Equip action cancelled.\n";
                return;
            } else if (choice < 0 || choice >= equipmentList.size()) {
                cout << "Invalid choice!\n";
                return;
            }
    
            // ถอดอุปกรณ์เดิม (ถ้ามี)
            if (equipmentList[choice] != nullptr) {
                // ลบค่าสถานะของอุปกรณ์เดิม
                vector<int> oldStats = equipmentList[choice]->getStat();
                stats.hpmax -= oldStats[0];
                stats.attack -= oldStats[1];
                stats.defense -= oldStats[2];
                stats.magic -= oldStats[3];
    
                // เพิ่มอุปกรณ์เดิมกลับเข้า Inventory
                inventory.push_back(*equipmentList[choice]);
    
                // ลบอุปกรณ์เดิม
                delete equipmentList[choice];
            }
    
            // สวมใส่อุปกรณ์ใหม่
            equipmentList[choice] = new Equipment(item);
    
            // เพิ่มค่าสถานะจากอุปกรณ์ใหม่
            vector<int> newStats = item.getStat();
            stats.hpmax += newStats[0];
            stats.attack += newStats[1];
            stats.defense += newStats[2];
            stats.magic += newStats[3];
    
            // ตรวจสอบ HP ไม่เกินค่าสูงสุด
            if (stats.hp > stats.hpmax) stats.hp = stats.hpmax;
    
            cout << "Equipped: " << item.getItemName() << " in slot " << choice << "\n";
        } else {
            // หากช่องอุปกรณ์ยังไม่เต็ม ให้สวมใส่อุปกรณ์ในช่องว่าง
            for (int i = 0; i < 3; i++) {
                if (equipmentList[i] == nullptr) {
                    equipmentList[i] = new Equipment(item);
    
                    // เพิ่มค่าสถานะจากอุปกรณ์ใหม่
                    vector<int> newStats = item.getStat();
                    stats.hpmax += newStats[0];
                    stats.attack += newStats[1];
                    stats.defense += newStats[2];
                    stats.magic += newStats[3];
    
                    // ตรวจสอบ HP ไม่เกินค่าสูงสุด
                    if (stats.hp > stats.hpmax) stats.hp = stats.hpmax;
    
                    cout << "Equipped: " << item.getItemName() << " in slot " << i << "\n";
                    break;
                }
            }
        }
    
        cout << "DEBUG: Equipment list size after equip: " << equipmentList.size() << endl;
    }
    

    void equip(Equipment* item) {
        bool found = false;
    
        // ตรวจสอบว่าไอเทมมีอยู่ใน Inventory หรือไม่
        for (auto& invItem : inventory) {
            if (&invItem == item) {
                found = true;
    
                // ถ้าเจอให้ทำการอัปเดตสถานะของผู้เล่น
                vector<int> itemStats = item->getStat();
                stats.hpmax += itemStats[0];
                stats.attack += itemStats[1];
                stats.defense += itemStats[2];
                stats.magic += itemStats[3];
    
                // ตรวจสอบว่า HP ไม่เกินค่าสูงสุด
                if (stats.hp > stats.hpmax) stats.hp = stats.hpmax;
    
                cout << "Item equipped: " << item->getItemName() << "\n";
    
                // เพิ่มไอเทมลงใน equipmentList หลังจากสวมใส่
                equipmentList.push_back(item);
                break;
            }
        }
    
        // ถ้าไม่พบไอเทมใน Inventory
        if (!found) {
            cout << "Item not found in inventory!\n";
        }
    }
    

    // ฟังก์ชันในการถอดอุปกรณ์
    void unequip() {
        // แสดงรายการอุปกรณ์ที่สวมใส่อยู่
        cout << "\n--- Equipped Items ---\n";
        for (size_t i = 0; i < equipmentList.size(); i++) {
            if (equipmentList[i] != nullptr) {
                cout << i << ". " << equipmentList[i]->getItemName() << "\n";
            } else {
                cout << i << ". (Empty Slot)\n";
            }
        }
    
        // ให้ผู้เล่นเลือกช่องที่ต้องการถอด
        int choice;
        cout << "Enter the slot number to unequip (0-2, or -1 to cancel): ";
        cin >> choice;
    
        // ตรวจสอบการเลือก
        if (choice == -1) {
            cout << "Unequip cancelled.\n";
            return;
        } else if (choice < 0 || choice >= equipmentList.size()) {
            cout << "Invalid slot number!\n";
            return;
        } else if (equipmentList[choice] == nullptr) {
            cout << "This slot is already empty!\n";
            return;
        }
    
        // ถอดอุปกรณ์
        Equipment* eq = equipmentList[choice];
    
        // คืนค่าสถานะของผู้เล่น
        vector<int> stat = eq->getStat();
        stats.hpmax -= stat[0];
        stats.attack -= stat[1];
        stats.defense -= stat[2];
        stats.magic -= stat[3];
    
        if (stats.hp > stats.hpmax) stats.hp = stats.hpmax;
    
        // เพิ่มอุปกรณ์ที่ถอดออกกลับเข้าไปใน Inventory
        inventory.push_back(*eq);
    
        // ลบอุปกรณ์ออกจากช่องที่เลือก
        delete equipmentList[choice];
        equipmentList[choice] = nullptr;
    
        // เพิ่มโค้ดใหม่: บันทึกประวัติการถอดอุปกรณ์
        cout << "Unequipped " << eq->getItemName() << " from slot " << choice << ".\n";
        cout << "DEBUG: Added " << eq->getItemName() << " to inventory.\n";
    }
    

    
    
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
        if (A.hp<0)
        { A.hp=0;}
    } else {/*โดนดาเมทธรรมดา*/
        B.hp -= dmg;
        if (B.hp<0)
        { B.hp=0;}
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
        if (A.hp<0)
        { A.hp=0;}
    } else {
        B.hp -= dmg;
        if (B.hp<0)
        { B.hp=0;}
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
    public:
        string npcname;
        vector<string> sellItem;
        vector<int> ItemPrice;
        vector<Equipment> ItemStats;
        bool hasShopped = false;  // เพิ่มตัวแปรเพื่อตรวจสอบว่าผู้เล่นได้ซื้อไปแล้วหรือยัง
    
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
            cout << "Attack+: " << ItemStats[i].getStat()[1] << " ";
            cout << "Defense+: " << ItemStats[i].getStat()[2] << " ";
            cout << "Heal+: " << ItemStats[i].getStat()[0] << " ";
            cout << "Magic+: " << ItemStats[i].getStat()[3] << endl;
        }
    }
    
    void NPC::sellItemToPlayer(Player &player) {
        if (hasShopped) {
            cout << "You have already purchased from " << npcname << ". You can't buy more this time!" << endl;
            return;
        }
        int choice;
        while (true) {
            shop();
            cout << "Your Gold: " << player.getGold() << endl;
            cout << "Enter item number (0 to exit): ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            if (choice == 0) break;
            if (choice > 0 && choice <= sellItem.size()) {
                int index = choice - 1;
                if (player.getGold() >= ItemPrice[index]) {
                    player.updateGold(-ItemPrice[index]);
                    if (sellItem[index] == "Attack Potion") {
                        int atkBoost = rand() % 5 + 10;
                        player.stats.attack += atkBoost;
                        cout << "You used Attack Potion! Attack increased by " << atkBoost << "!\n";
                    } 
                    else if (sellItem[index] == "Heal Potion") {
                        int healAmount = rand() % 10 + 10;
                        player.stats.hpmax += healAmount;
                        cout << "You used Heal Potion! Max HP increased by " << healAmount << "!\n";
                    } 
                    else if (sellItem[index] == "Defense Potion") {
                        int defBoost = rand() % 5 + 10;
                        player.stats.defense += defBoost;
                        cout << "You used Defense Potion! Defense increased by " << defBoost << "!\n";
                    } 
                    else {
                        // Create a new Equipment object with the correct name and stats
                        Equipment newItem(sellItem[index], ItemStats[index].getStat()[0], ItemStats[index].getStat()[1], ItemStats[index].getStat()[2], ItemStats[index].getStat()[3]);
                        player.equipItem(newItem);
                        cout << "You bought " << sellItem[index] << "!\n";
                    }
                    hasShopped = true;
                    return;
                } else {
                    cout << "Not enough gold!\n";
                }
            } else {
                cout << "Invalid choice!\n";
            }
        }
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

    int main() { 
        int WR = 0;
        srand(time(0));
        string playerName;
        cout << "Enter player name: ";
        getline(cin, playerName); // Set player name
        Player player(playerName, 100, 20, 10, 5);
        player.showStatus();
        player.addXp(0); 
        int playerLevel = player.getLevel();
        Monster randomMon = MonsterFactory::randMonster(playerLevel);
        Monster fixedMon = MonsterFactory::bossMonster();
        randomMon.showStatus();
        fixedMon.showStatus();
        player.addGold(randomMon.getGoldDrop()); // Add gold
        player.addXp(randomMon.getXpDrop()); // Add XP
        player.showStatus();
        int attackChoice;
        std::cout << "Choose attack: (1) Attack, (2) Skill, (3) Ultimate, (4) Heal\n";
        std::cin >> attackChoice;
    
        R result = battlesys(player, randomMon, attackChoice); // Call battlesys
    
        std::cout << "You dealt " << result.D << " damage!\n";
        switch (WR) {
            case 1: cout << "player win"; break;
            case 2: cout << "monster win"; break;
        }
        cout << "\n--- Player Status After Battle ---\n";
        player.showStatus();
        cout << "DEBUG: Equipment list size before buying: " << player.equipmentList.size() << "\n";
        player.showEquipment();
    
        cout << "\n--- Visiting a Shop ---\n";
        NPC shopNPC = getRandomNPC();
        shopNPC.sellItemToPlayer(player);
    
        cout << "\n--- Player Status After Shopping ---\n";
        player.showStatus();
        cout << "DEBUG: Equipment list size before shop: " << player.equipmentList.size() << "\n";
        for (size_t i = 0; i < player.equipmentList.size(); i++) {
            if (player.equipmentList[i] != nullptr) {
                cout << "DEBUG: Slot " << i + 1 << ": " << player.equipmentList[i]->getItemName() << "\n";
            } else {
                cout << "DEBUG: Slot " << i + 1 << ": (Empty Slot)\n";
            }
        }
    
        // Debug message to confirm the program reaches the test section
        cout << "\n--- Reached Test Section ---\n";
    
        // Create a test item dynamically
        Equipment* testItem = new Equipment("Test Sword", 0, 15, 5, 0);
    
        // Test equipping the item
        cout << "\nEquipping Test Sword...\n";
        player.equipItem(*testItem);
        player.showInventory();
        player.showEquipment();
        player.showStatus();
    
        cout << "Inventory size: " << player.inventory.size() << "\n";
        cout << "Equipment list size: " << player.equipmentList.size() << "\n";
    
        // Test unequipping the item
        cout << "\nUnequipping Test Sword...\n";
        player.unequip();
        player.showInventory();
        player.showEquipment();
        player.showStatus();
    
        cout << "Inventory size: " << player.inventory.size() << "\n";
        cout << "Equipment list size: " << player.equipmentList.size() << "\n";
    
        // Delete the test item
        delete testItem;
    
        cout << "\n--- End of Program ---\n";
        return 0;
    }
