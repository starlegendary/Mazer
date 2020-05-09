#include "datas.h"
void fight_with_monster(vector<vector<rooms>> board,status& Monster,status& Player,int S){
  string c;
  a_sec();
  b_sec("            Monster is here !!!!         ");
  b_sec("               Fight or Die ?            ");
  b_sec("Type 1 to fight      |      Type 2 to die");
  cout << "Input Command: ";
  cin >> c;
  while ( true ){
    if ( c == "1" ){
      cin.get();
      a_sec();
      b_sec("        You attack the Monster !!        ");

      cout << " HP of Monster: "<< Monster.h <<" - "<< Player.d;
      Monster.h -= Player.d;
      cout <<  " = " <<  Monster.h << endl;
      cin.get();

      if (Monster.h <= 0){
        a_sec();
        b_sec("             The Monster died ...        ");
        Player.pos.x = 0;
        Player.pos.y = 0;
        break;

      }else{

        a_sec();
        b_sec("      The Monster counterattacks you !!! ");

        cout << " HP of You: "<< Player.h <<" - "<< Monster.d;
        Player.h -= Monster.d;
        cout <<  " = " <<  Player.h << endl;
        cin.get();

        if (Player.h <=0){
          a_sec();
          b_sec("                 You died ...            ");
          break;
        }else{

          a_sec();
          b_sec("    It is lucky that you haven't died... ");
          b_sec("                However...               ");
          b_sec("    Monster takes you back to thr origin.");

          board[Player.pos.x][Player.pos.y].type.replace(0,1," ");
          Player.pos.x = S-1; Player.pos.y = S-1;
          Monster.pos.x = rand()%(S-2);Monster.pos.y = rand()%(S-2);
          board[Player.pos.x][Player.pos.y].type.replace(0,1,"@");
          Print_info(board,S,Player);
          break;
        }
      }
    }else if( c == "2"){
      Player.h = 0;
      break;
    }else{
      a_sec();
      b_sec("     There is no the third choice...     ");
      b_sec("Type 1 to fight      |      Type 2 to die");
      cout << "Input Command: ";
      cin >> c;
    }
  }
}
