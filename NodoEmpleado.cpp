#include "NodoEmpleado.h"

NodoEmpleado::NodoEmpleado(Empleado* dato) {
	this->dato = dato;
	this->siguiente = nullptr;
}

NodoEmpleado::NodoEmpleado(Empleado* dato, NodoEmpleado* siguiente) {
	this->dato = dato;
	this->siguiente = siguiente;
}

NodoEmpleado::~NodoEmpleado() {
	// La liberación del puntero a Empleado o del siguiente nodo 
	// se administra explícitamente desde la clase ListaEmpleado.
}

Empleado* NodoEmpleado::getDato() const {
	return dato;
}

NodoEmpleado* NodoEmpleado::getSiguiente() const {
	return siguiente;
}

void NodoEmpleado::setDato(Empleado* dato) {
	this->dato = dato;
}

void NodoEmpleado::setSiguiente(NodoEmpleado* siguiente) {
	this->siguiente = siguiente;
}
