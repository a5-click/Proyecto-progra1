#include "NodoComprobante.h"

NodoComprobante::NodoComprobante(ComprobantePago* dato) {
	this->dato = dato;
	this->siguiente = nullptr;
}

NodoComprobante::NodoComprobante(ComprobantePago* dato, NodoComprobante* siguiente) {
	this->dato = dato;
	this->siguiente = siguiente;
}

NodoComprobante::~NodoComprobante() {
}

ComprobantePago* NodoComprobante::getDato() const {
	return dato;
}

NodoComprobante* NodoComprobante::getSiguiente() const {
	return siguiente;
}

void NodoComprobante::setDato(ComprobantePago* dato) {
	this->dato = dato;
}

void NodoComprobante::setSiguiente(NodoComprobante* siguiente) {
	this->siguiente = siguiente;
}
