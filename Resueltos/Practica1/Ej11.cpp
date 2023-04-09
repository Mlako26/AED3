#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

vector<int> v;

bool chain(float w, int i) {
    if (i == -1 && w == 0) return true;
    if (i == -1 && w != 0) return false;
    return chain(w-v[i], i-1) || chain(w/v[i], i-1) || chain(pow(w, 1.0 / v[i]), i-1);
}

int main(int argc, char* argv[]) {
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);
    int n = v.size();
    bool res = chain(13, n-1);
    cout << res << endl;
    return 0;
}

/* 

f(w,i) = 1  si i = 0 y w = 0
       = 0  si i = 0 y w != 0
       = max(f(w-vi), f(w/vi), f(viroot(w))) sino 

Cuando no nos queden mas elementos, si hubiesemos elejido una combinacion correcta de operadores, hubiesemos llegado a w y en ese caso nos devuelve true. Sino false.

Por otro lado, si todavia me quedan elementos, tomo el O del algebra de bool (o el maximo entre 1s y 0s) entre aplicarle al w actual cualquiera de las operaciones inversas a las disponibles.

En otras palabras, en el paso k, va a existir una cadena de operadores que lleven a w, si es que al aplicarle las inversas a w con el elemento vk sigue existiendo una cadena desde k-1. 
 */