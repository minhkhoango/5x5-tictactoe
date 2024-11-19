#include<iostream>
#include<string>
#include<vector>
#include "common.h"

using namespace std;

bool check_horizon(vector<vector<char>>& board){
    for(int i = 1; i < sz; i++){
        bool ans = true;
        // check each horizonal row
        char check_if_similar = board[i][1];
        for(int j = 2; j < sz; j++){
            if(board[i][j] != check_if_similar || board[i][j] == '_') ans = false;
        }
        if(ans == true) return true;
    }
    return false;
}

bool check_vertical(vector<vector<char>>& board){
    for(int j = 1; j < sz; j++){
        bool ans = true;
        // check each vertical row
        char check_if_similar = board[1][j];
        for(int i = 2; i < sz; i++){
            if(board[i][j] != check_if_similar || board[i][j] == '_') ans = false;
        }
        if(ans == true) return true;
    }
    return false;
}

bool check_diagonal(vector<vector<char>>& board){
    // from left to right
    bool check_diag_down = true, check_diag_up = true;

    char check_if_similar = board[1][1];
    int y = 2, x = 2; // Coordinates: x for horizon, y for vertical 
    
    while(y < sz && x < sz){
        if(board[y][x] != check_if_similar || board[y][x] == '_') check_diag_down = false;
        y++;
        x++;
    }


    check_if_similar = board[sz-1][1];
    y = sz-2, x = 2;
    while(y > 0 && x < sz){
        if(board[y][x] != check_if_similar || board[y][x] == '_') check_diag_up = false;
        y--;
        x++;
    }

    if(check_diag_down == true || check_diag_up == true) return true;
    return false;
}

bool is_there_a_winner(vector<vector<char>>& board){
    // return true if someone wins, false otherwise

    bool _check_horizon = check_horizon(board);
    bool _check_vertical = check_vertical(board);
    bool _check_diagonal = check_diagonal(board);

    cout << _check_vertical << " " << _check_horizon << " " << _check_diagonal << "\n";
    if(_check_horizon == 1 || _check_vertical == 1 || _check_diagonal == 1){
        return true;
    }
    return false;
}