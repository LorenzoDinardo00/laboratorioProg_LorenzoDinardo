//
// Created by Lorenzo Dinardo on 26/09/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_CLIENTE_H
#define LABORATORIOPROG_LORENZODINARDO_CLIENTE_H
#include<string>

class Cliente {
private:
    std::string name;
    std::string surname;
    std::string starting_date;
    std::string idOwner;
public:
    Cliente(std::string name, std::string surname, std::string starting_date, std::string idOwner);
    std::string getName();
    std::string getSurname();
    std::string getStartingDate();
    std::string getIdOwner();
};


#endif //LABORATORIOPROG_LORENZODINARDO_CLIENTE_H
