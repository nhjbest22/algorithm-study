class Solution {
public:
    pair<int, int> v[100'005];

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int N = nums.size();

        for(int i = 0; i < N; i++){
            v[i] = {nums[i], i};
        }
        
        sort(v, v + N);
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