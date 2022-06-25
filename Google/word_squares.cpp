#include <bits/stdc++.h>
using namespace std;

// I DIDN'T FINISH

// [AREA, BALL, DEAR, LADY, LEAD, YARD]
// Responde se existe um word square que começa 
// na posição (i, j) e tem um tamanho = size
vector<vector<char>> words = {{'B','A','L','L'},
                                {'A','R','E','A'},
                                {'L','E','A','D'},
                                {'L','A','D','Y'}}; // yes
int k = 4;

// [0][1] [1][0]
// [0][2] [2][0]
// ...
// [1][2] [2][1]
// [1][3] [3][1]
// ...

bool isWordSquare(int i, int j, int size) {
    if(i > k) return true;

    for(int x = 0; x < size; x++) {
        if(words[i][j] != words[j][i]) return false;
        j++;
    }
    isWordSquare(i+1, i+1, size-1);
    
    return true;
}

int main() {
    cout << isWordSquare(0,0,k) << endl;    

    return 0;
}