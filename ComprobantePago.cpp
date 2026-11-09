#include "ComprobantePago.h"

ComprobantePago::ComprobantePago(int id, string fecha, Empleado* empleado,
	Departamento* departamento, double salarioBruto,
	double deducciones, double salarioNeto) {
    this->id = id;
    this->fecha = fecha;
    this->empleado = empleado;
    this->departamento = departamento;
    this->salarioBruto = salarioBruto;
    this->deducciones = deducciones;
    this->salarioNeto = salarioNeto;
}

ComprobantePago::~ComprobantePago() {
    // No se hace delete de empleado ni departamento: son agregados.
}

int ComprobantePago::getId() const { return id; }
string ComprobantePago::getFecha() const { return fecha; }
Empleado* ComprobantePago::getEmpleado() const { return empleado; }
Departamento* ComprobantePago::getDepartamento() const { return departamento; }
double ComprobantePago::getSalarioBruto() const { return salarioBruto; }
double ComprobantePago::getDeducciones() const { return deducciones; }
double ComprobantePago::getSalarioNeto() const { return salarioNeto; }

void ComprobantePago::setFecha(string fecha) { this->fecha = fecha; }
void ComprobantePago::setEmpleado(Empleado* empleado) { this->empleado = empleado; }
void ComprobantePago::setDepartamento(Departamento* departamento) { this->departamento = departamento; }

void ComprobantePago::setMontos(double salarioBruto, double deducciones, double salarioNeto) {
    this->salarioBruto = salarioBruto;
    this->deducciones = deducciones;
    this->salarioNeto = salarioNeto;
}
