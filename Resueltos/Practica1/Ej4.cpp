#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// Una solucion parcial es un subconjunto de C
// Una solucion candidata es una permutacion cualquiera de C
// Una solucion valida es tal que minimiza la sumatoria
// Para extender una solucion parcial se le agrega elementos de C
// restantes hasta completar
// Con C checkeo los elementos que ya utilice

int suma(vector<vector<int>> &M, vector<int> &cur) {
    int res = 0;

    int n = cur.size();
    res += M[cur[n-1] - 1][cur[0] - 1];
    for (int i = 0; i < n - 1; i++) {
        res += M[cur[i] - 1][cur[i+1] - 1];
    }

    return res;
}

vector<int> bestPerm(vector<vector<int>> &M, vector<int> &C, vector<int> &cur, int i) {
    int n = C.size();

    if (i == n) { // Si alcance solucion candidata
        return cur;
    }

    // Si continuo en una solucion parcial
    int min = -1;
    vector<int> res(n);
    for (int j = 0; j < n; j++) {
        if (C[j] == 0) {
            cur.push_back(j+1);
            C[j] = 1;
            vector<int> next = bestPerm(M, C, cur, i+1);
            C[j] = 0;
            cur.pop_back();
            int sum = suma(M, next);
            if (sum < min || min == -1 ) {
                min = sum;
                res = next;
            }
        }
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<vector<int>> M (4, vector<int>(4));
    M[0][0] = 0;
    M[1][1] = 5;
    M[2][2] = 0;
    M[3][3] = 4;
    M[0][1] = 1;
    M[0][2] = 10;
    M[0][3] = 10;
    M[1][2] = 3;
    M[1][3] = 15;
    M[2][3] = 70;
    M[1][0] = 10;
    M[2][0] = 21;
    M[3][0] = 3;
    M[2][1] = 17;
    M[3][1] = 22;
    M[3][2] = 30;

    vector<int> C(4);
    vector<int> aux;

    vector<int> res = bestPerm(M, C, aux, 0);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}

// Complejidad espacial: O(n) (Voy modificando un mismo vector solucion de tamano maximo n)
// Complejidad temporal: O(n! * n) (hay n! nodos, peor caso n operaciones (por suma)).
// Como poda, voy haciendo la suma en cada paso y si ya me pase no sigo
