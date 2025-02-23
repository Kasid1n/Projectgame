#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<string>

using namespace std;
//testnaja///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Player {
public:
    //int hp;
    int hp;
    int attack;
    int defense; 
    int magic;
    
};
Player Hero={100,20,10,15};
Player Mon={500,10,10,10};

//testnaja///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Battle {
    bool Block_on,Dodge_on,Parry_on;
    int maxHp,Hp,attack,magic,defense;

public:
    void getstat(Player &C);
    void Ready(Battle &E);
    void attacker();
    void defender();
    void Attack();
    void Heal();
    void Newturn();
    void Blocknaja();
    void Dodgenaja();
    void Parrynaja();
    int beAttack();
    int beWeapon();
    int beUlti();
    bool dead();
};

void Battle::getstat(Player &C){
    maxHp=C.hp;
    Hp=maxHp;
    attack=C.attack;
    magic=C.magic;
    defense=C.defense;

}

void Battle::attacker(Battle &opp) {
    int move;
    cout << "You're The Attacker\n";
    cout << "Press 1. Attack\nPress 2.Weapon Skill\nPress 3. Ultimate\nPress 4.Heal \n";
    while(true){
        cin >> move;
        switch (move) {
            case 1:
                cout << "You chose to Attack!\n";
                hero.Attack(1,opp);
                break;
            case 2:
                cout << "You used a Weapon SKill!\n";
                hero.Attack(2,opp);
                break;
            case 3:
                cout << "Ultimate Move Activated!\n";
                hero.Attack(3,opp);
                break;
            case 4:
                cout << "You Healed...\n";
                hero.Heal();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }
    }
}

void Battle::defender() {
    int move;
    cout << "You're The Defender\n";
    cout << "Press 1.Block(against Attack)\nPress 2.Dodge(against Weapon SKill)\nPress 3.Parry(against ultimate)\nPress 4. Give up\n";
    while(true){
        cin >> move;
        switch (move) {
            case 1:
                cout << "You Try to Block An Attack!\n";
                break;
            case 2:
                cout << "You try to Dodge!\n";
                break;
            case 3:
                cout << "You try to parry!\n";
                break;
            case 4:
                cout << "You gave up...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }
    }

}

void Battle::Attack(int x,Battle &opp){
    switch(x){
    case 1:return opp.beAttack();break;
    case 2:return opp.beWeapon();break;
    case 3:return opp.beUlti();break;
}
}

}

void Battle::Newturn(){Block_on=false;Dodge_on=false;Parry_on=false;}
void Battle::Blocknaja(){Block_on=true;}
void Battle::Dodgenaja(){Dodge_on=true;}
void Battle::Parrynaja(){Parry_on=true;}
void Battle::Heal(){Hp=maxHp+(Hp*((rand()%Hp)/100))}

int Battle::beAttack(int edmg ){
	int dmg=0,temp,randmg,per;

    per=rand()%2;
    randmg=(rand()%dmg)/100;
    if(per==0){edmg+=randmg;}
    if(per==1){edmg-=randmg;}

    temp=rand()%60+40;
    if(Block_on==true){
        edmg=edmg-(edmg*(temp/100));
    }
    
    if(edmg > defense){dmg = edmg-defense;}
    return dmg;	
}

int Battle::beWeapon(int edmg){/*จะมีติดสถานะแต่ยังไม่ได้ทำ*/
    int dmg=0,temp;
    temp=rand()%50+1;
    if(Dodge_on==true){dmg=0;}
    edmg=edmg+(edmg*(temp/100));
    
    if(edmg > defense){dmg = edmg-defense;}
    return dmg;	
}

int Battle::beUlti(int edmg){/*ยังไม่เสร็จนะจ๊ะ*/
    int dmg,temp,randmg,per;
    if(Parry_on==true){
        beAttack(ศัตรู);
        return dmg=0;
    }
    dmg=edmg*rand()%3+1;
    return dmg;	
}

bool Battle::dead(){
    if(hp<=0)return true;
    else return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Player Man("Jed");

void battlesystem() {

    srand(time(0));
    int rcoin = rand() % 2, coin = 2;
    string scoin;
    
    // ให้ผู้เล่นเลือก หัว หรือ ก้อย
    do {
        cout << "Pick head or tail: ";
        cin >> scoin;
        if (scoin == "head") coin = 0;
        else if (scoin == "tail") coin = 1;
        else cout << "Error. Try Again\n";
    } while (coin == 2);

    // เริ่มการต่อสู้
    Battle hero;
    Battle opp;
    int round = 1;

    while (true) {
        cout << "Round: " << round << endl;
        if (coin == rcoin) {
            hero.attacker();

            hero.defender();
        } else {
            hero.defender();
            hero.attacker();
        }
        round++;
        cout << "------------------\n";
    }

    return 0;
}
