#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;



int main(int argc, char* argv[]) {

    return 0;
}

/* 
a.

las posibilidades de que n dados sumen s, es la suma de las posibilidades de que el primer dado sea 1 <= i <= k y los restantes n-1 dados sumen s-i, para todo i.

f(n,s) = 1  si n = 1 y s <= k
       = 0 si n = 1 y s > k 
       = sum_{i=1}^{min(k,s)} f(n-1, s-i) sino

b.

En este caso, no importa realmente el orden de los dados, sino mas bien contar las diferentes configuraciones en las cuales se suma s. Es decir, si s = 6, con tres dados es la misma respuesta (1, 3, 2) y (3, 2, 1) y ...

Entonces, las posibilidades de que n dados con k caras sumen s.

g(n,s,k) = 1 si n = 1 y s <= k
         = 0 si n = 1 y s > k
         = sum_{i=1}^{min(k,s)} f(n-1, s-i, i) sino


c. Observemos que f tiene n * s instancias diferentes. De todos modos, en cada instancia recursiva de la funcion se llama casi siempre a k instancias. Entoneces, se tiene un orden de O(k^n) llamados recursivos. n * s <<<< k^n sii s <<< k^n/n

Por otro lado, la funcion g ...

d. Para calcular f, un algoritmo posible seria tener a K de variable global, y n y s de parametros de entrada. La recursion seria igual a la funcion recursiva, donde si me queda un solo dado devuelvo 1 o 0 siempre y cuando s este en el rango del dado, y sino sumo las combinaciones donde sale cada uno de los valores para el dado n. Para g es similar.

Con respecto a la programacion dinamica, se pueden resolver ambas funciones con una matriz de n x 
 */