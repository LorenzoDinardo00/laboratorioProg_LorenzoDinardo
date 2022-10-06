//
// Created by Lorenzo Dinardo on 26/09/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
#define LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
#include "Subject.cpp"
#include <list>
#include "Observer.h"

class ConcreteSubject: public Subject {
private:
    std::list<Observer*> observers;
    ConcreteSubject();
    ~ConcreteSubject();

public:
    static ConcreteSubject& getInstance() {
        static ConcreteSubject instance;
        return instance;
    }
    void registerObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObserver(Conto* bankAccount, Transazione* transaction);

    ConcreteSubject(const ConcreteSubject&) = delete;
    ConcreteSubject(ConcreteSubject&&) = delete;
    ConcreteSubject& operator=(const ConcreteSubject&) = delete;
    ConcreteSubject& operator=(ConcreteSubject&&) = delete;
};


#endif //LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
