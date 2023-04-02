//
// Created by Lorenzo Dinardo on 26/09/22.
//

#include "Cliente.h"

#include <utility>
Cliente::Cliente(const std::string &name, const std::string &surname, const std::string &startingDate, const std::string &idOwner) {
    this->name = name;
    this->surname =surname;
    this-> startingDate= startingDate;
    this-> idOwner = idOwner;
}


const std::string &Cliente::getName() const {
    return name;
}

const std::string &Cliente::getSurname() const {
    return surname;
}

const std::string &Cliente::getStartingDate() const {
    return startingDate;
}

const std::string &Cliente::getIdOwner() const {
    return idOwner;
}

