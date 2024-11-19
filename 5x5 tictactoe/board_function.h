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
    
    if(check == false) return -1;

    int ans = inp[0] - '0';
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
            cout << "Cheater!!!\n";
            this_thread::sleep_for(chrono::milliseconds(wait_time));
            cout << "You have one second to think about your life again\n";
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

void multiplayer(vector<vector<char>> &board, vector<vector<string>> &color){
    int number_of_move_made = 0;
    string player = "Player 1";

    while(number_of_move_made < 25){
        get_input(board,color,player);
        // if there is not a winner yet, we on playing
        print_board(board,color);

        bool _is_there_a_winner = is_there_a_winner(board, player);
        if(_is_there_a_winner == true){
            cout << "Congratulations, " << player << " wonnnn!!!!";
            return; 
        }

        if(player == "Player 1") player = "Player 2";
        else if (player == "Player 2") player = "Player 1";
        number_of_move_made++;
        // shift between players
    }
    
    cout << "Hmmm, there seems to be no winner.....\n";
}

void one_player(vector<vector<char>> &board, vector<vector<string>> &color){

}
