#include <bits/stdc++.h>
using namespace std;

int maximumToys(vector<int> prices, int k) {
    int maxToys = 0;
    sort(prices.begin(), prices.end());
    for(int price : prices) {
        if(price <= k) {
            k -= price;
            maxToys++;
        }
        else
            break;
    }
    
    return maxToys;
}

