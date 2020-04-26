#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "datas.h"
using namespace std;

void nth(){
    cout<< ' '<<blanck<<' '<<blanck;
};
void aline(rooms room, bool empty, char t){
    if(empty){nth();};
    if(t == 'z')
    {cout<<edge<<wall<<room.door.f<<wall<<edge;}
    if(t == 'a')
    {cout<<edge<<wall<<room.door.f<<wall;}
    else if(t == 'y')
    {cout<< '|'<<blanck<<' '<<blanck<<'|';}
    else if(t == 'b')
    {cout<< '|'<<blanck<<' '<<blanck;}
    else if(t == 'x'){cout<<room.door.l<<blanck<<room.type<<blanck<<room.door.r;}
    else if(t == 'c')
    {cout<<room.door.l<<blanck<<room.type<<blanck;}
    else if (t == 'w')
    {cout<<edge<<wall<<room.door.b<<wall<<edge;}
    else if (t == 'd')
    {cout<<edge<<wall<<room.door.b<<wall;};
    if(empty){cout<<endl;};};
void three(vector<vector<rooms>> board,int i, int j, bool empty,char a,char b,char c){
    aline(board[i][j-1], empty,a);
    aline(board[i][j  ], empty,b);
    aline(board[i][j+1], empty,c);};

void adisplay(vector<vector<rooms>> board,int i, int j){
    aline(board[i][j], true,'y');
    aline(board[i][j], true,'y');
    aline(board[i][j], true,'x');
    aline(board[i][j], true,'y');
    aline(board[i][j], true,'y');
};
void bdisplay(vector<vector<rooms>> board,int i, int j){
    three(board,i,j, false,'a','a','z');cout<<endl;
    for(int j = 0; j<2; j++){
        three(board,i,j, false,'b','b','y');cout<<endl;};
    three(board,i,j, false,'c','c','x');cout<<endl;
    for(int j = 0; j<2; j++){
        three(board,i,j, false,'b','b','y');cout<<endl;};
    three(board,i,j, false,'d','d','z');cout<<endl;
};
void display(vector<vector<rooms>> board,int i, int j){
    aline(board[i-1][j], true,'z');
    adisplay(board,i-1,j);
    bdisplay(board,i,j);
    adisplay(board,i+1,j);
    aline(board[i+1][j], true,'w');
};
