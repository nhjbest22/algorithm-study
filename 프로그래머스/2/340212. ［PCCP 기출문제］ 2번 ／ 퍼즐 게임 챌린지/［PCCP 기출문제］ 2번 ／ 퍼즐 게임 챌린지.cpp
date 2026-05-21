#include <string>
#include <vector>

using namespace std;

bool binary_search(int level, vector<int>& diffs, vector<int>& times, long long limit){
    long long total = 0;
    
    int N = diffs.size();
    
    for(int i = 0; i < N; i++){
        if(level >= diffs[i]) {
            total += times[i];
            continue;
        }
        
        total += (diffs[i] - level) * (times[i] + times[i-1]);
        total += times[i];
        
    }
    
    return total <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    // yes, no 가 내 level, 단 yes 일 경우에는 소요시간 <= limit
    int yes = 100'000;
    int no = 0;
    
    while(no + 1 < yes){
        int mid = (yes + no)/2;
        
        if(binary_search(mid, diffs, times, limit)) yes = mid;
        else no = mid;
    }
    
    
    return yes;
}