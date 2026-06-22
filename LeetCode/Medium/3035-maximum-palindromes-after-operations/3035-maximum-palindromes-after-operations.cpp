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

        int total_pair = 0;
        for(int i = 0; i < MAX; i++){
            total_pair += cnt[i]/2;
        }

        sort(word_len.begin(), word_len.end());

        for(auto& len: word_len){
            int needed_pair = len/2;
            if(needed_pair > total_pair) break;

            ans++;
            total_pair -= needed_pair;
        }

        return ans;
    }
};