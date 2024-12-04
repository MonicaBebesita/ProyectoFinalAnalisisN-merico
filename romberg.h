

/**
* @file
* @brief Contiene las rutinas del  metodo romberg
* @author Monica alejandra Castellanos
* @author Ashlee Vanessa Campaz
* @copyright MIT License
*/


#ifndef ROMBERG_H
#define ROMBERG_H

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include "trapecio.h"
#include "expresion.h"

using integracion::trapecio;
using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;
const double PI = 3.141592653589793;



	namespace integracion {
		
		/**
		* @brief Resultado de integracion por Romberg
		*/
		struct resultado_romberg {
			double valor;
			int k;
			double error;
			resultado_romberg(double valor, int k, double error)
				: valor(valor), k(k), error(error) {}
		};
		
		class Romberg {
		private:
			string f_str;
			double a;
			double b;
		public:
			/**
			* @brief Crear una instancia de la clase
			* @param f_str Expresión de la función a integrar
			* @param a Límite inferior
			* @param b Límite superior
			*/
			Romberg(string f_str, double a, double b) : f_str(f_str), a(a), b(b) {}
			
			/**
			* @brief Calcula la integral con k aproximaciones
			* @param k Número de aproximaciones
			* @return resultado de la integración
			*/
			resultado_romberg calcular(int k) {
				if (k < 2) {
					throw std::invalid_argument("El número de aproximaciones (k) debe ser mayor o igual a 2.");
				}
				
				size_t i, j;
				
				// Crear la matriz de k filas
				vector<vector<double>> m(k);
				
				// Redimensionar las filas
				for (i = 0; i < (size_t)k; i++) {
					m[i].resize(k - i);
				}
				
				// Llenar la primera columna de la matriz
				for (i = 0; i < (size_t)k; i++) {
					// Con trapecio (f_str, a, b, n = 2^i)
					int n = pow(2, i);
					trapecio t(f_str, a, b, n);
					m[i][0] = t.calcular();
				}
				
				// Realizar las combinaciones
				for (j = 1; j < (size_t)k; j++) {
					int po = pow(4, j);
					for (i = 0; i < (k - j); i++) {
						m[i][j] = ((double)(po) / (po - 1)) * m[i + 1][j - 1]
							- ((double)(1.0) / (po - 1)) * m[i][j - 1];
					}
				}
				
				// Imprimir la Matriz
				cout << "Matriz de aproximaciones:\n";
				for (i = 0; i < (size_t)k; i++) {
					for (j = 0; j < m[i].size(); j++) {
						cout << std::setprecision(10) << std::setw(20) << m[i][j] << " ";
					}
					cout << endl;
				}
				
				// Calcular el error de la integral
				double v_real = m[0][k - 1];
				double v_estimado = m[0][k - 2];
				double error = (v_real != 0.0) ? fabs((v_real - v_estimado) / v_real) * 100.0 : 0.0;
				
				return resultado_romberg{ v_real, k, error };
			}
		};
	}
	

#endif


