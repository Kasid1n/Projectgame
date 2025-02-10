/*
 level(xp)
 addlevel
 xptoup
 levelup ---->> statup++ ---->>enemy++
 ***dead*** re ?? 
 -ดู class -
*/ 
#include <iostream>
using namespace std ;

int level = 1 ;
int xp = 0 ;
int xptolevelup = 100 ;

 void addxp(int xpgained )
    {
        xp+=xpgained ;
        
        while(xp>=xptolevelup){     /*stat++ in levelup*/
            levelup() ;
        }
    }
  void showstatus()
    {
        cout<<"You're level is"<<" "<<level ;
        cout<<"You're xp is"<<" "<<xp ;


    }
 void levelup ()
    {
         level++ ;
         xp = xp-xptolevelup ;
         xptolevelup += (25*level)+123 ;
         cout<<"You reached level"<<level<<"!!!!" 
         showstatus() ;

    }
 void dead()
    {
        level = 0 ;
        xp = 0 ;
        xptolevelup =100 ;
        showstatus() ;

    }
