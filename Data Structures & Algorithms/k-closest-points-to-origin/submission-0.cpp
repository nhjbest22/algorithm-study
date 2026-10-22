class Solution {
public:
    int dist(vector<int>& p){
        return p[0]*p[0] + p[1]*p[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int N = points.size();
        for(int i = 0; i < N; i++){
            auto& p = points[i];

            pq.push({dist(p), i});
        }

        while(k--){
            auto [d, i] = pq.top(); pq.pop();
            ans.push_back(points[i]);
        }

        return ans;
    }
};
