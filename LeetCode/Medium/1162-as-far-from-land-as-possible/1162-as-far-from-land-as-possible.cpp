class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> lands;
        int N = grid.size();
        int MAX = -1;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0) continue;

                lands.push_back({i, j});
            }
        }

        if(lands.size() == 0) return -1;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 1) continue;

                int dist = INT32_MAX;
                for(auto& land: lands){
                    int cur_dist = abs(i - land.first) + abs(j - land.second);
                    dist = min(dist, cur_dist);
                }

                MAX = max(dist, MAX);
            }
        }

        return MAX;
    }
};