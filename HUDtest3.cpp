#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include<iomanip>
#include"test_4person.cpp"
using namespace std;


void doASCii(string x){
    string line="";
    ifstream inFile;
    inFile.open(x);
    if(inFile.is_open())
    {
        while(getline(inFile,line)){
            cout<<line<<endl;
        }
    }
    else
    cout<<"File failed to load";
    inFile.close();
}

void showNPC();

void showNPC(Player A){
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                   SHOP                                     ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    NPC shopNPC = getRandomNPC();

    if(shopNPC.npcname=="A"){doASCii("ascii_folder/npc1.txt");}
    if(shopNPC.npcname=="B"){doASCii("ascii_folder/npc2.txt");}
    if(shopNPC.npcname=="Secretmaster"){doASCii("ascii_folder/npc3.txt");}  
    cout << "════════════════════════════════════════════════════════════════════════════\n";
    shopNPC.sellItemToPlayer(A);  
    

}

int main(){
    SetConsoleOutputCP(65001);
    Player player("s", 100, 20, 10, 5);
    showNPC(player);
    
}