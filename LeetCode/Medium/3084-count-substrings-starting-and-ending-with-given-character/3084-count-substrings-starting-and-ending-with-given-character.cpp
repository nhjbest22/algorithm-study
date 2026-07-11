class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;

        for(const auto& ch: s){
            ans += (c == ch);
        }

        ans += ans * (ans-1) / 2;

        return ans;
    }
};