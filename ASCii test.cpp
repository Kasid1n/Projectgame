#include<iostream>
#include<fstream>
using namespace std;

void doASCii(string x){
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
    string filetxt="text.txt";
    doASCii(filetxt);
    return 0;
} 