class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, char> WtoP, PtoW;
        int N = pattern.size();

        for(auto& word: words){
            WtoP.clear();
            PtoW.clear();

            bool isSame = true;
            for(int i = 0; i < N; i++){
                if(WtoP.find(word[i]) == WtoP.end() && PtoW.find(pattern[i]) == PtoW.end()){
                    WtoP[word[i]] = pattern[i];
                    PtoW[pattern[i]] = word[i];
                    continue;
                }

                if(WtoP.find(word[i]) != WtoP.end() && PtoW.find(pattern[i]) != PtoW.end()){
                    if(WtoP[word[i]] == pattern[i] && PtoW[pattern[i]] == word[i]){
                        continue;
                    }

                    isSame = false;
                    break;
                }

                isSame = false;
                break;
            }

            if(isSame) ans.push_back(word);
        }

        return ans;
    }
};