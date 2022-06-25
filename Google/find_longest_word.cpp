#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> indexes, char target) {
    int left = 0;
    int right = indexes.size()-1;
    int ans = -1;

    while(left <= right) {
        int mid = left + ((right-left)/2);
        if(indexes[mid] <= target) left = mid+1;
        else {
            ans = indexes[mid];
            right = mid-1;
        }
    }

    return ans;
}

string longestWord(string s, set<string> d) {
    if(s.empty() || d.empty()) return "";

    string longestWord = "";
    int longestWordSize = 0;
    int lastPosS = 0;
    map<char, vector<int>> charCount;

    for(int i = 0; i < s.size(); i++) charCount[s[i]].push_back(i);

    for(auto dWord : d) {
        lastPosS = -1;
        bool isSubstr = true;
        for(auto charac : dWord) {
            if(charCount.find(charac) != charCount.end()) {
                int lastPosS = binarySearch(charCount[charac], lastPosS);
                if(lastPosS == -1) {
                    isSubstr = false;
                    break;
                }
            }
            // doesn't found the character, so go to next word 
            else {
                isSubstr = false;
                break;
            }
        }
        if(isSubstr) {
            if(dWord.size() > longestWordSize) {
                longestWordSize = dWord.size();
                longestWord = dWord;
            }
        }
    }
    
    return longestWord;
}

// O(numCharsS + numCharsOfAllWordsD * log(numCharsS))
// s = "abppplee" => [{a,[0]};{b,[1]};{p,[2,3,4]};{l,[5]};{e,[6,7]}]
// sort D in descending order, so can just stop when the words starts to be smaller then the longest subst by now 

int main() {
    cout << longestWord("abppplee", {"able", "ale", "apple", "bale", "kangaroo"}) << endl;
}