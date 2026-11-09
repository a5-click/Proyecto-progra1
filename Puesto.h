#ifndef PUESTO_H
#define PUESTO_H

#include <string>
using namespace std;

// Puesto es parte de la estructura interna de un Departamento.
class Puesto {
private:
    int id;
    string nombre;
    string descripcion;

public:
    Puesto(int id, string nombre, string descripcion);
    ~Puesto();

    int getId() const;
    string getNombre() const;
    string getDescripcion() const;

    void setNombre(string nombre);
    void setDescripcion(string descripcion);
};

#endif
