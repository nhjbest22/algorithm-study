class Solution {
public:
    int findComplement(int num) {
        long long cur = 1;
        long long ans = 0;
        while(num){
            ans += (1 - (num%2))*cur;

            num /= 2;
            cur *= 2;
        }

        return (int) ans;
    }
};