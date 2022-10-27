#include <iostream>
#include "Conto.h"
#include "TransactionManager.h"
#include <memory>
#include "Logger.cpp"
#include "FileManager.cpp"
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Logger stampaschermo;
    TransactionManager manager;
    FileManager stampafile("filecliente","fileconto","filetransazione");
    manager.registerObserver(&stampaschermo);
    manager.registerObserver(&stampafile);
    manager.lettorevalori("filecliente","fileconto","filetransazione");
    manager.Stampavalori();
    std::string idOwner1 = manager.AggiungiCliente("lorenzo","Dinardo");

    std::string idOwner2 = manager.AggiungiCliente("sofia","dinardo");
    std::string idConto = manager.CreazioneConto(1000, idOwner1);
    std::string idConto2 = manager.CreazioneConto(5000,idOwner2);
    manager.CreazioneTransazione(idConto,idConto2,500);
    manager.Stampavalori();



    return 0;
}
