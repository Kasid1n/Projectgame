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



	/*
void Unit::equip(Equipment* a) {
    if (equipmentList.size() >= 3) {
        cout << "Cannot equip more than 3 items." << endl;
        return;}


	equipmentList.push_back(a);
    vector<int> stat = a->getStat();
    hpmax += stat[0];
    atk += stat[1];
    def += stat[2];
    magic += stat[3];
    speed += stat[4];

	if (hp>hpmax)
	{
		hp=hpmax;
	}


	void Unit::unequip(int index) {
	
	vector<int> stat = equipmentList[index]->getStat();
    hpmax -= stat[0];
    atk -= stat[1];
    def -= stat[2];
    magic -= stat[3];
    speed -= stat[4];

    equipmentList.erase(equipmentList.begin() + index);

	if (hp > hpmax) {
        hp = hpmax;
    }
    }*/
