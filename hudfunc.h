#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<vector>
using namespace std;


#include"HUDtest2.h" 

 
//Screen Output
void sHUD();//Title
void nHUD(int &,Player);//Choice Hud, Main hud


void showeap(int,Player &);//gear show


void mon(Player &);//event mon
void shop(Player &);//event shop
void box(Player &);//event chest
void treasure();//event win
void boss(Player &);//event boss
void event(int &,Player);

string hero;//player name
int startweap;//select start weapon
vector<int> gear(3);//inventory



void showeap(int s,Player &me){
    system("cls");
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
                cout<<"Axe | HPmax +0 Atk +15 Def +0 Mag +0";
                cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
                nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
                nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
            nHUD(s,me);
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
                nHUD(s,me);
                break;

        }
        
        break;
        case 'e':
        system("cls");
        blank();
        nHUD(s,me);
        break;

        case 'E':
        system("cls");
        blank();
        nHUD(s,me);
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
    SetConsoleTextAttribute(h,14);
    string filetxt="ascii_folder/text.txt";//Game Title
    doASCii(filetxt);
}

void nHUD(int &t,Player me){//main system
    SetConsoleTextAttribute(h,7);//White
    cout<<"=====================================================================================\n";
    cout<<hero<<setw(15)<<"| "; me.showStatus(); cout<<"Turn : "<<t+1<<endl; 
    cout<<"=====================================================================================\n";
    doSlow("You decide to :\n",50);
    cout<<"[1] Moving Forward"<<setw(15)<<"[2] Rest"<<setw(30)<<"[3] Check your equipment\n>";
    char choice;
    
    int sc = rand()%50;//Different Scenery
    while(true){ 
        cin>> choice; 
    switch(choice){
        
        case '1'://Move
        system("cls");
        if(sc>=20){
        SetConsoleTextAttribute(h,8);
        doASCii("ascii_folder/walls2.txt");
        SetConsoleTextAttribute(h,7);
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
        event(t,me);
        //
        system("cls");
        blank();
        t++;
        nHUD(t,me);
        }
        else {
        SetConsoleTextAttribute(h,8);
        doASCii("ascii_folder/walls1.txt");
        SetConsoleTextAttribute(h,7);
        cout<<"=====================================================================================\n";
        doSlow("You found a gate and open it...",50);
        cout<<"\nPress Spacebar to continue.";
        while (true) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
                break;
            }
            Sleep(10);  // Reduce CPU usage
        }
        //code event here
        event(t,me);
        //
        system("cls");
        blank();
        t++;
        nHUD(t,me);
        }
        break;
        case '2'://Rest
        system("cls");
        blank();
        cout<<"=====================================================================================\n";
        doSlow("You lay against the wall for a few minute... You healed for : " ,50);
        cout<<"\nPress Spacebar to continue.";
        
        while (true) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {  // Check if space bar is pressed
                break;
            }
            Sleep(10);  // Reduce CPU usage
        }
        //code event here
        event(t,me);
        //
        system("cls");
        blank();
        nHUD(t,me);
        break;
        case '3':
        showeap(t,me);
        default:
            cout<<"Choose.\n"; 
    }
    }  
}
 
 
/////////////////////////////////event



void event(int &i,Player me){//turn
   int r = rand()%100+1;

  if(i<6) {// 10 ตาแรกจะไม่เจอบอส
    if(r<=60){
      mon(me);
    }
    else if(r>60 && r<=80){
      shop(me);
    }
    else if(r>80 && r<=100){
      box(me);
    }
    
  }

  else if(i>=6&&i<11){// ผ่านไปสิบตามีโอกาสเจอบอส
        if(r<=50){
          mon(me);
        }
        else if(r>50 && r<=70){
          shop(me);
        }
        else if(r>70 && r<=80){
          box(me);
        }
        else if(r>80 && r<=90){//จบเกม
          treasure();
        }
        else if(r>90 && r<=100){
          boss(me);
        }
        
  }
  else if(i>=11){// เพิ้มโอกาสเจอบอส
    if(r<=40){
      mon(me);
    }
    else if(r>40 && r<=60){
      shop(me);
    }
    else if(r>60 && r<=70){
      box(me);
    }
    else if(r>70 && r<=85){//จบเกม
      treasure();
    }
     else if(r>85 && r<=100){
       boss(me);
    }
    
}

}
  
void mon(Player &player){
  system("cls");
  blank();
  bar();
  doSlow("You encounter a monster!",50);
  cout<<"\nPress Spacebar to continue.";
  spaceb();
  //Code battle
  Monster randomMon = MonsterFactory::randMonster(player.level);
  showmon(randomMon);
  showbattle(player,randomMon);
  ////////
  
}
 
// void shop(Player &player){
//   system("cls");
// blank();
// bar();
// doSlow("You found a merchant.",50);
// cout<<"\nPress Spacebar to continue.";
// spaceb();
// NPC shopNPC = getRandomNPC();  // สุ่ม NPC
// showshop(player, shopNPC);     // แสดงร้านค้าและจัดการการซื้อขาย
// }

void treasure(){
  system("cls");
  SetConsoleTextAttribute(h,14);
doASCii("ascii_folder/Grail.txt");

bar();
doSlow("You found what you came here for!",50);
doASCii("ascii_folder/WIN.txt");
}

void boss(Player &player){
  system("cls");
blank();
bar();
doSlow("!!!!!",200);
cout<<"\nPress Spacebar to continue.";
spaceb();
//Code Boss
Monster boss = MonsterFactory::bossMonster();
showmon(boss);
showbattle(player,boss);

////////
}

void box(){
    system("cls");
doASCii("ascii_folder/Chest.txt");
bar();
doSlow("You found a chest!",50);
cout<<"\nPress Spacebar to continue.";
spaceb();
//Code chest

//
}




////////////////////////////////////////////////////////////////
