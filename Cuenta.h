//
// Created by carolina on 5/5/2024.
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
    [[nodiscard]] std::string mostrarDatosCuenta() ;
    bool operator==(const Cuenta& otraCuenta) const;
    //como no encontre algo equivalente al this.getClass().getSimpleName()
    std::string virtual mostrarNombreInstancia()=0;
    double virtual  montoAaAbonar()= 0;
    //En el caso de la cuenta corriente p.ej podria ser un producto entre los intereses devengados
    //* un monto que se solicito al banco
    // en el caso de caja de ahorro podria ser un monto fijo

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
