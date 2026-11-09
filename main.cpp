
#include <iostream>
#include <string>
#include <limits>

#include "Empleado.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"

#include "Departamento.h"
#include "Puesto.h"
#include "ComprobantePago.h"

#include "ListaEmpleado.h"
#include "ListaDepartamento.h"
#include "ListaPuesto.h"
#include "ListaComprobante.h"

#include "RepositorioArchivosTexto.h"
#include "ServicioPersistencia.h"

using namespace std;

// PROTOTIPOS
void menuPrincipal();
void registrarEmpleado(ListaEmpleado& empleados);
void mostrarEmpleados(ListaEmpleado& empleados);
void registrarDepartamento(ListaDepartamento& departamentos);
void mostrarDepartamentos(ListaDepartamento& departamentos);
void agregarPuesto(ListaDepartamento& departamentos);
void generarComprobante(ListaEmpleado& empleados,
ListaDepartamento& departamentos,
ListaComprobante& planilla);
void mostrarPlanilla(ListaComprobante& planilla);

// FUNCION PRINCIPAL
int main() {
	
	ListaEmpleado empleados;
	ListaDepartamento departamentos;
	ListaComprobante planilla;
	
	RepositorioArchivosTexto repositorio;
	ServicioPersistencia persistencia(repositorio);
	
	cout << "======================================" << endl;
	cout << "   SISTEMA DE PLANILLA HOSPITALARIA" << endl;
	cout << "======================================" << endl;
	
	if (persistencia.cargarTodo(empleados, departamentos, planilla)) {
		cout << "Datos cargados correctamente." << endl;
	} else {
		cout << "No se encontraron todos los archivos." << endl;
	}
	
	int opcion;
	
	do {
		menuPrincipal();
		cin >> opcion;
		
		switch (opcion) {
			
		case 1:
			registrarEmpleado(empleados);
			persistencia.guardarTodo(empleados, departamentos, planilla);
			break;
			
		case 2:
			mostrarEmpleados(empleados);
			break;
			
		case 3:
			registrarDepartamento(departamentos);
			persistencia.guardarTodo(empleados, departamentos, planilla);
			break;
			
		case 4:
			mostrarDepartamentos(departamentos);
			break;
			
		case 5:
			agregarPuesto(departamentos);
			persistencia.guardarTodo(empleados, departamentos, planilla);
			break;
			
		case 6:
			generarComprobante(empleados, departamentos, planilla);
			persistencia.guardarTodo(empleados, departamentos, planilla);
			break;
			
		case 7:
			mostrarPlanilla(planilla);
			break;
			
		case 8:
			if (persistencia.guardarTodo(empleados, departamentos, planilla)) {
				cout << "Informacion guardada correctamente." << endl;
			} else {
				cout << "Error al guardar." << endl;
			}
			break;
			
		case 9:
			persistencia.guardarTodo(empleados, departamentos, planilla);
			cout << "Gracias por utilizar el sistema." << endl;
			break;
			
		default:
			cout << "Opcion no valida." << endl;
		}
		
	} while (opcion != 9);
	
	return 0;
}

// MENU PRINCIPAL
void menuPrincipal() {
	
	cout << "\n========== MENU PRINCIPAL ==========" << endl;
	cout << "1. Registrar empleado" << endl;
	cout << "2. Mostrar empleados" << endl;
	cout << "3. Registrar departamento" << endl;
	cout << "4. Mostrar departamentos" << endl;
	cout << "5. Agregar puesto a departamento" << endl;
	cout << "6. Generar comprobante de pago" << endl;
	cout << "7. Mostrar planilla" << endl;
	cout << "8. Guardar informacion" << endl;
	cout << "9. Salir" << endl;
	cout << "Seleccione una opcion: ";
}

