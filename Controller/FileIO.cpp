//
// Created by Arthur on 20/11/2019.
//

#include "FileIO.h"
#include "../Model/ContaCorrente.h"

vector<string> FileIO::lerListaClientes(string s){

    string aux;
    vector<string> dadosCliente, linha;
    ifstream ifile;

    ifile.open(s);
    while(!ifile.eof()){

        getline(ifile,aux);
        linha.push_back(aux);

    }

    aux.clear();

    for(auto s : linha){

        stringstream check(s);

        while(getline(check, aux, ';')){
            dadosCliente.push_back(aux);
        }
    }
    ifile.close();
    return dadosCliente;
}

vector<string> FileIO::lerListaContas(string s){

    string aux;
    vector<string> dadosConta, linha;
    ifstream ifile;

    ifile.open(s);
    while(!ifile.eof()){

        getline(ifile,aux);
        linha.push_back(aux);

    }

    aux.clear();

    for(auto s : linha){

        stringstream check(s);

        while(getline(check, aux, ';')){
            dadosConta.push_back(aux);
        }
    }
    ifile.close();
    return dadosConta;
}

vector<string> FileIO::lerListaMove(string s){

    string aux;
    vector<string> dadosMove, linha;
    ifstream ifile;

    ifile.open(s);
    while(!ifile.eof()){

        getline(ifile,aux);
        linha.push_back(aux);

    }

    aux.clear();

    for(auto s : linha){

        stringstream check(s);

        while(getline(check, aux, ';')){
            dadosMove.push_back(aux);
        }
    }
    ifile.close();
    return dadosMove;
}


vector<Cliente> FileIO::preencheVectorCliente(string s){

    vector<string> aux;
    int i;

    aux = this->lerListaClientes(s);
    for(i = 0; i < aux.size()/4; i++){

        Cliente aux_cliente(aux[i*4],aux[i*4 + 1],aux[i*4 + 2],aux[i*4 + 3]);
        this->clientes.push_back(aux_cliente);
    }

    return this->clientes;
}
//TODO: IMPLEMENTAR METODOS CORRETAMENTE PARA OS DOIS TIPOS DE CONTA
vector<Conta> FileIO::preencheVectorPoupanca(string s){

    vector<string> aux;
    int i;

    aux = this->lerListaContas(s);
    for(i = 0; i < aux.size()/3; i++){

        Conta aux_conta(stoi(aux[i*3]), stod(aux[i*3 + 1]), aux[i*3 + 2]);
        this->contas.push_back(aux_conta);
    }
    return this->contas;
}

vector<Conta> FileIO::preencheVectorCorrente(string s){

    vector<string> aux;
    int i;

    aux = this->lerListaContas(s);
    for(i = 0; i < aux.size()/3; i++){

        ContaCorrente aux_conta(stoi(aux[i*3]), stod(aux[i*3 + 1]), aux[i*3 + 2],45.9);


        //this->contas.push_back(aux_conta);
    }
    return this->contas;
}

vector<Move> FileIO::preencheVectorMove(string s){

    vector<string> aux;
    Data aux_data;
    int i;

    aux = this->lerListaMove(s);
    for(i = 0; i < aux.size()/4; i++){
        aux_data.lerData(aux[i*4]);
        Move aux_move(aux_data, aux[i*4 + 1], aux[i*4 + 2][0], stod(aux[i*4 + 3]));
        this->move.push_back(aux_move);
    }
    return this->move;
}


void FileIO::salvarListaClientes(string s, vector<Cliente> c){

    ofstream ofile;

    ofile.open(s, ofstream::out | ofstream::trunc);
    for(auto x : c){

        ofile << x.getNome()
              << ";" << x.getCPF_CNPJ()
              << ";" << x.getEndereco()
              << ";" << x.getFone() << endl;
    }
}

void FileIO::salvarListaContas(string s, vector<ContaCorrente> c){

    ofstream ofile;

    ofile.open(s, ofstream::out | ofstream::trunc);
    for(auto x : c){

        ofile << x.getNumConta()
              << ";" << x.getSaldo()
              << ";" << x.getCliente().getCPF_CNPJ() << endl;
    }
}

void FileIO::salvarListaMove(string s, vector<Move> m){

    ofstream ofile;
    ofile.open(s);
    for(auto x : m){

        ofile << x.getData().getDia()
              << "/" << x.getData().getMes()
              << "/" << x.getData().getAno()
              << ";" << x.getDesc()
              << ";" << x.getDC()
              << ";" << x.getValor() << endl;
    }
}


vector<Cliente> FileIO::getClientes(){

    return this->clientes;

}

vector<ContaCorrente> FileIO::getConta(){

    return this->contas;

}

void FileIO::criarArquivo(string s){

    ofstream o;
    o.open(s);
    o.close();
}


