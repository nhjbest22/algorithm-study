#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)

int solution(vector<int> people, int limit) {
    int ans = 0;
    
    sort(people.begin(), people.end(), greater<>());
    int st = 0, en = people.size() - 1;
    
    while(st < en){
        ans++;

        if(limit - people[st++] < people[en]) 
            continue;
        
        en--;
    }
    
    if(st == en) ans++;
    
    return ans;
}