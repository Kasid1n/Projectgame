#ifndef HUBFUNC_H 
#define HUBFUNC_H 
#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<vector>
using namespace std;
#include"test_4person.h"
#include"Qol.h"
#include"HUDtest3.h"
#include"HUDtest2.h"

//Screen Output
void sHUD();//Title 
void nHUD(int &,Player &);//Choice Hud, Main hud


void showeap(int,Player &);//gear show
void showgear(int,Player &);

void mon(Player &);//event mon
void shop(Player &);//event shop
void box(Player &);//event chest
void treasure();//event win
void boss(Player &);//event boss
void event(int &,Player &);//event

string yname;//player name
int startweap;//select start weapon
vector<int> gear(3);//inventory

void showgear(int slot,Player &me,int t){
    system("cls");
    if(me.equipmentList[slot]->getItemName()=="Axe"){ 
            SetConsoleTextAttribute(h,2);
            doASCii("ascii_folder/Axe.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"Axe | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else if(me.equipmentList[slot]->getItemName()=="Bow"){
        system("cls");
            SetConsoleTextAttribute(h,2);
            doASCii("ascii_folder/Bow.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"Bow | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else if(me.equipmentList[slot]->getItemName()=="Sword"){
        system("cls");
            SetConsoleTextAttribute(h,2);
            doASCii("ascii_folder/Sword.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"Sword | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else if(me.equipmentList[slot]->getItemName()=="Shield"){
        system("cls");
            SetConsoleTextAttribute(h,2);
            doASCii("ascii_folder/Shield.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"Shield | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else if(me.equipmentList[slot]->getItemName()=="SuperAxe"){
        system("cls");
            SetConsoleTextAttribute(h,3);
            doASCii("ascii_folder/SuperAxe.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"SuperAxe| ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    }  else if(me.equipmentList[slot]->getItemName()=="BetterSword"){
        system("cls");
            SetConsoleTextAttribute(h,3);
            doASCii("ascii_folder/BetterSword.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"BetterSword | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else if(me.equipmentList[slot]->getItemName()=="Better_Shield"){
        system("cls");
            SetConsoleTextAttribute(h,3);
            doASCii("ascii_folder/Better_Shield.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"Saint'Wall | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else if(me.equipmentList[slot]->getItemName()=="Armor"){
        system("cls");
            SetConsoleTextAttribute(h,2);
            doASCii("ascii_folder/Armor.txt");
            SetConsoleTextAttribute(h,7);
            bar();
            cout<<"Armor | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else if(me.equipmentList[slot]->getItemName()=="Necklace"){
        system("cls");
            SetConsoleTextAttribute(h,2);
            doASCii("ascii_folder/Necklace.txt");
            SetConsoleTextAttribute(h,7); 
            bar();
            cout<<"Necklace | ";cout << "   Attack+: " << me.equipmentList[slot]->getStat()[1] << " ";
            cout << "Defense+: " << me.equipmentList[slot]->getStat()[2] << " ";
            cout << "Heal+: " << me.equipmentList[slot]->getStat()[0] << " ";
            cout << "Magic+: " << me.equipmentList[slot]->getStat()[3];
            cout<<"\nPress Spacebar to go back.";
            spaceb();
            system("cls");
            blank();
            nHUD(t,me);
    } else{
        system("cls");
            blank();
            bar();
            cout<<"You don't have equipment in that slot\n";
            cout<<"\nPress Spacebar to go back.";
                spaceb();
                system("cls");
                blank();
                nHUD(t,me);
    }

}

void showeap(int s,Player &me){
    system("cls");
    SetConsoleTextAttribute(h,7);
    char choice;
    blank();
    bar();
    cout<<"Which one...\n";
    cout<<"[1]  [2]  [3]  [E] Quit [R] Inventory [T] Status\n>";
    while (true){
        cin>> choice;
    switch(choice){
        case '1':{
            showgear(0,me,s);
        }
        break;

        case '2':
            showgear(1,me,s);
        break;
        case '3':
            showgear(2,me,s);
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
        case 'r':
        system("cls");
        blank();
        bar();
        me.showInventory();
        cout<<"Press Spacebar to go back.";
        spaceb();
        system("cls");
        blank();
        nHUD(s,me);
        break;

        case 'R':
        system("cls");
        blank();
        bar();
        me.showInventory();
        cout<<"Press Spacebar to go back.";
        spaceb();
        system("cls");
        blank();
        nHUD(s,me);
        break;

        case 't':
        system("cls");
        blank();
        bar();
        cout<< "HP: "<<me.stats.hpmax<<" "<<"Atk: "<<me.stats.attack<<" "<<"Def:"<<me.stats.defense<<" "<<"Mag:"<<me.stats.magic;
        cout<<"\nPress Spacebar to go back.";
        spaceb();
        system("cls");
        blank();
        nHUD(s,me);
        break;
        
        case 'T':
        system("cls");
        blank();
        bar();
        cout<< "HP: "<<me.stats.hpmax<<" "<<"Atk: "<<me.stats.attack<<" "<<"Def:"<<me.stats.defense<<" "<<"Mag:"<<me.stats.magic;
        cout<<"\nPress Spacebar to go back.";
        spaceb();
        system("cls");
        blank();
        nHUD(s,me);
        break;
        

        default:
        cout<<"You only have 3 slot of Equipment.\n";
    }
    }
    
    
}


void sHUD(){
    SetConsoleTextAttribute(h,14);
    string filetxt="ascii_folder/text.txt";//Game Title
    doASCii(filetxt);
}

void nHUD(int &t,Player &me){//main system
    cin.clear();
    SetConsoleTextAttribute(h,7);//White
    cout<<"=====================================================================================\n";
    cout<<yname<<setw(15)<<"| "" HP: " << me.stats.hp << "/" << me.stats.hpmax << "    Level: " << me.level << "    Gold: " << me.gold << "   "
    "Turn: " <<t+1<<endl;
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
        case '2':{//Rest
        int h= me.level*30;
            if(me.stats.hp + h > me.stats.hpmax) {h = me.stats.hpmax - me.stats.hp;}
            else
	        me.stats.hp += h;    
        
        system("cls");
        blank();
        cout<<"=====================================================================================\n";
        doSlow("You lay against the wall for a few minute... You healed for : ",50);
        cout<<h;
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
        break;}
        case '3':
        showeap(t,me);
        default:
            cout<<"Choose.\n"; 
        }
    }  
}
 
/////////////////////////////////event



void event(int &i,Player &me){//turn
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
    if(r<=30){
      shop(me);
    }
    else if(r>30 && r<=50){
      box(me);
    }
    else if(r>50 && r<=70){//จบเกม
     treasure();
    }
     else if(r>70 && r<=100){
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
  system("cls");
  //Code battle
  Monster randomMon = MonsterFactory::randMonster(player.level);
  showmon(randomMon);
  showbattle(player,randomMon);
  ////////
  
}
 
void shop(Player &player){
  system("cls");
blank();
bar();
doSlow("You found a merchant.",50);
cout<<"\nPress Spacebar to continue.";
spaceb();
system("cls");
NPC shopNPC = getRandomNPC();  // สุ่ม NPC
showshop(player, shopNPC);     // แสดงร้านค้าและจัดการการซื้อขาย
}

void treasure(){
  system("cls");
  SetConsoleTextAttribute(h,14);
doASCii("ascii_folder/Grail.txt");
doSlow("                    You have found what you are looking for!!!",50);
cout << endl;
doASCii("ascii_folder/WIN.txt");
enter();

}

void boss(Player &player){
  system("cls");
blank();
bar();
doSlow("!!!!!",200);
cout<<"\nPress Spacebar to continue.";
spaceb();
system("cls");
//Code Boss
Monster boss = MonsterFactory::bossMonster();
showmon(boss);
int a = showbattle(player,boss);
showbattle(player,boss);
if (a==1)
{   enter();
    treasure(); 
}


////////
}
 

void chestItem(Player &me) {
    int rewardType = rand() % 2; 

    if (rewardType == 0) { //gold
        int goldAmount = rand() % 10 + 10;  
        me.gold += goldAmount;
        cout << "You received " << goldAmount << " Gold!\n";
    } else { // XP
        int xpAmount = rand() % 101 + 100 ; 
        me.xp += xpAmount;
        if(me.xp >= me.xptolevelup) {
            me.level ++ ;
        }
        cout << "You received " << xpAmount << " XP!\n";
    } 
    
}

void box(Player &me){
    system("cls");
doASCii("ascii_folder/Chest.txt");
bar();
doSlow("You found a chest!\n",50);
spaceb();
//Code chest
chestItem(me);
enter();
//
}




////////////////////////////////////////////////////////////////
#endif // 
