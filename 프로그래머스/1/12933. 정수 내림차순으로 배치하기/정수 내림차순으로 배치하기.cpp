#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string buffer = to_string(n);
    sort(buffer.begin(), buffer.end(), greater<>());

    
    return stoll(buffer);
}