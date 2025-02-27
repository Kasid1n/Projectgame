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
    int hpmax, hp, attack, defense, magic;};
Player player = {"Hero", 100, 100, 20, 10, 15};
Monster enemy = {"Ajarn Daeng", 500, 500, 15, 8, 12};

/// จำลอง ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int AttackChoice() {/*อันนี้ช้อยของเพลเยอร์*/
    int achoice = 0;
    cout << "You're Attacker\n";//turn+P
    while (achoice < 1 || achoice > 4) {
        cout << "Press 1. Attack Press 2.Skill Press 3. Ultimate Press 4.Heal \n"; //ขออยู่บรรทัดเดียวกัน
        cin >> achoice;
    }
    return achoice;}
int DefenseChoice() {/*อันนี้ช้อยของเพลเยอร์*/
    int dchoice = 0;
    cout << "You're The Defender\n";//turn+P
    while (dchoice < 1 || dchoice > 4) {
        cout << "Press 1.Block(against Attack) Press 2.Dodge(against Weapon SKill) Press 3.Parry(against ultimate) Press 4. Give up\n";
        cin >> dchoice;
    }
    return dchoice;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*เป็นระบบการต่อสู้ คำนวน*/
void battlesys(Player &A, Monster &B, int attack) {/*เพราะมอนกับผู้เล่นมันคนละคลาสกัน เลยต้องทำ2อัน*/ /*อันนี้สำหรับคนตีมอนกัน*/
    cout <<endl;
    int defense = rand() % 3 + 1;
    cout << A.name << " Hp: " << A.hp << endl;
    cout << B.name << " Hp: " << B.hp << endl;
    
    float dmg = 0, def = B.defense, temp, rdmg, hp;
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
            A.hp += hp;
            if (A.hp > A.hpmax) A.hp = A.hpmax;
            cout << A.name << " heals +" << hp << " Hp\n";
            return;
    }
    switch (defense) {/*อันนี้ 1-3ทำให้มัน coutเฉยๆว่าเลือกอะไรไป*/
        case 1:cout << B.name << " blocks!\n";break;
        case 2:cout << B.name << " dodges!\n";break;
        case 3:cout << B.name << " counters!\n";break;
        case 4:
            cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered==true) {/*รีเทินดาเมทของอันติ*/
        A.hp -= dmg;
    } else {/*โดนดาเมทธรรมดา*/
        B.hp -= dmg;
    }
    cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
    cout <<endl;
}

void battlesys(Monster &A, Player &B, int defense) {/*มอนกันคนตี*/ /*ด้านในเหมือนด้านบน แค่สลับinputเฉยๆ*/
    cout <<endl;
    int attack = rand() % 4 + 1;
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
            cout << A.name << " heals +" << hp << " Hp\n";
            return;
    }
    switch (defense) {
        case 1:cout << B.name << " blocks!\n";break;
        case 2:cout << B.name << " dodges!\n";break;
        case 3:cout << B.name << " counters!\n";break;
        case 4:
            cout << B.name << " gave up!\n";
            dmg = 9999999;
            break;
    }

    if (countered==true) {
        A.hp -= dmg;
    } else {
        B.hp -= dmg;
    }
    cout << A.name << " did " << dmg << " damage\n";
    cout << B.name << " lost " << dmg << " HP\n";
    cout <<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void battle(Player &player, Monster &enemy) {//ฟังก์ชั่นbattle ใช้วนจนhpฝ่ายนึงหมด
    int WR;
    cout << "Battle begins: " << player.name << " vs " << enemy.name << "!\n";

    int rcoin = rand() % 2, coin = 2;
    string scoin;
    
    do {/*สุ่มเหรียญ*/
        cout << "Pick head or tail: ";
        cin >> scoin;
        if (scoin == "head") coin = 0;
        else if (scoin == "tail") coin = 1;
        else cout << "Error. Try Again\n";
    } while (coin == 2);

    int round = 1;
    while (player.hp > 0 && enemy.hp > 0) {/*ถ้าเลือดหมดจะจบ*/
        cout<<endl;
        int aiattack = rand() % 4 + 1;/*มอนสุ่มช้อยตีกับกัน*/
        int aidefense = rand() % 3 + 1;
        int attack, defense;

        cout << "Round: " << round << endl;

        if (coin == rcoin) {//สำหรับเหรีียญตรง จะได้เป็นattackerก่อน
            attack = AttackChoice();
            battlesys(player/*คนตี*/, enemy/*คนกัน*/, attack/*ช้อยตีว่ากดตีแบบไยกัน*/);
            if (enemy.hp <= 0 || player.hp <= 0) break;
            defense = DefenseChoice();
            battlesys(enemy, player, defense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
        } else {//เหรียญไม่ตรง
            defense = DefenseChoice();
            battlesys(enemy, player, defense);
            if (enemy.hp <= 0 || player.hp <= 0) break;
            attack = AttackChoice();
            battlesys(player, enemy, attack);
            if (enemy.hp <= 0 || player.hp <= 0) break;
        }
        round++;
    }

    if (player.hp > 0){WR=1; cout << "\n" << player.name << " wins!\n";}/*เช็คว่าใครชนะ*/
    else {WR=2; cout << "\n" << enemy.name << " wins!\n";}
    cout<<endl;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main() {
    srand(time(0));
    battle(player, enemy);
    return 0;
}
