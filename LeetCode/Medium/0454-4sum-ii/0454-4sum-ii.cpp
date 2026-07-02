class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int N = nums1.size();
        unordered_map<int, int> um;
        int ans = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                um[nums3[i] + nums4[j]]++;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int sum = nums1[i] + nums2[j];

                if(um.find(-sum) == um.end()) continue;
                
                ans += um[-sum];
            }
        }

        return ans;
    }
};