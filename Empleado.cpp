#include "Empleado.h"

//constructor
Empleado::Empleado(int id, string nombre, string identificacion,
				   double salarioBase, int horasExtras, int turnosNocturnos){
	this->id = id;
	this->nombre = nombre;
	this->identificacion = identificacion;
	this->salarioBase = salarioBase;
	this->horasExtras = horasExtras;
	this->turnosNocturnos = turnosNocturnos;
}

//destructor
Empleado::~Empleado(){
}

//setters
void Empleado::setNombre(string nombre){
	this->nombre = nombre;
}

void Empleado::setIdentificacion(string identificacion){
	this->identificacion = identificacion;
}

void Empleado::setSalarioBase(double salarioBase){
	if (salarioBase >= 0){
		this->salarioBase = salarioBase;
	}
}

void Empleado::setHorasExtras(int horasExtra){
	if (horasExtra >= 0){
		this->horasExtras = horasExtras;
	}
}

void Empleado::setTurnosNocturnos(int turnosNocturnos){
	if (turnosNocturnos >= 0){
		this->turnosNocturnos = turnosNocturnos;
	}
}

//getters
int Empleado::getId() const {
	return id;
}

string Empleado::getNombre() const {
	return nombre;
}

string Empleado::getIdentificacion() const {
	return identificacion;
}

double Empleado::getSalarioBase() const {
	return salarioBase;
}

int Empleado::getHorasExtras() const {
	return horasExtras;
}

int Empleado::getTurnosNocturnos() const {
	return turnosNocturnos;
}
//metodos

double Empleado::calcularPagoHorasExtras() const{
	
	double tarifaHora = salarioBase / 240.0;
	
	double tarifaExtra = tarifaHora * 1.5;
	
	return tarifaExtra * horasExtras;
}

double Empleado::calcularBonificacionNocturna() const {
	return turnosNocturnos * 15000.0;
}

double Empleado::calcularSalarioBruto() const {
	return salarioBase
		+ calcularPagoHorasExtras()
		+ calcularBonificacionNocturna()
		+ calcularBonificacionEspecifica();
}

double Empleado::calcularDeducciones() const {
	return calcularSalarioBruto() * 0.10;
}

double Empleado::calcularSalarioNeto() const {
	return calcularSalarioBruto() - calcularDeducciones();
}
