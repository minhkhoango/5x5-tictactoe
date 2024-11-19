#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool check_horizon(vector<vector<int>>& board){
    
}

bool check_vertical(vector<vector<int>>& board){

}

bool check_diagonal(vector<vector<int>>& board){

}

bool is_there_a_winner(vector<vector<int>>& board, string player){
    // return true if someone wins, false otherwise

    bool _check_horizon = check_horizon(board);
    bool _check_vertical = check_vertical(board);
    bool _check_diagonal = check_diagonal(board);

    if(_check_horizon == 1 || _check_vertical == 1 || _check_diagonal == 1){
        return true;
    }
    return false;
}