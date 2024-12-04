/**
* @file
* @brief Contiene de las rutinas de metodol de trapecio 
* @author Monica alejandra Castellanos
* @author Ashlee Vanessa Campaz
* @copyright MIT License
*/


#ifndef TRAPECIO_H
#define TRAPECIO_H

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

// hay dos sabores, cuando nos dan la función y cuando nos dan la tabla con datos
namespace integracion{
	/**
	* @brief Metodo del trapecio
	*/
	class trapecio{
	public:
		/**
		* @brief Crear una nueva instancia del método
		* @param f_str Texxto de la funcion a integrar
		* @param a Límite inferior
		* @param b Límite superior
		* @param n Cantidad de segmentos
		*/
		trapecio(string f_str, double a, double b, int n){
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
		trapecio(vector<double>x, vector<double>y){
			if(x.size() != y.size()){
				return;
			}
			this->x = x;
			this->y = y;
		}
		
		/**
		* brief Calcyla el valor de la integral en el intervalo dado
		*/
		double calcular(){
			// Para el metodo del trapecio se requieren al menos 2 valores de X
			if(x.size() < 2){
				return NAN;
			}
			if(x.size() != y.size()){
				return NAN;
			}
			int n = (int)x.size() - 1;
			
			double sum = y[0] + y[n];
			
			double sum_inter = 0.0f;
			
			for(int i = 1; i < n; i++){
				
				sum_inter += y[i];
			}
			double b = x[n];
			double a = x[0];
			return (b - a)*(y[0] + 2.0f * sum_inter + y[n])/(double)(2*n);
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
			
	private:
		vector<double>x; // Valores de la variable independiente
		vector<double>y; // Valores de la variable dependiente
	};
};

#endif
