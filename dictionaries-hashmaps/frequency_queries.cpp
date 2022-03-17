#include <bits/stdc++.h>
using namespace std;

vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> queries3;
    // <number, freq>
    unordered_map<int, int> freq;
    // <freq, freq da freq>
    unordered_map<int, int> freqFreq;
    /*
     
     [1]
     freq[1] = 1
     freqFreq[1] = 1
     
     [1, 1]
     freq[1] = 2
     freqFreq[2] = 1
     freqFreq[1] = 1
     
     [1, 1, 2]
     freq[1] = 2
     freq[2] = 1
     freqFreq[2] = 1
     freqFreq[1] = 1
     
    */
    
    for(vector<int> q : queries) {
        if(q[0] == 1) {
            freqFreq[freq[q[1]]]--;
            freq[q[1]]++;
            freqFreq[freq[q[1]]]++;
        }
        else if(q[0] == 2) {
            if(freq.find(q[1]) != freq.end()) {
                if(freq[q[1]] > 0) {
                    freqFreq[freq[q[1]]]--;
                    freq[q[1]]--;
                    freqFreq[freq[q[1]]]++;
                }
            }
        }
        else if(q[0] == 3) {
            if(freqFreq.find(q[1]) != freq.end()) {
                if(freqFreq[q[1]] > 0)
                    queries3.push_back(1);
                else
                    queries3.push_back(0);                    
            } else {
                queries3.push_back(0);                    
            }
        }
        
    }
    
    return queries3;
}

