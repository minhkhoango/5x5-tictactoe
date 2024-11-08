#include<iostream>
#include<vector>
#include<string>
#include "say_hello.cpp"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */


vector<vector<char>> board(6, vector<char> (6,'_'));
// board using a two demensional vector of size 6 - 6
// I plan to use number from 1 to 5

signed main(){

    //greet_the_player();

    for(int i = 1; i <= 5;i ++){
        for(int j = 1; j <= 5; j++){
            cout << RED << j << RESET <<  " ";
        }
        cout << endl;
    }
    int hello; cin >> hello;
}

