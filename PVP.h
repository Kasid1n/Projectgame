#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

/// จำลอง //////////////////////////////////////
class Player {
public:
    string name;
    int hpmax, hp, attack, defense, magic;};
class Monster {
public:
    string name;
    int hpmax, hp, attack, defense, magic};
Player player = {"Hero", 100, 100, 20, 10, 15};
Monster enemy = {"Ajarn Daeng", 500, 500, 15, 8, 12};

int AttackChoice() {
    int achoice = 0;
    cout << "You're Attacker\n";
    while (achoice < 1 || achoice > 4) {
        cout << "Press 1. Attack\nPress 2.Skill\nPress 3. Ultimate\nPress 4.Heal \n";
        cin >> achoice;
    }
    return achoice;}
int DefenseChoice() {
    int dchoice = 0;
    cout << "You're The Defender\n";
    while (dchoice < 1 || dchoice > 4) {
        cout << "Press 1.Block(against Attack)\nPress 2.Dodge(against Weapon SKill)\nPress 3.Parry(against ultimate)\nPress 4. Give up\n";
        cin >> dchoice;
    }
    return dchoice;}
/// จำลอง //////////////////////////////////////


void battlesys(Player &A, Monster &B, int attack, int defense) {
    cout << A.name << " Hp: " << A.hp << endl;
    cout << B.name << " Hp: " << B.hp << endl;
    
    float dmg = 0, def = B.defense, temp, rdmg, hp;
    bool countered = false;

    switch (attack) {
        case 1:
            cout << A.name << " attacks!\n";
            dmg = A.attack;
            rdmg = rand() % 31 - 15;
            dmg += dmg * (rdmg / 100);
            break;
        case 2:
            cout << A.name << " uses skill!\n";
            dmg = A.magic;
            def = 0;
            temp = rand() % 3 + 1;
            if (temp == 1) dmg = 0;
            break;
        case 3:
            cout << A.name << " uses ultimate!\n";
            dmg = (A.attack + A.magic) * 2;
            break;
        case 4:
            temp = rand() % 40 + 1;
            hp = A.hpmax * ((30 + temp) / 100.0);
            A.hp += hp;
            if (A.hp > A.hpmax) A.hp = A.hpmax;
            cout << A.name << " heals +" << hp << " Hp\n";
            return;
    }

    switch (defense) {
        case 1:
            cout << B.name << " blocks!\n";
            temp = rand() % 30 + 1;
            dmg -= dmg * ((50 + temp) / 100);
            break;
        case 2:
            cout << B.name << " dodges!\n";
            temp = rand() % 4 + 1;
            if (temp != 1) dmg = 0;
            break;
        case 3:
            cout << B.name << " counters!\n";
            countered = true;
            break;
        case 4:
            cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered) {
        A.hp -= dmg;
    } else {
        B.hp -= dmg;
    }

    cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
}



void battlesys(Monster &A, Player &B, int attack, int defense) {
    cout<<endl;
    cout << A.name << " Hp: " << A.hp << endl;
    cout << B.name << " Hp: " << B.hp << endl;
    
    float dmg = 0, def = B.defense, temp, rdmg, hp;
    bool countered = false;

    switch (attack) {
        case 1:
            cout << A.name << " attacks!\n";
            dmg = A.attack;
            rdmg = rand() % 31 - 15;
            dmg += dmg * (rdmg / 100);
            break;
        case 2:
            cout << A.name << " uses skill!\n";
            dmg = A.magic;
            def = 0;
            temp = rand() % 3 + 1;
            if (temp == 1) dmg = 0;
            break;
        case 3:
            cout << A.name << " uses ultimate!\n";
            dmg = (A.attack + A.magic) * 2;
            break;
        case 4:
            temp = rand() % 40 + 1;
            hp = A.hpmax * ((30 + temp) / 100.0);
            A.hp += hp;
            if (A.hp > A.hpmax) A.hp = A.hpmax;
            cout << A.name << " heals +" << hp << " Hp\n";
            return;
    }

    switch (defense) {
        case 1:
            cout << B.name << " blocks!\n";
            temp = rand() % 30 + 1;
            dmg -= dmg * ((50 + temp) / 100);
            break;
        case 2:
            cout << B.name << " dodges!\n";
            temp = rand() % 4 + 1;
            if (temp != 1) dmg = 0;
            break;
        case 3:
            cout << B.name << " counters!\n";
            countered = true;
            break;
        case 4:
            cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered) {
        A.hp -= dmg;
    } else {
        B.hp -= dmg;
    }

    cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
    cout<<endl;
}


void battle(Player &player, Monster &enemy) {
    int WR;
    cout << "Battle begins: " << player.name << " vs " << enemy.name << "!\n";

    int rcoin = rand() % 2, coin = 2;
    string scoin;
    
    do {
        cout << "Pick head or tail: ";
        cin >> scoin;
        if (scoin == "head") coin = 0;
        else if (scoin == "tail") coin = 1;
        else cout << "Error. Try Again\n";
    } while (coin == 2);

    int round = 1;
    while (player.hp > 0 && enemy.hp > 0) {
        cout<<endl;
        int aiattack = rand() % 4 + 1;
        int aidefense = rand() % 4 + 1;
        int attack, defense;

        cout << "Round: " << round << endl;

        if (coin == rcoin) {
            attack = AttackChoice();
            battlesys(player, enemy, attack, aidefense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
            defense = DefenseChoice();
            battlesys(enemy, player, aiattack, defense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
        } else {
            defense = DefenseChoice();
            battlesys(enemy, player, aiattack, defense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
            attack = AttackChoice();
            battlesys(player, enemy, attack, aidefense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
        }
        round++;
    }

    if (player.hp > 0){WR=1; cout << "\n" << player.name << " wins!\n";}
    else {WR=2; cout << "\n" << enemy.name << " wins!\n";}
    cout<<endl;}



int main() {
    srand(time(0));
    battle(player, enemy);
    return 0;
}
