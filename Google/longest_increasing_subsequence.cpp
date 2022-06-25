#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubseq(vector<int> sequence) {
    //   i     j
    // [-1, 3, 4, 5, 2, 2, 2]
    // [1,  2, 3]

    // O(n^2)
    if(sequence.size() < 1) return 0;
    vector<int> dynamicSubseq(sequence.size(), 1);
    int i, j, currGreaterSubseq, greaterSubseq = 1;
    for(int j = 1; j < sequence.size(); j++) {
        i = 0;
        currGreaterSubseq = 1;
        while(i < j) {
            if(sequence[j] > sequence[i]) {
                if(dynamicSubseq[i]+1 > currGreaterSubseq)
                    currGreaterSubseq = dynamicSubseq[i]+1;
            }
            i++;
        }
        dynamicSubseq[j] = currGreaterSubseq;
        if(dynamicSubseq[j] > greaterSubseq)
            greaterSubseq = dynamicSubseq[j] ;
    }

    return greaterSubseq;
}

int main() {
    vector<int> ex1 = {10,9,2,5,3,7,101,18};
    cout << longestIncreasingSubseq(ex1) << endl;

    vector<int> ex2 = {0,1,0,3,2,3};
    cout << longestIncreasingSubseq(ex2) << endl;

    vector<int> ex3 = {7,7,7,7,7,7,7};
    cout << longestIncreasingSubseq(ex3) << endl;
}
