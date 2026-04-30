#include <bits/stdc++.h>

using namespace std;

bool check(int mid, vector<int>& works, int n){
    // mid로 줄일 수 있는지 여부
    int sum = 0;
    
    for(auto& w: works){
        if(w < mid) break;
        
        sum += (w - mid);
    }
    
    return sum < n;
}

long long solution(int n, vector<int> works) {
    sort(works.begin(), works.end(), greater<>());
    
    int no = -1;
    int yes = 50'000;
        
    while(no + 1 < yes){
        int mid = (yes + no)/2;
        
        if(check(mid, works, n)) yes = mid;
        else no = mid;
    }
    
    for(auto& w: works){
        if(w < yes) break;
        
        n -= (w - yes);
        w = yes;
    }
    
    long long ans = 0;
    for(auto& w: works){
        if(w == 0) break;        
        if(n > 0){
            n--;
            w--;
        }
        
        ans += (long long)w * w;
    }

    return ans;    
}