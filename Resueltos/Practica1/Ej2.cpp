#include <stdio.h>
#include<stdlib.h>
#include <vector>

using namespace std;

bool esMagico(vector<vector<int>> &M, int &magicNum, vector<int> &sumCol){
    int n = M.size();
   
    for (int i = 0; i < n; i++) {
        if (sumCol[i] != magicNum) {
            return false;
        }
    }
    
    // Check diagonales
    int sumIzq = 0;
    int sumDer = 0;
    for (int i = 0; i < n; i++) {
        sumIzq += M[i][i];
        sumDer += M[i][n-1-i];
    }
    if (sumIzq != magicNum || sumDer != magicNum) {
        return false;
    }

    return true;
}

int cuadMag(vector<int> &remaining, vector<vector<int>>& square, int i, int j, int magicNum, vector<int>& sumCol, vector<int>& sumFil) {
    int n = square.size();

    if (j == n) {
        if (sumFil[i] != magicNum) {
            return 0;
        } else {
            return cuadMag(remaining, square, i + 1, 0, magicNum, sumCol, sumFil);
        }
    }

    if (i == n) { // Caso base
        return esMagico(square, magicNum, sumCol);
    }

    int res = 0; 
    for (int k = 1; k <= n * n; k++) {
        if (remaining[k-1] == 0 && sumCol[j] + k <= magicNum && sumFil[i] + k <= magicNum) { // Numero disponible
            square[i][j] = k;
            remaining[k-1] = 1;
            sumCol[j] += k;
            sumFil[i] += k;
            res += cuadMag(remaining, square, i, j+1, magicNum, sumCol, sumFil); 
            remaining[k-1] = 0; 
            sumCol[j] -= k;
            sumFil[i] -= k;
        }
    }
    return res;
}


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);

    // Inicializar
    int magicNum = (n * n * n + n) / 2;
    vector<vector<int>> M(n, vector<int>(n));
    vector<int> col(n);
    vector<int> fil(n);
    n = n * n;
    vector<int> c(n);

    int res = cuadMag(c, M, 0, 0, magicNum, col, fil);
    printf("La cantidad de cuadrados magicos de orden %d son: %d\n", n, res);
    return 0;
}