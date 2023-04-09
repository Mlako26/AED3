#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> mem;
vector<int> p;
int neginf = 0;

int main(){
    // Entrada
    p.push_back(3);
    p.push_back(2);
    p.push_back(5);
    p.push_back(6);
    
    // El menos infinito es mas chico que el menor valor alcanzable
    for (int i = 0; i < p.size(); i++) neginf -= p[i];

    // Escribo las posibles ganancias del primer dia
    mem.resize(p.size(), neginf);
    mem[0] = 0;
    mem[1] = -p[0];

    for (int i = 1; i < p.size(); i++) {
        vector<int> fila_i(p.size(), -1);

        for (int j = 0; j < p.size(); j++) {
            if (i + 1 < j) break;
            int res = mem[j];
            if (j > 0) {
                int aux = mem[j-1] - p[i];
                if (aux > res) res = aux;
            }
            if (j < p.size() - 1) {
                int aux = mem[j+1] + p[i];
                if (aux > res) res = aux;
            }
            fila_i[j] = res;
        }

        mem = fila_i;
    }
    cout << mem[0];
    return 0;
}
