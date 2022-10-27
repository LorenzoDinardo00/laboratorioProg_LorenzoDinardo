//
// Created by Lorenzo Dinardo on 26/09/22.
//

#include "Cliente.h"

#include <utility>
Cliente::Cliente(std::string name, std::string surname, std::string starting_date, std::string idOwner) {
    this->name = std::move(name);
    this->surname = std::move(surname);
    this-> starting_date= std::move(starting_date);
    this-> idOwner = std::move(idOwner);
}


const std::string &Cliente::getName() const {
    return name;
}

const std::string &Cliente::getSurname() const {
    return surname;
}

const std::string &Cliente::getStartingDate() const {
    return starting_date;
}

const std::string &Cliente::getIdOwner() const {
    return idOwner;
}

