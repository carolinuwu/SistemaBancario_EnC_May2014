//
// Created by ahreq on 5/5/2024.
//

#include "Cliente.h"
#include<iostream>

Cliente::Cliente(std::string nombre, std::string apellido, const Direccion &dire, int edad, int dni)
    : m_nombre(nombre), m_apellido(apellido), m_dire(dire), m_edad(edad), m_dni(dni) {
    if (edad <= 0 || dni <= 0) {
        throw std::invalid_argument("Ni la edad ni el DNI pueden ser menores o iguales a 0 ");
    }
}
void Cliente::guardarNape(std::array<std::string, 2> nape) {
    m_nombre = nape.at(0);
    m_apellido = nape.at(1);
}



int Cliente::mostrarDni() const {
    return m_dni;
}
std::string Cliente::mostrarme() const {
    return "Nombre y apellido : " + m_nombre + "  " +  m_apellido  + "\n" + " dni : "+ std::to_string(m_dni);
}

bool Cliente::operator==(const Cliente &otro) const{
    return m_dni == otro.m_dni;
}