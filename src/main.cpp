#include <iostream>
#include "../Model/Banco.h"

int main() {
    Cliente cliente("Arthur Cascardo","02198587645","Rua Junquilihos","997755250");
    Conta conta(cliente);
    Banco banco("Inter");
    Data data(19,11,2019);

    conta.creditarConta(100,"Teste");
    conta.debitarConta(50,"Debitar Teste");
    std::cout << conta.getSaldo();
    for(auto x : conta.obterExtratoMes()){
        int i = 0;
    }
}