#include <bits/stdc++.h>

using namespace std;

bool check(int mid, int n, vector<int>& cores){
    long long cnt = 0;
    
    for(int i = 0; i < cores.size(); i++){
        cnt += (mid) / cores[i];
        cnt += (mid % cores[i] != 0);
    }
    
    return cnt < n;
}

int solution(int n, vector<int> cores) {
    int yes = 0;
    int no = 10'000 * 25'000 + 1;
    
    
    while(yes + 1 < no){
        int mid = (yes + no)/2;
        
        if(check(mid, n, cores)) yes = mid;
        else no = mid;
    }
    
    int cnt = 0;
    
    for(int i = 0; i < cores.size(); i++){
        cnt += yes/cores[i];
        cnt += (yes % cores[i] != 0);
    }
    
    for(int i = 0; i< cores.size(); i++){
        if(yes % cores[i] != 0) continue;
        
        cnt++;
        
        if(cnt == n) return i+1;
    }
    
    return 0;
}