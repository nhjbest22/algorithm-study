class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        bool isUsed[2005];
        fill(isUsed, isUsed + 2005, true);
        
        int N = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            if(a.size() != b.size()) return a.size() < b.size();
            return a < b;
        });

        for(int i = N-1; i >= 0; i--){
            for(int j = 0; j < i; j++){
                if(!isUsed[j]) continue;

                string& str_short = words[j];
                string& str_long = words[i];
                
                int idx1 = str_short.size()-1;
                int idx2 = str_long.size()-1;

                bool isIncluded = true;
                while(idx1 >= 0 && idx2 >= 0){
                    if(str_short[idx1--] != str_long[idx2--]){
                        isIncluded = false;
                        break;
                    }
                }

                if(isIncluded) isUsed[j] = false;
            }
        }

        int ans = 0;
        for(int i = 0; i < N; i++){
            if(!isUsed[i]) continue;

            ans += (words[i].size() + 1);
        }



        return ans;
    }
};