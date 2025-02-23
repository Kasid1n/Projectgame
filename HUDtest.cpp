#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include<iomanip>
using namespace std;

//Screen Output
void sHUD();//Title
void nHUD();//Choice Hud
void blank();//blank screnn
void batHUD();//Battle Hud
void showmon(string); //entity show
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
    SetConsoleTextAttribute(h,15);//Text Color Red
    string filetxt="ascii_folder/text.txt";//Game Title
    doASCii(filetxt);
}

void nHUD(){
    SetConsoleTextAttribute(h,7);//White
    cout<<"=====================================================================================\n";
    cout<<"Name HP : 1/1"<<setw(20)<<"Gold : 500\n";
    cout<<"=====================================================================================  \n";
    doSlow("You decide to: \n",100);
    cout<<"[1] Moving Forward"<<setw(15)<<"[2] Rest"<<setw(20)<<"[3] Check your equipment";
}
 
void batHUD(){

}
void showmon(string x){
    SetConsoleTextAttribute(h,2);//Green
    cout<<"=====================================================================================\n";
    cout<<"                                    Mon                                              \n";
    cout<<"=====================================================================================\n";
    SetConsoleTextAttribute(h,4);//Red
    string filetxt=x;
    doASCii(filetxt);
}

void blank(){
    for(int i =0;i<24;i++){
        cout<<endl;
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
    system("cls"); 
    doSlowF("ascii_folder/Story1.txt",100);
    cout<<"Press Spacebar to continue.";  
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

