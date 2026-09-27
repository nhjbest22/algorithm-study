class Solution {
public:
    vector<int> par;
    int MAX;

    int find(int x){
        if(par[x] < 0) return x;

        return par[x] = find(par[x]);
    }

    bool is_diff_group(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return false;
        if(par[u] > par[v]) swap(u, v);

        par[u] += par[v];
        par[v] = u;

        return true;
    }

    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        
        if(!N) return 0;

        unordered_map<int, int> um;
        int idx = 0;
        MAX = 1;

        for(auto num: nums){
            if(um.find(num) != um.end()) continue;

            um[num] = idx++;
        }

        par.assign(idx, -1);

        for(auto& [num, i]: um){
            if(um.find(num+1) == um.end()) continue;

            if(is_diff_group(i, um[num+1])) MAX = max(MAX, -par[find(i)]);
        }

        return MAX;
    }
};
