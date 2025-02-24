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

public:
    Stats(int hpmax, int attack, int defense, int magic)
        : hpmax(hpmax), attack(attack), defense(defense), magic(magic) {
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
    }

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
private:
    int level;
    int xp;
    int xptolevelup;
    int statPoints;
    string name;
    Stats stats;
    int gold;

public:
    Player(string playerName, int hpmax, int attack, int defense, int magic)
        : name(playerName), stats(hpmax, attack, defense, magic), gold(0) {
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

    void addGold(int goldGained) {
        gold += goldGained;
    }

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
            cout << "You have " << statPoints << " stat points to distribute." << endl;
            cout << "1. HP\n2. Attack\n3. Defense\n4. Magic\nChoose a stat to increase: ";
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

class Monster {
private:
    string name;
    int level;
    Stats stats;
    int goldDrop;
    int xpDrop;

public:
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

class MonsterFactory {
public:
    static Monster randMonster(int level) {
        int randNum = rand() % 100;
        if (level >= 10 && randNum >= 70) return Monster("Chest", level, 100 + level * 10, 20 + level * 2, 12 + level, 8 + level / 2, 200, 300);
        if (level >= 7 && randNum >= 40) return Monster("Harpy.", level, 80 + level * 8, 15 + level * 2, 10 + level, 6 + level / 2, 100, 150);
        if (level >= 6 && randNum >= 20) return Monster("Hound", level, 60 + level * 6, 10 + level * 2, 8 + level, 4 + level / 2, 50, 80);
        if (level >= 5 && randNum >= 10) return Monster("Warrior-Skeleton", level, 60 + level * 6, 10 + level * 2, 8 + level, 4 + level / 2, 50, 80);
        return Monster("Skeleton", level, 1 + level * 5, 1 + level * 1, 6 + level, 1 + level / 1, 1, 1);
    }

    static Monster bossMonster1() {
        static Monster fixedMonster("ApocalypseSoulsBoss", 11, 111, 11, 11, 11, 111, 111);
        return fixedMonster;
    }
    static Monster bossMonster2() {
        static Monster fixedMonster("Dragonlord", 22, 222, 22, 22, 22, 222, 222);
        return fixedMonster;
    }
};

int main() {
    srand(time(0));
    
    string playerName;
    cout << "Enter player name: ";
    getline(cin, playerName);
    
    Player player(playerName, 100, 20, 10, 5);
    player.showStatus();
    player.addXp(10000);
    player.dead();

    int playerLevel = player.getLevel();
    Monster randomMon = MonsterFactory::randMonster(playerLevel);
    Monster fixedMon = MonsterFactory::bossMonster2();

    randomMon.showStatus();
    fixedMon.showStatus();

    player.addGold(randomMon.getGoldDrop());
    player.addXp(randomMon.getXpDrop());
    player.showStatus();

    return 0;
}
