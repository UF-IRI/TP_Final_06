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

	// Inicializamos los arrays (todos de 0 de largo)
	Consulta* listaConsultas = nullptr;
	listaConsultas = new Consulta[nCons];

	Contacto* listaContactos = nullptr;
	listaContactos = new Contacto[nCont];

	Medico* listaMedicos = nullptr;
	listaMedicos = new Medico[nMed];

	Paciente* listaPacientes = nullptr;
	listaPacientes = new Paciente[nPac];

	// Inicializamos los lectores de archivos
	fstream fp;
	fstream fp2;

	// Cargamos en las listas creadas los datos contenidos en cada archivo
	// utilizando la ruta de cada uno
	fp.open(BASE_PATH + "../data_files/input/Consultas.csv",ios::in);
	cargarDatosConsultas(fp, listaConsultas, &nCons);
	fp.close();

	fp.open(BASE_PATH + "../data_files/input/Contactos.csv", ios::in);
	cargarDatosContactos(fp, listaContactos, &nCont);
	fp.close();

	fp.open(BASE_PATH + "../data_files/input/Medicos.csv", ios::in);
	cargarDatosMedicos(fp, listaMedicos, &nMed);
	fp.close();

	fp.open(BASE_PATH + "../data_files/input/Pacientes.csv", ios::in);
	cargarDatosPacientes(fp, listaPacientes, &nPac);
	fp.close();

	// Creamos las listas auxiliares donde cargariamos
	// las consultas que pasen y no pasen el filtro
	// dentro de la funcion busqueda()
	int nArchivados = 0;
	int nNoArchivados = 0;

	Consulta* archivados = nullptr;
	archivados = new Consulta[nArchivados];

	Consulta* noArchivados = nullptr;
	noArchivados = new Consulta[nNoArchivados];

	fp.open("archivados.csv", ios::out);
	fp2.open("noArchivados.csv", ios::out);
	filtradoConsultas(fp,fp2,listaConsultas, archivados, noArchivados, &nCons, &nArchivados, &nNoArchivados);
	fp.close();
	fp2.close();

	fp.open("paraContactar.csv", ios::out);
	paraContactar(fp, noArchivados, listaContactos, listaMedicos, listaPacientes, &nNoArchivados, &nCont, &nMed, &nPac);
	fp.close();

	fp.open("paraContactar.csv", ios::in);
	fp2.open("contactados.csv", ios::out);
	simularSecretaria(fp,fp2);
	fp.close();
	fp2.close();

	// Cuando termine el programa borramos los listados dinamicos, asi ya no ocupan mas memoria
	delete[] listaConsultas;
	delete[] listaContactos;
	delete[] listaMedicos;
	delete[] listaPacientes;

	delete[] archivados;
	delete[] noArchivados;

    return EXIT_SUCCESS;
}
