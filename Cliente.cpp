//
// Created by Lorenzo Dinardo on 26/09/22.
//

#include "Cliente.h"
Cliente::Cliente(std::string name, std::string surname, std::string starting_date, std::string idOwner) {
    this->name = name;
    this->surname = surname;
    this-> starting_date= starting_date;
    this-> idOwner = idOwner;
}
std::string Cliente::getName() {
    return this->name;
}
std::string Cliente::getSurname() {
    return this->surname;
}
std::string Cliente::getStartingDate() {
    return this-> starting_date;
}
std::string Cliente::getIdOwner() {
    return this->idOwner;
}

