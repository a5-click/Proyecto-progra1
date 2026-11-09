#ifndef SERVICIOPERSISTENCIA_H
#define SERVICIOPERSISTENCIA_H

#include "IRepositorioPlanilla.h"

// SRP: coordina cuando cargar o guardar; no conoce el formato de los archivos.
// DIP: recibe la abstraccion por constructor (inyeccion de dependencias).
class ServicioPersistencia {
private:
    IRepositorioPlanilla& repositorio;

public:
    explicit ServicioPersistencia(IRepositorioPlanilla& repositorio);

    bool cargarTodo(ListaEmpleado& empleados,
	ListaDepartamento& departamentos,
	ListaComprobante& planilla);

    bool guardarTodo(const ListaEmpleado& empleados,
	const ListaDepartamento& departamentos,
	const ListaComprobante& planilla);
};

#endif
