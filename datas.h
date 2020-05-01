#ifndef _DATAS_H
#define _DATAS_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int S = 5;

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


map<string, status> items;
vector<vector<rooms>> board(S, vector<rooms>(S)); //board of game


void add_door(rooms);
void define_items();
void random_item();

void display(vector<vector<rooms>> board,int i, int j);

string blanck = "     ";
string edge = "+";
string wall = "-----";

#endif
