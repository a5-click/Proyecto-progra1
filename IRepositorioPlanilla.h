#ifndef IREPOSITORIOPLANILLA_H
#define IREPOSITORIOPLANILLA_H

class ListaEmpleado;
class ListaDepartamento;
class ListaComprobante;

// Abstraccion: la logica depende de esta interfaz, no de archivos concretos.
class IRepositorioPlanilla {
public:
    virtual ~IRepositorioPlanilla() {}

    virtual bool cargarEmpleados(ListaEmpleado& empleados) = 0;
    virtual bool cargarDepartamentos(ListaDepartamento& departamentos) = 0;
    virtual bool cargarPlanilla(ListaComprobante& planilla,
	const ListaEmpleado& empleados,
	const ListaDepartamento& departamentos) = 0;

    virtual bool guardarEmpleados(const ListaEmpleado& empleados) = 0;
    virtual bool guardarDepartamentos(const ListaDepartamento& departamentos) = 0;
    virtual bool guardarPlanilla(const ListaComprobante& planilla) = 0;
};

#endif
