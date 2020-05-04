#include "datas.h"

void move(status& player, status& item){
  player.pos.x += item.pos.x;
  player.pos.y += item.pos.y;
  player.h += item.h;
  player.d += item.d;
  player.v += item.v;
}
