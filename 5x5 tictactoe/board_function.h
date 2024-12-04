#include<iostream>
#include<vector>
#include<string>
#include <chrono>
#include <thread>
#include "common.h"
#include "check_winner.h"

#define y first
#define x second

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */

/*
#define RESET   ""
#define RED     ""      
#define BLUE    ""      
*/

using namespace std;

void print_board(vector<vector<char>> &board, vector<vector<string>> &color){
    cout << "   ";
    for(int i = 1; i < sz; i++) cout << i << " ";
    cout << "\n";

    for(int i = 1; i < sz; i++){
        // i is vertical, j is horizon
        cout << i << "  ";
        for(int j = 1; j < sz; j++){
            if(color[i][j] == "White") cout << board[i][j] << " ";
            else if(color[i][j] == "Blue") cout << BLUE << board[i][j] << RESET << " ";
            else cout << RED << board[i][j] << RESET << " ";
        }
        cout << endl;
    }
}

bool board_visited[sz][sz];

pair<int,int> user_move;
// fi is vertical, se is horizon

int input_is_valid(string inp){
    bool check = false;
    
    if(inp.size() == 1 && isdigit(inp[0])) check = true;
    // check if string size is one and the first character is a number
    
    if(check == false) return -1;

    int ans = inp[0] - '0';
    // convert string to int

    if(ans <= 0 || ans >= sz) return -1;
    // check in range
    return ans;
}
 
void get_input(vector<vector<char>> &board, vector<vector<string>> &color, string player){
    while(true) {
        string defensive_inp_1, defensive_inp_2; 
        cout << player << "\n";
        cout << "Vertical: ";
        cin >> defensive_inp_1;
        cout << "Horizon: ";
        cin >> defensive_inp_2;

        //cout << user_move.y << " " << user_move.x << "\n";
        user_move.y = input_is_valid(defensive_inp_1);
        user_move.x = input_is_valid(defensive_inp_2);

        if(user_move.y == -1 || user_move.x == -1){
            // if the user output sth with sz > 1 or non-number -> do it again
            cout << "Invalid input" << endl;
            continue;
        }

        if(board_visited[user_move.y][user_move.x] == 1){
            cout << "Position Has Already Been Taken \n";
            this_thread::sleep_for(chrono::milliseconds(wait_time));
        }
        else{
            board_visited[user_move.y][user_move.x] = 1;
            break;
            // input is valid
        }
    } 

    if(player == "Player 1"){
        color[user_move.y][user_move.x] = "Red";
        board[user_move.y][user_move.x] = 'O';
    }
    else{
        color[user_move.y][user_move.x] = "Blue";
        board[user_move.y][user_move.x] = 'X';
    }
}

void multiplayer(vector<vector<char>> &board, vector<vector<string>> &color, string player){
    int number_of_move_made = 0;

    while(number_of_move_made < 25){
        get_input(board,color,player);
        // if there is not a winner yet, we on playing
        print_board(board,color);

        bool _is_there_a_winner = is_there_a_winner(board);
        if(_is_there_a_winner == true){
            cout << "Congratulations, " << player << " won!";
            return; 
        }

        if(player == "Player 1") player = "Player 2";
        else if (player == "Player 2") player = "Player 1";
        number_of_move_made++;
        // shift between players
    }
    
    cout << "Hmmm, there seems to be no winner.....\n";
}

void bot_move(int x, int y, vector<vector<char>> &board, vector<vector<string>> &color  )
{
    user_move.y = y;
    user_move.x = x;
    color[user_move.y][user_move.x] = "Red";
    board[user_move.y][user_move.x] = 'O';
    board_visited[user_move.y][user_move.x] = true;
    cout << "Bot move: (" << x << ", " << y << ")" << endl;
}
void bot_algo(vector<vector<char>> &board, vector<vector<string>> &color)
{
    bool move = false;

    if (board[1][1] == '_')
    {
        bot_move(1, 1, board, color);
        return;
    }
    else if(board[sz-1][1] == '_')
    {
      bot_move(1, sz-1, board, color);
      return;
    }
    else if(board[1][sz-1] == '_')
    {
     bot_move(sz-1, 1, board, color);
     return;
    }

    for (int col = 1; col < sz; col++)
    {
        for (int row = 1; row < sz; row++)
        {
            if (board[col][row] == 'X')
            {
                if (col - 1 > 0 && board[col - 1][row] == '_')
                {
                    bot_move(row, col - 1, board, color);
                    move = true;
                    return;
                }
                else if (col + 1 < sz && board[col + 1][row] == '_')
                {
                    bot_move(row, col + 1, board, color);
                    move = true;
                    return;
                }
                else if (row + 1 < sz && board[col][row + 1] == '_')
                {
                    bot_move(row + 1, col, board, color);
                    move = true;
                    return;
                }
                else if (row - 1 > 0 && board[col][row - 1] == '_')
                {
                    bot_move(row - 1, col, board, color);
                    move = true;
                    return;
                }
            }
        }
    }

    if (!move)
    {
        for (int col = 1; col < sz; col++)
        {
            for (int row = 1; row < sz; row++)
            {
                if (board[col][row] == '_')
                {
                    bot_move(row, col, board, color);
                    return;
                }
            }
        }
    }
}
void one_player(vector<vector<char>> &board, vector<vector<string>> &color)
{
    int number_of_move_made = 0;
    string player = "Bot";

    while(number_of_move_made < (sz-1)*(sz-1)){

        if (number_of_move_made % 2 == 0)
        {
            bot_algo(board, color);
            print_board(board, color);

            if(is_there_a_winner(board)){
                    cout << "Congratulations, " << player << " wonnnn!!!!";
                return;
            }

            player = "Player 2";
        }
        else
        {
            get_input(board, color, player);
            print_board(board, color);

            if(is_there_a_winner(board)){
                    cout << "Congratulations, " << player << " wonnnn!!!!";
                return;
            }

            player = "Bot";
        }
        number_of_move_made++;
    }
}
