//
// Created by Arthur on 20/11/2019.
//

#ifndef TP3_CLIENTE_H
#define TP3_CLIENTE_H

#include <iostream>
#include <cmath>

using namespace std;

class Cliente {
    private:
        string nomeCliente;
        string cpf_cnpj;
        string endereco;
        string fone;
    public:
        Cliente();
        Cliente(string newnome, string newcpf, string newendereco, string newfone); //construtor
        Cliente(const Cliente& novocliente);										//construtor de copia
        ~Cliente();																	//destrutor
        void setNome(string novonome);
        void setCPF_CNPJ(string novocpf);
        void setEndereco(string novoendereco);
        void setFone(string novofone);
        string getNome();
        string getCPF_CNPJ();
        string getEndereco();
        string getFone();
};


#endif //TP3_CLIENTE_H
