#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include "ListaPuesto.h"
using namespace std;

// Composicion: el Departamento administra y destruye sus Puestos.
class Departamento {
private:
    int id;
    string nombre;
    ListaPuesto puestos;

public:
    Departamento(int id, string nombre);
    ~Departamento();

    Departamento(const Departamento&) = delete;
    Departamento& operator=(const Departamento&) = delete;

    int getId() const;
    string getNombre() const;
    void setNombre(string nombre);

    void agregarPuesto(Puesto* puesto);
    Puesto* obtenerPuesto(int indice) const;
    int getCantidadPuestos() const;
    ListaPuesto* getListaPuestos();
    const ListaPuesto* getListaPuestos() const;
};

#endif
