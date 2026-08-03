class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int idx = 0, N = nums.size();
        while(idx < N && k > 0){
            if(nums[idx] >= 0) break;

            nums[idx++] *= -1;
            k--;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(k%2 == 0) return sum;

        int MIN = *min_element(nums.begin(), nums.end());

        return sum - 2*MIN;
    }
};