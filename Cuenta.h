//
// Created by ahreq on 5/5/2024.
//

#ifndef CUENTA_H
#define CUENTA_H

#include "Cliente.h"
#include "Banco.h"
#include<string>

class Cuenta {
public:
    explicit Cuenta( double saldo, Cliente titular, Banco& banco);

    bool aumentarSaldo(double nuevoSaldo);
    bool decrementarSaldo(double cantidad);
     [[nodiscard]] double consultarSaldo() const;
    [[nodiscard]] std::string mostrarDatosCuenta() const;
    bool operator==(const Cuenta& otraCuenta) const;
    double virtual  montoAaAbonar()= 0;
    ~Cuenta();



private:
    int m_nroCuenta;
    double m_saldo;
    Cliente m_titular;
    Banco& m_banco;
    //agrego esto para q al instanciarse una cuenta su nro sea equivalente al numero de instancia en q este manejando el programa
    static int contadorInstancias;
};



#endif //CUENTA_H
