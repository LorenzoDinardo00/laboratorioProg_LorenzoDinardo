#include <iostream>
#include "Conto.h"
#include <memory>

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Cliente cliente1("nome", "cognome", "3-11-2000","client1" );
    std::shared_ptr<Transazione> transazione1 = std::make_shared<Transazione>("conto1", "conto2",1000,"transaction1",addition,"timestamp");
    std::unique_ptr<Conto> ptr1(new Conto("conto1", 0, cliente1));
    std::unique_ptr<Conto> ptr2(new Conto("conto2", 1000, cliente1));
    std::cout << ptr1->getIdentifier()<<" "<< ptr1->getAmount() << std::endl;
    std::cout << ptr2->getIdentifier()<<" "<< ptr2->getAmount() << std::endl;
    std::shared_ptr<Transazione> transazione2 = std::make_shared<Transazione>("conto1", "conto2",1000,"transaction1",addition,"timestamp");
    ptr1->addTransaction(transazione2);
    ptr2->addTransaction(transazione2);
    std::cout << ptr1->getIdentifier()<<" "<< ptr1->getAmount() << std::endl;
    std::cout << ptr2->getIdentifier()<<" "<< ptr2->getAmount() << std::endl;
    return 0;
}
