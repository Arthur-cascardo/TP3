//
// Created by Bia Amorzinho on 28/11/2019.
//

#include <list>
#include "Poupanca.h"

Poupanca::Poupanca(Cliente c) : Conta(c) {

    this->numConta = numConta++;
    this->saldo = 0;
    SaldoDiaBase a(4),b(8),f(12),d(15),e(31);
    a.setSaldoDiaBase(45);
    b.setSaldoDiaBase(42);
    f.setSaldoDiaBase(37);
    d.setSaldoDiaBase(87);
    e.setSaldoDiaBase(21);
    this->listaSaldoDiaBase.push_back(b);
    this->listaSaldoDiaBase.push_back(a);
    this->listaSaldoDiaBase.push_back(e);
    this->listaSaldoDiaBase.push_back(d);
    this->listaSaldoDiaBase.push_back(f);
}

void Poupanca::debitarConta(double debito, string descricao){

    Data d;
    string aux;
    d.getDataSistema();
    bool diaBaseExiste = false;

    for(auto x : this->listaSaldoDiaBase){
        if(x.getDiaBase() == d.getDia()){
            diaBaseExiste = true;
        }
    }
    if(!diaBaseExiste){
        SaldoDiaBase saldoDiaBase(d.getDia());
        this->listaSaldoDiaBase.push_back(saldoDiaBase);
    }

    if(debito > this->listaSaldoDiaBase[this->pegaSaldoDiaBasePorDia(d.getDia())].getSaldoDiaBase()) {
        for(auto & i : this->listaSaldoDiaBase){
            if(i.getDiaBase() < d.getDia()){
                if(debito - i.getSaldoDiaBase() <= 0){
                    i.setSaldoDiaBase(i.getSaldoDiaBase() - debito);
                    debito = 0;
                    break;
                } else {
                    debito -= i.getSaldoDiaBase();
                    i.setSaldoDiaBase(0);
                }
            }
        }
    } else {
        Move m(d, descricao, 'D', debito);
        this->movimentacoes.push_back(m);
        this->listaSaldoDiaBase[this->pegaSaldoDiaBasePorDia(d.getDia())].setSaldoDiaBase(
                this->listaSaldoDiaBase[this->pegaSaldoDiaBasePorDia(d.getDia())].getSaldoDiaBase() - debito
        );
    }


}

void Poupanca::creditarConta(double credito, string descricao){

    Data d;
    bool diaBaseExiste = false;
    d.getDataSistema();
    for(auto x : this->listaSaldoDiaBase){
        if(x.getDiaBase() == d.getDia()){
            diaBaseExiste = true;
        }
    }
    if(!diaBaseExiste){
        SaldoDiaBase saldoDiaBase(d.getDia());
        this->listaSaldoDiaBase.push_back(saldoDiaBase);
    }

    Move m(d, descricao, 'C', credito);
    this->movimentacoes.push_back(m);
    this->listaSaldoDiaBase[this->pegaSaldoDiaBasePorDia(d.getDia())].setSaldoDiaBase(
            this->listaSaldoDiaBase[this->pegaSaldoDiaBasePorDia(d.getDia())].getSaldoDiaBase() + credito
            );
}

int Poupanca::pegaSaldoDiaBasePorDia(int dia){

    int count = 0;

    for(auto x : this->listaSaldoDiaBase){
        if(x.getDiaBase() == dia){
            return count;
        }
        count++;
    }

}