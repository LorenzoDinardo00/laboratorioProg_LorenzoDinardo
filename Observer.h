//
// Created by Lorenzo Dinardo on 06/10/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_OBSERVER_H
#define LABORATORIOPROG_LORENZODINARDO_OBSERVER_H

#include "Conto.h"

class Observer {
public:
    Observer();
    virtual void update(Conto* bankAccount, Transazione* transaction) = 0;
};

#endif //LABORATORIOPROG_LORENZODINARDO_OBSERVER_H
