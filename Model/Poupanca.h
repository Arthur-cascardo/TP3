//
// Created by Arthur on 24/11/2019.
//

#ifndef TP3_POUPANCA_H
#define TP3_POUPANCA_H


#include "Conta.h"
#include "SaldoDiaBase.h"
#include <list>

class Poupanca : public Conta{
public:
    Poupanca();
    explicit Poupanca(Cliente c);
    void debitarConta(double debito);
private:
    vector<SaldoDiaBase> listaSaldoDiaBase;
    list<double> pegaSaldoDiaMaisProx(Data data);
};


#endif //TP3_POUPANCA_H
