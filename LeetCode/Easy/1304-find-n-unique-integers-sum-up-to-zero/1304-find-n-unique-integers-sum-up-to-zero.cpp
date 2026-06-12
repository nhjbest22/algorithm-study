class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;    

        // 4 -> -2 -1 1 2
        // 5 -> -2 -1 0 1 2
        
        int cur = n/2;
        cur *= -1;

        for(int i = 0; i < n; i++){
            if(n%2 == 0 && cur == 0) cur++;

            ans.push_back(cur++);
        }

        return ans;
    }
};