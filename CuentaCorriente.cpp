//
// Created by ahreq on 5/7/2024.
//

#include "CuentaCorriente.h"
CuentaCorriente::CuentaCorriente( double saldo, Cliente titular, Banco &banco) : Cuenta(saldo,titular,banco) {}

 double CuentaCorriente::montoAaAbonar() {
     //por ejemplo podria hacer un producto entre lo adeudado * los intereses devengados
    return 0.1;
 }
void CuentaCorriente::cambiarAesDeudor() {
    m_esDeudor = true;
}
void CuentaCorriente::aumentarIntereses(double cantNuevaIntereses) {
    //incrementa la cantidad de intereses en lo q se recibe como argumento
    m_cantIntereses+=cantNuevaIntereses;
}
std::string CuentaCorriente::mostrarNombreInstancia() {
    return " - Cuenta Corriente - ";
}







