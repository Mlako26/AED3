#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int maxc = 200;
int maxq = 7;

pair<int,int> invalid = make_pair(-1,-1);
vector<vector<pair<int,int>>> mem(7, vector<pair<int,int>>(15, invalid));

pair<int, int> paying(vector<int> &B, int i, int j) {
    int n = B.size();
    int aux = j;
    if (aux < 0) aux = 0;
    
    if (mem[i][aux] != invalid) return mem[i][aux];
    if (i == n && j <= 0) {
        mem[i][aux] = make_pair(0,0);
        return make_pair(0, 0);
    }
    if (i == n && j > 0) {
        mem[i][aux] = make_pair(maxc, maxq);
        return make_pair(maxc, maxq);
    }

    pair<int, int> res1 = paying(B, i+1, j);
    pair<int, int> res2 = paying(B, i+1, j-B[i]);
    pair<int, int> res;
    res2.first += B[i];
    res2.second += 1;

    if (res1.first < res2.first) {
        res = res1;
    } else if (res1.first == res2.first && res1.second < res2.second) {
        res = res1;
    } else {
        res = res2;
    }

    mem[i][aux] = res;
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> B;
    B.push_back(2);
    B.push_back(3);
    B.push_back(5);
    B.push_back(10);
    B.push_back(20);
    B.push_back(20);


    int c = 14;

    pair<int, int> res = paying(B, 0, c);

    cout<<res.first<<" "<<res.second<<endl;

    return 0;
}

/* 
    a. cc({b1,...,bn},c) = (+inf, +inf) si n = 0 y c > 0
                         = (0, 0)       si n = 0 y c <= 0
                         = min{cc({b1,...,bn-1},c), (bn, 1) + cc({b1,...,bn-1},c-bn)} sino

    b. complejidad = O(2^n)
 */

