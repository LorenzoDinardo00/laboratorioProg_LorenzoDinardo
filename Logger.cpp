//
// Created by Lorenzo Dinardo on 25/10/22.
//

#include <fstream>
#include <iostream>
#include "Conto.h"
#include "Observer.h"
class Logger: public Observer {
public:
    void update(const TransactionManager &t, const Cliente &cliente) override {
        std::cout<< "creazione nuovo cliente "<<std::endl;
        std::cout << cliente.getName() <<" "<< cliente.getSurname()<<" " <<cliente.getIdOwner()<<" "<<  cliente.getStartingDate();

    }

    void update(const TransactionManager &t, const Conto &conto) override {
        std::cout<< "creazione nuovo conto "<<std::endl;
        std::cout << conto.getIdOwner() << conto.getIdentifier() << conto.getAmount() << std::endl;
    }

    void update(const TransactionManager &t, const Transazione &transazione) override {
        std::cout<< "creazione nuova transazione "<<std::endl;
        std::cout << transazione.getAmount() << transazione.getTransationId() << transazione.getType() <<transazione.getSourceAddress()<<transazione.getDestinationAddress()<<transazione.getTimestamp()<< std::endl;
    }
};