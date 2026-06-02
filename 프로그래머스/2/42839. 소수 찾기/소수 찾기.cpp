#include <bits/stdc++.h>

using namespace std;

#define visit VISIT

const int MAX = 10'000'000;
bool isPrime[MAX + 5];


int solution(string numbers) {
    fill(isPrime, isPrime + MAX + 5, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i*i <= MAX; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= MAX; j += i){
            isPrime[j] = false;
        }
    }
    
    set<int> s;
    
    sort(numbers.begin(), numbers.end());
    do{
        for(int i = 1; i <= numbers.size(); i++){
            int num = stoi(numbers.substr(0, i));
            
            if(!isPrime[num]) continue;
            
            s.insert(num);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    
    return s.size();
}