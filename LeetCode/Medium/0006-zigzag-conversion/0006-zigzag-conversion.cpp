class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string str[1'005];

        int cur = 0;
        int N = s.size();

        int dir = -1;
        for(int i = 0; i < N; i++){
            str[cur] += s[i];

            if(cur == 0 || cur == numRows -1){
                dir *= -1;
            }

            cur += dir;
        }

        string ans;
        for(int i = 0; i < numRows; i++) ans += str[i];

        return ans;
    }
};