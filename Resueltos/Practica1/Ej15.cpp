#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> E = {1,2,3,4};
    vector<pair<int,int>> C = {{1,2},{2,3},{3,4}};
    vector<int> A;
    vector<int> B;
    vector<int> where(E.size(), 0);
    // where[i] = 0 -> E[i] no esta asignado a ningun subgrupo
    // where[i] = 1 -> E[i] esta en A
    // where[i] = 2 -> E[i] esta en B

    sort(C); // Ordeno C por primer componente tal que tengan el mismo orden que en E
    int j = 0;
    for (int i = 0; i < E.size(); ++i) {
        int a = 0;
        int b = 0;
        while (C[j].first == E[i]) {
            if (where[C[j].second] == 1) a++;
            if (where[C[j].second] == 2) b++;
            j++;
        }
        if (a < b) {
            A.push_back(E[i]);
            where[i] = 1;
        } else {
            B.push_back(E[i]);
            where[i] = 2;
        }
    }

    // Falta imprimir salida
    return 0;
}

/* 
Si logramos demostrar que para cualquier size de la entrada y cualquier instancia hay una solucion al problema, demostraremos que efectivamente siempre se puede encontrar una respuesta valida. Hagamos induccion en la cantidad de estudiantes.

Caso Base: Hay 1 solo estudiante
Simplemente divido el grupo de 1 estudiante en otro de 1 estudiante y otro de ninguno, ambos con ninguna pareja de estudiantes cercanos.

Paso Inductivo: supongamos que se puedan dividir en dos un grupo de k estudiantes, cada subgrupo con <= c/2 parejas cercanas, siendo c la cantidad de relaciones totales. Veamos que tambien se puede dividir uno de k+1 estudiantes.

Tenemos que con k estudiantes, de agregar un estudiante k+1, las relaciones totales pasan a ser c' = c + i + j. Contamos cuantas son las relaciones cercanas que tiene con los estudiantes en cada subgrupo. Es decir, llamemos i a la cantidad de relaciones cercanas que tiene el estudiante k+1 con los estudiantes de A, y j con los estudiantes de B. Notemos que como las relaciones se forman de entre dos estudiantes sin repeticiones, i y j suman exactamente la cantidad de relaciones totales en las cuales participa el estudiante k+1. Luego, de ser i menor (o igual), lo agrego al grupo A. De ser j menor, a B.

Por hipotesis inductiva, ambos grupos tenian <= c/2 relaciones. Supongamos que agregamos al estudiante al grupo A. En el peor caso, el grupo tenia de antemano exactamente c/2 relaciones, y luego de agregar al nuevo estudiante tendra c/2 + i. Luego, como i <= j, la cantidad totales de relaciones en el sistema seran c + i + j >= c + 2i. Por ultimo, observemos que (c+2i) / 2 = c/2 + i que es la cantidad exactas de relaciones que tenemos en el grupo A. Entonces, ambos grupos cumplen con la condicion de tener como mucho la mitad de relaciones maximas cada uno, y son validos.

Idem si agregamos al nuevo estudiante al grupo B.

Como para cualquier instancia existe una solucion, el problema tiene solucion siempre.
*/