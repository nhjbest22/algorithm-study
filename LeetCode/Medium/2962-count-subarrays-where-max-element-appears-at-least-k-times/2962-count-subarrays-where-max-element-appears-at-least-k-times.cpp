class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int MAX = *max_element(nums.begin(), nums.end());

        int N = nums.size();
        long long ans = 0;
        
        int st = 0;
        int count = 0;

        for(int en = 0; en < N; en++){
            if(nums[en] == MAX) count++;

            while(count >= k){
                if(nums[st] == MAX) 
                    count--;
                st++;
            }

            ans += st;
        }

        return ans;
    }
};