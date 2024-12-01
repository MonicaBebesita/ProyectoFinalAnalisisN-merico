#ifndef SIMPSON_H
#define SIMPSON_H
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>


#include "simpson38.h"
#include "simpson13.h"
#include "expresion.h"

using std::string;
using std::vector;
using std::ostream;
using integracion::simpson38;
using integracion::simpson13;
using std::endl;
using std::cout;

namespace integracion{
	class simpson{
	public:
		int n;
		simpson(string f_str, double a, double b, int n){
			// Simpson requiere que la cantidad de segmentos sea par
			this->n = 0;
			if(n<3){
				return;
			}
			this->n = n;
		int i=0;
	// Crear el evaluador de expresiones
			expression f(f_str);
			// calcular el paso h
			double h = (b - a)/(double)n;
			// construir la tabla de datos
			for(double xi = a; i <= n; i++, xi += h){
				x.push_back(xi);
				y.push_back(f(xi));
			}
		}
		
		
		
		simpson(vector<double>x, vector<double>y){
			int n= (int)x.size()-1;
			// Si la cantidad de segmentos es par, la cantidad de segmentos en x e y es impar
			if(n<3){
				return;
			}
			if(x.size() != y.size()){
				return;
				
			}
			this->n = n;
			this->x = x;
			this->y = y;
		}
			
			
		double calcular(){
				// si la cantidad de segmentos es par, aplicar simpson 1/#
				
			if(n % 2==0){
				cout<< "Calcular usando Simpson 1/3 con "<<n<< "segmentos"<<endl;
				simpson13 (x,y).calcular();
				return NAN;
				
			}
				//si la cantidad de segmentos es multiplo de 3 he impar aplicar 3/8 simpson
			if(n % 3==0){
				cout<< "Calcular usando Simpson 3/8 con "<<n<< "segmentos"<<endl;
				return simpson38 (x,y).calcular();
				return NAN;
				
			}
				
				
				
				//dividir la cantidad de segmentos en 2 y buscar el multiplo de 3 impar mas cercano
			cout<<"Calcular la integral con"<<n<<"segmentos"<<endl;
			int limite=n/2;
			cout<<"mitad del intervalo"<<limite<<endl;
			if(limite %3 !=0){
				limite++;
				
			}
			cout<<"limite: "<<limite<<endl;
			if(limite % 2==0){
				limite +=3;
				
			}
			int n_1=n-limite;
			vector<double>x_1(x.begin(), x.begin()+(n_1+1));
			vector<double>x_2(x.begin()+n_1, x.end());
			vector<double>y_1;(y.begin(), y.begin()+(n_1+1));
			vector<double>y_2(y.begin()+n_1, y.end());
			
			cout<<"primer valor: "<<x_1[0]<<endl;
			cout<<"primer valor: "<<x_1[x_1.size()-1]<<endl;
			cout<<"Calcular integral combinando simpson 1/2 con"<<n<<" y 3/8  con"<<limite<<"segmentos"<<endl;
			
			
			return simpson13(x_1, y_1).calcular() +simpson38(x_2, y_2).calcular();
		
		}
		
		void imprimir_tabla(ostream & os){
			os << std::setw(15) << "x"
				<< std::setw(15) << "y" << endl;
			for(size_t i = 0; i < x.size(); i++){
				os << std::setw(15) << x[i];
				os << std::setw(15) << y[i] << endl;
			}
			
		}
		
				
	private:
		vector<double>x; // Valores de la variable independiente
		vector<double>y; // Valores de la variable dependiente
					
					

		
	
		
	};
};






#endif
