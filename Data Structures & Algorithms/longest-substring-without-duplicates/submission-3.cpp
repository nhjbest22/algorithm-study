class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int N = s.size();
        vector<int> last(256, -1);

        int st = 0;
        for(int en = 0; en < N; en++){
            auto ch = s[en];

            st = max(st, last[ch] + 1);
            last[ch] = en;

            ans = max(ans, en - st + 1);
        }

        return ans;
    }
};
