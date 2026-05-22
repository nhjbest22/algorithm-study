class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int check[10];
        int N = nums.size();
        vector<vector<int>> res;

        for(int i  = 0; i< N; i++) check[i] = i;

        do{
            vector<int> v(N);
            for(int i = 0; i< N; i++){
                int idx = check[i];
                v[idx] = nums[i];
            }
            res.push_back(v);
        }while(next_permutation(check, check + N));

        return res;
    }
};