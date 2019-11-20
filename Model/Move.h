//
// Created by Arthur on 20/11/2019.
//

#ifndef TP3_MOVE_H
#define TP3_MOVE_H

#include <iostream>
#include <math.h>
#include "../Model/Data.h"

using namespace std;

class Move {
    private:
        Data dataMov;
        string descricao;
        char debitoCredito;
        double valor;
    public:
        Move(Data data, string desc, char debC, double val);	//construtor
        Move(const Move& m);									//construtor de copia
        ~Move();												//destrutor
        Data getData();
        string getDesc();
        char getDC();
        double getValor();
};


#endif //TP3_MOVE_H
