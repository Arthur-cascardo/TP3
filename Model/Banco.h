//
// Created by Arthur on 20/11/2019.
//

#ifndef TP3_BANCO_H
#define TP3_BANCO_H

#include <iostream>
#include <vector>
#include <list>
#include "Cliente.h"
#include "Conta.h"
#include "../Controller/FileIO.h"
#include "ContaCorrente.h"
#include "Poupanca.h"

class Banco {

private:

    string nomeBanco;
    vector<Cliente> clientes;
    vector<Conta> contas;
    vector<ContaCorrente> contaCorrente;
    vector<Poupanca> poupanca;
    vector<Move> movimentacoes;

public:

    Banco(string newBanco);
    void addCliente(Cliente newClient);
    void addConta(Cliente newConta, char tipoDeConta, double limiteCredito = 0.0);
    void removeCliente(string cpf);
    void removeConta(int numConta);
    double getSaldo(int numConta);
    void deposito(int numConta, double vdeposito);
    void saque(int numConta, double vdeposito);
    void transferencia(int contaOrigem, int contaDestino, double valorTransferencia);
    void tarifa();
    void imposto();
    vector<Move> extratomes(int numConta);
    vector<Move> extratoentredatas(int numConta, Data di, Data df);
    vector<Move> extratoapartirdata(int numConta, Data di);
    void salvar();

    //Getters

    string getnomeBanco();
    vector<Cliente> getClientList();
    vector<Conta> getContasList();
    vector<ContaCorrente> getContaCorrenteList();
    vector<Poupanca> getPoupancaList();

    //Setters

    void setClientList();
    void setContaList(char tipoDeConta);

    ~Banco();
};


#endif //TP3_BANCO_H
