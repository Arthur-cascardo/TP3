//
// Created by Bia Amorzinho on 28/11/2019.
//

#ifndef TP3_CONTACORRENTE_H
#define TP3_CONTACORRENTE_H
#include "Conta.h"


class ContaCorrente : public Conta{
public:

    ContaCorrente(Cliente c, double limiteCredito);

    void debitarConta(double debito, string descricao) override;

    void creditarConta(double credito, string descricao) override;
private:


    double limiteCredito;
};


#endif //TP3_CONTACORRENTE_H
