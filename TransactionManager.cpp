//
// Created by Lorenzo Dinardo on 18/10/22.
//

#include <iostream>
#include "TransactionManager.h"
#include "ConcreteSubject.h"
#include <fstream>
#include <sstream>

std::string TransactionManager::CreazioneConto(float amount, const std::string &idOwner) {
    std::string identifier ="conto"+ std::to_string(counterConto);
    Conto conto1 (identifier, 0, idOwner);

    counterConto ++;
    conti[identifier] = conto1;
    notifyObserver(*this,conto1);
    this->CreazioneTransazione(identifier,"",amount);
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
    notifyObserver(*this,cliente1);
    return idOwner;
}

void
TransactionManager::CreazioneTransazione(const std::string &destination_address, const std::string &source_address, float amount) {
    TransationType tipotransazione;
    std::string idTransaction= "transazione" +std::to_string(counterTransazione);
    std::chrono::time_point<std::chrono::system_clock>time= std::chrono::system_clock::now();
    std::time_t time2 = std::chrono::system_clock::to_time_t(time);
    Conto& contodest = conti.at(destination_address);
    std::shared_ptr<Transazione >t;
    if(source_address.empty()) {
         t = std::make_shared<Transazione>(destination_address, "-", amount,
                                                                       idTransaction, std::ctime(&time2), versamento);
    contodest.addTransaction(t);
    }else {
        Conto &contosour = conti.at(source_address);
        Cliente &clientedest = clienti.at(contodest.getIdOwner());
        Cliente &clientesour = clienti.at(contosour.getIdOwner());
        if (clientedest.getIdOwner() == clientesour.getIdOwner())
            tipotransazione = giroconto;
        else
            tipotransazione = bonifico;
            t = std::make_shared<Transazione>(destination_address, source_address,
                                                                                  amount, idTransaction,
                                                                                  std::ctime(&time2), tipotransazione);
        contodest.addTransaction(t);
        contosour.addTransaction(t);
    }
    //concreteSubject.notifyObserver(this, transaction.get());
    counterTransazione++;
    notifyObserver(*this, *t.get() );
}

void TransactionManager::Stampavalori() {
    for (auto conto:conti){

        std::cout<<conto.first <<" "<< conto.second.getAmount()<<std::endl;


    }


}

void TransactionManager::lettorevalori(const std::string &filecliente, const std::string &fileconto,
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
        if (!(iss >> identifier >> amount >> id_owner)) { throw std::runtime_error("errore"); } // error // process pair (a,b)


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


