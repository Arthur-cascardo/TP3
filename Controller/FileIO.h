//
// Created by Arthur on 20/11/2019.
//

#ifndef TP3_FILEIO_H
#define TP3_FILEIO_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "../Model/Cliente.h"
#include "../Model/Conta.h"
#include "../Model/Move.h"
#include "../Model/ContaCorrente.h"

using namespace std;

class FileIO{

public:

    vector<string> lerListaClientes(string s);
    vector<string> lerListaContas(string s);
    vector<string> lerListaMove(string s);
    vector<Cliente> preencheVectorCliente(string s);
    vector<Conta> preencheVectorConta(string s);
    vector<Move> preencheVectorMove(string s);
    void preencheMap();
    void salvarListaClientes(string s, vector<Cliente> c);
    void salvarListaContas(string s, vector<ContaCorrente> c);
    void salvarListaMove(string s, vector<Move> m);
    void criarArquivo(string s);
    //temp
    vector<Cliente> getClientes();
    vector<ContaCorrente> getConta();
    map<string,Conta> getMap();


private:

    vector<Cliente> clientes;
    vector<ContaCorrente> contas;
    vector<Move> move;
    map<string,ContaCorrente> listaClienteConta;
};



#endif //TP3_FILEIO_H
