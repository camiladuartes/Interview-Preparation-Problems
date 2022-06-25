#include <bits/stdc++.h>
using namespace std;

int volume(vector<int> heights) {
    if(heights.size() <= 0) return 0;
    int greater = heights[0]; // will initialize another section
    int volume = 0, currVolume = 0;

    for(int i = 1; i < heights.size(); i++) {
        if(heights[i] >= greater) {
            greater = heights[i];
            volume += currVolume;
            currVolume = 0;
        }
        else {
            currVolume += (greater - heights[i]);
        }
    }

    greater = heights[heights.size()-1];
    currVolume = 0;
    for(int i = heights.size()-2; i >= 0; i--) {
        if(heights[i] > greater) {
            greater = heights[i];
            volume += currVolume;
            currVolume = 0;
        }
        else {
            currVolume += (greater - heights[i]);
        }
    }

    return volume;
}

int main() {
    vector<int> heights = {1,3,2,4,1,3,1,4,5,2,2,1,4,2,2};
    cout << volume(heights) << endl;
}
