//
// Created by Lorenzo Dinardo on 04/03/23.
//
#include "gtest/gtest.h"
#include "../TransactionManager.h"

TEST(TransactionManagerTest, ContoIdentifierTest) {
    TransactionManager transaction_manager;
    std::string idcliente1= transaction_manager.add_client("paolo", "lore");
    std::string identifier = transaction_manager.create_account(500, idcliente1);
    ASSERT_EQ(identifier,"conto0");
    std::string idcliente2= transaction_manager.add_client("paolo", "lore");
    std::string identifier2 = transaction_manager.create_account(500, idcliente1);
    ASSERT_EQ(identifier2,"conto1");
}
TEST(TransactionManagerTest,CreateTransactionBonifico){
    TransactionManager manager;
    std::string idcliente1= manager.add_client("paolo", "lore");
    std::string idcliente2= manager.add_client("paola", "lore");

    std::string idconto1= manager.create_account(200, idcliente1);
    std::string idconto2= manager.create_account(500, idcliente2);
    std::shared_ptr<Transazione>t = manager.create_transaction(idconto1, idconto2, 30);
    ASSERT_EQ(t->getType(),bonifico);
}
TEST(TransactionManagerTest,CreateTransactionGiroconto){
    TransactionManager manager;
    std::string idcliente1= manager.add_client("paolo", "lore");
    std::string idconto1 = manager.create_account(200, idcliente1);
    std::string idconto2 = manager.create_account(300, idcliente1);

    std::shared_ptr<Transazione>t = manager.create_transaction(idconto1, idconto2, 30);
    ASSERT_EQ(t->getType(),giroconto);
}


TEST(TransactionManagerTest,CreateTransactionUnknownThrows){
    TransactionManager manager;
    std::string idcliente1= manager.add_client("paolo", "lore");
    manager.create_account(200, idcliente1);
    ASSERT_THROW(manager.create_transaction("conto0", "conto1", 30), std::runtime_error);
}



