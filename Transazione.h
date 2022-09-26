//
// Created by Lorenzo Dinardo on 22/08/22.
//
#include <string>

#ifndef LABORATORIOPROG_LORENZODINARDO_TRANSAZIONE_H
#define LABORATORIOPROG_LORENZODINARDO_TRANSAZIONE_H
enum TransationType { addition, removal };

class Transazione{
private:
    std::string destination_address;
    std::string source_address;
    float amount;
    std::string transation_ID;
    TransationType type;
    std::string timestamp;
public:
    Transazione();
    Transazione(std::string destination_address, std::string source_address, float amount, std::string transation_ID, TransationType type, std::string timestamp );
    std::string getSourceAddress();
    std::string getDestinationAddress();
    float getAmount() const;
    std::string getTransationID();
    TransationType getTransationType();
    std::string getTimestamp();
    std::string toString();

};
#endif //LABORATORIOPROG_LORENZODINARDO_TRANSAZIONE_H
