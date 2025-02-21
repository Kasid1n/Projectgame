#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
using namespace std;

//HUD
void sHUD();
void cHUD();
void nHUD();
void doASCii(string);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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
void sHUD(){
    SetConsoleTextAttribute(h,4);//Text Color
    string filetxt="text.txt";//Game Title
    doASCii(filetxt);
}

int main(){
    system("start cmd /k \"mode con: cols=200 lines=60\""); //Pop-up terminal
    SetConsoleOutputCP(65001);// Set CMD to UTF-8
    sHUD();
    
    
    return 0;
} 