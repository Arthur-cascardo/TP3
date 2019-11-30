//
// Created by Arthur on 20/11/2019.
//

#include "Cliente.h"

Cliente::Cliente(){

    this->nomeCliente = "";
    this->cpf_cnpj = "";
    this->endereco = "";
    this->fone = "";

}

Cliente::Cliente(string newnome, string newcpf, string newendereco, string newfone) //construtor
{
    nomeCliente = newnome;
    cpf_cnpj = newcpf;
    endereco = newendereco;
    fone = newfone;
}

Cliente::Cliente(const Cliente& novocliente) //construtor de copia
{
    nomeCliente = novocliente.nomeCliente;
    cpf_cnpj = novocliente.cpf_cnpj;
    endereco = novocliente.endereco;
    fone = novocliente.fone;
}

Cliente::~Cliente() //destrutor
{

}

void Cliente::setNome(string novonome)
{
    nomeCliente = novonome;
}

void Cliente::setCPF_CNPJ(string novocpf)
{
    bool v = false;
    for(int c=0; c<novocpf.length(); c++){
        if (!isdigit(novocpf[c])){
            v = true;
            break;
        }
    }
    if(novocpf.length() != 11 || v){
        throw string("Formato inválido, digite apenas 11 digitos");
    } else {
        cpf_cnpj = novocpf;
    }

}

void Cliente::setEndereco(string novoendereco)
{
    endereco = novoendereco;
}

void Cliente::setFone(string novofone)
{
    bool v = false;
    for(int c=0; c<novofone.length(); c++){
        if (!isdigit(novofone[c])){
            v = true;
            break;
        }
    }
    if((novofone.length() != 8 || novofone.length() != 9)|| v){
        throw string("Formato inválido, digite apenas 8 digitos");
    } else {
        fone = novofone;
    }
}
string Cliente::getNome()
{
    return nomeCliente;
}

string Cliente::getCPF_CNPJ()
{
    return cpf_cnpj;
}

string Cliente::getEndereco()
{
    return endereco;
}

string Cliente::getFone()
{
    return fone;
}
