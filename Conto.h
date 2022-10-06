//
// Created by Lorenzo Dinardo on 22/08/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_CONTO_H
#define LABORATORIOPROG_LORENZODINARDO_CONTO_H
#include <list>
#include <string>
#include "Transazione.h"
#include "Cliente.h"

class Conto {
private:
    std::string identifier;
    float amount;
    std::list<Transazione*> transaction_list;
    Cliente owner;
public:
    Conto(std::string identifier, float amount, std::list<Transazione*> transaction_list, Cliente owner);
    std::string getIdentifier();
    float getAmount();
    std::list<Transazione*> getTransactionList();
    void addTransaction(Transazione* transaction);
    Cliente getOwner();
};

#endif //LABORATORIOPROG_LORENZODINARDO_CONTO_H
