#include <bits/stdc++.h>
using namespace std;

string decompress(string compressedStr) {
    stack<char> auxStack;
    string returnStr = "";
    for(int i = 0; i < compressedStr.size(); i++) {
        if(compressedStr[i] != ']') auxStack.push(compressedStr[i]);
        else {
            string auxStr = "";
            // getting the substring
            while(auxStack.top() != '[') {
                auxStr = auxStack.top() + auxStr;
                auxStack.pop();
            }
            // poping the open bracket
            auxStack.pop();

            string subNum = "";
            // getting the integer value
            while(!auxStack.empty() && isdigit(auxStack.top())) {
                subNum = auxStack.top() + subNum;
                auxStack.pop();
            }
            
            // append the substring to the stack subNum times
            for(int i = 0; i < stoi(subNum); i++) {
                for(char c : auxStr) auxStack.push(c);
            }
        }
    }

    while(!auxStack.empty()) {
        returnStr = auxStack.top() + returnStr;
        auxStack.pop();
    }
    
    return returnStr;
}


int main() {
    cout << decompress("2[abc]4[ab]c") << endl;
    cout << decompress("2[3[a]b]") << endl;
}
