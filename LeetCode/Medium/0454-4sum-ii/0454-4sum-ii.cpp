class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int N = nums1.size();
        unordered_map<int, int> um;
        int ans = 0;

        for(auto& num1: nums1){
            for(auto& num2: nums2){
                um[num1 + num2]++;
            }
        }

        for(auto& num3: nums3){
            for(auto& num4: nums4){
                ans += um[-(num3 + num4)];
            }
        }

        return ans;
    }
};