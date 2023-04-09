#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<vector<int>> mem;
int n = 3, m = 3;

int vidaMin(int i, int j) {
    if (i == m || j == n) return 1;
    if (mem[i][j] != 0) return mem[i][j];

    int res;
    if (i == m - 1) res = vidaMin(i, j+1) - A[i][j];
    if (j == m - 1) res = vidaMin(i+1, j) - A[i][j];
    else res = min(vidaMin(i+1,j), vidaMin(i, j+1)) - A[i][j];

    if (res <= 0) res = 1;
    mem[i][j] = res;
    return mem[i][j];
}

int main(int argc, char* argv[]) {

    A.resize(n, vector<int>(m));
    mem.resize(n, vector<int>(m));
    A[0][0] = -2;
    A[0][1] = -3;
    A[0][2] = 3;
    A[1][0] = -5;
    A[1][1] = -10;
    A[1][2] = 1;
    A[2][0] = 10;
    A[2][1] = 30;
    A[2][2] = -5;

    int res = vidaMin(0,0);
    cout << res << endl;
    return 0;
}

/* 
a. La idea seria probar absolutamente todas las combinaciones del tablero y ver cual es el minimo al que llego comenzando con 0 de vida. Es decir, ese minimo en positivo mas 1 es la minima cantidad de vida con la que debo comenzar ese camino para siempre tener 1 de vida en cada paso. Luego, me fijo que camino me deja con el menor minimo posible y esa es la respuesta en absoluto + 1.

c. VM(i,j) = 1 si i > m o j > n
           = VM(i+1,j) - A[i][j] si j = n
           = VM(i,j+1) - A[i][j] si i = m
           = min(VM(i+1,j), VM(i, j+1)) - A[i][j] sino


d. 
Complejidad espacial: O(nm)
Complejidad temporal: O(nm)

Si fuese un enfoque bottom-up, por ejemplo de la siguiente forma: me fijo cual es el mas chico entre m y n, y luego calculo desde la fila/columna n/m hasta la 0 desde la ezquina inferior derecha. 
Espacial: O(min(n,m))
Temporal: O(nm)
 */