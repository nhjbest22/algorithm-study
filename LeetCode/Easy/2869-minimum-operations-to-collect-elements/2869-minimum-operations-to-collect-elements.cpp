class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_set<int> us;

        for(int i = N-1; i >=0; i--){
            if(nums[i] > k) continue;
            
            us.insert(nums[i]);

            if(us.size() == k) return N - i;
        }

        return 0;
    }
};