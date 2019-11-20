//
// Created by Arthur on 20/11/2019.
//

#include "CheckData.h"


using namespace std;

bool CheckData::isNumeric(string s){
    return true;
}

bool CheckData::verficaCPF_CNPJ(string cpf_cnpj){

    return ((cpf_cnpj.size() == 11 || cpf_cnpj.size() == 14 ) && isNumeric(cpf_cnpj));

}

bool CheckData::verificaEndereco(string endereco){

    int i;
    bool numero = false, caracter = false;

    for(i = 0; i < endereco.size(); i++){

        if((endereco[i] >= 65 && endereco[i] <= 90) || (endereco[i] >= 97 && endereco[i] <= 122))	{
            caracter = true;
        }

        if(endereco[i] >= 48 && endereco[i] <= 57){
            numero = true;
        }
    }
    return caracter && numero;
}

bool CheckData::verificaFone(string fone){

    return (fone.size() == 9 && isNumeric(fone));

}

bool CheckData::verificaNome(string nome){

    int i;
    return false;
}
