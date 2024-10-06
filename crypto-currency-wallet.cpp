#include <iostream>
#include <cstdlib>
#include <ctime>      //2023F-BCE-249
using namespace std; //2023F-BCE-250

// Function declarations
void cryptoPrices(double &bitcoinPrice, double &ethereumPrice, double &ripplePrice, double &renderPrice, double &solanaPrice);
void displayMenu();
void showPortfolio(double balance1, double balance2, double balance3);
void buyCoins(double &balance, double &bitcoinPrice, double &ethereumPrice, double &ripplePrice, double &renderPrice, double &solanaPrice);
void sellCoins(double &balance);
void transferCrypto(double &fromBalance, double &toBalance);
bool authenticateUser(const string& username, int password);

int main() {
    // Default username and passwords
    string user1 = "Dayan", user2 = "Muzammil", user3 = "Asees";
    int pass1 = 1234, pass2 = 4567, pass3 = 8910;

    // Default balances
    double balance1 = 1000.00, balance2 = 1000.00, balance3 = 1000.00;

    // Display random prices for crypto coins
    double bitcoinPrice, ethereumPrice, ripplePrice, renderPrice, solanaPrice;
    cryptoPrices(bitcoinPrice, ethereumPrice, ripplePrice, renderPrice, solanaPrice);
    cout << "CURRENT CRYPTO PRICES:\n";
    cout << "Bitcoin: $" << bitcoinPrice << endl;
    cout << "Ethereum: $" << ethereumPrice << endl;
    cout << "Ripple: $" << ripplePrice << endl;
    cout << "Render: $" << renderPrice << endl;
    cout << "Solana: $" << solanaPrice << endl;

    int choice, password;
    string username;
    bool authenticated = false;
    int attempts = 0;
    const int maxAttempts = 3;

    while (!authenticated && attempts < maxAttempts) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        authenticated = authenticateUser(username, password);
        attempts++;

        if (!authenticated) {
            cout << "Authentication failed. Please try again.\n";}
    }
    if (!authenticated) {
        cout << "Maximum login attempts exceeded. Exiting...\n";
        return 1;} // Exit the program after max attempts
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int user;
                cout << "Select user (1-Dayan, 2-Muzammil, 3-Asees): ";
                cin >> user;
                if (user == 1) {
                    buyCoins(balance1, bitcoinPrice, ethereumPrice, ripplePrice, renderPrice, solanaPrice);}
                else if (user == 2) {
                    buyCoins(balance2, bitcoinPrice, ethereumPrice, ripplePrice, renderPrice, solanaPrice);}
                else if (user == 3) {
                    buyCoins(balance3, bitcoinPrice, ethereumPrice, ripplePrice, renderPrice, solanaPrice);}
                else {
                    cout << "Invalid user!" << endl;}
                break;}
            case 2: {
                int user;
                cout << "Select user (1-Dayan, 2-Muzammil, 3-Asees): ";
                cin >> user;
                if (user == 1) {
                    sellCoins(balance1);}
                else if (user == 2) {
                    sellCoins(balance2);}
                else if (user == 3) {
                    sellCoins(balance3);}
                else {
                    cout << "Invalid user!" << endl;}
                break;}
            case 3: {
                int fromUser, toUser;
                cout << "Select sender (1-Dayan, 2-Muzammil, 3-Asees): ";
                cin >> fromUser;
                cout << "Select receiver (1-Dayan, 2-Muzammil, 3-Asees): ";
                cin >> toUser;
                if (fromUser == 1 && toUser == 2) {
                    transferCrypto(balance1, balance2);}
                else if (fromUser == 1 && toUser == 3) {
                    transferCrypto(balance1, balance3);}
                else if (fromUser == 2 && toUser == 1) {
                    transferCrypto(balance2, balance1);}
                else if (fromUser == 2 && toUser == 3) {
                    transferCrypto(balance2, balance3);}
                else if (fromUser == 3 && toUser == 1) {
                    transferCrypto(balance3, balance1);}
                else if (fromUser == 3 && toUser == 2) {
                    transferCrypto(balance3, balance2);}
                else {
                    cout << "Invalid users!" << endl;}
                break;}
            case 4:
                showPortfolio(balance1, balance2, balance3);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
// Function definitions
void cryptoPrices(double &bitcoinPrice, double &ethereumPrice, double &ripplePrice, double &renderPrice, double &solanaPrice) {
    srand(time(0));
    bitcoinPrice = rand() % 100 + 1;
    ethereumPrice = rand() % 100 + 1;
    ripplePrice = rand() % 100 + 1;
    renderPrice = rand() % 100 + 1;
    solanaPrice = rand() % 100 + 1;
}
void displayMenu() {
    cout << "************************************************\n";
    cout << "   WELCOME TO PHANTOM CRYPTOCURRENCY WALLET       \n";
    cout << "************************************************\n";

    cout << "\nMenu:\n";
    cout << "1. Buy Coins\n";
    cout << "2. Sell Coins\n";
    cout << "3. Transfer Crypto\n";
    cout << "4. Show Portfolio\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}
void showPortfolio(double balance1, double balance2, double balance3) {
    cout << "User portfolios:\n";
    cout << "1. Dayan: $" << balance1 << endl;
    cout << "2. Muzammil: $" << balance2 << endl;
    cout << "3. Asees: $" << balance3 << endl;
}
void buyCoins(double &balance, double &bitcoinPrice, double &ethereumPrice, double &ripplePrice, double &renderPrice, double &solanaPrice){
    int cryptoChoice;
    cout << "Select cryptocurrency to buy:\n";
    cout << "1. Bitcoin ($" << bitcoinPrice << ")\n";
    cout << "2. Ethereum ($" << ethereumPrice << ")\n";
    cout << "3. Ripple ($" << ripplePrice << ")\n";
    cout << "4. Render ($" << renderPrice << ")\n";
    cout << "5. Solana ($" << solanaPrice << ")\n";
    cout << "Enter your choice: ";
    cin >> cryptoChoice;

    double amount;
    cout << "Enter amount to buy: $";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount! Please enter a positive number.\n";
        return;}
    switch (cryptoChoice) {
        case 1:
            balance += amount * bitcoinPrice;
            break;
        case 2:
            balance += amount * ethereumPrice;
            break;
        case 3:
            balance += amount * ripplePrice;
            break;
        case 4:
            balance += amount * renderPrice;
            break;
        case 5:
            balance += amount * solanaPrice;
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;}
    cout << "Successfully bought cryptocurrency!" << endl;
}
void sellCoins(double &balance) {
    double amount;
    cout << "Enter amount to sell coins: $";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount! Please enter a positive number.\n";
        return;}
    if (amount > balance) {
        cout << "Insufficient balance!" << endl;}
    else {
        balance -= amount;
        cout << "Successfully sold coins worth $" << amount << endl;}
}
void transferCrypto(double &fromBalance, double &toBalance) {
    double amount;
    cout << "Enter amount to transfer: $";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount! Please enter a positive number.\n";
        return;}
    if (amount > fromBalance) {
        cout << "Insufficient balance!" << endl;}
    else {
        fromBalance -= amount;
        toBalance += amount;
        cout << "Successfully transferred $" << amount << endl;}
}
bool authenticateUser(const string& username, int password) {
    if (username == "Dayan" && password == 1234) {
        return true;}
    else if (username == "Muzammil" && password == 4567) {
        return true;}
    else if (username == "Asees" && password == 8910) {
        return true;}
    return false;
}