// REGISTRAR EMPLEADO
void registrarEmpleado(ListaEmpleado& empleados) {
	
	int tipo, id, extras, nocturnos;
	string nombre, identificacion;
	
	double salario;
	
	cout << "\nTIPO DE EMPLEADO" << endl;
	cout << "1. Medico" << endl;
	cout << "2. Enfermero" << endl;
	cout << "3. Administrativo" << endl;
	cout << "Seleccione: ";
	cin >> tipo;
	
	cout << "ID: ";
	cin >> id;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "Nombre: ";
	getline(cin, nombre);
	
	cout << "Identificacion: ";
	getline(cin, identificacion);
	
	cout << "Salario base: ";
	cin >> salario;
	
	cout << "Horas extras: ";
	cin >> extras;
	
	cout << "Turnos nocturnos: ";
	cin >> nocturnos;
	
	Empleado* nuevo = nullptr;
	
	if (tipo == 1) {
		
		string especialidad;
		int guardias;
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout << "Especialidad: ";
		getline(cin, especialidad);
		
		cout << "Cantidad de guardias: ";
		cin >> guardias;
		
		nuevo = new Medico(id, nombre, identificacion,
		salario, extras, nocturnos,
		especialidad, guardias);
	}
	
	else if (tipo == 2) {
		
		string turno;
		int guardias;
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout << "Turno: ";
		getline(cin, turno);
		
		cout << "Cantidad de guardias: ";
		cin >> guardias;
		
		nuevo = new Enfermero(id, nombre, identificacion,
		salario, extras, nocturnos,
		turno, guardias);
	}
	
	else if (tipo == 3) {
		
		string cargo;
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout << "Cargo: ";
		getline(cin, cargo);
		
		nuevo = new Administrativo(id, nombre, identificacion,
		salario, extras, nocturnos, cargo);
	}
	
	if (nuevo != nullptr) {
		empleados.insertarFinal(nuevo);
		cout << "Empleado registrado correctamente." << endl;
	} else {
		cout << "Tipo de empleado incorrecto." << endl;
	}
}

// MOSTRAR EMPLEADOS
void mostrarEmpleados(ListaEmpleado& empleados) {
	
	cout << "\n========== EMPLEADOS ==========" << endl;
	
	for (int i = 0; i < empleados.getCantidad(); i++) {
		
		Empleado* e = empleados.obtenerEnPosicion(i);
		
		if (e != nullptr) {
			cout << "\nID: " << e->getId() << endl;
			cout << "Nombre: " << e->getNombre() << endl;
			cout << "Identificacion: " << e->getIdentificacion() << endl;
			cout << "Salario base: " << e->getSalarioBase() << endl;
			cout << "Salario bruto: " << e->calcularSalarioBruto() << endl;
			cout << "Salario neto: " << e->calcularSalarioNeto() << endl;
		}
	}
}

// REGISTRAR DEPARTAMENTO
void registrarDepartamento(ListaDepartamento& departamentos) {
	
	int id;
	string nombre;
	
	cout << "\nID del departamento: ";
	cin >> id;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "Nombre del departamento: ";
	getline(cin, nombre);
	
	Departamento* nuevo = new Departamento(id, nombre);
	
	departamentos.insertarFinal(nuevo);
	
	cout << "Departamento registrado correctamente." << endl;
}

// MOSTRAR DEPARTAMENTOS
void mostrarDepartamentos(ListaDepartamento& departamentos) {
	
	cout << "\n========== DEPARTAMENTOS ==========" << endl;
	
	for (int i = 0; i < departamentos.getCantidad(); i++) {
		
		Departamento* d = departamentos.obtenerEnPosicion(i);
		
		if (d != nullptr) {
			cout << "ID: " << d->getId() << endl;
			cout << "Nombre: " << d->getNombre() << endl;
			cout << "Cantidad de puestos: "
				<< d->getCantidadPuestos() << endl;
		}
	}
}

