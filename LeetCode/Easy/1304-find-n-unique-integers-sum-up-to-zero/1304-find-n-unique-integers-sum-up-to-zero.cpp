class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;    

        // 4 -> -2 -1 1 2
        // 5 -> -2 -1 0 1 2
        
        int cur = n/2;
        while(cur > 0){
            ans.push_back(cur);
            ans.push_back(-cur);

            cur--;
        }

        if(n%2) ans.push_back(0);

        return ans;
    }
};