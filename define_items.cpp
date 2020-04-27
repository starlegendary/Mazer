#include "datas.h"

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
  items["Accelerator-Front"] = MakeStatus(0,2,0,0,0);
  items["Accelerator-Back"] = MakeStatus(0,-2,0,0,0);
  items["Accelerator-Left"] = MakeStatus(-2,0,0,0,0);
  items["Accelerator-Right"] = MakeStatus(2,0,0,0,0);
  items["Potion(HP +5)"] = MakeStatus(0,0,5,0,0);
  items["Potion(HP +10)"] = MakeStatus(0,0,10,0,0);
  items["Poison(HP -5)"] = MakeStatus(0,0,-5,0,0);
  items["Poison(HP -10)"] = MakeStatus(0,0,-10,0,0);
  items["Knife(DMG +10)"] = MakeStatus(0,0,0,10,0);
  items["Sword(DMG +20)"] = MakeStatus(0,0,0,20,0);
  items["Telescope(V +2)"] = MakeStatus(0,0,0,0,2);
}
