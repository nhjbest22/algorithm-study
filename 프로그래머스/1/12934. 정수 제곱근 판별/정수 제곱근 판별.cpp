#include <string>
#include <vector>

using namespace std;

typedef long long ll;

long long solution(long long n) {
    ll yes = 1;
    ll no = 0x3f3f3f3f;
    
    while(yes + 1 < no){
        ll mid = (yes + no)/2;
        
        if(mid * mid <= n) yes = mid;
        else no = mid;
    }
    
    if(n == yes * yes) return (yes+1)*(yes+1);
    else return -1;
    
}