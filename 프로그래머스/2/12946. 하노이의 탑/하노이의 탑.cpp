#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

void hanoi(int from, int to, int n){
    if(n == 1) {
        res.push_back({from, to});
        return;
    }
    
    hanoi(from, 6- from - to, n-1);
    res.push_back({from, to});
    hanoi(6-from-to, to, n-1);
}

vector<vector<int>> solution(int n) {
    hanoi(1, 3, n);
    
    return res;
}