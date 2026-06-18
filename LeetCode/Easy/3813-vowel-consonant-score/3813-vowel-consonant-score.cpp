class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;

        for(auto& ch: s){
            if(ch < 'a' || ch > 'z') continue;
            c++;

            for(auto& vowel: {'a', 'e', 'i', 'o', 'u'}){
                if(ch == vowel) v++;
            }
        }
        c -= v;

        return c > 0 ? v/c : 0;
    }
};