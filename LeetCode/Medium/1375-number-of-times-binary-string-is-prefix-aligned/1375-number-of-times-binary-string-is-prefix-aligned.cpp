class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int N = flips.size();
        int ans = 0;
        int MAX = 0;

        for(int i = 0; i < N; i++){
            auto& flip = flips[i];
            MAX = max(MAX, flip);

            if(MAX == i+1) ans++;
        }

        return ans;
    }
};