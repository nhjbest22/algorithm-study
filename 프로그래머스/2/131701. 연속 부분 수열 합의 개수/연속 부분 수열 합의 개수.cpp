#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int N = elements.size();
    for(int i = 0; i < N; i++){
        int sum = elements[i];
        int idx = (i + 1) % N;
        
        s.insert(sum);
        
        while(idx != i){
            sum += elements[idx];
            s.insert(sum);
            idx = (idx + 1) % N;
        }
    }
    
    return s.size();
}