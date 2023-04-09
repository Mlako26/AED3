#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

// Dada una matriz nxn simetrica, y un k natural < n, determinar un subconjunto de tamano 
// k de {1...n} tal que maximice la suma de las posiciones con esos indices

// Una solucion candidata es un conjunto de indices entre 1 y N de tamano k. 
// Una solucion sera valida si y solo si no existe otra solucion candidata tal que la suma de los elementos
// en M en esos indices combinados de cualquier forma sea superior a la suma con indices actuales
// Una solucion parcial es un conjunto de indices de tamano menor a k.
// Una solucion parcial se extiende agregandole elementos del conjunto espacio.
// Dada una solucion parcial y un indice i, se puede agregar i al conjunto o no, y en ambos casos sumar i.

pair<vector<int>, int> bestIndexes(int& k, vector<vector<int>>& M, vector<int>& curInd, int& curSum, int i) {
    int n = M.size();

    if (curInd.size() == k) {//Solucion candidata
        return make_pair(curInd, curSum);
    }

    vector<int> bestInd = {};
    int bestSum = 0;

    if (k - curInd.size() == n - i + 1) { // Solo consigo solucion valida si meto todos los restantes
        bestInd = curInd;
        bestSum = curSum;
        while (i <= n) {
            for (int j = 0; j < bestInd.size(); j++) {
                bestSum += M[bestInd[j] - 1][i - 1];
                bestSum += M[i - 1][bestInd[j] - 1];
            }
            bestSum += M[i-1][i-1];
            bestInd.push_back(i);
            i++;
        }
        return make_pair(bestInd, bestSum);
    }
    // Si todavia no alcanzo k, agarro la mejor solucion entre el conjunto donde no agrego o agrego i
    pair<vector<int>, int> possible = bestIndexes(k, M, curInd, curSum, i+1);
    bestInd = possible.first;
    bestSum = possible.second; // Empiezo asumiendo no agregar es mejor

    int nextUp = 0;
    for (int j = 0; j < curInd.size(); ++j) {
        nextUp += M[i - 1][curInd[j] - 1];
        nextUp += M[curInd[j] - 1][i - 1];
    }
    nextUp += M[i-1][i-1];
    curSum += nextUp;
    curInd.push_back(i);

    possible = bestIndexes(k, M, curInd, curSum, i+1);
    curSum -= nextUp;
    curInd.pop_back();

    if (possible.second > bestSum) {
        bestInd = possible.first;
        bestSum = possible.second;
    }

    return make_pair(bestInd, bestSum);
}

int main(int argc, char* argv[]) {
    vector<vector<int>> M (4, vector<int>(4));
    M[0][0] = 0;
    M[1][1] = 0;
    M[2][2] = 0;
    M[3][3] = 0;
    M[0][1] = 10;
    M[0][2] = 10;
    M[0][3] = 1;
    M[1][2] = 5;
    M[1][3] = 2;
    M[2][3] = 30;
    M[1][0] = 10;
    M[2][0] = 10;
    M[3][0] = 1;
    M[2][1] = 5;
    M[3][1] = 2;
    M[3][2] = 30;
    
    int k = 3;
    vector<int> cur;
    int best = 0;
    pair<vector<int>, int> res = bestIndexes(k, M, cur, best, 1);
    cout << "El mejor conjunto es: ";
    for (int i = 0; i < k; i++) {
        cout << res.first[i] << " ";
    }
    cout << endl << "Con ellos, se maximiza la suma con: " << res.second << endl;
    return 0;
}

/* 
    Complejidad espacial: Utilizo un vector de tamaño k para guardar las posibles
    respuestas. O(k)
    Complejidad temporal: La complejidad temporal será la de cada subproblema junto con
    la cantidad de ellos.
    Cada instancia tendra como mucho complejidad O(k), ya que recorro el vector solucion
    parcial algunas veces.
    Por otro lado, en el caso en el que se exploran todas las instancias, hay 2 llamados 
    recursivos por instancia n veces. (o agrego el elemento o no). O(2^n)
    => Complejidad O(k*2^n)

    Una poda podria ser ver que si solo me quedan exactamente la cantidad de numeros
    necesarios por agregar para llegar a los k elementos, agregarlos.
 */