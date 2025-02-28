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
#include"Shop.cpp"
#include"Equipment.h"
//Function

using namespace std; 




int main(){
    Equipment sword(0, 10, 0, 5);
    Equipment shield(0, 0, 10, 0);
    Equipment axe(0, 15, 0, 0);
    Equipment bow(0, 10, 0, 5);

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
    cin>> hero;
    Stats hero(100, 20, 10, 5);
    doSlow("There's a weapon beside you... It is...",50);
    cout<<"\n[1] Axe"<<setw(10)<<"[2] Bow"<<setw(15)<<"[3] Sword\n>";
    while(true){   
    cin>>startweap;
    switch(startweap){
        case 1:
        hero.equip(&axe);
        gear.at(0)=1;//gearid of axe
         
        break;
        case 2:
        hero.equip(&bow);
        gear.at(0)=2;//id bow
        
        break;
        case 3:
        hero.equip(&sword);
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
    nHUD(turn);
    
} 
