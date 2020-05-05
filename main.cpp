#include <iostream>
#include <map>
#include <string>
#include "datas.h"

using namespace std;

extern status Player;
extern status Monster;
extern map<string, status> items;
vector<string> player_items;


int main(){
    int S = 6;
    vector<vector<rooms>> board(S, vector<rooms>(S));
    string command;
    string temp_item;
    int nth_item;
    status front = MakeStatus(0,-1,0,0,0);
    status back = MakeStatus(0,1,0,0,0);
    status left = MakeStatus(-1,0,0,0,0);
    status right = MakeStatus(1,0,0,0,0);

    srand(time(NULL));
    int k = rand()%100;
    define_items();
    define_player_monster();;
    board[S-1][S-1].type.replace(0,1,"#");
    board[0][0].type.replace(0,1,"#");

    player_items.clear();

    for(int i = 0; i < S; i++ ){ // SET RANDOM ITEM IN EACH BOARD EXPECT THE START POINT AND THE END POINT
      for(int j = 0; j < S; j++ ){
        add_door(board[i][j]);
        if (!((i == 0 &&  j == 0) || (i == S-1 &&  j == S-1))){
          temp_item = random_item(k);
          k += rand()%100;
          board[i][j].item_name.replace(0,4,temp_item);
          board[i][j].type.replace(0,1,temp_item.substr(0,1));
        }
      }
    }
    //start game
    cout << "********Game Started********" << endl;
    cout << "[Some background information here.....] " << endl;
    cout << "Your Position: ("<< S-1 << "," << S-1 << ")" << endl;
    display(board,S-1,S-1);
    cout<<"HP: "<<Player.h<<"; Damage: "<<Player.d<<"; Visibility: "<<Player.v<<endl;

    while(!((Player.h == 0) || (Player.pos.x == 0 && Player.pos.y == 0))){

      if (!(Player.pos.x == Monster.pos.x &&  Player.pos.y == Monster.pos.y )){
          if( board[Player.pos.x][Player.pos.y].item_name != "NULL"){// pick the item in the current board
            cout <<  "You pick up an item: " << board[Player.pos.x][Player.pos.y].item_name << endl;
            player_items.push_back(board[Player.pos.x][Player.pos.y].item_name);
            board[Player.pos.x][Player.pos.y].item_name.replace(0,board[Player.pos.x][Player.pos.y].item_name.length(),"NULL");
            board[Player.pos.x][Player.pos.y].type.replace(0,1,"N");
          }

          cout << "Intput Command: " ;
          cin >> command;
          if(command == "front"){
            if (Player.pos.y != 0){
              move(Player,front);
              Player.h -= board[Player.pos.x][Player.pos.y].door.f;
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "back"){
            if (Player.pos.y != S-1){
              move(Player,back);
              Player.h -= board[Player.pos.x][Player.pos.y].door.b;
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "left"){
            if (Player.pos.x != 0){
              move(Player,left);
              Player.h -= board[Player.pos.x][Player.pos.y].door.l;
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "right"){
            if (Player.pos.x != S-1){
              move(Player,right);
              Player.h -= board[Player.pos.x][Player.pos.y].door.r;
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "use"){

            cin >> nth_item;
            if (nth_item <= player_items.size() && nth_item > 0){// check the exist of item
              cout<< "You used the item"<<endl;
              move(Player,items[player_items[nth_item-1]]);
              player_items.erase(player_items.begin()+nth_item-1);
            }else{
              cout << "********You cannot use it !********" << endl;
            }
          }

      }else{

        //fighting with monster
      }
      cout << "Your items: " << endl;
      for(int i = 0; i < player_items.size(); i++)
      {
        cout << i+1 <<" "<< player_items[i] << endl;
      }
      cout << "Your Position: (" << Player.pos.x <<","<<Player.pos.y<<")"<< endl;
      display(board,Player.pos.x,Player.pos.y);
      cout<<"HP: "<<Player.h<<"; Damage: "<<Player.d<<"; Visibility: "<<Player.v<<endl;

    }
    if (Player.h == 0){
      cout<<"You lose!"<<endl;
    }else if (Player.pos.x == 0 && Player.pos.y == 0){
      cout<<"You win!"<<endl;
    }

    return 0;
}
