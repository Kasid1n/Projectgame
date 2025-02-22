#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
using namespace std;

//Screen Output
void sHUD();
void cHUD();
void nHUD();
void showmon();
void doASCii(string); //ASCii Art
void doSlow(string); //Text Delay
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
    

void sHUD(){
    SetConsoleTextAttribute(h,4);//Text Color
    string filetxt="text.txt";//Game Title
    doASCii(filetxt);
}

void nHUD(){
    SetConsoleTextAttribute(h,1);
    
    string filetxt="nHUD.txt";
    doASCii(filetxt);
}

void showmon(){
    SetConsoleTextAttribute(h,4);//Red
    string filetxt="text.txt";
    doASCii(filetxt);
}


