#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include<iomanip>
using namespace std;

//Screen Output
void sHUD();//Title
void nHUD();
void showattack(string); //entity show
void showdodge(string);
void showparry(string);
void showblock(string);
void doASCii(string); //ASCii Art
void doSlow(string); //Text Delay
void doSlowF(string);
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
        cout << c << flush;
        Sleep(delay);  // Delay in milliseconds
    }
    cout<<endl;
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
            }
            cout<<endl;
        }
    }
    else
    cout<<"File failed to load";
    inFile.close();
}

void sHUD(){
    SetConsoleTextAttribute(h,4);//Text Color Red
    string filetxt="ascii_folder/text.txt";//Game Title
    doASCii(filetxt);
}

void nHUD(){
    SetConsoleTextAttribute(h,2);
    cout<<"=====================================================================================\n";
    cout<<"Name HP : 1/1"<<setw(20)<<"Gold : 500\n";
    cout<<"=====================================================================================\n";
}
 

void showattack(string x){
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                            ATTACK ACTION                                   ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";

    SetConsoleTextAttribute(h,4);//Red
    string filetxt=x;
    doASCii(filetxt);
    SetConsoleTextAttribute(h,2);
    if (true) {  
        cout << ">>> You hit the skeleton!\n";
    } else {
        cout << ">>> Your attack missed!\n";
    }
}
void showdodge(string x){
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                            DODGE ACTION                                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n"; 
    SetConsoleTextAttribute(h,4);//Red
    string filetxt=x;
    doASCii(filetxt);
    SetConsoleTextAttribute(h,2);
    if (true) {
        cout << ">>> You dodged the skeleton's attack!\n";
    } else {
        cout << ">>> You failed to dodge!\n";
    }
}

void showparry(string x){
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                            PARRY ACTION                                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n"; 
    SetConsoleTextAttribute(h,4);//Red
    string filetxt=x;
    doASCii(filetxt);
    SetConsoleTextAttribute(h,2);
    if (true) {
        cout << ">>> You successfully parried the attack!\n";
    } else {
        cout << ">>> Your parry failed!\n";
    }
}

void showblock(string x){
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             BLOCK ACTION                                   ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n"; 
    SetConsoleTextAttribute(h,4);//Red
    string filetxt=x;
    doASCii(filetxt);
    SetConsoleTextAttribute(h,2);
    if (true) {
        cout << ">>> You blocked the attack!\n";
    } else {
        cout << ">>> You failed to block the attack!\n";
    }
    
}

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
    showattack("ascii_folder/Skeleton.txt");
    showdodge("ascii_folder/Skeleton.txt");
    showparry("ascii_folder/Skeleton.txt");
    showblock ("ascii_folder/Skeleton.txt");
    
    //nHUD();   
} 

