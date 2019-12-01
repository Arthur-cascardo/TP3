//
// Created by Arthur on 20/11/2019.
//

#include "Conta.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


//Construtor

Conta::Conta(Cliente c){

    static int numConta;

    this->numConta = numConta++;
    this->saldo = 0;
    this->cliente = c;
}

//Getters

int Conta::getNumConta(){return this->numConta;}
double Conta::getSaldo(){return this->saldo;}
Cliente Conta::getCliente(){return this->cliente;}
vector<Move> Conta::getMovimentacoes(){return this->movimentacoes;}

//Setters

void Conta::setCliente(Cliente c){this->cliente = c;}

//Metodos

vector<Move> Conta::obterExtratoEntreDatas(Data di, Data df){

    vector<Move> aux;
    string aux_file;
    Data d;

    for(Move m : this->movimentacoes){
        d = m.getData();
        if(di >= d && df >= d){
            aux.push_back(m);
        }
    }
    return aux;
}

vector<Move> Conta::obterExtratoaPartirDeData(Data di){

    vector<Move> aux;
    Data df;
    df.getDataSistema();
    string aux_file;
    Data d;

    for(Move m : this->movimentacoes){
        d = m.getData();
        if(di >= d && df >= d){
            aux.push_back(m);
        }
    }
    return aux;
}

vector<Move> Conta::obterExtratoMes(){

    vector<Move> aux;
    Data d;
    int aux_dia,aux_mes,aux_ano;
    string aux_file;

    d.getDataSistema();
    aux_mes = d.getMes();
    aux_ano = d.getAno();
    aux_dia = d.numeroDias(aux_mes, aux_ano);

    Data di(1,aux_mes,aux_ano);
    Data df(aux_dia, aux_mes, aux_ano);



    for(Move m : this->movimentacoes){
        d = m.getData();
        if(di > d && df > d){
            aux.push_back(m);
        }
    }
    return aux;
}