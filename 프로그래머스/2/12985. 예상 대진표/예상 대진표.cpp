#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 1;
    a--;
    b--;
    
    a -= (a%2);
    b -= (b%2);
    
    while(a != b){
        a /= 2;
        b /= 2;
        
        a -= (a%2);
        b -= (b%2);
        
        cnt++;
    }
    
    return cnt;
}