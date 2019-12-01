//
// Created by Bia Amorzinho on 28/11/2019.
//

#include "ContaCorrente.h"
#include "Cliente.h"

ContaCorrente::ContaCorrente(Cliente c, double limiteCredito) : Conta(c) {
    this->numConta = numConta;
    this->cliente = cliente;
    this->saldo = saldo;
    this->limiteCredito = limiteCredito;
}

void ContaCorrente::debitarConta(double debito, string descricao){

    Data d;
    string aux;

    if(debito > this->saldo + this->limiteCredito){
        throw string ("Saldo Insuficiente");
    } else{

        d.getDataSistema();
        Move m(d, descricao, 'D', debito);
        this->movimentacoes.push_back(m);
        this->saldo -= debito;
    }


}

void ContaCorrente::creditarConta(double credito, string descricao){

    Data d;
    string aux;

    d.getDataSistema();
    Move m(d, descricao, 'C', credito);
    this->movimentacoes.push_back(m);
    this->saldo += credito;
}