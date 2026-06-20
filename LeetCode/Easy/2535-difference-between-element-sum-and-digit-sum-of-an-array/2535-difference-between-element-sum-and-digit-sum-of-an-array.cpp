class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum_element = accumulate(nums.begin(), nums.end(), 0);
        int sum_digit = 0;
        for(auto& num: nums){
            while(num){
                sum_digit += num % 10;
                num /= 10;
            }
        }

        return abs(sum_element - sum_digit);
    }
};