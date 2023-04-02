//
// Created by Lorenzo Dinardo on 25/10/22.
//

#include <fstream>
#include <iostream>
#include "Conto.h"
#include "Observer.h"

class Logger : public Observer {
public:
    void update(const TransactionManager &t, const Cliente &cliente) override {
        std::cout << "creazione nuovo cliente " << std::endl;
        std::cout << "nome cliente: " << cliente.getName() << " " << cliente.getSurname() << " ID Cliente: "
                  << cliente.getIdOwner() << " ora di iscrizione: " << cliente.getStartingDate();

    }

    void update(const TransactionManager &t, const Conto &conto) override {
        std::cout << "creazione nuovo conto " << std::endl;
        std::cout << "id cliente proprietario: " << conto.getIdOwner() << " ID conto: " << conto.getIdentifier()
                  << " amount conto " << conto.getAmount() << std::endl;
    }

    void update(const TransactionManager &t, const Transazione &transazione) override {
        std::cout << "creazione nuova transazione " << std::endl;
        std::string typeString;
        switch (transazione.getType()) {
            case bonifico: {
                typeString = "bonifico";
                break;
            }
            case giroconto: {
                typeString = "giroconto";
                break;
            }
            default:
                typeString = "non identificato";
                break;
        }
        std::cout << "valore transazione: " << transazione.getAmount() << " -" << " ID transazione: "
                  << transazione.getTransationId() << " -" << " tipo transazione: " << typeString << " -"
                  << " indirizzo sorgente: " << transazione.getSourceAddress() << " -" << " indirizzo destinazione: "
                  << transazione.getDestinationAddress() << " -" << " ora della transazione: "
                  << transazione.getTimestamp() << std::endl;
    }
};