//
// Created by Arthur on 20/11/2019.
//

#ifndef TP3_CONTA_H
#define TP3_CONTA_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Cliente.h"
#include "Move.h"
#include "Data.h"

using namespace std;

class Conta {
    public:

        //Construtor

        Conta();
        Conta(Cliente c);
        Conta(int numConta, double Saldo, string cpf_cnpj);

        //Getters

        int getNumConta();
        double getSaldo();
        Cliente getCliente();
        vector<Move> getMovimentacoes();

        //Metodos

        virtual int gerarNumConta();
        virtual void debitarConta(double debito, string descricao);
        virtual void creditarConta(double credito, string descricao);
        virtual vector<Move> obterExtratoEntreDatas(Data di, Data df);
        virtual vector<Move> obterExtratoaPartirDeData(Data di);
        virtual vector<Move> obterExtratoMes();

        //Setters

        virtual void setCliente(Cliente c);
<<<<<<< HEAD

    private:
=======
>>>>>>> remotes/origin/Bia

        int numConta;
protected:
    Cliente cliente;
    vector<Move> movimentacoes;
    double saldo;
};


#endif //TP3_CONTA_H
