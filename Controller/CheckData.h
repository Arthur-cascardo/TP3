//
// Created by Arthur on 20/11/2019.
//

#ifndef TP3_CHECKDATA_H
#define TP3_CHECKDATA_H

#include<iostream>

class CheckData {
    public:

        bool verficaCPF_CNPJ(std::string cpf_cnpj);
        bool verificaNome(std::string nome);
        bool verificaEndereco(std::string endereco);
        bool verificaFone(std::string fone);
        bool isNumeric(std::string s);

};


#endif //TP3_CHECKDATA_H
