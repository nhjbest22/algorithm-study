class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int N = s.size();
        unordered_set<string> us1, us2;

        for(int i = 0; i < N; i++){
            if(i + 10 > N) break;

            string str = s.substr(i, 10);

            if(us1.find(str) == us1.end()){
                us1.insert(str);
                continue;
            }

            us2.insert(str);
        }

        vector<string> ans(us2.begin(), us2.end());
        return ans;
    }
};