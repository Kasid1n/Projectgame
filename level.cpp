/*
 level(xp)
 addlevel
 xptoup
 levelup ---->> statup++ ---->>enemy++
 ***dead*** re ?? 
 -ดู class -
 ---randdom name ..
*/ 
#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std ;
class Player {
private:
    int level;
    int xp;
    int xptolevelup;
    string name ;
    int hp;
    int hpmax;
    int attack;
    int defense; 
    int magic;
    int speed;


public:
    Player(string Playername) {
        name = Playername ;
        level = 1;
        xp = 0;
        xptolevelup = 100 ;

        
    }

    void addxp(int xpgained) {
        xp += xpgained;
        while (xp >= xptolevelup) {   
            levelup();
        }
    }

    
    void showstatus() const {
        cout << name<< " is level " << level << endl;
        cout << name<<" xp is " << xp << endl;
    }

private:
    
    void levelup() {
        level++;
        xp -= xptolevelup;
        xptolevelup += (50 * level)+(rand()%99+1) ;
        cout <<name<<" reached level " << level << "!!!!" << endl;
        showstatus();
    }

public:
    
    void dead() {
        level = 1;
        xp = 0;
        xptolevelup = 100;
        showstatus();
    }
};

/*
int main() {
    string name ;
    cout<<"Please enter your name :" ;
    getline(cin,name) ;
    Player player(name) ;
    player.addxp(3000);   
   

    player.dead();       

    return 0;
}
*/



