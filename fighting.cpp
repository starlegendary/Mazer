#include "datas."
void fight_with_monster(vector<vector<rooms>> board,status& Monster,status& Player,int S){
  string c;
  cout << "----------------------------------------------------" << endl;
  cout << "|               Monster is here !!!!               |" << endl;
  cout << "----------------------------------------------------" << endl;
  cout << "|                  Fight or Die ?                  |" << endl;
  cout << "----------------------------------------------------" << endl;
  cout << "|   Type 1 to fight      |      Type 2 to die      |" << endl;
  cout << "----------------------------------------------------" << endl;
  cout << "Input Command: ";
  cin >> c;
  while ( true ){
    if ( c == "1" ){
      cin.get();
      cout << "----------------------------------------------------" << endl;
      cout << "|           You attack the Monster !!              |" << endl;
      cout << "----------------------------------------------------" << endl;

      cout << " HP of Monster: "<< Monster.h <<" - "<< Player.d;
      Monster.h -= Player.d;
      cout <<  " = " <<  Monster.h << endl;
      cin.get();

      if (Monster.h <= 0){
        cout << "----------------------------------------------------" << endl;
        cout << "|                The Monster died ...              |" << endl;
        Player.pos.x = 0;
        Player.pos.y = 0;
        break;

      }else{

        cout << "----------------------------------------------------" << endl;
        cout << "|         The Monster counterattacks you !!!       |" << endl;
        cout << "----------------------------------------------------" << endl;

        cout << " HP of You: "<< Player.h <<" - "<< Monster.d;
        Player.h -= Monster.d;
        cout <<  " = " <<  Player.h << endl;
        cin.get();

        if (Player.h <=0){
          cout << "----------------------------------------------------" << endl;
          cout << "|                    You died ...                  |" << endl;
          break;
        }else{

          cout << "----------------------------------------------------" << endl;
          cout << "|       It is lucky that you haven't died...       |" << endl;
          cout << "----------------------------------------------------" << endl;
          cout << "|                   However...                     |" << endl;
          cout << "----------------------------------------------------" << endl;
          cout << "|       Monster takes you back to thr origin.      |" << endl;
          cout << "----------------------------------------------------" << endl;

          Player.pos.x = S-1;
          Player.pos.y = S-1;
          Print_info(board,S,Player);
          break;
        }
      }
    }else if( c == "2"){
      Player.h = 0;
      break;
    }else{
      cout << "----------------------------------------------------" << endl;
      cout << "|        There is no the third choice...           |" << endl;
      cout << "----------------------------------------------------" << endl;
      cout << "|   Type 1 to fight      |      Type 2 to die      |" << endl;
      cout << "----------------------------------------------------" << endl;
      cout << "Input Command: ";
      cin >> c;
    }
  }
}
