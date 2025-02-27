#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<string>
//Library

#include"HUDtest.cpp"
#include"PVP.h"
#include"Equipment.h"
#include"event.cpp"
#include"Shop.cpp"
#include"SMPL.cpp"
#include"level.cpp"
#include"z.cpp"
//Function

using namespace std; 




int main(){
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
    doSlow("Your name is...",100);
    cin>> yname;
    doSlow("There's weapon beside you... It is...",100);
    cout<<"\n[1] Axe"<<setw(15)<<"[2] Bow"<<setw(15)<<"[3] Sword";
    cin>>startweap; 
    system("cls");
    doSlowF("ascii_folder/Story1.txt",100);//Intro
    cout<<"\nPress Spacebar to continue.";  
    while (true) {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
            break;
        }
        Sleep(10);  // Reduce CPU usage
    }  
    system("cls");
    blank();
    nHUD();    
} 
