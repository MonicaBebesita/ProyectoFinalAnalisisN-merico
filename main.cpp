/**
* @file
* @brief Pueba de los metodos de integracion
* @author 
* @copyright MIT License
*/

#include<iostream>
using namespace std;

#include "caso.h"
void esperar();
void mostrarMenu();
void mostrarSubMenuIntegracion();
int main (int argc, char *argv[]) {
	// Caso 1 - Método del trapecio
	//caso_1_trapecio();
	//caso_1_simpson38();
	caso_1_simpson13();
	//caso_1_romberg();
	
/**	int opcion = 0;
	
	do {
		mostrarMenu();
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: // Submenú Integración
			mostrarSubMenuIntegracion();
			break;
		case 2: // Derivación (aquí puedes agregar lógica en el futuro)
			cout << "Opción de derivacion no implementada aun.\n";
			esperar();
			break;
		case 3: // Salir
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opción invalida, intente de nuevo.\n";
			break;
		}
	} while (opcion != 3);
**/
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
	
void esperar() {
	while (cin.get() != '\n');// Limpia el buffer
	cout << "Presiona cualquier tecla para continuar...";
	cin.get();  // Espera a que el usuario presione una tecla
}
	
	
	


