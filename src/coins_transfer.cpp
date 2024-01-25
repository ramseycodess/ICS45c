#include <iostream>
#include "coins.hpp"
using namespace std;

int main() {
    Coins wallet1(50, 5, 5, 100); // First wallet
    Coins wallet2(25, 10, 10, 50); // Second wallet

    cout << "Initial state:\n";
    cout << "Wallet 1: " << wallet1 << endl;
    cout << "Wallet 2: " << wallet2 << endl;

    // Let's transfer some coins from wallet1 to wallet2
    Coins transfer = wallet1.extract_exact_change(Coins(10, 0, 5, 20));
    wallet2.deposit_coins(transfer);

    cout << "\nAfter transfer:\n";
    cout << "Wallet 1: " << wallet1 << endl;
    cout << "Wallet 2: " << wallet2 << endl;

    return 0;
}
