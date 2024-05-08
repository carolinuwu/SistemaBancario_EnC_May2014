//
// Created by ahreq on 5/8/2024.
//

#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H

#include "Cuenta.h"
#include "Cliente.h"
#include "Banco.h"
#include<string>


class CajaDeAhorro : public Cuenta {

public:
    explicit CajaDeAhorro(double saldo, Cliente titular, Banco& banco);
    double montoAaAbonar() override;
    std::string mostrarNombreInstancia() override;



};



#endif //CAJADEAHORRO_H
