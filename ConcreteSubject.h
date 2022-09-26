//
// Created by Lorenzo Dinardo on 26/09/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
#define LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
#include "Subject.cpp"
#include <list>
#include "Observer.cpp"
class ConcreteSubject: public Subject {
private:
    std::list<Observer*> observers;
    ConcreteSubject();

public:
    static ConcreteSubject& getInstance();
    void registerObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObserver(Conto* bankAccount, Transazione* transaction);


};


#endif //LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
