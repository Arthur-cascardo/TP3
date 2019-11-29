//
// Created by Bia Amorzinho on 28/11/2019.
//

#ifndef TP3_CONTACORRENTE_H
#define TP3_CONTACORRENTE_H
#include "Conta.h"


class ContaCorrente : public Conta{
public:
    ContaCorrente(double limiteCredito);

private:
    double limiteCredito;
};


#endif //TP3_CONTACORRENTE_H
