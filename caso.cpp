#include "caso.h"
#include "trapecio.h"
#include "simpson.h"
#include "simpson38.h"
#include "romberg.h"
#include "expresion.h"
using std::cout;
using std::endl;

void caso_1_trapecio(){
	using integracion::trapecio;
	
	string f_str = "e^(x^2)";
	double a = 0.0f;
	double b = 1.0f;
	int n = 5;
	
	// Crear la instancia del trapecio
	trapecio t(f_str,a , b , n);
	
	// Imprimir tabla de datos
	t.imprimir_tabla(cout);
	
	// Calcular el valor de la integral
	double valor  = t.calcular();
	
	// Imprimir el resultado por pantalla
	cout << "El valor de la integral de "
		<< f_str
		<< " en el intervalo ["
		<< a
		<< ","
		<< b
		<< "] es:"
		<< valor
		<< endl;
}

void caso_1_simpson(){
	using integracion::simpson;
	
	string f_str = "e^(x^2)";
	double a = 0.0f;
	double b = 1.0f;
	int n = 10.0f;
	
	// Crear la instancia del trapecio
	simpson i(f_str,a , b , n);
	
	// Imprimir tabla de datos
	i.imprimir_tabla(cout);
	
	// Calcular el valor de la integral
	double valor  = i.calcular();
	
	// Imprimir el resultado por pantalla
	cout << "El valor de la integral de "
		<< f_str
		<< " en el intervalo ["
		<< a
		<< ","
		<< b
		<< "] es:"
		<< valor
		<< endl;
}
	void caso_1_simpson38(){
		using integracion::simpson38;
		
		string f_str = "cos(4*x)-0.69*x^(5)+6.13*x^(4)+3.68*x^(3)-11.2*x^(2)";
		double a = -1.5088908961715f;            // Límite inferior
		double b =9.2706466711195f; 
		int n = 15;
		
		// Crear la instancia del trapecio
		simpson38 i(f_str,a , b , n);
		
		// Imprimir tabla de datos
		i.imprimir_tabla(cout);
		
		// Calcular el valor de la integral
		double valor  = i.calcular();
		double error= i.calcular_error(14762.100492858563);
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
			<<"%"
			<< endl;
	}
		
		
		
		
		
		void caso_1_simpson13(){
			using integracion::simpson13;
			
			string f_str = "cos(4*x)-0.69*x^(5)+6.13*x^(4)+3.68*x^(3)-11.2*x^(2)";
			double a = -1.5088908961715f;            // Límite inferior
			double b =9.2706466711195f; 
			int n = 16;
			
			
			simpson13 i(f_str,a , b , n);
			
			// Imprimir tabla de datos
			i.imprimir_tabla(cout);
			
			// Calcular el valor de la integral
			double valor  = i.calcular();
			double error= i.calcular_error(14762.100492858563);
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
				<<"%"
				<< endl;
			
		}
			
			
			void caso_1_romberg() {
				using integracion::Romberg;
				using integracion::resultado_romberg;
				
				string f_str = "cos(4*x)-0.69*x^(5)+6.13*x^(4)+3.68*x^(3)-11.2*x^(2)"; // La función a integrar
				double a = -1.5088908961715f;            // Límite inferior
				double b =9.2706466711195f;       // Límite superior
				int k = 15;                 // Número de aproximaciones
				
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
			
			
			
