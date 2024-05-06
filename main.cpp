#include <iostream>
#include "Cuenta.h";
#include "Banco.h";
#include "Cliente.h";
#include<vector>;


void pruebas();


void pruebas() {

    Direccion d= {"Otra", 123, 1, "A", "Caba"};
    Cliente titular("Otro", "xd", d, 30, 12345678);
    Banco banco("Cooperativo");
    Cuenta cuenta(1234, 1240, titular, banco);

    std::cout<<cuenta.mostrarDatosCuenta();

    banco.agregarClienteYCuentaAlMapa(titular,cuenta);
    Cliente titular2("Ruben ", "xd", d, 29, 111111);
    Cuenta cuenta2(1111, 1, titular2, banco);
//intento agregarle otra cuenta a alguien q ya tiene
    std::cout<<"\n";
  banco.agregarClienteYCuentaAlMapa(titular,cuenta2);
    std::cout<<"\n";
    banco.agregarClienteYCuentaAlMapa(titular2,cuenta2);
   std::vector<Cuenta> cuentas = banco.obtenerCuentas();
    std::cout<<"\n";

    auto mostrarCuentas = [&cuentas]->void {
        for (auto cuenta: cuentas) {
            std::cout<<cuenta.mostrarDatosCuenta();
        }
    };
    std::cout<<"-------------------MOSTRANDO CUENTAS---------------------------------";
    std::cout<<"\n";
    mostrarCuentas();
    std::cout<<"------------------------------------------------------------------------------";


}


int main()
{
 pruebas();
    return 0;
}
