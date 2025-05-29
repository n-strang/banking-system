/*
0> ROADMAP FOR BANKING SYSTEM:
1> create main menu (all options)  ---------- DONE
2> functions to log on to admin / user --------- SWAP AROUND accLoginType() THEN DONE
3> save data using some sort of file (csv/txt?)
4> store an array of different accounts ----------- DONE
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// struct to create accounts
struct accountData {
    string accUserName;
    double Balance;
    string accPassword;
};

// array that stores all accounts globally
vector<accountData>allAccounts;

// admin login
void adminLoginPanel() {
    cout << "admin" << endl;
}

// user login
void userLoginPanel() {
    cout << "admin" << endl;
}

// prints data stored in account
void printAccData() {
    for (const auto& acc : allAccounts) {
        cout << "\nName: " << acc.accUserName;
        cout << "\nPassword: " << acc.accPassword;
        cout << "\nbalance: " << acc.Balance;
        cout << endl;
    }
}

// take data from createNewAcc() and make it an object, then push that object into the array
void storeNewAccount(string name, string password, int balance) {
    accountData accData;
    accData.accUserName = name;
    accData.accPassword = password;
    accData.Balance = balance;
    allAccounts.push_back(accData);

}

// create a new account (username/password)
void createNewAcc() {
    string name;
    double bal = 0;
    string pword;
    cout << "creating new account..." << endl;
    cout << "enter an account name: ";
    cin >> name;
    cout << "\nenter an account password: ";
    cin >> pword;
    cout << "successfully created.";

    storeNewAccount(name, pword, bal);

}

// main menu (SWAP OUT VIEW ACCOUNTS TO ADMIN LOGIN)
void accLoginType() {
    int userInput;

    while (true) {
        cout << "\nPlease select from the following menu options (1-9)" << endl;
        cout << "1. Admin login" << endl;
        cout << "2. User login" << endl;
        cout << "3. Create Account" << endl;
        cout << "4. View created accounts" << endl;
        cout << "0. End program" << endl;
        cout << "Enter your choice: ";
        cin >> userInput;
        cout << endl;

        switch (userInput) {
            case 1:
                adminLoginPanel();
            break;
            case 2:
                userLoginPanel();
            break;
            case 3:
                createNewAcc();
            break;
            case 4:
                printAccData();
            break;
            case 0:
                cout << "Exiting program..." << endl;
            return;  // or break if you want to fall through
            default:
                cout << "Input not recognized, try again." << endl;
            break;
        }
    }
}


// main func
int main() {
    accLoginType();
    return 0;
}


