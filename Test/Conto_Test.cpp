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

TEST(Conto,TransactioninList){
    Conto conto("identifier", 100 , "Cliente1");
    std::shared_ptr<Transazione> transazione1=std::make_shared<Transazione>("","identifier",120,"transazione0","",bonifico);
    conto.addTransaction(transazione1);
    for (auto transazione : conto.getTransactionList() ){
        if(transazione==transazione1){
            SUCCEED();
        }
    }
    FAIL();
}