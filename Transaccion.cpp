//
// Created by carolina on 5/5/2024.
//

#include "Transaccion.h"

#include<iostream>
 Transaccion::Transaccion(Cuenta &origen, Cuenta &destino, Banco* banco,double montoTransferencia) : m_cuentaOrigen(&origen), m_cuentaDestino(&destino), m_monto(montoTransferencia), banco(banco)  {


 }


void Transaccion::mostrarme() {
    std::cout<<"  monto transferencia : " << m_monto <<"   Cuenta origen :   " <<m_cuentaOrigen->mostrarDatosCuenta() << "   Cuenta destino: " << m_cuentaDestino->mostrarDatosCuenta();
}
