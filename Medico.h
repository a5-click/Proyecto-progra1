#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"
#include <string>

using namespace std; 

class Medico : public Empleado {
private:
	string especialidad;
	int cantidadGuardias;
	
public:
	//constructor
	Medico(int, string, string, double, int, int, string, int);
	
	//Desctructor
	~Medico();
	
	//setters
	void setEspecialidad(string);
	void setCantidadGuardias(int);
	
	//getters
	string getEspecialidad() const;
	int getCantidadGuardias() const;
	
	//metodos virtuales
	double calcularBonificacionEspecifica() const override;
	
	string obtenerTipoEmpleado() const override;
};
#endif
