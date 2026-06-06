class Solution {
public:
    int diff(pair<int, int>& a, pair<int, int>& b){
        return abs(a.first - b.first);
    }

    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int en = indexDifference;
        int st = 0;

        pair<int, int> MAX = {-1, -1}, MIN = {INT32_MAX, INT32_MAX};

        while(en < nums.size()){
            pair<int, int> prev = {nums[st], st};
            pair<int, int> cur = {nums[en], en};

            MAX = max(MAX, prev);
            MIN = min(MIN, prev);

            if(diff(cur, MAX) >= valueDifference) return {en, MAX.second};
            if(diff(cur, MIN) >= valueDifference) return {en, MIN.second};


            st++;
            en++;
        }

        return {-1, -1};
    }
};