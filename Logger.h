//
// Created by Lorenzo Dinardo on 17/03/23.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_LOGGER_H
#define LABORATORIOPROG_LORENZODINARDO_LOGGER_H

#include "Observer.h"
#include "TransactionManager.h"
#include "Conto.h"
#include "Transazione.h"

class Logger : public Observer {
public:
    void update(const TransactionManager &t, const Cliente &cliente) override;

    void update(const TransactionManager &t, const Conto &conto) override;

    void update(const TransactionManager &t, const Transazione &transazione) override;
};

#endif //LABORATORIOPROG_LORENZODINARDO_LOGGER_H
