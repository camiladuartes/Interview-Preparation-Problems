#include <bits/stdc++.h>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    // line sweep
    /*
        (1, {begin, 3}), (5, {end, 3}), (4, {begin, 7}), (8, {end, 7}), (6,{begin,1}), (9, {end, 1})
        (1, {begin, 3}), (4, {begin, 7}), (5, {end, 3}), (6, {begin,1}), (8, {end, 7}),(9, {end, 1})
        
        valorAcumulado = 7
        maiorValor = MIN_VALUE
    */
    
    long a, b, k;
    long valorAcumulado = 0;
    long maiorValor = INT_MIN;
    vector<pair<int, pair<int, int>> > lineSweep;
    
    for(long i = 0; i < queries.size(); i++) {
        lineSweep.push_back({/*a*/queries[i][0], {/*begin*/1, /*k*/queries[i][2]}});
        lineSweep.push_back({/*b*/queries[i][1]+1, {/*end*/0, /*k*/queries[i][2]}});
    }
    
    sort(lineSweep.begin(), lineSweep.end());
    
    int tirarNoProx = 0, quantoTirar= 0;
    for(long i = 0; i < lineSweep.size(); i++) { // {a/b, {begin/end, k}}
        if(lineSweep[i].second.first == 1) {
            valorAcumulado += lineSweep[i].second.second;
            if(valorAcumulado > maiorValor) maiorValor = valorAcumulado;    
        }
        else {
            valorAcumulado -= lineSweep[i].second.second;
        }
    }
    
    return maiorValor;
}

