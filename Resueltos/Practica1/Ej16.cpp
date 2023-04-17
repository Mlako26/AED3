#include<iostream>
#include<vector>

using namespace std;

vector<int> V;
vector<pair<int,int>> E;

void fs(vector<int> &S, vector<bool> &W) {
    if (W.size() == 0) return;

    int best = 0;
    vector<int> bestS;

    for (int i = 0; i < W.size(); ++i) {
        S.push_back(W[i]);
        for (int j = 0; j < W.size(); ++j) {
            
        }
    }
}

int main() {

    return 0;
}