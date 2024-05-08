#include <iostream>
#include "Cuenta.h";
#include "Banco.h";
#include "Cliente.h";
#include<vector>;

#include "CajaDeAhorro.h"
#include "CuentaCorriente.h"


void pruebas();



void pruebas() {
/*
 * Intento instanciar algunos objetos, varios podian lanzar excepciones por recibir como argumentos valores incorrectos
 */
try {
    Direccion d;
    Cliente titular("Carolina", "xd", d, 27, 12345678);
    Banco banco("Cooperativo");

    CuentaCorriente cuenta( 1240, titular, banco);
    //hice a Cuenta una clase abstracta ya que queria que hubiese dos tipos de cuenta, la cuenta corriente y la caja de ahorro
    //para esto defini una funcion virtual pura en Cuenta que fue calcularMonto()-> retorna un double

//muestro los datos de cuenta
    std::cout<<cuenta.mostrarDatosCuenta();
//intento agregar a la cuenta y su cliente asociados al mapa que posee bancos de cuentas por cliente
    banco.agregarClienteYCuentaAlMapa(titular,cuenta);
    Cliente titular2("Ruben ", "xd", d, 29, 111111);
  CajaDeAhorro cuenta2(1, titular2, banco);
    //intento agregarle otra cuenta a alguien q ya posee una
    std::cout<<"\n";
    banco.agregarClienteYCuentaAlMapa(titular,cuenta2);
    std::cout<<"\n";
    banco.agregarClienteYCuentaAlMapa(titular2,cuenta2);
    std::vector<Cuenta*> cuentas = banco.obtenerCuentas();
    std::cout<<"\n";
//muestro los datos de las cuentas que poseo
    auto mostrarCuentas = [cuentas]()->void {
        for (auto cuenta: cuentas) {
            std::cout<<cuenta->mostrarDatosCuenta();
        }
    };
    std::cout<<"-------------------MOSTRANDO CUENTAS---------------------------------";
    std::cout<<"\n";
    mostrarCuentas();
    std::cout<<"------------------------------------------------------------------------------";


    banco.realizarTransferencia(cuenta,cuenta2,120);
    //muestro las transacciones, las mismas se componen de una cuenta de origen y uan cuenta destino y se
    //almacenaron en una cola fifo en Banco
    //tendria q agregar otro metodo para reencolarlas
    std::cout<<"------------------------------------------------------------------------------";
    std::cout<<"-------------------MOSTRANDO TRANSACCIONES---------------------------------";
    std::cout<<"\n";
    banco.mostrarTodasLasTransferencias();



} catch (const std::invalid_argument& e) {
    std::cout<<"ERROR" <<e.what();
}




}


int main()
{
 pruebas();
    return 0;
}
