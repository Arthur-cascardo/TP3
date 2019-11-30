//
// Created by Arthur on 20/11/2019.
//

#include "Banco.h"
#include "ContaCorrente.h"
#include "Poupanca.h"

Banco::Banco(string newBanco)
{
    nomeBanco = newBanco;
}

void Banco::addCliente(Cliente newCliente) {

    FileIO a;
    string aux;

    aux = "./Bancos/" + this->nomeBanco + "/Clientes " + this->nomeBanco + ".txt";

    this->setClientList();
    this->clientes.push_back(newCliente);
    a.salvarListaClientes(aux,this->clientes);

}

void Banco::addConta(Cliente newConta, char tipoDeConta, double limiteCredito) {
    FileIO a;
    if (tipoDeConta == 'c'){
        ContaCorrente c(limiteCredito);
        string aux;
        aux = "./Bancos/Inter/ContaCorrente " + this->nomeBanco + ".txt";
        this->setClientList();
        this->setContaList(tipoDeConta);
        this->contaCorrente.push_back(c);
        a.salvarListaContas(aux,this->contaCorrente);

    } else {
        Poupanca p();
        string aux;
        aux = "./Bancos/Inter/Poupanca " + this->nomeBanco + ".txt";
        this->setClientList();
        this->setContaList(tipoDeConta);
        //this->poupanca.push_back(p);
        //a.salvarListaContas(aux,this->poupanca);
    }







}

void Banco::removeCliente(string cpf) {

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->getCPF_CNPJ() == cpf) {
            for (auto y : this->contas) {
                if (y.getCliente().getCPF_CNPJ() == cpf) {
                    throw string ("Este cliente não pode ser removido pois possui uma Conta \n");

                }
            }
            this->clientes.erase(it);
        }


    }
}

void Banco::removeConta(int contaRemovida) {

    for (auto it = contas.begin(); it != contas.end(); ++it) {
        if (it->getNumConta() == contaRemovida) {
            this->contas.erase(it);
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

vector<Conta> Banco::getContasList() {

    return this->contas;

}
vector<ContaCorrente> Banco::getContaCorrenteList() {

    return this->contaCorrente;

}
vector<Poupanca> Banco::getPoupancaList() {

    return this->poupanca;

}


void Banco::deposito(int numConta, double valDeposito) {

    int count = 0;

    for (auto x : this->contas) {
        if (numConta == x.getNumConta()) {
            this->contas[count].creditarConta(valDeposito, "Deposito");
            break;
        }
        count++;
    }
}

void Banco::saque(int numConta, double valSaque) {

    int count = 0;

    for (auto x : this->contas) {
        if (numConta == x.getNumConta()) {
            this->contas[count].debitarConta(valSaque, "Saque");
            break;
        }
        count++;
    }
}

double Banco::getSaldo(int numConta) {
    for (auto x : this->contas) {
        if (numConta == x.getNumConta()) {
            double saldo = x.getSaldo();
            return saldo;
        }
    }
}

void Banco::transferencia(int contaorigem, int contadestino, double valorTransferencia) {

    int count = 0;

    for (auto x : this->contas) {
        if (contaorigem == x.getNumConta()) {
            this->contas[count].debitarConta(valorTransferencia, "Transferencia para a conta: " + contadestino);
            break;
        }
        count++;
    }

    count = 0;

    for (auto x : this->contas) {
        if (contadestino == x.getNumConta()) {
            this->contas[count].creditarConta(valorTransferencia, "Transferencia da conta: " + contaorigem);
            break;
        }
        count++;
    }
}

void Banco::tarifa() {

    int count = 0;

    for (auto x : this->contas) {
        this->contas[count].debitarConta(15, "Cobrança de tarifa");
        count++;
    }
}

vector<Move> Banco::extratomes(int numConta) {

    vector<Move> aux;
    int count = 0;

    for (auto x : this->contas) {
        if (numConta == x.getNumConta()) {
            aux = this->contas[count].obterExtratoMes();
            break;
        }
        count++;
    }
    return aux;
}

vector<Move> Banco::extratoentredatas(int numConta, Data di, Data df) {

    vector<Move> aux;
    int count = 0;

    for (auto x : this->contas) {
        if (numConta == x.getNumConta()) {
            aux = this->contas[count].obterExtratoEntreDatas(di, df);
            break;
        }
        count++;
    }
    return aux;
}

vector<Move> Banco::extratoapartirdata(int numConta, Data di) {

    vector<Move> aux;
    int count = 0;

    for (auto x : this->contas) {
        if (numConta == x.getNumConta()) {
            aux = this->contas[count].obterExtratoaPartirDeData(di);
            break;
        }
    }
    return aux;
}

void Banco::imposto() {

    int count = 0;
    vector<Move> vetMovi;

    for (auto x : this->contas) {
        float valor = 0;
        vetMovi = this->contas[count].getMovimentacoes();
        for (auto y : vetMovi) {
            if (y.getDC() == 'C') {
                valor += y.getValor();
            }
        }
        valor = valor * 0.0038;
        this->contas[count].debitarConta(valor, "Cobranca de CPMF");
        count++;
    }
}

void Banco::setClientList(){

    FileIO a;
    string aux;

    aux = "./Bancos/" + this->nomeBanco + "/Clientes " + this->nomeBanco + ".txt";
    this->clientes = a.preencheVectorCliente(aux);

}
//TODO: IMPLEMENTAR METODOS CORRETAMENTE PARA OS DOIS TIPOS DE CONTA
void Banco::setCorrenteList(){

<<<<<<< HEAD
    FileIO a;
    string aux;
    int count = 0;

    aux = "./Bancos/" + this->nomeBanco + "/Contas " + this->nomeBanco + ".txt";
    this->contas = a.preencheVectorConta(aux);
    for(auto x : this->contas){
        for(auto y : this->clientes){
            if(this->contas[count].getCliente().getCPF_CNPJ() == y.getCPF_CNPJ()) {
                this->contas[count].setCliente(y);
            }
        }
    }
}

void Banco::setPoupancaList(){
=======
void Banco::setContaList(char tipoDeConta){
>>>>>>> remotes/origin/Bia

    FileIO a;
    string aux;
    int count = 0;

    if (tipoDeConta == 'c'){
        aux = "./Bancos/Inter/ContaCorrente " + this->nomeBanco + ".txt";
        //this->contaCorrente = a.preencheVectorConta(aux);
        for(auto x : this->contas){
            for(auto y : this->clientes){
                if(this->contas[count].getCliente().getCPF_CNPJ() == y.getCPF_CNPJ()) {
                    this->contas[count].setCliente(y);
                }
            }
        }
    }
    else{
        aux = "./Bancos/" + this->nomeBanco + "/Poupanca " + this->nomeBanco + ".txt";
        this->contas = a.preencheVectorConta(aux);
        for(auto x : this->contas){
            for(auto y : this->clientes){
                if(this->contas[count].getCliente().getCPF_CNPJ() == y.getCPF_CNPJ()) {
                    this->contas[count].setCliente(y);
                }
            }
        }
    }

}

void Banco::salvar(){

    FileIO a;
    string aux = "./Bancos/" + this->nomeBanco + "/Contas " + this->nomeBanco + ".txt";

    a.salvarListaContas(aux,this->contaCorrente);
    aux = "./Bancos/" + this->nomeBanco + "/Clientes " + this->nomeBanco + ".txt";
    a.salvarListaClientes(aux,this->clientes);
}

Banco::~Banco()
{
}

