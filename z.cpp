#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>

using namespace std;


class Equipment {
    int hpmax;
    int atk;
    int def;
    int magic;
public:
    Equipment(int h, int a, int d, int m);
    vector<int> getStat();
};

Equipment::Equipment(int h, int a, int d, int m) {
    hpmax = h;
    atk = a;
    def = d;
    magic = m;
}

vector<int> Equipment::getStat() {
    vector<int> stats = {hpmax, atk, def, magic};
    return stats;
}

class Stats {
    int hp;
    int hpmax;
    int attack;
    int defense; 
    int magic;
    vector<Equipment*> equipmentList;

public:
    Stats(int h, int a, int d, int m);
    void start(); 
    void equip(Equipment* eq); 
    void unequip(int index); 
    void printStats(); 
    int getEquipmentCount();
};
int Stats::getEquipmentCount() {
    return equipmentList.size();
}
Stats::Stats(int h, int a, int d, int m) {
    hpmax = h;
    hp = h; // Initialize hp to max at the start
    attack = a;
    defense = d;
    magic = m;
}

void Stats::start() {
    hp = hpmax; 
}

void Stats::equip(Equipment* eq) {
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

    if (hp > hpmax) {
        hp = hpmax; 
    }
}

void Stats::unequip(int index) {
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

    if (hp > hpmax) {
        hp = hpmax; 
    }
}

void Stats::printStats() {
    cout << "HP: " << hp << "/" << hpmax << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Magic: " << magic << endl;
}

int main() {
    // Create some Equipment items
    Equipment sword(0, 10, 0, 5);
    Equipment shield(0, 0, 10, 0);
    Equipment axe(0, 15, 0, 0);
    Equipment bow(0, 10, 0, 5);

    // Create a Stats object for the character
    Stats hero(100, 20, 10, 5);

    // Print initial stats
    cout << "Initial Stats:\n";
    hero.printStats();

    // Equip items to the hero
    cout << "\nEquipping items...\n";
    char eq;	
    while (true) {
        cout << "Enter your choice: ";
        cin >> eq;

        if (eq == '1') {
            hero.equip(&sword);
        } else if (eq == '2') {
            hero.equip(&shield);
        } else if (eq == '3') {
            hero.equip(&axe);
        } else if (eq == '4') {
            hero.equip(&bow);
        } else if (eq == 'q') {
            break; // Stop the loop when the user chooses to quit
        } else {
            cout << "Invalid option, please try again.\n";
        }

        hero.printStats();
        if (eq == 'q') {
            break;
        }
    }
    hero.printStats();

    // Unequip the first item (sword)
    cout << "\nUnequipping sword...\n";
    char unequipChoice;
    while (true) {
        cout << "\nDo you want to unequip an item? (y/n): ";
        cin >> unequipChoice;

        if (unequipChoice == 'y') {
            int index;
            cout << "Enter the index of the item to unequip (0 to " << hero.getEquipmentCount() - 1 << "): ";
            cin >> index;
            hero.unequip(index);
            hero.printStats();
        } else if (unequipChoice == 'n') {
            break;
        } else {
            cout << "Invalid choice. Please enter 'y' to unequip or 'n' to stop.\n";
        }
    }
    hero.printStats();

    return 0;
}
