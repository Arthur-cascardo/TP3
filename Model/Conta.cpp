//
// Created by Arthur on 20/11/2019.
//

#include "Conta.h"
#include "../Controller/FileIO.h"


//Construtor

Conta::Conta(){

    this->numConta = 0;
    this->saldo = 0;
    this->cliente = Cliente();

}

Conta::Conta(Cliente c){

    FileIO a;
    string aux;
    static int i = 0;

    this->numConta = i++;
    this->saldo = 0;
    this->cliente = c;

    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";
    a.criarArquivo(aux);
    this->movimentacoes = a.preencheVectorMove(aux);
}

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

void Conta::debitarConta(double debito, string descricao){

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

vector<Move> Conta::obterExtratoEntreDatas(Data di, Data df){

    vector<Move> aux;
    string aux_file;
    FileIO a;
    Data d;

    aux_file = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";

    this->movimentacoes = a.preencheVectorMove(aux_file);
    for(Move m : this->movimentacoes){
        d = m.getData();
        if(di > d && df > d){
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
        if(di > d && df > d){
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