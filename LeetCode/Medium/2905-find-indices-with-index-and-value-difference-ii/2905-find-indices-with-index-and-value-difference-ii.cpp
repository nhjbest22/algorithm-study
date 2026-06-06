class Solution {
public:
    int diff(pair<int, int>& a, pair<int, int>& b){
        return abs(a.first - b.first);
    }

    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int en = indexDifference;
        int st = 0;

        int MIN = 0, MAX = 0;

        while(en < nums.size()){
            if(nums[st] > nums[MAX]) MAX = st;
            if(nums[st] < nums[MIN]) MIN = st;

            if(abs(nums[en] - nums[MAX]) >= valueDifference) return {en, MAX};
            if(abs(nums[en] - nums[MIN]) >= valueDifference) return {en, MIN};


            st++;
            en++;
        }

        return {-1, -1};
    }
};