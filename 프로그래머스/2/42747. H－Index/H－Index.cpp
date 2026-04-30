#include <bits/stdc++.h>

using namespace std;

bool check(int mid, vector<int>& citations){
    auto it = lower_bound(citations.begin(), citations.end(), mid);
    
    if(it == citations.end()) return false;
    
    int cnt = citations.end() - it;
    return cnt >= mid;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int yes = 0; int no = 1'001;
    
    while(yes + 1 < no){
        int mid = (yes + no)/2;
        
        if(check(mid, citations)) yes = mid;
        else no = mid;
    }
    
    return yes;
}