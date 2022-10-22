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

