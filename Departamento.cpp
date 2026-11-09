#include "Departamento.h"

Departamento::Departamento(int id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

Departamento::~Departamento() {
    // ListaPuesto libera los Puestos: se cumple la composicion.
}

int Departamento::getId() const { return id; }
string Departamento::getNombre() const { return nombre; }
void Departamento::setNombre(string nombre) { this->nombre = nombre; }

void Departamento::agregarPuesto(Puesto* puesto) {
    if (puesto != nullptr) {
        puestos.insertarFinal(puesto);
    }
}

Puesto* Departamento::obtenerPuesto(int indice) const {
    return puestos.obtenerEnPosicion(indice);
}

int Departamento::getCantidadPuestos() const {
    return puestos.getCantidad();
}

ListaPuesto* Departamento::getListaPuestos() { return &puestos; }
const ListaPuesto* Departamento::getListaPuestos() const { return &puestos; }
