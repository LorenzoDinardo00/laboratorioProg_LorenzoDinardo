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


const std::string &Transazione::getDestinationAddress() const {
    return destination_address;
}

const std::string &Transazione::getSourceAddress() const {
    return source_address;
}

float Transazione::getAmount() const {
    return amount;
}

const std::string &Transazione::getTransationId() const {
    return transation_ID;
}

const std::string &Transazione::getTimestamp() const {
    return timestamp;
}

TransationType Transazione::getType() const {
    return type;
}
