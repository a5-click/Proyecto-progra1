#include "ListaPuesto.h"

ListaPuesto::ListaPuesto() {
	this->primero = nullptr;
	this->cantidad = 0;
}

ListaPuesto::~ListaPuesto() {
	vaciar();
}

bool ListaPuesto::estaVacia() const {
	return primero == nullptr;
}

int ListaPuesto::getCantidad() const {
	return cantidad;
}

void ListaPuesto::insertarFinal(Puesto* puesto) {
	NodoPuesto* nuevo = new NodoPuesto(puesto);
	if (estaVacia()) {
		primero = nuevo;
	} else {
		NodoPuesto* aux = primero;
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
	}
	cantidad++;
}

Puesto* ListaPuesto::obtenerEnPosicion(int indice) const {
	if (indice < 0 || indice >= cantidad) {
		return nullptr;
	}
	
	NodoPuesto* aux = primero;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}

NodoPuesto* ListaPuesto::getPrimero() const {
	return primero;
}

void ListaPuesto::vaciar() {
	NodoPuesto* aux = primero;
	while (aux != nullptr) {
		NodoPuesto* siguiente = aux->getSiguiente();
		if (aux->getDato() != nullptr) {
			delete aux->getDato(); // Liberación por composición de Puesto
		}
		delete aux;
		aux = siguiente;
	}
	primero = nullptr;
	cantidad = 0;
}
