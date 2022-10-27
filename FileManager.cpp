//
// Created by Lorenzo Dinardo on 26/09/22.
//
#include <fstream>
#include <iostream>
#include "Conto.h"
#include "Observer.h"
class FileManager: public Observer {
private:
    std::string filecliente;
    std::string fileconto;
    std::string filetransazione;

public:
    FileManager(std::string filecliente, std::string fileconto, std::string filetransazione){
        this->filecliente=std::move(filecliente);
        this->fileconto=std::move(fileconto);
        this->filetransazione=std::move(filetransazione);
    }
    void update(const TransactionManager &t, const Cliente &cliente) override {
        std::ofstream f(filecliente, std::ios_base::app);
        std::string date = cliente.getStartingDate();
        date.pop_back();
        f << cliente.getName() <<" "<< cliente.getSurname() <<" "<< date <<" "<<cliente.getIdOwner()<< std::endl;

    }

    void update(const TransactionManager &t, const Conto &conto) override {
        std::ofstream f(fileconto, std::ios_base::app);
        f << conto.getIdentifier() << " "<<conto.getAmount() <<" "<<conto.getIdOwner() << std::endl;
    }

    void update(const TransactionManager &t, const Transazione &transazione) override {
        std::ofstream f(filetransazione, std::ios_base::app);
        std::string data = transazione.getTimestamp();
        data.pop_back();
        f <<transazione.getType() <<" "<<transazione.getDestinationAddress()<<" "<< transazione.getSourceAddress()<<" "<<transazione.getAmount() << " "<< transazione.getTransationId() <<" "<<data<<" "<<  std::endl;
    }
};