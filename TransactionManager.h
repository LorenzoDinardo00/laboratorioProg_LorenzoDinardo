//
// Created by Lorenzo Dinardo on 18/10/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_TRANSACTIONMANAGER_H
#define LABORATORIOPROG_LORENZODINARDO_TRANSACTIONMANAGER_H
#include <string>
#include <map>
#include<memory>
#include <vector>
#include "Cliente.h"
#include "Conto.h"
#include "Transazione.h"
#include "Subject.h"
#include "Observer.h"

class TransactionManager : public Subject{
private:
    int counterConto;
    int counterTransazione;
    int counterCliente;
    std::map<std::string,Cliente>clienti;
    std::map<std::string ,Conto>conti;
    std::vector<std::shared_ptr<Transazione>> transazioni;
    std::list<Observer*> observers;

public:
    TransactionManager();
    void registerObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObserver(const Cliente &cliente) override;
    void notifyObserver(const Conto &conto) override;
    void notifyObserver(const Transazione &transazione) override;
    std::string createAccount(float amount, const std::string& idOwner);
    std::shared_ptr<Transazione>
    createTransaction(const std::string &destinationAddress, const std::string &sourceAddress, float amount);
    std::string addClient(const std::string &name, const std::string &surname);
    void printAccount();
    void readValues(const std::string &filecliente, const std::string &fileconto, const std::string &filetransazione);
};


#endif //LABORATORIOPROG_LORENZODINARDO_TRANSACTIONMANAGER_H
