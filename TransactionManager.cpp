//
// Created by Lorenzo Dinardo on 18/10/22.
//

#include <iostream>
#include "TransactionManager.h"
#include <fstream>
#include <sstream>
void TransactionManager::registerObserver(Observer *observer) {
    observers.push_back(observer);
}
void TransactionManager::removeObserver(Observer *observer) {
    observers.remove(observer);
}

void TransactionManager::notifyObserver(const Cliente &cliente) {
    for (auto & o : observers){
        o->update(*this,cliente);
    }
}
void TransactionManager::notifyObserver(const Conto &conto) {
    for (auto &observer: observers) {
        observer->update(*this, conto);
    }
}

void TransactionManager::notifyObserver(const Transazione &transazione) {
    for (auto &observer: observers) {
        observer->update(*this, transazione);
    }
}
std::string TransactionManager::create_account(float amount, const std::string &idOwner) {
    std::string identifier ="conto"+ std::to_string(counterConto);
    Conto account (identifier, amount, idOwner);

    counterConto ++;
    conti[identifier] = account;
    notifyObserver(account);
    return identifier;
}

TransactionManager::TransactionManager() {
    counterConto=0;
    counterTransazione=0;
    counterCliente=0;
}

std::string TransactionManager::add_client(const std::string &name, const std::string &surname) {
    std::string idOwner="Cliente" +std::to_string(counterCliente);
    std::chrono::time_point<std::chrono::system_clock>time= std::chrono::system_clock::now();
    std::time_t time_t = std::chrono::system_clock::to_time_t(time); //conversione in formato leggibile (std::time_t)
    Cliente client(name, surname, std::ctime(&time_t), idOwner);
    clienti[idOwner] = client;
    counterCliente++;
    notifyObserver(client);
    return idOwner;
}

std::shared_ptr<Transazione>
TransactionManager::create_transaction(const std::string &destination_address, const std::string &source_address, float amount) {
    TransationType transaction_time;
    std::string idTransaction= "transazione" +std::to_string(counterTransazione);
    std::chrono::time_point<std::chrono::system_clock>time= std::chrono::system_clock::now();
    std::time_t time_t = std::chrono::system_clock::to_time_t(time);
    Conto& destinationAccount = conti.at(destination_address);
    std::shared_ptr<Transazione >transaction;


    auto destinationAccountIterator = conti.find(destination_address);
    if(destinationAccountIterator == conti.end()){
        throw std::runtime_error("conto destinazione inesistente");
    }
    auto sourceAccountIt = conti.find(source_address);
    if(sourceAccountIt == conti.end()){
        throw std::runtime_error("conto sorgente inesistente");
    }
    Conto &sourceAccount = conti.at(source_address);
    Cliente &clientdest = clienti.at(destinationAccount.getIdOwner());
    Cliente &clientsour = clienti.at(sourceAccount.getIdOwner());
    if (clientdest.getIdOwner() == clientsour.getIdOwner())
        transaction_time = giroconto;
    else
        transaction_time = bonifico;
    transaction = std::make_shared<Transazione>(destination_address, source_address,
                                                amount, idTransaction,
                                                std::ctime(&time_t), transaction_time);
    destinationAccount.addTransaction(transaction);
    sourceAccount.addTransaction(transaction);

    //concreteSubject.notifyObserver(this, transaction.get());
    counterTransazione++;
    notifyObserver(*transaction.get() );
    return(transaction);
}

void TransactionManager::print_account() {
    for (auto account:conti){

        std::cout << account.first << " " << account.second.getAmount() << " " << account.second.getIdOwner() << std::endl;


    }


}


void TransactionManager::read_values(const std::string &filecliente, const std::string &fileconto,
                                     const std::string &filetransazione) {
    std::ifstream filec(filecliente,std::ios_base::in);
    std::string line;
    while(std::getline(filec,line)) {
        std::istringstream iss(line);
        std::string name;
        std::string surname;
        std::string starting_date_day_name;
        std::string starting_date_month;
        int day;
        std::string date;
        int year;
        std::string idOwner;
        if (!(iss >> name >> surname >> starting_date_day_name >>starting_date_month>>day>>date>>year>> idOwner)) { throw std::runtime_error("errore"); } // error // process pair (a,b)
        std::ostringstream  starting_date;
        starting_date<< starting_date_day_name<<" "<< starting_date_month << " "<<day<<" "<<date<<" "<<year<<std::endl;

        Cliente cliente(name,surname,starting_date.str(),idOwner);
        clienti[idOwner] = cliente;
        counterCliente++;
    }
    std::ifstream fileco(fileconto,std::ios_base::in);
    while(std::getline(fileco,line)) {
        std::istringstream iss(line);
        std::string identifier;
        float amount;
        std::string id_owner;
        if (!(iss >> identifier >> amount >> id_owner)) { throw std::runtime_error("errore"); }


        Conto conto(identifier,amount,id_owner);
        conti[identifier] = conto;
        counterConto++;
    }
    std::ifstream filet(filetransazione,std::ios_base::in);
    while(std::getline(filet,line)) {
        std::istringstream iss(line);
        std::string destination_address;
        std::string source_address;
        float amount;
        std::string transation_ID;;
        std::string timestamp;
        std::string starting_date_day_name;
        std::string starting_date_month;
        int day;
        std::string date;
        int year;
        int type;

        if (!(iss>>type >> destination_address >> source_address >> amount>>transation_ID>>starting_date_day_name >>starting_date_month>>day>>date>>year)) { throw std::runtime_error("errore"); } // error // process pair (a,b)
        std::shared_ptr<Transazione >t;
        std::ostringstream  starting_date;
        starting_date<< starting_date_day_name<<" "<< starting_date_month << " "<<day<<" "<<date<<" "<<year<<std::endl;
        t = std::make_shared<Transazione>(destination_address, source_address, amount,
                                          transation_ID,starting_date.str(),  (TransationType) type);
        transazioni.push_back(t);
        conti.at(destination_address).addTransaction(t);
        if(source_address!="-")
            conti.at(source_address).addTransaction(t);
        counterTransazione++;
    }
}


