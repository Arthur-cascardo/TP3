#include <iostream>
<<<<<<< HEAD
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
=======
#include "../Model/Cliente.h"
#include "../Model/Conta.h"
#include "../Model/Banco.h"
#include "../Model/Interface.h"

int main() {
    setlocale( LC_ALL, "Portuguese" );
    Conta c;
    Banco b("Inter");
    Interface i;

    i.menu(b);

>>>>>>> remotes/origin/Bia
}