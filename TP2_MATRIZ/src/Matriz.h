/*
 * Matriz.h
 *
 *  Created on: 25 may 2024
 *      Author: JOSNIER
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;




class Matriz {
private :
	int n_filas,m_columnas;
	double **matriz;
	std::vector<std::vector<int>> num;
public:
	// constructores
	Matriz();
	Matriz(int n_filas, int m_columnas);
	Matriz(const Matriz& M);

	// funciones miembro
	Matriz& operator=(const Matriz& M);
	Matriz& ProductoPorEscalar(double esc);
    int numel();
	double Cumsum();
	double Max();
	double Min();

	friend ostream& operator<<(ostream& os, const Matriz& mat);
	//sobrecarga de operadores
	Matriz operator +(const Matriz& q)const;
		Matriz operator -(const Matriz& q)const;
		Matriz operator !()const;
		Matriz operator*(const Matriz& q)const;
	// destructores
	virtual ~Matriz();
};

#endif /* MATRIZ_H_ */
