//
// Created by Lorenzo Dinardo on 04/03/23.
//
#include "gtest/gtest.h"
#include"../Conto.h"

TEST(Conto,AddTransactionConto){
    Conto conto("identifier", 100 , "Cliente1");
    std::shared_ptr<Transazione> transazione1=std::make_shared<Transazione>("","identifier",20,"transazione0","",bonifico);
    conto.addTransaction(transazione1);
    ASSERT_EQ(80,conto.getAmount());
}

TEST(Conto,AmountNegative){
    Conto conto("identifier", 100 , "Cliente1");
    std::shared_ptr<Transazione> transazione1=std::make_shared<Transazione>("","identifier",120,"transazione0","",bonifico);
    ASSERT_THROW(conto.addTransaction(transazione1),std::runtime_error);
}
TEST(Conto,TransactionNegative){
    Conto conto("identifier", 100 , "Cliente1");
    std::shared_ptr<Transazione> transazione2 =std::make_shared<Transazione>("123456789", "987654321", -200,"transazione0","",bonifico);
    ASSERT_THROW(conto.addTransaction(transazione2), std::runtime_error);

}
TEST(ContoTest, TransactionListTest) {
    Conto conto("123456789", 1000, "Alice");

    // Add some transactions
    std::shared_ptr<Transazione> transaction1 = std::make_shared<Transazione>("", "identifier", 500, "transazione0", "", bonifico);
    conto.addTransaction(transaction1);
    std::shared_ptr<Transazione> transaction2 = std::make_shared<Transazione>("", "identifier", 200, "transazione1", "", bonifico);
    conto.addTransaction(transaction2);

    // Check if all transactions are in the list
    ASSERT_EQ(conto.getTransactionList().size(), 2);
    //non parte il ciclo for
}