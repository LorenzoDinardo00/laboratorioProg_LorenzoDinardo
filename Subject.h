//
// Created by Lorenzo Dinardo on 26/09/22.
//
#include "Conto.h"
class Observer;
class TransactionManager;

class Subject{
public:
    Subject()= default;
    virtual void registerObserver(Observer* observer)=0;
    virtual void removeObserver(Observer* observer)=0;
    virtual void notifyObserver( const Cliente &cliente)=0;
    virtual void notifyObserver( const Conto &conto)=0;
    virtual void notifyObserver( const Transazione &transazione)=0;
};