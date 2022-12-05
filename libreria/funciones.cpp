#include "funciones.h"

void cargarDatosConsultas(string filePath, Consulta*& listado, int* largo) {
	// Creamos el lector de archivos, y 2 strings auxiliares
	fstream fp;
	string line = "", headers = "", coma = "";
	// Abrimos el archivo de Ultimas Consultas
	fp.open(filePath, ios::in);
	// Chequeamos si esta abierto o no
	if (!fp.is_open()) {
		return;
	}
	// salteamos los encabezados
	getline(fp, headers);
	// Creamos un auxiliar a cargar en el listado
	Consulta auxCons;

	// Recorremos linea por linea el archivo,
	// cargando todos los datos disponibles en el listado
	while (getline(fp, line)) {
		string auxString = "";
		stringstream inputString(line);

		getline(inputString, auxString, ' ');
		auxCons.dni_pac = stoi(auxString);

		getline(inputString, coma, ' ');

		string auxDate = "";
		getline(inputString, auxString, ' ');
		stringstream date(auxString);
		// Primero dia y despues mes, asi esta en el mismo formato del .csv
		getline(date, auxDate, '/');
		auxCons.fechaSoli.dia = stoi(auxDate);
		getline(date, auxDate, '/');
		auxCons.fechaSoli.mes = stoi(auxDate);
		getline(date, auxDate, ' ');
		auxCons.fechaSoli.anio = stoi(auxDate);

		getline(inputString, coma, ' ');

		auxDate = "";
		getline(inputString, auxString, ' ');
		stringstream date2(auxString);
		// Primero dia y despues mes, asi esta en el mismo formato del .csv
		getline(date2, auxDate, '/');
		auxCons.fechaCons.dia = stoi(auxDate);
		getline(date2, auxDate, '/');
		auxCons.fechaCons.mes = stoi(auxDate);
		getline(date2, auxDate, ' ');
		auxCons.fechaCons.anio = stoi(auxDate);

		getline(inputString, coma, ' ');

		getline(inputString, auxString, ' ');
		if (auxString == "1") {
			auxCons.presento = true;
		}
		else {
			auxCons.presento = false;
		}

		getline(inputString, coma, ' ');

		getline(inputString, auxCons.matriculaMed, ' ');

		// Agregamos los datos cargados en auxPac al listado de pacientes
		agregarConsulta(listado, auxCons, largo);
	}
	// Cerramos el archivo
	fp.close();
}

void cargarDatosContactos(string filePath, Contacto*& listado, int* largo) {
	// Creamos el lector de archivos, y 2 strings auxiliares
	fstream fp;
	string line = "", headers = "", coma = "";

	// Abrimos el archivo de Contactos
	fp.open(filePath, ios::in);
	// Chequeamos si esta abierto o no
	if (!fp.is_open()) {
		return;
	}
	// salteamos los encabezados
	getline(fp, headers);
	// Creamos un auxiliar a cargar en el listado
	Contacto auxCont;

	// Recorremos linea por linea el archivo,
	// cargando todos los datos disponibles en el listado
	while (getline(fp, line)) {
		string auxString = "";
		stringstream inputString(line);

		getline(inputString, auxString, ' ');
		auxCont.dni_pac = stoi(auxString);

		getline(inputString, coma, ' ');
		
		getline(inputString, auxCont.telefono, ' ');
		
		getline(inputString, coma, ' ');

		getline(inputString, auxCont.celular, ' ');
		
		getline(inputString, coma, ' ');

		getline(inputString, auxCont.direccion, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxCont.mail, ' ');

		agregarContacto(listado, auxCont, largo);
	}
	// Cerramos el archivo
	fp.close();
}

