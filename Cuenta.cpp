//
// Created by ahreq on 5/5/2024.
//

#include "Cuenta.h"
#include<iostream>
#include<iomanip>

Cuenta::Cuenta(int cuenta, double saldo, Cliente titular, Banco& banco): m_nroCuenta(cuenta), m_saldo(saldo),m_titular(titular), m_banco(banco) {
    if (saldo<0) {
        throw std::invalid_argument("El saldo no puede ser inferior o igual a 0 ");
    }
    else if (cuenta<=0) {
        throw std::invalid_argument("El nro de cuenta no puede ser inferior o igual a 0 ");
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
std::string Cuenta::mostrarDatosCuenta() const {
    return "Numero de cuenta: " + std::to_string(m_nroCuenta) + "\n" +
                "Saldo: " + std::to_string(m_saldo) + "\n";

}

bool Cuenta::operator==(const Cuenta &otraCuenta) const{
    return this->m_nroCuenta == otraCuenta.m_nroCuenta;
}


Cuenta::~Cuenta() {
    m_banco.eliminarCuenta(*this);

}
