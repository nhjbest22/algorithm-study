class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }

        while(k--){
            auto [cur, i] = pq.top();
            pq.pop();

            cur *= multiplier;
            
            nums[i] = cur;
            pq.push({cur, i});
        }
        return nums;
    }
};