void cargarDatosMedicos(string filePath, Medico*& listado, int* largo) {
	// Creamos el lector de archivos, y 2 strings auxiliares
	fstream fp;
	string line = "", headers = "", coma = "";

	// Abrimos el archivo de Pacientes
	fp.open(filePath, ios::in);
	// Chequeamos si esta abierto o no
	if (!fp.is_open()) {
		return;
	}
	// salteamos los encabezados
	getline(fp, headers);
	// Creamos un auxiliar a cargar en el listado
	Medico auxMed;

	// Recorremos linea por linea el archivo,
	// cargando todos los datos disponibles en el listado
	while (getline(fp, line)) {
		string auxString = "";
		stringstream inputString(line);

		getline(inputString, auxMed.matricula, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxMed.nombre, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxMed.apellido, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxMed.telefono, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxMed.especialidad, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxString, ' ');
		if (auxString == "true") {
			auxMed.activo = true;
		}
		else {
			auxMed.activo = false;
		}

		// Agregamos los datos cargados en auxPac al listado de pacientes
		agregarMedico(listado, auxMed, largo);
	}
	// Cerramos el archivo
	fp.close();
}

void cargarDatosPacientes(string filePath, Paciente*& listado, int* largo) {
	// Creamos el lector de archivos, y 2 strings auxiliares
	fstream fp;
	string line = "", headers = "", coma = "";

	// Abrimos el archivo de Pacientes
	fp.open(filePath, ios::in);
	// Chequeamos si esta abierto o no
	if (!fp.is_open()) {
		return;
	}
	// salteamos los encabezados
	getline(fp, headers);
	// Creamos un auxiliar a cargar en el listado
	Paciente auxPac;

	// Recorremos linea por linea el archivo,
	// cargando todos los datos disponibles en el listado
	while (getline(fp, line)) {
		string auxString = "";
		stringstream inputString(line);

		getline(inputString, auxString, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxPac.nombre, ' ');
		
		if (chequearDNI(auxString)) //VER SI ESTO ES DNI
		{
			auxPac.dni = stoi(auxString); //VER SI LO CAMBIAMOS
		}

		getline(inputString, coma, ' ');

		getline(inputString, auxPac.apellido, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxString, ' ');
		auxPac.sexo = auxString[0];

		getline(inputString, coma, ' ');

		string auxDate = "";
		getline(inputString, auxString, ' ');
		stringstream date(auxString);
		// Primero mes y despues dia, asi esta en el mismo formato del .csv
		getline(date, auxDate, '/');
		auxPac.natalicio.dia = stoi(auxDate);
		getline(date, auxDate, '/');
		auxPac.natalicio.mes = stoi(auxDate);
		getline(date, auxDate, ' ');
		auxPac.natalicio.anio = stoi(auxDate);

		getline(inputString, coma, ' ');

		getline(inputString, auxPac.estado, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxPac.id_os, ' ');

		// Agregamos los datos cargados en auxPac al listado de pacientes
		agregarPaciente(listado, auxPac, largo);
	}
	// Cerramos el archivo
	fp.close();
}

void agregarConsulta(Consulta*& listado, Consulta agregar, int* largo) {
	*largo += 1;
	Consulta* newListado = nullptr; //inicializamos
	newListado = new Consulta[*largo];
	int i = 0;
	while (i < *largo - 1 && *largo - 1 != 0) {
		newListado[i] = listado[i];
		i++;
	}
	newListado[i] = agregar;

	delete[] listado;
	listado = newListado;
}

void agregarContacto(Contacto*& listado, Contacto agregar, int* largo) {
	*largo += 1;
	Contacto* newListado = nullptr;
	newListado = new Contacto[*largo];
	int i = 0;
	while (i < *largo - 1 && *largo - 1 != 0) {
		newListado[i] = listado[i];
		i++;
	}
	newListado[i] = agregar;

	delete[] listado;
	listado = newListado;
}

void agregarMedico(Medico*& listado, Medico agregar, int* largo) {
	*largo += 1;
	Medico* newListado = nullptr;
	newListado = new Medico[*largo];
	int i = 0;
	while (i < *largo - 1 && *largo - 1 != 0) {
		newListado[i] = listado[i];
		i++;
	}
	newListado[i] = agregar;

	delete[] listado;
	listado = newListado;
}

