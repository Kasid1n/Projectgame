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
} 

