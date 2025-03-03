#ifndef CHEST_H
#define CHEST_H

#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<vector>
using namespace std;
#include"test_4person.h"
#include"Qol.h"
#include"HUDtest3.h"
#include"HUDtest2.h"
 
void chestItem(Player &me) {
    int rewardType = rand() % 2; 

    if (rewardType == 0) { //gold
        int goldAmount = rand() % 10 + 10;  
        me.gold += goldAmount;
        cout << "You received " << goldAmount << " Gold!\n";
    } else { // XP
        int xpAmount = rand() % 101 + 100 ; 
        me.xp += xpAmount;
        if(me.xp >= me.xptolevelup) {
            me.level ++ ;
        }
        cout << "You received " << xpAmount << " XP!\n";
    } 
    
}
void box(Player &me){
    system("cls");
doASCii("ascii_folder/Chest.txt");
bar();
doSlow("You found a chest!",50);
cout<<"\nPress Spacebar to continue. \n";
spaceb();

//Code chest
    chestItem(me);
    me.showStatus() ;
    
 }

 #endif //CHEST.H
