#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H
#include "Empleado.h"
class NodoEmpleado {
private:
	Empleado* dato;
	NodoEmpleado* siguiente;
	
public:
	NodoEmpleado(Empleado* dato);
	NodoEmpleado(Empleado* dato, NodoEmpleado* siguiente);
	~NodoEmpleado();
	
	Empleado* getDato() const;
	NodoEmpleado* getSiguiente() const;
	
	void setDato(Empleado* dato);
	void setSiguiente(NodoEmpleado* siguiente);
};
#endif
