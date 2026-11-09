#include "Administrativo.h"

//constructor
Administrativo::Administrativo(int id, string nombre, string identificacion,
							   double salarioBase, int horasExtras, int turnosNocturnos,
							   string cargo) : Empleado (id, nombre, identificacion,
									salarioBase, horasExtras, turnosNocturnos) {
	this->cargo = cargo;
}

//destructor
Administrativo::~Administrativo() {
}

//setters
void Administrativo::setCargo(string cargo){
	this->cargo = cargo;
}

//getters
string Administrativo::getCargo() const {
	return cargo;
}

//metodos
double Administrativo::calcularBonificacionEspecifica () const {
	return 0.0;
}

string Administrativo::obtenerTipoEmpleado() const {
	return "Administrativo";
}
