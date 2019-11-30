//
<<<<<<< HEAD
// Created by Arthur on 24/11/2019.
=======
// Created by Bia Amorzinho on 28/11/2019.
>>>>>>> remotes/origin/Bia
//

#ifndef TP3_POUPANCA_H
#define TP3_POUPANCA_H

<<<<<<< HEAD

#include "Conta.h"
#include "SaldoDiaBase.h"
#include <list>
=======
#include "Conta.h"


>>>>>>> remotes/origin/Bia

class Poupanca : public Conta{
public:
    Poupanca();
<<<<<<< HEAD
    explicit Poupanca(Cliente c);
    void debitarConta(double debito);
private:
    vector<SaldoDiaBase> listaSaldoDiaBase;
    list<double> pegaSaldoDiaMaisProx(Data data);
=======
private:


>>>>>>> remotes/origin/Bia
};


#endif //TP3_POUPANCA_H
