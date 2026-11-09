#include "Medico.h"

//constructor
Medico::Medico(int id, string nombre, string identificacion,
			   double salarioBase, int horasExtras, int turnosNocturnos,
			   string especialidad, int cantidadGuardias)
	: Empleado(id, nombre, identificacion, salarioBase, horasExtras, turnosNocturnos){
	
this->especialidad = especialidad;
this->cantidadGuardias = cantidadGuardias;
}

//destructor
Medico::~Medico(){
}

//setters
void Medico::setEspecialidad(string especialidad){
	this->especialidad = especialidad;
}

void Medico::setCantidadGuardias(int cantidadGuardias){
	if(cantidadGuardias >= 0){
		this->cantidadGuardias = cantidadGuardias;
	}
}

//getters
string Medico::getEspecialidad() const {
	return especialidad;
}

int Medico::getCantidadGuardias() const {
	return cantidadGuardias;
}

//metodos
double Medico::calcularBonificacionEspecifica() const {
	return cantidadGuardias * 25000.0;
}

string Medico::obtenerTipoEmpleado() const {
	return "Medico";
}
