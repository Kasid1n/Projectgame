#include <iostream>
#include <string>
#include<ctime>
using namespace std;
#include"HUDtest.cpp"

void mon();
void shop();
void box();
void treasure();
void boss();

void event(int &i){
   int r = rand()%100+1;

  if(i<10) {
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

  else if(i>=10>30){
        if(r<=75){
          mon;
        }
        else if(r>75 && r<=85){
          shop;
        }
        else if(r>85 && r<=90){
          box;
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
    if(r<=55){
      mon;
    }
    else if(r>55 && r<=65){
      shop;
    }
    else if(r>65 && r<=70){
      box;
    }
    else if(r>70 && r<=80){
      treasure;
    }
    else if(r>80 && r<=100){
      boss;
    }
    i++;
}

}
 
void mon(){
  
  doSlow("You encounter a monster!",50);

}

void shop(){

}

void treasure(){

}

void boss(){

}

void box(){
  
}

   
