cmake_minimum_required(VERSION 3.28)
project(SistemaBancarioC__)

set(CMAKE_CXX_STANDARD 17)

add_executable(SistemaBancarioC__ main.cpp
        Banco.cpp
        Banco.h
        Cliente.cpp
        Cliente.h
        Cuenta.cpp
        Cuenta.h
        Buscador.cpp
        Buscador.h
        CuentaCorriente.cpp
        CuentaCorriente.h
        Transaccion.cpp
        Transaccion.h
)
