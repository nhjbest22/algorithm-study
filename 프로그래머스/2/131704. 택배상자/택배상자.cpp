#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int N = order.size();
    stack<int> s;
    int cur = 0;
    
    for(int i = 0; i < N; i++){
        int target = order[i];
        
        if(target > cur){
            while(cur < target){
                cur++;
                s.push(cur);
            }
            s.pop();
            answer++;
            
            continue;
        }
        
        if(s.top() != target) break;
        
        s.pop();
        answer++;
    }
    
    return answer;
}