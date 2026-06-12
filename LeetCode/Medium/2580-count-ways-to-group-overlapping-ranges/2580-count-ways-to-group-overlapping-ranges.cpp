class Solution {
public:
    const int mod = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& v1, const vector<int>& v2){
            if(v1[0] != v2[0]) return v1[0] < v2[0];
            return v1[1] < v2[1];
        });

        vector<vector<int>> new_ranges;
        int N = ranges.size();
        new_ranges.push_back(ranges[0]);

        for(int i = 1; i < N; i++){
            auto& en = new_ranges[new_ranges.size() -1];
            if(en[1] >= ranges[i][0]){
                en[1] = max(en[1], ranges[i][1]);
                continue;
            }

            new_ranges.push_back(ranges[i]);
        }

        int M = new_ranges.size();
        
        int ans = 1;
        while(M--){
            ans <<= 1;
            ans %= mod;
        }

        return ans;
    }
};