class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int M = queries.size();
        
        vector<int> colors(n, 0);
        vector<int> ans(M, 0);

        for(int i = 0; i < M; i++){
            int cnt = i == 0 ? 0 : ans[i-1];

            auto& q = queries[i];
            int idx = q[0], C = q[1];
            
            if(colors[idx] != 0){
                if(idx - 1 >= 0 && colors[idx-1] == colors[idx]) cnt--;
                if(idx + 1 < n && colors[idx] == colors[idx + 1]) cnt--;
            }

            colors[idx] = C;

            if(idx - 1 >= 0 && colors[idx-1] == colors[idx]) cnt++;
            if(idx + 1 < n && colors[idx] == colors[idx + 1]) cnt++;

            ans[i] = cnt;
        }

        return ans;
    }
};