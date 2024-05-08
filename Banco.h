//
// Created by carolina on 5/5/2024.
//
#ifndef BANCO_H
#define BANCO_H

class Cuenta;

   #include "Cliente.h"
#include <map>
#include <vector>
#include "Buscador.h"
class Transaccion;
#include <queue>

class Banco {
public:
    explicit Banco(const std::string &nombre);
    Banco();
    void agregarClienteYCuentaAlMapa(Cliente &cli,Cuenta &cuenta);
    bool eliminarCuenta(Cuenta &cuenta);
    [[nodiscard]] std::string getNombre() const;
    Cuenta* obtenerCuentaPorCliente(Cliente &cliente);
    std::vector<Cliente> obtenerClientes();
    std::vector<Cuenta*> obtenerCuentas();
    bool realizarTransferencia(Cuenta &origen, Cuenta &destino, double monto);
    bool realizarRetiro(Cuenta &origen, double monto);
    double informarDineroTotal();
    void mostrarTodasLasTransferencias();
    ~Banco();


private:
    std::map<Cliente*, Cuenta*> m_clientesYcuentas;
    std::queue<Transaccion> m_transaccionesRealizadas;
    std::string m_nombre;
    Buscador<Cliente> m_buscadorClientes;
    Buscador<Cuenta> m_buscadorCuentas;


    void inicializarMapa();
    void inicializarCola();
    bool buscarCliente(Cliente cli);
    bool buscarCuenta(Cuenta *c);
    void generarTransferencia(Cuenta *origen, Cuenta *destino, double monto);


};




#endif //BANCO_H
