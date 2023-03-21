//
// Created by Lorenzo Dinardo on 17/03/23.
//

#ifndef LABORATORIOPROG_LORENZODINARDO_FILEMANAGER_H
#define LABORATORIOPROG_LORENZODINARDO_FILEMANAGER_H
//
// Created by Lorenzo Dinardo on 26/09/22.
//
#include <fstream>
#include <iostream>
#include "Conto.h"
#include "Observer.h"

class FileManager: public Observer {
private:
    std::string filecliente;
    std::string fileconto;
    std::string filetransazione;

public:
    FileManager(std::string filecliente, std::string fileconto, std::string filetransazione);

    void update(const TransactionManager &t, const Cliente &cliente) override;

    void update(const TransactionManager &t, const Conto &conto) override;

    void update(const TransactionManager &t, const Transazione &transazione) override;
};

#endif //LABORATORIOPROG_LORENZODINARDO_FILEMANAGER_H
