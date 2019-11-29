//
// Created by Bia Amorzinho on 28/11/2019.
//

#include "ContaCorrente.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include "../Controller/FileIO.h"
#include <ctime>
#include "Cliente.h"
#include "Move.h"
#include "Data.h"

ContaCorrente::ContaCorrente(double limiteCredito){
    this->numConta = numConta;
    this->cliente = cliente;
    this->saldo = saldo;
    this->limiteCredito = limiteCredito;
}

/*
void ContaCorrente::debitarConta(double debito, string descricao){

    Data d;
    FileIO a;
    string aux;
    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";

    if(debito > this->saldo){return;}

    d.getDataSistema();
    Move m(d, descricao, 'D', debito);
    this->movimentacoes.push_back(m);
    this->saldo -= debito;
    a.salvarListaMove(aux,this->movimentacoes);
}
*/