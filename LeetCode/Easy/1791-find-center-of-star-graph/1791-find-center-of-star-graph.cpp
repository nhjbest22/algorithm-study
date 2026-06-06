class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];

        for(int i = 0; i < 2; i++){
            auto& e = edges[1];
            if(e[i] == a || e[i] == b) return e[i];
        }

        return 0;
    }
};