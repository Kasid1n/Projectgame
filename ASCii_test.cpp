#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

void doASCii(string x){
    SetConsoleOutputCP(65001);// Set CMD to UTF-8
    string line="";
    ifstream inFile;
    inFile.open("text.txt");
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

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string filetxt="text.txt";
    SetConsoleTextAttribute(h,4);
    doASCii(filetxt); 
    return 0;
} 