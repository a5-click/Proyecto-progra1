#include "NodoPuesto.h"

NodoPuesto::NodoPuesto(Puesto* dato) {
	this->dato = dato;
	this->siguiente = nullptr;
}

NodoPuesto::NodoPuesto(Puesto* dato, NodoPuesto* siguiente) {
	this->dato = dato;
	this->siguiente = siguiente;
}

NodoPuesto::~NodoPuesto() {
}

Puesto* NodoPuesto::getDato() const {
	return dato;
}

NodoPuesto* NodoPuesto::getSiguiente() const {
	return siguiente;
}

void NodoPuesto::setDato(Puesto* dato) {
	this->dato = dato;
}

void NodoPuesto::setSiguiente(NodoPuesto* siguiente) {
	this->siguiente = siguiente;
}
