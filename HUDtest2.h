#ifndef HUDTEST2.H
#define HUDTEST2.H

#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include<iomanip>

#include"Qol.h"
using namespace std;
#include"HUDtest3.h"

//Screen Output
void sHUD();//Title
void mon();
void hero();
 //entity show
void showgaveup(string);
void showwin();
void showlose();
void showAT();
void showDE();
void showmon();
 


void sHUD(){
    SetConsoleTextAttribute(h,4);//Text Color Red
    string filetxt="ascii_folder/text.txt";//Game Title
    doASCii(filetxt);
}

void mon(Monster &B){
    SetConsoleTextAttribute(h,4);
    cout<<"                       =====================================================\n";
    cout<<"                       "<< B.name << " | HP : "<< B.hp << "/" << B.hpmax <<"\n";
    cout<<"                       =====================================================\n";

    if(B.name=="Spider"){doASCii("ascii_folder/Spider.txt");}
    if(B.name=="Harpy"){doASCii("ascii_folder/Harpy.txt");}
    if(B.name=="Hound"){doASCii("ascii_folder/Hound.txt");}    
    if(B.name=="Warrior-Skeleton"){doASCii("ascii_folder/Warrior-Skeleton.txt");} 
    if(B.name=="Skeleton"){doASCii("ascii_folder/Skeleton.txt");}

    if(B.name=="ApocalypseSoulsBoss"){
        SetConsoleTextAttribute(h,14);
        doASCii("ascii_folder/ApocalypseSoulsBoss.txt");}
    if(B.name=="Dragonlord"){SetConsoleTextAttribute(h,14);
        doASCii("ascii_folder/DragonBoss.txt");}
    //doASCii("ascii_folder/Skeleton.txt");

}
void hero(Player &A){
    SetConsoleTextAttribute(h,2);
    cout<<"=====================================================\n";
    cout<< A.name << " | HP : "<< A.hp << "/" << A.hpmax <<"\n";
    cout<<"=====================================================\n";
}
  


/*void showgaveup(string x){
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             YOU GAVE UP                                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n"; 
    SetConsoleTextAttribute(h,4);//Red
    mon();
    string filetxt=x;
    doASCii(filetxt);
    hero();
    
    showlose ();
    
}*/

void showwin(){ 
    SetConsoleTextAttribute(h,15);//white
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                YOU WIN!                                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    
}

void showlose (){ 
    SetConsoleTextAttribute(h,15);//white
    cout << endl;
    doASCii("ascii_folder/LOSE");
    cout << endl;
    
}


void showAT(Player &A, Monster &B){
    SetConsoleTextAttribute(h,15);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO ATTACK                                 ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    mon(B);
    hero(A);
    int playerAttackChoice = AttackChoice();
    switch (playerAttackChoice) {
        case 1:
            cout << "You chose to Attack!\n";
            break;
        case 2:
            cout << "You chose to use Skill!\n";
            break;
        case 3:
            cout << "You chose to use Ultimate!\n";
            break;
        case 4:
            cout << "You chose to Heal\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
    }
    
    t = battlesys(A, B, playerAttackChoice);//float return pvp
    
    system("cls");
    SetConsoleTextAttribute(h,15);
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO ATTACK                                 ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    
    
    mon(B);
    hero(A);
    SetConsoleTextAttribute(h,4);
    switch (t.d) {/*อันนี้ 1-3ทำให้มัน coutเฉยๆว่าเลือกอะไรไป*/
        case 1:cout << B.name << " blocks!\n";break;
        case 2:cout << B.name << " dodges!\n";break;
        case 3:cout << B.name << " counters!\n";break;
        case 4:
            cout << B.name << " gave up!\n";
            break;
    }
    SetConsoleTextAttribute(h,2);
    if(playerAttackChoice==4){cout << A.name << " heals +" << t.h << " Hp\n";}
    else 
    {cout << A.name << " did " << t.D << " damage\n";
    SetConsoleTextAttribute(h,4);
    cout << B.name << " lost " << t.D << " HP\n";}
    enter();
    system("cls");
    
   // Sleep(900);
}

void showDE(Player &A, Monster &B){
    SetConsoleTextAttribute(h,15);
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO DEFENSE                                ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    mon(B);
    hero(A);

    int playerDefenseChoice = DefenseChoice();
    switch (playerDefenseChoice) {
        case 1:
            cout << "You chose to Block!\n";
            break;
        case 2:
            cout << "You chose to Dodge!\n";
            break;
        case 3:
            cout << "You chose to Parry!\n";
            break;
        case 4:
            cout << "You chose to Give up\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
    }
    t = battlesys(B, A, playerDefenseChoice); //float return pvp
   
    system("cls");
    SetConsoleTextAttribute(h,15);
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO DEFENSE                                ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    mon(B);
    hero(A);
    SetConsoleTextAttribute(h,4);
    switch (t.d) {/*อันนี้ 1-3ทำให้มัน coutเฉยๆว่าเลือกอะไรไป*/
        case 1:cout << B.name << " Attack!\n";break;
        case 2:cout << B.name << " Use Skill!\n";break;
        case 3:cout << B.name << " Use Ultimate!\n";break;
        /*case 4:
            cout << B.name << " Heal!\n";
            break;*/
    }
    SetConsoleTextAttribute(h,4);
    if(t.d==4){cout << B.name << " heals +" << t.h << " Hp\n";}
    else
    SetConsoleTextAttribute(h,4); 
    cout << B.name << " did " << t.D <<" damage\n"; 
    SetConsoleTextAttribute(h,2);
    cout << A.name << " lost " << t.D << " HP\n";
    enter();
    system("cls");
}

