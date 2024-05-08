// Emma Bilhimer
// Semester Project - Crypto-trading (Stock Market)
// Busch SP24
// Due May 8, 2024
/* Description of my project: This is a simulator of trading and selling cryptocurrency in C++. Although it's only bitcoin anc dogecoin. I just started getting into investing once I turned 18 and decided this would be a fun project to work on.  I utilized the logic related to account management and interaction with cryptocurrency prices in separate classes, code organization and readability.At first, I wanted to use an API to use live updates prices while I am not on the program, but it took way too many errors to realize it was a much longer project for next time. While it does not look very pretty, I am pretty satisfied with myself.
 */
#ifndef Cryptostocks_hpp
#define Cryptostocks_hpp

#include <stdio.h>

class CryptoStocks {
public:
    CryptoStocks();
    void updatePrices();                        // update bitcoin and dogecoin prices
    int getBitcoinPrice() const;                //  get the current bitcoin price
    int getDogecoinPrice() const;               // get the current dogecoin price

private:
    int bitcoinPrice;                           // current bitcoin price
    int dogecoinPrice;                          // current dogecoin price
};

#endif

