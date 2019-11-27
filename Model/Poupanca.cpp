//
// Created by Arthur on 24/11/2019.
//

#include "Poupanca.h"
#include "../Controller/FileIO.h"

Poupanca::Poupanca(){

    this->numConta = 0;
    this->saldo = 0;
    this->cliente = Cliente();

}

Poupanca::Poupanca(Cliente c){

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

void Poupanca::debitarConta(double debito){

    Data d;
    FileIO a;
    string aux;
    vector<SaldoDiaBase> auxSaldoDiaBase = this->listaSaldoDiaBase;
    aux = "./Bancos/Inter/Movimentacoes " + this->cliente.getCPF_CNPJ() + ".txt";
    d.getDataSistema();
    int count = d.getDia() - 1;

    for(double saldo : this->pegaSaldoDiaMaisProx(d)){
        if(debito == 0){
            this->listaSaldoDiaBase = auxSaldoDiaBase;
            break;
        }
        if(count < 0){
            //Saldo insuficiente
            break;
        }
        if(debito > saldo){
            debito -= saldo;
            auxSaldoDiaBase[count].saldoDiaBase = 0;
            count--;
        } else {
            auxSaldoDiaBase[count].saldoDiaBase -= debito;
        }
    }
    Move m(d, "Debito conta poupança", 'D', debito);
    this->movimentacoes.push_back(m);
    a.salvarListaMove(aux,this->movimentacoes);
}

list<double> Poupanca::pegaSaldoDiaMaisProx(Data d){

    int dia = d.getDia();
    list<double> aux;

    for(auto x : this->listaSaldoDiaBase){
        if(x.diaBase == dia) {
            break;
        }
        aux.push_front(x.saldoDiaBase);
    }
    return aux;
}

