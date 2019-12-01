//
// Created by Bia Amorzinho on 28/11/2019.
//

#include "SaldoDiaBase.h"

double SaldoDiaBase::getSaldoDiaBase() const {
    return saldoDiaBase;
}

void SaldoDiaBase::setSaldoDiaBase(double saldoDiaBase) {
    SaldoDiaBase::saldoDiaBase = saldoDiaBase;
}

int SaldoDiaBase::getDiaBase() const {
    return diaBase;
}

void SaldoDiaBase::setDiaBase(int diaBase) {
    SaldoDiaBase::diaBase = diaBase;
}

SaldoDiaBase::SaldoDiaBase(int diaBase) {
    this->diaBase = diaBase;
    this->saldoDiaBase = 0;
}
