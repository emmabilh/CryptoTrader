#include "Cryptostocks.hpp"

CryptoStocks::CryptoStocks() {
        bitcoinPrice = 61452.92;
        dogecoinPrice = 014;
    }

void CryptoStocks::updatePrices() {
}

int CryptoStocks::getBitcoinPrice() const {
    return bitcoinPrice;
}

int CryptoStocks::getDogecoinPrice() const {
    return dogecoinPrice;
}

