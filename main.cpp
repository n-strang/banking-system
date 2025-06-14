#include <iostream>
#include <vector>
#include <string>
using namespace std;

// struct to create accounts
struct accountData {
    string accUserName;
    double accBalance;
    string accPassword;
    int accPin;
};

// array that stores all accounts globally
vector<accountData>allAccounts;

bool searchForSpecificAccount() {
    cout << "account name: " << endl;
    string name;
    cin >> name;
    cout << endl;
    for (const auto& acc : allAccounts) {
        if (acc.accUserName == name) {
            cout << acc.accUserName << endl;
            cout << acc.accBalance << endl;
            cout << acc.accPassword << endl;
            cout << acc.accPin << endl;
            return true;
        }
    }
    cout << "Account not found.";
    return false;
}

bool checkForAccount(string name, string pword) {
    for (const auto& acc : allAccounts) {
        if (acc.accUserName == name && acc.accPassword == pword) {
            return true;
        }
    }
    return false;
}

void alphaSort(int userInput) {
    if (userInput == 1) {
        // sort a-z
    } else if (userInput == 2){
        // sort z-a
    }
    // pick up here
}

void listAllAccounts() {
    int userInput;
    while (true) {
        cout << "How would you like to sort/display accounts?: " << endl;
        cout << "1. Sort a-z by name: " << endl;
        cout << "2. Sort z-a by name: " << endl;
        cout << "3. exit menu " << endl;

        switch (userInput) {
            case 1:
                alphaSort(userInput);
            break;
            case 2:
                alphaSort(userInput);
            break;
            default:
                cout << "try another input";
            break;
        }
    }
}

void userOptions(string name, string password) {
    cout << "welcome " << name << "!" << endl;
    cout << "Select from the following options: " << endl;
    cout << "1. Deposit \n 2. View balance \n 3. Change username/password \n 4. change pin \n 5.close account";
}

// user login
void userLoginPanel() {
    string userName, password;
    cout << "Welcome, enter username and password: " << endl;
    cin >> userName;
    cout << endl;
    cin >> password;
    cout << endl;
    if (checkForAccount(userName, password)) {
        cout << "successful" << endl;
        userOptions(userName, password);
    } else {
        cout << "incorrect" << endl;
    }

}

// prints data stored in account
void printAccData() {
    for (const auto& acc : allAccounts) {
        cout << "\nName: " << acc.accUserName;
        cout << "\nPassword: " << acc.accPassword;
        cout << "\nbalance: " << acc.accBalance;
        cout << "\npin: " << acc.accPin;
        cout << endl;
    }
}

// take data from createNewAcc() and make it an object, then push that object into the array
void storeNewAccount(string name, string password, double balance, int pin) {
    accountData accData;
    accData.accUserName = name;
    accData.accPassword = password;
    accData.accBalance = balance;
    accData.accPin = pin;
    allAccounts.push_back(accData);

}

// create a new account (username/password)
void createNewAcc() {
    string name, pword;
    double bal = 0;
    int pin = 0;
    cout << "creating new account..." << endl;
    cout << "enter an account name: ";
    cin >> name;
    cout << "\nenter an account password: ";
    cin >> pword;
    cout << "Enter a pin: ";
    cin >> pin;
    cout << "successfully created.";

    storeNewAccount(name, pword, bal, pin);

}

//post login
void adminPanel() {
    int userInput;

    while (true) {
        cout << "welcome to the admin panel" << endl;
        cout << "select from the following " << endl;
        cout << "1. Create a new account " << endl;
        cout << "2. View all created accounts " << endl;
        cout << "3. View a created account" << endl;
        cout << "0. exit admin panel " << endl;
        cin >> userInput;
        cout << endl;

        switch (userInput) {
            case 1:
                createNewAcc();
            break;
            case 2:
                searchForSpecificAccount();
            break;
            case 3:
                listAllAccounts();
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
    string loginNameAttempt, loginPasswordAttempt;

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