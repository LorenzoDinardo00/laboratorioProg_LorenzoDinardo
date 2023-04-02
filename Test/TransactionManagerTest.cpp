//// Created by Lorenzo Dinardo on 04/03/23.//#include "gtest/gtest.h"#include "../TransactionManager.h"TEST(TransactionManagerTest, ContoIdentifierTest) {    TransactionManager transaction_manager;    std::string idcliente1= transaction_manager.addClient("paolo", "lore");    std::string identifier = transaction_manager.createAccount(500, idcliente1);    ASSERT_EQ(identifier,"conto0");    std::string idcliente2= transaction_manager.addClient("paolo", "lore");    std::string identifier2 = transaction_manager.createAccount(500, idcliente1);    ASSERT_EQ(identifier2,"conto1");}TEST(TransactionManagerTest,CreateTransactionBonifico){    TransactionManager manager;    std::string idcliente1= manager.addClient("paolo", "lore");    std::string idcliente2= manager.addClient("paola", "lore");    std::string idconto1= manager.createAccount(200, idcliente1);    std::string idconto2= manager.createAccount(500, idcliente2);    std::shared_ptr<Transazione>t = manager.createTransaction(idconto1, idconto2, 30);    ASSERT_EQ(t->getType(),bonifico);}TEST(TransactionManagerTest,CreateTransactionGiroconto){    TransactionManager manager;    std::string idcliente1= manager.addClient("paolo", "lore");    std::string idconto1 = manager.createAccount(200, idcliente1);    std::string idconto2 = manager.createAccount(300, idcliente1);    std::shared_ptr<Transazione>t = manager.createTransaction(idconto1, idconto2, 30);    ASSERT_EQ(t->getType(),giroconto);}TEST(TransactionManagerTest,CreateTransactionUnknownThrows){    TransactionManager manager;    std::string idcliente1= manager.addClient("paolo", "lore");    manager.createAccount(200, idcliente1);    ASSERT_THROW(manager.createTransaction("conto0", "conto1", 30), std::runtime_error);}