//
// Created by Lorenzo Dinardo on 22/08/22.
//
#include "Transazione.h"
#include <string>
#include <utility>

Transazione::Transazione() {}
Transazione::Transazione(std::string destination_address, std::string source_address, float amount,
                         std::string transation_ID,
                         std::string timestamp, TransationType type) {
    this->destination_address = std::move(destination_address);
    this->source_address = std::move(source_address);
    this->amount = amount;
    this->transation_ID= std::move(transation_ID);
    this->type = type;
    this->timestamp = std::move(timestamp);
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
std::string Transazione:: toString(){
    return destination_address + " to " + source_address + " - amount: " + std::to_string(amount);
}
