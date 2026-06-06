class Solution {
public:
    int diff(pair<int, int> a, pair<int, int>& b){
        return abs(a.first - b.first);
    }

    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int en = indexDifference;
        int st = 0;

        pair<int, int> MAX = {-1, -1}, MIN = {INT32_MAX, INT32_MAX};

        while(en < nums.size()){
            pair<int, int> cur = {nums[st], st};

            MAX = max(MAX, cur);
            MIN = min(MIN, cur);

            if(diff({nums[en], en}, MAX) >= valueDifference) return {en, MAX.second};
            if(diff({nums[en], en}, MIN) >= valueDifference) return {en, MIN.second};


            st++;
            en++;
        }

        return {-1, -1};
    }
};