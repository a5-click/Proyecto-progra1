#ifndef REPOSITORIOARCHIVOSTEXTO_H
#define REPOSITORIOARCHIVOSTEXTO_H

#include <string>
#include "IRepositorioPlanilla.h"
using namespace std;

// SRP: esta clase se encarga exclusivamente de leer y escribir archivos.
class RepositorioArchivosTexto : public IRepositorioPlanilla {
private:
    string archivoEmpleados;
    string archivoDepartamentos;
    string archivoPlanilla;

public:
    RepositorioArchivosTexto(
        string archivoEmpleados = "empleados.txt",
        string archivoDepartamentos = "departamentos.txt",
        string archivoPlanilla = "planilla.txt");

    bool cargarEmpleados(ListaEmpleado& empleados) override;
    bool cargarDepartamentos(ListaDepartamento& departamentos) override;
    bool cargarPlanilla(ListaComprobante& planilla,
	const ListaEmpleado& empleados,
	const ListaDepartamento& departamentos) override;

    bool guardarEmpleados(const ListaEmpleado& empleados) override;
    bool guardarDepartamentos(const ListaDepartamento& departamentos) override;
    bool guardarPlanilla(const ListaComprobante& planilla) override;
};

#endif
