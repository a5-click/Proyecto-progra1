#ifndef LISTACOMPROBANTE_H
#define LISTACOMPROBANTE_H
#include "NodoComprobante.h"
#include "ComprobantePago.h"

class ListaComprobante {
private:
	NodoComprobante* primero;
	int cantidad;
	
public:
	ListaComprobante();
	~ListaComprobante();
	
	bool estaVacia() const;
	int getCantidad() const;
	
	void insertarFinal(ComprobantePago* comprobante);
	ComprobantePago* obtenerEnPosicion(int indice) const;
	NodoComprobante* getPrimero() const;
	void vaciar();
};
#endif
