#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "========== Menu ==========" << endl;
    cout << "1. Enter Username" << endl;
    cout << "2. Exit" << endl;
    cout << "==========================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    string username;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter your username: ";
                cin.ignore(); // To clear the buffer before getline
                getline(cin, username);
                cout << "Hello, " << username << "!" << endl;
                break;
            case 2:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 2);

    return 0;
}