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
class TransactionManager {
private:
    int counterConto;
    int counterTransazione;
    int counterCliente;
    std::map<std::string,Cliente>clienti;
    std::map<std::string ,Conto>conti;
    std::vector<std::shared_ptr<Transazione>> transazioni;
public:
    TransactionManager();
    std::string CreazioneConto(float amount, const std::string& idOwner);
    void CreazioneTransazione(const std::string &destination_address, const std::string &source_address, float amount);
    std::string AggiungiCliente(const std::string &name, const std::string &surname);
    void Stampavalori();
};


#endif //LABORATORIOPROG_LORENZODINARDO_TRANSACTIONMANAGER_H
