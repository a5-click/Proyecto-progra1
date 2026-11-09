#include "ServicioPersistencia.h"
#include "ListaEmpleado.h"
#include "ListaDepartamento.h"
#include "ListaComprobante.h"

ServicioPersistencia::ServicioPersistencia(IRepositorioPlanilla& repositorio)
    : repositorio(repositorio) {
}

bool ServicioPersistencia::cargarTodo(
    ListaEmpleado& empleados, ListaDepartamento& departamentos,
    ListaComprobante& planilla) {
    // El orden importa: los comprobantes necesitan localizar empleado y departamento.
    bool e = repositorio.cargarEmpleados(empleados);
    bool d = repositorio.cargarDepartamentos(departamentos);
    bool p = repositorio.cargarPlanilla(planilla, empleados, departamentos);
    return e && d && p;
}

bool ServicioPersistencia::guardarTodo(
    const ListaEmpleado& empleados, const ListaDepartamento& departamentos,
    const ListaComprobante& planilla) {
    bool e = repositorio.guardarEmpleados(empleados);
    bool d = repositorio.guardarDepartamentos(departamentos);
    bool p = repositorio.guardarPlanilla(planilla);
    return e && d && p;
}
