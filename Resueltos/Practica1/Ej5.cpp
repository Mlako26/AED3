#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;



int main(int argc, char* argv[]) {

    return 0;
}

/* 
    b.Observemos que solo hay O(nk) posibles entradas para la funcion ss', pero se 
    realizan O(2^n) llamadas recursivas en el algoritmo. Entonces, observermos que
    nk << 2^n, es decir, habra superposicion ya que hay muchoas mas llamados
    recursivos que instancias validas, si y solo si k << 2^n/n.

    d.Subset_Sum(C,n,k) resuelve el problema ya que tenemos el conjunto entero C,
    el tamaño de C (con lo cual el algoritmo recorrera todo el conjunto), y j = k
    el valor total al que quiero sumar.
    Cada paso recursivo tiene complejidad O(1), y se generan solo nk instancias.
    => O(nk)

 */