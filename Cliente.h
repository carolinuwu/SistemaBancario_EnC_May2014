//
// Created by carolina on 5/5/2024.
//

#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <array>

struct Direccion {
    std::string calle;
    int altura;
    int piso;
    std::string depto;
    std::string ciudad;
};

class Cliente {
public:
    explicit Cliente(std::string nombre, std::string apellido, const Direccion& dire, int edad, int dni);
 Cliente();
    void guardarNape(std::array<std::string, 2> nape);

    int mostrarDni() const;
    std::string mostrarme() const;
    bool operator==(const Cliente& otro) const;
private:
    std::string m_nombre;
    std::string m_apellido;
    Direccion m_dire;
    int m_edad;
    int m_dni;

};



#endif //CLIENTE_H
