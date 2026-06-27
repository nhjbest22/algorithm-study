class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;

        for(int i = 0; i < k; i++){
            auto cur = pq.top();
            if(cur == 0) break;

            pq.pop();
            ans += cur;

            pq.push(cur/3 + (cur%3 > 0));
        }

        return ans;
    }
};