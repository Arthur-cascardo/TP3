//
// Created by Bia Amorzinho on 28/11/2019.
//

#ifndef TP3_SALDODIABASE_H
#define TP3_SALDODIABASE_H


class SaldoDiaBase {

private:
    double saldoDiaBase;
public:
    double getSaldoDiaBase() const;

    void setSaldoDiaBase(double saldoDiaBase);

    int getDiaBase() const;

    void setDiaBase(int diaBase);

    SaldoDiaBase(int diaBase);

private:
    int diaBase;
public:

};


#endif //TP3_SALDODIABASE_H
