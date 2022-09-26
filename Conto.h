//
// Created by Lorenzo Dinardo on 22/08/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_CONTO_H
#define LABORATORIOPROG_LORENZODINARDO_CONTO_H
#include <list>
#include<string>
#include "Transazione.h"
class Conto {
private:
    std::string identifier;
    float amount;
    std::list<Transazione*> transaction_list;
public:
    Conto(std::string identifier, float amount, std::list<Transazione*> transaction_list);
    std::string getIdentifier();
    float getAmount();
    std::list<Transazione*> getTransactionList();
    void addTransaction(Transazione* transaction);

};

#endif //LABORATORIOPROG_LORENZODINARDO_CONTO_H
