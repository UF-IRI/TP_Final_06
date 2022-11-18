#include "gmock/gmock.h"
#include "iri.cpp"
#include "funciones.h"

namespace Casos_Base::tests {
	TEST(Casos_Base, Test_Caso1) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) {
		ASSERT_THAT(1, 1);
	}
}

namespace PacienteTest::tests {

	TEST(PacienteTest, pruebaAgregarPaciente) {
		// Testeamos si el elemento que queremos agregar fue agregado correctamente
		// (valga la redundancia)
		int n = 0;
		int* largo = &n;
		Paciente* lista = new Paciente[*largo];
		Paciente auxPac;

		auxPac.dni = 42526433;
		auxPac.nombre = "Matias";
		auxPac.apellido = "Larrosa";
		auxPac.sexo = 'M';
		auxPac.natalicio.dia = 27;
		auxPac.natalicio.mes = 02;
		auxPac.natalicio.anio = 2001;
		auxPac.estado = "fallecido";
		auxPac.id_os = "IOSFA";

		agregarPaciente(lista, auxPac, largo);

		EXPECT_EQ(lista[0].dni, auxPac.dni);
		EXPECT_EQ(lista[0].nombre, auxPac.nombre);
		EXPECT_EQ(lista[0].apellido, auxPac.apellido);
		EXPECT_EQ(lista[0].sexo, auxPac.sexo);
		EXPECT_EQ(lista[0].natalicio.dia, auxPac.natalicio.dia);
		EXPECT_EQ(lista[0].natalicio.mes, auxPac.natalicio.mes);
		EXPECT_EQ(lista[0].natalicio.anio, auxPac.natalicio.anio);
		EXPECT_EQ(lista[0].estado, auxPac.estado);
		EXPECT_EQ(lista[0].id_os, auxPac.id_os);
		EXPECT_EQ(*largo, 1);

		delete[] lista;
	}

	TEST(PacienteTest, pruebaCargarPacientes) {
		// Testeamos la primera y la ultima posicion de una lista cargada de pacientes
		// Si ambos estan bien significa que el proceso de leer el archivo fue exitoso

		int n = 0;
		int* largo = &n;
		Paciente* lista = new Paciente[*largo];
		string filePath = (BASE_PATH + "../data_files/input/Pacientes.csv");
		cargarDatosPacientes(filePath, lista, largo);
		EXPECT_EQ(lista[0].dni, 10242582);
		EXPECT_EQ(lista[0].nombre, "Cersty");
		EXPECT_EQ(lista[0].apellido, "Thurston");
		EXPECT_EQ(lista[0].sexo, 'F');
		EXPECT_EQ(lista[0].natalicio.dia, 9);
		EXPECT_EQ(lista[0].natalicio.mes, 6);
		EXPECT_EQ(lista[0].natalicio.anio, 1970);
		EXPECT_EQ(lista[0].estado, "internado");
		EXPECT_EQ(lista[0].id_os, "Medicus");

		EXPECT_EQ(lista[*largo - 1].dni, 48363884);
		EXPECT_EQ(lista[*largo - 1].nombre, "Yelle");
		EXPECT_EQ(lista[*largo - 1].apellido, "Mangum");
		EXPECT_EQ(lista[*largo - 1].sexo, 'F');
		EXPECT_EQ(lista[*largo - 1].natalicio.dia, 29);
		EXPECT_EQ(lista[*largo - 1].natalicio.mes, 1);
		EXPECT_EQ(lista[*largo - 1].natalicio.anio, 2002);
		EXPECT_EQ(lista[*largo - 1].estado, "n/c");
		EXPECT_EQ(lista[*largo - 1].id_os, "Italiano");

		delete[] lista;
	}
}

namespace auxiliaresTest::tests {
	TEST(auxiliaresTest, pruebaOrdenarConsultas) {
		int n = 0;
		int* largo = &n;
		Consulta* lista = new Consulta[*largo];
		string filePath = (BASE_PATH + "../data_files/input/Consultas.csv");

		cargarDatosConsultas(filePath,lista,largo);

		ordenarConsultas(lista,largo);
		/*
		typedef struct consulta {
			unsigned int dni_pac;
			Fecha fechaSoli;
			Fecha fechaCons;
			bool presento;
			string matriculaMed;
		}Consulta;
		*/

		EXPECT_EQ(lista[0].dni_pac, 48363884);
		EXPECT_EQ(lista[0].fechaSoli.dia, 6);
		EXPECT_EQ(lista[0].fechaSoli.mes, 11);
		EXPECT_EQ(lista[0].fechaSoli.anio , 1974);
		EXPECT_EQ(lista[0].fechaCons.dia, 14);
		EXPECT_EQ(lista[0].fechaCons.mes, 12);
		EXPECT_EQ(lista[0].fechaCons.anio , 1974);
		EXPECT_EQ(lista[0].presento, true);
		EXPECT_EQ(lista[0].matriculaMed, "59-911-1635");

		EXPECT_EQ(lista[*largo-1].dni_pac, 10242582);
		EXPECT_EQ(lista[*largo - 1].fechaSoli.dia, 25);
		EXPECT_EQ(lista[*largo - 1].fechaSoli.mes, 3);
		EXPECT_EQ(lista[*largo - 1].fechaSoli.anio, 1991);
		EXPECT_EQ(lista[*largo - 1].fechaCons.dia, 5);
		EXPECT_EQ(lista[*largo - 1].fechaCons.mes, 10);
		EXPECT_EQ(lista[*largo - 1].fechaCons.anio, 1991);
		EXPECT_EQ(lista[*largo - 1].presento, false);
		EXPECT_EQ(lista[*largo - 1].matriculaMed, "49-626-8557");

		delete[] lista;
	}

	TEST(auxiliaresTest, pruebaEsBisiesto) {
		EXPECT_EQ(esBisiesto(2000), true);
		EXPECT_EQ(esBisiesto(2004), true);
		EXPECT_EQ(esBisiesto(1840), true);
		EXPECT_EQ(esBisiesto(2024), true);
		EXPECT_EQ(esBisiesto(1900), false);
		EXPECT_EQ(esBisiesto(2001), false);
		EXPECT_EQ(esBisiesto(1800), false);
		EXPECT_EQ(esBisiesto(2022), false);
	}
}