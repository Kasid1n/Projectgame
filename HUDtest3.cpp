#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include<iomanip>
#include"test_4person.h"
#include"Qol.h"
using namespace std;



void showNPC();

void showNPC(Player A){
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                   SHOP                                     ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    NPC shopNPC = getRandomNPC();
    
    //npcname pb
    if(shopNPC.npcname=="A"){doASCii("ascii_folder/npc1.txt");}
    if(shopNPC.npcname=="B"){doASCii("ascii_folder/npc2.txt");}
    if(shopNPC.npcname=="Secretmaster"){doASCii("ascii_folder/npc3.txt");}  
    cout << "════════════════════════════════════════════════════════════════════════════\n";
    //shopNPC.sellItemToPlayer(A);  
    shopNPC.shop();//doloop?

    //system("cls");

}

int main(){
    SetConsoleOutputCP(65001);
    Player player("s", 100, 20, 10, 5);
    player.addGold(100);
    showNPC(player);
    showNPC(player);
    showNPC(player);
    
}