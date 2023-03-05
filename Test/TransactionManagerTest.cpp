//
// Created by Lorenzo Dinardo on 04/03/23.
//
#include "gtest/gtest.h"
#include "../TransactionManager.h"

TEST(TransactionManagerTest, identifierTest) {
    TransactionManager transaction_manager;
    std::string identifier = transaction_manager.CreazioneConto(500,"IDCliente");
    ASSERT_EQ(identifier,"conto0");
}

