//
// Created by Lorenzo Dinardo on 06/10/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_OBSERVER_H
#define LABORATORIOPROG_LORENZODINARDO_OBSERVER_H

#include "Conto.h"
#include "TransactionManager.h"

class Observer {
public:
    Observer() = default;
    virtual void update(  const TransactionManager & t, const Cliente& cliente) = 0;
    virtual void update(const TransactionManager& t, const Conto& conto)= 0;
    virtual void update(const TransactionManager& t, const Transazione& transazione)=0;
};

#endif //LABORATORIOPROG_LORENZODINARDO_OBSERVER_H
