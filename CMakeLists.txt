cmake_minimum_required(VERSION 3.15)
project(TP3)

set(CMAKE_CXX_STANDARD 11)

add_executable(TP3 src/main.cpp Model/Banco.cpp Model/Banco.h Model/Cliente.cpp Model/Cliente.h Model/Conta.cpp Model/Conta.h Model/Move.cpp Model/Move.h Model/Data.cpp Model/Data.h Model/Interface.h Model/Interface.cpp Controller/CheckData.cpp Controller/CheckData.h Controller/FileIO.cpp Controller/FileIO.h Model/ContaCorrente.cpp Model/ContaCorrente.h Model/Poupanca.cpp Model/Poupanca.h Model/SaldoDiaBase.cpp Model/SaldoDiaBase.h)