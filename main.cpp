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
    /* manager.Stampavalori();
    std::string idOwner1 = manager.AggiungiCliente("lorenzo","Dinardo");

    std::string idOwner2 = manager.AggiungiCliente("Ida","Basta");
    std::string idConto = manager.CreazioneConto(1000, idOwner1);
    std::string idConto2 = manager.CreazioneConto(5000,idOwner2);
    manager.CreazioneTransazione(idConto,idConto2,500);
    manager.Stampavalori();
     */
    int scelta = 0;
    while(scelta!=5){
        std::cout<<"seleziona un'opzione:\n";
        std::cout<<"1. aggiungi cliente\n";
        std::cout<<"2. aggiungi conto a un cliente presente\n";
        std::cout<<"3. effettua transazione\n";
        std::cout<<"4. mostra valori\n";
        std::cout<<"5. esci dal menù\n";
        std::cout<<"> ";
        std::cin>>scelta;
        switch(scelta){
            case 1: {
                std::string nome, cognome;
                float amount;
                std::cout << "inserisci il nome del cliente: ";
                std::cin >> nome;
                std::cout << "inserisci il cognome del cliente: ";
                std::cin >> cognome;
                //std::string cliente;
                std::string idOwner = manager.AggiungiCliente(nome, cognome);
                std::cout << "Cliente aggiunto correttamente\n";
                break;
            }
            case 2:{
                std::string idOwner1;
                float amount;
                std::cout<<"inserisci l'ID del cliente";
                std::cin>>idOwner1;
                std::cout<<"inserisci l'amount del conto: ";
                std::cin>>amount;
                manager.CreazioneConto(amount,idOwner1);
                std::cout<<"conto creato con successo\n";
                break;
        }
            case 3:{
                std::string idOwner1,idOwner2;
                float amount;
                std::cout<<"inserisci l'ID del conto mittente: ";
                std::cin>>idOwner1;
                std::cout<<"inserisci l'ID del conto destinatario: ";
                std::cin>>idOwner2;
                std::cout<<"inserisci l'amount della transazione: ";
                std::cin>>amount;
                manager.CreazioneTransazione(idOwner2,idOwner1,amount);
                std::cout<<"transazione creata con successo!\n";
                break;
        }
            case 4:{
                manager.Stampavalori();
                break;
        }
            case 5:{
                return 0;

        }
            default:{
            std::cout<<"Scelta non valida riprova\n";
            break;
        }
        }


    }


    return 0;

}
