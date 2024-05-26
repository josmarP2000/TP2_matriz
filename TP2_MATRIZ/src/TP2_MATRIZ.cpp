//============================================================================
// Name        : TP2_MATRIZ.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Matriz.h"
using namespace std;

int main() {
	Matriz a,b,c;
		a = Matriz();
		b = Matriz(4, 5);
		c = b;

		cout << c << endl;
		return 0;
}
