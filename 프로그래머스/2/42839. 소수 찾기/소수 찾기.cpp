#include <bits/stdc++.h>

using namespace std;

#define visit VISIT

const int MAX = 10'000'000;

bool isPrime[MAX + 5];
bool isUsed[MAX + 5];
int ans;

bool visit[10];

void backtrack(const string& numbers, int cur, int len){
    if(isPrime[cur] && !isUsed[cur]){
        isUsed[cur] = true;
        ans++;
    }
    
    if(len == numbers.size()) return;

    for(int i = 0; i < numbers.size(); i++){
        if(visit[i]) continue;
        
        visit[i] = true;
        int nxt = numbers[i] - '0';
        backtrack(numbers, 10*cur + nxt, len + 1);
        visit[i] = false;
    }
    
}

int solution(string numbers) {
    fill(isPrime, isPrime + MAX + 5, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i*i <= MAX; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= MAX; j += i){
            isPrime[j] = false;
        }
    }
    
    backtrack(numbers, 0, 0);
    
    return ans;
}