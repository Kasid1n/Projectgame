#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Stats {
private:
    int hp;
    int hpmax;
    int attack;
    int defense;
    int magic;
    int speed;

public:
    Stats(int hpmax, int attack, int defense, int magic, int speed)
        : hpmax(hpmax), attack(attack), defense(defense), magic(magic), speed(speed) {
        hp = hpmax;
    }

    void start() {
        hp = hpmax;
    }

    void showStats() const {
        cout << "HP: " << hp << "/" << hpmax << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Magic: " << magic << endl;
        cout << "Speed: " << speed << endl;
    }

    void increaseStat(int choice) {
        switch (choice) {
            case 1: hpmax += 10; hp = hpmax; break;
            case 2: attack += 2; break;
            case 3: defense += 2; break;
            case 4: magic += 2; break;
            case 5: speed += 2; break;
            default: cout << "Invalid choice!" << endl; break;
        }
    }
};

class Player {
private:
    int level;
    int xp;
    int xptolevelup;
    int statPoints;
    string name;
    Stats stats;

public:https://github.com/Kasid1n/Projectgame/tree/main
    Player(string playerName, int hpmax, int attack, int defense, int magic, int speed)
        : name(playerName), stats(hpmax, attack, defense, magic, speed) {
        level = 1;
        xp = 0;
        xptolevelup = 100;
        statPoints = 0;
    }

    void addXp(int xpGained) {
        xp += xpGained;
        while (xp >= xptolevelup) {
            levelUp();
        }
    }

    void showStatus() const {
        cout << name << " is level " << level << endl;
        cout << name << " XP: " << xp << "/" << xptolevelup << endl;
        cout << "Stat Points: " << statPoints << endl;
        stats.showStats();
    }

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

    void distributeStatPoints() {
        while (statPoints > 0) {
            cout << "You have " << statPoints << " stat points to allocate." << endl;
            cout << "1. HP\n2. Attack\n3. Defense\n4. Magic\n5. Speed\nChoose a stat to increase: ";
            int choice;
            cin >> choice;
            stats.increaseStat(choice);
            statPoints--;
        }
    }

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

int main() {
    srand(time(0));
    Player player("Hero", 100, 20, 10, 5, 15);
    player.showStatus();
    player.addXp(120);
    player.dead();
    return 0;
}
