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
    std::list<std::shared_ptr<Transazione>> transaction_list;
    std::string id_owner;
public:
    Conto() = default;
    Conto(std::string identifier, float amount,std::string id_owner);

    const std::string &getIdentifier() const;

    float getAmount() const;

    const std::string &getIdOwner() const;

    void addTransaction(const std::shared_ptr<Transazione>& transaction);

    const std::list<std::shared_ptr<Transazione>> &getTransactionList() const;
};

#endif //LABORATORIOPROG_LORENZODINARDO_CONTO_H
