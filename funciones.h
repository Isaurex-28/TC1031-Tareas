#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

class Funciones{

    public:
    int sumaIterativa(int n);
    int sumaRecursiva(int n);
    int sumaDirecta(int n);

};

int Funciones::sumaIterativa(int n){
    int resultado = 0;

    if (0 > n){
        return 0;
    }

    for (int i = 0; i <= n; i++){
        resultado += i;
    }

    return resultado;
}

int Funciones::sumaRecursiva(int n){

	if (n == 0) {
		return 0;
    }

    else {
		return sumaRecursiva(n - 1) + n;
	}
}

int Funciones::sumaDirecta(int n){
    return (n * (n + 1))/2;
}

#endif