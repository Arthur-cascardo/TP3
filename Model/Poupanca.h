//
// Created by Bia Amorzinho on 28/11/2019.
//

#ifndef TP3_POUPANCA_H
#define TP3_POUPANCA_H

#include "Conta.h"
#include "SaldoDiaBase.h"
#include <algorithm>



class Poupanca : public Conta{
public:
    Poupanca(Cliente c);

    void debitarConta(double debito, string descricao);

    void creditarConta(double credito, string descricao);

    int pegaSaldoDiaBasePorDia(int dia);

    vector<SaldoDiaBase> obtemDiasAnteriores(int dia);

private:

    vector<SaldoDiaBase> listaSaldoDiaBase;
};


#endif //TP3_POUPANCA_H
