//
// Created by Arthur on 24/11/2019.
//

#ifndef TP3_CONTACORRENTE_H
#define TP3_CONTACORRENTE_H


#include "Conta.h"

class ContaCorrente : public Conta{
public:

private:
    double limiteCredito;

    void debitarConta(double debito, string descricao);
};


#endif //TP3_CONTACORRENTE_H
