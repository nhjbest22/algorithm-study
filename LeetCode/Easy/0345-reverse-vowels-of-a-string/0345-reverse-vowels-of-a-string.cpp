class Solution {
public:
    string reverseVowels(string s) {
        vector<int> v;
        int N = s.size();
        long long bitmask = 0;

        for(auto& vowel: {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}){
            int idx = vowel - 'A';
            bitmask |= (long long)1 << idx;
        }

        for(int i = 0; i < N; i++){
            int ch = s[i] - 'A';
            if(ch < 0) continue;
            
            long long bit = (long long)1 << ch;

            if(bitmask & bit) v.push_back(i);
        }

        int M = v.size();
        for(int i = 0; i < M/2; i++){
            int &l = v[i], &r = v[M-i-1];

            swap(s[l], s[r]);
        }

        return s;
    }
};