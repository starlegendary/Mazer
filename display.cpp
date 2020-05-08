#include "datas.h"

using namespace std;

string space = "     ";
string corn = "+";
string wall = "-----";
string brick= "|"+space+" "+space+"|";

void nth(){cout<<" "<< space
<<" " <<space<<" ";}
void a(bool sth, vector<vector<rooms>> board,int i, int j){
    if(sth) cout<<corn<<wall<<board[i][j].door.f<<wall<<corn;else nth();}
void c(bool sth, vector<vector<rooms>> board,int i, int j){
    if(sth) cout<<board[i][j].door.l<<space<<board[i][j].type<<space<<board[i][j].door.r;else nth();}
void d(bool sth, vector<vector<rooms>> board,int i, int j){
    if(sth) cout<<corn<<wall<<board[i][j].door.b<<wall<<corn;else nth();}
void b(bool sth, vector<vector<rooms>> board,int i, int j){
    if(sth) cout<<brick;else nth();}
bool inside(int i,int j,int S){return(j < S)&&(j >= 0)&&(i >= 0)&&(i < S);}

void one(void (*f)(bool, vector<vector<rooms>>, int, int ),bool sth,vector<vector<rooms>> board,int i, int j,int S){
    (*f)((inside(i-1,j,S) && sth),board,i-1,j);
    (*f)((inside(i  ,j,S))       ,board,i  ,j);
    (*f)((inside(i+1,j,S) && sth),board,i+1,j);cout<<endl;
    }
void three(bool sth,vector<vector<rooms>> board,int i, int j, int S){
    one(a,sth,board,i,j,S);one(b,sth,board,i,j,S);one(b,sth,board,i,j,S);
    one(c,sth,board,i,j,S);one(b,sth,board,i,j,S);one(b,sth,board,i,j,S);
    one(d,sth,board,i,j,S);
    }
void display(vector<vector<rooms>> board,int i, int j , int S){
    three(false,board,i,j-1,S);three(true ,board,i,j,S);three(false,board,i,j+1,S);
    }
