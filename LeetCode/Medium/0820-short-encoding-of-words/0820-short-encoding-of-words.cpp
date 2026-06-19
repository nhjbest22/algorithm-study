class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> us;
        int N = words.size();
        int ans = 0;

        for(auto& word: words) us.insert(word);

        for(int i=0; i < N; i++){
            auto& word = words[i];

            int len = word.size();
            for(int idx =1; idx < len; idx++)
                us.erase(word.substr(idx));
        }
        
        for(auto& key: us){
            ans += key.size() + 1;
        }

        return ans;
    }
};