#include <iostream>
#include <map>
#include <string>
#include "datas.h"
using namespace std;

void background(string name)
{
    cout << "";
};
void config(short size){

};
int main()
{

    string name;
    short size;

    cin >> name;
    background(name);
    cin >> size;
    config(size);
    cout << "Start Playing...";

    return 0;
}