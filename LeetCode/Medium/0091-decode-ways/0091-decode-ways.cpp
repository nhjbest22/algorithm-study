class Solution {
public:
    int numDecodings(string s) {
        int cnt[105];
        fill(cnt, cnt + 105, 0);
        cnt[0] = 1;

        s = "0" + s;

        int N = s.size();
        for(int i = 1; i < N; i++){
            int num = s[i] - '0';

            if(num != 0) cnt[i] += cnt[i-1];
            if(s[i-1] == '0') continue;

            if(i-2 < 0) continue;

            num += (s[i-1] - '0')*10;
            if(num > 26) continue;

            cnt[i] += cnt[i-2];
        }

        return cnt[N-1];
    }
};