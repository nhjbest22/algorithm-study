class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long MIN = 0;
        long long MAX = 0;

        long long cur = 0;
        for(int& diff: differences){
            cur += diff;

            MAX = max(MAX, cur);
            MIN = min(MIN, cur);
        }

        long long diff = lower - MIN;
        MAX += diff;

        return MAX > upper ? 0 : upper - MAX + 1;
    }
};