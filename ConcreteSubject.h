//
// Created by Lorenzo Dinardo on 26/09/22.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
#define LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
#include "Subject.cpp"
#include <list>

class ConcreteSubject: public Subject {
private:
    std::list<Observer*> observers;

public:
    void registerObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObserver(const TransactionManager &t, const Cliente &cliente) override;
    void notifyObserver(const TransactionManager &t, const Conto &conto) override;
    void notifyObserver(const TransactionManager &t, const Transazione &transazione) override;


};


#endif //LABORATORIOPROG_LORENZODINARDO_CONCRETESUBJECT_H
