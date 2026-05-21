#include <iostream>
using namespace std;



int solution(int n)
{
    int ans = 0;
    while(n){
        ans += n & 1;
        n /= 2;
    }    
    return ans;
}