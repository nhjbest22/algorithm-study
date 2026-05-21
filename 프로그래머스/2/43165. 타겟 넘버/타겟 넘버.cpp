#include <string>
#include <vector>

using namespace std;

int ans;

void backtrack(int idx, int sum, const vector<int>& numbers, const int& target){
    if(idx == numbers.size()){
        ans += (sum == target);
        return;
    }
    
    backtrack(idx + 1, sum + numbers[idx], numbers, target);
    backtrack(idx + 1, sum - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    backtrack(0, 0, numbers, target);
    
    return ans;
}