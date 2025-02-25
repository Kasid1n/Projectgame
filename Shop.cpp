#include "shop.h"
#include <cstdlib>  // สำหรับ rand()
#include <ctime>    // สำหรับ time()

NPC::NPC(string name) {
    npcname = name;
    if (npcname == "A") {       // ขายดาบ
        sellItem = {"Axe", "SuperAxe", "Sword"};
        ItemPrice = {15, 25, 30};
        ItemStats = {Equipment(0, 5, 0, 0), Equipment(0, 8, 0, 0), Equipment(0, 10, 0, 0, 0)};
    }
    else if (npcname == "B") {   //ขายโล่
        sellItem = {"Shield", "Better Shield"};   
        ItemPrice = {20, 30};
        ItemStats = {Equipment(0, 0, 5, 0), Equipment(0, 0, 8, 0)};
    }
    else if (npcname == "Secretmaster") {  // สุ่มของ
        vector<string> secretItems = {"Attack Potion", "Heal Potion", "Defense Potion"};
        int randIndex = rand() % 3;
        sellItem.push_back(secretItems[randIndex]);
        int price = rand() % 21 + 10;
        ItemPrice.push_back(price);

        if (secretItems[randIndex] == "Attack Potion") {
            ItemStats.push_back(Equipment(0, 5, 0, 0));
        } else if (secretItems[randIndex] == "Heal Potion") {
            ItemStats.push_back(Equipment(10, 0, 0, 5));
        } else {
            ItemStats.push_back(Equipment(0, 0, 5, 0));
        }
    }
}

void NPC::shop() {   // ขายบอกว่าเจอตัวไหน
    cout << npcname << "'s Shop\n";
    for (size_t i = 0; i < sellItem.size(); i++) {
        cout << i + 1 << ". " << sellItem[i] << " (Price: " << ItemPrice[i] << ")\n";
    }
}

void NPC::sellItemToPlayer(Player &player) {   //ขายของให้ผู้เล่น
    int choice;
    while (true) {
        shop();
        cout << "Your Gold: " << player.getGold() << endl;
        cout << "Enter item number (0 to exit): ";
        cin >> choice;
        if (choice == 0) break;

        if (choice > 0 && choice <= sellItem.size()) {
            int index = choice - 1;
            if (player.getGold() >= ItemPrice[index]) {
                player.updateGold(-ItemPrice[index]);
                player.equipItem(ItemStats[index]);
                cout << "You bought " << sellItem[index] << "!\n";
            } else {
                cout << "Not enough gold!\n";
            }
        } else {
            cout << "Invalid choice!\n";
        }
    }
}

// ฟังก์ชันสุ่ม NPC
NPC getRandomNPC() {
    srand(time(0)); // ตั้งค่า seed สำหรับการสุ่ม
    vector<string> npcNames = {"A", "B", "Secretmaster"};
    int randomIndex = rand() % npcNames.size();
    return NPC(npcNames[randomIndex]);
}
