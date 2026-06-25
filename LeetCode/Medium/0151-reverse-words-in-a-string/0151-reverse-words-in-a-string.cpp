class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int N = s.size();
        int l = 0, r = 0;
        int i = 0;

        while(i < N){
            while(i < N && s[i] == ' ')
                i++;

            if(i == N) break;

            while(i < N && s[i] != ' ')
                s[r++] = s[i++];
            
            reverse(s.begin() + l, s.begin() + r);
            s[r++] = ' ';

            l = r;
            i++;
        }

        s.resize(r - 1);

        return s;
    }
};