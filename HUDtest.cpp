#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;


#include"Equipment.cpp"


//Screen Output
void sHUD();//Title
void nHUD();//Choice Hud
void blank();//blank screnn
void bar();//cout bar
void doASCii(string); //ASCii Art
void doSlow(string); //Text Delay
void doSlowF(string);
void showeap();//gear show
void spaceb();//press space bar
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//Text setting

string hero;//player name
int startweap;//select start weapon
vector<int> gear(3);
//vector<Equipment> inven(3);
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



void showeap(){
    SetConsoleTextAttribute(h,7);
    char choice;
    blank();
    bar();
    cout<<"Which one...\n";
    cout<<"[1]  [2]  [3]  [E] Quit. \n>";
    while (true){
        cin>> choice;
    switch(choice){
        case '1':
        switch(gear.at(0)){
            case 1:
                system("cls");
                SetConsoleTextAttribute(h,2);
                doASCii("ascii_folder/Axe.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Axe | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;
            case 2:
                system("cls");
                SetConsoleTextAttribute(h,2);
                doASCii("ascii_folder/Bow.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Bow | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;
            case 3:
                system("cls");
                SetConsoleTextAttribute(h,2);
                doASCii("ascii_folder/Sword.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Sword | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;
            case 4:
                system("cls");
                SetConsoleTextAttribute(h,2);
                doASCii("ascii_folder/Shield.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Shield | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;
            case 5:
                system("cls");
                SetConsoleTextAttribute(h,3);
                doASCii("ascii_folder/BetterAxe.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Waraxe | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;

            case 6:
                system("cls");
                SetConsoleTextAttribute(h,3);
                doASCii("ascii_folder/BetterSword.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Da Sword | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;

            case 7:
                system("cls");
                SetConsoleTextAttribute(h,3);
                doASCii("ascii_folder/BetterShield.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Saint'Wall | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;

            case 8:
                system("cls");
                SetConsoleTextAttribute(h,2);
                doASCii("ascii_folder/Armor.txt");
                SetConsoleTextAttribute(h,7);
                bar();
                cout<<"Armor | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;

            case 9:
                system("cls");
                SetConsoleTextAttribute(h,2);
                doASCii("ascii_folder/Necklace.txt");
                SetConsoleTextAttribute(h,7); 
                bar();
                cout<<"Necklace | Stat";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;

            
        }
            break;
        case '2':
        switch(gear.at(1)){
            case 1:
            doASCii("ascii_folder/Axe.txt");
            break;
            case 2:
            doASCii("ascii_folder/Bow.txt");
            break;
            case 3:
            doASCii("ascii_folder/Sword.txt");
            break;
        }  

        doASCii("ascii_folder/Bow.txt");
        break;
        case '3':
        switch(gear.at(2)){
            case 1:
            doASCii("ascii_folder/Axe.txt");
            cout<<"=====================================================================================\n";
            
            break;
            case 2:
            doASCii("ascii_folder/Bow.txt");

            break;
            case 3:
            doASCii("ascii_folder/Sword.txt");

            break;

        }
        
        break;
        case 'e':
        system("cls");
        blank();
        nHUD();
        break;

        case 'E':
        system("cls");
        blank();
        nHUD();
        break;
 
        default:
        cout<<"You only have 3 slot of Equipment.\n";
    }
    }
    
    
}

void spaceb(){
    while (true) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
                break;
            }
            Sleep(10);  // Reduce CPU usage
    }
}

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
    doSlow("You decide to :\n",50);
    cout<<"[1] Moving Forward"<<setw(15)<<"[2] Rest"<<setw(30)<<"[3] Check your equipment\n>";
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
        doSlow("You walk past the dark hallway...",50);
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
        doSlow("You found a gate and open it...",50);
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
        case 3:
        showeap();
        default:
            cout<<"Choose.\n"; 
    }
    }  
}
 
void bar(){
    cout<<"=====================================================================================\n";
}

void blank(){
    for(int i =0;i<24;i++){
        cout<<endl;
    }
} 



//////////////////////////////////////////////////////////////////////////////////////////
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
    doSlow("Your name is...",50);
    cin>> hero;
    Stats hero(100, 20, 10, 5);
    doSlow("There's a weapon beside you... It is...",50);
    cout<<"\n[1] Axe"<<setw(10)<<"[2] Bow"<<setw(10)<<"[3] Sword\n>";
    while(true){
    cin>>startweap;
    switch(startweap){
        case 1:
        hero.equip(&axe);
        gear.at(0)=1;//gearid of axe
        
        break;
        case 2:
        hero.equip(&bow);
        gear.at(0)=2;//id bow
        
        break;
        case 3:
        hero.equip(&sword);
        gear.at(0)=3;//id sword
        
        break;
        default:
        cout<<"There's nothing else...";
    }
    break;
    }  

    system("cls");
    doSlowF("ascii_folder/Story1.txt",50);//Intro
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



