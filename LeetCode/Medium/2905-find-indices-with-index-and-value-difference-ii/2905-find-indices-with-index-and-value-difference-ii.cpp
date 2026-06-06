class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int en = indexDifference;
        int st = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minPQ;
        priority_queue<pair<int, int>> maxPQ;

        while(en < nums.size()){
            minPQ.push({nums[st], st});
            maxPQ.push({nums[st], st});

            if(abs(minPQ.top().first - nums[en]) >= valueDifference) return {minPQ.top().second, en};
            if(abs(maxPQ.top().first - nums[en]) >= valueDifference) return {maxPQ.top().second, en};


            st++;
            en++;
        }

        return {-1, -1};
    }
};