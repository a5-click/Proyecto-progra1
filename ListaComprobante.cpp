#include "ListaComprobante.h"

ListaComprobante::ListaComprobante() {
	this->primero = nullptr;
	this->cantidad = 0;
}

ListaComprobante::~ListaComprobante() {
	vaciar();
}

bool ListaComprobante::estaVacia() const {
	return primero == nullptr;
}

int ListaComprobante::getCantidad() const {
	return cantidad;
}

void ListaComprobante::insertarFinal(ComprobantePago* comprobante) {
	NodoComprobante* nuevo = new NodoComprobante(comprobante);
	if (estaVacia()) {
		primero = nuevo;
	} else {
		NodoComprobante* aux = primero;
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
	}
	cantidad++;
}

ComprobantePago* ListaComprobante::obtenerEnPosicion(int indice) const {
	if (indice < 0 || indice >= cantidad) {
		return nullptr;
	}
	
	NodoComprobante* aux = primero;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}

NodoComprobante* ListaComprobante::getPrimero() const {
	return primero;
}

void ListaComprobante::vaciar() {
	NodoComprobante* aux = primero;
	while (aux != nullptr) {
		NodoComprobante* siguiente = aux->getSiguiente();
		if (aux->getDato() != nullptr) {
			delete aux->getDato();
		}
		delete aux;
		aux = siguiente;
	}
	primero = nullptr;
	cantidad = 0;
}
