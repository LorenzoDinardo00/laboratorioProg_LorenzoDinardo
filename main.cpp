#include <iostream>
#include "Conto.h"
#include "TransactionManager.h"
#include <memory>

int main() {
    //std::cout << "Hello, World!" << std::endl;
    TransactionManager manager;
    std::string idOwner1 = manager.AggiungiCliente("Lorenzo","Dinardo");

    std::string idOwner2 = manager.AggiungiCliente("lore","dina");
    std::string idConto = manager.CreazioneConto(0, idOwner1);
    std::string idConto2 = manager.CreazioneConto(1000,idOwner2);
    manager.CreazioneTransazione(idConto,idConto2,500);
    manager.Stampavalori();

    return 0;
}
