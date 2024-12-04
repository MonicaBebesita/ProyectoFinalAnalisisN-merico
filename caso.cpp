
/**
* @file
* @brief Contiene los casos de integracion y diferenciacion 
* @author Monica alejandra Castellanos
* @author Ashlee Vanessa Campaz
* @copyright MIT License
*/

#include "caso.h"
#include "trapecio.h"
#include "simpson13.h"
#include "simpson38.h"
#include "romberg.h"
#include "primeras_diferencias.h"
#include "segundas_diferencias.h"
#include "expresion.h"
#include <cmath>
using std::cout;
using std::endl;




void caso_1_simpson38(){
	using integracion::simpson38;
	
	string f_str = "-sen(3*x)-e^x -3.75*x^5 +18.5 *x^3 +25.6 *x";
	double a = -2.4592133859032f;            // Límite inferior
	double b =2.4226737875573f; 
	int n = 15;
	
	// Crear la instancia del trapecio
	simpson38 i(f_str,a , b , n);
	
	// Imprimir tabla de datos
	i.imprimir_tabla(cout);
	
	// Calcular el valor de la integral
	double valor  = i.calcular();
	double error= i.calcular_error_teorico("-81*sin(3*x)-e^x-450*x");
	// Imprimir el resultado por pantalla
	cout<<">>>SIMPSON (3/8)<<<"<< endl;
	cout <<std::fixed << std::setprecision(10) <<  "El valor de la integral de "
		<< f_str
		<< " en el intervalo ["
		<< a
		<< ","
		<< b
		<< "]"
		<< " con "
		<< n
		<< " segmentos "
		<<"es:"
		<< valor
		<<" Con un error de: "
		<<error
		<< endl;
}
		
void caso_1_simpson13(){
	using integracion::simpson13;
	
	string f_str = "-sen(3*x)-e^x -3.75*x^5 +18.5 *x^3 +25.6 *x";
	double a = -2.4592133859032f;            // Límite inferior
	double b =2.4226737875573f; 
	int n = 16;
	
	
	simpson13 i(f_str,a , b , n);
	
	// Imprimir tabla de datos
	i.imprimir_tabla(cout);
	
	// Calcular el valor de la integral
	double valor  = i.calcular();
	double error= i.calcular_error_teorico("-81*sin(3*x)-e^x-450*x");
	// Imprimir el resultado por pantalla
	cout<<">>>SIMPSON (1/3)<<<"<< endl;
	cout <<std::fixed << std::setprecision(10) <<  "El valor de la integral de "
		<< f_str
		<< " en el intervalo ["
		<< a
		<< ","
		<< b
		<< "]"
		<< " con "
		<< n
		<< " segmentos "
		<<"es:"
		<< valor
		<<" Con un error de: "
		<<error
		<< endl;
	
}

void caso_1_romberg() {
	using integracion::Romberg;
	using integracion::resultado_romberg;
	
	string f_str = "-sin(3*x)-  (e^(x)) - (3.75*(x^(5))) +(18.5 *(x^(3))) +(25.6*x)"; // La función a integrar
	double a = -2.4592133859032f;            // Límite inferior
	double b =2.4226737875573f;       // Límite superior
	int k = 7;                 // Número de aproximaciones
	
	cout << "Metodo de Romberg\n";
	
	try {
		
		Romberg r(f_str, a, b);
		resultado_romberg rs = r.calcular(k);
		
		cout << "Función utilizada: " << f_str << endl;
		cout << "Numero de aproximaciones: " << k << endl;
		cout <<std::fixed << std::setprecision(10) << "Resultado de la integración por Romberg: " << rs.valor << endl;
		cout << "Con un error de: " << rs.error << "%\n";
	}
	catch (const std::exception& e) {
		cout << "Error: " << e.what() << endl;
	}
}

void caso_primeras_diferencias_general(double x, double h, int orden){
	using diferenciacion::p_diferenciacion;
	
	string f_str = "e^(x)*sin(x)";
	p_diferenciacion pd(f_str,orden);
	pd.calcular(x,h,1);
	pd.imprimir();
	pd.calcular(x,h,0);
	pd.imprimir();
	pd.calcular(x,h,-1);
	pd.imprimir();
}
void caso_segundas_diferencias_general(double x, double h, int orden){
	using diferenciacion::s_diferenciacion;
	string f_str = "e^(x)*sin(x)";
	s_diferenciacion sd(f_str,orden);
	sd.calcular(x,h,1);
	sd.imprimir();
	sd.calcular(x,h,0);
	sd.imprimir();
	sd.calcular(x,h,-1);
	sd.imprimir();
}
