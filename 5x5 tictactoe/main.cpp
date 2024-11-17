#include<iostream>
#include<vector>
#include<string>
#include "greet.h"
#include "board_function.h"

using namespace std;

vector<vector<char>> board(6, vector<char> (6,'_'));
vector<vector<string>> color(6, vector<string> (6, "White"));
// 2-d vector to signify color

signed main(){
    int player_style = _greet();
    // 1 is one player, 2 is multiplayer
    print_board(board, color);

    if(player_style == 1) one_player(board,color);
    else multiplayer(board, color);

}





//cout << RED << j << RESET <<  " ";
