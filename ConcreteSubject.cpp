//
// Created by Lorenzo Dinardo on 26/09/22.
//

#include "ConcreteSubject.h"
#include "Observer.h"
void ConcreteSubject::registerObserver(Observer *observer) {
    observers.push_back(observer);
}
void ConcreteSubject::removeObserver(Observer *observer) {
    observers.remove(observer);
}

void ConcreteSubject::notifyObserver(const TransactionManager &t, const Cliente &cliente) {
    for (auto & o : observers){
        o->update(t,cliente);
        }
}
void ConcreteSubject::notifyObserver(const TransactionManager &t, const Conto &conto) {
    for (auto &o: observers) {
        o->update(t, conto);
    }
}

void ConcreteSubject::notifyObserver(const TransactionManager &t, const Transazione &transazione) {
    for (auto &o: observers) {
        o->update(t, transazione);
    }
}
