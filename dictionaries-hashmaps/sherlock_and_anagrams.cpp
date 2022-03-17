#include <bits/stdc++.h>
using namespace std;

int sherlockAndAnagrams(string s) {
    /*
        abba:
            ft = [{'a', 2}, {'b', 2}]
            freq = [{{'a',1}, 1},
                    {{'b',1}, 1},
                    {{'b',2}, 1},
                    {{'a',2}, 1}]
        bba
            ft = [{'a', 1}, {'b', 2}]
            freq = [{{'a',1}, 2},
                    {{'b',1}, 2},
                    {{'b',2}, 2},
                    {{'a',2}, 1}]
        ba
            ft = [{'a', 1}, {'b', 1}]
            freq = [{{'a',1}, 3},
                    {{'b',1}, 3},
                    {{'b',2}, 2},
                    {{'a',2}, 1}]
        a
            ft = [{'a', 1}]
            freq = [{{'a',1}, 4},   a a => 4*3/2 = 6
                    {{'b',1}, 3},   b b => 3*2/2 = 3
                    {{'b',2}, 2},   bb bb => 2*1/2 = 1
                    {{'a',2}, 1}]   => 1*0/2 = 0
            aba
            aa
            aba
            {{'a', 1}, 2}
            {{'b', 1}, 1}            
    */
    map<map<char, int>, int> freq;
    for(int i = 0; i < s.size(); i++) {
        map<char, int> ft;
        for(int j = i; j < s.size(); j++) {
            ft[s[j]]++;
            freq[ft]++;
        }
    }
    
    int ans = 0;
    for(pair<map<char, int>, int> f : freq) {
        ans += (f.second * (f.second-1))/2; // all permutations (n*(n-1)/2)
    }
    
    return ans;
}

