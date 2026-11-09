#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleado.h"
#include <string>

using namespace std;

class Administrativo : public Empleado {
private:
	string cargo;
	
public:
	//constructor
	Administrativo(int, string, string, double, int, int, string);
	
	//destructor
	~Administrativo();
	
	//setters
	void setCargo(string);
	
	//getters
	string getCargo() const;
	
	//metodos
	double calcularBonificacionEspecifica() const override;
	
	string obtenerTipoEmpleado() const override;
};

#endif

