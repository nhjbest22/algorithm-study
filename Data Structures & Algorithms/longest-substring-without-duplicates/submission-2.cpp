class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, last_idx = 0;
        int N = s.size();
        vector<int> ch_idx(256, -1);

        for(int i = 0; i < N; i++){
            auto& ch = s[i];

            if(ch_idx[ch] >= last_idx)
                last_idx = ch_idx[ch] + 1;

            ch_idx[ch] = i;
            ans = max(ans, i - last_idx + 1);
        }

        return ans;
    }
};
