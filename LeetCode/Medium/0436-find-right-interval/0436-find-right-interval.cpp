class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts, ends;
        int N = intervals.size();
        vector<int> ans(N, -1);

        starts.reserve(N);
        ends.reserve(N);

        for(int i = 0; i < N; i++){
            auto& interval = intervals[i];
            starts.push_back({interval[0], i});
            ends.push_back({interval[1], i});
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int idx = 0;
        for(int i = 0; i < N; i++){
            auto& en = ends[i];
            
            while(idx < N && en.first > starts[idx].first)
                idx++;

            if(idx == N) break;
            
            ans[en.second] = starts[idx].second;
        }

        return ans;
    }
};