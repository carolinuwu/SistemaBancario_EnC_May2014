//
// Created by ahreq on 5/5/2024.
//

#ifndef CUENTA_H
#define CUENTA_H

#include "Cliente.h"
#include "Banco.h"
#include<string>

class Cuenta {
public:
    explicit Cuenta(int cuenta, double saldo, Cliente titular, Banco& banco);

    bool aumentarSaldo(double nuevoSaldo);
    bool decrementarSaldo(double cantidad);
    double consultarSaldo() const;
    std::string mostrarDatosCuenta() const;
    bool operator==(const Cuenta& otraCuenta) const;
    ~Cuenta();



private:
    int m_nroCuenta;
    double m_saldo;
    Cliente m_titular;
    Banco& m_banco;
};



#endif //CUENTA_H
