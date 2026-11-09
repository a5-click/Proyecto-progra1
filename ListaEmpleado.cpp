#include "ListaEmpleado.h"

ListaEmpleado::ListaEmpleado() {
	this->primero = nullptr;
	this->cantidad = 0;
}

ListaEmpleado::~ListaEmpleado() {
	vaciar();
}

bool ListaEmpleado::estaVacia() const {
	return primero == nullptr;
}

int ListaEmpleado::getCantidad() const {
	return cantidad;
}

void ListaEmpleado::insertarInicio(Empleado* empleado) {
	NodoEmpleado* nuevo = new NodoEmpleado(empleado, primero);
	primero = nuevo;
	cantidad++;
}

void ListaEmpleado::insertarFinal(Empleado* empleado) {
	NodoEmpleado* nuevo = new NodoEmpleado(empleado);
	if (estaVacia()) {
		primero = nuevo;
	} else {
		NodoEmpleado* aux = primero;
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
	}
	cantidad++;
}

Empleado* ListaEmpleado::buscarPorId(int id) const {
	NodoEmpleado* aux = primero;
	while (aux != nullptr) {
		if (aux->getDato() != nullptr && aux->getDato()->getId() == id) {
			return aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return nullptr;
}

bool ListaEmpleado::eliminarPorId(int id) {
	if (estaVacia()) {
		return false;
	}
	
	NodoEmpleado* borrado = nullptr;
	
	if (primero->getDato() != nullptr && primero->getDato()->getId() == id) {
		borrado = primero;
		primero = primero->getSiguiente();
	} else {
		NodoEmpleado* aux = primero;
		while (aux->getSiguiente() != nullptr && 
			   aux->getSiguiente()->getDato()->getId() != id) {
			aux = aux->getSiguiente();
		}
		
		if (aux->getSiguiente() == nullptr) {
			return false; // No se encontró el ID
		}
		
		borrado = aux->getSiguiente();
		aux->setSiguiente(borrado->getSiguiente());
	}
	
	// Se libera el objeto Empleado en memoria dinámica y luego el nodo
	delete borrado->getDato();
	delete borrado;
	cantidad--;
	return true;
}

Empleado* ListaEmpleado::obtenerEnPosicion(int indice) const {
	if (indice < 0 || indice >= cantidad) {
		return nullptr;
	}
	
	NodoEmpleado* aux = primero;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}

NodoEmpleado* ListaEmpleado::getPrimero() const {
	return primero;
}

void ListaEmpleado::vaciar() {
	NodoEmpleado* aux = primero;
	while (aux != nullptr) {
		NodoEmpleado* siguiente = aux->getSiguiente();
		if (aux->getDato() != nullptr) {
			delete aux->getDato(); // Liberación explícita del objeto dinámico
		}
		delete aux; // Liberación del nodo
		aux = siguiente;
	}
	primero = nullptr;
	cantidad = 0;
}
