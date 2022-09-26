//
// Created by Lorenzo Dinardo on 26/09/22.
//

#include "ConcreteSubject.h"

ConcreteSubject &ConcreteSubject::getInstance() {
    static ConcreteSubject INSTANCE;
    return INSTANCE;
}

void ConcreteSubject::registerObserver(Observer *observer) {
    observers.push_back(observer);
}
void ConcreteSubject::removeObserver(Observer *observer) {
    observers.remove(observer);
}
void ConcreteSubject::notifyObserver(Conto *bankAccount, Transazione *transaction) {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++){
        (*itr)->update(bankAccount, transaction);
    }
}