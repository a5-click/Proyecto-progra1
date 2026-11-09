#include "Enfermero.h"

//constructor
Enfermero::Enfermero(int id, string nombre, string identificacion, double salarioBase,
					 int horasExtras, int turnosNocturnos, string turno,
					 int cantidadGuardias) : Empleado (id, nombre, identificacion,
					 salarioBase, horasExtras, turnosNocturnos) {

	this->turno= turno;
	this->cantidadGuardias = cantidadGuardias;
}

//destructor
Enfermero::~Enfermero(){
	
}

//setters
void Enfermero::setTurno(string turno) {
	this->turno = turno;
}
void Enfermero::setCantidadGuardias(int cantidadGuardias) {
	if(cantidadGuardias >= 0){
		this->cantidadGuardias = cantidadGuardias;
		
	}
}

//getters
string Enfermero::getTurno() const {
	return turno;
}

int Enfermero::getCantidadGuardias() const {
	return cantidadGuardias;
}

//metodos
double Enfermero::calcularBonificacionEspecifica() const {
	return cantidadGuardias * 20000.0;
}

string Enfermero::obtenerTipoEmpleado() const {
	return "Enfermero";
}
