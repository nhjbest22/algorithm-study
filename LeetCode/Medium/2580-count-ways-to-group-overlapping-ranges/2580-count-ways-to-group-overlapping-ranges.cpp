class Solution {
public:
    const int mod = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& v1, const vector<int>& v2){
            if(v1[0] != v2[0]) return v1[0] < v2[0];
            return v1[1] < v2[1];
        });

        int en = ranges[0][1];
        int ans = 2;

        for(int i = 1; i < ranges.size(); i++){
            if(en >= ranges[i][0]){
                en = max(en, ranges[i][1]);
                continue;
            }

            ans *= 2;
            ans %= mod;
            en = ranges[i][1];
        }

        return ans;
    }
};