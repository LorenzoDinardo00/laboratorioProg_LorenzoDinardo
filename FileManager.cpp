//
// Created by Lorenzo Dinardo on 26/09/22.
//
#include <fstream>
#include <iostream>
#include "FileManager.h"
class FileManager: public Observer {
    void update(Conto bankAccount, Transazione transaction){
        std::ofstream outfile;
        outfile.open(bankAccount.getIdentifier() + ".txt");
        outfile<<transaction.toString()<< std::endl;
        outfile.close();
    }
};