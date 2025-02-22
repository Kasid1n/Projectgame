#include <iostream>
#include <string>
#include<ctime>
using namespace std;

void mon();
void shop();
void box();
void npc();
void treasure();
void boss();

void event(int &i){
   int r = rand()%100+1;

  if(i<10) {
    if(r<=70){
      mon;
    }
    else if(r>70 && r<=85){
      shop;
    }
    else if(r>85 && r<=90){
      box;
    }
    else if(r>90 && r<=100){
      npc;
    }
    i++;
  }

  else if(i>=10>30){
        if(r<=65){
          mon;
        }
        else if(r>65 && r<=75){
          shop;
        }
        else if(r>75 && r<=80){
          box;
        }
        else if(r>80 && r<=90){
          npc;
        }
        else if(r>90 && r<=95){
          treasure;
        }
        else if(r>95 && r<=100){
          boss;
        }
        i++;
  }
  else if(i>=30){
    if(r<=45){
      mon;
    }
    else if(r>45 && r<=55){
      shop;
    }
    else if(r>55 && r<=60){
      box;
    }
    else if(r>60 && r<=65){
      npc;
    }
    else if(r>65 && r<=80){
      treasure;
    }
    else if(r>80 && r<=100){
      boss;
    }
    i++;
}

}



void box(){
  int r = rand()%4;
  if (r<=2)
  {
    //get item
    //get heal 1+rand()%10?    
  }

  if (r==4)
  {
    // -hp 1+rand()%10
    // lose item
  }

}
/* npc -talk,got iteam-heal-gold ,lose iteam-hp minigame?
*/
void npc() {
    int action = rand() % 4;

    if (action == 0) {
        // NPC talks
        cout << "NPC: \"Hello, traveler! XXXXX\"" << endl;
    }
    if (action == 1) {
         int heal = 1 + rand() % 10;
         cout << "NPC healing  " << heal << endl;
    }
   if (action == 2)
         int gold = 1 + rand() % 10;
         cout << "You got " << gold << " gold." << endl;
    }
    else {
         int gold = 1 + rand() % 10;
         cout << "You were robbed.\n You lose " << gold << " gold." << endl;
   }
}
   