void agregarPaciente(Paciente*& listado, Paciente agregar, int* largo) {
	*largo += 1;
	Paciente* newListado = nullptr;
	newListado = new Paciente[*largo];
	int i = 0;
	while (i < *largo - 1 && *largo-1 !=0) {
		newListado[i] = listado[i];
		i++;
	}
	newListado[i] = agregar;

	delete[] listado;
	listado = newListado;
}


void ordenarConsultas(Consulta*& listado, int* largo) {
	int i, j;
	int cont = 0;
	// auxiliar para el swapeo del ordenamiento
	Consulta auxCons;
	for (i = 0; i < *largo - 1; i++) {
		cont = 0;
		for (j = 0; j < *largo - i - 1; j++) {
			int fecha1 = listado[j].fechaCons.anio * 10000 + listado[j].fechaCons.mes * 100 + listado[j].fechaCons.dia;
			int fecha2 = listado[j + 1].fechaCons.anio * 10000 + listado[j + 1].fechaCons.mes * 100 + listado[j + 1].fechaCons.dia;
			// Hacemos la comparacion
			// Ya pasamos ambas fechas a enteros para compararlas (unsigned int por temas de largo de los numeros)
			// Si no es el mismo DNI, automaticamente los cambiamos
			// Si es el mismo DNI, comparamos las fechas, asi queda con un doble ordenamiento
			if (listado[j].dni_pac < listado[j + 1].dni_pac || (listado[j].dni_pac == listado[j + 1].dni_pac && fecha1 > fecha2)) {
				auxCons = listado[j];
				listado[j] = listado[j + 1];
				listado[j + 1] = auxCons;
				cont++;
			}
		}
		if (cont == 0) {
			break;
		}
	}
}

void filtradoConsultas(Consulta*& listado, Consulta*& archivados, Consulta*& noArchivados, 
	int* largo, int* largoArch, int* largoNoArch) {
	// Primero ordenamos toda la lista de consultas usando una funcion
	ordenarConsultas(listado, largo);
	// El listado ahora esta ordenado por documento y luego por fechas
	fstream fp;
	fstream fp2;

	string fileArchivados = "archivados.csv";
	string fileNoArchivados = "noArchivados.csv";

	fp.open(fileArchivados, ios::out);
	if (!fp.is_open()) {
		return;
	}

	fp2.open(fileNoArchivados, ios::out);
	if (!fp2.is_open()) {
		return;
	}

	// Primero agregamos los encabezados
	fp << "dni_pac , fechaSoli , fechaCons , presento , matriculaMed , rotulo" << endl;
	fp2 << "dni_pac , fechaSoli , fechaCons , presento , matriculaMed" << endl;
	// Guardamos la fecha de hoy para comparar
	// La dejamos en la 0,0,0 en horas para evitar errores
	time_t hoy = time(NULL);
	int i, j, k;
	for (i = 0; i < *largo; i++) {
		// Cuento la cantidad de consultas que tiene el paciente, para luego sumarle a i
		j = i;
		while (listado[j].dni_pac == listado[i].dni_pac) {
			j++;
		}

		// Pasamos a struct tm la ultima consulta registrada del paciente
		// (tomamos desde el comienzo del dia, error minimo y perfectamente ignorable)
		struct tm ultConsTM = { 0,0,0, listado[j - 1].fechaCons.dia,listado[j - 1].fechaCons.mes - 1, listado[j - 1].fechaCons.anio - 1900 };
		time_t ultCons = mktime(&ultConsTM);
		// el -1900 en anio es porque tm tiene en cuenta los anios pasados desde el 1900
		// el -1 en mes es porque el rango va de 0 a 11
		// el j-1 es para que quede posicionado exactamente en la ultima fecha consultada del paciente


		float diferencia = difftime(hoy, ultCons) / (60 * 60 * 24);
		// 60 por segundos en un minuto, 60 por minutos en una hora, 24 por horas en un dia,
		// quedando asi la cantidad de dias entre fechas
		// 
		// Como el error seria minimo, no se tienen en cuenta los años bisiestos en la diferencia
		// (10 dias de diferencia como mucho, ya que la diferencia mas grande es de 42 anios)
		diferencia /= 365;

		if (diferencia >= 10 && !listado[j - 1].presento) {
			unsigned int dniAux = listado[j - 1].dni_pac;
			for (k = j - 1; listado[k].dni_pac == dniAux; k--) {
				agregarConsulta(archivados, listado[k], largoArch);
				fp << listado[k].dni_pac << " , " << listado[k].fechaSoli.dia << "/" << listado[k].fechaSoli.mes << "/" << listado[k].fechaSoli.anio <<
					" , " << listado[k].fechaCons.dia << "/" << listado[k].fechaCons.mes << "/" << listado[k].fechaCons.anio << " , " << listado[k].presento <<
					" , " << listado[k].matriculaMed << " , " << "archivado" << endl;
			}
		}
		else if (diferencia < 10 && !listado[j - 1].presento) {
			agregarConsulta(noArchivados, listado[j-1], largoNoArch);
			fp2 << listado[j-1].dni_pac << " , " << listado[j-1].fechaSoli.dia << "/" << listado[j-1].fechaSoli.mes << "/" << listado[j-1].fechaSoli.anio <<
				" , " << listado[j-1].fechaCons.dia << "/" << listado[j-1].fechaCons.mes << "/" << listado[j-1].fechaCons.anio << " , " << listado[j-1].presento <<
				" , " << listado[j-1].matriculaMed << endl;
		}

		i = j - 1;
	}
	fp.close();
	fp2.close();
}

