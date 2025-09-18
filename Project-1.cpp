#include<iostream>
#include<vector>
using namespace std;

class Tictactoe{
  private:
  vector<vector<char>> board; 
  int count ;
 public :

  
  Tictactoe(){
  board = vector<vector<char>>(3 , vector<char>(3 , ' ')) ;
  count  = 0 ; 
}
  void displayBoard(){
    cout<<endl ;
    for(int i = 0 ; i < 3 ; i++){
      for (int j = 0 ; j < 3 ; j++){
         cout<<board[i][j] ;
        if( j < 2 ){
          cout << " | " ; 
        }
        }
        cout<<endl ;
        if(i<2){
          cout<<"--+---+--";
      }
      cout<<endl ;
    }
  }
  bool validMove(int cell ,  char playerSymbol){
    int  row  = (cell - 1)/3 ;
    int col = (cell -1 ) % 3 ;
    if (cell < 1 || cell > 9){
      cout<< "Invalid Move " ;
      return false  ;
    }
    if (board[row][col] != ' ') {
    cout << "Cell already taken! Try again.\n";
    return false;
}
    board[row][col] = playerSymbol ;
    count++ ;
    return true ; 
    }
bool WInner(char playerSymbol){
          for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol) ||
                (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)) {
                  return true ; 
              }
            }
             if ((board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) ||
            (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)) {
            return true;
            }
            return false ; }

            bool isDRAW(){
              return count >= 9 ;
            }

            void PlayGame(const string& player1, const string& player2){
              char currentPlayer = 'X';
              string currentPlayerName = player1 ; 
              cout<<"Welcome to tic tac toe , "<< player1 <<"(X) and "<<player2 <<"(O) \n" ;
              displayBoard();
              while(true){
              int cell ;
              cout<<currentPlayerName<< " Your turn " ; 
              cin >> cell ;
              if(!validMove(cell , currentPlayer)){
                continue ;
              }
              displayBoard() ;
              if (WInner(currentPlayer)){
                cout << "Congratulations"<<currentPlayerName<<" you  won the game"<<endl ;
                break ; 
              }
              if(isDRAW()){
                cout<<"OH both have same potential"<<endl ;
                break ;
              }
              if(currentPlayer =='X'){
                currentPlayer = 'O' ;
                currentPlayerName = player2 ;
              }
              else{
                currentPlayer = 'X' ;
                currentPlayerName = player1 ; 
              }
            }
            }
};

int main(){
string player1 , player2  ;
cout<<"Enter your name player 1 : ";
cin>>player1 ;
cout<<"Enter your name player 2 : ";
cin>>player2 ;
Tictactoe game ;
game.PlayGame(player1 ,player2) ;

return 0;
}