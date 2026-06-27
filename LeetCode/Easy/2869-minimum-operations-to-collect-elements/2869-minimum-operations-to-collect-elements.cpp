class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int N = nums.size();
        int cnt = 0;

        bool isCollected[55] = {false, };

        for(int i = N-1; i >=0; i--){
            if(nums[i] > k) continue;

            cnt += !isCollected[nums[i]];
            isCollected[nums[i]] = true;

            if(cnt == k) return N - i;
        }

        return 0;
    }
};