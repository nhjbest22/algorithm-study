#include <iostream>

using namespace std;

int ans;

int solution(int n)
{
    while(n){
        ans += n % 10;
        n /= 10;
    }
    
    return ans;
}