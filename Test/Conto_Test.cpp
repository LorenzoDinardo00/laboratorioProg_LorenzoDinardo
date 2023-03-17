//
// Created by Lorenzo Dinardo on 04/03/23.
//
#include "gtest/gtest.h"
#include"../Conto.h"
/*
TEST(Conto,AddTransactionConto){
    Conto conto("identifier", 100 , "Cliente1");
    Conto conto2("identifier2",10,"Cliente2");
    std::shared_ptr<Transazione> transazione1=std::make_shared<Transazione>("identifier2","identifier",20,"transazione0","",bonifico);
    conto.addTransaction(transazione1);
    ASSERT_EQ(80,conto.getAmount());
    ASSERT_EQ(30,conto2.getAmount());
}

*/

TEST(Conto,AmountNegative){
    Conto conto("identifier", 100 , "Cliente1");
    std::shared_ptr<Transazione> transazione1=std::make_shared<Transazione>("id2","identifier",120,"transazione0","",bonifico);
    ASSERT_THROW(conto.addTransaction(transazione1),std::runtime_error);
}
TEST(Conto,ValidSourceAddress){
    Conto conto("identifier", 100 , "Cliente1");
    std::shared_ptr<Transazione> transazione1=std::make_shared<Transazione>("id2","identifier",80,"transazione0","",bonifico);
    std::shared_ptr<Transazione> transazione2=std::make_shared<Transazione>("id2","id3",80,"transazione0","",bonifico);

    ASSERT_THROW(conto.addTransaction(transazione2),std::runtime_error);
}
TEST(Conto,ValidDestinationAddress){
    Conto conto("identifier", 100 , "Cliente1");
    std::shared_ptr<Transazione> transazione1=std::make_shared<Transazione>("identifier","12345",80,"transazione0","",bonifico);
    std::shared_ptr<Transazione> transazione2=std::make_shared<Transazione>("id2","id3",80,"transazione0","",bonifico);

    ASSERT_THROW(conto.addTransaction(transazione2),std::runtime_error);
}
TEST(ContoTest, TransactionListTest) {
    Conto conto("123456789", 1000, "Alice");

    std::shared_ptr<Transazione> transaction1 = std::make_shared<Transazione>("lore", "123456789", 500, "transazione0", "", bonifico);
    conto.addTransaction(transaction1);
    std::shared_ptr<Transazione> transaction2 = std::make_shared<Transazione>("dina", "123456789", 200, "transazione1", "", bonifico);
    conto.addTransaction(transaction2);

    ASSERT_EQ(conto.getTransactionList().size(), 2);
    //non parte il ciclo for
    for(auto t:conto.getTransactionList()){
        if(t==transaction2)
            SUCCEED();
    }
}