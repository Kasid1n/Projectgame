#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;

class stats{		 
    int hp;
    int hpmax;
    int attack;
    int defense; 
    int magic;
    int speed;

    public:
    void start();

}

void stats::start(){
    hp = hpmax;
}


