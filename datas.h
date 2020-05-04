#ifndef _DATAS_H
#define _DATAS_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct position
{
    int x,y;
};
struct status
{
    position pos;
    int h, d, v;
};
struct doors
{
    int f, b, l, r;
};

struct rooms
{
    doors door;
    char  type = 'N';
    int   pass = 0;
};

void add_door(rooms&);
void move(status& , status&);
void define_items();
void define_player_moster();
void display(vector<vector<rooms>>,int, int);
string random_item(int);
status MakeStatus(int, int, int,int,int);



#endif
