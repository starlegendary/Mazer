#include <iostream>
#include <map>
#include <string>
#include "datas.h"

using namespace std;

extern status Player;
extern status Moster;
extern map<string, status> items;
map<int,string> player_items;


int main(){
    int S = 6;
    vector<vector<rooms>> board(S, vector<rooms>(S));
    string command;
    string temp_item;
    int num_of_item = 1;
    int nth_item;
    status front = MakeStatus(0,-1,0,0,0);
    status back = MakeStatus(0,1,0,0,0);
    status left = MakeStatus(-1,0,0,0,0);
    status right = MakeStatus(1,0,0,0,0);

    srand(time(NULL));
    int k = rand()%100;
    define_items();
    define_player_moster();;
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
    cout<<"HP: "<<Player.h<<"; Damage: "<<Player.d<<"; Visibilit: "<<Player.v<<endl;

    while(!((Player.h == 0) || (Player.pos.x == 0 && Player.pos.y == 0))){

      if (!(Player.pos.x == Moster.pos.x &&  Player.pos.y == Moster.pos.y )){
          if( board[Player.pos.x][Player.pos.y].item_name != "NULL"){// pick the item in the current board
            cout <<  "You pick up an item: " << board[Player.pos.x][Player.pos.y].item_name << endl;
            player_items[num_of_item] = board[Player.pos.x][Player.pos.y].item_name;
            num_of_item++;
            board[Player.pos.x][Player.pos.y].item_name.replace(0,board[Player.pos.x][Player.pos.y].item_name.length(),"NULL");
            board[Player.pos.x][Player.pos.y].item_name.replace(0,1,"N");
          }

          cout << "Intput Command: " ;
          cin >> command;
          if(command == "front"){
            if (Player.pos.y != 0){
              move(Player,front);
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "back"){
            if (Player.pos.y != S-1){
              move(Player,back);
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "left"){
            if (Player.pos.x != 0){
              move(Player,left);
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "right"){
            if (Player.pos.x != S-1){
              move(Player,right);
            }else{
              cout << "********You cannot move !********" << endl;
            }
          }else if(command == "use"){
            // check the exist of item
            cin >> nth_item;
            move(Player,items[player_items[nth_item]]);
            // del the item from the player item list
          }

      }else{

        //fighting with moster
      }
      cout << "Your items: " << endl;
      for(auto it = player_items.cbegin(); it != player_items.cend(); ++it)
      {
        cout << it->first <<" "<< it->second << endl;
      }
      cout << "Your Position: (" << Player.pos.x <<","<<Player.pos.y<<")"<< endl;
      display(board,Player.pos.x,Player.pos.y);
      cout<<"HP: "<<Player.h<<"; Damage: "<<Player.d<<"; Visibilit: "<<Player.v<<endl;

    }
    if (Player.h == 0){
      cout<<"You lose!"<<endl;
    }else if (Player.pos.x == 0 && Player.pos.y == 0){
      cout<<"You win!"<<endl;
    }

    return 0;
}
