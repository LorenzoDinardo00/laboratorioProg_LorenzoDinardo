#include <iostream>
#include "Conto.h"
#include <memory>

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Cliente cliente1("nome", "cognome", "3-11-2000","client1" );
    Transazione* transazione1 = new Transazione("conto1", "conto2",1000,"transaction1",addition,"timestamp");
    std::list<Transazione*> transactions;
    transactions.insert(transactions.begin(), transazione1);
    std::unique_ptr<Conto> ptr1(new Conto("obj1",0, transactions, cliente1));
    std::cout << ptr1->getIdentifier() << std::endl;
    return 0;
}
