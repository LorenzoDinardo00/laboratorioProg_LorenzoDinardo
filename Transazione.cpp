//
// Created by Lorenzo Dinardo on 22/08/22.
//
#include "Transazione.h"
#include <string>
#include <utility>


Transazione::Transazione(const std::string &destinationAddress, const std::string &sourceAddress, float amount,
                         const std::string &transationId,
                         const std::string &timeStamp, TransationType type) {
    this->destinationAddress = destinationAddress;
    this->sourceAddress = sourceAddress;
    this->amount = amount;
    this->transationID= transationId;
    this->type = type;
    this->timestamp = timeStamp;
    if(this->destinationAddress == "")
        throw std::runtime_error("destinazione inesistente");
    if(this->sourceAddress == "" && this->type == bonifico )
        throw std::runtime_error("sorgente inesistente in un bonifico");

    if(this->amount <= 0)
        throw std::runtime_error("transazione con amount negativo o nullo");
    if(this->sourceAddress == this->destinationAddress)
        throw std::runtime_error("transazione con mittente uguale a destinazione");




}


const std::string &Transazione::getDestinationAddress() const {
    return destinationAddress;
}

const std::string &Transazione::getSourceAddress() const {
    return sourceAddress;
}

float Transazione::getAmount() const {
    return amount;
}

const std::string &Transazione::getTransationId() const {
    return transationID;
}

const std::string &Transazione::getTimestamp() const {
    return timestamp;
}

TransationType Transazione::getType() const {
    return type;
}
