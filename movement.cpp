#include <iostream>
#include <map>
#include <string>
#include "datas.h"

using namespace std;
int lol(int a){if(a==0)return -1; else return a;}
position dis(position a, position b)
{
    position sth;
    sth.x = a.x - b.x;
    sth.y = a.y - b.y;
    return sth;
};
int sqsum(position sth)
{ 
    return sth.x*sth.x+sth.y*sth.y; 
}
position movement(position a, position b)
{
    position sth = dis(a,b);
    int diss = sqsum(sth);
    position change[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i = 0; i < 4; i++)
    {
        position newpos = dis(a,change[i]);
        if (sqsum(dis(sth,b))>= sqsum(dis(newpos,b)))
        {
            sth = newpos;
            diss = sqsum(newpos);
        };
    };
    return sth;
};