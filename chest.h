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
 
void chestItem(Player &me) {
    int rewardType = rand() % 2; 

    if (rewardType == 1) { //gold
        int goldAmount = rand() % 10 + (50*me.level);
        cout << "You received " << goldAmount << " Gold!\n";
        me.addGold(goldAmount);
        
    } else { // XP
        int xpAmount = rand() % 101 + (500*me.level) ;
        cout << "You received " << xpAmount << " XP!\n";
        me.addXp(xpAmount);
        
    } 
    
}
#endif// chest
