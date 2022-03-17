#include <bits/stdc++.h>
using namespace std;

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int contSorted = 0, numMinSwaps = 0, i = 0;
    
    while(contSorted != arr.size()) {
        if(i+1 != arr[i]) {
            swap(arr[i], arr[arr[i]-1]);
            numMinSwaps++;
        } else {
            contSorted++;
            i++;
        }
    }
   
    return numMinSwaps;
}

