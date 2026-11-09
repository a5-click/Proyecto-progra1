#ifndef LISTAPUESTO_H
#define LISTAPUESTO_H
#include "NodoPuesto.h"
#include "Puesto.h"

class ListaPuesto {
private:
	NodoPuesto* primero;
	int cantidad;
	
public:
	ListaPuesto();
	~ListaPuesto();
	
	bool estaVacia() const;
	int getCantidad() const;
	
	void insertarFinal(Puesto* puesto);
	Puesto* obtenerEnPosicion(int indice) const;
	NodoPuesto* getPrimero() const;
	void vaciar();
};
#endif
