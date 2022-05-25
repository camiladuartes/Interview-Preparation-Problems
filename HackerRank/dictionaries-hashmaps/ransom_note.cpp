#include <bits/stdc++.h>
using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> mag;
    for(int i = 0; i < magazine.size(); i++)
        mag[magazine[i]] += 1;
    
    for(int i = 0; i < note.size(); i++) {
        if(mag.find(note[i]) != mag.end()) {
            mag[note[i]]--;
            if(mag[note[i]] == 0)
                mag.erase(note[i]);
        }
        else {
            cout << "No\n";
            return;
        }
        
    }
    
    cout << "Yes\n";
}

