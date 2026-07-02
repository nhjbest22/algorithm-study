class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> rank(1'005, 2000);
        
        int R = 0;
        for(auto& num: arr2)
            rank[num] = R++;

        sort(arr1.begin(), arr1.end(), [&](const int& a, const int& b){
            if(rank[a] != rank[b]) return rank[a] < rank[b];
            return a < b;
        });

        return arr1;
    }
};