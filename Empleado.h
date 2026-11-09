#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using namespace std;

class Empleado {
private:
	int id;
	string nombre;
	string identificacion;
	double salarioBase;
	int horasExtras;
	int turnosNocturnos;

public:
	Empleado(int, string, string, double, int, int); //Constructor
	
	virtual ~Empleado(); //Destructor Virtual
	
	void setNombre(string);
	void setIdentificacion(string);
	void setSalarioBase(double);
	void setHorasExtras(int);
	void setTurnosNocturnos(int);
	//setters
	
	int getId() const;
	string getNombre() const;
	string getIdentificacion() const;
	double getSalarioBase() const;
	int getHorasExtras() const;
	int getTurnosNocturnos() const;
	//Getters
	
	//metdos
	double calcularPagoHorasExtras() const;
	double calcularBonificacionNocturna() const;
	
	virtual double calcularBonificacionEspecifica() const=0;
	
	double calcularSalarioBruto() const;
	double calcularDeducciones() const;
	double calcularSalarioNeto() const;
	
	virtual string obtenerTipoEmpleado() const=0;
	//indentificar el tipo de empleado
	
};

#endif

