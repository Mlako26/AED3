#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mem;
vector<int> p;
int neginf = 0;

int astroVoid(int j, int c) {
    
    if (j == 0 && c == 0) return 0;
    if (j == 0 && c == 1) return -p[j];
    if (j == 0) return neginf;
    if (c < 0 || j + 1 < c) return neginf;

    if (mem[j][c] != -1) return mem[j][c];

    int res = astroVoid(j-1, c-1) - p[j];
    int aux = astroVoid(j-1, c+1) + p[j];
    if (aux > res) res = aux;
    aux = astroVoid(j-1, c);
    if (aux > res) res = aux;

    return res;
}

int main(){
    p.push_back(3);
    p.push_back(6);
    p.push_back(10);

    vector<int> auxV(p.size(), -1);
    mem.resize(p.size(), auxV);
    for (int i = 0; i < p.size(); i++) neginf -= p[i];

    int res = astroVoid(p.size() - 1, 0);
    cout << res << endl;

    return 0;
}

/* 
    av_p(j,c) = 0         si j = 0 y c = 0
            = -p[j]       si j = 0 y c = 1
            = -inf      si c < 0 o j + 1 < c
            = -inf      si j = 0 y c != 0
            = max{av(j-1,c-1) - p[j], av(j-1, c+1) + p[j], av(j-1,c)} sino

    Con esta formula, el dato respuesta es av_p(|p| - 1, 0)
    Es decir, empiezo despues el ultimo dia posible y se que voy
    a terminar con 0 asteroides para una solucion optima.

    Complejidad PD Top Down:
        Espacial: O(n^2)
        Temporal: Cada instancia es O(1) y hay como mucho n/2 rocas por 
        instancia, con n dias. (compro todos los dias hasta la mitad de la cantidad, porque comienzo con 0 pero debo de finalizar con 0 tambien)
        => O(n^2)
 */