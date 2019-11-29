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

        int gerarNumConta();
        void debitarConta(double debito, string descricao);
        void creditarConta(double credito, string descricao);
        vector<Move> obterExtratoEntreDatas(Data di, Data df);
        vector<Move> obterExtratoaPartirDeData(Data di);
        vector<Move> obterExtratoMes();

        //Setters

        virtual void setCliente(Cliente c);

        int numConta;
        double saldo;
        Cliente cliente;
        vector<Move> movimentacoes;
};


#endif //TP3_CONTA_H
