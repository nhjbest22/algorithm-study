class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        bool isUsed[2005];
        fill(isUsed, isUsed + 2005, true);

        int N = words.size();
        int ans = 0;
        for(auto& word: words) reverse(word.begin(), word.end());
        sort(words.begin(), words.end());
        
        for(int i=0; i < N-1; i++){
            if(words[i].size() > words[i+1].size()) continue;

            int len = words[i].size();
            bool isIncluded = true;
            for(int j = 0; j < len; j++){
                if(words[i][j] != words[i+1][j]){
                    isIncluded = false;
                    break;
                }
            }

            if(isIncluded) isUsed[i] = false;
        }

        for(int i = 0; i< N; i++){
            if(!isUsed[i]) continue;

            ans += (words[i].size() + 1);
        }

        return ans;
    }
};