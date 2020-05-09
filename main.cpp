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
    status front = MakeStatus( 0,-1,0,0,0);
    status back  = MakeStatus( 0, 1,0,0,0);
    status left  = MakeStatus(-1, 0,0,0,0);
    status right = MakeStatus( 1, 0,0,0,0);

    //start game
    cout << "****************************************************" << endl;
    cout << "*                   Game Started                   *" << endl;
    cout << "****************************************************" << endl <<endl;
    cout << "[Some background information here.....] " << endl;

    int S ;
    a_sec();
    cout << "Input the size of the maze: ";
    cin >> S;
    while(!(S>=6 && S<=20)){
      cout << "Input the size of the maze: ";
      cin >> S;
    }
    
    vector<vector<rooms>> board(S, vector<rooms>(S));

    define_items();
    define_player_monster(S);

    player_items.clear();
    setup_doors_items(board,S);
    board[Player.pos.x][Player.pos.y].type.replace(0,1,"@");
    Print_info(board,S,Player);

    board[S-1][S-1].type.replace(0,1,"#");
    board[0][0].type.replace(0,1,"#");

    while(!((Player.h <= 0) || (Player.pos.x == 0 && Player.pos.y == 0)) && Monster.h > 0){

      if (!(Player.pos.x == Monster.pos.x &&  Player.pos.y == Monster.pos.y )){

          pick_item(board,Player);

          cout << "Intput Command Below (front/ left/ right/ back/ use + item no. ): " <<endl;
          cin >> command;
          a_sec(); a_sec();


          if(command == "front"){
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,front,board[Player.pos.x][Player.pos.y].door.f,0,Player.pos.y);
                board[x][y].door.f = 0;
          }else if(command == "back"){
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,back,board[Player.pos.x][Player.pos.y].door.b,S-1,Player.pos.y);
                board[x][y].door.b = 0;
          }else if(command == "left"){
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,left,board[Player.pos.x][Player.pos.y].door.l,0,Player.pos.x);
                board[x][y].door.l = 0;
          }else if(command == "right"){
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,right,board[Player.pos.x][Player.pos.y].door.r,S-1,Player.pos.x);
                board[x][y].door.r = 0;
          }else if(command == "use"){
                use_item(Player,S);
          }else{
                b_sec("Invalid !!");
          }

          srand(time(NULL));
          for ( int r = rand() % 2 ; r > 0 ; r--){
            Monster.pos = movement(Monster.pos,Player.pos);
            Monster.h -= 4;
          }
          if( !(Monster.pos.x == Player.pos.x && Monster.pos.y == Player.pos.y) ){Visibility(Monster,Player);}
          board[S-1][S-1].type.replace(0,1,"#");
          board[0][0].type.replace(0,1,"#");
          board[Player.pos.x][Player.pos.y].type.replace(0,1,"@");
          Print_info(board,S,Player);
          board[Player.pos.x][Player.pos.y].type.replace(0,1," ");

      }else{
        fight_with_monster(board,Monster,Player,S);
      }
    }

    if (Player.h <= 0){
      a_sec();
      b_sec("You lose!");
    }else if (Player.pos.x == 0 && Player.pos.y == 0){
      a_sec();
      b_sec("You win !");
    }
    return 0;
}
