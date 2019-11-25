#include <iostream>
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

}