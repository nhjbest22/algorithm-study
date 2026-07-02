class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        int y;
        
        int no = -1, yes = M-1;

        while(no + 1 < yes){
            int mid = (yes + no)/2;

            auto it = max_element(mat[mid].begin(), mat[mid].end());
            y = it - mat[mid].begin();

            if(mat[mid][y] > mat[mid+1][y]) yes = mid;
            else no = mid;
        }
        
        y = max_element(mat[yes].begin(), mat[yes].end()) - mat[yes].begin();

        return {yes, y};
    }
};