#ifndef NODOCOMPROBANTE_H
#define NODOCOMPROBANTE_H
#include "ComprobantePago.h"

class NodoComprobante {
private:
	ComprobantePago* dato;
	NodoComprobante* siguiente;
	
public:
	NodoComprobante(ComprobantePago* dato);
	NodoComprobante(ComprobantePago* dato, NodoComprobante* siguiente);
	~NodoComprobante();
	
	ComprobantePago* getDato() const;
	NodoComprobante* getSiguiente() const;
	
	void setDato(ComprobantePago* dato);
	void setSiguiente(NodoComprobante* siguiente);
};
#endif
