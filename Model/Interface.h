//
// Created by Bia Amorzinho on 23/11/2019.
//

#ifndef TP3_INTERFACE_H
#define TP3_INTERFACE_H
#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include "../Model/Banco.h"
#include "../Model/Cliente.h"
#include "../Model/Conta.h"
#include "../Model/ContaCorrente.h"
#include "../Model/Poupanca.h"


class Interface {



    public:

        Interface();
        void menu(Banco b);
        Banco cadastraNovoCliente(Banco b);
        Banco criarNovaConta(Banco b);
        Banco excluiCliente(Banco b);
        Banco excluiConta(Banco b);
        Banco deposito(Banco b);
        Banco saque(Banco b);
        Banco transferencia(Banco b);
        void obterSaldo(Banco b);
        void cobrarTarifa();
        void cobrarCPMF();
        void obterExtrato(Banco b);
        void listarClientes(Banco b);
        void listarContas(Banco b);
        ~Interface();

    void erroValorDigitado();
};


#endif //TP3_INTERFACE_H
