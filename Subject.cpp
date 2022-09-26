//
// Created by Lorenzo Dinardo on 26/09/22.
//
#include "Conto.h"
#include "Observer.cpp"
class Subject{
public:
    Subject();
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObserver(Conto* bankAccount, Transazione* transaction) = 0;
};