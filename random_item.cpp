#include "datas.h"

string random_item(){
  srand(time(NULL));
  auto it = items.begin();
  advance(it, rand() % items.size());
  string rditem_name = it->first;
  return rditem_name;
}
