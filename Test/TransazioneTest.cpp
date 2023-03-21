//
// Created by Lorenzo Dinardo on 15/03/23.
//
#include "gtest/gtest.h"
#include "../Transazione.h"

TEST(Transazione,TransactionNegative){

    ASSERT_THROW(Transazione transazione1("lore", "source", -100, "transazione1", "",bonifico), std::runtime_error);

}
TEST(Transazione,B_EmptyDestination){

    ASSERT_THROW(Transazione transazione1("", "source", 100, "transazione1", "",bonifico), std::runtime_error);

}
TEST(Transazione,B_SourceEmpty){

    ASSERT_THROW(Transazione transazione1("123", "", 100, "transazione1", "",bonifico), std::runtime_error);

}
TEST(Transazione,G_check){

    ASSERT_THROW(Transazione transazione1("", "", 100, "transazione1", "",giroconto), std::runtime_error);

}

