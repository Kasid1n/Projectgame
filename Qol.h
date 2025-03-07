#ifndef QOL_H
#define QOL_H

#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
using namespace std;

void blank();//blank screnn
void bar();//cout bar
void doASCii(string); //ASCii Art
void doSlow(string); //Text Delay
void doSlowF(string);
void spaceb();//press space bar
void enter();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//Text setting

 
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
void doSlow(const string &text, int delay) {
    for (char c : text) {
        if (GetAsyncKeyState(VK_LCONTROL) & 0x8000) {  // Ctrl to Skip
            continue; 
        }
        cout << c << flush;
        Sleep(delay);  // Delay in milliseconds
    };
}
void doSlowF(const string &text, int delay){
    string line="";
    ifstream inFile;
    inFile.open(text);
    if(inFile.is_open())
    {
        while(getline(inFile,line)){
            
            Sleep(10);  // Reduce CPU usage  
            for (char c : line) {
                if (GetAsyncKeyState(VK_LCONTROL) & 0x8000) {  // Ctrl to Skip
                    continue; 
                }
                cout << c << flush;
                Sleep(delay);  // Delay in milliseconds
            };
            cout<<endl; 
        }
    }
    else
    cout<<"File failed to load";
    inFile.close();
}

void blank(){
    for(int i =0;i<24;i++){
        cout<<endl;
    }
} 

void enter() {
    int pressCount = 0;
    SetConsoleTextAttribute(h,15);
    cout << "Press Enter to continue.";
    while (true) {
        
        // ตรวจสอบการกดปุ่ม "Enter"
        if (GetAsyncKeyState(0x0D) & 0x8000) {
            pressCount++; 

            if (pressCount == 2) {
                return;
            }

            while (GetAsyncKeyState(0x0D) & 0x8000) {
                Sleep(10);
            }
        }
        Sleep(10);
    }
}

void bar(){

    cout<<"=====================================================================================\n";
}


void spaceb(){
    while (true) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
                break;
            }
            Sleep(10);  // Reduce CPU usage
    }
}
#endif //QOL.H