// AGREGAR PUESTO
void agregarPuesto(ListaDepartamento& departamentos) {
	
	int idDepartamento;
	int idPuesto;
	string nombre, descripcion;
	
	cout << "\nID del departamento: ";
	cin >> idDepartamento;
	
	Departamento* departamento = nullptr;
	
	for (int i = 0; i < departamentos.getCantidad(); i++) {
		
		Departamento* actual = departamentos.obtenerEnPosicion(i);
		
		if (actual != nullptr && actual->getId() == idDepartamento) {
			departamento = actual;
			break;
		}
	}
	
	if (departamento == nullptr) {
		cout << "Departamento no encontrado." << endl;
		return;
	}
	
	cout << "ID del puesto: ";
	cin >> idPuesto;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "Nombre del puesto: ";
	getline(cin, nombre);
	
	cout << "Descripcion: ";
	getline(cin, descripcion);
	
	Puesto* puesto = new Puesto(idPuesto, nombre, descripcion);
	
	departamento->agregarPuesto(puesto);
	
	cout << "Puesto agregado correctamente." << endl;
}

// GENERAR COMPROBANTE
void generarComprobante(ListaEmpleado& empleados,
	ListaDepartamento& departamentos,
	ListaComprobante& planilla) {
	
	int idEmpleado, idDepartamento, idComprobante;
	string fecha;
	
	cout << "\nID del comprobante: ";
	cin >> idComprobante;
	
	cout << "ID del empleado: ";
	cin >> idEmpleado;
	
	Empleado* empleado = nullptr;
	
	for (int i = 0; i < empleados.getCantidad(); i++) {
		
		Empleado* actual = empleados.obtenerEnPosicion(i);
		
		if (actual != nullptr && actual->getId() == idEmpleado) {
			empleado = actual;
			break;
		}
	}
	
	if (empleado == nullptr) {
		cout << "Empleado no encontrado." << endl;
		return;
	}
	
	cout << "ID del departamento: ";
	cin >> idDepartamento;
	
	Departamento* departamento = nullptr;
	
	for (int i = 0; i < departamentos.getCantidad(); i++) {
		
		Departamento* actual = departamentos.obtenerEnPosicion(i);
		
		if (actual != nullptr && actual->getId() == idDepartamento) {
			departamento = actual;
			break;
		}
	}
	
	if (departamento == nullptr) {
		cout << "Departamento no encontrado." << endl;
		return;
	}
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "Fecha del pago: ";
	getline(cin, fecha);
	
	double bruto = empleado->calcularSalarioBruto();
	double neto = empleado->calcularSalarioNeto();
	double deducciones = bruto - neto;
	
	ComprobantePago* comprobante =
		new ComprobantePago(idComprobante, fecha, empleado,
		departamento, bruto, deducciones, neto);
	
	planilla.insertarFinal(comprobante);
	
	cout << "\nComprobante generado correctamente." << endl;
	cout << "Salario bruto: " << bruto << endl;
	cout << "Deducciones: " << deducciones << endl;
	cout << "Salario neto: " << neto << endl;
}

// MOSTRAR PLANILLA
	void mostrarPlanilla(ListaComprobante& planilla) {
		cout << "\n========== REGISTROS DE PLANILLA ==========" << endl;
		for (int i = 0; i < planilla.getCantidad(); i++) {
			ComprobantePago* c = planilla.obtenerEnPosicion(i);
			if (c != nullptr) {
				cout << "\nComprobante: " << c->getId() << endl;
				cout << "Fecha: " << c->getFecha() << endl;
				if (c->getEmpleado() != nullptr) {
					cout << "Empleado: "
					<< c->getEmpleado()->getNombre() << endl;
									}
									
				if (c->getDepartamento() != nullptr) {
					cout << "Departamento: "
					<< c->getDepartamento()->getNombre() << endl;
									}
									
				cout << "Salario bruto: " << c->getSalarioBruto() << endl;
				cout << "Deducciones: " << c->getDeducciones() << endl;
				cout << "Salario neto: " << c->getSalarioNeto() << endl;
								}
							}
						}
						
