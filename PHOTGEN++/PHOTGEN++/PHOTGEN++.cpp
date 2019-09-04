
#include "pch.h" //Estas librerias siempre tienen que ir hasta arriba, si no da un error
#include <iostream>

#include <string>
#include <stdlib.h>
#include <string.h>
#include<cstdlib> //Libreria para cambiar el color de la consola.
#include <fstream>
using namespace std;
/*
	Apunter personales
		\t Significa un tab en consola
		Simbolos particulares usados ═
*/

static int tema = 0; // variable para cambiar el tema

//Defincion de funciones abstractas
void generarTitulo();
void generarMenu();
void lectura();
void abrirArchivo();
//----------------------------------
void generarColor(int color) 
{
	if (color == 0)
	{
		system("color f0");
		tema = 1;
	}
	else if(color==1)
	{
		system("color 02");
		tema = 2;
	}
	else
	{
		system("color 1f");
		tema = 0;
	}
}
void opciones(int opc) 
{
	system("cls");
	generarTitulo();
	if (opc==49)
	{
		//Codigo para la opción 1
		abrirArchivo();
	}
	else if (opc == 50)
	{
		//Codigo para la opción 2
	}
	else if (opc == 51)
	{
		//Codigo para la opción 3
	}
	else if (opc == 52)
	{
		//Codigo para la opción 4
	}
	else if (opc == 53)
	{
		//Codigo para la opción 5
	}
	else if (opc==54) 
	{
		//Codigo para la opción 6
	}
	else if (opc == 55)
	{
		//Codigo para la opción 7
		generarColor(tema);
		system("cls");
		generarTitulo();
		generarMenu();
	}
	else if (opc == 56)
	{
		//Codigo para la opción 8
	}
	else 
	{
		system("cls");
		printf("\n\t\t\t\t\t OPCION INVALIDA!!\n");
		generarTitulo();
		generarMenu();
		
	}
}
void generarLinea(int tamaño)
{
	for (int i = 0; i < tamaño; i++)
	{
		printf("%c", 205);
	}
}
void generarTitulo()
{
	printf("\n\n \t\t");
	printf("%c", 201);
	generarLinea(66);
	printf("%c", 187);
	printf("\n\t\t%c\t\t\t    PHOTOGEN++", 186);
	printf("\t\t\t\t   %c", 186);
	printf("\n\t\t");
	printf("%c", 200);
	generarLinea(66);
	printf("%c", 188);
	printf("\n\n\n");
} 
void generarMenu()
{
	int entrada ;
	char input;
	
	printf("\n\t\t\t\t\t 1. Insertar imagen\n");
	printf("\n\t\t\t\t\t 2. Seleccionar imagen\n");
	printf("\n\t\t\t\t\t 3. Aplicar filtros\n");
	printf("\n\t\t\t\t\t 4. Edici%cn manual\n",162);
	printf("\n\t\t\t\t\t 5. Exportar imagen\n");
	printf("\n\t\t\t\t\t 6. Reportes\n");
	printf("\n\t\t\t\t\t 7. Cambiar de tema\n");
	printf("\n\t\t\t\t\t 8. Salir\n");
	printf("\n\t\t\t\t\t Entrada %c ",175);
	cin.clear();
	cin >> input;
	entrada = (int)input;
	opciones(entrada);
	
}
void lectura() 
{
	//std::ifstream archivo;
	//archivo.open("RUTA",ios::in)//abrimos el archivo en modo lectura  
	
}
void abrirArchivo()
{
	string ruta="";
	printf("Ingrese la ruta del archivo: ");
	cin.ignore();
	getline(cin,ruta);
	cout << "Ruta: " << ruta;
	system("pause");
}
int main()
{
	system("mode con: cols=100 lines=50");
	generarColor(tema);//Establecer color de consola. X color de fondo y Y color de letras
	generarTitulo();
	generarMenu();
}


