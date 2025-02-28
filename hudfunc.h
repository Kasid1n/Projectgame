#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<vector>
using namespace std;

//Screen Output
void sHUD();//Title
void nHUD();//Choice Hud, Main hud
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
vector<int> gear(3);//inventory


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
            default:
            system("cls");
            blank();
            bar();
            cout<<"You don't have equipment in that slot\n";
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
        default:
            system("cls");
            blank();
            bar();
            cout<<"You don't have equipment in that slot\n";
            cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
                break;
        }  

        doASCii("ascii_folder/Bow.txt");
        break;
        case '3':
        switch(gear.at(2)){
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
        default:
            system("cls");
            blank();
            bar();
            cout<<"You don't have equipment in that slot\n";
            cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD();
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
    SetConsoleTextAttribute(h,15);
    string filetxt="ascii_folder/text.txt";//Game Title
    doASCii(filetxt);
}

void nHUD(){//main system
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
        if(sc>=20){
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
        //event(&turn);
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
        //event(&turn);
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

/////////////////////////////////event

void mon();//event mon
void shop();//event shop
void box();//event chest
void treasure();//event win
void boss();//event boss

void event(int &i){//turn
   int r = rand()%100+1;

  if(i<10) {// 10 ตาแรกจะไม่เจอบอส
    if(r<=80){
      mon;
    }
    else if(r>80 && r<=95){
      shop;
    }
    else if(r>95 && r<=100){
      box;
    }
    i++;
  }

  else if(i>=10>30){// ผ่านไปสิบตามีโอกาสเจอบอส
        if(r<=75){
          mon;
        }
        else if(r>75 && r<=85){
          shop;
        }
        else if(r>85 && r<=90){
          box;
        }
        else if(r>90 && r<=95){//จบเกม
          treasure;
        }
        else if(r>95 && r<=100){
          boss;
        }
        i++;
  }
  else if(i>=30){// เพิ้มโอกาสเจอบอส
    if(r<=55){
      mon;
    }
    else if(r>55 && r<=65){
      shop;
    }
    else if(r>65 && r<=70){
      box;
    }
    else if(r>70 && r<=80){//จบเกม
      treasure;
    }
    else if(r>80 && r<=100){
      boss;
    }
    i++;
}

}
 
void mon(){
  system("cls");
  blank;
  bar;
  doSlow("You encounter a monster!",50);
  cout<<"Press Spacebar to continue.\n";
  spaceb;
  //Code battle

  ////////
  system("cls");
        blank();
        nHUD();
}

void shop(){
  system("cls");
blank;
bar;
doSlow("You found a merchant.",50);
cout<<"\nPress Spacebar to continue.";
spaceb;
//Code shop

////////
system("cls");
        blank();
        nHUD();
}

void treasure(){
  system("cls");
doASCii("ascii_folder/Grail.txt");
bar;
doSlow("You found what you came here for!",50);
cout<<"\nPress Spacebar to continue.";
spaceb;
doASCii("ascii_folder/WIN.txt");
}

void boss(){
  system("cls");
blank;
bar;
doSlow("!!!",200);
cout<<"\nPress Spacebar to continue.";
spaceb;
//Code Boss

////////
system("cls");
        blank();
        nHUD();
}

void box(){
    system("cls");
doASCii("ascii_folder/Chest.txt");
bar;
doSlow("You found a chest!",50);
cout<<"\nPress Spacebar to continue.";
spaceb;
//Code chest

//
system("cls");
        blank();
        nHUD();
}
