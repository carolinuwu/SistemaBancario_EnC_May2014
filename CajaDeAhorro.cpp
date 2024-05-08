//
// Created by carolina on 5/5/2024.
//
#include "CajaDeAhorro.h"
CajaDeAhorro::CajaDeAhorro(double saldo, Cliente titular, Banco &banco) : Cuenta(saldo,titular,banco) {

}
double CajaDeAhorro::montoAaAbonar() {
    //podria retornar un valor constante
    return 0.5;
}
std::string CajaDeAhorro::mostrarNombreInstancia() {
    return " - Caja de Ahorro - ";
}
