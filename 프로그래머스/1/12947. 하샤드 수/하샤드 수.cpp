#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer;
    
    int N = x;
    int div = 0;
    
    while(N) {
        div += N % 10;
        N /= 10;
    }
    
    return x % div == 0;
}