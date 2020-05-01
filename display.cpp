#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "datas.h"

using namespace std;

void nth(bool sth){if(sth) cout<<" "<< space <<" " <<space<<" ";};
void end(bool sth){if(sth) cout<<endl;}
void aaa(bool sth, vector<vector<rooms>> board,int i, int j){
    if(sth) cout<<corn<<wall<<board[i][j].door.f<<wall<<corn; else nth(true);};
void abc(bool sth, vector<vector<rooms>> board,int i, int j){
    if(sth) cout<<board[i][j].door.l<<space<<board[i][j].type<<space<<board[i][j].door.r; else nth(true);};
void ccc(bool sth, vector<vector<rooms>> board,int i, int j){
    if(sth) cout<<corn<<wall<<board[i][j].door.b<<wall<<corn; else nth(true);};
void b(bool sth){if(sth) cout<<brick; else nth(true);};
bool inside(int i, int j){
    return ((j < S)&&(j >= 0)&&(i >= 0)&&(i < S));
};

void bbb(bool sth,vector<vector<rooms>> board,int i, int j){
    b((sth && inside(i-1,j)));
    b((inside(i  ,j)));
    b((sth && inside(i+1,j)));end(true);
    b((sth && inside(i-1,j)));
    b((inside(i  ,j)));
    b((sth && inside(i+1,j)));end(true);
};

void top(bool sth,vector<vector<rooms>> board,int i, int j){
    aaa((sth && inside(i-1,j)),board,i-1,j);
    aaa((inside(i  ,j)),board,i  ,j);
    aaa((sth && inside(i+1,j)),board,i+1,j);end(true);
};
void bot(bool sth,vector<vector<rooms>> board,int i, int j){
    ccc((sth && inside(i-1,j)),board,i-1,j);
    ccc((inside(i  ,j)),board,i  ,j);
    ccc((sth && inside(i+1,j)),board,i+1,j);end(true);
};
void mid(bool sth,vector<vector<rooms>> board,int i, int j){
    abc((sth && inside(i-1,j)),board,i-1,j);
    abc((inside(i  ,j)),board,i  ,j);
    abc((sth && inside(i+1,j)),board,i+1,j);end(true);
};
void display(vector<vector<rooms>> board,int i, int j){
    top(false,board,i,j-1);bbb(false,board,i,j-1);
    mid(false,board,i,j-1);bbb(false,board,i,j-1);
    bot(false,board,i,j-1);
    top(true,board,i,j);bbb(true,board,i,j);
    mid(true,board,i,j);bbb(true,board,i,j);
    bot(true,board,i,j);
    top(false,board,i,j+1);bbb(false,board,i,j+1);
    mid(false,board,i,j+1);bbb(false,board,i,j+1);
    bot(false,board,i,j+1);
};
