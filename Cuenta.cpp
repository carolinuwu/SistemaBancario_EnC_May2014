//
// Created by carolina on 5/5/2024.
//

#include "Cuenta.h"
#include<iostream>
#include<iomanip>
#include <utility>

int Cuenta::contadorInstancias = 0;
Cuenta::Cuenta( double saldo, Cliente titular, Banco& banco): m_nroCuenta(++contadorInstancias), m_saldo(saldo),m_titular(std::move(titular)), m_banco(banco) {
    if (saldo<0) {
        throw std::invalid_argument("El saldo inicial no puede ser inferior o igual a 0 ");
        //las instancias de Cuenta Corriente permitiran posteriormente tener un saldo negativo, pero en principio no se podria instanciar una derivada de Cuenta
        //si el saldo fuere negativo
    }


}

bool Cuenta::aumentarSaldo(double nuevoSaldo) {

    if (nuevoSaldo<0) {
        throw std::invalid_argument("El saldo a computar no puede ser inferior a 0 ");
    }
    m_saldo +=nuevoSaldo;

    return true;

}
bool Cuenta::decrementarSaldo(double cantidad) {

    if (cantidad<0) {
        throw std::invalid_argument("El saldo a computar no puede ser inferior a 0 ");
    }
    m_saldo -=cantidad;
    return true;
}


double Cuenta::consultarSaldo() const {
    return m_saldo;
}
std::string Cuenta::mostrarDatosCuenta()   {
    //Me gustaria poder agregar algo analogo a lo de reflection de la api de Java q me permite hacer this.getClass().getSimpleName()
    //para q en tiempo de ejecucion se resuelva que derivada de la clase raiz Cuenta esta usando este metodo
    //utilice herencia en lugar de eso, tambien podria usar el patron visitor
        return mostrarNombreInstancia() + "Numero de cuenta: " + std::to_string(m_nroCuenta) + "\n" +
                "Saldo: " + std::to_string(m_saldo) + "\n";

}

bool Cuenta::operator==(const Cuenta &otraCuenta) const{
    return this->m_nroCuenta == otraCuenta.m_nroCuenta;
}


Cuenta::~Cuenta() {
    m_banco.eliminarCuenta(*this);

}
