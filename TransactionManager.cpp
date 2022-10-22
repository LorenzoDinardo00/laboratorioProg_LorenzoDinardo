//
// Created by Lorenzo Dinardo on 18/10/22.
//

#include <iostream>
#include "TransactionManager.h"
#include "ConcreteSubject.h"

std::string TransactionManager::CreazioneConto(float amount, const std::string &idOwner) {
    std::string identifier ="conto"+ std::to_string(counterConto);
Conto conto1 (identifier, amount, idOwner);
counterConto ++;
conti[identifier] = conto1;
return identifier;
}

TransactionManager::TransactionManager() {
    counterConto=0;
    counterTransazione=0;
    counterCliente=0;
}

std::string TransactionManager::AggiungiCliente(const std::string &name, const std::string &surname) {
    std::string idOwner="Cliente" +std::to_string(counterCliente);
    std::chrono::time_point<std::chrono::system_clock>time= std::chrono::system_clock::now();
    std::time_t time2 = std::chrono::system_clock::to_time_t(time);
    Cliente cliente1(name, surname, std::ctime(&time2), idOwner);
    clienti[idOwner] = cliente1;
    counterCliente++;
    return idOwner;
}

void
TransactionManager::CreazioneTransazione(const std::string &destination_address, const std::string &source_address, float amount) {
    TransationType tipotransazione;
    std::string idTransaction= "transazione" +std::to_string(counterTransazione);
    std::chrono::time_point<std::chrono::system_clock>time= std::chrono::system_clock::now();
    std::time_t time2 = std::chrono::system_clock::to_time_t(time);
    Conto& contodest = conti.at(destination_address);
    Conto& contosour = conti.at(source_address);
    Cliente&  clientedest = clienti.at(contodest.getOwner());
    Cliente& clientesour = clienti.at(contosour.getOwner());
    if(clientedest.getIdOwner()==clientesour.getIdOwner())
        tipotransazione = giroconto;
    else
        tipotransazione = bonifico;
    std::shared_ptr<Transazione> transazione2 = std::make_shared<Transazione>(destination_address, source_address,amount,idTransaction,std::ctime(&time2),tipotransazione);
    contodest.addTransaction(transazione2);
    contosour.addTransaction(transazione2);
    auto& concreteSubject = ConcreteSubject::getInstance();
    concreteSubject.notifyObserver(this, transaction.get());
    counterTransazione++;
}

void TransactionManager::Stampavalori() {
    for (auto conto:conti){

        std::cout<<conto.first <<" "<< conto.second.getAmount()<<std::endl;


    }
    //std::cout<<

}
