class Solution {
    const static int MAX = 1e5;
    int p[MAX + 5];

    int find(int x){
        if(p[x] < 0) return x;
        return p[x] = find(p[x]);
    }

    bool is_diff_group(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return false;

        if(p[u] == p[v]) p[u]--;
        if(p[u] < p[v]) p[v] = u;
        else p[u] = v;        

        return true;
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int N = nums.size();
        fill(p, p + MAX, -1);

        vector<pair<int, int>> v;
        for(int i = 0; i < N; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        for(int i = 1; i < N; i++){
            if(v[i].first - v[i-1].first > limit) continue;

            is_diff_group(v[i].second, v[i-1].second);
        }

        unordered_map<int, queue<int>> groups;
        for(int i = 0; i < N; i++){
            auto& [num, idx] = v[i];

            int root = find(idx);
            groups[root].push(num);
        }

        for(int i = 0; i < N; i++){
            int root = find(i);

            nums[i] = groups[root].front();
            groups[root].pop();
        }

        return nums;
    }
};