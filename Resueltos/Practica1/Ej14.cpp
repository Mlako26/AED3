#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v = {1,2,5};
    
    if (v.size() == 0) return 0;

    sort(v); // O(n log n)
    int costo = v[0];
    int res = 0;
    int i = 1;
    while (i < v.size()) {
        costo += v[i];
        res += costo;
    }
    cout << res << endl;

    return 0;
}

/* 

b.

observemos que luego de sumar i numeros, el costo total quedara 
(a1 + a2)*(i-1) + a3(i-2)+...+ai. Entonces, queremos que los numeros que mas se repiten sean lo mas small chicos posibles. Supongamos que ordenarlos por orden creciente y sumarlos en orden no fuese optimo. Entonces, existe al menos una posicion k donde en vez de sumar a_k sumamos a_j.

Si a_j < a_k, j < k,significa que el algoritmo hubiese devuelto
(a1 + a2)*(i-1) + ... + aj(i-j-1) + ... + ak(i-k-1) + ... + ai
y la mejor solucion
(a1 + a2)*(i-1) + ... + ak(i-j-1) + ... + aj(i-k-1) + ... + ai

Pero como es optima, tiene que darse que 

ak(i-j-1) + aj(i-k-1) < aj(i-j-1) + ak(i-k-1)
ak (i-j-1-i+k+1) < aj(i-j-1-i+k+1)
ak(k-j) < aj(k-j)  (como k > j, k-j > 0)
ak < aj ABSURDO

idem si aj > ak

Entonces, la soluion optima sera sumar todo en el orden ascendiente.
 */