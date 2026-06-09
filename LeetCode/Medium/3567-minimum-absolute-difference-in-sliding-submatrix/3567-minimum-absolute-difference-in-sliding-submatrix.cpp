class Solution {
public:
    int offSet = 100'000;
    int cnt[200'005];

    int findMinOfSet(set<int>& s){
        if(s.size() == 1) return 0;

        int ret = 0x3f3f3f3f;
        auto it = s.begin();
        int prev = *it;
        it++;

        while(it != s.end()){
            ret = min(ret, abs(*it - prev));
            prev = *it;
            it++;
        }

        return ret;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        fill(cnt, cnt + 200'005, 0);
        set<int> s;
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> ans;

        for(int i = 0; i < M - k + 1; i++){
            vector<int> buffer;
            s.clear();

            for(int j = 0; j < N - k + 1; j++){
                if(j == 0){
                    for(int x = i; x < i + k; x++){
                        for(int y = 0; y < k; y++){
                            cnt[grid[x][y] + offSet]++;

                            s.insert(grid[x][y]);
                        }
                    }

                } else{
                    for(int x = i; x < i + k; x++){
                        cnt[grid[x][j-1] + offSet]--;

                        if(!cnt[grid[x][j-1] + offSet]) s.erase(s.find(grid[x][j-1]));
                    }

                    for(int x = i; x < i + k; x++){
                        cnt[grid[x][j+k-1] + offSet]++;

                        s.insert(grid[x][j+k-1]);
                    }
                }       

                buffer.push_back(findMinOfSet(s));
            }

            ans.push_back(buffer);
        }

        return ans;
    }
};