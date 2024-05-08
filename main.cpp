
#include <iostream>
#include <vector>
#include <utility>              //include utility for pair
#include <cstdlib>              //include cstdlib for srand and rand
#include <ctime>                //include ctime for time function
#include "Cryptostocks.hpp"
using namespace std;



// all account details together
class Account {                                 // basic variables declared
    int dogecoin, balance;
    int bitcoin;
    int deposit, withdraw;
    int total_equity = 100;
    int predict;
    int dogecoin_value;
    int bitcoin_value;
int crypto_invest;
int crypto_return;

    // declare vector
    vector<pair<string, int> > transactions;

public:
    // deposit "cash"
    bool Deposit(int money)
    {
        deposit += money;
        balance += money;
        transactions.push_back({ "Deposit:", money });
        return true;
    }

    //display acct information with balance and crypto owned
    void Get_account_information()
    {

        cout << "Money Details:\n";
        cout << "Bank Balance:" << balance << endl;
        cout << "Dogecoin:" << dogecoin << endl;
        cout << "Bitcoin:" << bitcoin << endl;
    }

    // withdraw Cash
    bool Withdraw(int money)
    {
        if (money > balance) {
            return false; //insuffiecient
        }

        withdraw += money;
        balance -= money;
        transactions.push_back({ "Withdraw:", money });
        return true;
    }

    bool buy_crypto()
      {
          int option;
          cout << "To purchase dogecoin, press 1. Else, for bitcoin press 2\n";
          cin >> option;

          if (total_equity != 0) {
              if (option == 1) {
                  dogecoin += 1;
                  balance -= dogecoin_value;
                  crypto_invest += dogecoin_value;
              }
              else if (option == 2) {
                  bitcoin += 1;
                  balance -= bitcoin_value;
                  crypto_invest += bitcoin_value;
              }
              else {
                  cout << "Invalid option\n";
                  return false;
              }
              transactions.push_back({ "Crypto Bought:", (option == 1) ? dogecoin_value : bitcoin_value });
              return true;
          }
          else {
              cout << "Not enough equity\n";
              return false;
          }
      }

      bool sell_crypto()
      {
          int option;
          cout << "To sell dogecoin, press 1. Else, for bitcoin press 2\n";
          cin >> option;

          if (option == 1) {
              if (dogecoin == 0) {
                  cout << "You don't have any Dogecoin to sell\n";
                  return false;
              }
              balance += dogecoin_value;
              crypto_return += dogecoin_value;
              transactions.push_back({ "Dogecoin Sold:", dogecoin_value });
              dogecoin -= 1;
              return true;
          }
          else if (option == 2) {
              if (bitcoin == 0) {
                  cout << "You don't have any Bitcoin to sell\n";
                  return false;
              }
              balance += bitcoin_value;
              crypto_return += bitcoin_value;
              transactions.push_back({ "Bitcoin Sold:", bitcoin_value });
              bitcoin -= 1;
              return true;
          }
          else {
              cout << "Invalid option\n";
              return false;
          }
      }

    // Checking All Transactions
    void History()
    {
        cout << "Displaying all transactions\n";
        for (auto it : transactions) {
            cout << it.first << " " << it.second << endl;
        }

        char temp;
        cout << "Do you want to clear all transactions?:";
        cin >> temp;

        int no = transactions.size();

        // Clearing All transactions
        if (temp == 'Y') {
            transactions.clear();
            cout << "Total transactions cleared:" << no
                << endl;
        }
        else {
            cout << "Total transaction:" << no << endl;
        }
    }

    Account()
    {
        crypto_invest = 0;
        crypto_return = 0;
        total_equity = 100;

        balance = 50000;
        dogecoin = 0;
        bitcoin = 0;
        withdraw = 0;
        deposit = 0;
        dogecoin_value = 100;
        bitcoin_value = 500;
    }
};

int main() {
    Account person;
    CryptoStocks cryptoStocks; // instantiate CryptoStocks object
    int amount, choice;
    bool check;
    while (true) {
        cout << " "
                "******************************************"
                "***************************** \n";

        cout << endl;
        cout << "Press 1 to access your Account Info "
             << endl;
        cout << "Press 2 to Deposit your money "
             << endl;
        cout << "Press 3 to withdraw your money "
             << endl;
        cout << "Press 4 to view your history "
             << endl;
        cout << "Press 5 to Buy Crypto "
             << endl;
        cout << "Press 6 to Sell Crypto "
             << endl;
        cout << "Press any invalid key for exit \n"
             << endl;

        cout << " "
                "******************************************"
                "***************************** \n";

        cin >> choice;
        int ans;

        switch (choice) {
            case 1:
                person.Get_account_information();
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                ans = person.Deposit(amount);
                if (ans)
                    cout << "Successfully deposited money"
                         << endl;
                else
                    cout << "Failed\n";

                break;

            case 3:
                cout << "Enter amount to withdraw : ";
                cin >> amount;
                person.Withdraw(amount);

                if (ans)
                    cout << "Successful withdraw amount"
                         << endl;
                else
                    cout << "Not Enough Balance\n";

                break;

            case 4:
                person.History();
                break;

            case 5:
                cryptoStocks.updatePrices(); // update Bitcoin and Dogecoin prices
                cout << "Current Bitcoin Price: $" << cryptoStocks.getBitcoinPrice() << endl;
                cout << "Current Dogecoin Price: $" << cryptoStocks.getDogecoinPrice() << endl;
                ans = person.buy_crypto();
                if (ans)
                    cout << "Successful Transaction" << endl;
                else
                    cout << "Try again! You were too late.\n";
                break;

            case 6:
                ans = person.sell_crypto();
                if (ans)
                    cout << "Successful Transaction" << endl;
                else
                    cout << "Not Enough Cryptocoins\n";
                break;

            default:
                exit(0);
                break;
        }
    }
    return 0;
}


