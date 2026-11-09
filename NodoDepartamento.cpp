#include "NodoDepartamento.h"

NodoDepartamento::NodoDepartamento(Departamento* dato) {
	this->dato = dato;
	this->siguiente = nullptr;
}

NodoDepartamento::NodoDepartamento(Departamento* dato, NodoDepartamento* siguiente) {
	this->dato = dato;
	this->siguiente = siguiente;
}

NodoDepartamento::~NodoDepartamento() {
}

Departamento* NodoDepartamento::getDato() const {
	return dato;
}

NodoDepartamento* NodoDepartamento::getSiguiente() const {
	return siguiente;
}

void NodoDepartamento::setDato(Departamento* dato) {
	this->dato = dato;
}

void NodoDepartamento::setSiguiente(NodoDepartamento* siguiente) {
	this->siguiente = siguiente;
}
