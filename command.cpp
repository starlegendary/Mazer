#include "datas.h"

vector<string> player_items;
extern map<string, status> items;
void move(status& player, status& item){
  player.pos.x += item.pos.x;
  player.pos.y += item.pos.y;
  player.h += item.h;
  player.d += item.d;
  player.v += item.v;
}

void Print_info(vector<vector<rooms>> board,int S, status& Player){

  cout << "Your items: " << endl;
  for(int i = 0; i < player_items.size(); i++)
  {
    cout << i+1 <<" "<< player_items[i] << endl;
  }
  cout << "----------------------------------------------------" << endl;
  cout << "Your Position: ("<< Player.pos.x << "," << Player.pos.y << ")" << endl;
  display(board,Player.pos.x,Player.pos.y,S);
  cout << "----------------------------------------------------" << endl;
  cout<<"Health Point: "<<Player.h<<"; Damage: "<<Player.d<<"; Visibility: "<<Player.v<<endl;
  cout << "----------------------------------------------------" << endl;
}

void setup_doors_items(vector<vector<rooms>>& board,int S){
  string temp_item;
  srand(time(NULL));
  int k = rand()%100;

  for(int i = 0; i < S; i++ ){
    for(int j = 0; j < S; j++ ){
      add_door(board[i][j],k);
      k += rand()%100;
      if (!((i == 0 &&  j == 0) || (i == S-1 &&  j == S-1))){
        temp_item = random_item(k);
        k += rand()%100;
        board[i][j].item_name.replace(0,4,temp_item);
        board[i][j].type.replace(0,1,temp_item.substr(0,1));
      }
    }
  }
}

void move_and_loseHP(status& Player,status command,int t, int limit, int xy){
  if (xy != limit){
    move(Player,command);
    Player.h -= t;
  }else{
    cout << "[WARNING][WARNING]You cannot move ![WARNING][WARNING]" << endl;
    cout << "----------------------------------------------------" << endl;
  }
}

bool check(status Player,string item,int S){
  if (item == "Accelerator-Front" &&  Player.pos.y <= 1){
    return 0;
  }else if (item == "Accelerator-Back" && Player.pos.y >= S-2){
    return 0;
  }else if (item == "Accelerator-Left" &&  Player.pos.x <= 1){
    return 0;
  }else if (item == "Accelerator-Right" && Player.pos.x >= S-2){
    return 0;
  }else{ return 1; }
}

void use_item(status& Player,int S){
  int nth_item;
  cin >> nth_item;

  if (nth_item <= player_items.size() && nth_item > 0){// check the exist of item
      if(check(Player,player_items[nth_item-1],S)){
        cout<< "You used the item -- "<<player_items[nth_item-1]<<"."<<endl;
        cout << "----------------------------------------------------" << endl;
        move(Player,items[player_items[nth_item-1]]);
        player_items.erase(player_items.begin()+nth_item-1);
      }else{
        cout<<player_items[nth_item-1]<<" cannot be used."<<endl;
        cout << "----------------------------------------------------" << endl;
      }
  }else{
    cout << "[WARNING][WARNING]Item Not Exist ![WARNING][WARNING]" << endl;
    cout << "----------------------------------------------------" << endl;
  }

}

void pick_item(vector<vector<rooms>>& board,status& Player){
  if( board[Player.pos.x][Player.pos.y].item_name != "NULL"){// pick the item in the current board
    cout <<  "You pick up an item: " << board[Player.pos.x][Player.pos.y].item_name << endl;
    cout << "----------------------------------------------------" << endl;
    player_items.push_back(board[Player.pos.x][Player.pos.y].item_name);
    board[Player.pos.x][Player.pos.y].item_name.replace(0,board[Player.pos.x][Player.pos.y].item_name.length(),"NULL");
    board[Player.pos.x][Player.pos.y].type.replace(0,1,"N");
  }
}

int distance(status Monster,status Player){
  int x,y;
  x = (Monster.pos.x-Player.pos.x)*(Monster.pos.x-Player.pos.x);
  y = (Monster.pos.y-Player.pos.y)*(Monster.pos.y-Player.pos.y);
  return x+y;
}

void Visibility(status Monster,status Player){
  cout << "----------------------------------------------------" << endl;
  if (distance(Monster,Player) <= 4){
    cout << "|                     ROAR!!!!!                    |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|          You hear the roar of Monster!           |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|        Be careful !  Monster is nearby !!!       |" << endl;
    cout << "----------------------------------------------------" << endl;
  }else if(Player.v >= 2 &&  distance(Monster,Player) <= 16){
    cout << "|                 Thud...Thud...                   |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|          You hear the step of Monster!           |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|           Monster is closing to you.             |" << endl;
    cout << "----------------------------------------------------" << endl;
  }else if(Player.v >=3 && distance(Monster,Player) <= 32){
    cout << "|                 Fizz...Fizz...                   |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|    You hear a little noise from the Monster      |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|           Monster is still away from you.        |" << endl;
    cout << "----------------------------------------------------" << endl;
  }else{
    cout << "|                       ...                        |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|         You hear nothing, it is quiet...         |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|         Hope that Monster is not nerby           |" << endl;
    cout << "----------------------------------------------------" << endl;
  }
}
