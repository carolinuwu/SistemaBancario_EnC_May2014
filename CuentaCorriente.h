//
// Created by ahreq on 5/7/2024.
//

#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Cuenta.h"
#include "Cliente.h"
#include "Banco.h"
#include<string>


class CuentaCorriente : public Cuenta {
public:
    explicit CuentaCorriente( double saldo, Cliente titular, Banco& banco);
    double montoAaAbonar() override;
    std::string mostrarNombreInstancia() override;
    void cambiarAesDeudor();
    void aumentarIntereses(double cantNuevaIntereses);

private:
    bool m_esDeudor;
    bool m_pagaIntereses;
   double m_cantIntereses;
int limiteDeTransacciones; //mayor al de caja


};



#endif //CUENTACORRIENTE_H
