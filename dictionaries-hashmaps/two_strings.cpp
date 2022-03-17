#include <bits/stdc++.h>
using namespace std;

string twoStrings(string s1, string s2) {
    unordered_set<char> alfaS1;
    for(int i = 0; i < s1.size(); i++) {
        alfaS1.insert(s1[i]);
    }
    
    for(int i = 0; i < s2.size(); i++) {
        if(alfaS1.find(s2[i]) != alfaS1.end())
            return "YES";
    }
    
    return "NO";
}

