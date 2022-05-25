#include <bits/stdc++.h>
using namespace std;

string reverseShuffleMerge(string s) {
    map<char, int> unused;
    map<char, int> used;
    map<char, int> required;
    string ans = "";
    
    for(char c : s) unused[c]++;
    for(char c : s) used[c] = 0;
    // because the result is half size the given s
    for(auto it = unused.begin(); it != unused.end(); it++)
        required[it->first] = (it->second)/2;
     
    for(int i = s.size()-1; i >= 0; i--) {
        if(used[s[i]] < required[s[i]]) {
            ans += s[i];
            used[s[i]]++;
            
            char curr = s[i];
            for(int j = ans.size()-1-1; j >= 0; j--) {
                // if current char is less than some char before it, it may be not in lexicographically smallest order 
                if(curr < ans[j]) {
                    // pretend that we removed, and check if has enough to reach the required number
		    /* eggegg
           	     * gge
            	     * 2-1 + 0 = 1 >= 2? no
		     */
                    if(used[ans[j]]-1 + unused[ans[j]] >= required[ans[j]]) {
                        used[ans[j]]--;
                        ans.erase(j,1);
                    } else break;
                } else break;
            }
        }
        // if we really used or if we just passed through it
        unused[s[i]]--;
            
    }
    
    
    return ans;
}

