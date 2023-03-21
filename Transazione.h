//
// Created by Lorenzo Dinardo on 22/08/22.
//
#include <string>

#ifndef LABORATORIOPROG_LORENZODINARDO_TRANSAZIONE_H
#define LABORATORIOPROG_LORENZODINARDO_TRANSAZIONE_H
enum TransationType { bonifico, giroconto };

class Transazione{
private:
    std::string destination_address;
    std::string source_address;
    float amount;
    std::string transation_ID;;
    std::string timestamp;
    TransationType type;
public:
    Transazione(std::string destination_address, std::string source_address, float amount, std::string transation_ID,
                std::string timestamp, TransationType type);

    const std::string &getDestinationAddress() const;

    const std::string &getSourceAddress() const;

    float getAmount() const;

    const std::string &getTransationId() const;

    const std::string &getTimestamp() const;

    TransationType getType() const;

};
#endif //LABORATORIOPROG_LORENZODINARDO_TRANSAZIONE_H
