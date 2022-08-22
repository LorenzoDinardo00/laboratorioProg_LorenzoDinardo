//
// Created by Lorenzo Dinardo on 22/08/22.
//

#include "Conto.h"
#include <string>
Conto::Conto(std::string identifier, float amount, Transazione* transaction_list) {
    this->identifier = identifier;
    this->amount=amount;
    this->transaction_list = transaction_list;
}
std::string Conto::getIdentifier() {
    return this->identifier;
}
float Conto::getAmount() {
    return this->amount;
}
Transazione* Conto::getTransactionList() {
    return this->transaction_list;
}
void Conto::addTransaction(Transazione transaction) {
    int length = sizeof(*transaction_list)/sizeof(Transazione);
    Transazione transactions[length + 1];

    for(int i = 0; i<length+1; i++) {
        if(i == length)
            transactions[i] = transaction;
        else
            transactions[i] = this->transaction_list[i];
    }
    this->transaction_list = transactions;
    //ConcreteSubject.notifyObservers(this, transaction);
}