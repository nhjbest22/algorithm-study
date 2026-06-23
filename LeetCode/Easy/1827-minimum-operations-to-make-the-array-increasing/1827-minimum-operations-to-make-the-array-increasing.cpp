class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        
        int MAX = nums[0];
        for(int i = 1; i < N; i++){
            if(MAX < nums[i]){
                MAX = nums[i];
                continue;
            }

            ans += (MAX - nums[i] + 1);
            MAX++;
        }

        return ans;
    }
};