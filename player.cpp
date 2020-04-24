#include <iostream>
#include <map>
#include <string>
#include "datas.h"
using namespace std;



class player { 
private: 
    int x, y; 
  
public: 
    player(status player) 
    { 
        x = player.pos.x; 
        y = player.pos.y;
        int h = player.h;
        int d = player.d;
        int v = player.v;
    }
    int getX() 
    { 
        return x; 
    } 
    int getY() 
    { 
        return y; 
    } 
};