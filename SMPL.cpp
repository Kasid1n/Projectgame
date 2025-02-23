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

    void setLevel(int newLevel) {
        level = newLevel;
    }

    void showStatus() const {
        cout << name << " is level " << level << endl;
        cout << "XP: " << xp << "/" << xptolevelup << endl;
        cout << "Gold: " << gold << endl;
        stats.showStats();
    }

    int getLevel() const {
        return level;
    }
};

class Monster {
private:
    string name;
    Stats stats;

public:
    Monster(string monsterName, int hpmax, int attack, int defense, int magic, int playerLevel)
        : name(monsterName), stats(hpmax + playerLevel * 10, attack + playerLevel * 2, defense + playerLevel, magic + playerLevel / 2) {}

    void showStatus() const {
        cout << "Monster: " << name << endl;
        stats.showStats();
    }
};

class BossMonster {
private:
    string name;
    Stats stats;

public:
    BossMonster(string bossName, int hpmax, int attack, int defense, int magic)
        : name(bossName), stats(hpmax, attack, defense, magic) {}

    void showStatus() const {
        cout << "BOSS MONSTER: " << name << endl;
        stats.showStats();
    }
};

class MonsterFactory {
private:
    struct MonsterData {
        string name;
        int hpmax, attack, defense, magic;
        int minLevel, maxLevel;
    };

    static const vector<MonsterData> monsterTable;

public:
    static Monster createMonster(int level) {
        vector<const MonsterData*> validMonsters;
        for (const auto& data : monsterTable) {
            if (level >= data.minLevel && level <= data.maxLevel) {
                validMonsters.push_back(&data);
            }
        }
        if (validMonsters.empty()) {
            return Monster("unknow_mon", 1, 1, 1, 1, level);
        }
        int index = rand() % validMonsters.size();
        const auto& data = *validMonsters[index];
        return Monster(data.name, data.hpmax, data.attack, data.defense, data.magic, level);
    }
};

const vector<MonsterFactory::MonsterData> MonsterFactory::monsterTable = {
    {"Chest", 1, 1, 1, 1, 1, 1},
    {"Harpy", 2, 2, 2, 2, 2, 1},
    {"Hound", 3, 3, 3, 3, 3, 2},
    {"Skeleton", 4, 4, 4, 4, 4, 2},
    {"Spider", 5, 5, 5, 5, 5, 3},
    {"Warrior-Skeleton", 6, 6, 6, 6, 6, 3}
};

class BossFactory {
private:
    struct BossData {
        string name;
        int hpmax, attack, defense, magic;
    };

    static const vector<BossData> bossTable;

public:
    static BossMonster createBoss(const string& bossName) {
        for (const auto& boss : bossTable) {
            if (boss.name == bossName) {
                return BossMonster(boss.name, boss.hpmax, boss.attack, boss.defense, boss.magic);
            }
        }
        return BossMonster("Unknown Boss", 0, 0, 0, 0);
    }
};

const vector<BossFactory::BossData> BossFactory::bossTable = {
    {"ApocalypseSouls", 111, 111, 111, 111},
    {"Dragon", 222, 222, 222, 222},
    {"addboss", 333, 333, 333, 333}
};

int main() {
    srand(time(0));
    
    Player player("Hero", 100, 20, 10, 5);
    int chosenLevel;
    cout << "Enter player level: ";
    cin >> chosenLevel;
    player.setLevel(chosenLevel);
    player.showStatus();

    cout << "(1) random monster (2) a boss";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        Monster randomMonster = MonsterFactory::createMonster(player.getLevel());
        randomMonster.showStatus();
    } else if (choice == 2) {
        string chosenBoss;
        cout << "Enter boss name: ";
        getline(cin, chosenBoss);
        BossMonster boss = BossFactory::createBoss(chosenBoss);
        boss.showStatus();
    }
    
    return 0;
}
