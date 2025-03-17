#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    
    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, user, pass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("database.txt");
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            cout << "Login successful!\n";
            return true;
        }
    }
    file.close();
    cout << "Invalid username or password.\n";
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
