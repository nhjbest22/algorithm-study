class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n){
            cnt += n % 2;
            n /= 2;
        }

        return cnt;
    }
};