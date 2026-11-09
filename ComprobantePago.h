#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H

#include <string>
#include "Empleado.h"
class Departamento;
using namespace std;

// Agregacion: los punteros a Empleado y Departamento NO son propiedad
// del comprobante. Sus objetos existen independientemente.
class ComprobantePago {
private:
    int id;
    string fecha;
    Empleado* empleado;
    Departamento* departamento;
    double salarioBruto;
    double deducciones;
    double salarioNeto;

public:
    ComprobantePago(int id, string fecha, Empleado* empleado,
                    Departamento* departamento, double salarioBruto,
                    double deducciones, double salarioNeto);
    ~ComprobantePago();

    int getId() const;
    string getFecha() const;
    Empleado* getEmpleado() const;
    Departamento* getDepartamento() const;
    double getSalarioBruto() const;
    double getDeducciones() const;
    double getSalarioNeto() const;

    void setFecha(string fecha);
    void setEmpleado(Empleado* empleado);
    void setDepartamento(Departamento* departamento);
    void setMontos(double salarioBruto, double deducciones, double salarioNeto);
};

#endif
