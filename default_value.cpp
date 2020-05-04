#include "datas.h"
status Player;
status Moster;
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
  items["Potion(HP +10)"] = MakeStatus(0,0,10,0,0);
  items["Poison(HP -5)"] = MakeStatus(0,0,-5,0,0);
  items["Poison(HP -10)"] = MakeStatus(0,0,-10,0,0);
  items["Knife(DMG +10)"] = MakeStatus(0,0,0,10,0);
  items["Sword(DMG +20)"] = MakeStatus(0,0,0,20,0);
  items["Telescope(V +2)"] = MakeStatus(0,0,0,0,2);
  items["NULL"] = MakeStatus(0,0,0,0,0);
}

void define_player_moster(){
  Player = MakeStatus(5,5,50,5,1);
  Moster = MakeStatus(0,0,200,10,6);

}

string random_item(int k){
  srand(k);
  auto it = items.begin();
  advance(it, rand() % items.size());
  string rditem_name = it->first;
  return rditem_name;
}

void add_door(rooms& room){
  srand(time(NULL));
  room.door.f = rand()%5;
  room.door.b = rand()%5;
  room.door.l = rand()%5;
  room.door.r = rand()%5;
}
