#include <bits/stdc++.h>
using namespace std;

void minimumBribes(vector<int> q) {
    int n_bribes = 0;
    for(int i = q.size()-1; i >= 0; i--) {
        if(q[i] != (i+1)) { // se subornou
            if(((i-1) >= 0) and (q[i-1] == (i+1))) { // subornou 1x
                n_bribes++;
                swap(q[i], q[i-1]);
            }
            else if(((i-2) >= 0) and (q[i-2] == (i+1))) { // subornou 2x
                n_bribes += 2;
                q[i-2] = q[i-1];
                q[i-1] = q[i];
                q[i] = i+1;
            }
            else {
                cout << "Too chaotic\n";
                return;
            }
        }
    }
    
    cout << n_bribes << endl;
    return;
}

