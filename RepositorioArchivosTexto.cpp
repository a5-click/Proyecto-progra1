#include "RepositorioArchivosTexto.h"

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "ListaEmpleado.h"
#include "ListaDepartamento.h"
#include "ListaComprobante.h"
#include "NodoEmpleado.h"
#include "NodoDepartamento.h"
#include "NodoComprobante.h"
#include "ListaPuesto.h"
#include "NodoPuesto.h"
#include "Departamento.h"
#include "Puesto.h"
#include "ComprobantePago.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"

namespace {
    // Los archivos usan | como separador. No escriba ese caracter dentro
    // de nombres, especialidades, cargos, turnos o descripciones.
    bool separar(const string& linea, char separador, string campos[], int maxCampos,
                 int& cantidad) {
        cantidad = 0;
        string campo;
        stringstream flujo(linea);
        while (getline(flujo, campo, separador)) {
            if (cantidad >= maxCampos) return false;
            campos[cantidad++] = campo;
        }
        return true;
    }

    int aEntero(const string& valor) { return atoi(valor.c_str()); }
    double aDecimal(const string& valor) { return atof(valor.c_str()); }

    Empleado* crearEmpleado(const string campos[], int n) {
        if (n < 8) return nullptr;

        string tipo = campos[0];
        int id = aEntero(campos[1]);
        string nombre = campos[2];
        string identificacion = campos[3];
        double salario = aDecimal(campos[4]);
        int extras = aEntero(campos[5]);
        int nocturnos = aEntero(campos[6]);

        if (tipo == "MEDICO" && n >= 9) {
            return new Medico(id, nombre, identificacion, salario, extras,
			nocturnos, campos[7], aEntero(campos[8]));
        }
        if (tipo == "ENFERMERO" && n >= 9) {
            return new Enfermero(id, nombre, identificacion, salario, extras,
			nocturnos, campos[7], aEntero(campos[8]));
        }
        if (tipo == "ADMINISTRATIVO") {
            return new Administrativo(id, nombre, identificacion, salario,
			extras, nocturnos, campos[7]);
        }
        return nullptr;
    }

    Empleado* buscarEmpleado(const ListaEmpleado& lista, int id) {
        for (int i = 0; i < lista.getCantidad(); i++) {
            Empleado* e = lista.obtenerEnPosicion(i);
            if (e != nullptr && e->getId() == id) return e;
        }
        return nullptr;
    }

    Departamento* buscarDepartamento(const ListaDepartamento& lista, int id) {
        for (int i = 0; i < lista.getCantidad(); i++) {
            Departamento* d = lista.obtenerEnPosicion(i);
            if (d != nullptr && d->getId() == id) return d;
        }
        return nullptr;
    }
}

RepositorioArchivosTexto::RepositorioArchivosTexto(
    string archivoEmpleados, string archivoDepartamentos, string archivoPlanilla) {
    this->archivoEmpleados = archivoEmpleados;
    this->archivoDepartamentos = archivoDepartamentos;
    this->archivoPlanilla = archivoPlanilla;
}

bool RepositorioArchivosTexto::cargarEmpleados(ListaEmpleado& empleados) {
    ifstream archivo(archivoEmpleados.c_str());
    if (!archivo.is_open()) return false;

    empleados.vaciar();
    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        string campos[10];
        int n = 0;
        if (!separar(linea, '|', campos, 10, n)) continue;
        Empleado* empleado = crearEmpleado(campos, n);
        if (empleado != nullptr) empleados.insertarFinal(empleado);
    }
    archivo.close();
    return true;
}

bool RepositorioArchivosTexto::cargarDepartamentos(ListaDepartamento& departamentos) {
    ifstream archivo(archivoDepartamentos.c_str());
    if (!archivo.is_open()) return false;

    departamentos.vaciar();
    string linea;
    // Formato: D|id|nombre y P|idDepartamento|idPuesto|nombre|descripcion
    // Primero se crean todos los departamentos y luego se agregan sus puestos.
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        string campos[6];
        int n = 0;
        if (!separar(linea, '|', campos, 6, n) || n < 3) continue;
        if (campos[0] == "D") {
            departamentos.insertarFinal(new Departamento(aEntero(campos[1]), campos[2]));
        }
    }

    archivo.clear();
    archivo.seekg(0);
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        string campos[6];
        int n = 0;
        if (!separar(linea, '|', campos, 6, n)) continue;
        if (n >= 5 && campos[0] == "P") {
            Departamento* d = buscarDepartamento(departamentos, aEntero(campos[1]));
            if (d != nullptr) {
                d->agregarPuesto(new Puesto(aEntero(campos[2]), campos[3], campos[4]));
            }
        }
    }
    archivo.close();
    return true;
}

