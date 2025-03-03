#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<string>
#include<iomanip>
//Library

#include"hudfunc.h"

//Function

using namespace std; 


 

int main(){
    //ประกาศ equipment stats hp,atk,def,mag
    Equipment* axe = new Equipment("Axe", 5, 15, 5, 0);
    Equipment* bow = new Equipment("Bow", 2, 20, 0, 0);
    Equipment* sword = new Equipment("Sword", 0, 10, 0, 5);
    // Equipment* shield = new Equipment("shield", 10, 0, 20, 0);
    // Equipment* baxe = new Equipment("baxe", 10, 20, 5, 5);
    // Equipment* bsword = new Equipment("bsword", 5, 20, 10, 20);
    // Equipment* bshield = new Equipment("bshield", 20, 5, 30, 5);
    // Equipment* armor = new Equipment("armor", 30, 0, 10, 0);
    // Equipment* necklace = new Equipment("necklace", 10, 0, 0, 20);
    srand(time(0));

    int turn=0;//turn count

    SetConsoleOutputCP(65001);// Set CMD to UTF-8
    system("cls");//Clear Screen
    sHUD();
    while (true) {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
            break;
        }
        Sleep(10);  // Reduce CPU usage
    }
    system("cls");
    doSlow("Your name is...",50);
    getline(cin, yname);
    Player player(yname,100, 20, 10, 5);
    doSlow("There's a weapon beside you... It is...",50); 
    cout<<"\n[1] Axe"<<setw(10)<<"[2] Bow"<<setw(15)<<"[3] Sword\n>";
    while(true){   
    cin>>startweap;
    switch(startweap){
        case 1:
        player.equipItem(*axe);
        gear.at(0)=1;//gearid of axe

        break;
        case 2:
        player.equipItem(*bow);
        gear.at(0)=2;//id bow
        
        break;
        case 3:
        player.equipItem(*sword);
        gear.at(0)=3;//id sword
         
        break;
        default:
        cout<<"There's nothing else...";
    }
    break;
    }  

    system("cls");
    doSlowF("ascii_folder/Story1.txt",50);//Intro
    cout<<"\nPress Spacebar to continue.";  
    spaceb(); 
    system("cls");
    blank();
    nHUD(turn,player);
    

} 
