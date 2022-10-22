//
// Created by Lorenzo Dinardo on 22/08/22.
//

#include "ConcreteSubject.h"
#include "Conto.h"
#include <string>
#include <utility>

Conto::Conto(std::string identifier, float amount,std::string id_owner)  {
    this->identifier = std::move(identifier);
    this->amount=amount;
    this->id_owner = std::move(id_owner);
}
std::string Conto::getIdentifier() {
    return this->identifier;
}
float Conto::getAmount() {
    return this->amount;
}
std::list<std::shared_ptr<Transazione>> Conto::getTransactionList() {
    return this->transaction_list;
}
void Conto::addTransaction(const std::shared_ptr<Transazione>& transaction) {
    transaction_list.push_back(transaction);
    if (this->identifier == transaction->getSourceAddress()){
        if(this->amount-transaction->getAmount()<0){
            throw std::runtime_error("amount negative!");
        }
        this->amount -= transaction->getAmount();

    }else if(this->identifier== transaction->getDestinationAddress()){
        this->amount += transaction->getAmount();
    }


}
std::string Conto::getOwner() {
    return this->id_owner;
}