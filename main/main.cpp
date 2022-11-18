#include "iri.cpp"
#include "funciones.h"
#include <iostream>

// El using namespace std; esta en funciones.h
// Los testeos estan en casos_base.cpp

int main(void) {

	// Inicializamos los largos de arrays, y los punteros correspondientes
	int nCons = 0;
	int nCont = 0;
	int nMed = 0;
	int nPac = 0;

	int* largoCons = nullptr;
	int* largoCont = nullptr;
	int* largoMed = nullptr;
	int* largoPac = nullptr;

	largoCons = &nCons;
	largoCont = &nCont;
	largoMed = &nMed;
	largoPac = &nPac;

	// Inicializamos los arrays (todos de 0 de largo)
	Consulta* listaConsultas = new Consulta[*largoCons];
	Contacto* listaContactos = new Contacto[*largoCont];
	Medico* listaMedicos = new Medico[*largoMed];
	Paciente* listaPacientes = new Paciente[*largoPac];

	// Aca tendriamos guardada la ubicacion de cada archivo
	// (seguramente dentro del mismo proyecto)
	string filePathCons = (BASE_PATH + "../data_files/input/Consultas.csv");
	string filePathCont = (BASE_PATH + "../data_files/input/Contactos.csv");
	string filePathMed = (BASE_PATH + "../data_files/input/Medicos.csv");
	string filePathPac = (BASE_PATH + "../data_files/input/Pacientes.csv");

	// Cargamos en las listas creadas los datos contenidos en cada archivo
	cargarDatosConsultas(filePathCons, listaConsultas, largoCons);
	cargarDatosContactos(filePathCont, listaContactos, largoCont);
	cargarDatosMedicos(filePathMed, listaMedicos, largoMed);
	cargarDatosPacientes(filePathPac, listaPacientes, largoPac);

	// Creamos las listas auxiliares donde cargariamos
	// las consultas que pasen y no pasen el filtro
	// dentro de la funcion busqueda()
	int nArchivados = 0, nNoArchivados = 0;

	int* largoArch = nullptr;
	int* largoNoArch = nullptr;
	largoArch = &nArchivados;
	largoNoArch = &nNoArchivados;

	Consulta* archivados = new Consulta[*largoArch];
	Consulta* noArchivados = new Consulta[*largoNoArch];

	filtradoConsultas(listaConsultas, archivados, noArchivados, largoCons, largoArch, largoNoArch);

	paraContactar(noArchivados, listaContactos, listaMedicos, listaPacientes, largoNoArch, largoCont, largoMed, largoPac);

	simularSecretaria();

	// Cuando termine el programa borramos los listados dinamicos,
	// asi ya no ocupan mas memoria
	delete[] listaConsultas;
	delete[] listaContactos;
	delete[] listaMedicos;
	delete[] listaPacientes;

	delete[] archivados;
	delete[] noArchivados;

    return EXIT_SUCCESS;
}
