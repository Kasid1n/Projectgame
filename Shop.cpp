#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;
class NPC {
    string npcname ;
    vector<string> sellItem ;
    vector<int> ItemPrice;
public :
    NPC(string name) {
        npcname = name ;
        sellItem = {"Attack Potion" , "Magic Potion", "Defense Shield" , "Speed"} ;
        ItemPrice = {15 , 15 ,20 ,20} ;
    }   
    void shop() {
        cout<<npcname<<"'s shop" << endl ;
        for(int i = 0 ; i < sellItem.size() ; i++)
        cout<<i + 1 << " " << sellItem[i]<<" "<<ItemPrice[i]<<endl ;


    }
    void sellItemtoPlayer() {
        shop() ;  

    }
};  
/*    test  
int main() {
    NPC npc("L") ;
    npc.shop() ;
 
}
*/    