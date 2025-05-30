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

// user login
void userLoginPanel() {
    // will add a deposit / withdrawal / view function
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

//post login
void adminPanel() {
    int userInput;

    while (true) {
        cout << "welcome to the admin panel" << endl;
        cout << "select from the following " << endl;
        cout << "1. Create a new account(s) " << endl;
        cout << "2. View created Account(s) " << endl;
        cout << "0. exit admin panel " << endl;
        cin >> userInput;
        cout << endl;

        switch (userInput) {
            case 1:
                createNewAcc();
            break;
            case 2:
                printAccData();
            break;
            case 0:
                cout << "exiting admin panel... " << endl;
            return;
            default:
                cout << "Input not recognized, try again." << endl;
            break;
        }
    }
}

// admin login
void adminLogin() {
    // DEFAULT ADMIN LOGIN
    string adminName = "admin";
    string adminPassword = "123";
    string loginNameAttempt;
    string loginPasswordAttempt;

    while (true) {
        cout << "Enter admin username: ";
        cin >> loginNameAttempt;
        cout << "Enter admin password: ";
        cin >> loginPasswordAttempt;
        cout << endl;

        if (loginNameAttempt == adminName && loginPasswordAttempt == adminPassword) {
            cout << "Login successful!" << endl;
            adminPanel();
            break;
        } else {
            cout << "Wrong username/password, try again." << endl << endl;
        }
    }
}

// choose login panel
void accLoginType() {
    int userInput;

    while (true) {
        cout << "\nPlease select from the following menu options (1-9)" << endl;
        cout << "0. Admin login" << endl;
        cout << "1. User login" << endl;
        cout << "2. End program" << endl;
        cout << "Enter your choice (0-2): ";
        cin >> userInput;
        cout << endl;

        switch (userInput) {
            case 0:
                adminLogin();
            break;
            case 1:
                userLoginPanel();
            break;
            case 2:
                cout << "Exiting program..." << endl;
            return;
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


