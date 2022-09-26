//
// Created by Lorenzo Dinardo on 22/08/22.
//
#include "ConcreteSubject.cpp"
#include "Conto.h"
#include <string>
Conto::Conto(std::string identifier, float amount, std::list<Transazione*> transaction_list) {
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
std::list<Transazione*> Conto::getTransactionList() {
    return this->transaction_list;
}
void Conto::addTransaction(Transazione* transaction) {
    transaction_list.push_back(transaction);
    ConcreteSubject::getInstance().notifyObserver(this,transaction);
}