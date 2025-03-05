#ifndef HUBTEST3_H 
#define HUBTEST3_H 
#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include<iomanip>
#include"test_4person.h"
#include"Qol.h"
using namespace std;
 



void showNPC(NPC shopNPC){
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                   SHOP                                     ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    //npcname pb
    if(shopNPC.npcname=="A"){doASCii("ascii_folder/npc1.txt");}
    if(shopNPC.npcname=="B"){doASCii("ascii_folder/npc2.txt");}
    if(shopNPC.npcname=="Secretmaster"){doASCii("ascii_folder/npc3.txt");}  
    cout << "════════════════════════════════════════════════════════════════════════════\n";
    //shopNPC.sellItemToPlayer(A);  
    //shopNPC.shop();//doloop?

    //system("cls");
}

void showshop(Player &player,NPC shopNPC){
    /*sellItemToPlayer code*/
    if(shopNPC.hasShopped == true){cout << "You have already purchased.";}
    int choice;
    while (true) {
        showNPC(shopNPC);
        shopNPC.shop();
        cout << "Your Gold: " << player.getGold() << endl;
        cout << "Enter item number (0 to exit): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        if (choice == 0) break;
        if (choice > 0 && choice <= shopNPC.sellItem.size()) {
            system("cls");
            showNPC(shopNPC);
            int index = choice - 1;
            if (player.getGold() >= shopNPC.ItemPrice[index]) {
                player.updateGold(-shopNPC.ItemPrice[index]);
                if (shopNPC.sellItem[index] == "Attack Potion") {
                    int atkBoost = rand() % 5 + 10;
                    player.stats.attack += atkBoost;
                    cout << "You used Attack Potion! Attack increased by " << atkBoost << "!\n";
                    enter();
                    system("cls");
                } 
                else if (shopNPC.sellItem[index] == "Heal Potion") {
                    int healAmount = rand() % 10 + 10;
                    player.stats.hpmax += healAmount;
                    cout << "You used Heal Potion! Max HP increased by " << healAmount << "!\n";
                    enter();
                    system("cls");
                } 
                else if (shopNPC.sellItem[index] == "Defense Potion") {
                    int defBoost = rand() % 5 + 10;
                    player.stats.defense += defBoost;
                    cout << "You used Defense Potion! Defense increased by " << defBoost << "!\n";
                    enter();
                    system("cls");
                } 
                else {
                    cout << shopNPC.sellItem[index]<<endl;
                    // Create a new Equipment object with the correct name and stats
                    Equipment newItem(shopNPC.sellItem[index], shopNPC.ItemStats[index].getStat()[0], shopNPC.ItemStats[index].getStat()[1], shopNPC.ItemStats[index].getStat()[2], shopNPC.ItemStats[index].getStat()[3]);
                    player.equipItem(newItem);
                    system("cls");                                                               //////// ลบได้ๆ
                    cout << "You bought " << shopNPC.sellItem[index] << "!\n";
                    doASCii("ascii_folder/" + shopNPC.sellItem[index] + ".txt");                ////////  ถ้าไม่ใช่แบบที่คิด ลบได้ๆ
                    enter();
                    system("cls");
                }
                //shopNPC.hasShopped = true;
                return;
            } else {
                cout << "Not enough gold!\n";
                enter();
                system("cls");
             
            }
        } else {
            cout << "Invalid choice!\n";
            enter();
            system("cls");
        }
    }

}
 
void showgold(Player A){
    cout << "Your Gold: " << A.getGold() << endl;
}
#endif

// int main(){
//     SetConsoleOutputCP(65001);
//     Player player("s", 100, 20, 10, 5);
//     player.addGold(100);
//     NPC shopNPC = getRandomNPC();
//     //showNPC(player);
//     showshop(player,shopNPC);
//     player.showInventory();
//     player.showEquipment();
    
    
// }
