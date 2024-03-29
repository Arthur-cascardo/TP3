//
// Created by Arthur on 20/11/2019.
//

#include "Conta.h"
#include "../Controller/FileIO.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

<<<<<<< HEAD
=======

//Construtor

Conta::Conta(){

    this->numConta = 0;
    this->saldo = 0;
    this->cliente = Cliente();

}

Conta::Conta(Cliente c){

    FileIO a;
    string aux;

    this->numConta = gerarNumConta();
    this->saldo = 0;
    this->cliente = c;

    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";
    a.criarArquivo(aux);
    this->movimentacoes = a.preencheVectorMove(aux);
}

>>>>>>> remotes/origin/Bia
//Contrutor auxiliar

Conta::Conta(int numConta, double saldo, string cpf_cnpj){

    this->numConta = numConta;
    this->saldo = saldo;
    this->cliente.setCPF_CNPJ(cpf_cnpj);

}

//Getters

int Conta::getNumConta(){return this->numConta;}
double Conta::getSaldo(){return this->saldo;}
Cliente Conta::getCliente(){return this->cliente;}
vector<Move> Conta::getMovimentacoes(){return this->movimentacoes;}

//Setters

void Conta::setCliente(Cliente c){this->cliente = c;}

//Metodos

<<<<<<< HEAD
//void Conta::debitarConta(double debito, string descricao){
//
//    Data d;
//    FileIO a;
//    string aux;
//    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";
//
//    if(debito > this->saldo){return;}
//
//    d.getDataSistema();
//    Move m(d, descricao, 'D', debito);
//    this->movimentacoes.push_back(m);
//    this->saldo -= debito;
//    a.salvarListaMove(aux,this->movimentacoes);
//}
//
//void Conta::creditarConta(double credito, string descricao){
//
//    Data d;
//    FileIO a;
//    string aux;
//    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";
//
//    d.getDataSistema();
//    Move m(d, descricao, 'C', credito);
//    this->movimentacoes.push_back(m);
//    this->saldo += credito;
//    a.salvarListaMove(aux,this->movimentacoes);
//}
=======
void Conta::debitarConta(double debito, string descricao){

    Data d;
    FileIO a;
    string aux;
    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";

    if(debito > this->saldo){
        throw string ("Saldo Insuficiente");
    } else{

        d.getDataSistema();
        Move m(d, descricao, 'D', debito);
        this->movimentacoes.push_back(m);
        this->saldo -= debito;
        a.salvarListaMove(aux,this->movimentacoes);
    }


}
int Conta::gerarNumConta() {
    srand((unsigned)time(0));
    int maior = 1000;
    int menor = 9999;
    int aleatorio = rand()%(maior-menor+1) + menor;
    return aleatorio;
}

void Conta::creditarConta(double credito, string descricao){

    Data d;
    FileIO a;
    string aux;
    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";

    d.getDataSistema();
    Move m(d, descricao, 'C', credito);
    this->movimentacoes.push_back(m);
    this->saldo += credito;
    a.salvarListaMove(aux,this->movimentacoes);
}
>>>>>>> remotes/origin/Bia


vector<Move> Conta::obterExtratoEntreDatas(Data di, Data df){

    vector<Move> aux;
    string aux_file;
    FileIO a;
    Data d;

    aux_file = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";

    this->movimentacoes = a.preencheVectorMove(aux_file);
    for(Move m : this->movimentacoes){
        d = m.getData();
        if(di >= d && df >= d){
            aux.push_back(m);
        }
    }
    this->movimentacoes.clear();
    return aux;
}

vector<Move> Conta::obterExtratoaPartirDeData(Data di){

    vector<Move> aux;
    Data df;
    df.getDataSistema();
    string aux_file;
    Data d;
    FileIO a;

    aux_file = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";

    this->movimentacoes = a.preencheVectorMove(aux_file);

    for(Move m : this->movimentacoes){
        d = m.getData();
        if(di >= d && df >= d){
            aux.push_back(m);
        }
    }
    this->movimentacoes.clear();
    return aux;
}

vector<Move> Conta::obterExtratoMes(){

    vector<Move> aux;
    Data d;
    int aux_dia,aux_mes,aux_ano;
    string aux_file;
    FileIO a;

    aux_file = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";
    this->movimentacoes = a.preencheVectorMove(aux_file);
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
    this->movimentacoes.clear();
    return aux;
}