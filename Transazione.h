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
    Transazione();
    Transazione(std::string destination_address, std::string source_address, float amount, std::string transation_ID,
                std::string timestamp, TransationType type);
    std::string getSourceAddress();
    std::string getDestinationAddress();
    float getAmount() const;
    std::string getTransationID();
    TransationType getTransationType();
    std::string getTimestamp();
    std::string toString();
};
#endif //LABORATORIOPROG_LORENZODINARDO_TRANSAZIONE_H
