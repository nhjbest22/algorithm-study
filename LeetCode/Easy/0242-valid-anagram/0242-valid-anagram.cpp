class Solution {
public:
    int cnt1['z' - 'a' + 1];
    int cnt2['z' - 'a' + 1];

    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        fill(cnt1, cnt1 + ('z' - 'a' + 1), 0);
        fill(cnt2, cnt2 + ('z' - 'a' + 1), 0);

        for(auto& ch: s){
            int idx = ch - 'a';
            cnt1[idx]++;
        }

        for(auto& ch: t){
            int idx = ch - 'a';
            cnt2[idx]++;
        }

        for(int i = 0; i < 'z' - 'a' + 1; i++){
            if(cnt1[i] != cnt2[i]) return false;
        }

        return true;
    }
};