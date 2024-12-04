/**
* @file
* @brief Contiene los menus 
* @author Monica alejandra Castellanos
* @author Ashlee Vanessa Campaz
* @copyright MIT License
*/

#include<iostream>
using namespace std;

#include "caso.h"
void esperar();
void mostrarMenu();
void mostrarSubMenuIntegracion();
void menuDiferenciacion();
void leerDatos(int tipo);

int main (int argc, char *argv[]) {

	
	int opcion = 0;
	
	do {
		mostrarMenu();
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: // Submenú Integración
			mostrarSubMenuIntegracion();
			break;
		case 2: // submenu Diferenciacion
			menuDiferenciacion();
			break;
		case 3: // Salir
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opción invalida, intente de nuevo.\n";
			break;
		}
	} while (opcion != 3);

	return 0;
}

// Menú principal
void mostrarMenu() {
	system("cls");
	cout << "\n========== MENU ==========\n";
	cout << "1. Integracion\n";
	cout << "2. Derivacion\n";
	cout << "3. Salir\n";
	cout << "===========================\n";
}

// Submenú Integración
void mostrarSubMenuIntegracion() {
	int opcion = 0;
	
	do {
		system("cls");
		cout << "\n--- Metodos de Integracion ---\n";
		cout << "1. Simpson (1/3)\n";
		cout << "2. Simpson (3/8)\n";
		cout << "3. Romberg\n";
		cout << "4. Volver al menu principal\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			system("cls");
			caso_1_simpson13();
			esperar();
			break;
		case 2:
			system("cls");
			caso_1_simpson38();
			esperar();
			
			break;
		case 3:
			system("cls");
			caso_1_romberg();
			esperar();
			break;
		case 4:
			cout << "Volviendo al menu principal...\n";
			break;
		default:
			cout << "Opción invalida, intente de nuevo.\n";
			break;
		}
	} while (opcion != 4);
}

void leerDatos(int tipo){
	cout<<"----Calcular derivadas de funcion e^x*sen(x)----\n"<<endl;
	int orden; 
	double x;
	double h; 
	do{
		cout<<"Ingrese el orden (1 a 4):";
		cin >> orden;
		if(orden>4 || orden<1){
			cout<<"El orden es invalido.\n"<<endl;
		}
	}while(orden>4 || orden<1);
	cout<<"Ingrese el valor de x:";
	cin>> x;
	do{
		cout<<"Ingrese el paso (debe ser mayor a 0 y menor a 1):";
		cin >> h; 
		if(h<0 || h>1){
			cout<<"El paso es invalido."<<endl;
		}
	}while(h<0 || h>1); 
	
	system("clear");
	if(tipo==1){
		caso_primeras_diferencias_general(x, h, orden);
	}
	else{
		caso_segundas_diferencias_general(x, h,orden);
	}
} 	
	
void menuDiferenciacion(){
	
	int opcion;
	do{
		system("clear");
		cout<<"----MENU DIFERENCIACION---\n"<<
			"1.Primeras diferencias\n"<<
			"2.Segundas diferencias\n"<<
			"3.Volver atras\ningrese su opcion:";
		cin>> opcion;
		
		switch(opcion){
		case 1:
			system("clear");
			leerDatos(1);
			esperar();
			break;
		case 2:
			system("clear");
			leerDatos(2);
			esperar();
			break;
		case 3:
			break;
		default:
			cout<<"Opcion invalida."<<endl; 
		}
		
	}while(opcion!=3);
	
}

void esperar() {
	while (cin.get() != '\n');// Limpia el buffer
	cout << "Presiona enter para continuar...";
	cin.get();  // Espera a que el usuario presione una tecla
}


	
	


