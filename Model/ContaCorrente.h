//
<<<<<<< HEAD
// Created by Arthur on 24/11/2019.
=======
// Created by Bia Amorzinho on 28/11/2019.
>>>>>>> remotes/origin/Bia
//

#ifndef TP3_CONTACORRENTE_H
#define TP3_CONTACORRENTE_H
<<<<<<< HEAD


#include "Conta.h"

class ContaCorrente : public Conta{
public:

private:
    double limiteCredito;

    void debitarConta(double debito, string descricao);
=======
#include "Conta.h"


class ContaCorrente : public Conta{
public:
    ContaCorrente(double limiteCredito);

private:
    double limiteCredito;
>>>>>>> remotes/origin/Bia
};


#endif //TP3_CONTACORRENTE_H
