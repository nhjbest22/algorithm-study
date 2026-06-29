class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int N = nums.size();

        for(int i = 0; i <N; i++) pq.push({nums[i], i});
        vector<int> v_num(N), v_idx(N);

        while(1){
            if(pq.empty()) break;

            int len = 0;
            auto [prev_num, prev_idx] = pq.top();
            pq.pop();

            v_num[len] = prev_num;
            v_idx[len++] = prev_idx;

            while(!pq.empty()){
                auto [cur_num, cur_idx] = pq.top();
                if(cur_num - prev_num > limit) break;

                pq.pop();

                v_num[len] = cur_num;
                v_idx[len++] = cur_idx;

                prev_num = cur_num;
                prev_idx = cur_idx;
            }

            sort(v_idx.begin(), v_idx.begin() + len);
            for(int i = 0; i < len; i++){
                int idx = v_idx[i];
                nums[idx] = v_num[i];
            }
        }

        return nums;
    }
};