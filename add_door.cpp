#include "datas.h"

void add_door(rooms room){
  srand(time(NULL));
  room.door.f = rand()%5;
  room.door.b = rand()%5;
  room.door.l = rand()%5;
  room.door.r = rand()%5;
}
