# Proyecto-progra1
Grupo 2
Luis Sobrado Núñez 119920638
Freddy Mora 208770627
Marco Cuadra 208930547


Sistema de Gestión de Planilla Hospitalaria
Descripción del Proyecto
Sistema desarrollado en C++ para la administración de personal, organización de departamentos, puestos de trabajo y cálculo de salarios en una institución hospitalaria. El proyecto está construido bajo los principios de la Programación Orientada a Objetos (POO), principios SOLID y el uso de estructuras de datos dinámicas.

Funcionalidades Principales
Gestión de Personal: Registro, clasificación (Médicos, Enfermeros y Administrativos) y visualización de empleados.

Estructura Organizacional: Administración de departamentos y asignación de puestos de trabajo.

Control Salarial: Cálculo de salarios, deducciones, salarios netos y emisión de comprobantes de pago.

Persistencia de Datos: Almacenamiento y recuperación de información mediante archivos de texto (empleados.txt, departamentos.txt, planilla.txt).

Arquitectura y Componentes
Jerarquía de Clases: Empleado (clase base abstracta), Medico, Enfermero, Administrativo, Departamento, Puesto y ComprobantePago.

Estructuras Dinámicas: Listas implementadas mediante nodos (ListaEmpleado, ListaDepartamento, ListaPuesto, ListaComprobante).

Capas de Persistencia: Separación de la lógica de almacenamiento a través de IRepositorioPlanilla, RepositorioArchivosTexto y ServicioPersistencia.

Principios de Diseño: Aplicación de polimorfismo, herencia, composición, agregación y principios SOLID.

Requisitos y Ejecución
Lenguaje: C++

Para compilar y ejecutar el proyecto:

Importar todos los archivos fuente (.h y .cpp) dentro del entorno de desarrollo.

Verificar la correcta inclusión de dependencias entre cabeceras y clases.

Compilar el proyecto para generar el binario.

Ejecutar la aplicación desde la consola.
