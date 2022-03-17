#include <bits/stdc++.h>
using namespace std;

void countSwaps(vector<int> a) {
    int numSwaps = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.size()-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                numSwaps++;
            }
        }
    }
    cout << "Array is sorted in " << numSwaps << " swaps.\n";
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size() - 1] << endl;        
}

