class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v1(256, -1), v2(256, -1);

        int N = s.size();

        for(int i = 0; i < N; i++){
            // v1, v2 -> 각 문자들이 string에서 나온 마지막 자리수
            if(v1[s[i]] != v2[t[i]]) return false;

            v1[s[i]] = v2[t[i]] = i;
        }
        
        return true;
    }
};