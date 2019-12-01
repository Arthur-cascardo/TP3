//
// Created by Arthur on 20/11/2019.
//

#include "Banco.h"
#include "ContaCorrente.h"
#include "Poupanca.h"
#include "Interface.h"

Banco::Banco(string newBanco)
{
    nomeBanco = newBanco;
}

void Banco::addCliente(Cliente newCliente) {

    this->clientes.push_back(newCliente);
}

void Banco::addConta(Cliente newConta, char tipoDeConta, double limiteCredito) {

    switch(tipoDeConta){
        case 'C': {
            ContaCorrente c(newConta, limiteCredito);
            this->contaCorrente.push_back(c);
            break;
        }
        case 'P': {
            Poupanca p(newConta);
            this->poupanca.push_back(p);
            break;
        }
        default: {
            Interface i;
            i.erroValorDigitado();
        }
    }
}
void Banco::removeCliente(string cpf) {

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->getCPF_CNPJ() == cpf) {
            for (auto y : this->contaCorrente) {
                if (y.getCliente().getCPF_CNPJ() == cpf) {
                    throw string("Este cliente não pode ser removido pois possui uma Conta \n");

                }
            }
            this->clientes.erase(it);
        }
        for (auto it = clientes.begin(); it != clientes.end(); ++it) {
            if (it->getCPF_CNPJ() == cpf) {
                for (auto y : this->poupanca) {
                    if (y.getCliente().getCPF_CNPJ() == cpf) {
                        throw string("Este cliente não pode ser removido pois possui uma Conta \n");

                    }
                }
                this->clientes.erase(it);
            }

        }
    }
}

void Banco::removeConta(int contaRemovida) {

    for (auto it = contaCorrente.begin(); it != contaCorrente.end(); ++it) {
        if (it->getNumConta() == contaRemovida) {
            this->contaCorrente.erase(it);
            break;
        }
    }
    for (auto it = poupanca.begin(); it != poupanca.end(); ++it) {
        if (it->getNumConta() == contaRemovida) {
            this->poupanca.erase(it);
            break;
        }
    }
}

string Banco::getnomeBanco() {
    return nomeBanco;
}


vector<Cliente> Banco::getClientList() {

    return this->clientes;

}

vector<ContaCorrente> Banco::getContaCorrenteList() {

    return this->contaCorrente;

}

vector<Poupanca> Banco::getPoupancaList() {

    return this->poupanca;

}

void Banco::deposito(int numConta, double valDeposito) {

    int count = 0;

    for (auto x : this->contaCorrente) {
        if (numConta == x.getNumConta()) {
            this->contaCorrente[count].creditarConta(valDeposito, "Deposito");
            break;
        }
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        if (numConta == x.getNumConta()) {
            this->poupanca[count].creditarConta(valDeposito, "Deposito");
            break;
        }
        count++;
    }
}

void Banco::saque(int numConta, double valSaque) {

    int count = 0;

    for (auto x : this->contaCorrente) {
        if (numConta == x.getNumConta()) {
            this->contaCorrente[count].debitarConta(valSaque, "Saque");
            break;
        }
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        if (numConta == x.getNumConta()) {
            this->poupanca[count].debitarConta(valSaque, "Saque");
            break;
        }
        count++;
    }
}

double Banco::getSaldo(int numConta) {
    for (auto x : this->contaCorrente) {
        if (numConta == x.getNumConta()) {
            double saldo = x.getSaldo();
            return saldo;
        }
    }
    for (auto x : this->poupanca) {
        if (numConta == x.getNumConta()) {
            double saldo = x.getSaldo();
            return saldo;
        }
    }
}

void Banco::transferencia(int contaorigem, int contadestino, double valorTransferencia) {

    int count = 0;

    for (auto x : this->contaCorrente) {
        if (contaorigem == x.getNumConta()) {
            this->contaCorrente[count].debitarConta(valorTransferencia, "Transferencia para a conta: " + contadestino);
            break;
        }
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        if (contaorigem == x.getNumConta()) {
            this->poupanca[count].debitarConta(valorTransferencia, "Transferencia para a conta: " + contadestino);
            break;
        }
        count++;
    }

    count = 0;

    for (auto x : this->contaCorrente) {
        if (contadestino == x.getNumConta()) {
            this->contaCorrente[count].creditarConta(valorTransferencia, "Transferencia da conta: " + contaorigem);
            break;
        }
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        if (contadestino == x.getNumConta()) {
            this->poupanca[count].creditarConta(valorTransferencia, "Transferencia da conta: " + contaorigem);
            break;
        }
        count++;
    }
}

void Banco::tarifa() {

    int count = 0;

    for (auto x : this->contaCorrente) {
        this->contaCorrente[count].debitarConta(15, "Cobrança de tarifa");
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        this->poupanca[count].debitarConta(15, "Cobrança de tarifa");
        count++;
    }
}

vector<Move> Banco::extratomes(int numConta) {

    vector<Move> aux;
    int count = 0;

    for (auto x : this->contaCorrente) {
        if (numConta == x.getNumConta()) {
            aux = this->contaCorrente[count].obterExtratoMes();
            return aux;
        }
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        if (numConta == x.getNumConta()) {
            aux = this->poupanca[count].obterExtratoMes();
            return aux;
        }

    }
}

vector<Move> Banco::extratoentredatas(int numConta, Data di, Data df) {

    vector<Move> aux;
    int count = 0;

    for (auto x : this->contaCorrente) {
        if (numConta == x.getNumConta()) {
            aux = this->contaCorrente[count].obterExtratoEntreDatas(di, df);
            return aux;
        }
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        if (numConta == x.getNumConta()) {
            aux = this->poupanca[count].obterExtratoEntreDatas(di, df);
            return aux;
        }
        count++;
    }

}

vector<Move> Banco::extratoapartirdata(int numConta, Data di) {

    vector<Move> aux;
    int count = 0;

    for (auto x : this->contaCorrente) {
        if (numConta == x.getNumConta()) {
            aux = this->contaCorrente[count].obterExtratoaPartirDeData(di);
            return aux;

        }
    }
    count = 0;
    for (auto x : this->poupanca) {
        if (numConta == x.getNumConta()) {
            aux = this->poupanca[count].obterExtratoaPartirDeData(di);
            return aux;
        }
    }
}

void Banco::imposto() {

    int count = 0;
    vector<Move> vetMovi;

    for (auto x : this->contaCorrente) {
        float valor = 0;
        vetMovi = this->contaCorrente[count].getMovimentacoes();
        for (auto y : vetMovi) {
            if (y.getDC() == 'C') {
                valor += y.getValor();
            }
        }
        valor = valor * 0.0038;
        this->contaCorrente[count].debitarConta(valor, "Cobranca de CPMF");
        count++;
    }
    count = 0;
    for (auto x : this->poupanca) {
        float valor = 0;
        vetMovi = this->poupanca[count].getMovimentacoes();
        for (auto y : vetMovi) {
            if (y.getDC() == 'C') {
                valor += y.getValor();
            }
        }
        valor = valor * 0.0038;
        this->poupanca[count].debitarConta(valor, "Cobranca de CPMF");
        count++;
    }
}

Banco::~Banco(){

}


