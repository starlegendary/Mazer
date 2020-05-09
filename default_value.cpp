#include "datas.h"
status Player;
status Monster;
map<string, status> items;

status MakeStatus(int x ,int y ,int h ,int d , int v){
  status c ;
  c.pos.x = x;
  c.pos.y = y;
  c.h = h;
  c.d = d;
  c.v = v;
  return c;
}

void define_items(){
  items["Accelerator-Front"] = MakeStatus(0,-2,0,0,0);
  items["Accelerator-Back"] = MakeStatus(0,2,0,0,0);
  items["Accelerator-Left"] = MakeStatus(-2,0,0,0,0);
  items["Accelerator-Right"] = MakeStatus(2,0,0,0,0);
  items["Potion(HP +5)"] = MakeStatus(0,0,5,0,0);
  items["Bandage(HP +5)"] = MakeStatus(0,0,5,0,0);
  items["Potion(HP +10)"] = MakeStatus(0,0,10,0,0);
  items["First Aid Kit(HP +10)"] = MakeStatus(0,0,10,0,0);
  items["Knife(DMG +10)"] = MakeStatus(0,0,0,10,0);
  items["Sword(DMG +20)"] = MakeStatus(0,0,0,20,0);
  items["Detector(V +1)"] = MakeStatus(0,0,0,0,1);
  items[" NULL"] = MakeStatus(0,0,0,0,0);
}

void define_player_monster(int S){
  srand(time(NULL));
  Player = MakeStatus(S-1,S-1,S*4,S,1);
  Monster = MakeStatus(rand()%(S-2),rand()%(S-2),S*16,S*2,0);
}

string random_item(int k){
  srand(k);
  auto it = items.begin();
  advance(it, rand() % items.size());
  string rditem_name = it->first;
  return rditem_name;
}

void add_door(rooms& room,int k){
  srand(k);
  room.door.f = rand()%5;
  room.door.b = rand()%5;
  room.door.l = rand()%5;
  room.door.r = rand()%5;
}
