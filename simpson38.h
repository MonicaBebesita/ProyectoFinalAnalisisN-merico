#ifndef SIMPSON38_H
#define SIMPSON38_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "expresion.h"

using std::string;
using std::vector;
using std::ostream;
using std::endl;
using std::cout;

namespace integracion {
	class simpson38 {
	public:
		/**
		* @brief Crear una nueva instancia del método Simpson 3/8
		* @param f_str Texto de la función a integrar
		* @param a Límite inferior
		* @param b Límite superior
		* @param n Cantidad de segmentos (debe ser múltiplo de 3)
		*/
		simpson38(string f_str, double a, double b, int n) {
			// Validar que la cantidad de segmentos sea válida (múltiplo de 3 y mayor o igual a 3)
			if (n < 3 || n % 3 != 0) {
				throw std::invalid_argument("La cantidad de segmentos debe ser múltiplo de 3 y mayor o igual a 3.");
			}
			
			expression f(f_str);  // Crear el evaluador de expresiones
			double h = (b - a) / static_cast<double>(n);  // Calcular el paso h
			
			// Construir la tabla de datos
			for (int i = 0; i <= n; ++i) {
				double xi = a + i * h;
				x.push_back(xi);
				y.push_back(f(xi));
			}
		}
		
		/**
		* @brief Crear una nueva instancia usando una tabla de datos
		* @param x Valores de la variable independiente
		* @param y Valores de la variable dependiente
		*/
		simpson38(vector<double> x, vector<double> y) {
			if (x.size() < 4 || (x.size() - 1) % 3 != 0) {
				throw std::invalid_argument("La cantidad de puntos debe ser mayor o igual a 4 y el número de segmentos debe ser múltiplo de 3.");
			}
			
			if (x.size() != y.size()) {
				throw std::invalid_argument("Los vectores x e y deben tener el mismo tamaño.");
			}
			
			this->x = x;
			this->y = y;
		}
		
		/**
		* @brief Calcula el valor de la integral en el intervalo dado
		* @return Valor aproximado de la integral
		*/
		double calcular() {
			if (x.size() < 4 || (x.size() - 1) % 3 != 0) {
				throw std::logic_error("Los datos no cumplen con los requisitos del método Simpson 3/8.");
			}
			
			int n = static_cast<int>(x.size()) - 1;
			double h = (x[n] - x[0]) / static_cast<double>(n);
			
			double sum_1 = 0.0, sum_2 = 0.0, sum_3 = 0.0;
			
			// Sumas parciales
			for (int i = 1; i < n; ++i) {
				if (i % 3 == 0) {
					sum_3 += y[i];
				} else {
					sum_1 += y[i];
				}
			}
			
			return (3.0 * h / 8.0) * (y[0] + 3.0 * sum_1 + 2.0 * sum_3 + y[n]);
		}
		
		/**
		* @brief Imprime la tabla de datos
		* @param os Flujo de salida
		*/
		void imprimir_tabla(ostream &os) {
			os << std::setw(15) << "x" << std::setw(15) << "y" << endl;
			for (size_t i = 0; i < x.size(); ++i) {
				os << std::setw(15) << x[i];
				os << std::setw(15) << y[i] << endl;
			}
		}
		
		/**
		* @brief Calcula el error relativo porcentual dado un valor real conocido
		* @param valor_real Valor exacto o de referencia para comparar
		* @return Error relativo porcentual
		*/
		double calcular_error(double valor_real) {
			if (valor_real == 0) {
				throw std::invalid_argument("El valor real no puede ser cero para calcular el error relativo porcentual.");
			}
			
			double resultado_actual = this->calcular();
			return fabs((valor_real - resultado_actual) / valor_real) * 100.0;
		}
		
	private:
			vector<double> x;  // Valores de la variable independiente
			vector<double> y;  // Valores de la variable dependiente
	};
}

#endif
