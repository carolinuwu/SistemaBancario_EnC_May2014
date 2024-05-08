//
// Created by ahreq on 5/8/2024.
//

#ifndef TRANSACCION_H
#define TRANSACCION_H

class Banco;
#include "Cuenta.h"

class Transaccion {
public:
    explicit Transaccion(Cuenta& origen, Cuenta& destino, Banco* banco, double montoTransferencia);
void mostrarme();
private:
    Cuenta* m_cuentaOrigen;
    Cuenta* m_cuentaDestino;
    Banco* banco;
    double m_monto;
};



#endif //TRANSACCION_H
