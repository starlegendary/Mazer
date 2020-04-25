#include <iostream>
#include <map>
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
struct rooms
{
    position pos;
    doors    door;
    string   type;
    string   pass;
};
struct doors
{
    int f, b, l, r;
};
map<string, status> items;

void add_door(rooms);
