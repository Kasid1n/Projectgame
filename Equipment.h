#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector> 
using namespace std;
 

class Equipment{
	int hpmax;
	int atk;
	int def;
    int magic;
    int speed;
	public:
		Equipment(int,int,int,int,int);
		vector<int> getStat();			
};

Equipment::Equipment(int h,int a,int d,int m, int s){
	hpmax = h;
	atk = a;
	def = d;
    magic = m;
    speed = s;

}

vector<int> Equipment::getStat(){
	vector<int> stats = {hpmax, atk, def, magic ,speed};
    return stats;
}

/*void Unit::equip(Equipment *a){
	if (equipment!=NULL){
		vector<int> oldStat = equipment->getStat();
        hpmax -= oldStat[0];
        atk -= oldStat[1];
        def -= oldStat[2];
        magic -= oldStat[3];
        speed -= oldStat[4];
    }
		equipment = a;
		vector<int> stat = equipment->getStat();
		hpmax += stat[0];
		atk += stat[1];
		def += stat[2];
        magic += stat[3];
        speed += stat[4];
	

	if (hp>hpmax)
	{
		hp=hpmax;
	}
	
	}*/