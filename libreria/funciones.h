#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

// El struct fecha es para solucionarnos la vida y no tener que usar tanto <ctime>
typedef struct fecha {
	int dia, mes, anio;
}Fecha;

typedef struct consulta {
	string dni_pac;
	Fecha fechaSoli;
	Fecha fechaCons;
	bool presento;
	string matriculaMed;
}Consulta;

typedef struct contacto {
	string dni_pac;
	string telefono;
	string celular;
	string direccion;
	string mail;
}Contacto;

typedef struct medico {
	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
}Medico;

typedef struct paciente {
	unsigned int dni;
	string nombre;
	string apellido;
	char sexo;
	Fecha natalicio;
	string estado;
	string id_os;
}Paciente;

// Todas las funciones "cargar" añaden los datos dentro de un archivo .csv,
// cuya ubicacion es pasada como parametro, a un listado  que tambien es
// pasado como parametro junto con su largo en forma de puntero
void cargarDatosConsultas(string filePath, Consulta*& listado, int* largo);
void cargarDatosContactos(string filePath, Contacto*& listado, int* largo);
void cargarDatosMedicos(string filePath, Medico*& listado, int* largo);
void cargarDatosPacientes(string filePath, Paciente*& listado, int* largo);

// Todas las funciones "agregar" añaden un elemento
// a un listado ya establecido alargando dicho listado en uno
void agregarConsulta(Consulta*& listado, Consulta agregar, int* largo);
void agregarContacto(Contacto*& listado, Contacto agregar, int* largo);
void agregarMedico(Medico*& listado, Medico agregar, int* largo);
void agregarPaciente(Paciente*& listado, Paciente agregar, int* largo);

// Funcion auxiliar
// Ordena el listado principal de consultas
// Primero segun el paciente (usando el documento)
// y luego segun las fechas de consultas, de mas antigua a mas reciente
// 
// Usamos la mas reciente para ver si al paciente hay que archivarlo o no
// Utilizamos bubble sorting, es extremadamente ineficiente y poco practico, pero es el unico metodo de ordenamiento que vimos
void ordenarConsultas(Consulta*& listado, int* largo);

// Hace un filtro al listado de las consultas
// Dejando en una lista las que pasen dicho filtro,
// y en otra las que no lo hagan
void filtradoConsultas(Consulta*& listado, Consulta*& archivados, Consulta*& noArchivados, int* largo,  int* largoArch, int* largoNoArch);


// Usando los DNIs cargados en noArchivados, se carga en un archivo  llamado "paraContactar.csv", el cual luego seria enviado para secretaria
// Se tiene en cuenta si el paciente aparece en todas las demas archivos o no
// Retorna la cantidad de pacientes a contactar
void paraContactar(Consulta*& noArchivados, Contacto*& listaCont, Medico*& listaMed, Paciente*& listaPac, int* largoNoArch, int* largoCont, int* largoMed, int* largoPac);

// Simula usando numeros aleatorios el pase del archivo "paraContactar.csv" a la secretaria
// Devuelve los resultado en un nuevo archivo llamado "contactados.csv" que seria el resultado final del programa
// Dicho archivo tendria como orden de datos:
// nombre , apellido , id_os , retorna , nuevaConsulta
// En caso de que el paciente no quiera retornar, la nueva consulta estaria como "0/0/0"
void simularSecretaria();

// Funcion auxiliar
// Retorna true si el anio es bisiesto, false en caso contrario
bool esBisiesto(int anio);

// Funcion auxiliar
// retorna true si el dni son solo numeros y si el largo es entre 7 y 8, false en caso contrario.
bool chequearDNI(string DNI);