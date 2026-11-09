#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"
#include <string>

using namespace std;

class Enfermero : public Empleado {
private:
	string turno;
	int cantidadGuardias;
	
public:
	//constructor
	Enfermero(int, string, string, double, int, int,
			  string, int);
	
	//desctrutor
	~Enfermero();
	
	//setters
	void setTurno(string);
	void setCantidadGuardias(int);
	
	//getters
	string getTurno() const;
	int getCantidadGuardias() const;
	
	//metodos virtuales
	double calcularBonificacionEspecifica() const override;
	
	string obtenerTipoEmpleado() const override;
	
};

#endif

