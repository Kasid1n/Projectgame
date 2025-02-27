#include<iostream>
#include<fstream>
#include<windows.h>
#include <cstdlib>
#include<iomanip>
#include"PVP.cpp"
using namespace std;

//Screen Output
void sHUD();//Title
void nHUD();
void mon();
void hero();
void blank();
 //entity show
void showgaveup(string);
void showwin();
void showlose();
void showAT();
void showDE();
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

void mon(Monster &B){
    SetConsoleTextAttribute(h,4);
    cout<<"                       =====================================================\n";
    cout<<"                       "<< B.name << " | HP : "<< B.hp << "/" << B.hpmax <<"\n";
    cout<<"                       =====================================================\n";
    //if(B.name=="Skeleton"){doASCii("ascii_folder/Skeleton.txt");}
    //if(B.name==""){doASCii("ascii_folder/.txt");}
    //if(B.name==""){doASCii("ascii_folder/.txt");}
    //if(B.name==""){doASCii("ascii_folder/.txt");}
    doASCii("ascii_folder/Skeleton.txt");

}
void hero(Player &A){
    SetConsoleTextAttribute(h,2);
    cout<<"=====================================================\n";
    cout<< A.name << " | HP : "<< A.hp << "/" << A.hpmax <<"\n";
    cout<<"=====================================================\n";
}

void blank(){
    for(int i =0;i<24;i++){
        cout<<endl;
    }
}  


/*void showgaveup(string x){
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             YOU GAVE UP                                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n"; 
    SetConsoleTextAttribute(h,4);//Red
    mon();
    string filetxt=x;
    doASCii(filetxt);
    hero();
    
    showlose ();
    
}*/

void showwin(){ 
    SetConsoleTextAttribute(h,15);//white
    cout << endl;
    doASCii("ascii_folder/WIN");
    cout << endl;
    
}

void showlose (){ 
    SetConsoleTextAttribute(h,15);//white
    cout << endl;
    doASCii("ascii_folder/LOSE");
    cout << endl;
    
}


void showAT(Player &A, Monster &B){
    blank();
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO ATTACK                                 ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    mon(B);
    hero(A);
    int playerAttackChoice = AttackChoice();
    switch (playerAttackChoice) {
        case 1:
            cout << "You chose to Attack!\n";
            break;
        case 2:
            cout << "You chose to use Skill!\n";
            break;
        case 3:
            cout << "You chose to use Ultimate!\n";
            break;
        case 4:
            cout << "You chose to Heal\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
    }
    D = battlesys(A, B, playerAttackChoice);//float return pvp
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO ATTACK                                 ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    mon(B);
    hero(A);
    
    cout << A.name << " did " << D << " damage\n";
    cout << B.name << " lost " << D << " HP\n";
    Sleep(2000);
    
    
    
   // Sleep(900);
}

void showDE(Player &A, Monster &B){
    blank();
    SetConsoleTextAttribute(h,2);//Green
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO DEFENSE                                ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    mon(B);
    hero(A);

    int playerDefenseChoice = DefenseChoice();
    switch (playerDefenseChoice) {
        case 1:
            cout << "You chose to Block!\n";
            break;
        case 2:
            cout << "You chose to Dodge!\n";
            break;
        case 3:
            cout << "You chose to Parry!\n";
            break;
        case 4:
            cout << "You chose to Give up\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
    }
    D = battlesys(B, A, playerDefenseChoice); //float return pvp
    SetConsoleTextAttribute(h,2);//Green
    
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                             TURN TO DEFENSE                                ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    mon(B);
    hero(A);
    cout << A.name << " did " << D << " damage\n";
    cout << B.name << " lost " << D << " HP\n";
    Sleep(2000);
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

    //showgaveup ("ascii_folder/Skeleton.txt");
    //showwin();
    //showlose();
    //mon(enemy);
    //hero(player);
    //showAT(player,enemy);
    showDE(player,enemy);
    showAT(player,enemy);
    showDE(player,enemy);
    showAT(player,enemy);

    //nHUD();   
} 


