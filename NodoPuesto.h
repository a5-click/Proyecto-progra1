#ifndef NODOPUESTO_H
#define NODOPUESTO_H
#include "Puesto.h"

class NodoPuesto {
private:
	Puesto* dato;
	NodoPuesto* siguiente;
	
public:
	NodoPuesto(Puesto* dato);
	NodoPuesto(Puesto* dato, NodoPuesto* siguiente);
	~NodoPuesto();
	
	Puesto* getDato() const;
	NodoPuesto* getSiguiente() const;
	
	void setDato(Puesto* dato);
	void setSiguiente(NodoPuesto* siguiente);
};
#endif
