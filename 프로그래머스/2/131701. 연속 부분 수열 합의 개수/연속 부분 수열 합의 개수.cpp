#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> s;
    int N = elements.size();
    for(int i = 0; i < N; i++){
        int sum = 0;
        
        for(int j = 0; j < N; j++){
            sum += elements[(i+j) % N];
            s.insert(sum);
        }
    }
    
    return s.size();
}