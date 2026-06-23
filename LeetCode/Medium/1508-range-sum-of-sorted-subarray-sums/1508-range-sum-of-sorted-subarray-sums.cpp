class Solution {
public:
    const int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        
        int sum = 0;
        int idx = 0;
        while(1){
            idx++;
            if(idx > right) break;
            
            auto [cur, cur_idx] = pq.top();
            pq.pop();
            
            if(idx >= left) sum = (sum + cur) % mod;

            if(cur_idx == n-1) continue;
            
            cur = (cur + nums[cur_idx +1])%mod;
            pq.push({cur, cur_idx+1});
        }

        return sum;
    }
};