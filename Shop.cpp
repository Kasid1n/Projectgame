#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;

class NPC {
    string npcname;
    vector<string> sellItem;
    vector<int> ItemPrice;

public:
    static string Randname() {
        vector<string> npcName = {"A", "B", "C"};
        return npcName[rand() % npcName.size()];
    }

    NPC() {
        npcname = Randname();
        sellItem = {"Attack Potion", "Magic Potion", "Defense Shield", "Speed"};
        ItemPrice = {15, 15, 20, 20};  // ราคาอัพตามเลเวล
    }

    void shop() {
        cout << npcname << "'s shop" << endl;
        for (int i = 0; i < sellItem.size(); i++) {
            cout << i + 1 << " " << sellItem[i] << " " << ItemPrice[i] << endl;
        }
    }

    void sellItemToPlayer(int &playerGold, int &attack, int &magic, int &defense, int &speed) {
        int choice;
        while (true) {
            shop();
            cout << "You're Gold is " << playerGold << endl;
            cout << "Enter the number of item or Press *0* to exit: ";
            cin >> choice;
            if (choice == 0) {
                break;
            }
            else if (choice > 0 && choice <= sellItem.size()) {
                int Index = choice - 1;
                if (playerGold >= ItemPrice[Index]) {
                    playerGold -= ItemPrice[Index];
                    cout << "You bought " << sellItem[Index] << endl;
                    cout << "Gold: " << playerGold << endl;

                    if (Index == 0) {
                        attack += 5;  
                    } 
                    else if (Index == 1) {
                        magic += 5;  
                    } 
                    else if (Index == 2) {
                        defense += 5;  
                    } 
                    else if (Index == 3) {
                        speed += 5;  
                    }
                } else {
                    cout << "You don't have enough gold!" << endl;
                }
            } 
            else {
                cout << "Invalid choice. Try again!" << endl;
            }
        }
    }
};
/* test
int main() {
    NPC npc("L") ;
    npc.shop() ;
 
}
 */
   