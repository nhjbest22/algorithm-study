class Solution {
public:
    string reverseVowels(string s) {
        vector<int> v;
        int N = s.size();

        for(int i = 0; i < N; i++){
            auto& ch = s[i];
            
            for(auto vowel: {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}){
                if(ch == vowel){
                    v.push_back(i);
                    break;
                }
            }
        }

        int M = v.size();
        for(int i = 0; i < M/2; i++){
            int &l = v[i], &r = v[M-i-1];

            swap(s[l], s[r]);
        }

        return s;
    }
};