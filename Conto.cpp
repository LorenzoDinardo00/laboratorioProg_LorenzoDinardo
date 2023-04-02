//
// Created by Lorenzo Dinardo on 22/08/22.
//

#include "Conto.h"
#include <string>
#include <utility>

Conto::Conto(const std::string &identifier, float amount,const std::string &idOwner)  {
    this->identifier = identifier;
    this->amount=amount;
    this->idOwner = idOwner;
}

void Conto::addTransaction(const std::shared_ptr<Transazione>& transaction) {
    transaction_list.push_back(transaction);
    if (this->identifier == transaction->getSourceAddress()){
        if(this->amount-transaction->getAmount()<0){
            throw std::runtime_error("amount source balance negative!");
        }
        this->amount -= transaction->getAmount();

    }else if(this->identifier== transaction->getDestinationAddress()){
        this->amount += transaction->getAmount();
    }else throw std::runtime_error("identifier non è ne destinazione ne sorgente");

}




const std::string &Conto::getIdentifier() const {
    return identifier;
}

float Conto::getAmount() const {
    return amount;
}


const std::string &Conto::getIdOwner() const {
    return idOwner;
}

const std::list<std::shared_ptr<Transazione>> &Conto::getTransactionList() const {
    return transaction_list;
}
