#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "common.h"

using namespace std;

void displayMenu() {
    cout << "========== Menu ==========" << endl;
    cout << "1. One Player" << endl;
    cout << "2. Two Player" << endl;
    cout << "==========================" << endl;
    cout << "Enter your choice: ";
}

int _greet() {
    string choice;
    int answer;

    while(true){
        displayMenu();

        cin >> choice;
        if(choice == "1")
        {
            answer = 1;
            break;
        }
        else if(choice == "2")
        {
            answer = 2;
            break;
        }
        else
        {
         cout << "Invalid input!";
        }
        this_thread::sleep_for(chrono::milliseconds(wait_time));
        cout << "\n\n";
    }
    this_thread::sleep_for(chrono::milliseconds(wait_time));
    cout << "\n\n";
    return answer;
}
