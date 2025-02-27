#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;
#include"z.cpp"




//Screen Output
void sHUD();//Title
void nHUD();//Choice Hud
void blank();//blank screnn
void showmon(string); //entity show
void doASCii(string); //ASCii Art
void doSlow(string); //Text Delay
void doSlowF(string);
// void showeap(int);//gear show
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//Text setting

string hero;//player name
int startweap;//select start weapon
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
        }
    }
    else
    cout<<"File failed to load";
    inFile.close();
}

// void showeap(int choice){
//     SetConsoleTextAttribute(h,8);//Text Color Red
    
//     do{switch(choice){
//         case 1://Axe
//         doASCii("ascii_folder/Axe.txt");
//         break;
//         case 2://Bow
//         doASCii("ascii_folder/Bow.txt");
//         break;
//         case 3://Sword
//         doASCii("ascii_folder/Sword.txt");
//         break;
        
//         default:
        
//     }
//     }while(true);
    
// }



void sHUD(){
    SetConsoleTextAttribute(h,15);//Text Color Red
    string filetxt="ascii_folder/text.txt";//Game Title
    doASCii(filetxt);
}

void nHUD(){
    SetConsoleTextAttribute(h,7);//White
    for(int i =0;i<24;i++){
        cout<<endl;
    }
    cout<<"=====================================================================================\n";
    cout<<hero<<setw(15)<<"| HP : 1/1"<<setw(15)<<"Level : 1 "<<setw(15)<<"Gold : 500\n";  
    cout<<"=====================================================================================\n";
    doSlow("You decide to :\n",100);
    cout<<"[1] Moving Forward"<<setw(15)<<"[2] Rest"<<setw(30)<<"[3] Check your equipment";
    int choice;
    
    int sc = rand()%50;//Different Scenery
    while(true){ 
        cin>> choice; 
    switch(choice){
        
        case 1://Move
        system("cls");
        if(sc>=10){
        doASCii("ascii_folder/walls2.txt");
        cout<<"=====================================================================================\n";
        doSlow("You walk past the dark hallway...",100);
        cout<<"\nPress Spacebar to continue.";
        while (true) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
                break;
            }
            Sleep(10);  // Reduce CPU usage
        }
        //code event here
                
        //
        system("cls");
        blank();
        nHUD();
        }
        else {doASCii("ascii_folder/walls1.txt");
        cout<<"=====================================================================================\n";
        doSlow("You found a gate and open it...",100);
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
        break;
        case 2://Rest
        system("cls");
        blank();
        cout<<"=====================================================================================\n";
        doSlow("You lay against the wall for a few minute... You healed for : " ,50);
        cout<<"\nPress Spacebar to continue.";
        //code event here

        //
        while (true) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
                break;
            }
            Sleep(10);  // Reduce CPU usage
        }
        system("cls");
        blank();
        nHUD();
        break; 
        default:
            cout<<"Choose.\n"; 
    }
    }  
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
    Equipment sword(0, 10, 0, 5);
    Equipment shield(0, 0, 10, 0);
    Equipment axe(0, 15, 0, 0);
    Equipment bow(0, 10, 0, 5);
    

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
    cin>> hero;
    Stats yname(100, 20, 10, 5);
    doSlow("There's weapon beside you... It is...",100);
    
    cout<<"\n[1] Axe"<<setw(10)<<"[2] Bow"<<setw(10)<<"[3] Sword";
    while(true){
    cin>>startweap;
    switch(startweap){
        case 1:

        
    }
    } 
    //โค้ดอุปกรณ์

    //
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



