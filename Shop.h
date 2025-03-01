//รวมกับแชมป์แล้ว
#include <iostream>
#include <vector>
#include <string>
#include<ctime>
using namespace std;
class Equipment {
    public:
        int health;
        int attack;
        int defense;
        int magic;
        
        Equipment(int h, int a, int d, int m) : health(h), attack(a), defense(d), magic(m) {}
    };
    
    // กำหนดคลาส Player
    class Player {
    private:
        int gold;
        vector<Equipment> inventory;
    
    public:
        Player(int initialGold) : gold(initialGold) {}
    
        int getGold() {
            return gold;
        }
    
        void updateGold(int amount) {
            gold += amount;
        }
    
        void equipItem(Equipment item) {
            inventory.push_back(item);  // เพิ่มไอเทมเข้าไปใน inventory ของผู้เล่น
        }
    };
    
    // กำหนดคลาส NPC 
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
//---------------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------------------//
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
        cout << "Attack+: " << ItemStats[i].attack << " ";
        cout << "Defense+: " << ItemStats[i].defense << " ";
        cout << "Heal+: " << ItemStats[i].health << " ";
        cout << "Magic+: " << ItemStats[i].magic << endl;
    }
}

void NPC::sellItemToPlayer(Player &player) { // ขายของให้
    if (hasShopped) {
        cout << "You have already purchased from " << npcname << ". You can't buy more this time!" << endl;
        return;
    }


    int choice;
    while (true) {
        shop();
        cout << "Your Gold: " << player.getGold() << endl;
        cout << "Enter item number (0 to exit): ";

        if (!(cin >> choice)) { // ตรวจสอบการป้อนข้อมูล
            cin.clear(); // ป้อนไม่ถูก clear
            cin.ignore(1000, '\n'); // ข้ามที่ป้อนผิด
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 0) break;

        if (choice > 0 && choice <= sellItem.size()) { // เลือก item ที่มี
            int index = choice - 1;
            if (player.getGold() >= ItemPrice[index]) { // check gold
                player.updateGold(-ItemPrice[index]); // ลบตัง
                player.equipItem(ItemStats[index]); // ใส่
                cout << "You bought " << sellItem[index] << "!\n";
                hasShopped = true ;
                return ;
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


 
// test
// ---------------------------------------------------------------------------------------------------------------------------------//
// ---------------------------------------------------------------------------------------------------------------------------------//
 int main() {
     srand(time(0));  // เพื่อให้การสุ่มแตกต่างทุกครั้ง
     Player player(50);  // สร้างผู้เล่นที่มีทอง 50

     // สุ่มเลือก NPC
     NPC npc = getRandomNPC();

     // เริ่มการขายของ
     npc.sellItemToPlayer(player);
    
     return 0;
 }
