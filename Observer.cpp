//
// Created by Lorenzo Dinardo on 26/09/22.
//
#include "Conto.h"
class Observer{
public:
    Observer();
    virtual void update(Conto bankAccount, Transazione transaction) = 0;
};