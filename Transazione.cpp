//
// Created by Lorenzo Dinardo on 22/08/22.
//
#include "Transazione.h"
#include <string>

Transazione::Transazione() {}
Transazione::Transazione(std::string destination_address, std::string source_address, float amount,
                         std::string transation_ID, Transazione::transation_type type, std::string timestamp) {
    this->destination_address = destination_address;
    this->source_address = source_address;
    this->amount = amount;
    this->transation_ID= transation_ID;
    this->type = type;
    this->timestamp = timestamp;
}

std::string Transazione::getSourceAddress() {
    return this->source_address;
}
std::string Transazione::getDestinationAddress() {
    return this-> destination_address;
}
float Transazione::getAmount() const {
    return this->amount;
}
std::string Transazione::getTransationID() {
    return this->transation_ID;
}

TransationType Transazione::getTransationType() {
    return this->type;
}
std::string Transazione::getTimestamp() {
    return this->timestamp;
}