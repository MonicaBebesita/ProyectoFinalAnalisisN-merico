#ifndef SIMPSON13_H
#define SIMPSON13_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

#include "expresion.h"

using std::string;
using std::vector;
using std::ostream;
using std::endl;
using std::cout;

namespace integracion{
	class simpson13{
	public:
		/**
		* @brief Crear una nueva instancia del método
		* @param f_str Texxto de la funcion a integrar
		* @param a Límite inferior
		* @param b Límite superior
		* @param n Cantidad de segmentos
		*/
		simpson13(string f_str, double a, double b, int n){
			// Simpson 1/3 requiere que la cantidad de segmentos sea par
			if(n%2 != 0){
				return;
			}
			int i = 0;
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
		/**
		* @brief Crea una nueva instancia de etodo con una tabla de datos
		* @param x Valor de la variable independiente
		* @param y Valor de la variable dependiente
		*/
		simpson13(vector<double>x, vector<double>y){
			// Si la cantidad de segmentos es par, la cantidad de segmentos en x e y es impar
			if(x.size() % 2 == 0){
				return;
			}
			this->x = x;
			this->y = y;
		}
		
		/**
		* brief Calcyla el valor de la integral en el intervalo dado
		*/
		double calcular(){
			// 
			if(x.size() < 2 || x.size() % 2  == 0){
				return NAN;
			}
			
			// cantidad de segmentos = tamano del vector - 1 
			int n = (int)x.size() - 1;
			
			double b = x[n];
			double a = x[0];
			
			double h = (b-a)/(double)n;
			
			double sum_pares = 0.0f;
			double sum_impares = 0.0f;
			
			for(size_t i = 1; i < n; i++){
				if(i % 2 == 0){
					//cout << "Sum par " << i << " : " <<x[i] << endl;
					sum_pares += y[i];
				}else {
					//cout << "Sum impar " << i << " : " <<x[i] << endl;
					sum_impares += y[i];
				}
			}
			
			return (h/(double)3.0f)*(y[0] + 4.0f*sum_impares + 2.0f*sum_pares + y[n]);
		}
			/**
			* Envia la tabla de datos a un flujo de salida
			
			*/
		void imprimir_tabla(ostream & os){
			os << std::setw(15) << "x"
					<< std::setw(15) << "y" << endl;
			for(size_t i = 0; i < x.size(); i++){
				os << std::setw(15) << x[i];
				os << std::setw(15) << y[i] << endl;
			}
		}
			
			/**
			* @brief Calcula el error relativo porcentual dado un valor real conocido.
			* @param valor_real Valor exacto o de referencia para comparar.
			* @return Error relativo porcentual.
			*/
		double calcular_error(double valor_real) {
				if (valor_real == 0) {
					throw std::invalid_argument("El valor real no puede ser cero para calcular el error relativo porcentual.");
				}
				
				double resultado_actual = this->calcular();
				
				return fabs((valor_real - resultado_actual) / valor_real) * 100.0;
		}
				
	private:
					vector<double>x; // Valores de la variable independiente
					vector<double>y; // Valores de la variable dependiente
		
		
	};
};

#endif
