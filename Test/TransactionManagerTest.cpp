//
// Created by Lorenzo Dinardo on 04/03/23.
//
#include "gtest/gtest.h"
#include "../TransactionManager.h"

TEST(TransactionManagerTest, ContoIdentifierTest) {
    TransactionManager transaction_manager;
    std::string idcliente1=transaction_manager.AggiungiCliente("paolo","lore");
    std::string identifier = transaction_manager.CreazioneConto(500,idcliente1);
    ASSERT_EQ(identifier,"conto0");
}
TEST(TransactionManagerTest,AddTransactionTestbonifico){
    TransactionManager manager;
    std::string idcliente1=manager.AggiungiCliente("paolo","lore");
    std::string idcliente2=manager.AggiungiCliente("paola","lore");

    std::string idconto1= manager.CreazioneConto(200,idcliente1);
    std::string idconto2= manager.CreazioneConto(500,idcliente2);
    std::shared_ptr<Transazione>t = manager.CreazioneTransazione(idconto1,idconto2,30);
    ASSERT_EQ(t->getType(),bonifico);
}
TEST(TransactionManagerTest,AddTransactionTestgiroconto){
    TransactionManager manager;
    std::string idcliente1=manager.AggiungiCliente("paolo","lore");
    std::string idconto1 = manager.CreazioneConto(200,idcliente1);
    std::string idconto2 = manager.CreazioneConto(300,idcliente1);

    std::shared_ptr<Transazione>t = manager.CreazioneTransazione(idconto1,idconto2,30);
    ASSERT_EQ(t->getType(),giroconto);
}

TEST(TransactionManagerTest,AddTransactionTestVersamento){
    TransactionManager manager;
    std::string idcliente1=manager.AggiungiCliente("paolo","lore");
    manager.CreazioneConto(200,idcliente1);

    std::shared_ptr<Transazione>t = manager.CreazioneTransazione("conto0","",30);
    ASSERT_EQ(t->getType(),versamento);
}
TEST(TransactionManagerTest,AddTransactionTestContoinesistente){
    TransactionManager manager;
    std::string idcliente1=manager.AggiungiCliente("paolo","lore");
    manager.CreazioneConto(200,idcliente1);
    ASSERT_THROW(manager.CreazioneTransazione("conto0","conto1",30),std::runtime_error);
}



