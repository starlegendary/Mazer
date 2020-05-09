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
    cout << "*               Game Project: Mazer                *" << endl;
    cout << "****************************************************" << endl <<endl;

    int S,x,y;
    int count = 0;
    
    a_sec();
    cout << "Choose the difficulties of the game(6-20): ";
    cin >> S;
    while(!(S>=6 && S<=20)){
      cout << "Choose the difficulties of the game(6-20): ";
      cin >> S;
    }
    a_sec();
    print("Stars, hide your fires; Let not light see my black and deep desires. -- William Shakespea", true); enter();
    print("You wake up... there is nothing but darkness.", true); enter();
    print("'This is the maze.' You hear a voice.", true); enter();
    print("'Escape or kill the monster' The voice continues.", true); enter();
    print("'This damn wall must be talking cause man I can hear them.' You think to yourself.", true); enter();
    print("'You struggle to stand up... Your journey start here.", true); enter();
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
          if(count == 1) 

          cout << "Intput Command Below (front/ left/ right/ back/ use + item no. ): " <<endl;
          cin >> command;
          a_sec(); a_sec();


          if(command == "front"){
                count += 1;
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,front,board[Player.pos.x][Player.pos.y].door.f,0,Player.pos.y);
                board[x][y].door.f = 0;
          }else if(command == "back"){
                count += 1;
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,back,board[Player.pos.x][Player.pos.y].door.b,S-1,Player.pos.y);
                board[x][y].door.b = 0;
          }else if(command == "left"){
                count += 1;
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,left,board[Player.pos.x][Player.pos.y].door.l,0,Player.pos.x);
                board[x][y].door.l = 0;
          }else if(command == "right"){
                count += 1;
                x=Player.pos.x;y=Player.pos.y;
                move_and_loseHP(Player,right,board[Player.pos.x][Player.pos.y].door.r,S-1,Player.pos.x);
                board[x][y].door.r = 0;
          }else if(command == "use"){
                use_item(Player,S);
          }else{
                b_sec("HAHAHA!!! You just waste a round man.");
          }

          srand(time(NULL));
          for ( int r = rand() % 2 ; r > 0 ; r--){
            Monster.pos = movement(Monster.pos,Player.pos);
            Monster.h -= 4;
          }
          
          if (count == 1){
              b_sec(" hp is reduced ahhh ");
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