bool RepositorioArchivosTexto::cargarPlanilla(
    ListaComprobante& planilla, const ListaEmpleado& empleados,
    const ListaDepartamento& departamentos) {
    ifstream archivo(archivoPlanilla.c_str());
    if (!archivo.is_open()) return false;

    planilla.vaciar();
    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        string campos[8];
        int n = 0;
        if (!separar(linea, '|', campos, 8, n) || n < 7) continue;

        Empleado* empleado = buscarEmpleado(empleados, aEntero(campos[2]));
        Departamento* departamento = buscarDepartamento(departamentos, aEntero(campos[3]));
        if (empleado == nullptr || departamento == nullptr) continue;

        planilla.insertarFinal(new ComprobantePago(
            aEntero(campos[0]), campos[1], empleado, departamento,
            aDecimal(campos[4]), aDecimal(campos[5]), aDecimal(campos[6])));
    }
    archivo.close();
    return true;
}

bool RepositorioArchivosTexto::guardarEmpleados(const ListaEmpleado& empleados) {
    ofstream archivo(archivoEmpleados.c_str());
    if (!archivo.is_open()) return false;

    NodoEmpleado* nodo = empleados.getPrimero();
    while (nodo != nullptr) {
        Empleado* e = nodo->getDato();
        if (e != nullptr) {
            archivo << e->obtenerTipoEmpleado() << '|'
                    << e->getId() << '|' << e->getNombre() << '|'
                    << e->getIdentificacion() << '|'
                    << setprecision(15) << e->getSalarioBase() << '|'
                    << e->getHorasExtras() << '|' << e->getTurnosNocturnos();

            Medico* medico = dynamic_cast<Medico*>(e);
            Enfermero* enfermero = dynamic_cast<Enfermero*>(e);
            Administrativo* administrativo = dynamic_cast<Administrativo*>(e);

            if (medico != nullptr) {
                archivo << '|' << medico->getEspecialidad()
                        << '|' << medico->getCantidadGuardias();
            } else if (enfermero != nullptr) {
                archivo << '|' << enfermero->getTurno()
                        << '|' << enfermero->getCantidadGuardias();
            } else if (administrativo != nullptr) {
                archivo << '|' << administrativo->getCargo();
            }
            archivo << '\n';
        }
        nodo = nodo->getSiguiente();
    }
    archivo.close();
    return true;
}

bool RepositorioArchivosTexto::guardarDepartamentos(const ListaDepartamento& departamentos) {
    ofstream archivo(archivoDepartamentos.c_str());
    if (!archivo.is_open()) return false;

    for (int i = 0; i < departamentos.getCantidad(); i++) {
        Departamento* d = departamentos.obtenerEnPosicion(i);
        if (d == nullptr) continue;
        archivo << "D|" << d->getId() << '|' << d->getNombre() << '\n';

        const ListaPuesto* puestos = d->getListaPuestos();
        NodoPuesto* nodo = puestos->getPrimero();
        while (nodo != nullptr) {
            Puesto* p = nodo->getDato();
            if (p != nullptr) {
                archivo << "P|" << d->getId() << '|' << p->getId()
                        << '|' << p->getNombre() << '|'
                        << p->getDescripcion() << '\n';
            }
            nodo = nodo->getSiguiente();
        }
    }
    archivo.close();
    return true;
}

bool RepositorioArchivosTexto::guardarPlanilla(const ListaComprobante& planilla) {
    ofstream archivo(archivoPlanilla.c_str());
    if (!archivo.is_open()) return false;

    NodoComprobante* nodo = planilla.getPrimero();
    while (nodo != nullptr) {
        ComprobantePago* c = nodo->getDato();
        if (c != nullptr && c->getEmpleado() != nullptr &&
            c->getDepartamento() != nullptr) {
            archivo << c->getId() << '|' << c->getFecha() << '|'
                    << c->getEmpleado()->getId() << '|'
                    << c->getDepartamento()->getId() << '|'
                    << setprecision(15) << c->getSalarioBruto() << '|'
                    << c->getDeducciones() << '|'
                    << c->getSalarioNeto() << '\n';
        }
        nodo = nodo->getSiguiente();
    }
    archivo.close();
    return true;
}
