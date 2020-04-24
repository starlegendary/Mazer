#include <iostream>
#include <map>
#include <string>
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
struct room
{
    position pos;
    int f, b, l, r;
    string type;
    string pass;
};
map<string, status> item;
