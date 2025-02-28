#include <iostream>
#include <string>
#include<ctime>
using namespace std;

#include"HUDtest.cpp"

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

   
