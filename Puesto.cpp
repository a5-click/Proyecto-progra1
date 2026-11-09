#include "Puesto.h"

Puesto::Puesto(int id, string nombre, string descripcion) {
    this->id = id;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

Puesto::~Puesto() {
}

int Puesto::getId() const { return id; }
string Puesto::getNombre() const { return nombre; }
string Puesto::getDescripcion() const { return descripcion; }

void Puesto::setNombre(string nombre) { this->nombre = nombre; }
void Puesto::setDescripcion(string descripcion) { this->descripcion = descripcion; }
