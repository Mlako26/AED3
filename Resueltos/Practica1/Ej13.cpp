#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> A = {1,1,1,1,1};
    vector<int> B = {1,2,3};

    int i = 0;
    int j = 0;
    int parejas = 0;
    while(i < A.size() && j < B.size()) {
        if (abs(A[i] - B[j]) <= 1) {
            parejas++;
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << parejas << endl;

    return 0;
}

/* 
13.a.
Recorriendo de izquierda a derecha, de estar ambos multiconjuntos ordenados, el algoritmo para encontrar la maxima cantidad de parejas es el siguiente:

Sea i un indice al principio del arreglo A, y j del arreglo B. Si |A[i] - B[j]| <= 1, entonces +1 cantidad de parejas y i++ j++. Si no, el menor de A[i] y B[j]++ ese indice.

i = 0;
j = 0;
parejas = 0;
while(i < A.size() && j < B.size()) {
    if (|A[i] - B[j]| <= 1) {
        parejas++;
        i++;
        j++;
    } else if (A[i] < B[j]) {
        i++;
    } else {
        j++;
    }
}

c. Primero observemos que la solucion es valida. Es decir, sea o no optima la solucion (la maxima cantidad de parejas posibles), la obtenida sera <= a la misma. Veamos que nunca se agregan parejas con > 1 de diferencia en habilidad. Estando en la posicion i y j, solo se sumara 1 a la cantidad de parejas si la diferencia de habilidad es <= 1. Como en ningun otro lugar se agregan parejas, todas las parejas agregadas son un subconjunto de las parejas agregadas por cualquier solucion optima.

Por otro lado, queremos ver que efectivamente no existe una solucion mejor, y la obtenida por el algoritmo greedy es optima. Veamos que en cada paso k nuestra solucion con parejas p1...pr luego de haber comparado k personas se puede extender a una solucion optima p1...prpr+1...pm. Hagamos induccion en k.

k = 0: Cuando no compare ninguna persona todavia, se puede extender la secuencia vacia a cualquier solucion optima.

k > 0: Supongamos que la solucion parcial obtenida luego de realizar k-1 comparaciones p1...pr puede ser extendida a una optima p1...prpr+1...pm. Quiero ver que realizando mi comparacion k esto sigue valiendo. En la comparacion k estamos observando a un A_i y B_j elementos de cada conjunto.

Si |A_i - B_j| <= 1, entonces pueden formar pareja p. Como la solucion p1...prpr+1...pm es optima, y todavia no considere esta pareja, p es una entre pr+1...pm. Luego, a mi solucion parcial p1...prp la puedo extender a la optima p1...prp[(pr+1...pm) / p] anterior. (no importa el orden de las parejas).

Si el algoritmo greedy no formo una pareja con A_i y B_j, significa que |A_i - B_j| > 1. Aca se dan dos casos:
    A_i < B_j: Como los arreglos estan ordenados en forma creciente, sabemos que toda persona A_l que venia antes de A_i tambien cumplira que |A_l - B_j| > 1. Entonces, el algoritmo greedy compara la siguiente persona A_i+1 con B_j, ya que A_i+1 >= A_i. Como A_l no podrian haber formado pareja con B_j, no me estoy perdiendo de ninguna pareja por no compararlos, y entonces no pertenece a la extension pr+1...pm optima. Entonces, puedo extender el algoritmo luego de k+1 comparaciones a una solucion optima.
    A_i > B_j: Idem que el caso anterior pero adelantando a B_j+1.

Como en cada paso de nuestro algoritmo se puede extender a una solucion optima, en particular al finalizar todos sus pasos la solucion obtenida sera optima y no existe una mejor.
*/