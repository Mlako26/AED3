#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> w, s;
vector<vector<int>> mem;
int n;

int maxPile(int c, int i) {
    if (c < 0) return -1;
    if (i == n) return 0;

    int p = min(c, w[0]);

    if (mem[p][i] != 0) return mem[c][i];
    return mem[p][i] = max(maxPile(c, i+1), 1 + maxPile(min(c-w[i], s[i]), i+1));
}

int main(int argc, char* argv[]) {
    n = 5;
    w.push_back(19);
    w.push_back(7);
    w.push_back(5);
    w.push_back(6);
    w.push_back(1);

    s.push_back(15);
    s.push_back(13);
    s.push_back(7);
    s.push_back(8);
    s.push_back(2);

    mem.resize(20, vector<int>(n));

    int res = maxPile(100, 0);
    cout << res << endl;

    return 0;
}

/* 
a. Pruebo absolutamente todas las combinaciones de pilas validas y me quedo con la mas larga.
b. 
mp(s, i)        = -inf si s < 0
                = 0 si i = n + 1 & s >= 0
                = max (1 + mp(min(s-wi, si),i+1), mp(s,i+1)) sino
 */