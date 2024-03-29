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
    std::string startingDate;
    std::string idOwner;
public:
    Cliente()= default;
    Cliente(const std::string &name, const std::string &surname, const std::string &startingDate, const std::string &idOwner);

    const std::string &getIdOwner() const;

    const std::string &getSurname() const;

    const std::string &getStartingDate() const;

    const std::string &getName() const;
};


#endif //LABORATORIOPROG_LORENZODINARDO_CLIENTE_H
