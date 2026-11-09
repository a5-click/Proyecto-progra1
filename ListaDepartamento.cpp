#include "ListaDepartamento.h"

ListaDepartamento::ListaDepartamento() {
	this->primero = nullptr;
	this->cantidad = 0;
}

ListaDepartamento::~ListaDepartamento() {
	vaciar();
}

bool ListaDepartamento::estaVacia() const {
	return primero == nullptr;
}

int ListaDepartamento::getCantidad() const {
	return cantidad;
}

void ListaDepartamento::insertarFinal(Departamento* departamento) {
	NodoDepartamento* nuevo = new NodoDepartamento(departamento);
	if (estaVacia()) {
		primero = nuevo;
	} else {
		NodoDepartamento* aux = primero;
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
	}
	cantidad++;
}

Departamento* ListaDepartamento::obtenerEnPosicion(int indice) const {
	if (indice < 0 || indice >= cantidad) {
		return nullptr;
	}
	
	NodoDepartamento* aux = primero;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}

NodoDepartamento* ListaDepartamento::getPrimero() const {
	return primero;
}

void ListaDepartamento::vaciar() {
	NodoDepartamento* aux = primero;
	while (aux != nullptr) {
		NodoDepartamento* siguiente = aux->getSiguiente();
		if (aux->getDato() != nullptr) {
			delete aux->getDato();
		}
		delete aux;
		aux = siguiente;
	}
	primero = nullptr;
	cantidad = 0;
}
