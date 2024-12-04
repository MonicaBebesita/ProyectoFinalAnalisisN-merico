
/**
* @file
* @brief Contiene las rutinas de metodo segundas diferencias
* @author Monica alejandra Castellanos
* @author Ashlee Vanessa Campaz
* @copyright MIT License
*/


#ifndef SEGUNDAS_DIFERENCIAS_H
#define SEGUNDAS_DIFERENCIAS_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include "expresion.h"

using std::ostream;
using std::cout; 
using std::endl;

namespace diferenciacion{
	
	class s_diferenciacion{
		
	public:
		/**
		@brief Crea una instancia para calcular segundas diferencias
		@param f_str Texto de la funcion a derivar
		@param orden orden de la derivada
		*/
		s_diferenciacion(string f_str,int orden):f_str(f_str),orden(orden),f(f_str){
			
		}
		
		/**
		@brief calcula la derivada de f_str en x 
		@param x valor en el cual se evalua la derivada
		@param h paso
		@param tipo debe ser -1,0,1 que representan a la diferenciacion 
		hacia atras, central y hacia delante respectivamente.
		*/
		double calcular(double x, double h, int tipo){
			this->x = x;
			this->h = h;  
			this->tipo = tipo;
			double valor;
			estado = 1;
			switch (tipo){
				
			case -1:
				valor = calcular_hacia_atras();
				break;
			case 0:
				valor= calcular_central();
				break;
			case 1:
				valor = calcular_hacia_delante();
			default: 
				estado = -1;
				valor = NAN; 
			}
			
			return valor;
		}
			/**
			@brief Imprime toda la informacion de la derivada
			*/
			void imprimir(){
				
				if(estado){
					switch(tipo){
					case 1:
						imprimir_tabla_adelante(cout);
						break;
					case 0:
						imprimir_tabla_central(cout);
						break;
					case -1:
						imprimir_tabla_atras(cout);
						break;
					}
					cout<<"La derivada de orden "<<orden <<" la funcion: "<<f_str<< " en x="<<x<<
					   " utilizando segundas diferencias con un paso de "<< h << " es "<< valor << "." <<endl; 
				}
				else{
					if(estado==-1){
						cout<<"Error:Tipo invalido, el tipo debe ser -1, 0 o 1"<<endl; 
					}else{
						cout<<"Error:Orden invalido, el orden debe ser 1,2,3 o 4"<<endl; 
					}
				}
				cout<<"--------------------------------------------------------------------------------------"<<endl;
			}	
	private:
		/**
		@brief Imprime la tabla de datos de una derivada hacia delante
		@param os metodo de salida
		*/
		void imprimir_tabla_adelante(ostream & os){
			using std::ceil;
			os<<std::setw(25)<<"-----TABLA DE DATOS DERIVADA HACIA ADELANTE------"<<endl; 
			os<<std::setw(15)<< "x"
				<<std::setw(15) << "f(x)"<<endl;
			for(int i =0; i<orden + 2;i++){
				os<<std::setw(15)<< x + i*h
					<<std::setw(15)<<f(x + i*h)<<endl; 
				
			}
		}
		/**
		@brief Imprime la tabla de datos de una derivada central
		@param os metodo de salida
		*/
		void imprimir_tabla_central(ostream & os){
			using std::ceil;
			os<<std::setw(25)<<"-----TABLA DE DATOS DERIVADA CENTRAL------"<<endl; 
			os<<std::setw(15)<< "x"
			<<std::setw(15) << "f(x)"<<endl;
			for(int i =0; i<orden + 3;i++){
				if(i<=ceil((orden/2.0f)) || orden%2==0){
					os<<std::setw(15)<< x + ceil((orden/2.0f))*h  - i*h + h
						<<std::setw(15)<<f(x + ceil((orden/2.0f))*h - i*h +h)<<endl; 
				}else{
					os<<std::setw(15)<< x + ceil((orden/2.0f))*h - i*h
						<<std::setw(15)<<f(x + ceil((orden/2.0f))*h - i*h )<<endl; 
				} 
			}
		}	
		/**
		@brief Imprime la tabla de datos de una derivada hacia atras
		@param os metodo de salida
		*/	
		void imprimir_tabla_atras(ostream & os){
			using std::ceil;
			os<<std::setw(25)<<"-----TABLA DE DATOS DERIVADA HACIA ATRAS------"<<endl; 
			os<<std::setw(15)<< "x"
				<<std::setw(15) << "f(x)"<<endl;
			for(int i =0; i<orden + 2;i++){
				os<<std::setw(15)<< x - i*h
					<<std::setw(15)<<f(x - i*h)<<endl; 
					
			}
		}
		/**
		@brief Calcula una derivada hacia adelante 
		*/
		double calcular_hacia_delante(){
			double x1 = x + h;
			double x2 = x + 2*h; 
			double x3 = x + 3*h;
			double x4 = x + 4*h;
			double x5 = x + 5*h;
			double y = f(x);
			double y1 = f(x1);
			double y2 = f(x2);
			double y3 = f(x3); 
			double y4 = f(x4);
			double y5 = f(x5);
			
			switch(orden){
			case 1:
				valor = (-y2 + 4*y1 -3*y)/(2*(x1-x));
				break;
			case 2:
				valor = (-y3 + 4*y2 - 5*y1 + 2*y)/pow(x1-x,2);
				break;
			case 3:
				valor = (-3*y4 + 14*y3 - 24*y2 + 18*y1 - 5*y)/(2*pow(x1-x,3));
				break;
			case 4:
				valor = ( - 2*y5 + 11*y4 - 24*y3 + 26*y2 -14*y1 +3*y)/pow(x1-x,4);
				break;
			default:
				estado = -2;
				valor = NAN;
			}
			return valor; 
		} 
		/**
		@brief Calcula una derivada central
		*/
		double calcular_central(){
			double x1= x +h;
			double x_1 = x-h;
			double x2 = x + 2*h;
			double x_2 = x - 2*h;
			double x3 = x + 3*h;
			double x_3 = x - 3*h;
			double y = f(x);
			double y1 = f(x1);
			double y2 = f(x2);
			double y3 = f(x3);
			double y_1 = f(x_1);
			double y_2 = f(x_2);
			double y_3 = f(x_3);
			switch (orden){
			case 1:
				valor = (- y2 + 8*y1- 8*y_1 + y_2)/(12*(x1-x));
				break;
			case 2:
				valor = (-y2 + 16*y1 -30*y + 16*y_1 - y_2)/(12*pow(x1-x,2));
				break;
			case 3:
				valor = (-y3 + 8*y2 - 13*y1 + 13*y_1 - 8*y_2 + y_2)/(8*pow(x1-x,3));
				break;
			case 4:
				valor = (-y3 + 12*y2 - 39*y1 + 56*y - 39*y_1 + 12*y_2 - y_3)/(6*pow(x1-x,4));
				break;
			default:
				estado = -2;
				valor = NAN;
			}
			return valor;
		}
		/**
		@brief Calcula una derivada hacia atras
		*/
		double calcular_hacia_atras(){
			double x_5 = x - 5*h;
			double x_4 = x - 4*h;
			double x_3 = x - 3*h;
			double x_2 = x - 2*h;
			double x_1 = x -h;
			double y = f(x);
			double y_1 = f(x_1);
			double y_2 = f(x_2);
			double y_3 = f(x_3);
			double y_4 = f(x_4);
			double y_5 = f(x_5);
			switch (orden){
			case 1:
				valor = (3*y - 4*y_1 + y_2)/(2*(x-x_1));
				break;
			case 2:
				valor = (2*y - 5*y_1 + 4*y_2 -y_3)/pow(x-x_1,2);
				break;
			case 3:
				valor = (5*y - 18*y_1 + 24*y_2 -14*y_3 + 3*y_4)/(2*pow(x-x_1,3));
				break;
			case 4:
				valor = (3*y - 14*y_1 + 26*y_2 - 24*y_3 + 11*y_4 -2*y_5)/pow(x-x_1,4);
				break;
			default:
				estado = -2;
				valor = NAN;
			}
			
			return valor; 
		}	
	
		string f_str;
		int orden;
		int estado = 0;
		double h; 
		double x;
		int tipo;
		double valor;
		expression f;
	};
};
#endif
