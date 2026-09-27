class Solution {
public:
    vector<int> p;
    int MAX;

    int find(int x){
        if(p[x] < 0) return x;

        return p[x] = find(p[x]);
    }

    bool is_diff_group(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return false;

        if(p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;

        return true;
    }

    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;

        MAX = 1;
        int idx = 0;
        unordered_map<int, int> um;

        for(auto& num: nums){
            if(um.find(num) != um.end()) continue;

            um[num] = idx++;
        }

        p.assign(idx, -1);

        for(auto& [num, i]: um){
            if(um.find(num + 1) == um.end()) continue;

            if(is_diff_group(i, um[num+1])) MAX = max(MAX, -p[find(i)]);
        }

        return MAX;
    }
};
