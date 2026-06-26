class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        int N = nums.size();

        for(int i = 0; i < N; i++){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        int prev = v[0].first;

        for(int i = 1; i < N; i++){
            if(v[i].first != prev){
                prev = v[i].first;
                continue;
            }

            if(v[i].second - v[i-1].second <= k) return true;
        }

        return false;
    }
};