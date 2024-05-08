//
// Created by ahreq on 5/5/2024.
//

#include "Banco.h"
#include "Cuenta.h"



#include<iostream>

#include "Transaccion.h"


Banco::Banco(const std::string &nombre): m_nombre(nombre) {
    if (nombre.length()==0) {
        throw std::invalid_argument("EL NOMBRE DEL BANCO NO PUEDE ESTAR VACIO!");
    }
    this->inicializarMapa();
    this->inicializarCola();

}

void Banco::inicializarMapa() {
    m_clientesYcuentas = std::map<Cliente*, Cuenta*>{};
}
void Banco::inicializarCola() {
    m_transaccionesRealizadas = std::queue<Transaccion>();
}

void Banco::agregarClienteYCuentaAlMapa(Cliente &cli, Cuenta &cuenta) {
    if (bool tengoCliente = this->buscarCliente(cli)) {
        std::cout<<"Ya hay una cuenta asociada a ese cliente!";
    }
    else {
std::cout<<"Agregando al cliente y la cuenta !";
        m_clientesYcuentas.insert({&cli,&cuenta});
    }
}
bool Banco:: eliminarCuenta(Cuenta& cuenta) {
    bool pude = false;
    auto iterador = m_clientesYcuentas.find(std::map<Cliente *, Cuenta *>::key_type(&cuenta));
    if (iterador!=m_clientesYcuentas.end()) {
        std::cout<<" ELIMINANDO LA CUENTA ! ";
        m_clientesYcuentas.erase(iterador);
        pude = true;

    }
    else {

    }
    return pude;
}
std::string Banco::getNombre() const {
    return m_nombre;
}
Cuenta* Banco:: obtenerCuentaPorCliente(Cliente &cliente) {
    return &*m_clientesYcuentas.at(&cliente);

}
std::vector<Cliente>  Banco:: obtenerClientes() {
    std::vector<Cliente> clientesVector;
    for(const auto &mapa : m_clientesYcuentas) {
        clientesVector.push_back(*mapa.first); //para el vector
    }
    return clientesVector;
}
std::vector<Cuenta*> Banco::obtenerCuentas() {
    std::vector<Cuenta*> cuentasVector;
    for (const auto &mapa : m_clientesYcuentas) {
        cuentasVector.push_back(&*mapa.second);
    }

    return cuentasVector;
}

 bool Banco::buscarCliente(Cliente cli) {
     const std::vector<Cliente> clientes = this->obtenerClientes();
  return m_buscadorClientes.buscarElemento(clientes,cli);
}
bool Banco::buscarCuenta(Cuenta *c) {
    std::vector<Cuenta*> cuentas = this->obtenerCuentas();
    return m_buscadorCuentas.buscarElemento(cuentas,&*c);
}

bool Banco::realizarTransferencia(Cuenta &origen, Cuenta &destino, double monto) {
    bool sePudo = false;
    if (this->buscarCuenta(&origen) && this->buscarCuenta(&destino)==1 ) {
        origen.decrementarSaldo(monto);
        destino.aumentarSaldo(monto);
        this->generarTransferencia(&origen,&destino,monto);
        sePudo = true;
    }
    return sePudo;
}
void Banco::generarTransferencia(Cuenta *origen, Cuenta *destino, double monto) {
    m_transaccionesRealizadas.push(Transaccion(*origen,*destino,this,monto));
}



void Banco::mostrarTodasLasTransferencias() {
  while (!m_transaccionesRealizadas.empty()) {
      std::cout<< "Transaccion : ";
      std::cout<<"\n ";
      m_transaccionesRealizadas.front().mostrarme();
      std::cout<<"\n ";
      std::cout<<"------------------------------------------- ";
        m_transaccionesRealizadas.pop();
  }
}


bool Banco::realizarRetiro(Cuenta &origen,double monto) {
    bool sePudo = false;
    origen.decrementarSaldo(monto);
    sePudo = true;
    return sePudo;
}

double Banco::informarDineroTotal() {
    double montoTotal = 0;
    std::vector<Cuenta*> cuentasVector = this->obtenerCuentas();
    for (int i = 0; i < cuentasVector.size(); ++i) {
        montoTotal +=cuentasVector.at(i)->consultarSaldo();
    }
    std::cout<<"El monto total en este banco es de : "<<montoTotal;
    return montoTotal;
}
Banco::~Banco() {
    for (auto&[fst, snd] :m_clientesYcuentas) {
        delete fst;
        delete snd;

    }

}



