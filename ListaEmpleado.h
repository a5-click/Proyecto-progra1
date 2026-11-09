#ifndef LISTAEMPLEADO_H
#define LISTAEMPLEADO_H
#include "NodoEmpleado.h"
#include "Empleado.h"

class ListaEmpleado {
private:
	NodoEmpleado* primero;
	int cantidad;
	
public:
	ListaEmpleado();
	~ListaEmpleado();
	
	bool estaVacia() const;
	int getCantidad() const;
	
	void insertarInicio(Empleado* empleado);
	void insertarFinal(Empleado* empleado);
	
	Empleado* buscarPorId(int id) const;
	bool eliminarPorId(int id);
	Empleado* obtenerEnPosicion(int indice) const;
	
	NodoEmpleado* getPrimero() const;
	void vaciar();
};
#endif
