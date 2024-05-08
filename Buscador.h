//
// Created by carolina on 5/5/2024.
//
#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <vector>
#include <algorithm>

template<class T>
class Buscador {
public:
    bool buscarElemento(const std::vector<T> &elementos, const T& elementoBuscado) const {
        //recordar q 1-> true, 0 -> false.
        auto elementoBscado = std::find(elementos.begin(), elementos.end(), elementoBuscado);
        bool loTengo = (elementoBscado!=elementos.end());
        return loTengo;
    }
    bool buscarElemento(const std::vector<T*> &elementos, const T* elementoBuscado) const {
        auto elementoEncontrado = std::find(elementos.begin(), elementos.end(), elementoBuscado);
        return (elementoEncontrado != elementos.end());
    }


};


#endif //BUSCADOR_H
