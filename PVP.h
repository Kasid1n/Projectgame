{///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class Battle {
    bool Block_on,Dodge_on,Parry_on;

public:
    void attacker();
    void defender();
    void Newturn();
    void Blocknaja();
    void Dodgenaja();
    void Parrynaja();
    int beAttack();
    int beWeapon();
    int beUlti();
    bool dead();
};

void Battle::attacker() {
    int move;
    cout << "You're The Attacker\n";
    cout << "Press 1. Attack\nPress 2.Weapon Skill\nPress 3. Ultimate\nPress 4.Leave \n";
    while(true){
        cin >> move;
        switch (move) {
            case 1:
                cout << "You chose to Attack!\n";
                break;
            case 2:
                cout << "You used a Weapon SKill!\n";
                break;
            case 3:
                cout << "Ultimate Move Activated!\n";
                break;
            case 4:
                cout << "You leave...\n";
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

void Battle::Newturn(){Block_on=false;Dodge_on=false;Parry_on=false;}
void Battle::Blocknaja(){Block_on=true;}
void Battle::Dodgenaja(){Dodge_on=true;}
void Battle::Parrynaja(){Parry_on=true;}

int Battle::beAttack(int edmg ){
	int dmg,temp,randmg,per;

    per=rand()%2;
    randmg=(rand()%dmg)/100
    if(per==0){edmg+=randmg;}
    if(per==1){edmg-+randmg;}

    temp=rand()%60+40;
    if(Block_on=true;){
        edmg=edmg-(edmg*(temp/100));
    }
    
    if(edmg > defense){dmg = edmg-defense;}
    return dmg;	
}

int Battle::beWeapon(int edmg){/*จะมีติดสถานะแต่ยังไม่ได้ทำ*/
    int dmg,temp;
    temp=rand()%50+1;
    if(Dodge_on=true;){dmg=0;}
    edmg=edmg+(edmg*(temp/100));
    
    
    if(edmg > defense){dmg = edmg-defense;}
    return dmg;	
}

int Battle::beUlti(int edmg){/*ยังไม่เสร็จนะจ๊ะ*/
    int dmg,temp,randmg,per;
    if(Parry_on=true){
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
}


//class คิดว่าเครละ แต่main (func battle)ยังไม่เสด
int main() {

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
    Battle battle;
    int round = 1;

    while (true) {
        cout << "Round: " << round << endl;
        if (coin == rcoin) {
            battle.attacker();
            battle.defender();
        } else {
            battle.defender();
            battle.attacker();
        }
        if ()
        round++;
        cout << "------------------\n";
    }

    return 0;
}
