class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int N = votes.size(), M = votes[0].size();

        vector<vector<int>> rank(M, vector<int>(M, 0));
        unordered_map<char, int> um;

        int idx = 0;
        string str = "";
        for(auto& ch: votes[0])
            um[ch] = idx++;
        

        for(auto& vote: votes){
            for(int i = 0; i < M; i++){
                int idx = um[vote[i]];
                rank[idx][i]++;
            }
        }

        string ans = votes[0];
        sort(ans.begin(), ans.end(), [&](const auto& ch1, const auto& ch2){
            int idx1 = um[ch1], idx2 = um[ch2];

            for(int i = 0; i < M ; i++){
                if(rank[idx1][i] != rank[idx2][i])
                    return rank[idx1][i] > rank[idx2][i];
            }

            return ch1 < ch2;
        });

        return ans;
    }
};