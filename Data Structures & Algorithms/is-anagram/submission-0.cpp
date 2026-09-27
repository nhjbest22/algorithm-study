class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = 'z' - 'a' + 1;

        vector<int> cnt(len, 0);

        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }

        for(auto num: cnt){
            if(num != 0) return false;
        }

        return true;
    }
};
