#include<iostream>
#include<vector>
#include<string>
#include <chrono>
#include <thread>
#include <ctype.h>

#define y first
#define x second

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */

using namespace std;

int wait_time = 1000;


void print_board(vector<vector<char>> &board, vector<vector<string>> &color){
    cout << "   1 2 3 4 5\n";
    for(int i = 1; i <= 5; i++){
        // i is vertical, j is horizon
        cout << i << "  ";
        for(int j = 1; j <= 5; j++){
            if(color[i][j] == "White") cout << board[i][j] << " ";
            else if(color[i][j] == "Blue") cout << BLUE << board[i][j] << RESET << " ";
            else cout << RED << board[i][j] << RESET << " ";
        }
        cout << endl;
    }
}
bool board_visited[6][6];

pair<int,int> user_move;
// fi is vertical, se is horizon

bool input_in_range(int inp){
    bool a = false;
    if((inp >= 1) && (inp <= 5)) a = true;
    return a;
}
 
void get_input(vector<vector<char>> &board, vector<vector<string>> &color, string player){
    while(true) {
        cout << player << "\n";
        cout << "Vertical: ";
        cin >> user_move.y;
        cout << "Horizon: ";
        cin >> user_move.x;

        cout << user_move.y << " " << user_move.x << "\n";

        if(input_in_range(user_move.y) == false || input_in_range(user_move.x) == false){
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

    while(/*is_there_a_winner(board,color) == false && */number_of_move_made < 25){
        get_input(board,color,player);
        // if there is not a winner yet, we on playing
        print_board(board,color);

        if(player == "Player 1") player = "Player 2";
        else if (player == "Player 2") player = "Player 1";
        number_of_move_made++;
        // shift between players
    }
    color[user_move.y][user_move.x] = "red";
    board[user_move.y][user_move.x] = 'O';
    print_board(board,color);

}

void one_player(vector<vector<char>> &board, vector<vector<string>> &color){

}