void paraContactar(Consulta*& noArchivados, Contacto*& listaCont, Medico*& listaMed, Paciente*& listaPac, 
	int* largoNoArch, int* largoCont, int* largoMed, int* largoPac) {
	int h, i, j, k;
	fstream fp;
	string fileContactar = "paraContactar.csv";
	bool flag1, flag2, flag3;

	fp.open(fileContactar, ios::out);
	if (!fp.is_open()) {
		return;
	}
	Paciente auxPac;
	Contacto auxCont;
	Medico auxMed;
	// Primero hacemos los encabezados
	fp << "nombre , apellido , id_os , telefono , matriculaMed , nombreMed , apellidoMed , telefonoMed , especialidad , activo" << endl;
	/*nombre, apellido, teléfono y datos del último médico que los atendió, obra social*/
	for (i = 0; i < *largoNoArch; i++) {
		flag1 = false;
		flag2 = false;
		flag3 = false;
		for (j = 0; j<*largoPac; j++) {
			if (noArchivados[i].dni_pac == listaPac[j].dni) {
				auxPac = listaPac[j];
				flag1 = true;
			}
			if (flag1) {
				break;
			}
		}
		for (k = 0; k<*largoCont; k++) {
			// Vamos a registrar solo el primer numero de telefono
			// que aparezca en nombre del paciente (hay algunos con numeros repetidos)
			if (noArchivados[i].dni_pac == listaCont[k].dni_pac && flag1) {
				auxCont = listaCont[k];
				flag2 = true;
			}
			if (flag2) {
				break;
			}
		}
		for (h = 0; h<*largoMed; h++) {
			if (noArchivados[i].matriculaMed == listaMed[h].matricula && flag1 && flag2) {
				auxMed = listaMed[h];
				flag3 = true;
			}
			if (flag3) {
				break;
			}
		}

		if (flag1 && flag2 && flag3) {
			fp << auxPac.nombre << " , " << auxPac.apellido << " , " << auxPac.id_os << " , " << auxCont.telefono << " , " << auxMed.matricula << " , " <<
				auxMed.nombre << " , " << auxMed.apellido << " , " << auxMed.telefono << " , " << auxMed.especialidad << " , " << auxMed.activo << endl;
		}

	}

	fp.close();
}