void showbattle(Player &player, Monster &enemy){ //เหลือใครเริ่มก่อน
    int r =rand()%2;
    enemy.getGoldDrop();
    enemy.getXpDrop(); 
    if(r==0){
    while (player.hp > 0 && enemy.hp > 0){
        showDE(player,enemy);
        if (enemy.hp <= 0 || player.hp <= 0){ 
            if (enemy.hp <= 0){
                showwin();
                cout << "gold +" << enemy.getGoldDrop() << " xp +"<< enemy.getXpDrop()<< endl;
                player.addGold(enemy.getGoldDrop());
                player.addXp(enemy.getXpDrop());
                cout << "your gold = " << player.gold << " your xp = "<< player.xp<< endl;
                enter();
            }
            
        
        break;}
        showAT(player,enemy);
        if (enemy.hp <= 0 || player.hp <= 0){
            if (enemy.hp <= 0){
                showwin();
                cout << "gold +" << enemy.getGoldDrop() << " xp +"<< enemy.getXpDrop()<< endl;
                player.addGold(enemy.getGoldDrop());
                player.addXp(enemy.getXpDrop());
                cout << "your gold = " << player.gold << " your xp = "<< player.xp<< endl;
                enter();
            }
        break;}
    }}
    else{
        while (player.hp > 0 && enemy.hp > 0){
            showAT(player,enemy);
            if (enemy.hp <= 0 || player.hp <= 0){
                if (enemy.hp <= 0){
                    showwin();
                    cout << "gold +" << enemy.getGoldDrop() << " xp +"<< enemy.getXpDrop()<< endl;
                    player.addGold(enemy.getGoldDrop());
                    player.addXp(enemy.getXpDrop());
                    cout << "your gold = " << player.gold << " your xp = "<< player.xp<< endl;
                    enter();
                }
            break;}
            showDE(player,enemy);
            if (enemy.hp <= 0 || player.hp <= 0) {
                if (enemy.hp <= 0){
                    showwin();
                    cout << "gold +" << enemy.getGoldDrop() << " xp +"<< enemy.getXpDrop() << endl;
                    player.addGold(enemy.getGoldDrop());
                    player.addXp(enemy.getXpDrop());
                    cout << "your gold = " << player.gold << " your xp = " << player.xp << endl;
                    enter();
                }
            break;}
        }}

}

void showmon(Monster &B){
    SetConsoleTextAttribute(h,15);
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                         !!!  FOUND MONSTER  !!!                            ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    SetConsoleTextAttribute(h,4);
    if(B.name=="Spider"){doASCii("ascii_folder/Spider.txt");}
    if(B.name=="Harpy"){doASCii("ascii_folder/Harpy.txt");}
    if(B.name=="Hound"){doASCii("ascii_folder/Hound.txt");}    
    if(B.name=="Warrior-Skeleton"){doASCii("ascii_folder/Warrior-Skeleton.txt");} 
    if(B.name=="Skeleton"){doASCii("ascii_folder/Skeleton.txt");}

    if(B.name=="ApocalypseSoulsBoss"){
        SetConsoleTextAttribute(h,14);
        doASCii("ascii_folder/ApocalypseSoulsBoss.txt");}
    if(B.name=="Dragonlord"){SetConsoleTextAttribute(h,14);
        doASCii("ascii_folder/DragonBoss.txt");}
    SetConsoleTextAttribute(h,15);
    cout << "═════════════════════════════════════════════════════════════════════════════\n";
    SetConsoleTextAttribute(h,4);
    cout << "                             " <<B.name << endl;
    SetConsoleTextAttribute(h,15);
    cout << "═════════════════════════════════════════════════════════════════════════════\n";
    enter();
    system("cls");
    
}

#endif//hudtest2

/*int main(){
    SetConsoleOutputCP(65001);// Set CMD to UTF-8
    system("cls");//Clear Screen
    sHUD();
    while (true) {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
            break;
        }
        Sleep(10);  // Reduce CPU usage
    }
    //system("cls"); 
    //doSlowF("ascii_folder/Story1.txt",120);
    cout<<"Press Spacebar to continue.";  
    while (true) {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
            break;
        }
        Sleep(10);  // Reduce CPU usage
    }    
    system("cls");

    //showgaveup ("ascii_folder/Skeleton.txt");
    //showwin();
    //showlose();
    //mon(enemy);
    //hero(player);
    //showAT(player,enemy);

    while (true){
    
    string playerName;
    getline(cin, playerName); //ตั้งชื่อ
    Player player(playerName, 100, 20, 10, 5);
    Player s("s", 100, 20, 10, 5);
    //player.showStatus();
    //player.addXp(10); 
    //int playerLevel = player.getLevel();
    Monster randomMon = MonsterFactory::randMonster(1);
    Monster fixedMon = MonsterFactory::bossMonster();
    //randomMon.showStatus();
    showmon(randomMon);
    //showmon(fixedMon);
    showbattle(player,randomMon);
    //showbattle(player,fixedMon);
    }
    //nHUD();   
    
} 
*/

