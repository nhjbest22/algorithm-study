class Solution {
public:
    const int MAX = 'z' - 'a' + 1;
    int maxPalindromesAfterOperations(vector<string>& words) {
        int cnt[MAX];
        fill(cnt, cnt + MAX, 0);
        int ans = 0;
        
        vector<int> word_len;

        for(auto& word: words){
            word_len.push_back(word.size());
            for(auto& ch: word) cnt[ch - 'a']++;
        }

        int one = 0, two = 0;
        for(int i = 0; i < MAX; i++){
            two += cnt[i]/2;
            one += cnt[i]%2;
        }

        sort(word_len.begin(), word_len.end());

        for(auto& len: word_len){
            int one_cnt = len%2;
            int two_cnt = len/2;

            if(two_cnt > two) continue;

            ans++;
            if(one_cnt){
                two = one ? two : two - 1;
                one = one ? one -1 : one + 1;
            }

            two -= two_cnt;
        }

        return ans;
    }
};