void simularSecretaria() {
	string filePathContactar = "paraContactar.csv";
	string filePathContactados = "contactados.csv";
	srand(time(NULL));
	fstream fp;
	fstream fp2;
	// nombre,apellido,id_os,nuevaCons,retorna
	// retorna es booleano
	fp.open(filePathContactar, ios::in);
	if (!fp.is_open()) {
		return;
	}

	fp2.open(filePathContactados, ios::out);
	if (!fp2.is_open()) {
		return;
	}
	// Nos salteamos los encabezados
	string headers = "";
	getline(fp, headers);

	Paciente auxPac;
	bool retorna;
	int obraSocial;
	Fecha nuevaConsulta;


	string line = "", coma = "";
	fp2 << "nombre , apellido , id_os , retorna , nuevaConsulta" << endl;
	while (getline(fp, line)) {
		int aux = rand();
		string auxString = "";
		stringstream inputString(line);

		getline(inputString, auxPac.nombre, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxPac.apellido, ' ');

		getline(inputString, coma, ' ');

		getline(inputString, auxPac.id_os, ' ');

		retorna = aux % 2;
		// 1 = el paciente quiere otro turno
		// 0 = el paciente no quiere otro turno

		nuevaConsulta = { 0,0,0 };

		if (retorna) {
			// Son 6 obras sociales
			// OSDE=0, Italiano=1, Medicus=2, IOSFA=3, Espanyol=4, Aleman=5
			obraSocial = aux % 6;
			switch (obraSocial) {
			case 0:
				auxPac.id_os = "OSDE";
				break;
			case 1:
				auxPac.id_os = "Italiano";
				break;
			case 2:
				auxPac.id_os = "Medicus";
				break;
			case 3:
				auxPac.id_os = "IOSFA";
				break;
			case 4:
				auxPac.id_os = "Espanyol";
				break;
			case 5:
				auxPac.id_os = "Aleman";
				break;
			}

			struct tm hoy;
			time_t t = time(NULL);
			localtime_s(&hoy, &t);

			nuevaConsulta = { aux % 31 + 1,aux % 12 + 1, aux % ((hoy.tm_year + 1900 + 2) - (hoy.tm_year+1900+1) + 1) + (hoy.tm_year + 1900 + 1) };

			if (esBisiesto(nuevaConsulta.anio) && nuevaConsulta.mes == 2 && nuevaConsulta.dia > 29) {
				nuevaConsulta.dia -= 2;
			}
			else if(!esBisiesto(nuevaConsulta.anio) && nuevaConsulta.mes == 2 && nuevaConsulta.dia > 28) {
						nuevaConsulta.dia -= 3;
			}

			if ((nuevaConsulta.mes == 4 || nuevaConsulta.mes == 6 || nuevaConsulta.mes == 9 || nuevaConsulta.mes == 11) && nuevaConsulta.dia>30) {
				nuevaConsulta.dia--;
			}

		}
		fp2 << auxPac.nombre << " , " << auxPac.apellido << " , " << auxPac.id_os << " , " << 
			retorna << " , " << nuevaConsulta.dia << "/" << nuevaConsulta.mes << "/" << nuevaConsulta.anio << endl;
	}

	fp.close();
	fp2.close();
}

bool esBisiesto(int anio) {
	bool aux;
	if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
		aux = true;
	}
	else {
		aux = false;
	}
	return aux;
}

bool chequearDNI(string DNI)
{
	int tam = DNI.length();
	bool flag = true;
	if (tam == 7 || tam == 8)
	{
		for (int i = 0; i < tam; i++)
		{//si no son numeros, devuelve falso
			if (DNI[i] != '0' || DNI[i] != '1' DNI[i] != '2' || DNI[i] != '3' || DNI[i] != '4' || DNI[i] != '5' || DNI[i] != '6' || DNI[i] != '7' || DNI[i] != '8' || DNI[i] != '9')
			{
				flag = false;
				break;
			}
		}
	}
	else
	{
		flag = false;
	}
	
	return flag;
}