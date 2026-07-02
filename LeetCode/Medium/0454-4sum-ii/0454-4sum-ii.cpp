class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int N = nums1.size();
        vector<int> sums(N*N);
        int ans = 0;

        int idx = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                sums[idx++] = nums3[i] + nums4[j];
            }
        }

        sort(sums.begin(), sums.end());

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int sum = nums1[i] + nums2[j];
                auto [it1, it2] = equal_range(sums.begin(), sums.end(), -sum);

                ans += it2 - it1;
            }
        }

        return ans;
    }
};