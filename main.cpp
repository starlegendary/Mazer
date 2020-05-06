#include <iostream>
#include <map>
#include <string>
#include "datas.h"

using namespace std;

extern status Player;
extern status Monster;
extern map<string, status> items;
extern vector<string> player_items;


int main(){

    string command;
    status front = MakeStatus(0,-1,0,0,0);
    status back = MakeStatus(0,1,0,0,0);
    status left = MakeStatus(-1,0,0,0,0);
    status right = MakeStatus(1,0,0,0,0);

    //start game
    cout << "****************************************************" << endl;
    cout << "*                   Game Started                   *" << endl;
    cout << "****************************************************" << endl <<endl;
    cout << "[Some background information here.....] " << endl;

    int S ;
    cout << "----------------------------------------------------" << endl;
    cout << "Input the size of the maze: ";
    cin >> S;
    vector<vector<rooms>> board(S, vector<rooms>(S));

    define_items();
    define_player_monster(S);;
    board[S-1][S-1].type.replace(0,1,"#");
    board[0][0].type.replace(0,1,"#");

    player_items.clear();
    setup_doors_items(board,S);

    Print_info(board,S,Player);

    while(!((Player.h <= 0) || (Player.pos.x == 0 && Player.pos.y == 0)) && Monster.h > 0){

      if (!(Player.pos.x == Monster.pos.x &&  Player.pos.y == Monster.pos.y )){

          pick_item(board,Player);

          cout << "Intput Command: " ;
          cin >> command;
          cout << "----------------------------------------------------" << endl;
          cout << "----------------------------------------------------" << endl;


          if(command == "front"){
                move_and_loseHP(Player,front,board[Player.pos.x][Player.pos.y].door.f,0,Player.pos.y);

          }else if(command == "back"){
                move_and_loseHP(Player,back,board[Player.pos.x][Player.pos.y].door.b,S-1,Player.pos.y);

          }else if(command == "left"){
                move_and_loseHP(Player,left,board[Player.pos.x][Player.pos.y].door.l,0,Player.pos.x);

          }else if(command == "right"){
                move_and_loseHP(Player,right,board[Player.pos.x][Player.pos.y].door.r,S-1,Player.pos.x);

          }else if(command == "use"){
                use_item(Player,S);
          }
          Visibility(Monster,Player);
          Print_info(board,S,Player);

      }else{

        fight_with_monster(board,Monster,Player,S);
      }
    }

    if (Player.h <= 0){
      cout << "----------------------------------------------------" << endl;
      cout << "|                     You lose!                    |" << endl;
      cout << "----------------------------------------------------" << endl;
    }else if (Player.pos.x == 0 && Player.pos.y == 0){
      cout << "----------------------------------------------------" << endl;
      cout << "|                     You win !                    |" << endl;
      cout << "----------------------------------------------------" << endl;
    }

    return 0;
}
