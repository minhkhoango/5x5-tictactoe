#include<iostream>
#include<string>
#include <chrono>
#include <thread>

using namespace std;

int wait_time_between = 1500;

void wait_until_ready(){
    string response;
    while(true){
        // infite loop until the user is ready
        getline(cin, response);
        // create a string that change upper_case -> lowercase, remove any spaces
        string corrected_response = "";
        for(int i = 0; i < response.size(); i++){
            // iterator through the response string
            char add = response[i];
            if(add == ' ') continue;
            // skip the space
            corrected_response = corrected_response + add;
        }

        if(corrected_response == "yes" || corrected_response == "ok" || corrected_response == "y") break;
        
        cout << "Alright, we will wait for 3 seconds :v" << "\n\n";
        this_thread::sleep_for(chrono::milliseconds(wait_time_between*2)); // (1)
        // wait 3 seconds
        cout << "Are you ready? " << "\n";
        // ask the player again, repeating the cycle
    }
}

void greet_the_player(){
    // greet the player
    cout << "Hello, welcome to the the game of 5x5 tictac toe" << "\n\n";
    // sleep for 1 second
    this_thread::sleep_for(chrono::milliseconds(wait_time_between)); // (1)
    // introduce the rule of the game
    cout << "Since you are so good, the machine will play first!" << "\n\n";
    this_thread::sleep_for(chrono::milliseconds(wait_time_between)); // (1)
    cout << "Each player will take 1 turn, until either a player win, or there are no spaces left" << "\n\n";
    cout << "Are you ready? " << "\n";

    // wait until player is ready
    wait_until_ready();
    cout << "Great response! Now we shall begin!" << endl;
}

// https://www.geeksforgeeks.org/sleep-function-in-cpp/ (1)