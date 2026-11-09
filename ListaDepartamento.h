#ifndef LISTADEPARTAMENTO_H
#define LISTADEPARTAMENTO_H
#include "NodoDepartamento.h"
#include "Departamento.h"

class ListaDepartamento {
private:
	NodoDepartamento* primero;
	int cantidad;
	
public:
	ListaDepartamento();
	~ListaDepartamento();
	
	bool estaVacia() const;
	int getCantidad() const;
	
	void insertarFinal(Departamento* departamento);
	Departamento* obtenerEnPosicion(int indice) const;
	NodoDepartamento* getPrimero() const;
	void vaciar();
};
#endif
