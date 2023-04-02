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
    FileManager(const std::string &filecliente, const std::string &fileconto,const  std::string &filetransazione){
        this->filecliente=filecliente;
        this->fileconto=fileconto;
        this->filetransazione=filetransazione;
    }
    void update(const TransactionManager &t, const Cliente &cliente) override {
        std::ofstream file(filecliente, std::ios_base::app);
        std::string date = cliente.getStartingDate();
        date.pop_back();
        file << cliente.getName() << " " << cliente.getSurname() << " " << date << " " << cliente.getIdOwner() << std::endl;

    }

    void update(const TransactionManager &t, const Conto &conto) override {
        std::ofstream file(fileconto, std::ios_base::app);
        file << conto.getIdentifier() << " " << conto.getAmount() << " " << conto.getIdOwner() << std::endl;
    }

    void update(const TransactionManager &t, const Transazione &transazione) override {
        std::ofstream file(filetransazione, std::ios_base::app);
        std::string data = transazione.getTimestamp();
        data.pop_back();
        file << transazione.getType() << " " << transazione.getDestinationAddress() << " " << transazione.getSourceAddress() << " " << transazione.getAmount() << " " << transazione.getTransationId() << " " << data << " " << std::endl;
    }
};