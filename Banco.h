//
// Created by ahreq on 5/5/2024.
//

#ifndef BANCO_H
#define BANCO_H

class Cuenta;

#include "Cliente.h"
#include <map>
#include <vector>
#include "Buscador.h"

class Banco {
public:
    explicit Banco(std::string nombre);
    void agregarClienteYCuentaAlMapa(Cliente &cli,Cuenta &cuenta);
    bool eliminarCuenta(Cuenta &cuenta);
    std::string getNombre() const;
    Cuenta* obtenerCuentaPorCliente(Cliente &cliente);
    std::vector<Cliente> obtenerClientes();
    std::vector<Cuenta> obtenerCuentas();
    bool realizarTransferencia(Cuenta &origen, Cuenta &destino, double monto);
    bool realizarRetiro(Cuenta &origen, double monto);
    double informarDineroTotal();
    ~Banco();

private:


    std::map<Cliente*, Cuenta*> m_clientesYcuentas;
    std::string m_nombre;
    Buscador<Cliente> m_buscadorClientes;
    Buscador<Cuenta> m_buscadorCuentas;


    void inicializarMapa();
    bool buscarCliente(Cliente cli);
    bool buscarCuenta(Cuenta *c);

};




#endif //BANCO_H
