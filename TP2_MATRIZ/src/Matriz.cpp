/*
 * Matriz.cpp
 *
 *  Created on: 25 may 2024
 *      Author: JOSNIER
 */

#include "Matriz.h"

Matriz::Matriz() {
	int i,j;
	n_filas = 2;
	m_columnas = 2;
	for(i=0; i<n_filas; i++){
		for(j=0; i<m_columnas; j++){
			matriz[i][j] = 0;
		}
	}
}

Matriz::Matriz(int n, int m) {
	int i,j;
	this->n_filas = n;
	this->m_columnas = m;
	for(i=0; i<n; i++){
		for(j=0; i<m; j++){
			this->matriz[i][j] = 0;
		}
	}
}

Matriz::Matriz(const Matriz &M) {
	int i,j;
	m_columnas = M.m_columnas;
	n_filas = M.n_filas;
	for(i=0; i<n_filas; i++){
		for(j=0; i<m_columnas; j++){
			matriz[i][j] = M.matriz[i][j];
		}
	}
}

Matriz& Matriz::operator =(const Matriz &M) {
	return(*this);
}

ostream& operator<<(ostream& os, const Matriz& mat){
	int i, j;
	for(i=0; i<mat.n_filas; i++){
		for(j=0; j<mat.m_columnas; j++){
			os << mat.m_columnas;
		}
		os << "\n";
	}
	return os;
}

Matriz Matriz::operator +(const Matriz& mat)const{
int i,j;
Matriz result=Matriz();
if(n_filas != mat.n_filas || m_columnas != mat.m_columnas){
	cout<<("las matrices deben de tener el mismo tamaño para poder sumarlas");
}
for(i=0;i<n_filas;i++){
	for(j=0;j<m_columnas;j++){
		result.num[i][j]=this->num[i][j] + mat.num[i][j];
	}
}
return result;}

Matriz Matriz::operator -(const Matriz& mat)const{
int i,j;
Matriz result=Matriz();
if(n_filas != mat.n_filas || m_columnas != mat.m_columnas){
	cout<<("las matrices deben de tener el mismo tamaño para poder restarlas");
}
for(i=0;i<n_filas;i++){
	for(j=0;j<m_columnas;j++){
		result.num[i][j]=this->num[i][j] - mat.num[i][j];
	}
}
return result;}

Matriz Matriz::operator !()const{
	int i,j;
	Matriz result=Matriz(m_columnas,n_filas);//las culumanas y filas se invierten
	for(i=0;i<n_filas;i++){
		for(j=0;j<m_columnas;j++){
			result.num[i][j]=this->num[j][i];
		}
	}
	return result;}

Matriz Matriz::operator*(const Matriz& q)const{
		//antes de hacer el producto habria que verificar las dimensiones
		//las columnas de la rimera matriz deben ser la misma cantidad que las filas de la segunda matriz
	if(n_filas != q.m_columnas){
		cout<<"No se puede obtener el producto matricial, no cumple condicion de dimenciones"<<endl;
		return Matriz(0,0);
	}
	Matriz result=Matriz(n_filas,q.m_columnas);
	int i,j,p;
	for(i=0;i<n_filas;i++){
		for(j=0;j<q.m_columnas;j++){
			for(p=0;p<n_filas;p++){
				result.num[i][j]+= num[i][p] * q.num[p][j];
			}
		}
	}
	return result;}

Matriz& Matriz::ProductoPorEscalar(double esc) {
             	for (int i = 0; i < n_filas; i++) {
		            for (int j = 0; j < m_columnas; j++) {
		               this->matriz[i][j]*=esc;
		            }
		        }
	return*this;
}

int Matriz::numel() {
	return n_filas*m_columnas;
}

double Matriz::Cumsum() {
	double suma=0.0;
	 for (int i = 0; i < n_filas; i++) {
	            for (int j = 0; j < m_columnas; j++) {
	                suma += matriz[i][j];
	            }
	        }
	        return suma;
}

double Matriz::Max() {
	 double max = matriz[0][0];
	        for (int i = 0; i < n_filas; i++) {
	            for (int j = 0; j < m_columnas; j++) {
	                if (matriz[i][j] > max) {
	                    max = matriz[i][j];
	                }
	            }
	        }
	        return max;
}

double Matriz::Min() {
	 double min = matriz[0][0];
	        for (int i = 0; i < n_filas; i++) {
	            for (int j = 0; j < m_columnas; j++) {
	                if (matriz[i][j] < min) {
	                    min = matriz[i][j];
	                }
	            }
	        }
	        return min;
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}
